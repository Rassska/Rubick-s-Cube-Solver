#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <string>

#include "Cube.h"
#include "Init.h"
void init(Cube &MyCube)
{
    int size = 9;
    std::vector<char> FrontPosition(size);
    std::vector<char> BackPosition(size);
    std::vector<char> UpPosition(size);
    std::vector<char> LeftPosition(size);
    std::vector<char> DownPosition(size);
    std::vector<char> RightPosition(size);
    for (int i = 0; i < size; i++)
    {
        std::cin >> FrontPosition[i];
    }
    for (int i = 0; i < size; i++)
    {
        std::cin >> BackPosition[i];
    }
    for (int i = 0; i < size; i++)
    {
        std::cin >> UpPosition[i];
    }
    for (int i = 0; i < size; i++)
    {
        std::cin >> LeftPosition[i];
    }
    for (int i = 0; i < size; i++)
    {
        std::cin >> DownPosition[i];
    }
    for (int i = 0; i < size; i++)
    {
        std::cin >> RightPosition[i];
    }
 
    MyCube.setPosition("Front", FrontPosition);
    MyCube.setPosition("Back", BackPosition);
    MyCube.setPosition("Left", LeftPosition);
    MyCube.setPosition("Right", RightPosition);
    MyCube.setPosition("Up", UpPosition);
    MyCube.setPosition("Down", DownPosition);
}