# IME552 - Network Optimization

## Description
Implementation of data structures and algorithms related to the networks or graphs.

1. Head-Tail Pointer for Sparse Matrix Calculation(head_tail_pointer.h)
2. Adjacency List (adj_list.h)
3. Graph Search Algorithm

## Usage
### 1. Head-Tail Pointer
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
### 2. Adjacency List
test_edges.txt
```c++
1 3
2 3
1 4
```
```c++
// load edges
std::vector<std::tuple<int, int>> edges = readEdges("test_edges.txt", 3);

AdjacencyList adj = AdjacencyList();
// It'll be deprecated and replaced by the constructor.
for(auto i : edges){
    adj.addDirectedEdge(std::get<0>(i), std::get<1>(i));
}
// test code
adj.printEdges();
```


## License
[MIT](https://choosealicense.com/licenses/mit/)