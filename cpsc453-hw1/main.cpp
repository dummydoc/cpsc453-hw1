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

Triangle transformTri(Triangle tri, glm::vec3 vertex)
{
    glm::mat3 scaleMatrix = glm::mat3(1.0/3.0, 0.0, 0.0,
                                      0.0, 1.0/3.0, 0.0,
                                      0.0, 0.0, 1.0);

    glm::mat3 translateMatrix = glm::mat3(1.0, 0.0, 0.0,
                                          0.0, 1.0, 0.0,
                                          2.0/3.0 * vertex.x,
                                          2.0/3.0 * vertex.y, 1.0);

    glm::mat3 transformMatrix = scaleMatrix * translateMatrix;

    Triangle transformedTriangle(transformMatrix * tri.getV1(), transformMatrix *
      tri.getV2(), transformMatrix * tri.getV3());

    return transformedTriangle;
}

Hexagon transformHexagon(Hexagon hex, glm::vec3 dir)
{
  Hexagon transformedHexagon(transformTri(hex.getT1(), dir),
                             transformTri(hex.getT2(), dir),
                             transformTri(hex.getT3(), dir),
                             transformTri(hex.getT4(), dir),
                             transformTri(hex.getT5(), dir),
                             transformTri(hex.getT6(), dir));

  return transformedHexagon;
}


int main(int argc, const char * argv[]) {

//    Triangle triTest(glm::vec3(1.0, 0.0, 1.0), glm::vec3(0.0, 0.0, 1.0), glm::vec3(0.0, 1.0, 1.0));
//
//    std::vector<glm::vec3> testTri = {glm::vec3(1.0, 0.0, 1.0), glm::vec3(0.0, 0.0, 1.0), glm::vec3(0.0, 1.0, 1.0)};
//
//    glm::vec3 vert = glm::vec3(1.0, 0.0, 1.0);
//
//    Triangle testTransform = transformTri(triTest, vert);
//
//
//    std::cout << testTransform.getV1().x << std::endl;
//    std::cout << testTransform.getV1().y << std::endl;
//    std::cout << testTransform.getV1().z << std::endl;
//
//    std::cout << testTransform.getV2().x << std::endl;
//    std::cout << testTransform.getV2().y << std::endl;
//    std::cout << testTransform.getV2().z << std::endl;
//
//    std::cout << testTransform.getV3().x << std::endl;
//    std::cout << testTransform.getV3().y << std::endl;
//    std::cout << testTransform.getV3().z << std::endl;
    
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
    
    for (glm::vec3 v : vertices) {
        std::cout << v.x << std::endl;
        std::cout << v.y << std::endl;
        std::cout << v.z << std::endl;
    }


    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
};
