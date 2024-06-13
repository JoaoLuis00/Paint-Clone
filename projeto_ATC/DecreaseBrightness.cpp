#include "DecreaseBrightness.h"

void DecreaseBrightness::apply(Bitmap& bmp)
{
	int size = bmp.imgSize();
	uint8_t red, green, blue;
	for (int i = 0; i < size; i++)
	{
		red = bmp[i].getr() - 15;
		blue = bmp[i].getb() - 15;
		green = bmp[i].getg() - 15;

		if (red < 0)
			red = 0;
		if (green < 0)
			green = 0;
		if (blue < 0)
			blue = 0;

		bmp[i].setr(red);
		bmp[i].setg(green);
		bmp[i].setb(blue);
	}
}
