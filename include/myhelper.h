/**
 @author Sahil Dadia (dadiasahil94@yahoo.in)
 @date 12th August 2016
 @brief File containing helper functions for OpenCV
 */

#ifndef __MYHELPERFUNC_H__
#define __MYHELPERFUNC_H__

#include <iostream>
#include <opencv2/opencv.hpp> // Required for paramters of functions
#include <dirent.h>


/**
@namespace helperfunc
*/
namespace helperfunc {

    /**
    @brief Get data-type of OpenCV matrix object

    @details The output of cv::Mat.type() is an integer which indicates the data type of the matrix,\n
    such as (0,1,2,3,4,5,6), which corresponds to (8UC1 ... 32FC1).\n
    It is not intuitive. This function converts it to string.Hence making it easier to read.

    @details Useage :
    @code
    helperfunc::ImgTypeToStr(image_matrix.type()) >> input is an integer
            "8UC1" >> Output
    @endcode

    @param[in] matrix_type (type = int) Output of cv::Mat.type()

    @return String of the type
    */
    std::string ImgTypeToStr(int matrix_type);

    /**
    @struct ImageHeaderStruct

    @brief Data struct to store OpenCV matrix object headers

    @details Used in conjunction with GetImageHeader(). So while using GetImageHeader(), you
    need to declare ImageHeaderStruct variable as follows
    @code
    helperfunc::ImageHeaderStruct my_struct = helperfunc::GetImageHeader(image)
    @endcode
    It stores number of rows, columns, channels and the data type of image
    @see GetImageHeader()
    */
    struct ImageHeaderStruct {
        unsigned int num_rows=0, num_cols=0, num_channels=0;
        std::string data_type="None";
    };

    /**
    @brief Get image para for OpenCV matrix object such as rows, cols etc.

    @details Used in conjunction with a struct ImageHeaderStruct, which contains number of rows, columns, channels and data type of the image.\n
    So while using GetImageHeader(), you need to declare ImageHeaderStruct variable as follow,
    @code
    helperfunc::ImageHeaderStruct my_img_header = helperfunc::GetImageHeader(image)
    @endcode

    @param[in] input_image (type = cv::Mat) OpenCV matrix object

    @return image_data (type = ImageHeaderStruct) A structure containing the header information

    @see ImageHeaderStruct
    */
    ImageHeaderStruct GetImageHeader(const cv::Mat input_image);

    /**
    @brief Print the details of imageheader

    @param[in]  Imageheader struct object

    @see ImageHeaderStruct
    */
    void PrintImageHeader(const ImageHeaderStruct img_headstruct);

    /**
    @brief Returns a vector containing files of a particular directory

    @param[in]  dir_name (type = char[]) Directory to search
    @param[out] file_lists (type = std::vector<std::string>)  List containing all file names

    @return -
    */
    void ListFilesInDir(const char dir_name[], std::vector<std::string> &file_lists);

    /**
    @brief Prints the elements of vector

    @param[in]  vec (type = std::vector<any_type>) Vector for iterations
    */
    template <class t>
    void PrintVectorElements(const std::vector<t> vec){
        // Note : `auto` keyword is of c++11 standard. So compile your program using c++11
        for( auto i = vec.begin(); i != vec.end(); i++ ){
            std::cout << *i << std::endl;
        }
    }

} // End of helperfunc namespace

#endif
