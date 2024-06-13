#include "Filter.h"
#include "RedSelectionChannel.h"

void RedSelectionChannel::apply(Bitmap& bmp)
{
	int size = bmp.imgSize();
	uint8_t red_value=0;

	for (int i = 0; i<size ; i++)
	{
		red_value = (bmp[i]).getr();

		(bmp[i]).setg(red_value);
		(bmp[i]).setb(red_value);
	}
}
