#include <iostream>
#include <string>
#include "rectangle.h"
#include "circle.h"
#include "ring.h"
#include "CompositeShape.h"

int main()
{
  chupina::CompositeShape container;
  std::string shapeName = "";
  bool ifScaled = false;
  while (std::cin.peek() != EOF) {
    chupina::Shape * ptShp;
    std::cin >> shapeName;
    if (!shapeName.compare("RECTANGLE")) {
      double x1, y1, x2, y2;
      std::cin >> x1 >> y1 >> x2 >> y2;
      try {
        chupina::Rectangle rect({x1, y1}, {x2, y2});
        ptShp = &rect;
        container.push_back(ptShp);
      } catch (const std::exception & e) {
        std::cerr << e.what();
        continue;
      }
    } else if (!shapeName.compare("CIRCLE")) {
      double x, y, R;
      std::cin >> x >> y >> R;
      try {
        chupina::Circle circ({x, y}, R);
        ptShp = &circ;
        container.push_back(ptShp);
      } catch (const std::exception & e) {
        std::cerr << e.what();
        continue;
      }
    } else if (!shapeName.compare("RING")) {
      double x, y, R, r;
      std::cin >> x >> y >> R >> r;
      try {
        chupina::Ring ring({x, y}, R, r);
        ptShp = &ring;
        container.push_back(ptShp);
      } catch (const std::exception & e) {
        std::cerr << e.what();
        continue;
      }
    } else if (!shapeName.compare("SCALE")) {
      std::cout.precision(1);
      std::cout << std::fixed << container.getArea();
      for (size_t i = 0; i < container.size(); i++) {
        chupina::Rectangle_t frameRect = container[i].getFrameRect();
        std::cout << ' ' << frameRect.pos_.x_ - frameRect.width_ / 2.0 <<
                     ' ' << frameRect.pos_.y_ - frameRect.height_ / 2.0 <<
                     ' ' << frameRect.pos_.x_ + frameRect.width_ / 2.0 <<
                     ' ' << frameRect.pos_.y_ + frameRect.height_ / 2.0;
      }
      std::cout << '\n';
      double posX, posY, factor;
      std::cin >> posX >> posY >> factor;
      if (!container.empty()) {
        for (size_t i = 0; i < container.size(); ++i) {
          chupina::Rectangle_t initialPos = container[i].getFrameRect();
          container[i].move(chupina::Point_t{posX, posY});
          chupina::Rectangle_t newPos = container[i].getFrameRect();
          double difX = std::abs(newPos.pos_.x_ - initialPos.pos_.x_) * factor;
          double difY = std::abs(newPos.pos_.y_ - initialPos.pos_.y_) * factor;
          container[i].move(difX, difY);
        }
        try {
          container.scale(factor);
        } catch (const std::exception & e) {
          std::cerr << e.what();
          break;
        }
        std::cout << container.getArea();
        for (size_t i = 0; i < container.size(); i++) {
          chupina::Rectangle_t frameRect = container[i].getFrameRect();
          std::cout << ' ' << frameRect.pos_.x_ - frameRect.width_ / 2.0 <<
                       ' ' << frameRect.pos_.y_ - frameRect.height_ / 2.0 <<
                       ' ' << frameRect.pos_.x_ + frameRect.width_ / 2.0 <<
                       ' ' << frameRect.pos_.y_ + frameRect.height_ / 2.0;
        }
        std::cout << '\n';
        ifScaled = true;
      }
      break;
    } else {
      std::cin.ignore();
    }
  }
  if (!ifScaled) {
    std::cerr << "Scale wasn't completed";
    return 1;
  }
  return 0;
}
