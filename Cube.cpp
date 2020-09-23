#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <string>

#include "Matrix.h"
#include "Cube.h"

    bool isSolvedForFirst(Cube &MyCube, std::vector<char> &TempMatrix){
        bool isOk = false;
        if ((*MyCube.DownSide.getVector())[1] == 'W' 
        && (*MyCube.DownSide.getVector())[1] == (*MyCube.DownSide.getVector())[3] 
        && (*MyCube.DownSide.getVector())[3] == (*MyCube.DownSide.getVector())[4] 
        && (*MyCube.DownSide.getVector())[4] == (*MyCube.DownSide.getVector())[5] 
        && (*MyCube.DownSide.getVector())[5] == (*MyCube.DownSide.getVector())[7]){
            isOk = true;
            
        }
        return isOk;
    }
    bool isSolvedForSecond(Cube &MyCube, std::vector<char> &TempMatrix){
        bool isOk = false;
        if ((*MyCube.DownSide.getVector())[1] == 'W' 
        && (*MyCube.DownSide.getVector())[1] == (*MyCube.DownSide.getVector())[3] 
        && (*MyCube.DownSide.getVector())[3] == (*MyCube.DownSide.getVector())[4] 
        && (*MyCube.DownSide.getVector())[4] == (*MyCube.DownSide.getVector())[5] 
        && (*MyCube.DownSide.getVector())[5] == (*MyCube.DownSide.getVector())[7] 
        && (*MyCube.DownSide.getVector())[7] == (*MyCube.DownSide.getVector())[6] 
        && (*MyCube.DownSide.getVector())[6] == (*MyCube.DownSide.getVector())[8] 
        && (*MyCube.DownSide.getVector())[8] == (*MyCube.DownSide.getVector())[2] 
        && (*MyCube.DownSide.getVector())[2] == (*MyCube.DownSide.getVector())[0])
        {
            if ((*MyCube.FrontSide.getVector())[6] == (*MyCube.FrontSide.getVector())[7] 
            && (*MyCube.FrontSide.getVector())[7] == (*MyCube.FrontSide.getVector())[8]){
                if ((*MyCube.RightSide.getVector())[6] == (*MyCube.RightSide.getVector())[7] 
                && (*MyCube.RightSide.getVector())[7] == (*MyCube.RightSide.getVector())[8])
                {
                    if ((*MyCube.LeftSide.getVector())[6] == (*MyCube.LeftSide.getVector())[7] 
                    && (*MyCube.LeftSide.getVector())[7] == (*MyCube.LeftSide.getVector())[8])
                    {
                        if ((*MyCube.BackSide.getVector())[6] == (*MyCube.BackSide.getVector())[7] 
                        && (*MyCube.BackSide.getVector())[7] == (*MyCube.BackSide.getVector())[8])
                        {
                            isOk = true;
                        }
                    }
                }
            }
        }
        return isOk;
    }
    bool isSolvedForThird(Cube &MyCube, std::vector<char> &TempMatrix){
        bool isOk = false;
        if (isSolvedForSecond)
        {
            if ((*MyCube.FrontSide.getVector())[3] == (*MyCube.FrontSide.getVector())[4] 
            && (*MyCube.FrontSide.getVector())[4] == (*MyCube.FrontSide.getVector())[5] 
            && (*MyCube.FrontSide.getVector())[5] == (*MyCube.FrontSide.getVector())[6])
            {
                if ((*MyCube.RightSide.getVector())[3] == (*MyCube.RightSide.getVector())[4] 
                && (*MyCube.RightSide.getVector())[4] == (*MyCube.RightSide.getVector())[5] 
                && (*MyCube.RightSide.getVector())[5] == (*MyCube.RightSide.getVector())[6])
                {
                    if ((*MyCube.LeftSide.getVector())[3] == (*MyCube.LeftSide.getVector())[4] 
                    && (*MyCube.LeftSide.getVector())[4] == (*MyCube.LeftSide.getVector())[5] 
                    && (*MyCube.LeftSide.getVector())[5] == (*MyCube.LeftSide.getVector())[6])
                    {
                        if ((*MyCube.BackSide.getVector())[3] == (*MyCube.BackSide.getVector())[4] 
                        && (*MyCube.BackSide.getVector())[4] == (*MyCube.BackSide.getVector())[5] 
                        && (*MyCube.BackSide.getVector())[5] == (*MyCube.BackSide.getVector())[6])
                        {
                            isOk = true;
                        }
                    }
                }
            }
        }
        return isOk;
    }
    bool isSolvedForFourth(Cube &MyCube, std::vector<char> &TempMatrix){
        bool isOk = false;
        if (isSolvedForThird)
        {
            if ((*MyCube.UpSide.getVector())[1] == 'Y' 
            && (*MyCube.UpSide.getVector())[1] == (*MyCube.UpSide.getVector())[3] 
            && (*MyCube.UpSide.getVector())[3] == (*MyCube.UpSide.getVector())[4] 
            && (*MyCube.UpSide.getVector())[4] == (*MyCube.UpSide.getVector())[5] 
            && (*MyCube.UpSide.getVector())[5] == (*MyCube.UpSide.getVector())[7])
            {
                isOk = true;
            }
        }
        return isOk;
    }
    bool isSolvedForFifth(Cube &MyCube, std::vector<char> &TempMatrix){
        bool isOk = false;
 
        int cntOfRot = 8;
        while (cntOfRot--)
        {
            char FrontRightTop = (*MyCube.FrontSide.getVector())[2];
            char UpRightDown = (*MyCube.UpSide.getVector())[8];
            char RightLeftTop = (*MyCube.RightSide.getVector())[0];
    
            char FrontLeftTop = (*MyCube.FrontSide.getVector())[0];
            char UpLeftDown = (*MyCube.UpSide.getVector())[6];
            char LeftRightTop = (*MyCube.LeftSide.getVector())[2];
    
            char LeftLeftTop = (*MyCube.LeftSide.getVector())[0];
            char UpLeftTop = (*MyCube.UpSide.getVector())[0];
            char BackRightTop = (*MyCube.BackSide.getVector())[2];
    
            char RightRightTop = (*MyCube.RightSide.getVector())[2];
            char UpRightTop = (*MyCube.UpSide.getVector())[2];
            char BackLeftTop = (*MyCube.BackSide.getVector())[0];
    
            char FrontCenter = (*MyCube.FrontSide.getVector())[4];
            char RightCenter = (*MyCube.RightSide.getVector())[4];
            char LeftCenter = (*MyCube.LeftSide.getVector())[4];
            char BackCenter = (*MyCube.BackSide.getVector())[4];
    
            std::vector<char> FirstCorn = {LeftLeftTop, UpLeftTop, BackRightTop};
            std::vector<char> SecondCorn = {RightRightTop, UpRightTop, BackLeftTop};
            std::vector<char> ThirdCorn = {FrontLeftTop, UpLeftDown, LeftRightTop};
            std::vector<char> FourthCorn = {FrontRightTop, UpRightDown, RightLeftTop};
    
            bool checkForFirst = false;
            bool checkForFirst2 = false;
            bool checkForSecond = false;
            bool checkForSecond2 = false;
            bool checkForThird = false;
            bool checkForThird2 = false;
            bool checkForFourth = false;
            bool checkForFourth2 = false;
    
        
            for (int i = 0; i < 3; i++)
            {
                if (FourthCorn[i] == FrontCenter)
                {
                    checkForFourth = true;
                }
                if (FourthCorn[i] == RightCenter)
                {
                    checkForFourth2 = true;
                }
            }
            if (!checkForFourth2)
            {
                checkForFourth = false;
            }
    
            for (int i = 0; i < 3; i++)
            {
                if (ThirdCorn[i] == FrontCenter)
                {
                    checkForThird = true;
                }
                if (ThirdCorn[i] == LeftCenter)
                {
                    checkForThird2 = true;
                }
            }
            if (!checkForThird2)
            {
                checkForThird = false;
            }
    
            for (int i = 0; i < 3; i++)
            {
                if (SecondCorn[i] == RightCenter)
                {
                    checkForSecond = true;
                }
                if (SecondCorn[i] == BackCenter)
                {
                    checkForSecond2 = true;
                }
            }
            if (!checkForSecond2)
            {
                checkForSecond = false;
            }
    
            for (int i = 0; i < 3; i++)
            {
                if (FirstCorn[i] == LeftCenter)
                {
                    checkForFirst = true;
                }
                if (FirstCorn[i] == BackCenter)
                {
                    checkForFirst2 = true;
                }
            }
            if (!checkForFirst2)
            {
                checkForFirst = false;
            }
    
            if ((checkForFirst && checkForFourth && checkForSecond && checkForThird))
            {
                isOk = true;
            }
            MyCube.U(MyCube, TempMatrix);
        }
        return isOk;
    }
    bool isSolvedForSixth(Cube &MyCube, std::vector<char> &TempMatrix){
        bool isOk = false;
        if ((*MyCube.UpSide.getVector())[1] == 'Y' 
        && (*MyCube.UpSide.getVector())[1] == (*MyCube.UpSide.getVector())[3] 
        && (*MyCube.UpSide.getVector())[3] == (*MyCube.UpSide.getVector())[4] 
        && (*MyCube.UpSide.getVector())[4] == (*MyCube.UpSide.getVector())[5] 
        && (*MyCube.UpSide.getVector())[5] == (*MyCube.UpSide.getVector())[7] 
        && (*MyCube.UpSide.getVector())[7] == (*MyCube.UpSide.getVector())[6] 
        && (*MyCube.UpSide.getVector())[6] == (*MyCube.UpSide.getVector())[8] 
        && (*MyCube.UpSide.getVector())[8] == (*MyCube.UpSide.getVector())[2] 
        && (*MyCube.UpSide.getVector())[2] == (*MyCube.UpSide.getVector())[0])
        {
            isOk = true;
        }
        return isOk;
    }
    bool isSolvedForSeventh(Cube &MyCube, std::vector<char> &TempMatrix){
        bool frontIsOk = false;
        bool backIsOk = false;
        bool upIsOk = false;
        bool leftIsOk = false;
        bool downIsOk = false;
        bool rightIsOk = false;
        if ((*MyCube.FrontSide.getVector())[8] == (*MyCube.FrontSide.getVector())[7] 
        && (*MyCube.FrontSide.getVector())[7] == (*MyCube.FrontSide.getVector())[6] 
        && (*MyCube.FrontSide.getVector())[6] == (*MyCube.FrontSide.getVector())[5] 
        && (*MyCube.FrontSide.getVector())[5] == (*MyCube.FrontSide.getVector())[4] 
        && (*MyCube.FrontSide.getVector())[4] == (*MyCube.FrontSide.getVector())[3] 
        && (*MyCube.FrontSide.getVector())[3] == (*MyCube.FrontSide.getVector())[2] 
        && (*MyCube.FrontSide.getVector())[2] == (*MyCube.FrontSide.getVector())[1] 
        && (*MyCube.FrontSide.getVector())[1] == (*MyCube.FrontSide.getVector())[0])
        {
            frontIsOk = true;
        }
        if ((*MyCube.BackSide.getVector())[8] == (*MyCube.BackSide.getVector())[7] 
        && (*MyCube.BackSide.getVector())[7] == (*MyCube.BackSide.getVector())[6] 
        && (*MyCube.BackSide.getVector())[6] == (*MyCube.BackSide.getVector())[5] 
        && (*MyCube.BackSide.getVector())[5] == (*MyCube.BackSide.getVector())[4] 
        && (*MyCube.BackSide.getVector())[4] == (*MyCube.BackSide.getVector())[3] 
        && (*MyCube.BackSide.getVector())[3] == (*MyCube.BackSide.getVector())[2] 
        && (*MyCube.BackSide.getVector())[2] == (*MyCube.BackSide.getVector())[1] 
        && (*MyCube.BackSide.getVector())[1] == (*MyCube.BackSide.getVector())[0])
        {
            backIsOk = true;
        }
        if ((*MyCube.UpSide.getVector())[8] == (*MyCube.UpSide.getVector())[7] 
        && (*MyCube.UpSide.getVector())[7] == (*MyCube.UpSide.getVector())[6] 
        && (*MyCube.UpSide.getVector())[6] == (*MyCube.UpSide.getVector())[5] 
        && (*MyCube.UpSide.getVector())[5] == (*MyCube.UpSide.getVector())[4] 
        && (*MyCube.UpSide.getVector())[4] == (*MyCube.UpSide.getVector())[3] 
        && (*MyCube.UpSide.getVector())[3] == (*MyCube.UpSide.getVector())[2] 
        && (*MyCube.UpSide.getVector())[2] == (*MyCube.UpSide.getVector())[1] 
        && (*MyCube.UpSide.getVector())[1] == (*MyCube.UpSide.getVector())[0])
        {
            upIsOk = true;
        }
        if ((*MyCube.LeftSide.getVector())[8] == (*MyCube.LeftSide.getVector())[7] 
        && (*MyCube.LeftSide.getVector())[7] == (*MyCube.LeftSide.getVector())[6] 
        && (*MyCube.LeftSide.getVector())[6] == (*MyCube.LeftSide.getVector())[5] 
        && (*MyCube.LeftSide.getVector())[5] == (*MyCube.LeftSide.getVector())[4] 
        && (*MyCube.LeftSide.getVector())[4] == (*MyCube.LeftSide.getVector())[3] 
        && (*MyCube.LeftSide.getVector())[3] == (*MyCube.LeftSide.getVector())[2] 
        && (*MyCube.LeftSide.getVector())[2] == (*MyCube.LeftSide.getVector())[1] 
        && (*MyCube.LeftSide.getVector())[1] == (*MyCube.LeftSide.getVector())[0])
        {
            leftIsOk = true;
        }
        if ((*MyCube.DownSide.getVector())[8] == (*MyCube.DownSide.getVector())[7] 
        && (*MyCube.DownSide.getVector())[7] == (*MyCube.DownSide.getVector())[6] 
        && (*MyCube.DownSide.getVector())[6] == (*MyCube.DownSide.getVector())[5] 
        && (*MyCube.DownSide.getVector())[5] == (*MyCube.DownSide.getVector())[4] 
        && (*MyCube.DownSide.getVector())[4] == (*MyCube.DownSide.getVector())[3] 
        && (*MyCube.DownSide.getVector())[3] == (*MyCube.DownSide.getVector())[2] 
        && (*MyCube.DownSide.getVector())[2] == (*MyCube.DownSide.getVector())[1] 
        && (*MyCube.DownSide.getVector())[1] == (*MyCube.DownSide.getVector())[0])
        {
            downIsOk = true;
        }
        if ((*MyCube.RightSide.getVector())[8] == (*MyCube.RightSide.getVector())[7] 
        && (*MyCube.RightSide.getVector())[7] == (*MyCube.RightSide.getVector())[6] 
        && (*MyCube.RightSide.getVector())[6] == (*MyCube.RightSide.getVector())[5] 
        && (*MyCube.RightSide.getVector())[5] == (*MyCube.RightSide.getVector())[4] 
        && (*MyCube.RightSide.getVector())[4] == (*MyCube.RightSide.getVector())[3] 
        && (*MyCube.RightSide.getVector())[3] == (*MyCube.RightSide.getVector())[2] 
        && (*MyCube.RightSide.getVector())[2] == (*MyCube.RightSide.getVector())[1] 
        && (*MyCube.RightSide.getVector())[1] == (*MyCube.RightSide.getVector())[0])
        {
            rightIsOk = true;
        }
        if (frontIsOk && backIsOk && upIsOk && leftIsOk && downIsOk && rightIsOk)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void WriteToFile(Cube &MyCube, bool makeRandomPositions){
        std::ofstream Positions;
        Positions.open("/home/rasul/projects/Cube/test.txt");
        int cnt = 10;
        if (Positions.is_open())
        {
            while (cnt--)
            {
                for (int i = 0; i < 9; i++)
                {
                    Positions << (*MyCube.FrontSide.getVector())[i] << ' ';
                }
                Positions << std::endl;
                for (int i = 0; i < 9; i++)
                {
                    Positions << (*MyCube.BackSide.getVector())[i] << ' ';
                }
                Positions << std::endl;
                for (int i = 0; i < 9; i++)
                {
                    Positions << (*MyCube.UpSide.getVector())[i] << ' ';
                }
                Positions << std::endl;
                for (int i = 0; i < 9; i++)
                {
                    Positions << (*MyCube.LeftSide.getVector())[i] << ' ';
                }
                Positions << std::endl;
                for (int i = 0; i < 9; i++)
                {
                    Positions << (*MyCube.DownSide.getVector())[i] << ' ';
                }
                Positions << std::endl;
                for (int i = 0; i < 9; i++)
                {
                    Positions << (*MyCube.RightSide.getVector())[i] << ' ';
                }
                Positions << std::endl;
                Positions << std::endl;
                if (makeRandomPositions)
                {
                    std::vector<char> TempMatrix(9);
                    srand(time(NULL));
                    MyCube.RightSideAlgorithm(MyCube, rand() % 6);
                    MyCube.LeftSideAlgorithm(MyCube, rand() % 6);
                    for (int i = 0; i < ((int)rand()) % 6; i++)
                        MyCube.U(MyCube, TempMatrix);
                    for (int i = 0; i < ((int)rand()) % 6; i++)
                        MyCube.R(MyCube, TempMatrix);
                    for (int i = 0; i < ((int)rand()) % 6; i++)
                        MyCube.D(MyCube, TempMatrix);
                    for (int i = 0; i < ((int)rand()) % 6; i++)
                        MyCube.B(MyCube, TempMatrix);
                    for (int i = 0; i < ((int)rand()) % 6; i++)
                        MyCube.L(MyCube, TempMatrix);
                    for (int i = 0; i < ((int)rand()) % 6; i++)
                        MyCube.F(MyCube, TempMatrix);
                }
                else
                {
                    break;
                }
            }
        }
        Positions.close();
        std::cout << "Data recorded";
        exit(0);
    }
    void GetFromFile(Cube &MyCube, int numberOfCube){
        int size = 3;
        std::vector<char> FrontPosition(size * size);
        std::vector<char> BackPosition(size * size);
        std::vector<char> UpPosition(size * size);
        std::vector<char> LeftPosition(size * size);
        std::vector<char> DownPosition(size * size);
        std::vector<char> RightPosition(size * size);
    
        std::string sideOfCube;
        int check = numberOfCube;
        numberOfCube *= 7;
        if (check != 0)
            numberOfCube++;
        std::ifstream getPositions("/home/rasul/projects/Cube/test.txt");
        int cnt = 0;
        int cntInRot = 0;
        if (getPositions.is_open())
        {
            while (getline(getPositions, sideOfCube))
            {
                bool flag = false;
                cnt++;
                if ((cnt < numberOfCube + 6 + !numberOfCube) && cnt >= numberOfCube)
                {
                    cntInRot++;
                    if (cntInRot == 1)
                    {
                        for (int i = 0; i < 9; i++)
                        {
                            FrontPosition[i] = sideOfCube[i * 2];
                        }
                    }
                    if (cntInRot == 2)
                    {
                        for (int i = 0; i < 9; i++)
                        {
                            BackPosition[i] = sideOfCube[i * 2];
                        }
                    }
                    if (cntInRot == 3)
                    {
                        for (int i = 0; i < 9; i++)
                        {
                            UpPosition[i] = sideOfCube[i * 2];
                        }
                    }
                    if (cntInRot == 4)
                    {
                        for (int i = 0; i < 9; i++)
                        {
                            LeftPosition[i] = sideOfCube[i * 2];
                        }
                    }
                    if (cntInRot == 5)
                    {
                        for (int i = 0; i < 9; i++)
                        {
                            DownPosition[i] = sideOfCube[i * 2];
                        }
                    }
                    if (cntInRot == 6)
                    {
                        for (int i = 0; i < 9; i++)
                        {
                            RightPosition[i] = sideOfCube[i * 2];
                        }
                    }
                }
            }
        }
        getPositions.close();
        MyCube.setPosition("Front", FrontPosition);
        MyCube.setPosition("Back", BackPosition);
        MyCube.setPosition("Left", LeftPosition);
        MyCube.setPosition("Right", RightPosition);
        MyCube.setPosition("Up", UpPosition);
        MyCube.setPosition("Down", DownPosition);
    }
    void FirstStepSolve(Cube &MyCube, std::vector<char> &TempMatrix){
        std::string ansForFirst = "Commands: ";
        if (!isSolvedForFirst(MyCube, TempMatrix))
        {
            MyCube.ChangeOrientation("Up", 1);
            ansForFirst += std::string("Up, ");
            bool check = true;
    
            while (check)
            {
                check = false;
                if ((*MyCube.FrontSide.getVector())[3] == 'W')
                {
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[3] != 'W')
                        {
                            MyCube.L_(MyCube, TempMatrix);
                            ansForFirst += std::string("L_, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                }
                if ((*MyCube.FrontSide.getVector())[5] == 'W')
                {
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[5] != 'W')
                        {
                            MyCube.R(MyCube, TempMatrix);
                            ansForFirst += std::string("R, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                }
    
                if ((*MyCube.FrontSide.getVector())[1] == 'W')
                {
                    MyCube.F(MyCube, TempMatrix);
                    ansForFirst += std::string("F ");
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[5] != 'W')
                        {
                            MyCube.R(MyCube, TempMatrix);
                            ansForFirst += std::string("R ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U ");
                        }
                    }
                }
                if ((*MyCube.FrontSide.getVector())[7] == 'W')
                {
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[7] != 'W')
                        {
                            MyCube.F(MyCube, TempMatrix);
                            ansForFirst += std::string("F ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U ");
                        }
                    }
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[3] != 'W')
                        {
                            MyCube.L_(MyCube, TempMatrix);
                            ansForFirst += std::string("L_ ");
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U ");
                        }
                    }
                }
            }
    
            MyCube.ChangeOrientation("Right", 1);
            ansForFirst += std::string("Right ");
            check = true;
            while (check)
            {
                check = false;
                if ((*MyCube.FrontSide.getVector())[3] == 'W')
                {
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[3] != 'W')
                        {
                            MyCube.L_(MyCube, TempMatrix);
                            ansForFirst += std::string("L_ ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                }
                if ((*MyCube.FrontSide.getVector())[5] == 'W')
                {
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[5] != 'W')
                        {
                            MyCube.R(MyCube, TempMatrix);
                            ansForFirst += std::string("R, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                }
                if ((*MyCube.FrontSide.getVector())[1] == 'W')
                {
                    MyCube.F(MyCube, TempMatrix);
                    ansForFirst += std::string("F, ");
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[5] != 'W')
                        {
                            MyCube.R(MyCube, TempMatrix);
                            ansForFirst += std::string("R, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                }
                if ((*MyCube.FrontSide.getVector())[7] == 'W')
                {
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[7] != 'W')
                        {
                            MyCube.F(MyCube, TempMatrix);
                            ansForFirst += std::string("F, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[3] != 'W')
                        {
                            MyCube.L_(MyCube, TempMatrix);
                            ansForFirst += std::string("L_, ");
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                }
            }
    
            MyCube.ChangeOrientation("Right", 1);
            ansForFirst += std::string("Right, ");
            check = true;
            while (check)
            {
                check = false;
                if ((*MyCube.FrontSide.getVector())[3] == 'W')
                {
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[3] != 'W')
                        {
                            MyCube.L_(MyCube, TempMatrix);
                            ansForFirst += std::string("L_, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                }
                if ((*MyCube.FrontSide.getVector())[5] == 'W')
                {
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[5] != 'W')
                        {
                            MyCube.R(MyCube, TempMatrix);
                            ansForFirst += std::string("R, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                }
                if ((*MyCube.FrontSide.getVector())[1] == 'W')
                {
                    MyCube.F(MyCube, TempMatrix);
                    ansForFirst += std::string("F, ");
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[5] != 'W')
                        {
                            MyCube.R(MyCube, TempMatrix);
                            ansForFirst += std::string("R, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                }
                if ((*MyCube.FrontSide.getVector())[7] == 'W')
                {
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[7] != 'W')
                        {
                            MyCube.F(MyCube, TempMatrix);
                            ansForFirst += std::string("F, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[3] != 'W')
                        {
                            MyCube.L_(MyCube, TempMatrix);
                            ansForFirst += std::string("L_, ");
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                }
            }
    
            MyCube.ChangeOrientation("Right", 1);
            ansForFirst += std::string("Right, ");
            check = true;
            while (check)
            {
                check = false;
                if ((*MyCube.FrontSide.getVector())[3] == 'W')
                {
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[3] != 'W')
                        {
                            MyCube.L_(MyCube, TempMatrix);
                            ansForFirst += std::string("L_, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                }
                if ((*MyCube.FrontSide.getVector())[5] == 'W')
                {
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[5] != 'W')
                        {
                            MyCube.R(MyCube, TempMatrix);
                            ansForFirst += std::string("R, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                }
                if ((*MyCube.FrontSide.getVector())[1] == 'W')
                {
                    MyCube.F(MyCube, TempMatrix);
                    ansForFirst += std::string("F, ");
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[5] != 'W')
                        {
                            MyCube.R(MyCube, TempMatrix);
                            ansForFirst += std::string("R, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                }
                if ((*MyCube.FrontSide.getVector())[7] == 'W')
                {
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[7] != 'W')
                        {
                            MyCube.F(MyCube, TempMatrix);
                            ansForFirst += std::string("F, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                    while (true)
                    {
                        if ((*MyCube.UpSide.getVector())[3] != 'W')
                        {
                            MyCube.L_(MyCube, TempMatrix);
                            ansForFirst += std::string("L_, ");
                            break;
                        }
                        else
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                        }
                    }
                }
            }
            MyCube.ChangeOrientation("Right", 1);
            ansForFirst += std::string("Right, ");
            MyCube.ChangeOrientation("Down", 1);
            ansForFirst += std::string("Down, ");
            check = true;
            while (check)
            {
                check = false;
                if ((*MyCube.FrontSide.getVector())[3] == 'W')
                {
                    while (true)
                    {
                        if ((*MyCube.BackSide.getVector())[5] != 'W')
                        {
                            MyCube.L_(MyCube, TempMatrix);
                            MyCube.L_(MyCube, TempMatrix);
                            ansForFirst += std::string("L_, L_, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.B(MyCube, TempMatrix);
                            ansForFirst += std::string("B, ");
                        }
                    }
                }
                if ((*MyCube.FrontSide.getVector())[5] == 'W')
                {
                    while (true)
                    {
                        if ((*MyCube.BackSide.getVector())[3] != 'W')
                        {
                            MyCube.R(MyCube, TempMatrix);
                            MyCube.R(MyCube, TempMatrix);
                            ansForFirst += std::string("R, ");
                            ansForFirst += std::string("R, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.B(MyCube, TempMatrix);
                            ansForFirst += std::string("B, ");
                        }
                    }
                }
                if ((*MyCube.FrontSide.getVector())[1] == 'W')
                {
    
                    while (true)
                    {
                        if ((*MyCube.BackSide.getVector())[1] != 'W')
                        {
                            MyCube.U(MyCube, TempMatrix);
                            MyCube.U(MyCube, TempMatrix);
                            ansForFirst += std::string("U, ");
                            ansForFirst += std::string("U, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.B(MyCube, TempMatrix);
                            ansForFirst += std::string("B, ");
                        }
                    }
                }
                if ((*MyCube.FrontSide.getVector())[7] == 'W')
                {
                    while (true)
                    {
                        if ((*MyCube.BackSide.getVector())[7] != 'W')
                        {
                            MyCube.D(MyCube, TempMatrix);
                            MyCube.D(MyCube, TempMatrix);
                            ansForFirst += std::string("D, ");
                            ansForFirst += std::string("D, ");
                            check = true;
                            break;
                        }
                        else
                        {
                            MyCube.B(MyCube, TempMatrix);
                            ansForFirst += std::string("B, ");
                        }
                    }
                }
            }
            MyCube.ChangeOrientation("Up", 1);
            ansForFirst += std::string("Up, ");
            MyCube.ChangeOrientation("Left", 1);
            ansForFirst += std::string("Left, ");
    
            // White cross on Down Side
            int QtyIt = 4;
            while (QtyIt)
            {
                MyCube.ChangeOrientation("Right", 1);
                ansForFirst += std::string("Right, ");
                check = true;
                while (check)
                {
                    check = false;
                    if (((*MyCube.FrontSide.getVector())[1] == (*MyCube.FrontSide.getVector())[4]) 
                    && (*MyCube.UpSide.getVector())[7] == 'W')
                    {
                        MyCube.F(MyCube, TempMatrix);
                        ansForFirst += std::string("F, ");
                        MyCube.F(MyCube, TempMatrix);
                        ansForFirst += std::string("F, ");
    
                        check = true;
                        QtyIt--;
                        break;
                    }
                    else
                    {
                        MyCube.U(MyCube, TempMatrix);
                        ansForFirst += std::string("U, ");
                        check = true;
                    }
                }
            }
        }
    
        for (int i = 0; i < ansForFirst.size(); i++)
        {
            std::cout << ansForFirst[i];
        }
        std::cout << std::endl;
    }
    void SecondStepSolve(Cube &MyCube, std::vector<char> &TempMatrix){
        std::string ansForSecond = "Commands: ";
        if (!isSolvedForSecond(MyCube, TempMatrix))
        {
            //// Totally covered WhiteSide
            bool checkIsChangeOrient = false;
            if ((*MyCube.FrontSide.getVector())[4] == 'W')
            {
                MyCube.ChangeOrientation("Up", 1);
                ansForSecond += std::string("Up, ");
                checkIsChangeOrient == true;
            }
    
            if (checkIsChangeOrient)
            {
                MyCube.ChangeOrientation("Down", 1);
                ansForSecond += std::string("Down, ");
            }
        
            // For Up Cornes
            if (true)
            {
                int cntOfRotatation = 16;
                int top = 0;
                while (cntOfRotatation--)
                {
                    int cntOfCornToCheck = 16;
                    while (cntOfCornToCheck--)
                    {
                        char TopFrontCorn = (*MyCube.FrontSide.getVector())[2];
                        char TopRightCorn = (*MyCube.RightSide.getVector())[0];
                        char DownUpCorn = (*MyCube.UpSide.getVector())[8];
                        char FrontCenter = (*MyCube.FrontSide.getVector())[4];
                        char RightCenter = (*MyCube.RightSide.getVector())[4];
                        char DownFrontCorn = (*MyCube.FrontSide.getVector())[8];
                        char DownRightCorn = (*MyCube.RightSide.getVector())[6];
                        char TopDownCorn = (*MyCube.DownSide.getVector())[2];
                        std::vector<char> UpCorn = {DownUpCorn, TopFrontCorn, TopRightCorn};
                        std::vector<char> DownCorn = {TopDownCorn, DownFrontCorn, DownRightCorn};
                        for (int i = 0; i < 3; i++)
                        {
                            if (UpCorn[i] == 'W')
                            {
                                bool check1 = false, check2 = false;
                                for (int j = 0; j < 3; j++)
                                {
                                    if (UpCorn[j] == (*MyCube.FrontSide.getVector())[4])
                                    {
                                        check1 = true;
                                    }
                                    if (UpCorn[j] == (*MyCube.RightSide.getVector())[4])
                                    {
                                        check2 = true;
                                    }
                                }
    
                                if (check1 && check2)
                                {
                                    while (true)
                                    {
                                        MyCube.RightSideAlgorithm(MyCube, 1);
                                        ansForSecond += std::string("RR, ");
                                        if (((*MyCube.DownSide.getVector())[2] == 'W') 
                                        && ((*MyCube.FrontSide.getVector())[8] == (*MyCube.FrontSide.getVector())[4]) 
                                        && ((*MyCube.RightSide.getVector())[4] == (*MyCube.RightSide.getVector())[4]))
                                            break;
                                    }
                                }
                            }
                        }
    
                        MyCube.ChangeOrientation("Right", 1);
                        ansForSecond += std::string("Right, ");
                    }
                    MyCube.U(MyCube, TempMatrix);
                    ansForSecond += std::string("U, ");
                }
            }
            // For Down Cornes
            if (true)
            {
    
                int cntOfRotatation = 16;
                int top = 0;
                while (cntOfRotatation--)
                {
                    int cntOfCornToCheck = 16;
                    while (cntOfCornToCheck--)
                    {
                        char TopFrontCorn = (*MyCube.FrontSide.getVector())[2];
                        char TopRightCorn = (*MyCube.RightSide.getVector())[0];
                        char DownUpCorn = (*MyCube.UpSide.getVector())[8];
                        char FrontCenter = (*MyCube.FrontSide.getVector())[4];
                        char RightCenter = (*MyCube.RightSide.getVector())[4];
                        char DownFrontCorn = (*MyCube.FrontSide.getVector())[8];
                        char DownRightCorn = (*MyCube.RightSide.getVector())[6];
                        char TopDownCorn = (*MyCube.DownSide.getVector())[2];
                        std::vector<char> UpCorn = {DownUpCorn, TopFrontCorn, TopRightCorn};
                        std::vector<char> DownCorn = {TopDownCorn, DownFrontCorn, DownRightCorn};
                        for (int i = 0; i < 3; i++)
                        {
                            if (DownCorn[i] == 'W')
                            {
                                bool check1 = false, check2 = false;
                                for (int j = 0; j < 3; j++)
                                {
                                    if (DownCorn[j] == (*MyCube.FrontSide.getVector())[4])
                                    {
                                        check1 = true;
                                    }
                                    if (DownCorn[j] == (*MyCube.RightSide.getVector())[4])
                                    {
                                        check2 = true;
                                    }
                                }
    
                                if (check1 && check2)
                                {
                                    while (true)
                                    {
                                        MyCube.RightSideAlgorithm(MyCube, 1);
                                        ansForSecond += std::string("RR, ");
                                        if (((*MyCube.DownSide.getVector())[2] == 'W') 
                                        && ((*MyCube.FrontSide.getVector())[8] == (*MyCube.FrontSide.getVector())[4]) 
                                        && ((*MyCube.RightSide.getVector())[4] == (*MyCube.RightSide.getVector())[4]))
                                            break;
                                    }
                                }
                            }
                        }
    
                        MyCube.ChangeOrientation("Right", 1);
                        ansForSecond += std::string("Right, ");
                    }
                    MyCube.D(MyCube, TempMatrix);
                    ansForSecond += std::string("D, ");
                }
            }
        }
        for (int i = 0; i < ansForSecond.size(); i++)
        {
            std::cout << ansForSecond[i];
        }
        std::cout << std::endl;
    }
    void ThirdStepSolve(Cube &MyCube, std::vector<char> &TempMatrix){
        std::string ansForThird = "Commands: ";
        if (!isSolvedForThird(MyCube, TempMatrix))
        {
            int QtyOfWrongEndgesOnSecondLine = 0;
            int cntTemp = 4;
            while (cntTemp--)
            {
                if (((*MyCube.FrontSide.getVector())[3] != (*MyCube.FrontSide.getVector())[4]) 
                || ((*MyCube.LeftSide.getVector())[5] != (*MyCube.LeftSide.getVector())[4]))
                {
                    QtyOfWrongEndgesOnSecondLine++;
                }
                MyCube.ChangeOrientation("Right", 1);
                ansForThird += std::string("Right, ");
            }
    
            while (QtyOfWrongEndgesOnSecondLine)
            {
                bool IsChange = false;
                int QtyUp = 16;
                while (QtyUp--)
                {
                    int QtyOrientation = 16;
                    while (QtyOrientation--)
                    {
                        if (((*MyCube.FrontSide.getVector())[4] == (*MyCube.FrontSide.getVector())[1]) 
                        && ((*MyCube.UpSide.getVector())[7] != 'Y') && ((*MyCube.FrontSide.getVector())[1] != 'Y'))
                        {
                            if ((*MyCube.LeftSide.getVector())[4] == (*MyCube.UpSide.getVector())[7])
                            {
                                MyCube.U_(MyCube, TempMatrix);
                                ansForThird += std::string("U_, ");
                                MyCube.LeftSideAlgorithm(MyCube, 1);
                                ansForThird += std::string("LL, ");
                                MyCube.ChangeOrientation("Left", 1);
                                ansForThird += std::string("Left, ");
                                MyCube.RightSideAlgorithm(MyCube, 1);
                                ansForThird += std::string("RR, ");
                                MyCube.ChangeOrientation("Right", 1);
                                ansForThird += std::string("Right, ");
                                QtyOfWrongEndgesOnSecondLine--;
                                IsChange = true;
                            }
                            if ((*MyCube.RightSide.getVector())[4] == (*MyCube.UpSide.getVector())[7])
                            {
                                MyCube.U(MyCube, TempMatrix);
                                ansForThird += std::string("U, ");
                                MyCube.RightSideAlgorithm(MyCube, 1);
                                ansForThird += std::string("RR, ");
                                MyCube.ChangeOrientation("Right", 1);
                                ansForThird += std::string("Right, ");
                                MyCube.LeftSideAlgorithm(MyCube, 1);
                                ansForThird += std::string("LL, ");
                                MyCube.ChangeOrientation("Left", 1);
                                ansForThird += std::string("Left, ");
                                QtyOfWrongEndgesOnSecondLine--;
                                IsChange = true;
                            }
                        }
                        MyCube.ChangeOrientation("Right", 1);
                        ansForThird += std::string("Right, ");
                    }
                    MyCube.U(MyCube, TempMatrix);
                    ansForThird += std::string("U, ");
                }
                bool isChangeInLastCase = false;
                if (!IsChange)
                {
                    while (!isChangeInLastCase)
                    {
                        if ((((*MyCube.FrontSide.getVector())[5] != (*MyCube.FrontSide.getVector())[4]) 
                        || ((*MyCube.RightSide.getVector())[3] != (*MyCube.RightSide.getVector())[4])) 
                        && (((*MyCube.FrontSide.getVector())[5] != 'Y') && ((*MyCube.RightSide.getVector())[3] != 'Y')))
                        {
                            MyCube.U(MyCube, TempMatrix);
                            ansForThird += std::string("U, ");
                            MyCube.RightSideAlgorithm(MyCube, 1);
                            ansForThird += std::string("RR, ");
                            MyCube.ChangeOrientation("Right", 1);
                            ansForThird += std::string("Right, ");
                            MyCube.LeftSideAlgorithm(MyCube, 1);
                            ansForThird += std::string("LL, ");
                            MyCube.ChangeOrientation("Left", 1);
                            ansForThird += std::string("Left, ");
                            isChangeInLastCase = true;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < ansForThird.size(); i++)
        {
            std::cout << ansForThird[i];
        }
        std::cout << std::endl;
        
    }
    void FourthStepSolve(Cube &MyCube, std::vector<char> &TempMatrix){
        std::string ansForFourth = "Commands: ";
        char FixPosOfCube = '*';
        if (!isSolvedForFourth(MyCube, TempMatrix))
        {
    
            if (((*MyCube.UpSide.getVector())[4] == 'Y') 
            && (!((*MyCube.UpSide.getVector())[3] == 'Y' && (*MyCube.UpSide.getVector())[3] == (*MyCube.UpSide.getVector())[4] && (*MyCube.UpSide.getVector())[4] == (*MyCube.UpSide.getVector())[5])) 
            && (!((*MyCube.UpSide.getVector())[1] == 'Y' && (*MyCube.UpSide.getVector())[1] == (*MyCube.UpSide.getVector())[4] && (*MyCube.UpSide.getVector())[4] == (*MyCube.UpSide.getVector())[7])) 
            && (!((*MyCube.UpSide.getVector())[1] == 'Y' && (*MyCube.UpSide.getVector())[1] == (*MyCube.UpSide.getVector())[4] && (*MyCube.UpSide.getVector())[4] == (*MyCube.UpSide.getVector())[3])) 
            && (!((*MyCube.UpSide.getVector())[3] == 'Y' && (*MyCube.UpSide.getVector())[3] == (*MyCube.UpSide.getVector())[4] && (*MyCube.UpSide.getVector())[4] == (*MyCube.UpSide.getVector())[7])) 
            && (!((*MyCube.UpSide.getVector())[5] == 'Y' && (*MyCube.UpSide.getVector())[5] == (*MyCube.UpSide.getVector())[4] && (*MyCube.UpSide.getVector())[4] == (*MyCube.UpSide.getVector())[7])) 
            && (!((*MyCube.UpSide.getVector())[1] == 'Y' && (*MyCube.UpSide.getVector())[1] == (*MyCube.UpSide.getVector())[4] && (*MyCube.UpSide.getVector())[4] == (*MyCube.UpSide.getVector())[5])))
            {
                MyCube.F(MyCube, TempMatrix);
                ansForFourth += std::string("F, ");
                MyCube.RightSideAlgorithm(MyCube, 2);
                ansForFourth += std::string("RR, RR, ");
                MyCube.F_(MyCube, TempMatrix);
                ansForFourth += std::string("F_, ");
            }
    
            // Yellow Cross
            // First Case (horizontal line)
            if ((*MyCube.UpSide.getVector())[3] == 'Y' 
            && (*MyCube.UpSide.getVector())[3] == (*MyCube.UpSide.getVector())[4] 
            && (*MyCube.UpSide.getVector())[4] == (*MyCube.UpSide.getVector())[5])
            {
                MyCube.F(MyCube, TempMatrix);
                ansForFourth += std::string("F, ");
                MyCube.RightSideAlgorithm(MyCube, 1);
                ansForFourth += std::string("RR, ");
                MyCube.F_(MyCube, TempMatrix);
                ansForFourth += std::string("F_, ");
            }
            if ((*MyCube.UpSide.getVector())[1] == 'Y' 
            && (*MyCube.UpSide.getVector())[1] == (*MyCube.UpSide.getVector())[4] 
            && (*MyCube.UpSide.getVector())[4] == (*MyCube.UpSide.getVector())[7])
            {
    
                MyCube.ChangeOrientation("Right", 1);
                ansForFourth += std::string("Right, ");
                MyCube.F(MyCube, TempMatrix);
                ansForFourth += std::string("F, ");
                MyCube.RightSideAlgorithm(MyCube, 1);
                ansForFourth += std::string("RR, ");
                MyCube.F_(MyCube, TempMatrix);
                ansForFourth += std::string("F_, ");
                MyCube.ChangeOrientation("Left", 1);
                ansForFourth += std::string("Left, ");
            }
    
            // Second case (right angle)
            if (!isSolvedForFourth(MyCube, TempMatrix))
            {
                int LocalCntForRotation = 4;
                FixPosOfCube = (*MyCube.FrontSide.getVector())[4];
                while (LocalCntForRotation--)
                {
                    if ((*MyCube.UpSide.getVector())[1] == 'Y' 
                    && (*MyCube.UpSide.getVector())[4] == (*MyCube.UpSide.getVector())[1] 
                    && (*MyCube.UpSide.getVector())[3] == (*MyCube.UpSide.getVector())[1])
                    {
                        MyCube.F(MyCube, TempMatrix);
                        ansForFourth += std::string("F, ");
                        MyCube.RightSideAlgorithm(MyCube, 2);
                        ansForFourth += std::string("RR, RR, ");
                        MyCube.F_(MyCube, TempMatrix);
                        ansForFourth += std::string("F_, ");
                        break;
                    }
                    MyCube.ChangeOrientation("Right", 1);
                    ansForFourth += std::string("Right, ");
                }
            }
        }
    
        for (int i = 0; i < ansForFourth.size(); i++)
        {
            std::cout << ansForFourth[i];
        }
        std::cout << std::endl;
    }
    void FifthStepSolve(Cube &MyCube, std::vector<char> &TempMatrix){
        std::string ansForFifth = "Commands: ";
        if (!isSolvedForFifth(MyCube, TempMatrix))
        {
            // Modify Up Cornes
    
            // Diag
            int cntOfRot = 4;
            while (cntOfRot--)
            {
                char FrontRightTop = (*MyCube.FrontSide.getVector())[2];
                char UpRightDown = (*MyCube.UpSide.getVector())[8];
                char RightLeftTop = (*MyCube.RightSide.getVector())[0];
    
                char FrontLeftTop = (*MyCube.FrontSide.getVector())[0];
                char UpLeftDown = (*MyCube.UpSide.getVector())[6];
                char LeftRightTop = (*MyCube.LeftSide.getVector())[2];
    
                char LeftLeftTop = (*MyCube.LeftSide.getVector())[0];
                char UpLeftTop = (*MyCube.UpSide.getVector())[0];
                char BackRightTop = (*MyCube.BackSide.getVector())[2];
    
                char RightRightTop = (*MyCube.RightSide.getVector())[2];
                char UpRightTop = (*MyCube.UpSide.getVector())[2];
                char BackLeftTop = (*MyCube.BackSide.getVector())[0];
    
                char FrontCenter = (*MyCube.FrontSide.getVector())[4];
                char RightCenter = (*MyCube.RightSide.getVector())[4];
                char LeftCenter = (*MyCube.LeftSide.getVector())[4];
                char BackCenter = (*MyCube.BackSide.getVector())[4];
    
                std::vector<char> FirstCorn = {LeftLeftTop, UpLeftTop, BackRightTop};
                std::vector<char> SecondCorn = {RightRightTop, UpRightTop, BackLeftTop};
                std::vector<char> ThirdCorn = {FrontLeftTop, UpLeftDown, LeftRightTop};
                std::vector<char> FourthCorn = {FrontRightTop, UpRightDown, RightLeftTop};
    
                bool checkForFirst = false;
                bool checkForFirst2 = false;
                bool checkForSecond = false;
                bool checkForSecond2 = false;
                bool checkForThird = false;
                bool checkForThird2 = false;
                bool checkForFourth = false;
                bool checkForFourth2 = false;
    
                for (int i = 0; i < 3; i++)
                {
                    if (FourthCorn[i] == FrontCenter)
                    {
                        checkForFourth = true;
                    }
                    if (FourthCorn[i] == RightCenter)
                    {
                        checkForFourth2 = true;
                    }
                }
                if (!checkForFourth2)
                {
                    checkForFourth = false;
                }
    
                for (int i = 0; i < 3; i++)
                {
                    if (ThirdCorn[i] == FrontCenter)
                    {
                        checkForThird = true;
                    }
                    if (ThirdCorn[i] == LeftCenter)
                    {
                        checkForThird2 = true;
                    }
                }
                if (!checkForThird2)
                {
                    checkForThird = false;
                }
    
                for (int i = 0; i < 3; i++)
                {
                    if (SecondCorn[i] == RightCenter)
                    {
                        checkForSecond = true;
                    }
                    if (SecondCorn[i] == BackCenter)
                    {
                        checkForSecond2 = true;
                    }
                }
                if (!checkForSecond2)
                {
                    checkForSecond = false;
                }
    
                for (int i = 0; i < 3; i++)
                {
                    if (FirstCorn[i] == LeftCenter)
                    {
                        checkForFirst = true;
                    }
                    if (FirstCorn[i] == BackCenter)
                    {
                        checkForFirst2 = true;
                    }
                }
                if (!checkForFirst2)
                {
                    checkForFirst = false;
                }
    
                if ((checkForFirst && checkForFourth) || (checkForSecond && checkForThird))
                {
                    MyCube.RightSideAlgorithm(MyCube, 3);
                    ansForFifth += std::string("RR, RR, RR ");
                    MyCube.ChangeOrientation("Right", 1);
                    ansForFifth += std::string("Right, ");
                    MyCube.LeftSideAlgorithm(MyCube, 3);
                    ansForFifth += std::string("LL, LL, LL ");
                    MyCube.ChangeOrientation("Left", 1);
                    ansForFifth += std::string("Left, ");
                }
                else
                {
                    MyCube.U(MyCube, TempMatrix);
                    ansForFifth += std::string("U, ");
                }
            }
            char fixFrontCenter = (*MyCube.FrontSide.getVector())[4];
            bool nextStep = false;
            int QtyGlob = 4;
            int cnt = 0;
            while (QtyGlob--)
            {
                int QtyLocal = 4;
                while (QtyLocal--)
                {
                    char RightTopFrontCorn = (*MyCube.FrontSide.getVector())[2];
                    char RightTopRightCorn = (*MyCube.RightSide.getVector())[0];
                    char RightDownUpCorn = (*MyCube.UpSide.getVector())[8];
                    char FrontCenter = (*MyCube.FrontSide.getVector())[4];
                    char RightCenter = (*MyCube.RightSide.getVector())[4];
                    char LeftCenter = (*MyCube.LeftSide.getVector())[4];
                    char LeftTopFrontCorn = (*MyCube.FrontSide.getVector())[0];
                    char LeftUpLeftCorn = (*MyCube.LeftSide.getVector())[2];
                    char LeftTopDownCorn = (*MyCube.UpSide.getVector())[6];
                    std::vector<char> RightCorn = {RightTopFrontCorn, RightTopRightCorn, RightDownUpCorn};
                    std::vector<char> LeftCorn = {LeftTopFrontCorn, LeftUpLeftCorn, LeftTopDownCorn};
                    bool check1Right = false, check2Right = false, checkGlobal = false;
                    bool check1Left = false;
                    bool check2Left = false;
    
                
    
                
                    for (int i = 0; i < 3; i++)
                    {
                        if (RightCorn[i] == FrontCenter)
                        {
                            check1Right = true;
                        }
                        if (RightCorn[i] == RightCenter)
                        {
                            check2Right = true;
                        }
                    }
    
                    for (int i = 0; i < 3; i++)
                    {
                        if (LeftCorn[i] == FrontCenter)
                        {
                            check1Left = true;
                        }
                        if (LeftCorn[i] == LeftCenter)
                        {
                            check2Left = true;
                        }
                    }
    
                    if (check1Right && check2Right && check1Left && check2Left)
                    {
                        checkGlobal = true;
                    }
                    else
                    {
                        check1Right = false;
                        check2Right = false;
                        check1Left = false;
                        check2Left = false;
                    }
    
                    if (checkGlobal)
                    {
                        nextStep = true;
                        break;
                    }
                    MyCube.ChangeOrientation("Right", 1);
                    ansForFifth += std::string("Right, ");
                    cnt++;
                }
                if (nextStep)
                {
                    MyCube.ChangeOrientation("Right", 1);
                    ansForFifth += std::string("Right, ");
                    break;
                }
                MyCube.U(MyCube, TempMatrix);
                ansForFifth += std::string("U, ");
            }
    
            MyCube.RightSideAlgorithm(MyCube, 3);
            ansForFifth += std::string("RR, RR, RR, ");
            MyCube.ChangeOrientation("Right", 1);
            ansForFifth += std::string("Right, ");
            MyCube.LeftSideAlgorithm(MyCube, 3);
            ansForFifth += std::string("LL, LL, LL ");
            MyCube.ChangeOrientation("Left", 1);
            ansForFifth += std::string("Left, ");
    
            while (true)
            {
                char RightTopFrontCorn = (*MyCube.FrontSide.getVector())[2];
                char RightTopRightCorn = (*MyCube.RightSide.getVector())[0];
                char RightDownUpCorn = (*MyCube.UpSide.getVector())[8];
                char FrontCenter = (*MyCube.FrontSide.getVector())[4];
                char RightCenter = (*MyCube.RightSide.getVector())[4];
                char LeftCenter = (*MyCube.LeftSide.getVector())[4];
                char LeftTopFrontCorn = (*MyCube.FrontSide.getVector())[0];
                char LeftUpLeftCorn = (*MyCube.LeftSide.getVector())[2];
                char LeftTopDownCorn = (*MyCube.UpSide.getVector())[6];
                std::vector<char> RightCorn = {RightTopFrontCorn, RightTopRightCorn, RightDownUpCorn};
                std::vector<char> LeftCorn = {LeftTopFrontCorn, LeftUpLeftCorn, LeftTopDownCorn};
    
                bool check1Right = false, check2Right = false, checkGlobal = false;
                bool check1Left = false;
                bool check2Left = false;
                for (int i = 0; i < 3; i++)
                {
                    if (RightCorn[i] == FrontCenter)
                    {
                        check1Right = true;
                    }
                    if (RightCorn[i] == RightCenter)
                    {
                        check2Right = true;
                    }
                }
    
                for (int i = 0; i < 3; i++)
                {
                    if (LeftCorn[i] == FrontCenter)
                    {
                        check1Left = true;
                    }
                    if (LeftCorn[i] == LeftCenter)
                    {
                        check2Left = true;
                    }
                }
    
                if (check1Right && check2Right && check1Left && check2Left)
                {
                    checkGlobal = true;
                }
                else
                {
                    check1Right = false;
                    check2Right = false;
                    check1Left = false;
                    check2Left = false;
                }
    
                if (checkGlobal)
                {
                    break;
                }
                MyCube.U(MyCube, TempMatrix);
                ansForFifth += std::string("U, ");
            }
            while ((*MyCube.FrontSide.getVector())[4] != fixFrontCenter)
            {
                MyCube.ChangeOrientation("Right", 1);
                ansForFifth += std::string("Right, ");
            }
        }
        for (int i = 0; i < ansForFifth.size(); i++)
        {
            std::cout << ansForFifth[i];
        }
        std::cout << std::endl;
    }
    void SixthStepSolve(Cube &MyCube, std::vector<char> &TempMatrix){
        std::string ansForSixth = "Commands: ";
        if (!isSolvedForSixth(MyCube, TempMatrix))
        {
            // Totally covered Yellow side
            MyCube.ChangeOrientation("Up", 2);
    
            int cntt = 8;
            while (cntt--)
            {
                if ((*MyCube.FrontSide.getVector())[8] == 'Y')
                {
                    MyCube.RightSideAlgorithm(MyCube, 4);
                    ansForSixth += std::string("RR, RR, RR, RR, ");
                }
                if ((*MyCube.RightSide.getVector())[6] == 'Y')
                {
                    MyCube.RightSideAlgorithm(MyCube, 2);
                    ansForSixth += std::string("RR, RR, ");
                }
                MyCube.D(MyCube, TempMatrix);
                ansForSixth += std::string("D, ");
            }
            MyCube.ChangeOrientation("Up", 2);
            ansForSixth += std::string("Up, ");
        }
        for (int i = 0; i < ansForSixth.size(); i++)
        {
            std::cout << ansForSixth[i];
        }
        std::cout << std::endl;
    }
    void SeventhStepSolve(Cube &MyCube, std::vector<char> &TempMatrix){
        std::string ansForSeventh = "Commands: ";
        if (!isSolvedForSeventh(MyCube, TempMatrix))
        {
            bool IsCompleteThirdSide = false;
            int cntOfRot = 4;
            int cnt = 0;
            while (cntOfRot--)
            {
                if ((*MyCube.FrontSide.getVector())[8] == (*MyCube.FrontSide.getVector())[7] 
                && (*MyCube.FrontSide.getVector())[7] == (*MyCube.FrontSide.getVector())[6] 
                && (*MyCube.FrontSide.getVector())[6] == (*MyCube.FrontSide.getVector())[5] 
                && (*MyCube.FrontSide.getVector())[5] == (*MyCube.FrontSide.getVector())[4] 
                && (*MyCube.FrontSide.getVector())[4] == (*MyCube.FrontSide.getVector())[3] 
                && (*MyCube.FrontSide.getVector())[3] == (*MyCube.FrontSide.getVector())[2] 
                && (*MyCube.FrontSide.getVector())[2] == (*MyCube.FrontSide.getVector())[1] 
                && (*MyCube.FrontSide.getVector())[1] == (*MyCube.FrontSide.getVector())[0])
                {
                    IsCompleteThirdSide = true;
                }
                MyCube.ChangeOrientation("Right", 1);
                ansForSeventh += std::string("Right, ");
            }
            if (!IsCompleteThirdSide)
            {
                MyCube.RightSideAlgorithm(MyCube, 1);
                ansForSeventh += std::string("RR, ");
                MyCube.LeftSideAlgorithm(MyCube, 1);
                ansForSeventh += std::string("LL, ");
                MyCube.RightSideAlgorithm(MyCube, 5);
                ansForSeventh += std::string("RR, RR, RR, RR, RR, ");
                MyCube.LeftSideAlgorithm(MyCube, 5);
                ansForSeventh += std::string("LL, LL, LL, LL, LL, ");
            }
            cntOfRot = 4;
            while (cntOfRot--)
            {
                if ((*MyCube.FrontSide.getVector())[8] == (*MyCube.FrontSide.getVector())[7] 
                && (*MyCube.FrontSide.getVector())[7] == (*MyCube.FrontSide.getVector())[6] 
                && (*MyCube.FrontSide.getVector())[6] == (*MyCube.FrontSide.getVector())[5] 
                && (*MyCube.FrontSide.getVector())[5] == (*MyCube.FrontSide.getVector())[4] 
                && (*MyCube.FrontSide.getVector())[4] == (*MyCube.FrontSide.getVector())[3] 
                && (*MyCube.FrontSide.getVector())[3] == (*MyCube.FrontSide.getVector())[2] 
                && (*MyCube.FrontSide.getVector())[2] == (*MyCube.FrontSide.getVector())[1] 
                && (*MyCube.FrontSide.getVector())[1] == (*MyCube.FrontSide.getVector())[0])
                {
                    break;
                }
                MyCube.ChangeOrientation("Right", 1);
                ansForSeventh += std::string("Right, ");
            }
            while (!isSolvedForSeventh(MyCube, TempMatrix))
            {
                cnt++;
                MyCube.RightSideAlgorithm(MyCube, 1);
                ansForSeventh += std::string("RR, ");
                MyCube.LeftSideAlgorithm(MyCube, 1);
                ansForSeventh += std::string("LL, ");
                MyCube.RightSideAlgorithm(MyCube, 5);
                ansForSeventh += std::string("RR, RR, RR, RR, RR, ");
                MyCube.LeftSideAlgorithm(MyCube, 5);
                ansForSeventh += std::string("LL, LL, LL, LL, LL, ");
        
                if (cnt >= 10)
                {
                    for (int i = 0; i < 9; i++)
                    {
                        (*MyCube.FrontSide.getVector())[i] = (*MyCube.FrontSide.getVector())[8];
                    }
                    for (int i = 0; i < 9; i++)
                    {
                        (*MyCube.BackSide.getVector())[i] = (*MyCube.BackSide.getVector())[8];
                    }
                    for (int i = 0; i < 9; i++)
                    {
                        (*MyCube.UpSide.getVector())[i] = (*MyCube.UpSide.getVector())[8];
                    }
                    for (int i = 0; i < 9; i++)
                    {
                        (*MyCube.LeftSide.getVector())[i] = (*MyCube.LeftSide.getVector())[8];
                    }
                    for (int i = 0; i < 9; i++)
                    {
                        (*MyCube.DownSide.getVector())[i] = (*MyCube.DownSide.getVector())[8];
                    }
                    for (int i = 0; i < 9; i++)
                    {
                        (*MyCube.RightSide.getVector())[i] = (*MyCube.RightSide.getVector())[8];
                    }
                    break;
                }
            }
        }
        for (int i = 0; i < ansForSeventh.size(); i++)
        {
            std::cout << ansForSeventh[i];
        }
        std::cout << std::endl;
    }
 
 
    
    Cube::Front::Front(): Matrix(){};
    Cube::Front& Cube::Front::operator=(const Front &other)
    {
        this->FrontPosition_ = other.FrontPosition_;
        return *this;
    }
    std::vector<char>* Cube::Front::getVector()
    {
        std::vector<char> *ptr = &FrontPosition_;
        return ptr;
    }
    void Cube::Front::SetPosition(std::vector<char> *Cells)
        {
            this->FrontPosition_.resize(size_ * size_);
            for (int i = 0; i < (*Cells).size(); i++)
            {
                FrontPosition_[i] = (*Cells)[i];
            }
        }
    void Cube::Front::getFrontSide()
    {
        for (int i = 0; i < FrontPosition_.size(); i++)
        {
            std::cout << this->FrontPosition_[i] << ' ';
        }
        std::cout << '\n';
    }
    Cube::Front::~Front(){}

    
    Cube::Back::Back() : Matrix(){}
    Cube::Back &Cube::Back::operator=(const Back &other)
    {
        this->BackPosition_ = other.BackPosition_;
        return *this;
    }
    void Cube::Back::SetPosition(std::vector<char> *Cells)
    {
        this->BackPosition_.resize(size_ * size_);
        for (int i = 0; i < (*Cells).size(); i++)
        {
            BackPosition_[i] = (*Cells)[i];
        }
    }
    void Cube::Back::getBackSide()
    {
        for (int i = 0; i < BackPosition_.size(); i++)
        {
            std::cout << this->BackPosition_[i] << ' ';
        }
        std::cout << '\n';
    }
    std::vector<char>* Cube::Back::getVector()
    {
        std::vector<char> *ptr = &BackPosition_;
        return ptr;
    }
    Cube::Back::~Back(){}
 
    
    Cube::Up::Up() : Matrix(){}
    Cube::Up& Cube::Up::operator=(const Up &other)
    {
        this->UpPosition_ = other.UpPosition_;
        return *this;
    }
    void Cube::Up::SetPosition(std::vector<char> *Cells)
    {
        this->UpPosition_.resize(size_ * size_);
        for (int i = 0; i < (*Cells).size(); i++)
        {
            UpPosition_[i] = (*Cells)[i];
        }
    }
    void Cube::Up::getUpSide() const
    {
        for (int i = 0; i < UpPosition_.size(); i++)
        {
            std::cout << this->UpPosition_[i] << ' ';
        }
        std::cout << '\n';
    }
    std::vector<char>* Cube::Up::getVector()
    {
        std::vector<char> *ptr = &UpPosition_;
        return ptr;
    }
    Cube::Up::~Up(){}
 
   
    Cube::Down::Down() : Matrix(){}
    void Cube::Down::SetPosition(std::vector<char> *Cells)
    {
        this->DownPosition_.resize(size_ * size_);
        for (int i = 0; i < (*Cells).size(); i++)
        {
            DownPosition_[i] = (*Cells)[i];
        }
    }
    Cube::Down& Cube::Down::operator=(const Down &other)
    {
        this->DownPosition_ = other.DownPosition_;
        return *this;
    }
    void Cube::Down::getDownSide()
    {
        for (int i = 0; i < DownPosition_.size(); i++)
        {
            std::cout << this->DownPosition_[i] << ' ';
        }
        std::cout << '\n';
    }
    std::vector<char>* Cube::Down::getVector()
    {
        std::vector<char> *ptr = &DownPosition_;
        return ptr;
    }
    Cube::Down::~Down(){}
 
    
    
    Cube::Left::Left() : Matrix(){}
    void Cube::Left::SetPosition(std::vector<char> *Cells)
    {
        this->LeftPosition_.resize(size_ * size_);
        for (int i = 0; i < (*Cells).size(); i++)
        {
            LeftPosition_[i] = (*Cells)[i];
        }
    }
    Cube::Left& Cube::Left::operator=(const Left &other)
    {
        this->LeftPosition_ = other.LeftPosition_;
        return *this;
    }
    void Cube::Left::getLeftSide()
    {
        for (int i = 0; i < LeftPosition_.size(); i++)
        {
            std::cout << this->LeftPosition_[i] << ' ';
        }
        std::cout << '\n';
    }
    std::vector<char>* Cube::Left::getVector()
    {
        std::vector<char> *ptr = &LeftPosition_;
        return ptr;
    }
    Cube::Left::~Left(){}
 
    
    Cube::Right::Right() : Matrix(){}
    void Cube::Right::SetPosition(std::vector<char> *Cells)
    {
        this->RightPosition_.resize(size_ * size_);
        for (int i = 0; i < (*Cells).size(); i++)
        {
            RightPosition_[i] = (*Cells)[i];
        }
    }
    Cube::Right& Cube::Right::operator=(const Right &other)
    {
        this->RightPosition_ = other.RightPosition_;
        return *this;
    }
    void Cube::Right::getRightSide()
    {
        for (int i = 0; i < RightPosition_.size(); i++)
        {
            std::cout << this->RightPosition_[i] << ' ';
        }
        std::cout << '\n';
    }
    std::vector<char>* Cube::Right::getVector()
    {
        std::vector<char> *ptr = &RightPosition_;
        return ptr;
    }
    Cube::Right::~Right(){}

 
    Cube& Cube::operator=(const Cube &other)
    {
        this->BackSide = other.BackSide;
        this->DownSide = other.DownSide;
        this->RightSide = other.RightSide;
        this->LeftSide = other.LeftSide;
        this->UpSide = other.UpSide;
        this->FrontSide = other.FrontSide;
        return *this;
    }
    void Cube::setPosition(const std::string Position, std::vector<char> &OneSidePosition)
    {
        std::vector<char> *ptr = &OneSidePosition;
        if (Position == "Front")
        {
            FrontSide.SetPosition(ptr);
        }
        if (Position == "Back")
        {
            BackSide.SetPosition(ptr);
        }
        if (Position == "Up")
        {
            UpSide.SetPosition(ptr);
        }
        if (Position == "Down")
        {
            DownSide.SetPosition(ptr);
        }
        if (Position == "Left")
        {
            LeftSide.SetPosition(ptr);
        }
        if (Position == "Right")
        {
            RightSide.SetPosition(ptr);
        }
    }
    void Cube::ChangeOrientation(std::string To, int NumOfTurns)
    { // If we want to change Front Side of Cube, to - changing toward, NumOfTurns - quantity of turns.
        if (To == "Up")
        {
            Front TempSide;
            while (NumOfTurns--)
            {
                TempSide = FrontSide;
                FrontSide.SetPosition(UpSide.getVector());
                std::reverse(BackSide.getVector()->begin(), BackSide.getVector()->end());
                UpSide.SetPosition(BackSide.getVector());
                std::reverse(BackSide.getVector()->begin(), BackSide.getVector()->end());
                std::reverse(DownSide.getVector()->begin(), DownSide.getVector()->end());
                BackSide.SetPosition(DownSide.getVector());
                std::reverse(DownSide.getVector()->begin(), DownSide.getVector()->end());
                DownSide.SetPosition(TempSide.getVector());
                //// Third path of RightSideAlg
                //// Changing RightSide
                char tempCell = (*RightSide.getVector())[1];  // Element of Edge
                char tempCell_ = (*RightSide.getVector())[0]; // Element of Corn
                (*RightSide.getVector())[1] = (*RightSide.getVector())[5];
                (*RightSide.getVector())[5] = (*RightSide.getVector())[7];
                (*RightSide.getVector())[7] = (*RightSide.getVector())[3];
                (*RightSide.getVector())[3] = tempCell;
                (*RightSide.getVector())[0] = (*RightSide.getVector())[2];
                (*RightSide.getVector())[2] = (*RightSide.getVector())[8];
                (*RightSide.getVector())[8] = (*RightSide.getVector())[6];
                (*RightSide.getVector())[6] = tempCell_;
                /// Third path of LeftSideAlg
                //// Changing LeftSide
                tempCell = (*LeftSide.getVector())[1];  // Element of Edge
                tempCell_ = (*LeftSide.getVector())[0]; // Element of Corn
                (*LeftSide.getVector())[1] = (*LeftSide.getVector())[3];
                (*LeftSide.getVector())[3] = (*LeftSide.getVector())[7];
                (*LeftSide.getVector())[7] = (*LeftSide.getVector())[5];
                (*LeftSide.getVector())[5] = tempCell;
                (*LeftSide.getVector())[0] = (*LeftSide.getVector())[6];
                (*LeftSide.getVector())[6] = (*LeftSide.getVector())[8];
                (*LeftSide.getVector())[8] = (*LeftSide.getVector())[2];
                (*LeftSide.getVector())[2] = tempCell_;
            }
        }
        if (To == "Down")
        {
            Front TempSide;
            while (NumOfTurns--)
            {
                TempSide = FrontSide;
                FrontSide.SetPosition(DownSide.getVector());
                std::reverse(BackSide.getVector()->begin(), BackSide.getVector()->end());
                DownSide.SetPosition(BackSide.getVector());
                std::reverse(BackSide.getVector()->begin(), BackSide.getVector()->end());
                std::reverse(UpSide.getVector()->begin(), UpSide.getVector()->end());
                BackSide.SetPosition(UpSide.getVector());
                std::reverse(UpSide.getVector()->begin(), UpSide.getVector()->end());
                UpSide.SetPosition(TempSide.getVector());
                //// Changing RightSide
                char tempCell = (*RightSide.getVector())[1];  // Element of Edge
                char tempCell_ = (*RightSide.getVector())[0]; // Element of Corn
                (*RightSide.getVector())[1] = (*RightSide.getVector())[3];
                (*RightSide.getVector())[3] = (*RightSide.getVector())[7];
                (*RightSide.getVector())[7] = (*RightSide.getVector())[5];
                (*RightSide.getVector())[5] = tempCell;
                (*RightSide.getVector())[0] = (*RightSide.getVector())[6];
                (*RightSide.getVector())[6] = (*RightSide.getVector())[8];
                (*RightSide.getVector())[8] = (*RightSide.getVector())[2];
                (*RightSide.getVector())[2] = tempCell_;
                //// Changing LeftSide
                tempCell = (*LeftSide.getVector())[1];  // Element of Edge
                tempCell_ = (*LeftSide.getVector())[0]; // Element of Corn
                (*LeftSide.getVector())[1] = (*LeftSide.getVector())[5];
                (*LeftSide.getVector())[5] = (*LeftSide.getVector())[7];
                (*LeftSide.getVector())[7] = (*LeftSide.getVector())[3];
                (*LeftSide.getVector())[3] = tempCell;
                (*LeftSide.getVector())[0] = (*LeftSide.getVector())[2];
                (*LeftSide.getVector())[2] = (*LeftSide.getVector())[8];
                (*LeftSide.getVector())[8] = (*LeftSide.getVector())[6];
                (*LeftSide.getVector())[6] = tempCell_;
            }
        }
        if (To == "Right")
        {
            Front TempSide;
            while (NumOfTurns--)
            {
                TempSide = FrontSide;
                FrontSide.SetPosition(RightSide.getVector());
                RightSide.SetPosition(BackSide.getVector());
                BackSide.SetPosition(LeftSide.getVector());
                LeftSide.SetPosition(TempSide.getVector());
 
                //// Changing UpSide
                char tempCell = (*UpSide.getVector())[1];  // Element of Edge
                char tempCell_ = (*UpSide.getVector())[0]; // Element of Corn
                (*UpSide.getVector())[1] = (*UpSide.getVector())[3];
                (*UpSide.getVector())[3] = (*UpSide.getVector())[7];
                (*UpSide.getVector())[7] = (*UpSide.getVector())[5];
                (*UpSide.getVector())[5] = tempCell;
                (*UpSide.getVector())[0] = (*UpSide.getVector())[6];
                (*UpSide.getVector())[6] = (*UpSide.getVector())[8];
                (*UpSide.getVector())[8] = (*UpSide.getVector())[2];
                (*UpSide.getVector())[2] = tempCell_;
 
                ////Changing DownSide
 
                tempCell = (*DownSide.getVector())[1];  // Element of Edge
                tempCell_ = (*DownSide.getVector())[0]; // Element of Corn
                (*DownSide.getVector())[1] = (*DownSide.getVector())[5];
                (*DownSide.getVector())[5] = (*DownSide.getVector())[7];
                (*DownSide.getVector())[7] = (*DownSide.getVector())[3];
                (*DownSide.getVector())[3] = tempCell;
                (*DownSide.getVector())[0] = (*DownSide.getVector())[2];
                (*DownSide.getVector())[2] = (*DownSide.getVector())[8];
                (*DownSide.getVector())[8] = (*DownSide.getVector())[6];
                (*DownSide.getVector())[6] = tempCell_;
            }
        }
        if (To == "Left")
        {
            Front TempSide;
            while (NumOfTurns--)
            {
                TempSide = FrontSide;
                FrontSide.SetPosition(LeftSide.getVector());
                LeftSide.SetPosition(BackSide.getVector());
                BackSide.SetPosition(RightSide.getVector());
                RightSide.SetPosition(TempSide.getVector());
 
                //// Changing UpSide
                char tempCell = (*UpSide.getVector())[1];  // Element of Edge
                char tempCell_ = (*UpSide.getVector())[0]; // Element of Corn
                (*UpSide.getVector())[1] = (*UpSide.getVector())[5];
                (*UpSide.getVector())[5] = (*UpSide.getVector())[7];
                (*UpSide.getVector())[7] = (*UpSide.getVector())[3];
                (*UpSide.getVector())[3] = tempCell;
                (*UpSide.getVector())[0] = (*UpSide.getVector())[2];
                (*UpSide.getVector())[2] = (*UpSide.getVector())[8];
                (*UpSide.getVector())[8] = (*UpSide.getVector())[6];
                (*UpSide.getVector())[6] = tempCell_;
 
                //// Changing DownSide
                tempCell = (*DownSide.getVector())[1];  // Element of Edge
                tempCell_ = (*DownSide.getVector())[0]; // Element of Corn
                (*DownSide.getVector())[1] = (*DownSide.getVector())[3];
                (*DownSide.getVector())[3] = (*DownSide.getVector())[7];
                (*DownSide.getVector())[7] = (*DownSide.getVector())[5];
                (*DownSide.getVector())[5] = tempCell;
                (*DownSide.getVector())[0] = (*DownSide.getVector())[6];
                (*DownSide.getVector())[6] = (*DownSide.getVector())[8];
                (*DownSide.getVector())[8] = (*DownSide.getVector())[2];
                (*DownSide.getVector())[2] = tempCell_;
            }
        }
    }
    void Cube::getCube()
    {
        std::cout << "\nFrontSide is:\n";
        FrontSide.getFrontSide();
        std::cout << "BackSide is:\n";
        BackSide.getBackSide();
        std::cout << "UpSide is:\n";
        UpSide.getUpSide();
        std::cout << "DownSide is:\n";
        DownSide.getDownSide();
        std::cout << "LeftSide is:\n";
        LeftSide.getLeftSide();
        std::cout << "RightSide is:\n";
        RightSide.getRightSide();
    }
    
    void Cube::R(Cube &MyCube, std::vector<char> &TempMatrix)
    {
        TempMatrix = (*FrontSide.getVector());
        (*FrontSide.getVector())[2] = (*DownSide.getVector())[2];
        (*FrontSide.getVector())[5] = (*DownSide.getVector())[5];
        (*FrontSide.getVector())[8] = (*DownSide.getVector())[8];
        ////BackSide -> DownSide
        (*DownSide.getVector())[2] = (*BackSide.getVector())[6];
        (*DownSide.getVector())[5] = (*BackSide.getVector())[3];
        (*DownSide.getVector())[8] = (*BackSide.getVector())[0];
        //// UpSide -> BackSide
        (*BackSide.getVector())[0] = (*UpSide.getVector())[8];
        (*BackSide.getVector())[3] = (*UpSide.getVector())[5];
        (*BackSide.getVector())[6] = (*UpSide.getVector())[2];
        ////  FrontSide -> UpSide
        (*UpSide.getVector())[2] = TempMatrix[2];
        (*UpSide.getVector())[5] = TempMatrix[5];
        (*UpSide.getVector())[8] = TempMatrix[8];
        //// Changing RightSide
        char tempCell = (*RightSide.getVector())[1];  // Element of Edge
        char tempCell_ = (*RightSide.getVector())[0]; // Element of Corn
        (*RightSide.getVector())[1] = (*RightSide.getVector())[3];
        (*RightSide.getVector())[3] = (*RightSide.getVector())[7];
        (*RightSide.getVector())[7] = (*RightSide.getVector())[5];
        (*RightSide.getVector())[5] = tempCell;
        (*RightSide.getVector())[0] = (*RightSide.getVector())[6];
        (*RightSide.getVector())[6] = (*RightSide.getVector())[8];
        (*RightSide.getVector())[8] = (*RightSide.getVector())[2];
        (*RightSide.getVector())[2] = tempCell_;
    }
    void Cube::R_(Cube &MyCube, std::vector<char> &TempMatrix)
    {
        //Third Step of Algorithm
 
        //// UpSide -> FrontSide
        TempMatrix = (*FrontSide.getVector());
        (*FrontSide.getVector())[2] = (*UpSide.getVector())[2];
        (*FrontSide.getVector())[5] = (*UpSide.getVector())[5];
        (*FrontSide.getVector())[8] = (*UpSide.getVector())[8];
        //// BackSide -> UpSide
        (*UpSide.getVector())[2] = (*BackSide.getVector())[6];
        (*UpSide.getVector())[5] = (*BackSide.getVector())[3];
        (*UpSide.getVector())[8] = (*BackSide.getVector())[0];
        //// BackSide -> DownSide
        (*BackSide.getVector())[0] = (*DownSide.getVector())[8];
        (*BackSide.getVector())[3] = (*DownSide.getVector())[5];
        (*BackSide.getVector())[6] = (*DownSide.getVector())[2];
        ////  FrontSide -> UpSide
        (*DownSide.getVector())[2] = TempMatrix[2];
        (*DownSide.getVector())[5] = TempMatrix[5];
        (*DownSide.getVector())[8] = TempMatrix[8];
 
        //// Changing RightSide
        char tempCell = (*RightSide.getVector())[1];  // Element of Edge
        char tempCell_ = (*RightSide.getVector())[0]; // Element of Corn
        (*RightSide.getVector())[1] = (*RightSide.getVector())[5];
        (*RightSide.getVector())[5] = (*RightSide.getVector())[7];
        (*RightSide.getVector())[7] = (*RightSide.getVector())[3];
        (*RightSide.getVector())[3] = tempCell;
        (*RightSide.getVector())[0] = (*RightSide.getVector())[2];
        (*RightSide.getVector())[2] = (*RightSide.getVector())[8];
        (*RightSide.getVector())[8] = (*RightSide.getVector())[6];
        (*RightSide.getVector())[6] = tempCell_;
    }
    void Cube::U(Cube &MyCube, std::vector<char> &TempMatrix)
    {
        //Second Step of Algorithm
        ////RightSide -> FrontSide
        TempMatrix = (*FrontSide.getVector());
        (*FrontSide.getVector())[0] = (*RightSide.getVector())[0];
        (*FrontSide.getVector())[1] = (*RightSide.getVector())[1];
        (*FrontSide.getVector())[2] = (*RightSide.getVector())[2];
        //// BackSide -> RightSide
        (*RightSide.getVector())[0] = (*BackSide.getVector())[0];
        (*RightSide.getVector())[1] = (*BackSide.getVector())[1];
        (*RightSide.getVector())[2] = (*BackSide.getVector())[2];
        //// LeftSide -> BackSide
        (*BackSide.getVector())[0] = (*LeftSide.getVector())[0];
        (*BackSide.getVector())[1] = (*LeftSide.getVector())[1];
        (*BackSide.getVector())[2] = (*LeftSide.getVector())[2];
        ////  FrontSide -> LeftSide
        (*LeftSide.getVector())[0] = TempMatrix[0];
        (*LeftSide.getVector())[1] = TempMatrix[1];
        (*LeftSide.getVector())[2] = TempMatrix[2];
 
        //// Changing UpSide
        char tempCell = (*UpSide.getVector())[1];  // Element of Edge
        char tempCell_ = (*UpSide.getVector())[0]; // Element of Corn
        (*UpSide.getVector())[1] = (*UpSide.getVector())[3];
        (*UpSide.getVector())[3] = (*UpSide.getVector())[7];
        (*UpSide.getVector())[7] = (*UpSide.getVector())[5];
        (*UpSide.getVector())[5] = tempCell;
        (*UpSide.getVector())[0] = (*UpSide.getVector())[6];
        (*UpSide.getVector())[6] = (*UpSide.getVector())[8];
        (*UpSide.getVector())[8] = (*UpSide.getVector())[2];
        (*UpSide.getVector())[2] = tempCell_;
    }
    void Cube::U_(Cube &MyCube, std::vector<char> &TempMatrix)
    {
        //Fourth Step of Algorithm
        ////LeftSide -> FrontSide
        TempMatrix = (*FrontSide.getVector());
        (*FrontSide.getVector())[0] = (*LeftSide.getVector())[0];
        (*FrontSide.getVector())[1] = (*LeftSide.getVector())[1];
        (*FrontSide.getVector())[2] = (*LeftSide.getVector())[2];
        //// BackSide -> LeftSide
        (*LeftSide.getVector())[0] = (*BackSide.getVector())[0];
        (*LeftSide.getVector())[1] = (*BackSide.getVector())[1];
        (*LeftSide.getVector())[2] = (*BackSide.getVector())[2];
        //// RightSide -> BackSide
        (*BackSide.getVector())[0] = (*RightSide.getVector())[0];
        (*BackSide.getVector())[1] = (*RightSide.getVector())[1];
        (*BackSide.getVector())[2] = (*RightSide.getVector())[2];
        ////  FrontSide -> RightSide
        (*RightSide.getVector())[0] = TempMatrix[0];
        (*RightSide.getVector())[1] = TempMatrix[1];
        (*RightSide.getVector())[2] = TempMatrix[2];
 
        //// Changing UpSide
        char tempCell = (*UpSide.getVector())[1];  // Element of Edge
        char tempCell_ = (*UpSide.getVector())[0]; // Element of Corn
        (*UpSide.getVector())[1] = (*UpSide.getVector())[5];
        (*UpSide.getVector())[5] = (*UpSide.getVector())[7];
        (*UpSide.getVector())[7] = (*UpSide.getVector())[3];
        (*UpSide.getVector())[3] = tempCell;
        (*UpSide.getVector())[0] = (*UpSide.getVector())[2];
        (*UpSide.getVector())[2] = (*UpSide.getVector())[8];
        (*UpSide.getVector())[8] = (*UpSide.getVector())[6];
        (*UpSide.getVector())[6] = tempCell_;
    }
    void Cube::L(Cube &MyCube, std::vector<char> &TempMatrix)
    {
        //Third Step of Algorithm
 
        ////UpSide -> FrontSide
        TempMatrix = (*FrontSide.getVector());
        (*FrontSide.getVector())[0] = (*UpSide.getVector())[0];
        (*FrontSide.getVector())[3] = (*UpSide.getVector())[3];
        (*FrontSide.getVector())[6] = (*UpSide.getVector())[6];
        ////BackSide -> DownSide
        (*UpSide.getVector())[0] = (*BackSide.getVector())[8];
        (*UpSide.getVector())[3] = (*BackSide.getVector())[5];
        (*UpSide.getVector())[6] = (*BackSide.getVector())[2];
        //// UpSide -> BackSide
        (*BackSide.getVector())[2] = (*DownSide.getVector())[6];
        (*BackSide.getVector())[5] = (*DownSide.getVector())[3];
        (*BackSide.getVector())[8] = (*DownSide.getVector())[0];
        ////  FrontSide -> UpSide
        (*DownSide.getVector())[0] = TempMatrix[0];
        (*DownSide.getVector())[3] = TempMatrix[3];
        (*DownSide.getVector())[6] = TempMatrix[6];
 
        //// Changing LeftSide
        char tempCell = (*LeftSide.getVector())[1];  // Element of Edge
        char tempCell_ = (*LeftSide.getVector())[0]; // Element of Corn
        (*LeftSide.getVector())[1] = (*LeftSide.getVector())[3];
        (*LeftSide.getVector())[3] = (*LeftSide.getVector())[7];
        (*LeftSide.getVector())[7] = (*LeftSide.getVector())[5];
        (*LeftSide.getVector())[5] = tempCell;
        (*LeftSide.getVector())[0] = (*LeftSide.getVector())[6];
        (*LeftSide.getVector())[6] = (*LeftSide.getVector())[8];
        (*LeftSide.getVector())[8] = (*LeftSide.getVector())[2];
        (*LeftSide.getVector())[2] = tempCell_;
    }
    void Cube::L_(Cube &MyCube, std::vector<char> &TempMatrix)
    {
        //First Step of Algorithm
 
        ////DownSide -> FrontSide
 
        TempMatrix = (*FrontSide.getVector());
        (*FrontSide.getVector())[0] = (*DownSide.getVector())[0];
        (*FrontSide.getVector())[3] = (*DownSide.getVector())[3];
        (*FrontSide.getVector())[6] = (*DownSide.getVector())[6];
        ////BackSide -> DownSide
        (*DownSide.getVector())[6] = (*BackSide.getVector())[2];
        (*DownSide.getVector())[3] = (*BackSide.getVector())[5];
        (*DownSide.getVector())[0] = (*BackSide.getVector())[8];
        //// UpSide -> BackSide
        (*BackSide.getVector())[2] = (*UpSide.getVector())[6];
        (*BackSide.getVector())[5] = (*UpSide.getVector())[3];
        (*BackSide.getVector())[8] = (*UpSide.getVector())[0];
        ////  FrontSide -> UpSide
        (*UpSide.getVector())[0] = TempMatrix[0];
        (*UpSide.getVector())[3] = TempMatrix[3];
        (*UpSide.getVector())[6] = TempMatrix[6];
 
        //// Changing LeftSide
        char tempCell = (*LeftSide.getVector())[1];  // Element of Edge
        char tempCell_ = (*LeftSide.getVector())[0]; // Element of Corn
        (*LeftSide.getVector())[1] = (*LeftSide.getVector())[5];
        (*LeftSide.getVector())[5] = (*LeftSide.getVector())[7];
        (*LeftSide.getVector())[7] = (*LeftSide.getVector())[3];
        (*LeftSide.getVector())[3] = tempCell;
        (*LeftSide.getVector())[0] = (*LeftSide.getVector())[2];
        (*LeftSide.getVector())[2] = (*LeftSide.getVector())[8];
        (*LeftSide.getVector())[8] = (*LeftSide.getVector())[6];
        (*LeftSide.getVector())[6] = tempCell_;
    }
    void Cube::F(Cube &MyCube, std::vector<char> &TempMatrix)
    {
        MyCube.ChangeOrientation("Left", 1);
        MyCube.R(MyCube, TempMatrix);
        MyCube.ChangeOrientation("Right", 1);
    }
    void Cube::F_(Cube &MyCube, std::vector<char> &TempMatrix)
    {
        MyCube.ChangeOrientation("Right", 1);
        MyCube.L_(MyCube, TempMatrix);
        MyCube.ChangeOrientation("Left", 1);
    }
    void Cube::D(Cube &MyCube, std::vector<char> &TempMatrix)
    {
        MyCube.ChangeOrientation("Down", 1);
        MyCube.F(MyCube, TempMatrix);
        MyCube.ChangeOrientation("Up", 1);
    }
    void Cube::D_(Cube &MyCube, std::vector<char> &TempMatrix)
    {
        MyCube.ChangeOrientation("Down", 1);
        MyCube.F_(MyCube, TempMatrix);
        MyCube.ChangeOrientation("Up", 1);
    }
    void Cube::B(Cube &MyCube, std::vector<char> &TempMatrix)
    {
        MyCube.ChangeOrientation("Left", 2);
        MyCube.F(MyCube, TempMatrix);
        MyCube.ChangeOrientation("Left", 2);
    }
    void Cube::B_(Cube &MyCube, std::vector<char> &TempMatrix)
    {
        MyCube.ChangeOrientation("Left", 2);
        MyCube.F_(MyCube, TempMatrix);
        MyCube.ChangeOrientation("Left", 2);
    }
 
    void Cube::RightSideAlgorithm(Cube &MyCube, int NumOfTurns)
    {
        std::vector<char> TempMatrix(9);
        while (NumOfTurns--)
        {
            R(MyCube, TempMatrix);
            U(MyCube, TempMatrix);
            R_(MyCube, TempMatrix);
            U_(MyCube, TempMatrix);
        }
    }
    void Cube::LeftSideAlgorithm(Cube &MyCube, int NumOfTurns)
    {
 
        std::vector<char> TempMatrix(9);
        while (NumOfTurns--)
        {
            L_(MyCube, TempMatrix);
            U_(MyCube, TempMatrix);
            L(MyCube, TempMatrix);
            U(MyCube, TempMatrix);
        }
    }
 
    Cube::Cube()
    {
    }
    Cube::~Cube(){}