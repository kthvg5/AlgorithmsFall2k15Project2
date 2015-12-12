#include "vertex.h"

Vertex::Vertex(){
    name = NULL;
    index= -1;

    DW_InDegree = 0;
    DW_OutDegree = 0;
    DW_LSP_Weight = 0;
    DW_LSP_EndNode =NULL;
    DW_Solution = false;

    UW_LSP_Weight = 0;
    UW_LSP_EndNode = NULL;
    UW_Solution = false;

    DU_InDegree = 0;
    DU_OutDegree = 0;
    DU_LSP_Weight = 0;
    DU_LSP_EndNode = NULL;
    DU_ClosenessCentrality = 0;
    DU_BetweennessCentrality = 0;
    DU_Found = false;

    UU_LSP_Weight = 0;
    UU_LSP_EndNode = NULL;
    UU_ClosenessCentrality = 0;
    UU_BetweennessCentrality = 0;
    UU_Found = false;

}

void Vertex::initialize(const int I, const string Bill){
    name = Bill;
    index = I;
    return;
}

void Vertex::DU_Cross(){
    DU_BetweennessCentrality++;
    return;
}

void Vertex::UU_Cross(){
    UU_BetweennessCentrality++;
    return;
}


