#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

class Pixel {
public:
	// Inicializa o Objeto Pixel com cor preta como default.
	Pixel();
	// Inicializa o Objeto Pixel com a cor especificada nos valores RGB.
	Pixel(uint8_t r, uint8_t g, uint8_t b);
	friend ostream& operator <<(ostream& os, const Pixel& px);
	uint8_t getr(void);
	uint8_t getg(void);
	uint8_t getb(void);
	void setr(uint8_t r);
	void setg(uint8_t g);
	void setb(uint8_t b);

private:
	// Stores the individual color components.
	uint8_t red, green, blue;

};