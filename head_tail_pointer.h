//
// Created by yoonsikjung on 2022/03/16.
//

#ifndef NETWORK_OPTIMIZATION_HEAD_TAIL_POINTER_H
#define NETWORK_OPTIMIZATION_HEAD_TAIL_POINTER_H

#endif //NETWORK_OPTIMIZATION_HEAD_TAIL_POINTER_H
#include <iostream>
#include <vector>

class Data{

public:
    Data(Data* next, int col, int value) : next(next), col(col), value(value){}
    Data* next;
    int col;
    int value;
};

typedef Data* ptr_type;
typedef std::vector<std::vector<int>> matrix;

// head-tail pointer wrapper class
class HTPtr{
private:
    int num_of_row;
    int num_of_col;
    std::vector<Data*> ptr;

public:
    HTPtr(matrix A);
    std::vector<Data*> getPtr();
    void printArc(int node_idx);
    void pprint();
    std::vector<int> matmul(const std::vector<int> x);
};
