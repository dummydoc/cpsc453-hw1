// Hexagon.cpp
// Hexagon class with 6 Triangles using Triangle.hpp

#include "Hexagon.hpp"

Hexagon::Hexagon(glm::vec3 vec1, glm::vec3 vec2, glm::vec3 vec3) : v1(vec1), v2(vec2), v3(vec3) {
}

Hexagon::~Hexagon(){
}

Triangle Hexagon::getT1(){
  return this->t1;
}

Triangle Hexagon::getT2(){
  return this->t2;
}

Triangle Hexagon::getT3(){
  return this->t3;
}

Triangle Hexagon::getT4(){
  return this->t4;
}

Triangle Hexagon::getT5(){
  return this->t5;
}

Triangle Hexagon::getT6(){
  return this->t6;
}
