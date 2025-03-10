// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>
#include <cstdint>
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
Circle::Circle(double r) { setRadius(r); }

void Circle::setRadius(double r) {
  if (r < 0)
    return;
  radius = r;
  ference = 2 * M_PI * radius;
  area = M_PI * radius * radius;
}

void Circle::setFerence(double f) {
  if (f < 0)
    return;
  radius = f / (2 * M_PI);
  ference = f;
  area = M_PI * radius * radius;
}

void Circle::setArea(double a) {
  if (a < 0)
    return;
  radius = sqrt(a / M_PI);
  ference = 2 * M_PI * radius;
  area = a;
}

double Circle::getRadius() const { return radius; }

double Circle::getFerence() const { return ference; }

double Circle::getArea() const { return area; }