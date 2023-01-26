# Shape Separation and Isolation using OpenCV in C++

This project is a C++ implementation that uses OpenCV library to separate and isolate individual shapes in a grayscale image and creating another image for each different shape found. The algorithm used in this project is called "column-wise traversal" which uses a stack to process the pixels.

The algorithm works as follows:
1. Create a blank image of the same size as the input image.
2. Start from the first pixel and add its location to the stack.
3. As long as the stack is not empty, remove a pixel location and put 255 in place of that pixel location in the new blank image.
4. As soon as you remove a pixel location from the stack, check all its neighbours that are 255.
5. Add those locations to the stack if they have not been processed yet.
6. If the pixel has already been processed, it will not be added to the stack again.
7. When the stack is empty, the new blank image will have the object separated from the rest of the objects in the input image.

## Requirements
- OpenCV (3.4 or later)
- Visual Studio (2015 or later)
- Windows

## Usage
1. Clone the repository
2. Rename the input image to "img1.jpg" or change the name in the code at line number 15
3. Open the project in Visual Studio
4. Add OpenCV include and library paths to the project properties
5. Build and run the project
6. The resulting images of each shape will be saved in the same directory with the prefix "image-" and the shape number as suffix, for example "image-1.jpg"

## Note
- The program currently only works with grayscale images.
- Feel free to modify the code to suit your needs.
