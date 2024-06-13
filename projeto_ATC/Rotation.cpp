#pragma once
#include "Rotation.h"
#include <vector>
#include "Pixel.h"
#define _USE_MATH_DEFINES
#include "math.h"


void Rotation::apply(Bitmap& bmp)
{
	int height = bmp.imgHeight();
	int width = bmp.imgWidth();

	vector<Pixel> temp_pData(width*height);
	
	double radians = ((degrees) * M_PI) / 180;

	float sin_r = (float)sin(radians);
	float cos_r = (float)cos(radians);

	//descobrir as coordenadas do centro da imagem

	double cx = 0.5 * ((double)width - 1);
	double cy = 0.5 * ((double)height - 1);


	double aux1;
	double aux2;

	int xx;
	int yy;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//calcular a posição do pixel em relação ao centro
			aux1 = x - cx;
			aux2 = y - cy;

			xx = (int)(aux1 * cos_r - aux2 * sin_r + cx);
			yy = (int)(aux1 * sin_r + aux2 * cos_r + cy);

			if ((xx >= 0) && (xx < width) && (yy >= 0) && (yy < height))
			{
				//passa de 2 dimensoes para array unidimensional
				temp_pData[(y * width + x)] = bmp[(yy * width + xx)];
			}
		}
	}
	
    //atualizar o bmp com os novos valores de temp
	for (int i = 0; i < (bmp.imgSize()); i++)
	{
		bmp[i] = temp_pData[i];
	}


}
