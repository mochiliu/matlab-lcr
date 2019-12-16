#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrSendVarExpPatLut()");
        return;
    }
    
    int result = DLPC350_SendVarExpPatLut();
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToSendVarExpPatLut", "Failed to send variable exposure pattern LUT");
        return;
    }
}