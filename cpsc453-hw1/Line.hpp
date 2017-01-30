// Line.hpp
// Line class with 2 Vertices using glm::vec3

#ifndef LINE_HPP
#define LINE_HPP

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Line {
private:
  glm::vec3 v1, v2;
public:
  Line(glm::vec3 vec1, glm::vec3 vec2);
  ~Line();
  glm::vec3 getV1();
  glm::vec3 getV2();
    std::vector<glm::vec3> getVertices();
    static std::vector<glm::vec3> transformLine(Line line);
};

#endif // LINE_HPP
