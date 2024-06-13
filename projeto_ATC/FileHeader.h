#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
//Alterado
using namespace std;

class FileHeader {
public:
	FileHeader();
	bool readFileHeader(ifstream& ifs);
	friend ostream& operator<<(ostream& o, const FileHeader& fh);
	bool  writeFileHeader(ofstream& ofs);
	//private:
	int16_t type;													/* Magic identifier:  'B' 'M'     */
	uint32_t size;													/* File size in bytes          */
	uint16_t reserved1;
	uint16_t reserved2;												/* Bytes reserved			   */
	uint32_t offset;
};