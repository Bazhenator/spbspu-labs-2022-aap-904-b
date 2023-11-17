#include <iostream>
#include <string>
#include <cstddef>
#include <cmath>
#include "Rectangle.h"
#include "Parallelogram.h"
#include "Square.h"
#include "CompositeShape.h"

int main() {
  flusova::CompositeShape composition;
  std::string shapeName = "";
  bool scaleFlag = false;
  while (std::cin.peek() != EOF) {
    std::cin >> shapeName;
    flusova::Shape* shapeData;
    if (!shapeName.compare("RECTANGLE")) {
      double lX, lY, rX, rY;
      std::cin >> lX >> lY >> rX >> rY;
      try {
        flusova::Rectangle rectangle(flusova::point_t{ lX, lY }, flusova::point_t{ rX, rY });
        shapeData = &rectangle;
        composition.push_back(shapeData);
      }
      catch (const std::runtime_error& e) {
        std::cerr << e.what() << '\n';
        continue;
      }
    }
    else if (!shapeName.compare("PARALLELOGRAM")) {
      double aX, aY, bX, bY, cX, cY;
      std::cin >> aX >> aY >> bX >> bY >> cX >> cY;
      try {
        flusova::Parallelogram parallelogram(flusova::point_t{ aX, aY }, flusova::point_t{ bX, bY },
                                             flusova::point_t{ cX, cY });
        shapeData = &parallelogram;
        composition.push_back(shapeData);
      }
      catch (const std::runtime_error& e) {
        std::cerr << e.what() << '\n';
        continue;
      }
    }
    else if (!shapeName.compare("SQUARE")) {
      try {
        double x, y, side;
        std::cin >> x >> y >> side;
        flusova::Square square({ x, y }, side);
        shapeData = &square;
        composition.push_back(shapeData);
      }
      catch (const std::runtime_error& e) {
        std::cerr << e.what() << '\n';
        continue;
      }
    }
    else if (!shapeName.compare("SCALE")) {
      if (composition.empty()) {
        return 1;
      }
      std::cout.precision(1);
      std::cout << std::fixed << composition.getArea();
      for (std::size_t i = 0; i < composition.size(); ++i) {
        flusova::rectangle_t frameRect = composition[i]->getFrameRect();
        std::cout << " " << frameRect.pos_.x_ - frameRect.width_ / 2.0;
        std::cout << " " << frameRect.pos_.y_ - frameRect.height_ / 2.0;
        std::cout << " " << frameRect.pos_.x_ + frameRect.width_ / 2.0;
        std::cout << " " << frameRect.pos_.y_ + frameRect.height_ / 2.0;
      }
      std::cout << '\n';
      double pX, pY, multiplier;
      std::cin >> pX >> pY >> multiplier;
      if (multiplier <= 0) {
        std::cerr << "Wrong multiplier!" << '\n';
        break;
      }
      flusova::point_t toPoint{ pX, pY };
      for (std::size_t i = 0; i < composition.size(); ++i) {
        flusova::rectangle_t startRect = composition[i]->getFrameRect();
        composition[i]->move(toPoint);
        flusova::rectangle_t currentRect = composition[i]->getFrameRect();
        double dX = (startRect.pos_.x_ - currentRect.pos_.x_) * multiplier;
        double dY = (startRect.pos_.y_ - currentRect.pos_.y_) * multiplier;
        composition[i]->move(dX, dY);
      }
      composition.scale(multiplier);
      std::cout << std::fixed << composition.getArea();
      for (std::size_t i = 0; i < composition.size(); ++i) {
        flusova::rectangle_t frameRect = composition[i]->getFrameRect();
        std::cout << " " << frameRect.pos_.x_ - frameRect.width_ / 2.0;
        std::cout << " " << frameRect.pos_.y_ - frameRect.height_ / 2.0;
        std::cout << " " << frameRect.pos_.x_ + frameRect.width_ / 2.0;
        std::cout << " " << frameRect.pos_.y_ + frameRect.height_ / 2.0;
      }
      std::cout << "\n";
      scaleFlag = true;
      break;
    }
  }
  if (scaleFlag == false) {
    std::cerr << "Scale Error! Try again!" << '\n';
    return 1;
  }
  return 0;
}
