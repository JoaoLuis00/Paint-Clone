#pragma once
#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include "FileHeader.h"
#include "InfoHeader.h"
#include "Pixel.h"
#include "Image.h"




using namespace std;
//struct Vari�veis {
//	/*File Header*/
//	unsigned uint8_t byte0;												/* Magic identifier:  'B'      */
//	unsigned uint8_t byte1;												/* Magic identifier:  'M'      */
//	unsigned int size;													/* File size in bytes          */
//	unsigned short int reserved1, reserved2;							/* Bytes reserved			   */
//	unsigned int offset;												/* Offset to image data, bytes */
//
//	/*Image Header*/
//	unsigned int sizea;													/* Header size in bytes        */
//	int width, height;													/* Width and height of image   */
//	unsigned short int planes;											/* Number of colour planes     */
//	unsigned short int bits;											/* Bits per pixel              */
//	unsigned int compression;											/* Compression type            */
//	unsigned int imagesize;												/* Image size in bytes         */
//	int xresolution, yresolution;										/* Pixels per meter            */
//	unsigned int ncolours;												/* Number of colours           */
//	unsigned int importantcolours;										/* Important colours           */
//};

//struct Objetos {
//	FileHeader FS;
//	InfoHeader IS;
//};

class Bitmap {
public:
	//--------------------------------------------------------------------------------------------------------
	//Todas as Fun��es(	1-Construtor	|	2-Abrir o Ficheiro BMP	|	3-Ler o Ficheiro aberto	|	
	//	4-Feuint8_t o ficheiro BMP	|	5-Imprimir as Vari�veis lidas	|	6-Copiar para um novo Ficheiro BMP	)
	//--------------------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------------------------------------
	//		1-Fun��o Construtor:
	//		Esta fun��o constroi o objeto criado pelo utilizador
	//		Por outro lado, este construtor utiliza dois outros construtores de cada umas das classes (FileHeader e InfoHeader).
	//		Esta fun��o n�o tem qualquer tipo de retorno, apenas cria os construtores mais b�sicos, isto �, tudo a 0
	//---------------------------------------------------------------------------------------------------------------------------
	//Bitmap(const FileHeader& FS, const InfoHeader& IS, const Image& Img);
	Bitmap();
	//---------------------------------------------------------------------------------------------------------------------------
	//		2-Fun��o para abrir o ficheiro bmp:
	//		Esta fun��o � apenas usada uma vez por cada ficheiro BMP e obriga o uso da fun��o "void close();" sempre que a usamos
	//		O seu objetivo � abrir o ficheiro BMP em modo de leitura para de seguida podermos retirar todas as vari�veis uteis.
	//		Sabemos qual o ficheiro que precisamos de abrir pois o utilizador fornece-nos um nome ("string name").
	//		Depois de aberto o ficheiro BMP colocamos uma vari�vel ("bool openBMP;") a 1 para termos conhecimento.
	//		Caso esta fun��o n�o consiga encontrar o ficheiro mencionado pelo utilizador imprime uma mensagem de erro.
	//---------------------------------------------------------------------------------------------------------------------------
    void open(string file_name);

	//---------------------------------------------------------------------------------------------------------------------------
	//		3-Fun��o para ler todas as vari�veis do Ficheiro BMP:
	//		Esta fun��o utiliza duas outras fun��es de leitura localizadas em cada uma das classes (FileHeader e InfoHeader).
	//		Depois de lidas todas as vari�veis colocamos uma vari�vel ("bool jaleu;") a 1 para termos conhecimento.
	//---------------------------------------------------------------------------------------------------------------------------
	/*Objetos*//*Vari�veis*/ void read();

	//---------------------------------------------------------------------------------------------------------------------------FileHeader
	//		4-Fun��o para feuint8_t o ficheiro BMP aberto:
	//		Esta fun��o vem sempre em seguida da fun��o de abertura ("void open(string name);") por conven��o e 
	//		com o objetivo de ter-mos menores gastos de mem�ria e processamento.
	//---------------------------------------------------------------------------------------------------------------------------
	void close();

	//---------------------------------------------------------------------------------------------------------------------------
	//		5-Fun��o para Imprimir todas as vari�veis lidas do ficheiro bmp:
	//		Esta fun��o utiliza duas outras fun��es de impress�o de cada uma das classes (FileHeader e InfoHeader).
	//		N�o pretendo imprimir todos os pixeis visto que iria atrapalhar,e n�o iria fornecer nenhuma informa��o util para o utilizador
	//---------------------------------------------------------------------------------------------------------------------------
	void save(string file_name);

	Pixel& operator [](int i);

	int imgSize();
	int imgHeight();
	int imgWidth();

    //teste para a fun��o de crop(cortar) a imagem
    void clearimg(int width,int height);
    //

    //escrever em hex para o ficheiro
    void writePixelInfo();

	void imprimir();
	//---------------------------------------------------------------------------------------------------------------------------
	//		6-Fun��o para criar um novo ficheiro BMP e copiar tudo do ficheiro BMP aberto, anteriormente para o novo:
	//		Esta fun��o tem como objetivo a copia de todas as vari�veis lidas inclusive todos os pixeis do ficheiro BMP aberto 
	//		e escolhido pelo utilizador, para um ficheiro BMP novo com o nome de ("copia.bmp"), criado ainda nesta fun��o.
	//		Fazemos isto pois, deste modo, podemos sempre n�o gravar as altera��es efetuadas � imagem original e esperamos apenas
	//		para copiar de volta para o ficheiro BMP inicial, caso o utilizador pretenda gravar as altera��es.
	//---------------------------------------------------------------------------------------------------------------------------
	void copiar(FileHeader FS, InfoHeader IS, Image Img);

private:
	//-----------------------------------------------------------------------------------------------
	//Todas as Vari�vels(	1-Ficheiros	|	2-Controlo	|	3-Objetos	|	4-Para apagar no futuro	)
	//-----------------------------------------------------------------------------------------------

	//-----------------------------------------
	//		1-Vari�veis de Ficheiro:
	//-----------------------------------------
	ifstream bucky;
	ofstream bucky1;
	string name;
	//-----------------------------------------
	//		2-vari�veis de controlo:
	//-----------------------------------------
	bool jaleu;
	bool openBMP;
	//-----------------------------------------
	//		3-Objetos das outras classes:
	//-----------------------------------------
	FileHeader FS;
	InfoHeader IS;
protected:
	Image Img;
	Pixel pt;
	//-----------------------------------------
	//4-Vari�veis designadas das outras classes
	//-----------------------------------------
	//unsigned uint8_t byte0;												/* Magic identifier:  'B'      */
	//unsigned uint8_t byte1;												/* Magic identifier:  'M'      */
	//unsigned int size;												/* File size in bytes          */
	//unsigned short int reserved1, reserved2;							/* Bytes reserved			   */
	//unsigned int offset;												/* Offset to image data, bytes */
	//unsigned int sizea;												/* Header size in bytes        */
	//int width, height;												/* Width and height of image   */
	//unsigned short int planes;										/* Number of colour planes     */
	//unsigned short int bits;											/* Bits per pixel              */
	//unsigned int compression;											/* Compression type            */
	//unsigned int imagesize;											/* Image size in bytes         */
	//int xresolution, yresolution;										/* Pixels per meter            */
	//unsigned int ncolours;											/* Number of colours           */
	//unsigned int importantcolours;
	//
	//-----------------------------------------
	//			Fim das Vari�veis
	//-----------------------------------------
};
