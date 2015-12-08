#include "bfs.h"

void directed_BFS(Vertex array[], Edge 2d_edge[][], Path 2d_path[][])
{
    int parent;

    //Iterate through the entire vertex array and find all BFS
    for(int x = 0, x < 547; x++){
        int front = x;

        //Creating the queue, place starting element into the queue
        queue<Vertex> path;
        path.push(x); //queue

        Vertex[x].DU_found = true;

        //place the elements connected to the starting element into the queue and into the list
        //in the correct order
        while(!path.empty()){
            for(int s = 0; s < 547; s++){
                if(2d_edge.Dweight[x][s] != -1 && 2d_edge.UU_removed != true && Vertex[s].found == false)
                    parent = front;
                    path.push(s);
                    Vertex[s].DU_Found = true;
                    2d_path[x][s].DU_Parent = front;
                    2d_path[x][s].DU_Weight = 2d_path[x][front] + 1;
                    2d_path[x][s].DU_GoHome(Edge 2d_edge[][], int x, int s, Path 2d_path[][], int parent);
            }
            path.pop();
        }
    }
}

void undirected_BFS(Vertex array[], Edge 2d_edge[][], Path 2d_path[][])
{
    int parent;

    //Iterate through the entire vertex array and find all BFS
    for(int x = 0, x < 547; x++){
        int front = x;

        //Creating the queue, place starting element into the queue
        queue<Vertex> path;
        path.push(x); //queue

        Vertex[x].UU_found = true;

        //place the elements connected to the starting element into the queue and into the list
        //in the correct order
        while(!path.empty()){
            for(int s = 0; s < 547; s++){
                if(2d_edge.Uweight[x][s] != -1 && 2d_edge.UU_removed != true && Vertex[s].found == false)
                    parent = front;
                    path.push(s);
                    Vertex[s].UU_Found = true;
                    2d_path[x][s].UU_Parent = front;
                    2d_path[x][s].UU_Weight = 2d_path[x][front] + 1;
                    2d_path[x][s].UU_GoHome(Edge 2d_edge[][], int x, int s, Path 2d_path[][], int parent);
            }
            path.pop();
        }
    }
}
