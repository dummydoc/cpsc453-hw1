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

Triangle transformTri(Triangle tri, glm::vec3 vertex, glm::vec3 center)
{
//    std::cout << "Original" << std::endl;
//    
//    for (glm::vec3 v : tri.getVertices()) {
//        std::cout << v.x << std::endl;
//        std::cout << v.y << std::endl;
//        std::cout << v.z << std::endl;
//    }
//    
//    std::cout << std::endl;
    
    glm::mat3 scaleMatrix = glm::mat3(1.0/3.0, 0.0, 0.0,
                                      0.0, 1.0/3.0, 0.0,
                                      0.0, 0.0, 1.0);

    glm::mat3 translateMatrix = glm::mat3(1.0, 0.0, 0.0,
                                          0.0, 1.0, 0.0,
                                          (2.0/3.0) * (vertex - center).x, (2.0/3.0) * (vertex - center).y, 1.0);

    glm::mat3 transformMatrix = translateMatrix * scaleMatrix;

    Triangle transformedTriangle = Triangle(transformMatrix * tri.getV1(), transformMatrix *
      tri.getV2(), transformMatrix * tri.getV3());
    
//    std::cout << "Transformed" << std::endl;
//    
//    for (glm::vec3 v : transformedTriangle.getVertices()) {
//        std::cout << v.x << std::endl;
//        std::cout << v.y << std::endl;
//        std::cout << v.z << std::endl;
//    }
//    
//    std::cout << std::endl;

    return transformedTriangle;
}

Hexagon transformHexagon(Hexagon hex, glm::vec3 dir)
{
    
    Triangle transformedTri1 = transformTri(hex.getT1(), dir, hex.getCenter());
    Triangle transformedTri2 = transformTri(hex.getT2(), dir, hex.getCenter());
    Triangle transformedTri3 = transformTri(hex.getT3(), dir, hex.getCenter());
    Triangle transformedTri4 = transformTri(hex.getT4(), dir, hex.getCenter());
    Triangle transformedTri5 = transformTri(hex.getT5(), dir, hex.getCenter());
    Triangle transformedTri6 = transformTri(hex.getT6(), dir, hex.getCenter());

//    std::cout << "Transformed triangles" << std::endl;
//    for (glm::vec3 v : transformedTri1.getVertices()) {
//        std::cout << v.x << std::endl;
//        std::cout << v.y << std::endl;
//        std::cout << v.z << std::endl;
//    }
    
    
    
  Hexagon transformedHexagon = Hexagon(transformedTri1,
                                       transformedTri2,
                                       transformedTri3,
                                       transformedTri4,
                                       transformedTri5,
                                       transformedTri6,
                                       glm::vec3((2.0/3.0) * dir.x, (2.0/3.0) * dir.y, 1),
                                       dir);
    
    

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
    
    
    Hexagon testHex = Hexagon(tr1, tr2, tr3, tr4, tr5, tr6, center, vertices.at(0));
    
    Hexagon smallTestHex = transformHexagon(testHex, rightVertex);
    
//    for (glm::vec3 v : vertices) {
//        std::cout << v.x << std::endl;
//        std::cout << v.y << std::endl;
//        std::cout << v.z << std::endl;
//    }

    std::cout << "Transformed hex" << std::endl;
    for (Triangle t : smallTestHex.getTriangles()) {
        std::cout << "Triangle" << std::endl;
        for (glm::vec3 v : t.getVertices()) {
            std::cout << v.x << std::endl;
            std::cout << v.y << std::endl;
            std::cout << v.z << std::endl;
        }
    }


    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
};
