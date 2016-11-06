/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    VideoCapture cap("G:/chrome downloads may 2016/2016-06-03 14.49.33.869.mp4"); // open the video file for reading

    if ( !cap.isOpened() )  // if not success, exit program
    {
         cout << "Cannot open the video file" << endl;
         return -1;
    }

    //cap.set(CV_CAP_PROP_POS_MSEC, 300); //start the video at 300ms

    double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video

     cout << "Frame per seconds : " << fps << endl;

    namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

    while(1)
    {
        Mat frame;

        bool bSuccess = cap.read(frame); // read a new frame from video

         if (!bSuccess) //if not success, break loop
        {
                        cout << "Cannot read the frame from video file" << endl;
                       break;
        }

        imshow("MyVideo", frame); //show the frame in "MyVideo" window

        if(waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
       {
                cout << "esc key is pressed by user" << endl; 
                break; 
       }
    }

    return 0;

}
*/

//
// #include "opencv2/objdetect/objdetect.hpp"
// #include "opencv2/highgui/highgui.hpp"
// #include "opencv2/imgproc/imgproc.hpp"
//
// #include <iostream>
// #include <stdio.h>
//
// using namespace std;
// using namespace cv;
//
// 
//
// /** @function main */
// int main( int argc, const char** argv )
// {
//	 VideoCapture cap;
//	 cap.open("rtp://192.168.0.102:8080/");
//
//	 if ( !cap.isOpened() )  // if not success, exit program
//    {
//         cout << "Cannot open the video file" << endl;
//         return -1;
//    }
//
//	 while(1)
//    {
//        Mat frame;
//		cout<<"got here";
//        bool bSuccess = cap.read(frame); // read a new frame from video
//
//         if (!bSuccess) //if not success, break loop
//        {
//                        cout << "Cannot read the frame from video file" << endl;
//                       break;
//        }
//
//        imshow("MyVideo", frame); //show the frame in "MyVideo" window
//
//        if(waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
//       {
//                cout << "esc key is pressed by user" << endl; 
//                break; 
//       }
//    }
//
//    return 0;
//
//}
//





//
//#include <opencv2/opencv.hpp>
// 
//using namespace cv;
// 
//int main (int argc, const char * argv[])
//{
//    VideoCapture cap(0);
//	//cap.open("C:/Users/Sorin/Desktop/video conversions/b.avi");
//    cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);
//    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);
// 
//    if (!cap.isOpened())
//        return -1;
// 
//    Mat img;
//	Mat frame_gray;
//    namedWindow("opencv", CV_WINDOW_AUTOSIZE);
//    HOGDescriptor hog;
//    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
// 
//    while (true)
//	{
//		cvtColor( img, frame_gray, CV_BGR2GRAY );
//	}
//    return 0;
//}
//
//void detectAndDisplay( Mat frame )
//{
//  std::vector<Rect> faces;
//  Mat frame_gray;
//
//  cvtColor( frame, frame_gray, CV_BGR2GRAY );
//  equalizeHist( frame_gray, frame_gray );
//
//  //-- Detect faces
//  face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );
//
//  for( size_t i = 0; i < faces.size(); i++ )
//  {
//    Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
//    ellipse( frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
//
//    Mat faceROI = frame_gray( faces[i] );
//    std::vector<Rect> eyes;
//
//    //-- In each face, detect eyes
//    eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );
//
//    for( size_t j = 0; j < eyes.size(); j++ )
//     {
//       Point center( faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5 );
//       int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
//       circle( frame, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
//     }
//  }
//  //-- Show what you got
//  imshow( window_name, frame );
// }
//

 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//#include <opencv/cv.h>
//#include <opencv/highgui.h>

//using namespace cv;

//int main(int argc, char** argv)
//{
//    VideoCapture cap(0);
//    if(!cap.isOpened()) return -1;

//    Mat edges, corners;
//    namedWindow("Faces",1);
//    for(;;)
//    {
//        Mat frame;
//        cap >> frame;
////        cvtColor(frame, edges, CV_BGR2GRAY);
////        cvtColor(frame, corners, CV_BGR2GRAY);
////        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
////        Canny(edges, edges, 0, 30, 3);
////        cornerHarris(corners, corners, 1, 5, 0.01);
////        imshow("corners", corners);
////        imshow("edges", edges);

//        /* detect faces */
//        CvSeq *faces = cvHaarDetectObjects(
//            frame,            /* the source image */
//            cascade_f,      /* the face classifier */
//            storage,        /* memory buffer, created with cvMemStorage */
//            1.1, 3, 0,      /* special parameters, tune for your app */
//            cvSize(40, 40)  /* minimum detection scale */
//        );

//        /* return if not found */
//        if (faces->total == 0) return;

//        if(waitKey(30) >= 0) break;
//    }
//    return 0;
//}
