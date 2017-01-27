// Triangle.cpp
// Triangle class with 3 Vertices using glm::vec3

#include "Triangle.hpp"

Triangle::Triangle(glm::vec3 vec1, glm::vec3 vec2, glm::vec3 vec3) : v1(vec1), v2(vec2), v3(vec3) {
}

Triangle::~Triangle(){
}

glm::vec3 Triangle::getV1(){
  return this->v1;
}

glm::vec3 Triangle::getV2(){
  return this->v2;
}

glm::vec3 Triangle::getV3(){
  return this->v3;
}

std::vector<glm::vec3> Triangle::getVertices(){
    std::vector<glm::vec3> vertices;
    
    vertices.push_back(getV1());
    vertices.push_back(getV2());
    vertices.push_back(getV3());
    
    
    return vertices;
}

Triangle Triangle::transformTri(Triangle tri, glm::vec3 vertex, glm::vec3 center){
    
    glm::mat3 scaleMatrix = glm::mat3(1.0/3.0, 0.0, 0.0,
                                      0.0, 1.0/3.0, 0.0,
                                      0.0, 0.0, 1.0);

    glm::mat3 translateMatrix = glm::mat3(1.0, 0.0, 0.0,
                                          0.0, 1.0, 0.0,
                                          (2.0/3.0) * (vertex - center).x, (2.0/3.0) * (vertex - center).y, 1.0);

    glm::mat3 transformMatrix = translateMatrix * scaleMatrix;

    Triangle transformedTriangle = Triangle(transformMatrix * tri.getV1(), transformMatrix *
                                            tri.getV2(), transformMatrix * tri.getV3());

    return transformedTriangle;
}
