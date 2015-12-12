#include "bfs.h"

const int vertices = 547;

void directed_BFS(Vertex array[], Edge d_edge[][vertices], Path d_path[][vertices])
{
    int parent;

    //Iterate through the entire vertex array and find all BFS
    for(int x = 0; x < vertices; x++){
        int from = x;

        //Creating the queue, place starting element into the queue
        queue<Vertex> path;
        path.push(x); //queue

        Vertex[x].DU_found = true;

        //place the elements connected to the starting element into the queue and into the list
        //in the correct order
        while(!path.empty()){
            for(int s = 0; s < vertices; s++){
                if(d_edge.Dweight[from][s] != -1 && d_edge.UU_removed != true && Vertex[s].found == false){
                    parent = path.front();
                    path.push(s);
                    Vertex[s].DU_Found = true;
                    d_path[x][s].DU_Parent = from;
                    d_path[x][s].DU_Weight = d_path[from][s] + 1;
                    d_path[x][s].DU_GoHome(Edge d_edge[][vertices], int from, int s, Path d_path[][vertices], int parent);
                }
            }
            path.pop();
        }
        
        for(int r = 0; r < vertices; r++){
            Vertex[x][r].DU_Found = false; 
        }
    }
}

void undirected_BFS(Vertex array[], Edge d_edge[][vertices], Path d_path[][vertices])
{
    int parent;

    //Iterate through the entire vertex array and find all BFS
    for(int x = 0, x < vertices; x++){
        int from = x;

        //Creating the queue, place starting element into the queue
        queue<Vertex> path;
        path.push(x); //queue

        Vertex[x].UU_found = true;

        //place the elements connected to the starting element into the queue and into the list
        //in the correct order
        while(!path.empty()){
            for(int s = 0; s < vertices; s++){
                if(d_edge.Uweight[from][s] != -1 && d_edge.UU_removed != true && Vertex[s].found == false){
                    parent = path.front();
                    path.push(s);
                    Vertex[s].UU_Found = true;
                    d_path[x][s].UU_Parent = from;
                    d_path[x][s].UU_Weight = d_path[from][s] + 1;
                    d_path[x][s].UU_GoHome(Edge d_edge[][vertices], int from, int s, Path d_path[][vertices], int parent);
                }
            }
            path.pop();
        }
        
        for(int r = 0; r < vertices; r++){
            Vertex[x][r].DU_Found = false; 
        }
    }
}
