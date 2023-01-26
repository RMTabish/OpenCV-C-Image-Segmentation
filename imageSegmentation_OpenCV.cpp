#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>
#include<opencv2/core.hpp>

using namespace cv;
using namespace std;





class node {
public:
	long int data;
	node* next;

	node() {
		data = 0;
		next = NULL;
	}
	node(long int x) {
		data = x;
		next = NULL;

	}

};

//stack
class stack {

public:
	node* head;

	stack() {
		head = NULL;
	}

	void push(int x) {
		node* niya = new node(x);

		if (head == NULL) {
			head = niya;

		}
		else {
			node* temp = new node;
			temp = head;
			head = niya;
			head->next = temp;
		}
	}

	void pop() {
		if (head == NULL) {
			return;

		}

		else {
			node* temp = new node;
			temp = head;
			head = head->next;
			delete temp;


		}
	}



	long int get_head() {
		if (head == NULL) {
			return -1;

		}
		else {
			return head->data;

		}
	}

	bool is_empty() {
		if (head == NULL) {
			return true;

		}
		else
			return false;

	}
};

int main() {

	int no_img = 1;

	//	Mat IMG;
	Mat DST;
	Mat IMG = imread("Img1.png", IMREAD_GRAYSCALE);
	IMG.convertTo(DST, CV_32F);

	//creating second image 
	Mat IMG2;
	IMG.convertTo(IMG2, CV_32F);




	for (int i = 0; i < IMG.rows; i++) {
		for (int j = 0; j < IMG.cols; j++) {
			IMG2.at<float>(i, j) = 0;
		}
	}


	float** image = new float* [DST.rows];
	for (int i = 0; i < DST.rows; i++) {
		image[i] = new float[DST.cols];
	}
	//create checkers array 
	float** check = new float* [DST.rows];
	for (int i = 0; i < DST.rows; i++) {
		check[i] = new float[DST.cols];
	}


	for (int i = 0; i < IMG.rows; i++) {
		for (int j = 0; j < IMG.cols; j++) {
			check[i][j] = 0;
		}
	}




	//convert image to 2d array
	for (int a = 0; a < DST.rows; ++a)
	{
		for (int b = 0; b < DST.cols; ++b)
			image[a][b] = DST.at<float>(a, b);
	}

	bool k = false;
	int a, b;
	for (a = 0; a < DST.cols; ++a)
	{
		for (b = 0; b < DST.rows; ++b) {

			if (image[b][a] != 0 && check[b][a] != 1) {



				stack imi;
				int Z = b * DST.cols + a;
				imi.push(Z);
				check[b][a] = 1;

				while (!imi.is_empty()) {

					long int top = imi.get_head();
					imi.pop();

					int x = top / DST.cols;
					int y = top - (x * DST.cols);
					IMG2.at<float>(x, y) = 255;

					//-1-neighbour

					if (image[x + 1][y + 1] != 0) {

						int in = (x + 1) * DST.cols + (y + 1);

						if (check[x + 1][y + 1] == 0) {
							//push cordinate only if it is not already in the stack

							imi.push(in);
							check[x + 1][y + 1] = 1;
						}
					}
					//2-neighbour
					if (image[x][y + 1] != 0) {

						int in = (x)* DST.cols + (y + 1);

						if (check[x][y + 1] == 0) {
							//push cordinate only if it is not already in the stack

							imi.push(in);
							check[x][y + 1] = 1;
						}
					}
					if (image[x + 1][y] != 0) {

						int in = (x + 1) * DST.cols + (y);

						if (check[x + 1][y] == 0) {
							//push cordinate only if it is not already in the stack

							imi.push(in);
							check[x + 1][y] = 1;
						}
					}

					if (image[x - 1][y - 1] != 0) {

						int in = (x - 1) * DST.cols + (y - 1);

						if (check[x - 1][y - 1] == 0) {
							//push cordinate only if it is not already in the stack

							imi.push(in);
							check[x - 1][y - 1] = 1;
						}
					}

					if (image[x][y - 1] != 0) {

						int in = (x)* DST.cols + (y - 1);

						if (check[x][y - 1] == 0) {
							//push cordinate only if it is not already in the stack

							imi.push(in);
							check[x][y - 1] = 1;
						}
					}
					if (image[x - 1][y] != 0) {

						int in = (x - 1) * DST.cols + (y);

						if (check[x - 1][y] == 0) {
							//push cordinate only if it is not already in the stack

							imi.push(in);
							check[x - 1][y] = 1;
						}
					}
					if (image[x + 1][y - 1] != 0) {

						int in = (x + 1) * DST.cols + (y - 1);

						if (check[x + 1][y - 1] == 0) {
							//push cordinate only if it is not already in the stack

							imi.push(in);
							check[x + 1][y - 1] = 1;
						}
					}
					if (image[x - 1][y + 1] != 0) {

						int in = (x - 1) * DST.cols + (y + 1);

						if (check[x - 1][y + 1] == 0) {
							//push cordinate only if it is not already in the stack

							imi.push(in);
							check[x - 1][y + 1] = 1;
						}
					}


				}


				imshow("Window", IMG2);

				//saving image 
				imwrite("image" + to_string(no_img) + ".jpg", IMG2);
				no_img++;
				waitKey(0);

				for (int i = 0; i < IMG.rows; i++) {
					for (int j = 0; j < IMG.cols; j++) {
						IMG2.at<float>(i, j) = 0;
					}
				}

				k = true;
				break;

			}
		}

	}



	//checking if value already in stack
	//node* traverse = new node;



	//till stack is not empty 










}