#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <string>

#include "Cube.h"
void SolveCube(Cube &MyCube)
{
    MyCube.getCube();
    std::cout << std::endl;
    std::vector<char> TempMatrix(9);
    std::cout << "\n**After The First Algorithm**\n(White Cross)\n";
    FirstStepSolve(MyCube, TempMatrix);
    MyCube.getCube();
    std::cout << "\n**After The Second Algorithm**\n(Completely covered white side and first line of another sides)\n";
    SecondStepSolve(MyCube, TempMatrix);
    MyCube.getCube();
    std::cout << "\n**After The Third Algorithm**\n(Completely covered second line of another sides)\n";
    ThirdStepSolve(MyCube, TempMatrix);
    MyCube.getCube();
    std::cout << "\n**After The Fourth Algorithm**\n(Yellow Cross)\n";
    FourthStepSolve(MyCube, TempMatrix);
    MyCube.getCube();
    std::cout << "\n**After The Fifth Algorithm**\n(Modify Up Cornes)\n";
    FifthStepSolve(MyCube, TempMatrix);
    MyCube.getCube();
    std::cout << "\n**After The Sixth Algorithm**\n(Completely covered Yellow side)\n";
    SixthStepSolve(MyCube, TempMatrix);
    MyCube.getCube();
    std::cout << "\n**After The Seventh Algorithm**\n(Totally have solved, Congratulations!)\n";
    SeventhStepSolve(MyCube, TempMatrix);
    MyCube.getCube();
}