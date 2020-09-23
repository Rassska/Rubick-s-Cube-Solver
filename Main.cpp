
/**
 *    author:  Rasul Yunusov
 *    created: 21.05.2020 20:28:26
**/
 
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <string>

#include "Cube.h"
#include "Init.h"
#include "Solve.h"
int main()
{
   
    Cube MyCube;
    init(MyCube);
    std::cout << '\n';
    SolveCube(MyCube);
 
}
 