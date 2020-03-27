#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
//��������ͷ
int main()
{
	VideoCapture cap;          //ʵ����һ��videocapture�࣬����Ϊcap
	cap.open(0);              //�򿪱����ĵ�һ������ͷ
	if (!cap.isOpened())     //isOpened()�����Ƶ�Ƿ�����������������1
	{
		std::cout << "���ɴ���Ƶ�ļ�" << std::endl;
		return -1;
	}
	double fps = cap.get(CAP_PROP_FPS);//ͨ��get()����ͬ�������Ի����Ƶ��fps
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		cv::Mat frame;
		cv::Mat frame1;
		cv::Mat dx;
		cv::Mat dy;
		cv::Mat abs_dx;
		cv::Mat abs_dy;
		bool rSucess = cap.read(frame);
		if (!rSucess)
		{
			std::cout << "���ܴ���Ƶ�ж�ȡ֡" << std::endl;
			break;
		}
		else
		{
			cvtColor(frame, frame1, CV_RGB2GRAY);
			//��Ե��ȡ����
			Sobel(frame1, dx, CV_16SC1,1,0,3);
			convertScaleAbs(dx, abs_dx);
			Sobel(frame1, dy, CV_16SC1, 1, 0, 3);
			convertScaleAbs(dy, abs_dy);
			cv::imshow("frame ", frame);
			cv::imshow("frame ", frame1);
			cv::imshow("dx ", abs_dx);
			cv::imshow("dy ", abs_dy);
		}
		waitKey(30);

	}
	return 0;
}
