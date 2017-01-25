// Triangle.hpp
// Triangle class with 3 Vertices using glm::vec3

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Triangle {
private:
  glm::vec3 v1, v2, v3;
public:
  Triangle(glm::vec3 vec1, vec2, vec3);
  ~Triangle();
  glm::vec3 getV1();
  glm::vec3 getV2();
  glm::vec3 getV3();
};

#endif // TRIANGLE_HPP
