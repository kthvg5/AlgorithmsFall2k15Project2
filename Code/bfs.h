#ifndef BFS_H
#define BFS_H

#include <iostream>
#include <string>
#include <queue>
#include "functions.h"

using namespace std;

void directed_BFS(Vertex array[], Edge d_edge[][547], Path d_path[][547]);

void undirected_BFS(Vertex array[], Edge d_edge[][547], Path d_path[][547]);

#endif //BFS_H

