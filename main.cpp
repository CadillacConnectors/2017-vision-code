#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;

int main() {
    VideoCapture cap;
    VideoCapture cap2;
    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    if(!cap.open(0) || !cap2.open(1))
        return 0;
    for(;;)
    {
        Mat frame;
        Mat frame2;

        cap >> frame;
        cap2 >> frame2;

        frame -= Scalar(255, 200, 255);
        frame2 -= Scalar(255, 200, 255);

        if( frame.empty() || frame2.empty()) break; // end of video stream
        imshow("Camera 0", frame);
        imshow("Camera 1", frame2);
        if( waitKey(10) == 27 ) break; // stop capturing by pressing ESC
    }
    // the camera will be closed automatically upon exit
    // cap.close();
    return 0;
}

