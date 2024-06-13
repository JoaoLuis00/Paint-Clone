#pragma once
#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
//Alterado
using namespace std;

class InfoHeader {
public:
	InfoHeader();
	bool readInfoHeader(ifstream& ifs);
	friend ostream& operator<<(ostream& o, const InfoHeader& ih);
	bool  writeInfoHeader(ofstream& ofs);
	uint32_t getwidth();
	uint32_t getheight();
	private:
	uint32_t sizea;													/*			Header size in bytes			*/
	uint32_t width;													/*			Width of the Image				*/
	uint32_t height;												/*			Height of the Image				*/
	uint16_t planes;												/*			Colour Planes -> tem de ser 1	*/
	uint16_t bits;													/*			Bits per pixel					*/
	uint32_t compression;											/*			Compression type -> tem de ser 0*/
	uint32_t imagesize;												/*			Image size in bytes				*/
	uint32_t xresolution;											/*			Pixels per Meter in X			*/
	uint32_t yresolution;											/*			Pixels per Meter in Y			*/
	uint32_t ncolours;												/*			Number of Colours				*/
	uint32_t importantcolours;										/*			Important Colours				*/
};