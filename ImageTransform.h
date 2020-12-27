#pragma once

#include "uiuc/PNG.h"
using namespace uiuc;

PNG custom(PNG image);  
/*PNG filter(PNG image);
PNG bright(PNG image); */
PNG createSpotlight(PNG image, int centerX, int centerY); 
PNG black(PNG image);
PNG watermark(PNG firstImage, PNG secondImage);
