#include "VerticalMirror.h"

void VerticalMirror::apply(Bitmap& bmp)
{
    int width = bmp.imgWidth();
    int height = bmp.imgHeight();

    vector<Pixel> temp(width * height);

    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            
            temp[(height-row-1)*width+col] = bmp[row*width+col];
        
        }
    }

    for (int i = 0; i < bmp.imgSize(); i++)
    {
        bmp[i] = temp[i];
    }
}
