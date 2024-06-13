#include "Threshold.h"

void Threshold::apply(Bitmap& bmp)
{
	int size = bmp.imgSize();
	uint8_t red, green, blue;
	int median;
	for (int i = 0; i < size; i++)
	{
		red = bmp[i].getr();
		blue = bmp[i].getb();
		green = bmp[i].getg();

		median = (red + green + blue) / 3;

		if (median > 127)
		{
			bmp[i].setr(255);
			bmp[i].setg(255);
			bmp[i].setb(255);
		}

		else
		{
			bmp[i].setr(0);
			bmp[i].setg(0);
			bmp[i].setb(0);
		}
	}
}
