#include "ImageManipulation.h"
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

std::string convertImageToGray(std::string &sourceImagePath)
{
    Mat sourceImage = imread(sourceImagePath);
    std::string fullPath = "";
    std::string outputFileName = "grayscaleImage.jpg";
    bool result = false;
    try
    {
        // Check if the sourceImage was loaded successfully
        if (sourceImage.empty())
        {
            std::cout << "Error: Could not load sourceImage." << std::endl;
            return fullPath;
        }

        // Convert the sourceImage to grayscale
        Mat grayscaledImage;
        cvtColor(sourceImage, grayscaledImage, COLOR_BGR2GRAY);
        result = imwrite(outputFileName, grayscaledImage);

        if (result)
        {
            fullPath = cv::samples::findFile(outputFileName);
            std::cout << "Saved image to: " << fullPath << std::endl;
        }
    }
    catch (const cv::Exception &e)
    {
        std::cout << "Exception converting image to PNG format : % s\n"
                  << e.what() << '\n';
    }
    return fullPath;
}

std::string changeImageBrightness(std::string &sourceImagePath, int deltaBrightness)
{
    Mat sourceImage = imread(sourceImagePath);
    std::string fullPath = "";
    std::string outputFileName = "brightenedImage.jpg";
    bool result = false;
    try
    {
        // Convert the brightness for the sourceImage.
        Mat imageWithAlteredBrightness;
        sourceImage.convertTo(imageWithAlteredBrightness, -1, 1, deltaBrightness);
        result = imwrite(outputFileName, imageWithAlteredBrightness);

        if (result)
        {
            fullPath = cv::samples::findFile(outputFileName);
            std::cout << "Saved image to: " << fullPath << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    return fullPath;
}

std::string changeImageContrast(std::string &sourceImagePath, float deltaContrast)
{
    Mat sourceImage = imread(sourceImagePath);
    std::string fullPath = "";
    std::string outputFileName = "contrastedImage.jpg";
    bool result = false;
    try
    {
        // Convert the contrast of an sourceImage.
        Mat imageWithAlteredContrast;
        sourceImage.convertTo(imageWithAlteredContrast, -1, deltaContrast, 0);
        result = imwrite(outputFileName, imageWithAlteredContrast);

        if (result)
        {
            fullPath = cv::samples::findFile(outputFileName);
            std::cout << "Saved image to: " << fullPath << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    return fullPath;
}

std::string equalizeImageHistogram(std::string &sourceImagePath)
{
    Mat sourceImage = imread(sourceImagePath);
    std::string fullPath = "";
    std::string outputFileName = "equalizedHistImage.jpg";
    bool result = false;
    try
    {
        // Equalizes the histogram of a color sourceImage.
        Mat equalizedImage;
        Mat grayscaledImage;
        cvtColor(sourceImage, grayscaledImage, COLOR_BGR2GRAY);
        equalizeHist(grayscaledImage, equalizedImage);

        result = imwrite(outputFileName, equalizedImage);

        if (result)
        {
            fullPath = cv::samples::findFile(outputFileName);
            std::cout << "Saved image to: " << fullPath << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    return fullPath;
}

std::string homogeneousBlur(std::string &sourceImagePath, int kernelSize)
{
    Mat sourceImage = imread(sourceImagePath);
    std::string fullPath = "";
    std::string outputFileName = "homogeneousBlur.jpg";
    bool result = false;
    try
    {
        // Filter using the homogeneous blur
        Mat blurredImage;
        blur(sourceImage, blurredImage, Size(kernelSize, kernelSize));
        result = imwrite(outputFileName, blurredImage);

        if (result)
        {
            fullPath = cv::samples::findFile(outputFileName);
            std::cout << "Saved image to: " << fullPath << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    return fullPath;
}

std::string gaussianBlur(std::string &sourceImagePath, int kernelSize)
{
    Mat sourceImage = imread(sourceImagePath);
    std::string fullPath = "";
    std::string outputFileName = "gaussianBlur.jpg";
    bool result = false;
    try
    {
        // Filter using the homogeneous blur
        Mat blurredImage;
        GaussianBlur(sourceImage, blurredImage, Size(kernelSize, kernelSize), 0);
        result = imwrite(outputFileName, blurredImage);

        if (result)
        {
            fullPath = cv::samples::findFile(outputFileName);
            std::cout << "Saved image to: " << fullPath << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    return fullPath;
}

std::string invertImage(std::string &sourceImagePath)
{
    Mat sourceImage = imread(sourceImagePath);
    std::string fullPath = "";
    std::string outputFileName = "invertedImage.jpg";
    bool result = false;
    try
    {
        if (sourceImage.empty())
        {
            std::cout << "Error: Input sourceImage is empty." << std::endl;
            return fullPath;
        }

        // Ensure that the input matrix is of type CV_32F or CV_64F
        if (sourceImage.type() != CV_32F && sourceImage.type() != CV_64F)
        {
            std::cout << "Error: Input sourceImage must have data type CV_32F or CV_64F." << std::endl;
            // Convert the source sourceImage to CV_32F or CV_64F depending on your needs
            sourceImage.convertTo(sourceImage, CV_32F);
        }
        std::cout << sourceImage.type() << std::endl;

        Mat invertedImage;
        invert(sourceImage, invertedImage, DECOMP_LU);
        result = imwrite(outputFileName, invertedImage);

        if (result)
        {
            fullPath = cv::samples::findFile(outputFileName);
            std::cout << "Saved image to: " << fullPath << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    return fullPath;
}

std::string erodeImage(std::string &sourceImagePath, int kernelSize)
{
    Mat sourceImage = imread(sourceImagePath);
    std::string fullPath = "";
    std::string outputFileName = "erodedImage.jpg";
    bool result = false;
    try
    {
        // Filter using the homogeneous blur
        Mat erodeImage;
        erode(sourceImage, erodeImage, getStructuringElement(MORPH_RECT, Size(kernelSize, kernelSize)));
        result = imwrite(outputFileName, erodeImage);

        if (result)
        {
            fullPath = cv::samples::findFile(outputFileName);
            std::cout << "Saved image to: " << fullPath << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    return fullPath;
}

Mat convertToFloatImage(Mat sourceImage)
{
    // Check if the input sourceImage is empty
    if (sourceImage.empty())
    {
        std::cout << "Error: Input sourceImage is empty." << std::endl;
        // Return an empty matrix as an error indicator
        return Mat();
    }

    // Create a matrix to store the converted sourceImage
    Mat floatImage;

    // Convert the source sourceImage to CV_32F or CV_64F depending on your needs
    sourceImage.convertTo(floatImage, CV_32F); // Change to CV_64F for double precision

    return floatImage;
}

std::string rotateImage(std::string &sourceImagePath, int iAngle)
{
    // Load an sourceImage from file
    Mat sourceImage = imread(sourceImagePath);
    std::string fullPath;
    std::string outputFileName = "rotatedImage.jpg";
    bool result = false;
    try
    {
        int imageHeight = sourceImage.rows / 2;
        int imageWidth = sourceImage.cols / 2;
        Mat matRotation = getRotationMatrix2D(Point(imageWidth, imageHeight), (iAngle - 180), 1);

        Mat rotatedImage;
        warpAffine(sourceImage, rotatedImage, matRotation, sourceImage.size());

        result = imwrite(outputFileName, rotatedImage);
        if (result)
        {
            fullPath = cv::samples::findFile(outputFileName);
            std::cout << "Saved image to: " << fullPath << std::endl;
        }
    }
    catch (const cv::Exception &e)
    {
        std::cout << "Exception converting image to PNG format : % s\n"
                  << e.what() << '\n';
    }

    return fullPath;
}