//
// Created by yoonsikjung on 2022/03/21.
//

#ifndef NETWORK_OPTIMIZATION_ADJ_LIST_H
#define NETWORK_OPTIMIZATION_ADJ_LIST_H

#endif //NETWORK_OPTIMIZATION_ADJ_LIST_H

#include <vector>
#include <tuple>

// assume all parameters are integer.

class Edge;

class Node;

class Edge {

public:
    int head;
    int cost;
    int lb;
    int ub;
    Edge *next;
};

class Node {
public:
    int nodeId;
    int capacity;
    Edge *next;


};


class AdjacencyList {
    std::vector<Node *> nodes;
//    int N; // number of nodes
//    int M; // number of edges


public:
    AdjacencyList() = default;

//    AdjacencyList(int N);
    AdjacencyList(std::vector<std::tuple<int, int>> edges, bool isDirected) {
        if (isDirected) {
            for (auto i: edges) {
                addDirectedEdge(std::get<0>(i), std::get<1>(i));
            }
        } else {
            for (auto i: edges) {
                addUnDirectedEdge(std::get<0>(i), std::get<1>(i));
            }
        }
    };


    Edge *findLastEdge(Edge *edge) {
        if (edge->next == NULL) {
            return edge;
        } else {
            return findLastEdge((edge)->next);
        }

    }

    void addEdgeToNode(Node *node, Edge *edge) {
        if (node->next == NULL) {
            node->next = edge;
        } else {
            auto end = findLastEdge((node->next));
            end->next = edge;
        }
    }


    Node *findNode(int nodeId) {
        auto first = nodes.begin();
        auto last = nodes.end();
        for (; first != last; ++first) {
            if ((**first).nodeId == nodeId) {
                return *first;
            }
        }
        return NULL;
    }

    void addDirectedEdge(int tail, int head, int cost = 1, int lb = 0, int ub = 0) {
        // if node_t not exist, add node_t
        Node *node_t = findNode(tail);
        Node *node_h = findNode(head);
        if (node_t == NULL) {
            node_t = new Node{tail, 0, NULL};
            nodes.push_back(node_t);
        }
        if (node_h == NULL) {
            node_h = new Node{head, 0, NULL};
            nodes.push_back(node_h);
        }

        // generate edge instance
        auto edge_t = new Edge{head, cost, lb, ub, NULL};
        // connect to node_t
        addEdgeToNode(node_t, edge_t);

    }

    void addUnDirectedEdge(int u, int v, int cost = 1, int lb = 0, int ub = 0) {
        Node *node_u = findNode(u);
        Node *node_v = findNode(v);

        // if node not exist, add node
        if (node_u == NULL) {
            node_u = new Node{u, 0, NULL};
            nodes.push_back(node_u);
        }
        if (node_v == NULL) {
            node_v = new Node{v, 0, NULL};
            nodes.push_back(node_v);
        }

        // u -> v
        // generate edge instance
        auto edge_u = new Edge{v, cost, lb, ub, NULL};
        // connect to node_u
        node_u->next = edge_u;

        // v -> u
        // generate edge instance
        auto edge_v = new Edge{v, cost, lb, ub, NULL};
        // connect to node
        node_v->next = edge_v;
    }

    void printNodes() {
        for (auto i: nodes) {
            std::cout << (*i).nodeId << std::endl;
        }
    }

    void printEdges() {
        for (auto i: nodes) {
            auto cursor = i->next;
            std::cout << (*i).nodeId << ":";
            while (cursor != NULL) {
                std::cout << (*cursor).head << " -> ";
                cursor = cursor->next;
            }
            std::cout << std::endl;
        }
    }

};
