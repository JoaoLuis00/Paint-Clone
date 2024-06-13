#include "IncreaseBrightness.h"

void IncreaseBrightness::apply(Bitmap& bmp)
{
	int size = bmp.imgSize();
	uint8_t red, green, blue;
	for (int i = 0; i < size; i++)
	{
		red = bmp[i].getr() + 15;
		blue = bmp[i].getb() + 15;
		green = bmp[i].getg() + 15;

		if (red > 255)
			red = 255;
		if (green > 255)
			green = 255;
		if (blue > 255)
			blue = 255;

		bmp[i].setr(red);
		bmp[i].setg(green);
		bmp[i].setb(blue);
	}
}
