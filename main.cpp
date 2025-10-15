#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    // 读取BGR图像
    Mat img_bgr = imread("test.png");
    if(img_bgr.empty() == true) {
        std::cerr << "Error: Could not load image" << std::endl;
        return -1;
    }
    imshow("img", img_bgr);

    // 转换到HSV颜色空间
    Mat img_hsv;
    cvtColor(img_bgr, img_hsv, COLOR_BGR2HSV);

    // 分离HSV通道
    std::vector<Mat> hsv_channels;
    split(img_hsv, hsv_channels);
    Mat img_h = hsv_channels[0];
    Mat img_s = hsv_channels[1];
    Mat img_v = hsv_channels[2];
    imshow("img_h", img_h);
    imshow("img_s", img_s);
    imshow("img_v", img_v);

    // 创建H通道掩码
    Mat mask_h, mask_s, mask_v;
    inRange(img_h, 120, 175, mask_h);
    inRange(img_s, 50, 255, mask_s);
    inRange(img_v, 50, 255, mask_v);
    imshow("mask_h", mask_h);
    imshow("mask_s", mask_s);
    imshow("mask_v", mask_s);

    // 组合H和S通道掩码
    Mat mask_h_and_s;
    bitwise_and(mask_h, mask_s, mask_h_and_s);

    // 组合H、S和V通道掩码
    Mat mask;
    bitwise_and(mask_h_and_s, mask_v, mask);
    imshow("mask", mask_s);

    // 应用掩码到原图
    Mat img_out;
    bitwise_and(img_bgr, img_bgr, img_out, mask);

    // 显示和保存结果
    imshow("img_out", img_out);
    imwrite("img_out.png", img_out);
    waitKey(0);
    
    return 0;
}
