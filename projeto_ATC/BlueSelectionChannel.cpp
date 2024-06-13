#include "BlueSelectionChannel.h"


void BlueSelectionChannel::apply(Bitmap& bmp)
{
	int size = bmp.imgSize();
	uint8_t blue_value = 0;

	for (int i = 0; i < size; i++)
	{
		blue_value = (bmp[i]).getb();

		(bmp[i]).setr(blue_value);
		(bmp[i]).setg(blue_value);
	}
}