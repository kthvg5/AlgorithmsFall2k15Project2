#include "functions.h"

void undirect(Edge matrix[][]){
    for(int i = 0; i < 547; i++)
    {
        for(int j = i; j < 547; j++)
        {
            if (matrix[i][j].Dweight == -1)
                matrix[i][j].Uweight = matrix[j][i].Dweight;
            else if(matrix[j][i] != -1)
                matrix[i][j].Uweight = matrix[i][j].Dweight+matrix[j][i].Dweight;
        }
    }
    return;
}

void edgeArrayInit(Edge RBM[], int num_edges){
    for(int i = 0; i < num_edges; i++)
    {
        getline(cin, RBM[i].from, ',');//that is a comma
        getline(cin, RBM[i].to, ',');//also a comma
        getline(cin, RBM[i].weight, '\n'); //not a comma
    }
    edgeSort(RBM[], 0, num_edges);
    return;
}

void edgeSort(Edge arr[], int left, int right) {
      int i = left, j = right;
      Edge tmp;
      string pivot = arr[(left + right) / 2].StartVertex;

      /* partition */
      while (i <= j) {
            while (arr[i].StartVertex < pivot)
                  i++;
            while (arr[j].StartVertex > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
    return;
}

void vertArrayInit(Vertex vert[], int num_edges, Edge RBM[]) {
    vertNo = 0;
    vert[0].index = 0;
    vert[0].name = RBM[0].StartVertex;
    for(int i = 1; i < num_edges; i++)
    {
        if (RBM[i].from !=vert[vertNo].name)
        {
            vertNo++;
            vert[vertNo].index = vertNo;
            vert[vertNo].name = RBM[i].from;
        }
    }
    return;
}

void DW_GoHome(Edge matrix[][], int from, int to, Path parents[][]);
{
    if(from == to)
        return;
    else
    {
        matrix[parents[from][to]][to].traverse();
        path.DW_GoHome(matrix, from, parents[from][to], parents);
    }
    return;
}

void UW_GoHome(Edge matrix[][], int from, int to, Path parents[][]);
{
    if(from == to)
        return;
    else
    {
        matrix[parents[from][to]][to].traverse();
        path.UW_GoHome(matrix, from, parents[from][to], parents);
    }
    return;
}

void DU_GoHome(Edge matrix[][], int from, int to, Path parents[][], Vertex start);
{
    if(from == to)
        return;
    else
    {
        matrix[parents[from][to]][to].traverse(start);
        path.DU_GoHome(matrix, from, parents[from][to], parents, start);
    }
    return;
}

void UU_GoHome(Edge matrix[][], int from, int to, Path parents[][], Vertex start);
{
    if(from == to)
        return;
    else
    {
        matrix[parents[from][to]][to].traverse(start);
        path.UU_GoHome(matrix, from, parents[from][to], parents, start);
    }
    return;
}











