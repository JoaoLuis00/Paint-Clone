#include "GreenSaturationChannel.h"

void GreenSaturationChannel::apply(Bitmap& bmp)
{
	int size = bmp.imgSize();

	for (int i = 0; i < size; i++)
	{
		(bmp[i]).setg(255);
	}
}