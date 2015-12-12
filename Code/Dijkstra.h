using namespace std;

#include <fstream>
#include <string>
#include <iostream>
#include <climits>

#include "edge.h"
#include "path.h"
#include "vertex.h"
#include "functions.h"

//This file contains the function declarations for the functions required
//to run our implimentation of Dijkstra.

void DW_dijkstra(Path WayHome[][547], Vertex nodes[], Edge Matrix[][547], int num_verts);
void UW_dijkstra(Path WayHome[][547], Vertex nodes[], Edge Matrix[][547], int num_verts);

//adds a node and it's incoming edges to the solution and it's outgoing
//edges to the frontier. There are probably better ways to do this, but
//we are using bools.
void DW_addToSolution(Vertex Node, Edge Matrix[][547], int num_verts);
void UW_addToSolution(Vertex Node, Edge Matrix[][547], int num_verts);

//sets all frontier and solution bools to false
void DW_reset(Edge Matrix[][547], Vertex Nodes[], int num_verts);
void UW_reset(Edge Matrix[][547], Vertex Nodes[], int num_verts);
