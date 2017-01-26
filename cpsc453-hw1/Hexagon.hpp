// Hexagon.hpp
// Hexagon class with 6 Triangles using Triangle.hpp

#ifndef HEXAGON_HPP
#define HEXAGON_HPP

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "Triangle.hpp"

class Hexagon {
private:
  Triangle t1, t2, t3, t4, t5, t6;
public:
  Hexagon(Triangle tri1, Triangle tri2, Triangle tri3, Triangle tri4,
    Triangle tri5, Triangle tri6);
  ~Hexagon();
  Triangle getT1();
  Triangle getT2();
  Triangle getT3();
  Triangle getT4();
  Triangle getT5();
  Triangle getT6();
};

#endif // HEXAGON_HPP