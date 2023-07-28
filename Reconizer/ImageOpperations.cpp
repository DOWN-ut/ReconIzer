#include "ImageOpperations.h"

cv::Mat ImageOpperations::UnitedColor(int R, int G, int B, const cv::Mat inputImage)
{
    if (inputImage.empty()) 
    {
        std::cout << "Impossible de charger l'image." << std::endl;
        return inputImage;
    }

    cv::Mat output = inputImage.clone();

    for (int y = 0; y < output.rows; y++) 
    {
        for (int x = 0; x < output.cols; x++)
        {
            output.at<cv::Vec3b>(y, x) = cv::Vec3b(B, G, R);
        }
    }


    return output;
}

cv::Vec2b ImageOpperations::ThumbnailFrameTracker(Thumbnail wantedObject, const cv::Mat frameFromVideo)
{
    
}

float ImageOpperations::PSNR(const cv::Mat image1, const cv::Mat image2)
{
    return 0.0f;
}
