#include "RedSaturationChannel.h"

void RedSaturationChannel::apply(Bitmap& bmp)
{
	int size = bmp.imgSize();

	for (int i = 0; i < size; i++)
	{
		(bmp[i]).setr(255);
	}

}

