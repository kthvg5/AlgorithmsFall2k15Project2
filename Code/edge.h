#ifndef EDGE_H
#define EDGE_H
using namespace std;

#include <fstream>
#include <string>
#include <iostream>
class Edge{
/*
Key to reading veriable names:
DW = Directed Weighted
UW = Undirected Weighted
DU = Directed Unweighted
UU = Undirected Unweighted
*/
public:
    string StartVertex;
    string EndVertex;
    int index_Start;
    int index_End;
    int Dweight; //directed graph weight
    int Uweight;//undirected graph weight
    int DU_BetweennessCentrality;
    int UU_BetweennessCentrality;
    float DW_BetweennessCentrality; //Remember, before outputting this we need to devide it by it's weight
    float UW_BetweennessCentrality; //Ditto
    bool DW_Frontier, DW_Solution, DW_Removed, UW_Frontier, UW_Solution, UW_Removed; //bools for dijkstra
    bool DU_Removed, UU_Removed; //bools for BFS

    //functions

    //construstor
    Edge();


    //Traversal functions
    void DW_Traverce();
    void DU_Traverce(Vertex starts_at);
    void UW_Traverce();
    void UU_Traverce(Vertex starts_at);


};
#endif // EDGE_H
