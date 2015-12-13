using namespace std;

#include <fstream>
#include <string>
#include <iostream>

#include "edge.h"
#include "path.h"
#include "vertex.h"


//function that takes a directed adjacency matrix and makes it into an
//undirected adjacency matrix, but only the top right half along the diagonal.
void undirect(Edge matrix[][547]);

//takes input in form of edge list (using format from,to,weight) and fills edge
//array RBM (replacable by matrix) in alphabetic order with respect to From
void edgeArrayInit(Edge RBM[], int num_edges);

//quicksort rewritten to work for edges
void edgeSort(Edge arr[], int left, int right);

//takes an array of edges and extracts the vertex names
void vertArrayInit(Vertex vert[], int num_edges, Edge RBM[]);

//traverse the path back home
//from is start of path. to is end of path
void DW_GoHome(Edge matrix[][547], int from, int to, Path parents[][547]);
void UW_GoHome(Edge matrix[][547], int from, int to, Path parents[][547]);
void DU_GoHome(Edge matrix[][547], int from, int to, Path parents[][547], Vertex start);
void UU_GoHome(Edge matrix[][547], int from, int to, Path parents[][547], Vertex start);

//takes an array of edges and places them into the array
//pass in: edge array, edge matrix, and path array
//yes this is a reference to The Matrix
void redPill(Edge matrix[][547], Edge RBM[], Vertex vertical[], int num_edge, int num_vert);

//takes a matrix of edges and uses it to update the array
//yes, this is still a reference ot The Matrix
void bluePill(Edge RBM[], Edge Edgy[][547], int num_edge);

//Sort the edge array in decending order with respect to
//UU_Betweeness and DU_Betweeness respectivly
void UU_ComunismEdgeSort(Edge arr[], int left, int right);
void DU_ComunismEdgeSort(Edge arr[], int left, int right);

//removes the edges that have one of the five highest betweenness centralities
//returns an int equal to the number of edges removed.
int UU_Comunism(Edge RBM[], int num_edge);
int DU_Comunism(Edge RBM[], int num_edge);

//takes array and uses it to update matrix. Slightly different from red pill
//Still a The Matrix joke
void PurplePill(Edge RBM[], Edge Edgy[][547], int num_edges);

//find the weighted and unweighted in and out degrees of each vertex
void degreeFinder(Vertex nodesBro[], Edge matrix[][547], int num_verts);

//Finds LSP weight and name for each node
//NOTE: this does not print that out. It just sets the values in each node
void LSP(Path wayHome[][547], int num_verts, Vertex Nodes[]);

//calculates and prints out the spread of degrees among nodes
void DegPrint(Vertex Nodes[], const int weight_in, const int weight_out,
const int weightless_in, const int weightless_out, const int num_verts);

//finds diameter of both directed and undirected forms of unweighted graph
//then passes those values to the two functions below this one for distribution
//calculation and printing
void ShortestPathDistroPrint(Path wayHome[][547], const int num_verts, Vertex Nodes[]);

//calculates and prints distribution of shortest paths for Undirected Unweighted graph
void UndirectedPathDistributionOutput(Path wayHome[][547], const int num_verts,
Vertex Nodes[], const int UMax);

//calculates and prints distribution of shortest paths for Directed Unweighted graph
void DirectedPathDistributionOutput(Path wayHome[][547], const int num_verts,
Vertex Nodes[], const int DMax);

//calculates and prints unweighted betweenness centrality. Follows the
//pattern of the functions above.
//NOTE--CALL BLUE PILL BEFORE CALLING THIS!!!
void UnweightedBetweennessDisplay(Edge RBM[], const int num_edge);

//calculates and prints distribution of betweenness centrality of Undirected Unweighted graph
void UU_BetweennessPrint(Edge RBM[], const int num_edge, const int UMax);

//calculates and prints distribution of betweenness centrality of Directed Unweighted graph
void DU_BetweennessPrint(Edge RBM[], const int num_edge, const int DMax);


/*
Functions still needed:
    Fixes weighted degree (currently I dont take into account the weight of the edge)
    Prints out weighted degree distribution
    Find and print unweighted closeness centrality distribution of a vertices


Other things still needed:
        Int main needs to be finished, but I think we should wait to do that until we know what
            all it needs to include
        Bugfixing.
        compiling
        Post compiling bugfixing
        submition

*/
