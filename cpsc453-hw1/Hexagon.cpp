// Hexagon.cpp
// Hexagon class with 6 Triangles using Triangle.hpp

#include <vector>
#include "Triangle.hpp"
#include "Hexagon.hpp"

Hexagon::Hexagon(Triangle tri1, Triangle tri2, Triangle tri3, Triangle tri4,
                 Triangle tri5, Triangle tri6, glm::vec3 center, glm::vec3 rightVertex) :
                    t1(tri1), t2(tri2), t3(tri3), t4(tri4), t5(tri5), t6(tri6), c(center), rVertex(rightVertex) {
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
    vertices.push_back(this->getRightVertex());
    
    float theta = M_PI/3.0;
    
    float radius = glm::length(this->getRightVertex() - this->getCenter());
    
    for (int i = 1; i < 6; i++) {
        if (i == 3) {
            vertices.push_back(glm::vec3(2 * this->getCenter().x - this->getRightVertex().x,
                                         2 * this->getCenter().y - this->getRightVertex().y,
                                         1.0));
        } else {
            vertices.push_back(glm::vec3(this->getCenter().x + radius * cosf(theta * i),
                                         this->getCenter().y + radius * sinf(theta * i),
                                         1.0));
        }
    }
    
    return vertices;
}

glm::vec3 Hexagon::getCenter() {
    return this->c;
}

glm::vec3 Hexagon::getRightVertex(){
    return this->rVertex;
}

std::vector<Triangle> Hexagon::getTriangles(){
    std::vector<Triangle> triangles;
    
    triangles.push_back(this->getT1());
    triangles.push_back(this->getT2());
    triangles.push_back(this->getT3());
    triangles.push_back(this->getT4());
    triangles.push_back(this->getT5());
    triangles.push_back(this->getT6());
    
    return triangles;
}

Hexagon Hexagon::transformHex(Hexagon hex, glm::vec3 dir){
    Triangle transformedTri1 = Triangle::transformTri(hex.getT1(), dir, hex.getCenter());
    Triangle transformedTri2 = Triangle::transformTri(hex.getT2(), dir, hex.getCenter());
    Triangle transformedTri3 = Triangle::transformTri(hex.getT3(), dir, hex.getCenter());
    Triangle transformedTri4 = Triangle::transformTri(hex.getT4(), dir, hex.getCenter());
    Triangle transformedTri5 = Triangle::transformTri(hex.getT5(), dir, hex.getCenter());
    Triangle transformedTri6 = Triangle::transformTri(hex.getT6(), dir, hex.getCenter());

    Hexagon transformedHexagon = Hexagon(transformedTri1,
                                         transformedTri2,
                                         transformedTri3,
                                         transformedTri4,
                                         transformedTri5,
                                         transformedTri6,
                                         glm::vec3((2.0/3.0) * dir.x, (2.0/3.0) * dir.y, 1),
                                         dir);
    
    
    
    return transformedHexagon;
}
