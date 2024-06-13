#include "Sharpness.h"

void Sharpness::apply(Bitmap& bmp)
{

    int height = bmp.imgHeight();
    int width = bmp.imgWidth();

    //novos valors das componentes
    float nred;
    float ngreen;
    float nblue;
    //valores do kernel para aplicação do filtro;
    float neighbour_mask = -1.0/9.0;
    float pixel_mask = 8.0/9.0;
    float corner_mask = 0;

    nred = ngreen = nblue = 0;

    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            nred = ngreen = nblue = 0;
            //nao filtra nas bordas da imagem
            //resolver talvez (?)
            int pos_atual = row * width + col;

            if (row == 0 || row == (height - 1) || col == (width - 1) || col == 0)
                continue;
            else
            {
                //pixel topo esquerda
                nred += bmp[(pos_atual) - width - 1].getr() * corner_mask;
                ngreen += bmp[(pos_atual) - width - 1].getg() * corner_mask;
                nblue += bmp[(pos_atual) - width - 1].getb() * corner_mask;

                //pixel topo meio
                nred += bmp[(pos_atual) - (width)].getr() * neighbour_mask;
                ngreen += bmp[(pos_atual) - (width)].getg() * neighbour_mask;
                nblue += bmp[(pos_atual) - (width)].getb() * neighbour_mask;

                //pixel topo direita
                nred += bmp[(pos_atual) - (width)+1].getr() * corner_mask;
                ngreen += bmp[(pos_atual) - (width)+1].getg() * corner_mask;
                nblue += bmp[(pos_atual) - (width)+1].getb() * corner_mask;

                //pixels« meio esquerda
                nred += bmp[(pos_atual) - 1].getr() * neighbour_mask;
                ngreen += bmp[(pos_atual) - 1].getg() * neighbour_mask;
                nblue += bmp[(pos_atual) - 1].getb() * neighbour_mask;

                //pixel meio
                nred += bmp[(pos_atual)].getr() * pixel_mask;
                ngreen += bmp[(pos_atual)].getg() * pixel_mask;
                nblue += bmp[(pos_atual)].getb() * pixel_mask;

                //pixel direita
                nred += bmp[(pos_atual) + 1].getr() * neighbour_mask;
                ngreen += bmp[(pos_atual) + 1].getg() * neighbour_mask;
                nblue += bmp[(pos_atual) + 1].getb() * neighbour_mask;

                //pixel baixo esquerda
                nred += bmp[(pos_atual) + width - 1].getr() * corner_mask;
                ngreen += bmp[(pos_atual) + width - 1].getg() * corner_mask;
                nblue += bmp[(pos_atual) + width - 1].getb() * corner_mask;

                //pixel baixo maio
                nred += bmp[(pos_atual) + width].getr() * neighbour_mask;
                ngreen += bmp[(pos_atual) + width].getg() * neighbour_mask;
                nblue += bmp[(pos_atual) + width].getb() * neighbour_mask;

                //pixel baixo direita
                nred += bmp[(pos_atual) + width + 1].getr() * corner_mask;
                ngreen += bmp[(pos_atual) + width + 1].getg() * corner_mask;
                nblue += bmp[(pos_atual) + width + 1].getb() * corner_mask;

                // atualizar os valores das componentes após os calculos
                bmp[pos_atual].setr((uint8_t)(nred));
                bmp[pos_atual].setg((uint8_t)(ngreen));
                bmp[pos_atual].setb((uint8_t)(nblue));


            }//else

        }// for_col
    }//for_row
}
