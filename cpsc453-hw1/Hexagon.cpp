// Hexagon.cpp
// Hexagon class with 6 Triangles using Triangle.hpp

#include <vector>
#include "Hexagon.hpp"

Hexagon::Hexagon(Triangle tri1, Triangle tri2, Triangle tri3, Triangle tri4,
                 Triangle tri5, Triangle tri6) :
                    t1(tri1), t2(tri2), t3(tri3), t4(tri4), t5(tri5), t6(tri6) {
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

std::vector<glm::vec3> Hexagon::getVertices(){
    std::vector<glm::vec3> vertices;
    vertices.push_back(glm::vec3(1.0, 0.0, 1.0));
    
    float theta = M_PI/3.0;
    
    float radius = glm::length(glm::vec3(1.0, 0.0, 1.0) - glm::vec3(0.0, 0.0, 1.0));
    
    for (int i = 1; i < 6; i++) {
        if (i == 3) {
            vertices.push_back(glm::vec3(-1.0, 0.0, 1.0));
        } else {
            vertices.push_back(glm::vec3(0.0 + radius * cosf(theta * i), 0.0 + radius * sinf(theta * i), 1.0));
        }
    }
    
    return vertices;
}
