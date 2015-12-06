#include "edge.h"

Edge::Edge(){
    StartVertex = NULL;
    EndVertex = NULL;
    index_Start = -1;
    index_End = -1;
    Dweight = -1;
    Uweight = 0;
    DU_BetweennessCentrality = 0;
    UU_BetweennessCentrality = 0;
    DW_BetweennessCentrality = 0;
    UW_BetweennessCentrality = 0;
    DW_Frontier = false;
    DW_Solution = false;
    DW_Removed = false;
    UW_Frontier = false;
    UW_Solution = false;
    UW_Removed = false;
    DU_Removed = false;
    UU_Removed = false;
}
