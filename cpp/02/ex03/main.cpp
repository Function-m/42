#include <iostream>
#include "Point.h"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
  // 꼭짓점을 정의
  Point a(0.0f, 0.0f), b(3.0f, 0.0f), c(1.5f, 3.0f);

  // 삼각형 내부의 점
  Point inside(1.5f, 1.0f);
  if (bsp(a, b, c, inside))
    std::cout << "Point (1.5, 1.0) is inside the triangle." << std::endl;
  else
    std::cout << "Point (1.5, 1.0) is not inside the triangle." << std::endl;

  // 삼각형 외부의 점
  Point outside(2.0f, 3.0f);
  if (bsp(a, b, c, outside))
    std::cout << "Point (2.0, 3.0) is inside the triangle." << std::endl;
  else
    std::cout << "Point (2.0, 3.0) is not inside the triangle." << std::endl;

  // 삼각형 경계의 점
  Point onEdge(1.5f, 0.0f);
  if (bsp(a, b, c, onEdge))
    std::cout << "Point (1.5, 0.0) is inside the triangle." << std::endl;
  else
    std::cout << "Point (1.5, 0.0) is not inside the triangle." << std::endl;

  // 삼각형 꼭짓점의 점
  Point vertex(0.0f, 0.0f);
  if (bsp(a, b, c, vertex))
    std::cout << "Point (0.0, 0.0) is inside the triangle." << std::endl;
  else
    std::cout << "Point (0.0, 0.0) is not inside the triangle." << std::endl;

  return 0;
}
