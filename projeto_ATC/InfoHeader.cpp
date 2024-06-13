#include "InfoHeader.h"
//Alterado
InfoHeader::InfoHeader()
	: sizea(0), width(0), height(0), planes(0), bits(0), compression(0), imagesize(0), xresolution(0), yresolution(0), ncolours(0), importantcolours(0)
{
}
bool InfoHeader::readInfoHeader(ifstream& ifs) {

	ifs.read((char*)&sizea, sizeof(uint32_t));										/* Recolher a variável Size do Image Header (4 bytes) */
	ifs.read((char*)&width, sizeof(uint32_t));										/* Recolher a variável Width do Image Header (4 bytes) */
	ifs.read((char*)&height, sizeof(uint32_t));										/* Recolher a variável Height do Image Header (4 bytes) */
	ifs.read((char*)&planes, sizeof(uint16_t));										/* Recolher a variável Planes do Image Header (2 bytes)  -> tem de ser 1 */
	/*if (planes != 1)
	{
		throw 1, 1;
	}*/
	ifs.read((char*)&bits, sizeof(uint16_t));										/* Recolher a variável Bits do Image Header (2 bytes) */
	ifs.read((char*)&compression, sizeof(uint32_t));								/* Recolher a variável Compression do Image Header (4 bytes)  -> tem de ser 0 */
	/*if (compression != 0)
	{
		throw 9, 99999;
	}*/
	ifs.read((char*)&imagesize, sizeof(uint32_t));									/* Recolher a variável ImageSize do Image Header (4 bytes) */
	ifs.read((char*)&xresolution, sizeof(uint32_t));								/* Recolher a variável Xresolution do Image Header (4 bytes) */
	ifs.read((char*)&yresolution, sizeof(uint32_t));								/* Recolher a variável Yresolution do Image Header (4 bytes) */
	ifs.read((char*)&ncolours, sizeof(uint32_t));									/* Recolher a variável Ncolours do Image Header (4 bytes) */
	ifs.read((char*)&importantcolours, sizeof(uint32_t));
	this->sizea = sizea;
	this->width = width;
	this->height = height;
	this->planes = planes;
	this->bits = bits;
	this->compression = compression;
	this->imagesize = imagesize;
	this->xresolution = xresolution;
	this->yresolution = yresolution;
	this->ncolours = ncolours;
	this->importantcolours = importantcolours;
	return true;
}

ostream& operator<<(ostream& o, const InfoHeader& ih)
{
	o << "Header size in bytes: " << ih.sizea << endl
		<< "Width of the Image: " << ih.width << endl
		<< "Height of the Image: " << ih.height << endl
		<< "Number of Colour Planes: " << ih.planes << endl
		<< "Bits per Pixel: " << ih.bits << endl
		<< "Compression Type: " << ih.compression << endl
		<< "Image Size in Bytes: " << ih.imagesize << endl
		<< "Pixels per Meter in X" << ih.xresolution << endl
		<< "Pixels per Meter in Y" << ih.yresolution << endl
		<< "Number of Colours" << ih.ncolours << endl
		<< "Important Colours" << ih.importantcolours << endl;
	return o;
}

bool  InfoHeader::writeInfoHeader(ofstream& ofs) 
{
	ofs.write((char*)&sizea, sizeof(uint32_t));										/* Escrever a variável Size do Image Header (4 bytes) */
	ofs.write((char*)&width, sizeof(uint32_t));										/* Escrever a variável Width do Image Header (4 bytes) */
	ofs.write((char*)&height, sizeof(uint32_t));									/* Escrever a variável Height do Image Header (4 bytes) */
	ofs.write((char*)&planes, sizeof(uint16_t));									/* Escrever a variável Planes do Image Header (2 bytes)  -> tem de ser 1 */
	ofs.write((char*)&bits, sizeof(uint16_t));										/* Escrever a variável Bits do Image Header (2 bytes) */
	ofs.write((char*)&compression, sizeof(uint32_t));								/* Escrever a variável Compression do Image Header (4 bytes)  -> tem de ser 0 */
	ofs.write((char*)&imagesize, sizeof(uint32_t));									/* Escrever a variável ImageSize do Image Header (4 bytes) */
	ofs.write((char*)&xresolution, sizeof(uint32_t));								/* Escrever a variável Xresolution do Image Header (4 bytes) */
	ofs.write((char*)&yresolution, sizeof(uint32_t));								/* Escrever a variável Yresolution do Image Header (4 bytes) */
	ofs.write((char*)&ncolours, sizeof(uint32_t));									/* Escrever a variável Ncolours do Image Header (4 bytes) */
	ofs.write((char*)&importantcolours, sizeof(uint32_t));
	return true;
}

uint32_t InfoHeader::getwidth() {
	return width;
}
uint32_t InfoHeader::getheight() {
	return height;
}