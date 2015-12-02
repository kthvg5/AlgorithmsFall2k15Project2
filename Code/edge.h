#ifndef EDGE_H
#define EDGE_H
class Edge{
/*
Key to reading veriable names:
DW = Directed Weighted
UW = Undirected Weighted
DU = Directed Unweighted
UU = Undirected Unweighted
Open determins if Dijkstra and BFS will acknoledge its existance
*/
public;
    string StartVertex;
    string EndVertex;
    int index_Start;
    int index_End;
    int DU_BetweennessCentrality;
    int UU_BetweennessCentrality;
    float DW_BetweennessCentrality; //Remember, before outputting this we need to devide it by it's weight
    float DU_BetweennessCentrality; //Ditto

};
#endif // EDGE_H
