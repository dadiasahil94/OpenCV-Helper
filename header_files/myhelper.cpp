#include "myhelper.h"
#include <iostream>
#include <opencv2/opencv.hpp>

namespace helperfunc {


    std::string TypeToStr(int matrix_type) {
        // Function to convert matrix type to string for better debugging
        std::string r;

        uchar depth = matrix_type & CV_MAT_DEPTH_MASK;
        uchar chans = 1 + (matrix_type >> CV_CN_SHIFT);

        switch (depth) {

        case CV_8U:
        r = "8U";
        break;
        case CV_8S:
        r = "8S";
        break;
        case CV_16U:
        r = "16U";
        break;
        case CV_16S:
        r = "16S";
        break;
        case CV_32S:
        r = "32S";
        break;
        case CV_32F:
        r = "32F";
        break;
        case CV_64F:
        r = "64F";
        break;
        default:
        r = "User";
        break;
        }

        r += "C";
        r += (chans + '0');

        return r;
    }

    ImageHeaderStruct GetImageHeader(const cv::Mat input_image) {
        // Function to find matrix headers
        ImageHeaderStruct image_data;
        image_data.num_rows = input_image.rows;
        image_data.num_cols = input_image.cols;
        image_data.num_channels = input_image.channels();
        image_data.data_type = TypeToStr(input_image.type());

        return image_data;
    }


} //End of helperfunc namespace
