#include "VideoOperations.h"

void VideoOperations::UnitedColor(int R, int G, int B, Video* video)
{
	for (int i = 0; i < video->Length(); i++)
	{
		video->GetFrame(i)->SetImage(ImageOpperations::UnitedColor(R, G, B, video->GetFrame(i)->Image()));
	}
}

void VideoOperations::TrackThumbnail(Video* video, Thumbnail* thumbnail, float framePrecision, float imagePrecision)
{
	int step = 1 / framePrecision;

	vector<cv::Vec3f> positions;

	cv::Vec3f detectedPosition;
	for (int i = 0; i < video->Length(); i++)
	{
		Frame* frame = video->GetFrame(i);
		
		if (i % step == 0)
		{
			//detectedPosition = ImageOpperations::ThumbnailFrameTrackerWholeFrame(thumbnail, frame->Image(), imagePrecision);
			detectedPosition = ImageOpperations::ThumbnailFrameTrackerWindows(thumbnail, frame->Image(), imagePrecision);
			positions.push_back(detectedPosition);

			cout << "Detected at : (" << detectedPosition[0] << "," << detectedPosition[1] << ")"
				<< " with a PSNR of " << detectedPosition[2] << endl;
		}
	}

	int lastX, lastY, posId = 0;

	for (int i = 0; i < video->Length(); i++)
	{
		int x, y; float ratio = (i % step) / (float)step;
		if (i % step == 0)
		{
			lastX = positions[posId][0]; lastY = positions[posId][1];
			x = lastX; y = lastY; posId++;
		}
		else
		{
			x = lastX + ((positions[posId][0] - lastX) * ratio);
			y = lastY + ((positions[posId][1] - lastY) * ratio);
		}

		x = min(max(x, 0), video->GetFrame(i)->Image().cols);
		y = min(max(y, 0), video->GetFrame(i)->Image().rows);

		DrawRect(video->GetFrame(i), x,y, thumbnail->Image().cols, thumbnail->Image().rows);
	}
}

void VideoOperations::DrawRect(Frame* frame, int x, int y, int w, int h)
{
	for (int dx = x; dx < x + w && dx < frame->Image().cols; dx++)
	{
		frame->Image().at<cv::Vec3b>(y, dx) = cv::Vec3b(255, 0, 0);
	}
	for (int dx = x; dx < x + w && dx < frame->Image().cols; dx++)
	{
		frame->Image().at<cv::Vec3b>(min(y+h, frame->Image().rows-1), dx) = cv::Vec3b(255, 0, 0);
	}
	for (int dy = y; dy < y + h && dy < frame->Image().rows; dy++)
	{
		frame->Image().at<cv::Vec3b>(dy, x) = cv::Vec3b(255, 0, 0);
	}
	for (int dy = y; dy < y + h && dy < frame->Image().rows; dy++)
	{
		frame->Image().at<cv::Vec3b>(dy, min(x+w, frame->Image().cols-1)) = cv::Vec3b(255, 0, 0);
	}
}
