#include "path.h"

Path::Path()
{
    DW_Parent = -1;
    DW_Weight = int.max;
    UW_Parent = -1;
    UW_Weight = int.max;
    DU_Parent = -1;
    DU_Weight = int.max;
    UU_Parent = -1;
    UU_Weight = int.max;
}

void Path::DW_GoHome(Edge matrix[][], int from, int to, Path parents[][]);
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

void Path::UW_GoHome(Edge matrix[][], int from, int to, Path parents[][]);
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

void Path::DU_GoHome(Edge matrix[][], int from, int to, Path parents[][], Vertex start);
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

void Path::UU_GoHome(Edge matrix[][], int from, int to, Path parents[][], Vertex start);
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

