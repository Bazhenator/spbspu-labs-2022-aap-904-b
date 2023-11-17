#include <iostream>
#include <string>
#include "base-types.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Ellipse.h"
#include "Concave.h"
#include "CompositeShape.h"

int main()
{
  bool check = false;
  std::string name = "";
  oleynikova::CompositeShape data;
  while (!std::cin.eof()) {
    std::cin >> name;
    oleynikova::Shape *shape;
    if (name == "RECTANGLE") {
      oleynikova::point_t leftPoint, rightPoint;
      std::cin >> leftPoint.x_ >> leftPoint.y_ >> rightPoint.x_ >> rightPoint.y_;
      try {
        oleynikova::Rectangle rectangle(leftPoint, rightPoint);
        shape = &rectangle;
        data.push_back(shape);
      }
      catch (const std::runtime_error &e) {
        std::cerr << e.what();
        continue;
      }
    }
    else if (name == "ELLIPSE") {
      oleynikova::point_t center;
      double verticRad, horizontRad;
      std::cin >> center.x_ >> center.y_ >> verticRad >> horizontRad;
      try {
        oleynikova::Ellipse ellipse(center, verticRad, horizontRad);
        shape = &ellipse;
        data.push_back(shape);
      }
      catch (const std::runtime_error &e) {
        std::cerr << e.what();
        continue;
      }
    }
    else if (name == "CONCAVE") {
      oleynikova::point_t left, upper, right, inner;
      std::cin >> left.x_ >> left.y_ >> upper.x_ >> upper.y_ >> right.x_ >> right.y_ >> inner.x_ >> inner.y_;
      try {
        oleynikova::Concave concave(left, upper, right, inner);
        shape = &concave;
        data.push_back(shape);
      }
      catch (const std::runtime_error &e) {
        std::cerr << e.what();
        continue;
      }
    }
    else if (name == "SCALE") {
      if (!data.empty()) {
        std::cout.precision(1);
        std::cout << std::fixed << data.getArea();
        for (size_t i = 0; i < data.size(); i++) {
          oleynikova::rectangle_t frameRect = data[i]->getFrameRect();
          std::cout << ' ' << frameRect.pos_.x_ - frameRect.width_ / 2.0 << ' ' << frameRect.pos_.y_ - frameRect.height_ / 2.0;
          std::cout << ' ' << frameRect.pos_.x_ + frameRect.width_ / 2.0 << ' ' << frameRect.pos_.y_ + frameRect.height_ / 2.0;
        }
        std::cout << '\n';
        oleynikova::point_t newCenter;
        double rate;
        std::cin >> newCenter.x_ >> newCenter.y_ >> rate;
        for (size_t i = 0; i < data.size(); i++) {
          oleynikova::point_t center = data[i]->getFrameRect().pos_;
          data[i]->move(newCenter);
          oleynikova::point_t vector((center - data[i]->getFrameRect().pos_) * rate);
          try {
            data[i]->scale(rate);
          }
          catch (const std::runtime_error &e) {
            std::cerr << e.what();
            return 1;
          }
          data[i]->move(newCenter + vector);
        }
        std::cout << data.getArea();
        for (size_t i = 0; i < data.size(); i++) {
          oleynikova::rectangle_t frameRect = data[i]->getFrameRect();
          std::cout << ' ' << frameRect.pos_.x_ - frameRect.width_ / 2.0 << ' ' << frameRect.pos_.y_ - frameRect.height_ / 2.0;
          std::cout << ' ' << frameRect.pos_.x_ + frameRect.width_ / 2.0 << ' ' << frameRect.pos_.y_ + frameRect.height_ / 2.0;
        }
        std::cout << '\n';
        check = true;
        break;
      }
      else {
        std::cerr << "Nothing to scale\n";
        return 1;
      }
    }
    else {
      std::getline(std::cin, name);
    }
  }
  if (check == false) {
    std::cerr << "did not scale\n";
    return 1;
  }
  return 0;
}
