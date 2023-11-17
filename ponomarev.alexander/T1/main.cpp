#include <iostream>
#include <iomanip>
#include <string>
#include "Rectangle.h"
#include "Complexquad.h"
#include "Circle.h"
#include "CompositeShape.h"
#include "Shape.h"

int main()
{
  ponomarev::CompositeShape storage;
  std::string name;
  bool scaled = false;
  while (std::cin.peek() != EOF) {
    ponomarev::Shape *ptShape;
    std::cin >> name;
    if (!name.compare("RECTANGLE")) {
      ponomarev::point_t lowerLeft, upperRight;
      std::cin >> lowerLeft >> upperRight;
      try {
        ponomarev::Rectangle temp(lowerLeft, upperRight);
        ptShape = &temp;
        storage.push_back(ptShape);
      } catch(const std::runtime_error &e) {
        std::cerr << e.what();
        continue;
      }
    } else if (!name.compare("CIRCLE")) {
      ponomarev::point_t center;
      double radius;
      std::cin >> center >> radius;
      try {
        ponomarev::Circle temp(center, radius);
        ptShape = &temp;
        storage.push_back(ptShape);
      } catch(const std::runtime_error &e) {
        std::cerr << e.what();
        continue;
      }
    } else if (!name.compare("COMPLEXQUAD")) {
      ponomarev::point_t lowerLeftPoint, upperRightPoint, lowerRightPoint, upperLeftPoint;
      std::cin >> lowerLeftPoint >> upperRightPoint >> lowerRightPoint >> upperLeftPoint;
      try {
        ponomarev::Complexquad temp(lowerLeftPoint, upperRightPoint, lowerRightPoint, upperLeftPoint);
        ptShape = &temp;
        storage.push_back(ptShape);
      } catch (const std::runtime_error &e) {
        std::cerr << e.what();
        continue;
      }
    } else if (!name.compare("SCALE")) {
      if (storage.empty()) {
        break;
      }
      std::cout.precision(1);
      std::cout << std::fixed << storage.getArea();
      for (std::size_t i = 0; i < storage.size(); i++) {
        std::cout << ' ' << storage[i]->getFrameRect();
      }
      std::cout << '\n';

      ponomarev::point_t center;
      double multiplier;
      std::cin >> center >> multiplier;
      for (std::size_t i = 0; i < storage.size(); i++) {
        ponomarev::point_t oldCenter = storage[i]->getFrameRect().pos_;
        storage[i]->move(center);
        ponomarev::point_t offsetVector = (oldCenter - storage[i]->getFrameRect().pos_) * multiplier;
        storage[i]->move(center + offsetVector);
      }
      try {
        storage.scale(multiplier);
      } catch (const std::runtime_error &e) {
        std::cerr << e.what();
        break;
      }

      std::cout << storage.getArea();
      for (std::size_t i = 0; i < storage.size(); i++) {
        std::cout << ' ' << storage[i]->getFrameRect();
      }
      std::cout << '\n';
      scaled = true;
      break;
    } else {
      std::getline(std::cin, name);
    }
  }
  if (!scaled) {
    std::cerr << "Scaling wasn't completed.\n";
    return 1;
  }
  return 0;
}
