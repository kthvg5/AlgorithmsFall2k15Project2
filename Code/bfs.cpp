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
        path.push(array[x]); //queue

        array[x].DU_Found = true;

        //place the elements connected to the starting element into the queue and into the list
        //in the correct order
        while(!path.empty()){
            for(int s = 0; s < vertices; s++){
                if(d_edge[from][s].Dweight != -1 && d_edge[from][s].UU_Removed != true && array[s].DU_Found == false){
                    parent = path.front();
                    path.push(array[s]);
                    array[s].DU_Found = true;
                    d_path[x][s].DU_Parent = from;
                    d_path[x][s].DU_Weight = d_path[from][s].DU_Weight + 1;
                    DU_GoHome(Edge d_edge[][vertices], int from, int s, Path d_path[][vertices], int parent);
                }
            }
            path.pop();
        }
        
        for(int r = 0; r < vertices; r++){
            array[r].DU_Found = false; 
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
        path.push(array[x]); //queue

        array[x].UU_found = true;

        //place the elements connected to the starting element into the queue and into the list
        //in the correct order
        while(!path.empty()){
            for(int s = 0; s < vertices; s++){
                if(d_edge[from][s].Uweight != -1 && d_edge[from][s].UU_removed != true && array[s].DU_Found == false){
                    parent = path.front();
                    path.push(array[s]);
                    array[s].UU_Found = true;
                    d_path[x][s].UU_Parent = from;
                    d_path[x][s].UU_Weight = d_path[from][s].DU_Weight + 1;
                    UU_GoHome(Edge d_edge[][vertices], int from, int s, Path d_path[][vertices], int parent);
                }
            }
            path.pop();
        }
        
        for(int r = 0; r < vertices; r++){
            array[r].DU_Found = false; 
        }
    }
}
