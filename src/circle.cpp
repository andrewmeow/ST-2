// Copyright 2022 UNN-CS
#include <cstdint>
#include "circle.h"

Circle::Circle(double r) { setRadius(r); }

void Circle::setRadius(double r) {
  if (r < 0)
    return; // Радиус не может быть отрицательным
  radius = r;
  ference = 2 * M_PI * radius;
  area = M_PI * radius * radius;
}

void Circle::setFerence(double f) {
  if (f < 0)
    return; // Длина окружности не может быть отрицательной
  radius = f / (2 * M_PI);
  ference = f;
  area = M_PI * radius * radius;
}

void Circle::setArea(double a) {
  if (a < 0)
    return; // Площадь не может быть отрицательной
  radius = sqrt(a / M_PI);
  ference = 2 * M_PI * radius;
  area = a;
}

double Circle::getRadius() const { return radius; }

double Circle::getFerence() const { return ference; }

double Circle::getArea() const { return area; }