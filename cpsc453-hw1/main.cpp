//
//  main.cpp
//  cpsc453-hw1
//
//  Created by Owen McGill on 2017-01-24.
//  Copyright © 2017 mcgillowen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "Triangle.hpp"
#include "Hexagon.hpp"


std::vector<float> recurse(int level, Hexagon previousHex) {

  std::vector<float> resultVertices;

  if (level == 0) {
    for(Triangle t : previousHex.getTriangles()) {
      for (glm::vec3 v : t.getVertices()) {
        resultVertices.push_back(v.x);
        resultVertices.push_back(v.y);
      }
    }

    return resultVertices;
  } else {

    std::vector<glm::vec3> vertices = previousHex.getVertices();
    std::vector<Hexagon> hexs;

    for (glm::vec3 v : vertices) {
      hexs.push_back(Hexagon::transformHex(previousHex, v));
    }

    level--;

    for (Hexagon hex : hexs) {
      std::vector<float> result = recurse(level, previousHex);

      resultVertices.insert(resultVertices.end(), result.begin(), result.end());
    }

    return resultVertices;
  }
}

Hexagon createBaseHexagon() {

  std::vector<glm::vec3> vertices;
  vertices.push_back(glm::vec3(1.0, 0.0, 1.0));

  float theta = M_PI/3.0;

  glm::vec3 center = glm::vec3(0.0, 0.0, 1.0);

  glm::vec3 rightVertex = glm::vec3(1.0, 0.0, 1.0);

  float radius = glm::length(glm::vec3(1.0, 0.0, 1.0) - center);

  for (int i = 1; i < 6; i++) {
      if (i == 3) {
          vertices.push_back(glm::vec3(-1.0, 0.0, 1.0));
      } else {
          vertices.push_back(glm::vec3(0.0 + radius * cosf(theta * i), 0.0 + radius * sinf(theta * i), 1.0));
      }
  }

  Triangle tr1 = Triangle(center, vertices.at(0), vertices.at(1));
  Triangle tr2 = Triangle(center, vertices.at(1), vertices.at(2));
  Triangle tr3 = Triangle(center, vertices.at(2), vertices.at(3));
  Triangle tr4 = Triangle(center, vertices.at(3), vertices.at(4));
  Triangle tr5 = Triangle(center, vertices.at(4), vertices.at(5));
  Triangle tr6 = Triangle(center, vertices.at(5), vertices.at(0));


  Hexagon hex = Hexagon(tr1, tr2, tr3, tr4, tr5, tr6, center, vertices.at(0));

  return hex;

}


int main(int argc, const char * argv[]) {

  Hexagon testHex = createBaseHexagon();

    // Hexagon smallTestHex = Hexagon::transformHex(testHex, rightVertex);
    //
    // for (glm::vec3 v : testHex.getVertices()) {
    //     std::cout << v.x << std::endl;
    //     std::cout << v.y << std::endl;
    //     std::cout << v.z << std::endl;
    // }
    //
    // std::cout << "Transformed hex" << std::endl;
    // for (Triangle t : smallTestHex.getTriangles()) {
    //     std::cout << "Triangle" << std::endl;
    //     for (glm::vec3 v : t.getVertices()) {
    //         std::cout << v.x << std::endl;
    //         std::cout << v.y << std::endl;
    //         std::cout << v.z << std::endl;
    //     }
    // }

    std::vector<float> vertices = recurse(1, testHex);

    for (size_t i = 0; i < vertices.size() - 1; i++) {
      std::cout << vertices.at(i) << "," << vertices.at(i+1) << std::endl;
    }

    return 0;
};
