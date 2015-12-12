#include "Dijkstra.h"

//Directed Weighted
void DW_dijkstra(Path WayHome[][547], Vertex nodes[], Edge Matrix[][547], int num_verts)
{
    int bestFrom, bestTo, bestWeight = INT_MAX;
    for(int i = 0; i < num_verts; i++)
    {
        DW_addToSolution(nodes[i], Matrix, num_verts);
        for(int x = 1; x < num_verts; x++)
        {
            for(int from = 0; from < num_verts; from++)   //this goes through every possible edge (yes,
            {   //even the ones that aren't there) and finds which one is the best adition to our solution.
                if(nodes[from].DW_Solution == true) //this should do a lot of
                {       //optimizing since it cuts out half of our looping
                    for(int to = 0; to < num_verts; to++)
                    {
                        if(Matrix[from][to].Dweight !=-1)   //since the agerage node has
                        {   //like four edges going out of it, this should also cut some time. (note, weight of -1 indicates no edge)
                            if((Matrix[from][to].Dweight + WayHome[from][to].DW_Weight) < bestWeight//checks if weight is better than current
                            && Matrix[from][to].DW_Solution == false   //makes sure this isnt an edge we already got
                            && Matrix[from][to].DW_Frontier == true)   //makes sure this edge is one we are able to get
                            {
                                bestFrom = from;
                                bestTo = to;
                            }
                        }
                    }
                }
            }//detect if bestFrom/bestTo have been changed (maybe reset them to -1 and if they are still that, break from loop
            DW_addToSolution(nodes[Matrix[bestFrom][bestTo].index_End], Matrix, num_verts);   //adds "Best" node to solution
            DW_GoHome(Matrix, i, Matrix[bestFrom][bestTo].index_End, WayHome);   //paths itself back home
        }
        DW_reset(Matrix, nodes, num_verts);
    }
    return;
}

void DW_addToSolution(Vertex Node, Edge Matrix[][547], int num_verts, int from){
    Node.DW_Solution = true;
    for (int i = 0; i < num_verts; i++)
    {
        Matrix[i][Node.index].DW_Solution = True;
        Matrix[Node.index][i].DW_Frontier = True;
    }
    return;
}

void DW_reset(Edge Matrix[][547], Vertex Nodes[], int num_verts){
    for(int i = 0; i < num_verts; i++)
    {
        Nodes[i].DW_Solution = false;
        for(int x = 0; x < num_verts; x++)
        {
            Matrix[i][x].DW_Frontier = false;
            Matrix[i][x].DW_Solution = false;
        }
    }
    return;
}

//Undirected Weighted
void UW_dijkstra(Path WayHome[][547], Vertex nodes[], Edge Matrix[][547], int num_verts)
{
    int bestFrom, bestTo, bestWeight = INT_MAX;
    for(int i = 0; i < num_verts; i++)
    {
        UW_addToSolution(nodes[i], Matrix, num_verts);
        for(int x = 1; x < num_verts; x++)
        {
            for(int from = 0; from < num_verts; from++)   //this goes through every possible edge (yes,
            {   //even the ones that aren't there) and finds which one is the best adition to our solution.
                if(nodes[from].UW_Solution == true) //this should do a lot of
                {       //optimizing since it cuts out half of our looping
                    for(int to = 0; to < num_verts; to++)
                    {
                        if(Matrix[from][to].Uweight !=-1)   //since the agerage node has
                        {   //like four edges going out of it, this should also cut some time. (note, weight of -1 indicates no edge)
                            if((Matrix[from][to].Uweight + WayHome[from][to].UW_Weight) < bestWeight//checks if weight is better than current
                            && Matrix[from][to].UW_Solution == false   //makes sure this isnt an edge we already got
                            && Matrix[from][to].UW_Frontier == true)   //makes sure this edge is one we are able to get
                            {
                                bestFrom = from;
                                bestTo = to;
                            }
                        }
                    }
                }
            }
            UW_addToSolution(nodes[Matrix[bestFrom][bestTo].index_End], Matrix, num_verts);   //adds "Best" node to solution
            UW_GoHome(Matrix, i, Matrix[bestFrom][bestTo].index_End, WayHome);   //paths itself back home
        }
        UW_reset(Matrix, nodes, num_verts);
    }
    return;
}

void UW_addToSolution(Vertex Node, Edge Matrix[][547], int num_verts, int from){
    Node.UW_Solution = true;
    for (int i = 0; i < num_verts; i++)
    {
        Matrix[i][Node.index].UW_Solution = True;
        Matrix[Node.index][i].UW_Frontier = True;
    }
    return;
}

void UW_reset(Edge Matrix[][547], Vertex Nodes[], int num_verts){
    for(int i = 0; i < num_verts; i++)
    {
        Nodes[i].UW_Solution = false;
        for(int x = 0; x < num_verts; x++)
        {
            Matrix[i][x].UW_Frontier = false;
            Matrix[i][x].UW_Solution = false;
        }
    }
    return;
}
