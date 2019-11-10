//
//  main.cpp
//  How to Fall Slower Than Gravity
//
//  Created by Jacob Cupul on 11/9/19.
//  Copyright © 2019 Jacob Cupul. All rights reserved.
//

#include <iostream>
#include "DrunkardRandomWalk.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    double output;
    output = DrunkenWalkProbability(11, 0.6, 7, 100000);
    std::cout << output << std::endl;
    return 0;
}
