# IME552 - Network Optimization

## Description
Implementation for data structures related to networks or graphs.

1. Head-Tail Pointer for Sparse Matrix Calculation
2. Adjacency Matrix(not implemented yet)

## Usage
###1. Head-Tail Pointer

```c++
//example matrix A and vector x
std::vector<std::vector<int>> A;

A.push_back({2,0,-3,0,0,-5,0,4,0,0});
A.push_back({0,3,2,1,0,-3,0,0,4,2});
A.push_back({0,4,0,0,1,0,2,0,1,0});
A.push_back({1,0,0,1,0,0,0,2,0,0});
A.push_back({0,0,2,0,1,0,3,0,0,0});

std::vector<int> x = {1,0,2,0,1,0,0,1,5,1};

HTPtr p = HTPtr(A);
// test the code
p.pprint();

// matrix multiplication with vector x
auto res = p.matmul(x) // it returns vector

```

## License
[MIT](https://choosealicense.com/licenses/mit/)