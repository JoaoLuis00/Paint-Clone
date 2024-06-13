#ifndef FILTER_H
#define FILTER_H
#include "Bitmap.h"

class Filter{
public:

	virtual void apply(Bitmap& bmp)=0;

};
#endif
