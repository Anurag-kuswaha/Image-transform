#include <iostream>
#include <cmath>
#include <cstdlib>

#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageTransform.h"

using uiuc::PNG;
using uiuc::HSLAPixel;
using namespace std;

/**
 * Returns an image that has been transformed to grayscale.
 *
 * The saturation of every pixel is set to 0, removing any color.
 *
 * @return The grayscale image.
 */
PNG custom(PNG image) {
 /*  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);
   if(pixel.h > 25 && pixel.h <160) pixel.h=225;
  }
} */
int test;
cout<<"colour range"<<endl;
cout<<"for red press 0"<<endl<<"for green enter 135"<<endl<<"for blue enter 225"<<endl<<"for voilet 315"<<endl<<"for yellow enetr 45"<<endl;
cin>>test;
for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);
      if(pixel.h > 25 && pixel.h <160) pixel.h=test;
  
  }
} /*
for (unsigned x = 0; x < image.width()/2; x++) {
    for (unsigned y = image.height()/2; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);
     
     pixel.s=0;
  
  }
}*/
  return image;
}/*
PNG filter(PNG image) {
  for (unsigned x = 0; x < image.width(); x++) {
  for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);
     
        pixel.h = 225;
	
     
    }
  } 
  return image;
}
PNG bright(PNG image) {
  
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);
      if(pixel.s < 0.4) pixel.s += 0.25;
      pixel.l += 0.1;
    }
  }

  return image;
}


*/

 
PNG createSpotlight(PNG image, int centerX, int centerY) {
	
 for(unsigned int x=0;x<image.width();x++){ 

    for(unsigned int y=0;y<image.height();y++){ 

        HSLAPixel & pixel = image.getPixel(x, y); 

        double distance = sqrt((x-centerX)*(x - centerX)+(y - centerY)*(y - centerY)); 

        if (distance > 160) pixel.l = 0.2 * pixel.l;

        else pixel.l = pixel.l*(1 - 0.002*distance); 

    } 

    } 
  return image;
  
}
 

/**
 * Returns a image transformed to Illini colors.
 *
 * The hue of every pixel is set to the a hue value of either orange or
 * blue, based on if the pixel's hue value is closer to orange than blue.
 *
 * @param image A PNG object which holds the image data to be modified.
 *
 * @return The illinify'd image.
**/

PNG black(PNG image) {
for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);
      if(x%2==0 || y%2==0) pixel.s=0; 
	
     
    }
  }
  return image;
}
 

/**
* Returns an immge that has been watermarked by another image.
*
* The luminance of every pixel of the second image is checked, if that
* pixel's luminance is 1 (100%), then the pixel at the same location on
* the first image has its luminance increased by 0.2.
*
* @param firstImage  The first of the two PNGs, which is the base image.
* @param secondImage The second of the two PNGs, which acts as the stencil.
*
* @return The watermarked image.
*/

PNG watermark(PNG firstImage, PNG secondImage) {
//	cout<<"width is"<<firstImage.width()<<endl<<secondImage.width()<<endl;
for (unsigned x = 0; x < secondImage.width(); x++) {
    for (unsigned y = 0; y < secondImage.height(); y++) {
      HSLAPixel & pixel = secondImage.getPixel(x, y);
      HSLAPixel & pixel_1 = firstImage.getPixel(x, y);
      if(pixel.l ==1 && pixel_1.l >= (0.2 + pixel_1.l)) pixel_1.l= 1;
      else if(pixel.l==1){
      	pixel_1.l += 0.3;
	  } 
	  pixel_1.s=0;
    }
  }
  return firstImage;
}
