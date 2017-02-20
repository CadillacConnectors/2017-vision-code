#include <iostream>
#include "opencv2/opencv.hpp"
#include <sys/stat.h>

using namespace cv;

int main() {
    VideoCapture cap;
    const char *file = "cam0.jpg";
    struct stat buffer;

    if(!cap.open(0))
        return 0;
    for(;;)
    {
        Mat frame;

        cap >> frame;

        //frame -= Scalar(255, 200, 255);

        if( frame.empty()) break; // end of video stream

        if (stat(file, &buffer)) std::remove(file);

        imwrite(file, frame);

        if( waitKey(10) == 27 ) break; // stop capturing by pressing ESC
    }
    // the camera will be closed automatically upon exit
    // cap.close();
    return 0;
}

