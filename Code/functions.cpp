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
    edgeSort(RBM, 0, num_edges);
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
            edgeSort(arr, left, j);
      if (i < right)
            edgeSort(arr, i, right);
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

void DW_GoHome(Edge matrix[][], int from, int to, Path parents[][]){
    if(from == to)
        return;
    else
    {
        matrix[parents[from][to]][to].traverse();
        path.DW_GoHome(matrix, from, parents[from][to], parents);
    }
    return;
}

void UW_GoHome(Edge matrix[][], int from, int to, Path parents[][]){
    if(from == to)
        return;
    else
    {
        matrix[parents[from][to]][to].traverse();
        path.UW_GoHome(matrix, from, parents[from][to], parents);
    }
    return;
}

void DU_GoHome(Edge matrix[][], int from, int to, Path parents[][], Vertex start){
    if(from == to)
        return;
    else
    {
        matrix[parents[from][to]][to].traverse(start);
        path.DU_GoHome(matrix, from, parents[from][to], parents, start);
    }
    return;
}

void UU_GoHome(Edge matrix[][], int from, int to, Path parents[][], Vertex start){
    if(from == to)
        return;
    else
    {
        matrix[parents[from][to]][to].traverse(start);
        path.UU_GoHome(matrix, from, parents[from][to], parents, start);
    }
    return;
}

void redPill(Edge matrix[][], Edge RBM[], Vertex vertical[], int num_edge){ //NOT DONE YET!!!
    int from, to;
    for(int i = 0; i < num_edge; i++)
    {
        from = VertexSearch(vertical, 0, num_edge, RBM[i].StartVertex);
        to = VertexSearch(vertical, 0, num_edge, RBM[i].EndVertex);
        matrix[from][to] = RBM[i];
        matrix[from][to].index_Start = from;
        matrix[from][to].index_End = to;
    }
    return;
}

int VertexSearch (Vertex vertical[], int left, int right, string name){
    int middle = (left+right)/2;
    if (vertical[middle].name == name)
        return middle;
    else if (vertical[middle].name > name)
        return VertexSearch(vertical, middle, right, name);
    else
        return VertexSearch(vertical, left, middle, name);
}

void bluePill(Edge RBM[], Edge Edgey[][], int num_edge){
    int from to;
    for (int i = 0; i < num_edge; i++)
    {
        from = RBM[i].index_Start;
        to = RBM[i].index_End;
        RBM[i] = Edgey[from][to];
    }
    return;
}

void UU_ComunismEdgeSort(Edge arr[], int left, int right) {
      int i = left, j = right;
      Edge tmp;
      int pivot = arr[(left + right) / 2].UU_BetweennessCentrality;

      /* partition */
      while (i <= j) {
            while (arr[i].StartVertex > pivot)
                  i++;
            while (arr[j].StartVertex < pivot)
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
            UU_ComunismEdgeSort(arr, left, j);
      if (i < right)
            UU_ComunismEdgeSort(arr, i, right);
    return;
}

void DU_ComunismEdgeSort(Edge arr[], int left, int right) {
      int i = left, j = right;
      Edge tmp;
      int pivot = arr[(left + right) / 2].DU_BetweennessCentrality;

      /* partition */
      while (i <= j) {
            while (arr[i].StartVertex > pivot)
                  i++;
            while (arr[j].StartVertex < pivot)
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
            DU_ComunismEdgeSort(arr, left, j);
      if (i < right)
            DU_ComunismEdgeSort(arr, i, right);
    return;
}

int UU_Comunism(Edge RBM[], int num_edge) {
    int removed = 0, Max = 0;
    UU_ComunismEdgeSort(RBM, 0, num_edge);
    for(int i = 0; i < 5; i++)
    {
        Max = RBM[removed].UU_BetweennessCentrality;
        while(RBM[removed].UU_BetweennessCentrality == Max)
        {
            RBM[removed].UU_Removed = true;
            removed++;
        };
    }
    return removed;
}

int DU_Comunism(Edge RBM[], int num_edge) {
    int removed = 0, Max = 0;
    DU_ComunismEdgeSort(RBM, 0, num_edge);
    for(int i = 0; i < 5; i++)
    {
        Max = RBM[removed].DU_BetweennessCentrality;
        while(RBM[removed].DU_BetweennessCentrality == Max)
        {
            RBM[removed].DU_Removed = true;
            removed++;
        };
    }
    return removed;
}


