#include "GrayScale.h"

void GrayScale::apply(Bitmap& bmp)
{
	int size = bmp.imgSize();
	uint8_t red, green, blue;
	int new_red, new_green, new_blue;
	for (int i = 0; i < size; i++)
	{
		red = bmp[i].getr();
		blue = bmp[i].getb();
		green = bmp[i].getg();

		new_red = new_green = new_blue = (red + green + blue) / 3;

		(bmp[i]).setr((uint8_t)new_red);
		(bmp[i]).setg((uint8_t)new_green);
		(bmp[i]).setb((uint8_t)new_blue);
	}
}
