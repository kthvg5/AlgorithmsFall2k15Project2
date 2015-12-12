#ifndef BFS_H
#define BFS_H

#include <iostream>
#include <string>
#include <queue>
#include "functions.h"

using namespace std;

void directed_BFS(Vertex array[], Edge 2d_edge[][], Path 2d_path[][]);

void undirected_BFS(Vertex array[], Edge 2d_edge[][], Path 2d_path[][]);

#endif //BFS_H

