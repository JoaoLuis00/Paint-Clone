#include "Image.h"
#include "Pixel.h"

void Image::readImage(ifstream& bucky) {
	uint8_t red = 0;
	uint8_t green = 0;
	uint8_t blue = 0;
	for (int i = 0; i < size; i++)
	{
			bucky.read((char*)&blue, 1);
			bucky.read((char*)&green, 1);
			bucky.read((char*)&red, 1);
			//Pixel* newPixel = new Pixel(red, green, blue);
			pixels.push_back(Pixel(red,green,blue));
	}
}

bool Image::writeImage(ofstream& ofs)
{
	for (int i = 0; i < size; i++)
	{
		uint8_t red = pixels[i].getr();
		uint8_t green = pixels[i].getg();
		uint8_t blue = pixels[i].getb();

		ofs.write(reinterpret_cast<char*>(&blue), sizeof(uint8_t));
		ofs.write(reinterpret_cast<char*>(&green), sizeof(uint8_t));
		ofs.write(reinterpret_cast<char*>(&red), sizeof(uint8_t));
		
	}
	return true;
}

//Acho que esta funçao nao e precisa 
//void Image::imprimirVetor()
//{
//
//	for (int i = 0; i < size; i++)
//	{
//			cout << "Pixel[" << i << "] -> azul = " << (pixels[i]).getb() << endl;
//			cout << "Pixel[" << i << "] -> verde = " << (pixels[i]).getg() << endl;
//			cout << "Pixel[" << i << "] -> vermelho = " << (pixels[i]).getr() << endl;
//	}
//	cout << "Não existem mais Pixeis, na matriz" << endl;
//}

Pixel& Image::operator[](int i)
{
	return pixels[i];
}
void Image::setHeight(int height)
{
	this->height = height;
}
void Image::setSize(int size)
{
	this->size = size;
}
void Image::setWidth(int width)
{
    this->width = width;
}

void Image::resetpixels(int width, int height)
{
    pixels.clear();
    //pixels.resize(width*height);
}

int Image::getSize()
{
	return size;
}

int Image::getHeight()
{
	return height;
}

int Image::getWidth()
{
	return width;
}


Image::Image() 
	:size(0) , height(0), width(0), pixels(NULL)
{
}
Image::Image(int height, int width)
	: size(height*width), height(height), width(width), pixels(NULL)
{
	//inicialização do vector (vector <Pixel> & PixelMatrix)
}
