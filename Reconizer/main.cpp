#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "Video.h"
#include "Frame.h"

using namespace cv;

void mainYahnis()
{
    cv::Mat img = cv::imread("D:/Documents/Projets Dev/ReconIzer/Data/abstract-rainbow-colors-background.jpg");
    namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
    cv::imshow("First OpenCV Application", img);
    cv::moveWindow("First OpenCV Application", 0, 45);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

void mainArthur()
{
    Video test = Video("C:/Users/arthu/Desktop/Code/Reconize/ReconIzer/Data/BALLS.mp4");
    test.Display("test");
    cv::waitKey(0);
    cv::destroyAllWindows();
}

int main()
{
    //mainYahnis();
    mainArthur();
    return 0;
}