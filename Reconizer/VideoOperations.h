#pragma once
#include <iostream>
#include "Video.h"
#include "ImageOpperations.h"

using namespace std;

class VideoOperations
{
public:
	static void UnitedColor(int R, int G, int B, Video* video);

	static void TrackThumbnail(Video* video, Thumbnail* thumbnail);
};

