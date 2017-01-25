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

std::vector<glm::vec3> transformTri(std::vector<glm::vec3> tri, glm::vec3 vertex)
{
    glm::mat3 scaleMatrix = glm::mat3(1.0/3.0, 0.0, 0.0,
                                      0.0, 1.0/3.0, 0.0,
                                      0.0, 0.0, 1.0);

    glm::mat3 translateMatrix = glm::mat3(1.0, 0.0, 0.0,
                                          0.0, 1.0, 0.0,
                                          2.0/3.0 * vertex.x, 2.0/3.0 * vertex.y, 1.0);

    glm::mat3 transformMatrix = scaleMatrix * translateMatrix;

    std::vector<glm::vec3> transformedTriangle;

    for (glm::vec3 v : tri) {
        transformedTriangle.push_back(transformMatrix * v);
    }

    return transformedTriangle;
}


int main(int argc, const char * argv[]) {

    Triangle triTest(glm::vec3(1.0, 0.0, 1.0), glm::vec3(0.0, 0.0, 1.0), glm::vec3(0.0, 1.0, 1.0));

    std::vector<glm::vec3> testTri = {glm::vec3(1.0, 0.0, 1.0), glm::vec3(0.0, 0.0, 1.0), glm::vec3(0.0, 1.0, 1.0)};

    glm::vec3 vert = glm::vec3(1.0, 0.0, 1.0);

    std::vector<glm::vec3> testTransform = transformTri(testTri, vert);

    for(glm::vec3 v : testTransform) {
        std::cout << v.x << std::endl;
        std::cout << v.y << std::endl;
        std::cout << v.z << std::endl;
    }

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
