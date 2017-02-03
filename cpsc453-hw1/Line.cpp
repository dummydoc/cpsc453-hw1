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

std::vector<Line> Line::transformLine(Line line){

    glm::vec3 v1 = line.getV1();
    glm::vec3 v2 = line.getV2();

    float theta = M_PI / 3.0;

    float v3x = (v2.x - v1.x) * cosf(theta) - (v2.y - v1.y) * sinf(theta) + v1.x;
    float v3y = (v2.x - v1.x) * sinf(theta) + (v2.y - v1.y) * cosf(theta) + v1.y;

    glm::vec3 v3(v3x, v3y, 1);

    glm::vec3 a = v2;
    glm::vec3 b = v1;
    glm::vec3 c = v3;

    glm::vec3 d((2.0/3.0) * a.x + (1.0/3.0) * b.x,
                (2.0/3.0) * a.y + (1.0/3.0) * b.y,
                1);

    glm::vec3 f((2.0/3.0) * b.x + (1.0/3.0) * a.x,
                (2.0/3.0) * b.y + (1.0/3.0) * a.y,
                1);

    glm::vec3 e((1.0/3.0) * (a.x + b.x + c.x),
                (1.0/3.0) * (a.y + b.y + c.y),
                1);

    std::vector<Line> retVal;

    retVal.push_back(Line(b, f));
    retVal.push_back(Line(f, e));
    retVal.push_back(Line(e, d));
    retVal.push_back(Line(d, a));


    return retVal;
}

std::vector<Line> Line::createAllHexLines() {

    std::vector<glm::vec3> vertices;
    vertices.push_back(glm::vec3(1.0, 0.0, 1.0));

    float theta = M_PI/3.0;

    glm::vec3 center = glm::vec3(0.0, 0.0, 1.0);

    float radius = glm::length(glm::vec3(1.0, 0.0, 1.0) - center);

    for (int i = 1; i < 6; i++) {
        if (i == 3) {
            vertices.push_back(glm::vec3(-1.0, 0.0, 1.0));
        } else {
            vertices.push_back(glm::vec3(0.0 + radius * cosf(theta * i), 0.0 + radius * sinf(theta * i), 1.0));
        }
    }

    Line line1 = Line(vertices.at(0), vertices.at(1));
    Line line2 = Line(vertices.at(1), vertices.at(2));
    Line line3 = Line(vertices.at(2), vertices.at(3));
    Line line4 = Line(vertices.at(3), vertices.at(4));
    Line line5 = Line(vertices.at(4), vertices.at(5));
    Line line6 = Line(vertices.at(5), vertices.at(0));


    std::vector<Line> lines;
    lines.push_back(line1);
    lines.push_back(line2);
    lines.push_back(line3);
    lines.push_back(line4);
    lines.push_back(line5);
    lines.push_back(line6);
    
    return lines;

}


std::vector<float> Line::recurse(int level, std::vector<Line> previousLines) {

    std::vector<float> resultVertices;

    if (level == 0) {
        for(Line l : previousLines) {
            for (glm::vec3 v : l.getVertices()) {
                resultVertices.push_back(v.x);
                resultVertices.push_back(v.y);
            }
        }

        return resultVertices;
    } else {


        std::vector<Line> lines;

        for (Line l : previousLines) {
            std::vector<Line> newLines = Line::transformLine(l);
            lines.reserve(lines.size() + newLines.size());
            lines.insert(std::end(lines), std::begin(newLines), std::end(newLines));
        }

        std::vector<float> result = recurse(level - 1, lines);
        resultVertices.reserve(resultVertices.size() + result.size());
        resultVertices.insert(std::end(resultVertices), std::begin(result), std::end(result));

        return resultVertices;
    }

}
