#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
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
    cv::Mat img = cv::imread("C:/Users/arthu/Pictures/lol.png");
    namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
    cv::imshow("First OpenCV Application", img);
    cv::moveWindow("First OpenCV Application", 0, 45);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

int main()
{
    mainYahnis();
    mainArthur();
    return 0;
}