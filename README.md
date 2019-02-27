# ImageProcessingViewer


> Simple Image Proceesing Viewer. There are various functions for image processing.

![7](https://user-images.githubusercontent.com/26502774/53494405-06581800-3ae1-11e9-9d91-a3c6ca3824d2.PNG)
![8](https://user-images.githubusercontent.com/26502774/53494414-0bb56280-3ae1-11e9-997e-d63bc17d8880.PNG)



## Functions

You can do various things by importing an image file.  
You can image scaling, image rotation, and you can get a histogram. You can also apply four filters to the image.  

You can add two kinds of noise to the image.
Noise can be eliminated by applying Mean filter or Order-statistics filter.  
Also, The PSNR of the original image and the reconstructed image result can be obtained.


## Implementation
* Interpolation
  1. Bilinear interpolation
  2. Bicubic interpolation
* Histogram Equalization
* Histogram Matching
* Filter
  1. Average Filter
  2. Gaussian Filter
  3. Smooth Filter
  4. Sharpen Filter
* Noise
  1. Gaussian Noise
  2. Salt & Pepper Noise
* Noise Filtering
  1. Mean Filter
  2. Order-statistics Filter
  3. Contraharmonic Filter
  4. Adaptive median Filter
* Get PSNR
  


## Requirement
* Visual Studio 2015
* MFC
* opencv 3.1.0

