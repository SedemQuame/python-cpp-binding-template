#pragma once
#include <string>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

std::string convertImageToGray(std::string &sourceImagePath);

std::string changeImageBrightness(std::string &sourceImagePath, int deltaBrightness);

std::string changeImageContrast(std::string &sourceImagePath, float deltaContrast);

std::string equalizeImageHistogram(std::string &sourceImagePath);

std::string homogeneousBlur(std::string &sourceImagePath, int kernelSize);

std::string gaussianBlur(std::string &sourceImagePath, int kernelSize);

// std::string convertToFloatImage(std::string &sourceImagePath);

std::string invertImage(std::string &sourceImagePath);

std::string erodeImage(std::string &sourceImagePath, int kernelSize);

std::string rotateImage(std::string &sourceImagePath, int kernelSize);
