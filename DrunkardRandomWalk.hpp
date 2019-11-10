//
//  DrunkardRandomWalk.hpp
//  How to Fall Slower Than Gravity
//
//  Created by Jacob Cupul on 11/9/19.
//  Copyright © 2019 Jacob Cupul. All rights reserved.
//

#ifndef DrunkardRandomWalk_hpp
#define DrunkardRandomWalk_hpp
#include <stdio.h>
#include <cstdlib>
int SimulateWalk(int n, double p, int x){
    double rand_num;
    int move;
    int outcome;
    while (x!= 0 && x!= n) {
        rand_num = rand()/(double)RAND_MAX;
        if (rand_num < p) {
            move = 1;
        } else{
            move = -1;
        }
        x += move;
    }
    
    if (x==n){
        outcome = 1;
    }else{
        outcome = 0;
    }
    return outcome;
}

double DrunkenWalkProbability(int n, double p, int x, int sims){
    int count_home = 0;
    for (int iter = 1; iter <= sims; iter++) {
        count_home += SimulateWalk(n, p, x);
    }
    return count_home/(double)sims;
}

#endif /* DrunkardRandomWalk_hpp */
