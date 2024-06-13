#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <vector>
#include "Pixel.h"

using namespace std;


//----------------------------------------------------------------------------------//
//								TODO: Vetor de Objetos Pixel						//
// PT: Este vetor cont�m objetos Pixel no seu interior, formando a matriz de Pixeis	//
// EN: This vector contains Pixel Objects, to form the PixelMatriz					//
//----------------------------------------------------------------------------------//
typedef	vector <Pixel> PixelMatrix;



//--------------------------------------------------------------------------//
// TODO: Class Imagem														//
// PT: Esta class � utilizada para fazer o agrupamento dos Pixeis do Bitmap	//
// EN: This class is used to agroup all the Pixels from the Bitmap image	//
//--------------------------------------------------------------------------//
class Image {
public:
	//--------------------------------------------------------------------------------------------------------------------------------------//
	//TODO: Construtores																													//
	// PT: Existem dois construtores da class Image, pertencente ao ficheiro "PixelImage.h".												//
	// Um por defeito, colocando height e width a 0, e outro a receber esses mesmos argumentos												//
	// EN: There are two constructores in the class Image, that belongs to the PixelImage.h file.											//
	// We made one by default, that puts height and width with the value of 0, and another one that receives those two varibles by argument //
	//--------------------------------------------------------------------------------------------------------------------------------------//
	Image();
	Image(int height, int width);

	//-------------------------------------------------------------------------------------------------------------------------------------------------//
	//TODO-Pt: 1-Escrever no ecr�/2-Ler do ficheiro Bitmap/3-Escrever do ficheiro Bitmap/4-Overload para escrita no display/5-Atribui��o das vari�veis //													  //
	//-------------------------------------------------------------------------------------------------------------------------------------------------//

	//-------------------------------------------------------------------------------------------------------------------------------------------//
	// 1-PT: A fun��o "imprimirVetor()", �n�o recebe qualquer argumento e o seu objetivo � pura e simplesmente escrever no ecr� todos os pixeis  //
	// 1-EN: The function "imprimirVetor()", does not receive any argument and his purpose is only to write all the Pixels in the display 		 //
	//-------------------------------------------------------------------------------------------------------------------------------------------//
	//void imprimirVetor();

	//----------------------------------------------------------------------------------------------------------------------------------------//
	// 2-PT: A fun��o "readImage(ifstream& bucky)", recebe um ficheiro para leitura como argumento e faz a atribui��o das respetivas vari�vel //
	// 2-EN: The function "readImage(ifstream& bucky)", receives by an argument a file to read,												  //
	// and with that the function assigns the values to the respective variable																  //
	//----------------------------------------------------------------------------------------------------------------------------------------//
	void readImage(ifstream& bucky);

	//------------------------------------------------------------------------------------------------------------------------------------------------------------//
	// 3-PT: A fun��o "writeImage(ofstream& ofs)", recebe um ficheiro para escrita como argumento e o seu prop�sito � escrever os Pixeis nesse mesmo ficheiro  //
	// 3-EN: The function "writeImage(ofstream& ofs)", receives by an argument a file to write and his purpose is to write the Pixels in that File 			  //
	//------------------------------------------------------------------------------------------------------------------------------------------------------------//
	bool writeImage(ofstream& ofs);


	//-------------------------------------------------------------------------------------------------------------------------------------------//
	// 4-PT: A fun��o "ostream& operator <<(ostream& os, const Image& img)", � uma fun��o de overload, que recebe dois argumentos sendo			 //
	// que o primeiro � a escrita no ecr� e o segundo � o objeto Image,o seu prop�sito escrever no ecr� todos os pixeis							 //
	// 4-EN: The function ostream& operator <<(ostream& os, const Image& img)", It's an overload function, that receives two arguments			 //
	// the first one is the writing overload and the secoond one is the Image Object. His purpose is only to write all the Pixels in the display //
	//-------------------------------------------------------------------------------------------------------------------------------------------//
	friend ostream& operator <<(ostream& os, const Image& img);

	//----------------------------------------------------------------------------------------------------------//
	// 5-PT: As fun��es de Set recebem um argumento que ser� a atribui��o � respetiva vari�vel					//
	// (utilizadas maioritariamente para introduzir os valores de altura e comprimento, antes de ler os pixeis)	//
	// 5-EN: The Set functions receives an argument that assigns the values to the respective variable  		//
	//----------------------------------------------------------------------------------------------------------/~/
	void setHeight(int height);
	void setSize(int size);
	void setWidth(int width);

    void resetpixels(int width,int height);

	int getSize();
	int getHeight();
	int getWidth();
	//************************FAZER ESTES COMENTARIOS***********************************
	//Pixel* operator [](int i);
	Pixel& operator [](int i);


	//-------------------------------------//
	//		Pertencentes � Class Filtro    //
	//-------------------------------------//

	//------------------------------------------------------------------------------//
	// TODO:			Protected Variables of Class Imagem							//
	// PT: Esta vetor � utilizado para fazer o agrupamento dos Pixeis do Bitmap		//
	// EN: This vector is used to agroup all the Pixels from the Bitmap image		//
	//------------------------------------------------------------------------------//
protected:
	PixelMatrix pixels;

	//------------------------------------------------------------------------------//
	// TODO:			Private Variables of Class Imagem							//
	//------------------------------------------------------------------------------//
private:
	ifstream bucky;
	string name;
	int size;
	int height;
	int width;
};
