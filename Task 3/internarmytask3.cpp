#include <iostream>
#include "opencv2/opencv.hpp"


using namespace cv;
using namespace std;

// Function to apply grayscale filter
void applyGrayscale(Mat& image) {
    cvtColor(image, image, COLOR_BGR2GRAY);
}

// Function to apply blur filter
void applyBlur(Mat& image) {
    blur(image, image, Size(5, 5));
}

// Function to apply sharpen filter
void applySharpen(Mat& image) {
    Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(image, image, image.depth(), kernel);
}

// Function to display the menu
int showMenu() {
    cout << "***** Image Processing Menu *****" << endl;
    cout << "1. Grayscale" << endl;
    cout << "2. Blur" << endl;
    cout << "3. Sharpen" << endl;
    cout << "4. Save Modified Image" << endl;
    cout << "5. Exit" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    Mat image = imread("input_image.jpg"); // Replace "input_image.jpg" with the actual image file

    if (image.empty()) {
        cerr << "Error: Unable to load the image." << endl;
        return -1;
    }

    int choice;
    do {
        choice = showMenu();

        switch (choice) {
            case 1:
                applyGrayscale(image);
                break;

            case 2:
                applyBlur(image);
                break;

            case 3:
                applySharpen(image);
                break;

            case 4:
                imwrite("modified_image.jpg", image); // Save the modified image as "modified_image.jpg"
                cout << "Modified image saved successfully." << endl;
                break;

            case 5:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }

        if (choice != 5) {
            imshow("Modified Image", image);
            waitKey(0);
            destroyAllWindows();
        }

    } while (choice != 5);

    return 0;
}
