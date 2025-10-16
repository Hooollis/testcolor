**OpenCV 颜色分离测试项目**


一个基于 OpenCV 和 C++ 的简单颜色分离测试项目，可以在 Ubuntu 系统下运行。该项目能够从图像中分离出特定颜色范围的对象。


**功能特性**

* 原始图像读取

* 将图像转为HSV 色系

* 将颜色分离为H、S、V单通道

* 对每个通道构建掩膜

* 对图像进行逻辑运算

* 分离结果保存功能


**环境要求**


系统要求

* Ubuntu 24.04 或更高版本


**依赖库**

* OpenCV 4.0 或更高版本

* C++11 兼容编译器


**安装步骤**

1. 安装依赖

bash

sudo apt update

sudo apt install build-essential cmake git

sudo apt install libopencv-dev


2. 克隆项目

bash

git clone https://github.com/Hooollis/testcolor.git

cd testcolor


3. 编译项目

bash

cmake .

make


**使用方法**

**基本使用**

bash

# 使用默认行颜色分离

./testcolor


**交互式控制**

程序运行后，会出现两个窗口：

* img：显示原始图像

* img_out：显示颜色分离后的图像


**代码示例**

主要的颜色分离逻辑：

cpp

    // 读取BGR图像
    Mat img_bgr = imread("test.png");
    if(img_bgr.empty()) {
        std::cerr << "Error: Could not load image" << std::endl;
        return -1;
    }
    // 转换到HSV颜色空间
    Mat img_hsv;
    cvtColor(img_bgr, img_hsv, COLOR_BGR2HSV);
    // 应用掩码到原图
    Mat img_out;
    bitwise_and(img_bgr, img_bgr, img_out, mask);
    
**项目结构**

text

testcolor /

├── CMakeLists.txt

├── main.cpp

├── test.png

└── README.md


**故障排除**

**常见问题**

1. OpenCV 未找到

o 确认 OpenCV 安装：pkg-config --modversion opencv4

o 如果使用自定义安装路径，修改 CMakeLists.txt

2. 编译错误

o 确保 GCC 版本支持 C++17

o 检查 OpenCV 版本兼容性


**调试模式**

启用调试输出：

bash

./testcolor --debug


**贡献指南**

欢迎提交 Issue 和 Pull Request！

1. Fork 本项目

2. 创建特性分支

3. 提交更改

4. 推送到分支

5. 创建 Pull Request


**许可证**

本项目采用 MIT 许可证 - 查看?LICENSE?文件了解详情。


**更新日志**

v1.0.0 (2025-10-13)

* 初始版本发布

* 支持图像颜色分离


**联系方式**

* 项目主页：https://github.com/Hooollis /testcolor

* 问题反馈：https://github.com/Hooollis /testcolor/issues


**致谢**

* 感谢 OpenCV 社区提供的优秀计算机视觉库

* 感谢所有贡献者的支持和帮助

