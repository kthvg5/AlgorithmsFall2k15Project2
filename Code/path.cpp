#include "path.h"

Path::Path()
{
    DW_Parent = -1;
    DW_Weight = INT_MAX/2;
    UW_Parent = -1;
    UW_Weight = INT_MAX/2;
    DU_Parent = -1;
    DU_Weight = INT_MAX/2;
    UU_Parent = -1;
    UU_Weight = INT_MAX/2;
}

