
#include "Video.h"


Video::Video(const string path)
{
	this->path = path;
	this->cvVideo = new cv::VideoCapture();
	this->Open();
	this->SetupData();
	this->Close();
}

void Video::SetupData()
{
	this->fps = this->cvVideo->get(cv::CAP_PROP_FPS);
	this->nbFrames = this->cvVideo->get(cv::CAP_PROP_FRAME_COUNT);
	SetupFrames();
}

void Video::SetupFrames()
{
	frames = new Frame * [nbFrames];

	this->Open();

	cv::Mat arr; int i = 0;
	while (this->cvVideo->read(arr))
	{
		Frame* frame = new Frame("", arr.clone());
		frames[i] = frame; i++;
	}

	this->Close();
}

void Video::Display(string windowName)
{
	this->Open();

	for (int i = 0; i < nbFrames; i++)
	{
		frames[i]->Show();

		char key = cv::waitKey(1000.0 / this->fps);
		if (key == 27) {
			// If the 'Esc' key is pressed, break the loop and stop the video
			break;
		}
	}

	this->Close();
}

void Video::Open()
{
	this->cvVideo->open(this->path);
}

void Video::Close()
{
	this->cvVideo->release();
}
