/**
 * @file main.cpp
 * A simple C++ program that manipulates an image.
 *
 * @Anurag Kushwaha
**/

#include "ImageTransform.h"
#include "uiuc/PNG.h"

int main() {
  uiuc::PNG png, png2, result;

  png.readFromFile("input.png");
  result = custom(png);
  result.writeToFile("out-custom.png");
  /*
  png.readFromFile("alma.png");
  result = filter(png);
  result.writeToFile("out-filter.png");
  
   png.readFromFile("alma.png");
  result = bright(png);
  result.writeToFile("out-bright.png");
  */
  result = createSpotlight(png, 450, 150);
  result.writeToFile("out-spotlight.png");

  result = black(png);
  result.writeToFile("out-black.png");

  png2.readFromFile("overlay.png");
  result = watermark(png, png2);
  result.writeToFile("out-watermark.png");
  
  return 0;
}
