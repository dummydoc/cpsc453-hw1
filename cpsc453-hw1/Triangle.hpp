// Triangle.hpp
// Triangle class with 3 Vertices using glm::vec3

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Triangle {
private:
  glm::vec3 v1, v2, v3;
public:
  Triangle(glm::vec3 vec1, glm::vec3 vec2, glm::vec3 vec3);
  ~Triangle();
  glm::vec3 getV1();
  glm::vec3 getV2();
  glm::vec3 getV3();
    std::vector<glm::vec3> getVertices();
    static Triangle transformTri(Triangle tri, glm::vec3 vertex, glm::vec3 center);
};

#endif // TRIANGLE_HPP
