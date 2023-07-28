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

cv::Vec2b ImageOpperations::ThumbnailFrameTracker(Thumbnail* wantedObject, const cv::Mat frameFromVideo)
{
    float PSNR = 0;
    int verticalSizeThumbnail = wantedObject->Image().rows;
    int horizontalSizeThumbnail = wantedObject->Image().cols;
    Thumbnail currentZoneChecked = new Thumbnail();

    for (int x = 0; x < frameFromVideo.cols - horizontalSizeThumbnail; x++) {
        for (int y = 0; y < frameFromVideo.rows - horizontalSizeThumbnail; y++) {
            
        }
    }
}

float ImageOpperations::PSNR(const cv::Mat image1, const cv::Mat image2)
{
    cv::Mat diff;
    cv::absdiff(image1, image2, diff);
    diff.convertTo(diff, image1.type());
    diff = diff.mul(diff);

    double mse = cv::sum(diff)[0] / (image1.rows * image2.cols * image1.channels()); // Compute mean squared error

    if (mse <= 1e-10) {
        return 100.0; // Return a high value (PSNR is infinity) for identical images
    }
    else {
        double psnr = 10.0 * log10((255 * 255) / mse); // Compute PSNR
        return psnr;
    }
}


