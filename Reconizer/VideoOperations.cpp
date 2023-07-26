#include "VideoOperations.h"

void VideoOperations::UnitedColor(int R, int G, int B, Video* video)
{
	for (int i = 0; i < video->Length(); i++)
	{
		video->Frame(i)->SetImage(ImageOpperations::UnitedColor(R, G, B, video->Frame(i)->Image()));
	}
}