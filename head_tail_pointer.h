//
// Created by yoonsikjung on 2022/03/16.
//

#ifndef NETWORK_OPTIMIZATION_HEAD_TAIL_POINTER_H
#define NETWORK_OPTIMIZATION_HEAD_TAIL_POINTER_H

#endif //NETWORK_OPTIMIZATION_HEAD_TAIL_POINTER_H
#include <iostream>
#include <vector>

template <typename T>
class Data{

public:
    Data(Data* next, int col, T value) : next(next), col(col), value(value){}
    Data* next;
    int col;
    T value;
};

typedef std::vector<std::vector<int>> matrix;

// head-tail pointer wrapper class

class HTPtr{
private:
    int num_of_row;
    std::vector<Data<int>*> ptr;

public:

    HTPtr(const matrix* A);
    std::vector<Data<int>*> getPtr();
    void printArc(int node_idx);
    void pprint();
    std::vector<int> matmul(std::vector<int> x);
};
