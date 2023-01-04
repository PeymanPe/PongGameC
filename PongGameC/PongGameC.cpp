#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

#include <chrono>
#include <thread>


#include <conio.h>
#include<ctime>

#define KEY_LEFT 97
#define KEY_RIGHT 100

using namespace cv;
using namespace std;

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

void setupgame(int inputkey=0) {







	Mat image = Mat::zeros(330, 330, CV_8UC3);
	image.setTo(cv::Scalar(255, 255, 255));


	Rect r = Rect(10, 10, 310, 310);

	rectangle(image, r, Scalar(255, 0, 0), 10, 8, 0);

	Rect r2 = Rect(20+ inputkey, 300, 50, 10);



	rectangle(image, r2, Scalar(0, 255, 0), 10, 8, 0);
	imshow("Display Window", image);
	
	sleep_until(system_clock::now() + seconds(1));

	
	

}


int main(int argc, char* argv[])
{
	int ch;
	int incc=10;
	int i = 0;


	while (i < 10) {
		
		incc *= (-1);
		setupgame(incc);
		waitKey(100);
	
		i++;
	}
	
		switch (ch = _getch()) {
		case KEY_RIGHT:
			incc = 10;
			break;


		case KEY_LEFT:
			incc = -10;
			break;


		}
	setupgame(incc);


	
	
	return 0;
}