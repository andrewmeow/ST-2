#include "circle.h"

double ropeGap() {
  double earthRadius = 6378.1 * 1000; // Перевод в метры
  Circle earth(earthRadius);

  double newFerence =
      earth.getFerence() + 1; // Увеличиваем длину верёвки на 1 метр
  Circle newEarth(0);
  newEarth.setFerence(newFerence);

  return newEarth.getRadius() - earth.getRadius();
}

double calcConcreteCost() {
  Circle pool(3);  // Бассейн
  Circle outer(4); // Бассейн + дорожка

  double trackArea = outer.getArea() - pool.getArea();
  return trackArea * 1000; // 1000 р за 1 м²
}

double calcFenceCost() {
  Circle outer(4); // Радиус всей конструкции с дорожкой
  return outer.getFerence() * 2000; // 2000 р за 1 м
}