#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main(){
	// 读入图片
	Mat img = imread("../src/img.png");
	
	// 判断是否正确读入图片
	if (img.empty()){
		cout<<"图片路径错误，没有图片被读入"<<endl;
		return 0;
	}
	
	// 保存图片
	// imwrite("another_salute.png",img);
	
	// 显示图片
	imshow("salute",img);
 	waitKey();
	destroyAllWindows();
	return 0;
}
