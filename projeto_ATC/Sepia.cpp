#include "Sepia.h"

void Sepia::apply(Bitmap& bmp)
{
	int size = bmp.imgSize();
	uint8_t red, green, blue;
	double new_red, new_green, new_blue;
	for (int i = 0; i < size; i++)
	{
		//Le os valores das componentes a de cada pixel
		red = bmp[i].getr();
		green = bmp[i].getg();
		blue = bmp[i].getb();

		//Calcula os novos valores das componentes 
		new_red = (0.393 * red + 0.769 * green + 0.189 * blue);
		new_green = (0.349 * red + 0.686 * green + 0.168 * blue);
		new_blue = (0.272 * red + 0.534 * green + 0.131 * blue);

		(bmp[i]).setr((unsigned char)new_red);
		(bmp[i]).setg((unsigned char)new_green);
		(bmp[i]).setb((unsigned char)new_blue);
	}
}
