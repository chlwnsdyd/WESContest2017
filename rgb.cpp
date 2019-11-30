#include<opencv\highgui.h>
#include<opencv\cv.h>
#include<stdio.h>

void main() {
	IplImage *hsvImage = 0, *grayImage;
	IplImage *srcImage = cvLoadImage("C:\\Users\\KTH\\Desktop\\test.jpg");
	int hcount;
	int wcount;
	int B1, G1, R1, B2, G2, R2;
	int index;
	int Rcount = 0;
	int Lcount = 0;
	int w = srcImage->width;
	int h = srcImage->height;

	//create image
	hsvImage = cvCreateImage(cvGetSize(srcImage), IPL_DEPTH_8U, 3);
	grayImage = cvCreateImage(cvGetSize(srcImage), IPL_DEPTH_8U, 1);    //��鿵������ �Ұ��̹Ƿ� ä���� 1�� ����


																		//����ȯ
																		//cvCvtColor(�����̹���, ����̹���, ��ȯ���)
																		//��ȯ��� : CV_<src color code>2<dst color code>
																		//color code : RGB, BGR, GRAY, HSV, YcrCb, XYZ, Lab, Luv, HLS
	cvCvtColor(srcImage, hsvImage, CV_RGB2HSV);
	cvCvtColor(srcImage, grayImage, CV_RGB2GRAY);

	for (hcount = 0; hcount < h / 2; hcount++) {
		for (wcount = 0; wcount < w / 3; wcount++) {
			index = 3 * wcount + hcount * (img->widthStep);
			B1 = (int)(img->imageData[index]);
			G1 = (int)(img->imageData[index + 1]);
			R1 = (int)(img->imageData[index + 2]);
			if ((R1=255 ) && (G1 = 255) && (B1 = 255)) {
				Lcount++;
			}
		}

	}
	for (hcount = 0; hcount < h / 2; hcount++) {
		for (wcount = w / 3 * 2; wcount < w; wcount++) {
			index = 3 * wcount + hcount * (img->widthStep);
			B2 = (int)(img->imageData[index]);
			G2 = (int)(img->imageData[index + 1]);
			R2 = (int)(img->imageData[index + 2]);
			if ((R2=255 ) && (G2 = 255) && (B2 = 255)) {
				Rcount++;
			}
		}

	}

	printf("Lcount : %d, Rcount : %d", Lcount, Rcount);



	//create window
	cvNamedWindow("RGB image", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("HSV image", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("GRAY image", CV_WINDOW_AUTOSIZE);
	//show window
	cvShowImage("RGB image", srcImage);
	cvShowImage("HSV image", hsvImage);
	cvShowImage("GRAY image", grayImage);

	cvWaitKey(0);

	//release image
	cvReleaseImage(&srcImage);
	cvReleaseImage(&hsvImage);
	cvReleaseImage(&grayImage);
}
