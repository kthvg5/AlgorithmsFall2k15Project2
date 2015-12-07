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

