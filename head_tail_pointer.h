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

//typedef std::vector<std::vector<int>> matrix;

// head-tail pointer wrapper class
template<typename T>
class HTPtr{
private:
    int num_of_row;
    std::vector<Data<T>*> ptr;

public:
    HTPtr(const std::vector<std::vector<T>>* A) {
        num_of_row = A->size();
        int row_counter = 0;
        int col_counter = 0;
        Data<T>* temp = NULL;
        Data<T>* c = NULL;

        for(auto row: *A){
            for(auto val : row){
                if(val == 0) {

                }
                else{
                    c = new Data<T>{NULL, col_counter, val};
                    if(temp == NULL)
                        temp = c;
                    else
                        temp -> next = c;
                    temp = c;
                    if(ptr.size() == row_counter){
                        ptr.push_back(c);
                    }
                }
                col_counter++;
            }
            row_counter++;
            col_counter = 0;

        }
    }

    void printArc(int node_idx) {
        if(node_idx >= num_of_row){
            std::cout << "out of index" << std::endl;
            return;
        }
        Data<T>* i;
        Data<T>* i_;

        if (node_idx == num_of_row -1){
            i_ = NULL;
        }else{
            i_ = ptr.at(node_idx+1);
        }
        i = ptr.at(node_idx);

        Data<T>* temp;
        while(i != i_){
            std::cout << (i->value) << " ";
            i = i->next;
        }
    }

    std::vector<Data<T>*> getPtr() {
        return ptr;
    }

    std::vector<T> matmul(std::vector<T> x) {

        std::vector<T> res;
        for(int row_idx = 0; row_idx < num_of_row; row_idx++){

            Data<T>* i;
            Data<T>* i_;

            if (row_idx == num_of_row - 1){
                i_ = NULL;
            }else{
                i_ = ptr.at(row_idx + 1);
            }
            i = ptr.at(row_idx);

            int s = 0;
            while(i != i_){
                s += i->value * x.at(i->col);
                i = i->next;
            }
            res.push_back(s);
        }
        return res;

    }

    void pprint() {

        for(int i = 0; i < num_of_row; i++){
            printArc(i);
            std::cout << std::endl;
        }
    }
};
