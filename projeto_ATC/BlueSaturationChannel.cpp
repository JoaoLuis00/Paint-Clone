#include "BlueSaturationChannel.h"

void BlueSaturationChannel::apply(Bitmap& bmp)
{
	int size = bmp.imgSize();

	for (int i = 0; i < size; i++)
	{
		(bmp[i]).setb(255);
	}
}