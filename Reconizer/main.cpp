#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "Video.h"
#include "Frame.h"
#include "VideoOperations.h"

using namespace cv;

void mainYahnis(string path)
{
    Video* test = new Video(path + "/Data/BALLS.mp4");
    test->Display("test");
    VideoOperations::UnitedColor(150, 0, 0, test);
    cv::waitKey(0);
    cv::destroyAllWindows();
}

void mainArthur(string path)
{
    Video test = Video( path + "/Data/BALLS.mp4");
    test.Display("test");
    cv::waitKey(0);
    cv::destroyAllWindows();
}

int main()
{ 
    //mainYahnis("D:/Documents/Projets Dev/ReconIzer");
    mainArthur("C:/Users/arthu/Desktop/Code/Reconize/ReconIzer");
    return 0;
}