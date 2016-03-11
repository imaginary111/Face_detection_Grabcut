# Face_detection_Grabcut
To detect face in an image and then performs grabcut and other effects using OpenCv
HOW TO RUN
Compile the code by giving command
from the directory location in the terminal. Then run the code by giving command “./application”. If g++
and opencv are installed it will prompt
"Please enter the name of image to be processed: "
Enter the name of image with extension of the image. I have attached an image "harpreet.jpg", you can use this as a input image or you can use any other image.
[NOTE that that should be in same directory]. Enter eg.:
harpreet.jpg
IMPLEMENTATION
First this code will detect the faces of person/people in the image, then it will crop their faces and make equal number of new images (crop_detected*.jpg like crop_detected0.jpg , crop_detected1.jpg ...).
Then by using grab cut it will cut only body parts in newly made images and save these in equal number of new images (detected*.jpg like detected0.jpg ,detected1.jpg ...).
Then it will give some effect to each newly made image by applying computations at pixel level of images and save these as equal number of new images (result*.jpg like result0.jpg
,result1.jpg ...).
End
