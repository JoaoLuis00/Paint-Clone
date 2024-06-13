#pragma once
#include "Filter.h"

class RedSaturationChannel : public Filter
{
public:

    void apply(Bitmap& bmp);

};
