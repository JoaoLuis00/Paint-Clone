#include "Negative.h"

void Negative::apply(Bitmap& bmp)
{
	int size = bmp.imgSize();
	uint8_t red, green, blue;
	for (int i = 0; i < size; i++)
	{
		red = bmp[i].getr();
		blue = bmp[i].getb();
		green = bmp[i].getg();
		
		(bmp[i]).setr(255 - red);
		(bmp[i]).setg(255 - green);
		(bmp[i]).setb(255 - blue);
	}
}
