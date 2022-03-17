//
// Created by yoonsikjung on 2022/03/14.
//
#include "head_tail_pointer.h"

HTPtr::HTPtr(matrix A) {
    num_of_row = A.size();
    num_of_col = A[0].size();
//        ptr.resize(num_of_row);
    int row_counter = 0;
    int col_counter = 0;
    Data* temp = NULL;
    Data* c = NULL;

    for(auto row: A){
        for(auto val : row){
            if(val == 0) {

            }
            else{
                c = new Data{NULL, col_counter, val};
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

void HTPtr::printArc(int node_idx) {
    if(node_idx >= num_of_row){
        std::cout << "out of index" << std::endl;
        return;
    }
    Data* i;
    Data* i_;

    if (node_idx == num_of_row -1){
        i_ = NULL;
    }else{
        i_ = ptr.at(node_idx+1);
    }
    i = ptr.at(node_idx);

    Data* temp;
    while(i != i_){
        std::cout << (i->value) << " ";
        i = i->next;
    }
}

std::vector<Data *> HTPtr::getPtr() {
    return ptr;
}

std::vector<int> HTPtr::matmul(const std::vector<int> x) {

        std::vector<int> res;
        for(int row_idx = 0; row_idx < num_of_row; row_idx++){

            Data* i;
            Data* i_;

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

void HTPtr::pprint() {

        for(int i = 0; i < num_of_row; i++){
            printArc(i);
            std::cout << std::endl;
        }


}






