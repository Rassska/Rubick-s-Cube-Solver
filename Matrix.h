#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <string>

class Matrix
{
public:
    Matrix();
    Matrix(std::vector<char> &position);
    ~Matrix();
 
protected:
    std::vector<char> matrix_;
    int size_;
};