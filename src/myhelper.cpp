// Custom include files
#include "../include/myhelper.h"
// Regular include files
#include <iostream>
#include <opencv2/opencv.hpp>
#include<dirent.h> // For listing files in a direcory


namespace helperfunc {


    std::string ImgTypeToStr(int matrix_type) {
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
        image_data.num_rows = (unsigned int)input_image.rows;
        image_data.num_cols = (unsigned int)input_image.cols;
        image_data.num_channels = (unsigned int)input_image.channels();
        image_data.data_type = ImgTypeToStr(input_image.type());

        return image_data;
    }

    void PrintImageHeader(const ImageHeaderStruct img_headstruct){
        std::cout << "Number of rows : " << img_headstruct.num_rows  << std::endl;
        std::cout << "Number of cols : " << img_headstruct.num_cols  << std::endl;
        std::cout << "Number of channels : " << img_headstruct.num_channels  << std::endl;
        std::cout << "Data type : " << img_headstruct.data_type  << std::endl;
    }

    // template <class T>
    // std::string type_name(){
    //     // Used to find the type of any variable
    //
    //     typedef typename std::remove_reference<T>::type TR;
    //     std::unique_ptr<char, void(*)(void*)> own
    //            (
    //     #ifndef _MSC_VER
    //                     abi::__cxa_demangle(typeid(TR).name(), nullptr,
    //                                                nullptr, nullptr),
    //     #else
    //                     nullptr,
    //     #endif
    //                     std::free
    //            );
    //     std::string r = own != nullptr ? own.get() : typeid(TR).name();
    //     if (std::is_const<TR>::value)
    //         r += " const";
    //     if (std::is_volatile<TR>::value)
    //         r += " volatile";
    //     if (std::is_lvalue_reference<T>::value)
    //         r += "&";
    //     else if (std::is_rvalue_reference<T>::value)
    //         r += "&&";
    //     return r;
    // }

    void ListFilesInDir(const char dir_name[], std::vector<std::string> &file_lists){
        // Returns a vector containing files of a particular directory
        DIR *pDIR;
        struct dirent *entry;
        if( pDIR=opendir(dir_name) ){
            while(entry = readdir(pDIR)){
                // Add file to directory if its not . or ..
                if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                    file_lists.push_back(std::string(entry->d_name));
                }
            }
            closedir(pDIR);
        }
    }




} //End of helperfunc namespace
