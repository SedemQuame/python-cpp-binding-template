#include <pybind11/pybind11.h>
#include <iostream>
#include <string>

#include "ImageManipulation.h"

using namespace cv;
using namespace std;

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(main, m)
{
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: main

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

    m.def("convertImageToGray", &convertImageToGray, R"pbdoc(
        Convert an image from RGB to Grayscale.
    )pbdoc");

    m.def("changeImageBrightness", &changeImageBrightness, R"pbdoc(
        Modify the brightness of an image.
    )pbdoc");

    m.def("changeImageContrast", &changeImageContrast, R"pbdoc(
        Modify the contrast of an image.
    )pbdoc");

    m.def("equalizeImageHistogram", &equalizeImageHistogram, R"pbdoc(
        Modify the contrast of an image.
    )pbdoc");

    m.def("homogeneousBlur", &homogeneousBlur, R"pbdoc(
        Add blur effect to the image.
    )pbdoc");

    m.def("gaussianBlur", &gaussianBlur, R"pbdoc(
        Add blur effect to the image.
    )pbdoc");

    m.def("invertImage", &invertImage, R"pbdoc(
        Modify the brightness of an image.
    )pbdoc");

    m.def("erodeImage", &erodeImage, R"pbdoc(
        Erode the image.
    )pbdoc");

    m.def("rotateImage", &rotateImage, R"pbdoc(
        Rotate an image.
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
