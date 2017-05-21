//
// Created by catofthecannals on 21/05/17.
//

#ifndef ALGO3_TP2_GRAFGEN_H
#define ALGO3_TP2_GRAFGEN_H

#include <chrono>
#include <random>
#include "/home/catofthecannals/algo3-tp2/src/graph.h"

void genKGraph(int n, edgeList &edges, int maxW, bool digraph);
void shuffleEdgeList(edgeList &edges);
void genRandomGraph(int n, int m, edgeList &edges, int maxW, bool digraph);

#endif //ALGO3_TP2_GRAFGEN_H