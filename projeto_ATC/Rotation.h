#pragma once
#include "Filter.h"
class Rotation : public Filter
{
public:
    //construtor para definir os graus de roatação da imagem de 90 em 90
    Rotation(int rdegrees);

    void apply(Bitmap& bmp);
private:
    int degrees;
};
