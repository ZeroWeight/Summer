#include <opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include<iostream>
#define scalar 100
//int main() {
//	cv::Mat Img = cv::imread("C:/Users/Zero Weight/Desktop/Startrails/359.jpg");
//	cv::Mat images(Img.size(), CV_8U, cv::Scalar(0));
//	cv::cvtColor(Img, images, cv::COLOR_BGR2GRAY);
//	for (int i = 0;i < images.rows;i++)
//		for (int j = 0;j < images.cols;j++)
//			if (*(images.data + images.step*i + j) < scalar) *(images.data + images.step*i + j) = 0;
//			else *(images.data + images.step*i + j) = 255;
//	cv::imshow("", images);
//	cv::waitKey();
//	//
//	const int channels[1] = { 0 };
//	const int histSize[1] = { 256 };
//	float hranges[2] = { scalar,255 };
//	const float* ranges[1] = { hranges };
//	cv::Mat hist;
//	cv::calcHist(&images, 1, channels, cv::Mat(), hist, 1, histSize, ranges);
//	//
//	double maxVal = 0;
//	double minVal = 0;
//	cv::minMaxLoc(hist, &minVal, &maxVal, 0, 0);
//	int Size = hist.rows;
//	cv::Mat histImg(Size, Size, CV_8U, cv::Scalar(255));
//	int hpt = 0.9*Size;
//	for (int h = 0;h<Size;h++)
//	{
//		float binVal = hist.at<float>(h);
//		int intensity =(binVal*hpt / maxVal);
//		line(histImg, cv::Point(h, Size), cv::Point(h, Size - intensity), cv::Scalar::all(0));
//		std::cout << intensity << '\t' << std::endl;
//	}
//	cv::imshow("test", histImg);
//	cv::waitKey();
//}