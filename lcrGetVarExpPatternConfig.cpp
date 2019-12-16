#include "lcr.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    if (nrhs > 0)
    {
        mexErrMsgIdAndTxt("lcr:usage", "Usage: [numLutEntries, numPatsForTrigOut2, numImages, repeat] = lcrGetVarExpPatternConfig()");
        return;
    }
    unsigned int numLutEntries;
    unsigned int numPatsForTrigOut2;
    unsigned int numImages;
    bool repeat;
    int result = DLPC350_GetVarExpPatternConfig(&numLutEntries, &numPatsForTrigOut2, &numImages, &repeat);
    if (result == -1)
    {
        mexErrMsgIdAndTxt("lcr:failedToGetVarExpPatternConfig", "Failed to get variable exposure pattern config");
        return;
    }
    
    plhs[0] = mxCreateDoubleScalar(numLutEntries);
    plhs[1] = mxCreateDoubleScalar(numPatsForTrigOut2);
    plhs[2] = mxCreateDoubleScalar(numImages);
    plhs[3] = mxCreateLogicalScalar(repeat);
}