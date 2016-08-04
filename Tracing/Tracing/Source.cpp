#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\video\tracking.hpp>
#include <opencv2\video\video.hpp>
#include<iostream>
void paint(cv::Point2i point, cv::Mat & mat);
int main() {
	cv::Mat frame;
	cv::VideoCapture video("origin.avi");
	cv::Mat module= cv::imread("module.jpg");
	cv::Mat mod_hsv;
	cv::cvtColor(module, mod_hsv, CV_BGR2HSV);
	const int channels[1] = { 0 };
	const int channel[3] = { 0,1,2 };
	const int histSize[1] = { 256 };
	float hranges[2] = { 0,360 };
	const float* ranges[1] = { hranges };
	cv::Mat hist;
	cv::Mat result;
	cv::calcHist(&mod_hsv, 1, channels, cv::Mat(), hist, 1, histSize, ranges);
	cv::Size size(video.get(CV_CAP_PROP_FRAME_WIDTH), video.get(CV_CAP_PROP_FRAME_HEIGHT));
	int fps = video.get(CV_CAP_PROP_FPS);
	int iterator = 0;
	int total = video.get(CV_CAP_PROP_FRAME_COUNT);
	cv::VideoWriter output("result.avi", CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
	while (video.isOpened()) {
		video >> frame;
		if (frame.cols == 0) break;
		cv::calcBackProject(&frame,1,channel,hist,result,ranges);
		cv::RotatedRect  res = cv::CamShift(result, cv::Rect(cv::Point2i(0, 0), cv::Point2i(frame.cols, frame.rows)),
			cv::TermCriteria(cv::TermCriteria::COUNT|cv::TermCriteria::MAX_ITER, 1, 1));
		paint(res.center, frame);
		output << frame;
		std::cout << iterator << std::endl;
		iterator++;
	}
	
}
void paint(cv::Point2i point, cv::Mat & mat)
{
	//x w y h
	if (point.x <= 0 || point.y <= 0)return;
	int radius = 30;
	int outer = 30;
	int inner = 15;
	int xstart = ((point.x - radius) > 0 ? (point.x - radius) : 0);
	int ystart = ((point.y - radius) > 0 ? (point.y - radius) : 0);
	int xend = ((point.x + radius) < mat.cols ? (point.x + radius) : mat.cols);
	int yend = ((point.y + radius) < mat.rows ? (point.y + radius) : mat.rows);
	for (int i = xstart;i < xend;i++) {
		for (int j = ystart;j < yend;j++) {
			//change the color
			if ((point.x - i)*(point.x - i) + (point.y - j)*(point.y - j)>(inner*inner)) {
				if ((point.x - i)*(point.x - i) + (point.y - j)*(point.y - j) < (outer*outer)) {
					mat.ptr(j)[i * 3] = 251;//B
					mat.ptr(j)[i * 3 + 1] = 230;//G
					mat.ptr(j)[i * 3 + 2] = 172;//R
				}
			}
		}
	}
}