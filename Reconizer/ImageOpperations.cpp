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

vector<int> ImageOpperations::ProcessWindows(Frame* frame, Thumbnail* thumbnail)
{
    vector<int> windows;
    for (int i = 0; i < frame->Image().cols; i++) {
        if (thumbnail->GetGraph()->Compare(frame->GetGraph(), i))
        {
            windows.push_back(i);
        }
    }

    cout << windows.size() << " windows compatible over " << frame->Image().cols << endl;
    return windows;
}

cv::Vec3f ImageOpperations::ThumbnailFrameTrackerWindows(Thumbnail* wantedObject, Frame* frame, float precision)
{
    int step = 1 / precision;
    int verticalSizeThumbnail = wantedObject->Image().rows;
    cv::Vec3f result = cv::Vec3f(0.0, 0.0, 0.0);

    vector<int> windows = ProcessWindows(frame,wantedObject);

    for (int x : windows)
    {
        for (int y = 0; y < frame->Image().rows - verticalSizeThumbnail; y += step) {

            float currentPSNR = PSNR(wantedObject->Image(), frame->Image(), x, y);

            if (result[2] < currentPSNR) {
                result[0] = x;
                result[1] = y;
                result[2] = currentPSNR;
            }
        }
    }

    return result;
}

cv::Vec3f ImageOpperations::ToHSL(cv::Vec3f rgb)
{
    // Convert RGB values to the range [0, 1]
    double red = static_cast<double>(rgb[2]) / 255.0;
    double green = static_cast<double>(rgb[1]) / 255.0;
    double blue = static_cast<double>(rgb[0]) / 255.0;

    // Find the maximum and minimum RGB components
    double maxComponent = std::max({ red, green, blue });
    double minComponent = std::min({ red, green, blue });

    // Calculate lightness (L)
    double l = (maxComponent + minComponent) / 2.0;
    double h, s;

    if (maxComponent == minComponent) {
        // Grayscale color (no saturation)
        h = 0.0;
        s = 0.0;
    }
    else {
        // Calculate saturation (S)
        double d = maxComponent - minComponent;
        s = l > 0.5 ? d / (2.0 - maxComponent - minComponent) : d / (maxComponent + minComponent);

        // Calculate hue (H)
        if (maxComponent == red) {
            h = (green - blue) / d + (green < blue ? 6.0 : 0.0);
        }
        else if (maxComponent == green) {
            h = (blue - red) / d + 2.0;
        }
        else { // maxComponent == blue
            h = (red - green) / d + 4.0;
        }
        h *= 60.0; // Convert to degrees
    }

    return cv::Vec3f(h, s, l);
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
        return 1000.0; // Return a high value (PSNR is infinity) for identical images
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


