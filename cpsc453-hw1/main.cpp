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
    
    std::vector<float> vertices = Hexagon::recurse(3, testHex, testHex);
    
    for (size_t i = 0; i < vertices.size() - 1; i += 2) {
        std::cout << vertices.at(i) << "," << vertices.at(i+1) << "," << std::endl;
    }
    
    return 0;
};
