#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    // 读取 BMP 格式文件
    cv::Mat bmp_image = cv::imread("input.bmp", cv::IMREAD_COLOR);
    if (bmp_image.empty()) {
        std::cerr << "Failed to open input BMP file." << std::endl;
        return 1;
    }

    // 检查图像是否成功读取
    if (bmp_image.empty()) {
        std::cerr << "Failed to read image." << std::endl;
        return 1;
    }

    // 写入 JPEG 格式文件
    std::vector<int> compression_params;
    compression_params.push_back(cv::IMWRITE_JPEG_QUALITY);
    compression_params.push_back(95); // JPEG 质量参数，范围从0到100，100为最高质量

    if (!cv::imwrite("output.jpg", bmp_image, compression_params)) {
        std::cerr << "Failed to write JPEG file." << std::endl;
        return 1;
    }

    std::cout << "BMP to JPEG conversion complete." << std::endl;
    return 0;
}
