#include "HorizontalMirror.h"

void HorizontalMirror::apply(Bitmap& bmp)

{
    int width = bmp.imgWidth();
    int height = bmp.imgHeight();

    vector<Pixel> temp(width * height);

    //logica ---- trabalhar em 2d num array 1d (0,1)-> width * row=0 + col=1      
    
    //(10,10)-> width * row=10 + col=10 

    //---> pos para width=2 : 2*10+10=30 logo o valor de (10,10) do array 2d vai estar na pos 30 do array 1d


     for (int row = 0; row < height; ++row) {
          for (int col = 0; col < width ; ++col) {

              temp[row * width + col] = bmp[row * width + (width - 1 - col)];
          
          }
     }

     for (int i = 0; i < bmp.imgSize(); i++)
     {
         bmp[i] = temp[i];
     }
}
