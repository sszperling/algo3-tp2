//
// Created by catofthecannals on 21/05/17.
//

#include "grafGen.h"


void genKGraph(int n, edgeList &edges, int maxW, bool digraph){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::uniform_int_distribution<int> distribution(0, maxW);
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            edge e;
            e.start = i;
            e.end = j;
            e.weight = distribution(generator);
            edges.push_back(e);
            if(digraph){
                edge f;
                f.start = j;
                f.end = i;
                f.weight = distribution(generator);
                edges.push_back(f);
            }
        }

    }
}

void shuffleEdgeList(edgeList &edges) { //https://codeground.in/blog/index.php/2016/11/13/technical-interview-question-on-data-structures-and-algorithms-perfect-shuffle/
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    for (int i = 0; i < edges.size(); ++i) {
        std::uniform_int_distribution<int> distribution(i, edges.size()-1);
        std::swap(edges[i], edges[distribution(generator)]);
    }
}

void genRandomGraph(int n, int m, edgeList &edges, int maxW, bool digraph) {
    genKGraph(n, edges, maxW, digraph);
    shuffleEdgeList(edges);
    int amountOfEdgesToErase = n*(n-1) - m;
    for (int i = 0; i < amountOfEdgesToErase; ++i) {
        edges.pop_back();
    }

}
