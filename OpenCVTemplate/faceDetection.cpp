/*
 *
*/
#include <opencv2\objdetect.hpp>
#include "opencv2\highgui/highgui.hpp"
#include "opencv2\imgproc/imgproc.hpp"
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

// functii header
void detectAndDisplay(Mat frame);

// variabile globale
// Trebuie copiat fisiereul de haarcascade de la opencv/data/haarscascades in folderul targetat
string face_cascade_name = "g:/haarcascade_frontalface_alt.xml";
CascadeClassifier face_cascade;
string window_name = "Capture - Face detection";
int filenumber; // numarul fisierului de salvat
string filename;

// Functia main
int main(void)
{
	VideoCapture capture(0);
	//capture.open("http://192.168.0.102:8080/stream.wmv");


	if (!capture.isOpened())  // verificam daca stream-ul webcam-ului s-a deschis
		return -1;

	// incarcarea fisierului cascade
	if (!face_cascade.load(face_cascade_name))
	{
		printf("--(!)Eroare la incarcare\n");
		return (-1);
	};

	// citirea stream-ului video
	Mat frame;

	for (;;)
	{
		capture >> frame;

		// aplicarea clasificatorului la frame
		if (!frame.empty())
		{
			detectAndDisplay(frame);
		}
		else
		{
			printf(" --(!) Nici-un cadru capturat. -- Break!");
			break;
		}

		int c = waitKey(10);

		if (27 == char(c))
		{
			break;
		}
	}

	return 0;
}

// functia detectAndDisplay
void detectAndDisplay(Mat frame)
{
	std::vector<Rect> faces;
	Mat frame_gray;
	Mat crop;
	Mat res;
	Mat gray;
	string text;
	stringstream sstm;

	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	// detectarea faciala
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

	// setarea regiunilor de interes
	cv::Rect roi_b;
	cv::Rect roi_c;

	size_t ic = 0;   // indexul elementului curent
	int ac = 0;		   // aria elementului curent

	size_t ib = 0;   // indexul elementului cel mai mare
	int ab = 0;      // aria celui mai mare element

	for (ic = 0; ic < faces.size(); ic++) // iterarea prin fetele detectate

	{
		roi_c.x = faces[ic].x;
		roi_c.y = faces[ic].y;
		roi_c.width = (faces[ic].width);
		roi_c.height = (faces[ic].height);

		ac = roi_c.width * roi_c.height; // aflarea ariei fetei detectate

		roi_b.x = faces[ib].x;
		roi_b.y = faces[ib].y;
		roi_b.width = (faces[ib].width);
		roi_b.height = (faces[ib].height);

		ab = roi_b.width * roi_b.height; // aflarea ariei celui mai mare element

		if (ac > ab)
		{
			ib = ic;
			roi_b.x = faces[ib].x;
			roi_b.y = faces[ib].y;
			roi_b.width = (faces[ib].width);
			roi_b.height = (faces[ib].height);
		}

		crop = frame(roi_b);
		resize(crop, res, Size(128, 128), 0, 0, INTER_LINEAR); // necesar pentru salvarea ulterioara a imaginilor
		cvtColor(crop, gray, CV_BGR2GRAY); // convertirea imaginilor in Grayscale pentru a reduce spatiul ocupat

		// formarea numelui de fisier
		filename = "";
		stringstream ssfn;
		ssfn << filenumber << ".png";
		filename = ssfn.str();
		filenumber++;

		imwrite(filename, gray);

		Point pt1(faces[ic].x, faces[ic].y); // afisarea stream-ului  live de la camera
		Point pt2((faces[ic].x + faces[ic].height), (faces[ic].y + faces[ic].width));
		rectangle(frame, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);
	}

	// afisarea imaginii
	sstm << "Marimea de crop: " << roi_b.width << "x" << roi_b.height << " Nume fisier: " << filename;
	text = sstm.str();

	putText(frame, text, cvPoint(30, 30), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0, 0, 255), 1, CV_AA);
	imshow("original", frame);

	if (!crop.empty())
	{
		imshow("Detectata", crop);
	}
	else
		destroyWindow("Detectata");
}