#ifndef VERTEX_H
#define VERTEX_H
using namespace std;

#include <fstream>
#include <string>
#include <iostream>

class Vertex{
/*
Key to reading veriable names:
DW = Directed Weighted
UW = Undirected Weighted
DU = Directed Unweighted
UU = Undirected Unweighted
LSP = Longest Shortest Path to START at the current vertex
InDegree is the sum of the weights of all incoming edges (weight = 1 for unweighted)
OutDegree is the sum of the weights of all outgoing edges (weight = 1 for unweighted)
ClosenessCentrality is the average path length to all vertices from the chosen vertex
Betweenness Centrality is the number of shortest paths that go through the chosen vertex

PathLength is a little tricky and requires knowledge of how we are storing these to
understand. Basically, all verteces will be stored in an array and sorted alphabetically.
PathLength[i] stores the weight of the path from this vertex to the vertex in with an index
of i in the array of all vertices.
*/
public:
    string name;
    int index; //yes, this can be gotten, but we only have a week and this is easier.

    //statistics on Vertex in a Directed Weighted graph
    int DW_InDegree;
    int DW_OutDegree;
    int DW_LSP_Weight; //Stores the weight of the LSP to start from this vertex
    string DW_LSP_EndNode;//Stores the endnode of that path
    bool DW_Solution;

    //statistics on Undirected Weighted
    int UW_LSP_Weight;
    string UW_LSP_EndNode;
    bool DW_Soluttion;

    //statistics on the Directed Unweighted graph
    int DU_InDegree;
    int DU_OutDegree;
    int DU_LSP_Weight;
    string DU_LSP_EndNode;
    int DU_ClosenessCentrality;
    int DU_BetweennessCentrality;
    bool DU_Found;

    //statistics on Vertex in an Undirected Unweighted graph
    int UU_LSP_Weight; //again, longest shortest path that STARTS here
    string UU_LSP_EndNode;
    int UU_ClosenessCentrality;
    int UU_BetweennessCentrality;
    bool UU_Found;

    //constructor
    Vertex();

    //Initial editing
    void initialize(const int I, const string Bill);

    //cross through functions (called when a path goes through a node)
    void DU_Cross();
    void UU_Cross();
};

#endif // VERTEX_H
