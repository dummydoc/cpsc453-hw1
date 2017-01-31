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

int main(int argc, const char * argv[]) {

    Hexagon testHex = Hexagon::createBaseHexagon();

    //    glm::vec3 rightVertex = glm::vec3(1.0, 0.0, 1.0);
    //
    //    Hexagon smallTestHex = Hexagon::transformHex(testHex, rightVertex);

    //     for (glm::vec3 v : testHex.getVertices()) {
    //         std::cout << v.x << std::endl;
    //         std::cout << v.y << std::endl;
    //         std::cout << v.z << std::endl;
    //     }

    //std::cout << "Transformed hex" << std::endl;
    //     for (Triangle t : testHex.getTriangles()) {
    //         std::cout << "Triangle" << std::endl;
    //         for (glm::vec3 v : t.getVertices()) {
    //             std::cout << v.x << std::endl;
    //             std::cout << v.y << std::endl;
    //             std::cout << v.z << std::endl;
    //         }
    //     }
    
    std::vector<float> vertices = Hexagon::recurse(3, testHex, testHex);
    
    for (size_t i = 0; i < vertices.size() - 1; i += 2) {
        std::cout << vertices.at(i) << "," << vertices.at(i+1) << "," << std::endl;
    }
    
    return 0;
};
