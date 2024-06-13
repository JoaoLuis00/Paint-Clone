#include "GreenSelectionChannel.h"

void GreenSelectionChannel::apply(Bitmap& bmp)
{
	int size = bmp.imgSize();
	uint8_t green_value = 0;

	for (int i = 0; i < size; i++)
	{
		green_value = (bmp[i]).getg();

		(bmp[i]).setr(green_value);
		(bmp[i]).setb(green_value);
	}
}
