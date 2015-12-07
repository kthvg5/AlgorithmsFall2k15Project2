#ifndef PATH_H
#define PATH_H

using namespace std;

#include <fstream>
#include <string>
#include <iostream>
class Path{
/*
Key to reading veriable names:
DW = Directed Weighted
UW = Undirected Weighted
DU = Directed Unweighted
UU = Undirected Unweighted
*/
public:
    int DW_Parent, DW_Weight, UW_Parent, UW_Weight, DU_Parent, DU_Weight, UU_Parent, UU_Weight;

    //constructor
    Path();

    //traverse the path back home
    void DW_GoHome(Edge matrix[][], int from, int to, Path parents[][]);
    void UW_GoHome(Edge matrix[][], int from, int to, Path parents[][]);
    void DU_GoHome(Edge matrix[][], int from, int to, Path parents[][], Vertex start);
    void UU_GoHome(Edge matrix[][], int from, int to, Path parents[][], Vertex start);
};

#endif // PATH_H
