#include "bfs.h"

const int vertices = 547;

void directed_BFS(Vertex array[], Edge d_edge[][vertices], Path d_path[][vertices])
{
    Vertex parent;
    queue<Vertex> path;

    //Iterate through the entire vertex array and find all BFS
    for(int x = 0; x < vertices; x++){
        int from = x;
        cout << "hello" << endl;
        //Creating the queue, place starting element into the queue
        path.push(array[x]); //queue
        cout << "this isnt the problem" << endl;
        parent = path.front();
        cout << "prolly not the prolem" << endl;
        array[x].DU_Found = true;
        cout << "possible" << endl;
        d_path[x][x].DU_Parent = x;
        d_path[x][x].DU_Weight = 0;
        //place the elements connected to the starting element into the queue and into the list
        //in the correct order
        while(!path.empty() && parent.index !=-1){
            cout << "do we get back in here?" << endl;
            for(int s = 0; s < vertices; s++){
                    cout << "s = " << s << endl;
                    cout << "parent = " << parent.index << endl;
                if(d_edge[parent.index][s].Dweight != -1 && d_edge[parent.index][s].DU_Removed != true && array[s].DU_Found != true){
                    cout << "im back" << endl;
                    parent = path.front();
                    path.push(array[s]);
                    array[s].DU_Found = true;
                    d_path[x][s].DU_Parent = parent.index;
                    d_path[x][s].DU_Weight = d_path[x][s].DU_Weight + 1;
                    DU_GoHome(d_edge, from, s, d_path, parent);
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
    Vertex parent;

    //Iterate through the entire vertex array and find all BFS
    for(int x = 0; x < vertices; x++){
        int from = x;

        //Creating the queue, place starting element into the queue
        queue<Vertex> path;
        path.push(array[x]); //queue

        array[x].UU_Found = true;
        d_path[x][x].UU_Parent = x;
        d_path[x][x].UU_Weight = 0;
        cout << "x = " << x << endl;
        //place the elements connected to the starting element into the queue and into the list
        //in the correct order
        while(!path.empty()&& parent.index !=-1){
            for(int s = 0; s < vertices; s++){
                if(d_edge[from][s].Uweight != -1 && d_edge[from][s].UU_Removed != true && array[s].UU_Found == false){
                    parent = path.front();
                    path.push(array[s]);
                    array[s].UU_Found = true;
                    d_path[x][s].UU_Parent = from;
                    d_path[x][s].UU_Weight = d_path[from][s].UU_Weight + 1;
                    UU_GoHome(d_edge, from, s, d_path, parent);
                }
            }
            path.pop();
        }

        for(int r = 0; r < vertices; r++){
            array[r].UU_Found = false;
        }
    }
}
