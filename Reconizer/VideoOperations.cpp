#include "VideoOperations.h"

void VideoOperations::UnitedColor(int R, int G, int B, Video* video)
{
	for (int i = 0; i < video->Length(); i++)
	{
		video->GetFrame(i)->SetImage(ImageOpperations::UnitedColor(R, G, B, video->GetFrame(i)->Image()));
	}
}

void VideoOperations::TrackThumbnail(Video* video, Thumbnail* thumbnail)
{
	for (int i = 0; i < video->Length(); i++)
	{
		Frame* frame = video->GetFrame(i);

		cv::Vec3f detectedPosition = ImageOpperations::ThumbnailFrameTracker(thumbnail, frame->Image());

		cout << "Detected at : (" << detectedPosition[0] << "," << detectedPosition[1] << ")"
			<< " with a PSNR of " << detectedPosition[2] << endl;
	}
}
