using namespace std;

#include <fstream>
#include <string>
#include <iostream>


//function that takes a directed adjacency matrix and makes it into an
//undirected adjacency matrix, but only the top right half along the diagonal.
void undirect(Edge matrix[][]);

//takes input in form of edge list (using format from,to,weight) and fills edge
//array RBM (replacable by matrix) in alphabetic order with respect to From
void edgeArrayInit(Edge RBM[], int num_edges);

//quicksort rewritten to work for edges
void edgeSort(Edge arr[], int left, int right);

//takes an array of edges and extracts the vertex names
void vertArrayInit(Vertex vert[], int num_edges, Edge RBM[]);

//traverse the path back home
void DW_GoHome(Edge matrix[][], int from, int to, Path parents[][]);
void UW_GoHome(Edge matrix[][], int from, int to, Path parents[][]);
void DU_GoHome(Edge matrix[][], int from, int to, Path parents[][], Vertex start);
void UU_GoHome(Edge matrix[][], int from, int to, Path parents[][], Vertex start);

//takes an array of edges and places them into the array
//pass in: edge array, edge matrix, and path array
//yes this is a reference to The Matrix
void redPill(Edge matrix[][], Edge RBM[], Vertex vertical[], int num_edge);

//binary search implimented for our nodes.
//takes in Vertex array and a string Name.
//returns int value of index. Sorry Morales, no Pointers
int VertexSearch (Vertex vertical[], int left, int right, string name);
