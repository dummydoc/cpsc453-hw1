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

    glm::mat3 translateMatrix1 = glm::mat3(1.0, 0.0, 0.0,
                                           0.0, 1.0, 0.0,
                                           (1.0/3.0) * (getV2() - getV1()).x,
                                           (1.0/3.0) * (getV2() - getV1()).y,
                                           1);

    glm::mat3 translateMatrix2 = glm::mat3(1.0, 0.0, 0.0,
                                           0.0, 1.0, 0.0,
                                           (2.0/3.0) * (getV2() - getV1()).x,
                                           (2.0/3.0) * (getV2() - getV1()).y,
                                           1);

    glm::mat translateToOriginV1 = glm::mat3(1.0, 0.0, 0.0,
                                             0.0, 1.0, 0.0,
                                             -getV1().x, -getV1().y, 1);

    glm::mat translateToOriginV2 = glm::mat3(1.0, 0.0, 0.0,
                                             0.0, 1.0, 0.0,
                                             -getV2().x, -getV2().y, 1);






    Line line1 = Line(scaleMatrix * line.getV1(), scaleMatrix * line.getV2());
    Line line2 = Line(translateMatrix1 * scaleMatrix * line.getV1(),
                      translateMatrix1 * scaleMatrix * line.getV2());
    Line line3 = Line(translateMatrix1 * scaleMatrix * line.getV1(),
                      translateMatrix1 * scaleMatrix * line.getV2());
    Line line4 = Line(translateMatrix2 * scaleMatrix * line.getV1(),
                      translateMatrix2 * scaleMatrix * line.getV2());

    std::vector<Line> retVal;

    retVal.push_back(line1);
    retVal.push_back(line2);
    retVal.push_back(line3);
    retVal.push_back(line4);


    return retVal;
}
