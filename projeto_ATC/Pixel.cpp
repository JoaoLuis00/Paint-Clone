#include "Pixel.h"
// Initializes a Pixel with a default black color.
Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b)
	: red(r), green(g), blue(b)
{
}
// Initializes a color Pixel with the specified RGB values.
Pixel::Pixel()
	: red(0), green(0), blue(0)
{
}
uint8_t Pixel::getr(void)
{
	return red;
}
uint8_t Pixel::getg(void)
{
	return green;
}
uint8_t Pixel::getb(void)
{
	return blue;
}

void Pixel::setr(uint8_t r)
{
	this->red = r;
}

void Pixel::setg(uint8_t g)
{
	this->green = g;
}

void Pixel::setb(uint8_t b)
{
	this->blue = b;
}

ostream& operator<<(ostream& os, const Pixel& px)
{
    os << "{"
        << hex << uppercase <<(int)px.red
        << ","
        << hex << uppercase << (int)px.green
        << ","
        << hex << uppercase << (int)px.blue
        << "}";
        return os;
}
