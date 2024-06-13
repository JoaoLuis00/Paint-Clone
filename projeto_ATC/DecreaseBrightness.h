#pragma once
#include "Filter.h"

class DecreaseBrightness : public Filter
{
public:

    void apply(Bitmap& bmp);

};