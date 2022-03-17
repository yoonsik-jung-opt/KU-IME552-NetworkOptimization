
#include <vector>
#include "head_tail_pointer.h"

int main() {
    //example matrix & vector
    std::vector<std::vector<int>> A;

    A.push_back({2,0,-3,0,0,-5,0,4,0,0});
    A.push_back({0,3,2,1,0,-3,0,0,4,2});
    A.push_back({0,4,0,0,1,0,2,0,1,0});
    A.push_back({1,0,0,1,0,0,0,2,0,0});
    A.push_back({0,0,2,0,1,0,3,0,0,0});

    std::vector<int> x = {1,0,2,0,1,0,0,1,5,1};

    HTPtr<int> p = HTPtr<int>(&A);
    // print test code
    p.pprint();
    std::cout << std::endl;
    // matrix multiplication test code
    for(auto i : p.matmul(x)){
        std::cout << i << " ";
    }

    return 0;
}
