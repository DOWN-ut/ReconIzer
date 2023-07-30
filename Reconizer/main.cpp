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

    //Thumbnail* tn = new Thumbnail(video->GetFrame(0)->Image(), 50, 50, 615, 720 - 519);
    Thumbnail* tn = new Thumbnail(video->GetFrame(0)->Image(), 215, 215, 0, 720 - 215);
    cout << "Loaded thumbnail from video" << endl;
    tn->Show();

    //tn->GetGraph()->Display(); return;

    cout << "Video pre-processing" << endl;
    video->ProcessFrames(true);

    cout << "Starting tracking" << endl;
    //VideoOperations::TrackThumbnailWholeFrame(video, tn,0.1f,0.25f);
    VideoOperations::TrackThumbnailWindow(video, tn,0.1f,1.0f);

    video->Display("test");
    video->Save(path + "/Data/NewTracking.mp4");

    cv::waitKey(0);
    cv::destroyAllWindows();
}

void mainYahnis(string path)
{
    Video* test = new Video(path + "/Data/BALLITO.mp4"); 
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