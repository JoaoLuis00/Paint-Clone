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
//struct Variáveis {
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
	//Todas as Funções(	1-Construtor	|	2-Abrir o Ficheiro BMP	|	3-Ler o Ficheiro aberto	|	
	//	4-Feuint8_t o ficheiro BMP	|	5-Imprimir as Variáveis lidas	|	6-Copiar para um novo Ficheiro BMP	)
	//--------------------------------------------------------------------------------------------------------

	//---------------------------------------------------------------------------------------------------------------------------
	//		1-Função Construtor:
	//		Esta função constroi o objeto criado pelo utilizador
	//		Por outro lado, este construtor utiliza dois outros construtores de cada umas das classes (FileHeader e InfoHeader).
	//		Esta função não tem qualquer tipo de retorno, apenas cria os construtores mais básicos, isto é, tudo a 0
	//---------------------------------------------------------------------------------------------------------------------------
	//Bitmap(const FileHeader& FS, const InfoHeader& IS, const Image& Img);
	Bitmap();
	//---------------------------------------------------------------------------------------------------------------------------
	//		2-Função para abrir o ficheiro bmp:
	//		Esta função é apenas usada uma vez por cada ficheiro BMP e obriga o uso da função "void close();" sempre que a usamos
	//		O seu objetivo é abrir o ficheiro BMP em modo de leitura para de seguida podermos retirar todas as variáveis uteis.
	//		Sabemos qual o ficheiro que precisamos de abrir pois o utilizador fornece-nos um nome ("string name").
	//		Depois de aberto o ficheiro BMP colocamos uma variável ("bool openBMP;") a 1 para termos conhecimento.
	//		Caso esta função não consiga encontrar o ficheiro mencionado pelo utilizador imprime uma mensagem de erro.
	//---------------------------------------------------------------------------------------------------------------------------
    void open(string file_name);

	//---------------------------------------------------------------------------------------------------------------------------
	//		3-Função para ler todas as variáveis do Ficheiro BMP:
	//		Esta função utiliza duas outras funções de leitura localizadas em cada uma das classes (FileHeader e InfoHeader).
	//		Depois de lidas todas as variáveis colocamos uma variável ("bool jaleu;") a 1 para termos conhecimento.
	//---------------------------------------------------------------------------------------------------------------------------
	/*Objetos*//*Variáveis*/ void read();

	//---------------------------------------------------------------------------------------------------------------------------FileHeader
	//		4-Função para feuint8_t o ficheiro BMP aberto:
	//		Esta função vem sempre em seguida da função de abertura ("void open(string name);") por convenção e 
	//		com o objetivo de ter-mos menores gastos de memória e processamento.
	//---------------------------------------------------------------------------------------------------------------------------
	void close();

	//---------------------------------------------------------------------------------------------------------------------------
	//		5-Função para Imprimir todas as variáveis lidas do ficheiro bmp:
	//		Esta função utiliza duas outras funções de impressão de cada uma das classes (FileHeader e InfoHeader).
	//		Não pretendo imprimir todos os pixeis visto que iria atrapalhar,e não iria fornecer nenhuma informação util para o utilizador
	//---------------------------------------------------------------------------------------------------------------------------
	void save(string file_name);

	Pixel& operator [](int i);

	int imgSize();
	int imgHeight();
	int imgWidth();

    //teste para a função de crop(cortar) a imagem
    void clearimg(int width,int height);
    //

    //escrever em hex para o ficheiro
    void writePixelInfo();

	void imprimir();
	//---------------------------------------------------------------------------------------------------------------------------
	//		6-Função para criar um novo ficheiro BMP e copiar tudo do ficheiro BMP aberto, anteriormente para o novo:
	//		Esta função tem como objetivo a copia de todas as variáveis lidas inclusive todos os pixeis do ficheiro BMP aberto 
	//		e escolhido pelo utilizador, para um ficheiro BMP novo com o nome de ("copia.bmp"), criado ainda nesta função.
	//		Fazemos isto pois, deste modo, podemos sempre não gravar as alterações efetuadas à imagem original e esperamos apenas
	//		para copiar de volta para o ficheiro BMP inicial, caso o utilizador pretenda gravar as alterações.
	//---------------------------------------------------------------------------------------------------------------------------
	void copiar(FileHeader FS, InfoHeader IS, Image Img);

private:
	//-----------------------------------------------------------------------------------------------
	//Todas as Variávels(	1-Ficheiros	|	2-Controlo	|	3-Objetos	|	4-Para apagar no futuro	)
	//-----------------------------------------------------------------------------------------------

	//-----------------------------------------
	//		1-Variáveis de Ficheiro:
	//-----------------------------------------
	ifstream bucky;
	ofstream bucky1;
	string name;
	//-----------------------------------------
	//		2-variáveis de controlo:
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
	//4-Variáveis designadas das outras classes
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
	//			Fim das Variáveis
	//-----------------------------------------
};
