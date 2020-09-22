
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
 
/*
 
 
R R R W W O G W G
W Y O O Y B R Y B
Y O G Y B O Y B W
B G B Y O B W W W
O R O G G G O R Y
B W R G R B Y R G
 
W W W W W W W W W
Y Y Y Y Y Y Y Y Y
G G G G G G G G G
R R R R R R R R R
B B B B B B B B B
O O O O O O O O O
 
Y W O W W B W W B
Y Y B Y Y B Y R R
W B B W G G G G W
O O O R R R G O R
B B Y G B Y W G G
G Y R O O R O O R
*/