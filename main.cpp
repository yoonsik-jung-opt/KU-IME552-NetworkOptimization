
#include <vector>
#include <fstream>
#include "head_tail_pointer.h"
#include "adj_list.h"
#include <sstream>

void testHTPointer() {
    //example matrix & vector
    std::vector<std::vector<int>> A;

    A.push_back({2, 0, -3, 0, 0, -5, 0, 4, 0, 0});
    A.push_back({0, 3, 2, 1, 0, -3, 0, 0, 4, 2});
    A.push_back({0, 4, 0, 0, 1, 0, 2, 0, 1, 0});
    A.push_back({1, 0, 0, 1, 0, 0, 0, 2, 0, 0});
    A.push_back({0, 0, 2, 0, 1, 0, 3, 0, 0, 0});

    std::vector<int> x = {1, 0, 2, 0, 1, 0, 0, 1, 5, 1};

    HTPtr<int> p = HTPtr<int>(&A);
    // print test code
    p.pprint();
    std::cout << std::endl;
    // matrix multiplication test code
    for (auto i: p.matmul(x)) {
        std::cout << i << " ";
    }
}

std::vector<std::tuple<int, int>> readEdges(std::string fname, int lines = -1) {
//    std::cout << std::__fs::filesystem::current_path() << std::endl;
    std::vector<std::tuple<int, int>> edges;
    std::ifstream file(fname);
    std::string delim = " ";

    if (file.is_open()) {
        std::string s;
        if (lines == -1) {// read all
            while (std::getline(file, s)) {
                size_t pos = 0;
                std::vector<int> nodes{};
                pos = s.find(delim);
                std::stringstream ss(s);
                int temp;
                while (ss >> temp) {
                    nodes.push_back(temp);
                }
                edges.push_back(std::tuple<int, int>(nodes[0], nodes[1]));
            }
        } else {
            for (int i = 0; i < lines; ++i) {
                getline(file, s);
                size_t pos = 0;
                std::vector<int> nodes{};
                pos = s.find(delim);
                std::stringstream ss(s);
                int temp;
                while (ss >> temp) {
                    nodes.push_back(temp);
                }
                edges.push_back(std::tuple<int, int>(nodes[0], nodes[1]));
            }
        }
    }
    return edges;
}

void testAdjList(int testcase = 1) {
    std::vector<std::tuple<int, int>> edges;
    switch (testcase) {
        case 1:
            edges = readEdges("../test_edges.txt");
            break;

        case 2:
            edges = readEdges("../graph500-scale18-ef16_adj.edges.txt", 1000);
            break;

        case 3:
            edges.emplace_back(2, 1);
            edges.emplace_back(3, 1);
            edges.emplace_back(4, 1);
            edges.emplace_back(6, 1);
            break;
    }

    AdjacencyList adj = AdjacencyList();
    for (auto i: edges) {
        adj.addDirectedEdge(std::get<0>(i), std::get<1>(i));
    }

//    adj.printNodes();
    adj.printEdges();
//    adj.printNodes();
//    std::cout << adj.checkIndegree(4) <<std::endl;

    adj.topologicalOrdering();
}

int main() {
    testAdjList(2);

    return 0;
}
