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

cv::Vec3f ImageOpperations::ThumbnailFrameTrackerWholeFrame(Thumbnail* wantedObject, const cv::Mat frameFromVideo, float precision)
{
    int step = 1 / precision;
    cv::Vec3f result = cv::Vec3f(0.0,0.0,0.0);

    int verticalSizeThumbnail = wantedObject->Image().rows;
    int horizontalSizeThumbnail = wantedObject->Image().cols;

    for (int x = 0; x < frameFromVideo.cols - horizontalSizeThumbnail; x+=step) {
        for (int y = 0; y < frameFromVideo.rows - verticalSizeThumbnail; y+=step) {

            float currentPSNR = PSNR(wantedObject->Image(), frameFromVideo,x,y);

            if (result[2] < currentPSNR) {
                result[0] = x; 
                result[1] = y;
                result[2] = currentPSNR;
            }
        }
    }

    return result;
}

vector<int> ImageOpperations::ProcessWidnows(Frame* frame, Thumbnail* thumbnail)
{
    vector<int> windows;
    for (int i = 0; i < frame->Image().cols; i++) {

    }
}

cv::Vec3f ImageOpperations::ThumbnailFrameTrackerWindows(Thumbnail* wantedObject, const cv::Mat frameFromVideo, float precision)
{
    int step = 1 / precision;
    cv::Vec3f result = cv::Vec3f(0.0, 0.0, 0.0);

    int verticalSizeThumbnail = wantedObject->Image().rows;
    int horizontalSizeThumbnail = wantedObject->Image().cols;

    for (int x = 0; x < frameFromVideo.cols - horizontalSizeThumbnail; x += step) {
        for (int y = 0; y < frameFromVideo.rows - verticalSizeThumbnail; y += step) {

            float currentPSNR = PSNR(wantedObject->Image(), frameFromVideo, x, y);

            if (result[2] < currentPSNR) {
                result[0] = x;
                result[1] = y;
                result[2] = currentPSNR;
            }
        }
    }

    return result;
}

float ImageOpperations::PSNR(const cv::Mat thumbnail, const cv::Mat frame, int x, int y)
{
    double mse = 0.0;
    int height = thumbnail.rows;
    int width = thumbnail.cols;

    /*for (int i = 0; i < height * width * 3; i++)
    {
        int diff = thumbnail.data[i] - frame.data[i + (y + (x * height) * 3)];
        mse += diff * diff;
    }*/

    for (int i = 0; i < height; ++i) 
    {
        for (int j = 0; j < width; ++j) 
        {
            for (int c = 0; c < 3; ++c) 
            {
                int diff = thumbnail.at<cv::Vec3b>(j, i)[c] - frame.at<cv::Vec3b>(j + y, i + x)[c];
                mse += diff * diff;
            }
        }
    }

    mse /= (3 * height * width);

    if (mse <= 1e-10) {
        return 100.0; // Return a high value (PSNR is infinity) for identical images
    }
    else {
        double psnr = 10.0 * log10((255 * 255) / mse); // Compute PSNR
        return psnr;
    }
    /*cv::Mat diff;
    cv::absdiff(image1, image2, diff); // Compute absolute difference between images

    cv::Mat diffChannels[3];
    cv::split(diff, diffChannels); // Split the diff image into separate channels

    double mse = 0.0;
    for (int i = 0; i < 3; ++i) {
        cv::multiply(diffChannels[i], diffChannels[i], diffChannels[i]); // Square the elements of each channel
        mse += cv::sum(diffChannels[i])[0]; // Accumulate the squared differences for each channel
    }

    mse /= (image1.rows * image1.cols * image1.channels()); // Compute mean squared error

    if (mse <= 1e-10) {
        return 100.0; // Return a high value (PSNR is infinity) for identical images
    }
    else {
        double psnr = 10.0 * log10((255 * 255) / mse); // Compute PSNR
        return psnr;
    }*/
}


