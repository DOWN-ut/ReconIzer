#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;

int main()
{
    //cv::Mat img = cv::imread("D:/Documents/Projets Dev/ReconIzer/Data/abstract-rainbow-colors-background.jpg");
    cv::Mat img2 = cv::imread("C:/Users/arthu/Pictures/lol.png");
    namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
    cv::imshow("First OpenCV Application", img2);
    cv::moveWindow("First OpenCV Application", 0, 45);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}