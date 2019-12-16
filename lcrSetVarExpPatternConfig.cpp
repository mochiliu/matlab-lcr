#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs < 4 || nrhs > 4)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: lcrSetVarExpPatternConfig(numLutEntries, repeat, numPatsForTrigOut2, numSplash)");
        return;
    }
    
    unsigned int numLutEntries = mxGetScalar(prhs[0]);
    bool repeat = mxGetScalar(prhs[1]);
    unsigned int numPatsForTrigOut2 = mxGetScalar(prhs[2]);
    unsigned int numSplash = mxGetScalar(prhs[3]);
    
    int result = DLPC350_SetVarExpPatternConfig(numLutEntries, repeat, numPatsForTrigOut2, numSplash);
    if (result < 0)
    {
        mexErrMsgIdAndTxt("lcr:failedToSetVarExpPatternConfig", "Failed to set varibale exposure pattern config");
        return;
    }
}