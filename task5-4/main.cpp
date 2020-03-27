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
		cv::Mat dx;
		cv::Mat dy;
		bool rSucess = cap.read(frame);
		if (!rSucess)
		{
			std::cout << "���ܴ���Ƶ�ж�ȡ֡" << std::endl;
			break;
		}
		else
		{
			//��Ե��ȡ����
			Sobel(frame, dx, CV_16SC1,1,0,3);
			Sobel(frame, dy, CV_16SC1, 1, 0, 3);
			cv::imshow("frame ", frame);
			cv::imshow("dx ", dx);
			cv::imshow("dy ", dy);
		}
		waitKey(30);

	}
	return 0;
}