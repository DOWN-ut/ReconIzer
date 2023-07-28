#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "Video.h"
#include "Frame.h"
#include "Thumbnail.h"
#include "VideoOperations.h"

using namespace cv;

void mainYahnis(string path)
{
    Video* test = new Video(path + "/Data/BALLS.mp4"); 
    mainmain(test);
}

void mainArthur(string path)
{
    Video* test = new Video(path + "/Data/BALLS.mp4");
    mainmain(test);
}

void mainmain(Video* video)
{
    //VideoOperations::UnitedColor(150, 0, 0, test);

    Thumbnail* tn = new Thumbnail(video->GetFrame(0), 50, 50, 615, 720 - 519);
    tn->Show();

    video->Display("test");

    cv::waitKey(0);
    cv::destroyAllWindows();
}

int main()
{ 
    mainYahnis("D:/Documents/Projets Dev/ReconIzer");
    //mainArthur("C:/Users/arthu/Desktop/Code/Reconize/ReconIzer");
    return 0;
}