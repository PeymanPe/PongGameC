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

Point center(100, 100);

void centerCircle(Point* arr, int* direction) {
	Point a1(1, 1);
	Point a2(-1, 1);
	Point a3(1, -1);
	Point a4(-1, -1);
	if (*direction == 1) {
		*arr = a1;
		
	}
	else if (*direction == 2) {
		*arr = a2;
		
	}
	else if (*direction == 3) {
		*arr = a3;
		
	}
	else if (*direction == 4) {
		*arr = a4;
		
	}


}

void setupgame(int inputkey=0, int counter=0) {



	srand(time(0));

	int direction = 1;



	Mat image = Mat::zeros(330, 330, CV_8UC3);
	image.setTo(cv::Scalar(255, 255, 255));


	Rect r = Rect(10, 10, 310, 310);

	rectangle(image, r, Scalar(255, 0, 0), 10, 8, 0);

	Rect r2 = Rect(20+ inputkey, 300, 50, 10);



	rectangle(image, r2, Scalar(0, 255, 0), 10, 8, 0);


	
	
	Point adder(1, 1);
	

	if (counter == 0) {
		Point center( 100, 100);//Declaring the center point
	}
	else  {
		int cent[2] = { 100,100 };
		centerCircle(&adder, &direction);
		center = center + adder;
		
		

	}
	
	int radius = 5; //Declaring the radius
	Scalar line_Color(0, 0, 0);//Color of the circle
	int thickness = 5;//thickens of the line
	
	circle(image, center, radius, line_Color, thickness);



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
		setupgame(incc,i);
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