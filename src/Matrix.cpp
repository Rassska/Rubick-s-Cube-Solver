#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <string>

#include "Matrix.h"


    Matrix::Matrix()
    {
        this->size_ = 9;
        this->matrix_.resize(size_);
        for (int i = 0; i < size_; i++)
        {
            matrix_[i] = 'W'; // Determing random colors for side of Cube
        }
    }
 
    Matrix::Matrix(std::vector<char> &position) : Matrix()
    {
        for (int i = 0; i < size_; i++)
        {
            matrix_[i] = position[i]; //  Determing colors for each sell of side of Cube
        }
    }
 
    Matrix::~Matrix(){}