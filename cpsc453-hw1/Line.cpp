// Line.cpp
// Line class with 2 Vertices using glm::vec3

#include "Line.hpp"

Line::Line(glm::vec3 vec1, glm::vec3 vec2) : v1(vec1), v2(vec2) {
}

Line::~Line(){
}

glm::vec3 Line::getV1(){
  return this->v1;
}

glm::vec3 Line::getV2(){
  return this->v2;
}

std::vector<glm::vec3> Line::getVertices(){
    std::vector<glm::vec3> vertices;

    vertices.push_back(getV1());
    vertices.push_back(getV2());


    return vertices;
}

std::vector<Line> Line::transformLine(Line line, glm::vec3 center){

    glm::mat3 scaleMatrix = glm::mat3(1.0/3.0, 0.0, 0.0,
                                      0.0, 1.0/3.0, 0.0,
                                      0.0, 0.0, 1.0);

    glm::mat3 transformMatrix = scaleMatrix;


    return Line(glm::vec3(0,0,1), glm::vec3(0,0,1));
}
