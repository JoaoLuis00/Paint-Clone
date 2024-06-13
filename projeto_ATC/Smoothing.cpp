#include "Smoothing.h"
#include <cmath>
void Smoothing::apply(Bitmap& bmp)
{

    int height = bmp.imgHeight();
    int width = bmp.imgWidth();

    //novos valores das componentes
    float nred;
    float ngreen;
    float nblue;
    float mask = (1.0/9.0);

    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            nred = ngreen = nblue = 0;

            //nao filtra nas bordas da imagem
            //resolver talvez (?)

            if (row == 0 || row == (height - 1) || col == (width - 1) || col == 0)
                continue;
            else
            {
                //pixel topo esquerda//
                nred += bmp[(row * width + col) - width - 1].getr() * mask;
                ngreen += bmp[(row * width + col) - width - 1].getg() * mask;
                nblue += bmp[(row * width + col) - width - 1].getb() * mask;

                //pixel topo meio//
                nred += bmp[(row * width + col) - (width)].getr() * mask;
                ngreen += bmp[(row * width + col) - (width)].getg() * mask;
                nblue += bmp[(row * width + col) - (width)].getb() * mask;

                //pixel topo direita//
                nred += bmp[(row * width + col) - (width)+1].getr() * mask;
                ngreen += bmp[(row * width + col) - (width)+1].getg() * mask;
                nblue += bmp[(row * width + col) - (width)+1].getb() * mask;

                //pixels« meio esquerda//
                nred += bmp[(row * width + col) - 1].getr() * mask;
                ngreen += bmp[(row * width + col) -1].getg() * mask;
                nblue += bmp[(row * width + col) -1].getb() * mask;

                //pixel meio//
                nred += bmp[(row * width + col)].getr() * mask;
                ngreen += bmp[(row * width + col)].getg() * mask;
                nblue += bmp[(row * width + col)].getb() * mask;

                //pixel direita//
                nred += bmp[(row * width + col) + 1].getr() * mask;
                ngreen += bmp[(row * width + col) + 1].getg() * mask;
                nblue += bmp[(row * width + col) + 1].getb() * mask;

                //pixel baixo esquerda//
                nred += bmp[(row * width + col) + width-1].getr() * mask;
                ngreen += bmp[(row * width + col) + width-1].getg() * mask;
                nblue += bmp[(row * width + col) + width-1].getb() * mask;

                //pixel baixo maio//
                nred += bmp[(row * width + col) +width].getr() * mask;
                ngreen += bmp[(row * width + col) + width].getg() * mask;
                nblue += bmp[(row * width + col) + width].getb() * mask;

                //pixel baixo direita//
                nred += bmp[(row * width + col) + width + 1].getr() * mask;
                ngreen += bmp[(row * width + col) + width + 1].getg() * mask;
                nblue += bmp[(row * width + col) + width + 1].getb() * mask;
                
                // atualizar os valores das componentes após os calculos//
                bmp[row * width + col].setr((uint8_t)(nred));
                bmp[row * width + col].setg((uint8_t)(ngreen));
                bmp[row * width + col].setb((uint8_t)(nblue));


            }//else
        
        }// for_col
    }//for_row

}
