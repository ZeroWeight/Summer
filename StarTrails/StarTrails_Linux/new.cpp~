//#include <opencv2\core\core.hpp>
//#include<opencv2\highgui\highgui.hpp>
//#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2/opencv.hpp>
#include<iostream>
#include<stdio.h>
#define scalar 100
#define all 453
int main() {
	int i = 0;
	char s[20];
	//print
	sprintf(s, "Startrails/%03d.jpg", i);
	cv::Mat output = cv::imread(s);
	cv::Mat temp;
	cv::Mat gray;
	cv::Mat OutGray;
	i++;
	while (i < all) {
		std::cout<<i<<std::endl;
		cv::cvtColor(output, OutGray, CV_BGR2GRAY);
		sprintf(s, "Startrails/%03d.jpg", i);
		i++;
		temp = cv::imread(s);
		cv::cvtColor(temp, gray, CV_BGR2GRAY);
		for (int r = 0;r < temp.rows;r++)
			for (int c = 0;c < temp.cols;c++)
				if (*(gray.data + gray.step*r + c) > *(OutGray.data + OutGray.step*r + c))
					output.at<cv::Vec3b>(r, c) = temp.at<cv::Vec3b>(r, c);
	}
	sprintf(s, "Startrails/%03d.jpg", i);
	cv::imwrite(s, output);
	return 0;
}
