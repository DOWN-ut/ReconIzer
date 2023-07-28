#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "Video.h"
#include "Frame.h"
#include "Thumbnail.h"
#include "VideoOperations.h"

using namespace cv;

void mainmain(Video* video, string path)
{
    //VideoOperations::UnitedColor(150, 0, 0, test);

    cout << "Loaded video" << endl;

    Thumbnail* tn = new Thumbnail(video->GetFrame(0)->Image(), 50, 50, 615, 720 - 519);
    cout << "Loaded thumbnail from video" << endl;
    tn->Show();

    cout << "Starting tracking" << endl;
    VideoOperations::TrackThumbnail(video, tn,0.1f,0.25f);

    video->Display("test");
    video->Save(path + "/Data/FirstTracking.mp4");

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void mainYahnis(string path)
{
    Video* test = new Video(path + "/Data/BALLS.mp4"); 
    mainmain(test, path);
}

void mainArthur(string path)
{
    Video* test = new Video(path + "/Data/BALLS.mp4");
    mainmain(test, path);
}

int main()
{ 
    mainYahnis("D:/Documents/Projets Dev/ReconIzer");
    //mainArthur("C:/Users/arthu/Desktop/Code/Reconize/ReconIzer");
    return 0;
}