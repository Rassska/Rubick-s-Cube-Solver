#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <string>
#include "Matrix.h"

class Cube
{
public:
    friend void WriteToFile(Cube &MyCube, bool makeRandomPositions);
    friend void GetFromFile(Cube &MyCube, int numberOfCube);
    friend void FirstStepSolve(Cube &MyCube, std::vector<char> &TempMatrix);
    friend void SecondStepSolve(Cube &MyCube, std::vector<char> &TempMatrix);
    friend void ThirdStepSolve(Cube &MyCube, std::vector<char> &TempMatrix);
    friend void FourthStepSolve(Cube &MyCube, std::vector<char> &TempMatrix);
    friend void FifthStepSolve(Cube &MyCube, std::vector<char> &TempMatrix);
    friend void SixthStepSolve(Cube &MyCube, std::vector<char> &TempMatrix);
    friend void SeventhStepSolve(Cube &MyCube, std::vector<char> &TempMatrix);

    friend bool isSolvedForFirst(Cube &MyCube, std::vector<char> &TempMatrix);
    friend bool isSolvedForSecond(Cube &MyCube, std::vector<char> &TempMatrix);
    friend bool isSolvedForThird(Cube &MyCube, std::vector<char> &TempMatrix);
    friend bool isSolvedForFourth(Cube &MyCube, std::vector<char> &TempMatrix);
    friend bool isSolvedForFifth(Cube &MyCube, std::vector<char> &TempMatrix);
    friend bool isSolvedForSixth(Cube &MyCube, std::vector<char> &TempMatrix);
    friend bool isSolvedForSeventh(Cube &MyCube, std::vector<char> &TempMatrix);
 
    class Front;
    class Back;
    class Up;
    class Down;
    class Left;
    class Right;
 
    class Front : public Matrix {

        friend Up;
        friend Down;
        friend Left;
        friend Right;
        friend Back;
 
    public:
        Front();
 
        void SetPosition(std::vector<char> *Cells);
        Front &operator=(const Front &other);
 
        void getFrontSide();
        std::vector<char> *getVector();
 
        ~Front();
 
    protected:
        std::vector<char> FrontPosition_;
 
    }; // white -> Yellow
    class Back : public Matrix
 
    {
    public:
        Back();
        void SetPosition(std::vector<char> *Cells);
        Back &operator=(const Back &other);
        void getBackSide();
        std::vector<char> *getVector();
 
        ~Back();
 
    private:
        std::vector<char> BackPosition_;
    }; 
    class Up : public Matrix
    {
    public:
        Up();
        void SetPosition(std::vector<char> *Cells);

        Up &operator=(const Up &other);
        void getUpSide() const;
        std::vector<char> *getVector();
        ~Up();
 
    private:
        std::vector<char> UpPosition_;
    }; // Blue -> Green
    class Down : public Matrix
    {
    public:
        Down();
        void SetPosition(std::vector<char> *Cells);
        Down &operator=(const Down &other);
        void getDownSide();
        std::vector<char> *getVector();
        ~Down();
 
    private:
        std::vector<char> DownPosition_;
    }; // Orange -> Red
    class Left : public Matrix
    {
    public:
        Left();
 
        void SetPosition(std::vector<char> *Cells);
        Left &operator=(const Left &other);
        void getLeftSide();
        std::vector<char> *getVector();
 
        ~Left();
    private:
        std::vector<char> LeftPosition_;
    }; // Green -> Blue
    class Right : public Matrix
    {
    public:
        Right();
 
        void SetPosition(std::vector<char> *Cells);
        Right &operator=(const Right &other);
        void getRightSide();
        std::vector<char> *getVector();
 
        ~Right();
 
    private:
        std::vector<char> RightPosition_;
    }; // Red -> Orange
 
    Cube &operator=(const Cube &other);
    void setPosition(const std::string Position, std::vector<char> &OneSidePosition);
    void ChangeOrientation(std::string To, int NumOfTurns);
    void getCube();

    void R(Cube &MyCube, std::vector<char> &TempMatrix);
    void R_(Cube &MyCube, std::vector<char> &TempMatrix);
    void U(Cube &MyCube, std::vector<char> &TempMatrix);
    void U_(Cube &MyCube, std::vector<char> &TempMatrix);
    void L(Cube &MyCube, std::vector<char> &TempMatrix);
    void L_(Cube &MyCube, std::vector<char> &TempMatrix);
    void F(Cube &MyCube, std::vector<char> &TempMatrix);
    void F_(Cube &MyCube, std::vector<char> &TempMatrix);
    void D(Cube &MyCube, std::vector<char> &TempMatrix);
    void D_(Cube &MyCube, std::vector<char> &TempMatrix);
    void B(Cube &MyCube, std::vector<char> &TempMatrix);
    void B_(Cube &MyCube, std::vector<char> &TempMatrix);
    void RightSideAlgorithm(Cube &MyCube, int NumOfTurns);
    void LeftSideAlgorithm(Cube &MyCube, int NumOfTurns);

    Cube();
    ~Cube();
    
 
protected:
    Front FrontSide;
    Back BackSide;
    Up UpSide;
    Left LeftSide;
    Down DownSide;
    Right RightSide; // Objects imagine sides of Cube.
};