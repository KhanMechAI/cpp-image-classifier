#include <iostream>
#include <opencv2/opencv.hpp>

using std::cout, std::cin, std::endl;

int getCaptureDeviceID(){

    char user_input;
    int deviceId;

    cout << "Please enter a device id as an integer, or 'q' to quit" << endl;
    cin >> user_input;

    if (isdigit(user_input)){
        deviceId = (int)user_input;
    } else {
        deviceId = -1;
    };


    return deviceId;
};

cv::VideoCapture getCaptureDevice(){

    bool validCaptureDevice = false;

    cv::VideoCapture cap;

    while (!validCaptureDevice) {
        int deviceId = getCaptureDeviceID();

        if (deviceId < 0) {
            cout << "Exiting...";
            exit(-1);
        };

        cap.open(deviceId);

        if (!cap.isOpened()){
            cout << "no stream detected" << endl;
        } else {
            validCaptureDevice = true;
        }
    }
    return cap;
};

int main() {
    cv::Mat frame;
    cv::namedWindow("Video Player");

    cv::VideoCapture cap = getCaptureDevice();

    cout << "Start grabbing" << endl
         << "Press any key to terminate" << endl;

    while (true) {
        cap.read(frame);
        if (frame.empty()) {
            break;
        }

        cv::imshow("Video Player", frame);
        char c = (char) cv::waitKey(25);

        if (c == 27){ //If 'Esc' is entered break the loop//
            break;
        }


    }

    cap.release();//Releasing the buffer memory//
    return 0;
}
