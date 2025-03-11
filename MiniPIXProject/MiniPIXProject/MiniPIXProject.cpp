#include "pxcapi.h"
#include <iostream>

int main() {
    int rc; // Return code

    std::cout << "Initializing Pixet Core..." << std::endl;
    rc = pxcInitialize();
    std::cout << "pxcInitialize: " << rc << " (0 is OK)" << std::endl;

    rc = pxcSetTimepix3Mode(0, PXC_TPX3_OPM_TOATOT);
    std::cout << "pxcSetTimepix3Mode: " << rc << " (0 is OK)" << std::endl;

    rc = pxcMeasureMultipleFrames(0, 3, 1, PXC_TRG_NO);
    std::cout << "pxcMeasureMultipleFrames: " << rc << " (0 is OK)" << std::endl;

    rc = pxcSaveMeasuredFrame(0, 0, "testImg0.png");
    std::cout << "Saved frame 0: " << rc << " (0 is OK)" << std::endl;

    rc = pxcSaveMeasuredFrame(0, 1, "testImg1.txt");
    std::cout << "Saved frame 1: " << rc << " (0 is OK)" << std::endl;

    rc = pxcSaveMeasuredFrame(0, 2, "testImg2.pbf");
    std::cout << "Saved frame 2: " << rc << " (0 is OK)" << std::endl;

    rc = pxcExit();
    std::cout << "pxcExit: " << rc << " (0 is OK)" << std::endl;

    return 0;

}
