#include "Dijkstra.h"

void DW_dijkstra(Path WayHome[][], Vertex nodes[], Edge Matrix[][], int num_verts)
{
    int bestFrom, bestTo, bestWeight = INT_MAX;
    for(int i = 0; i < num_verts; i++)
    {
        addToSolution(nodes[i], Matrix, num_verts);
        for(int x = 1; x < num_verts; x++)
        {
            for(int from = 0; from < num_verts; from++)
            {
                if(nodes[from].solution == true)
                {
                    for(int to = 0; to < num_verts; to++)
                    {
                        if(Matrix[from][to].Dweight !=-1)
                        {
                            if(Matrix[from][to].Dweight + Path[from][to].weight < bestWeight
                            && Matrix[from][to].DW_Solution == false
                            && Matrix[from][to].DW_Frontier == true)
                            {
                                bestFrom = from;
                                bestTo = to;
                            }
                        }
                    }
                }
            }
            addToSolution(WayHome, nodes[Matrix[bestFrom][bestTo].index_End],
            Matrix, num_verts);
            DW_GoHome(Matrix, i, Matrix[bestFrom][bestTo].index_End, WayHome);
        }
        reset(Matrix, nodes, num_verts);
    }
    return;
}

void DW_addToSolution(Vertex Node, Edge Matrix[][], int num_verts, int from){
    Node.DW_Solution = true;
    for (int i = 0; i < num_verts; i++)
    {
        Matrix[i][Node.index].DW_Solution = True;
        Matrix[Node.index][i].DW_Frontier = True;
    }
    return;
}

void DW_reset(Edge Matrix[][], Vertex Nodes[], int num_verts){
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









