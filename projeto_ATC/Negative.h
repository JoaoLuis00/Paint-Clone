#pragma once
#include "Filter.h"

class Negative : public Filter
{
public:

    void apply(Bitmap& bmp);

};
