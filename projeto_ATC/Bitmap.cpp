#include "Bitmap.h"

//Bitmap::Bitmap(const FileHeader& FS, const InfoHeader& IS, const Image& Img)
//	: FS(), IS(), Img(), jaleu(0), openBMP(0)
//{
//
//}

Bitmap::Bitmap()
	: FS(), IS(), Img(), jaleu(0), openBMP(0)
{

}

void Bitmap::open(string file_name)
{
	//fazer com que o name entre no bucky.open!
    bucky.open(file_name, ios::binary | ios::in); //ainda por terminar pois estamos a inserir "joao.bmp" e � suposto entrar o argumento (name) e adicionarmos .bmp no fim da string
	if (!bucky.is_open()) {
		exit(EXIT_FAILURE);
	}
	this->openBMP = 1;
}

/*Objetos*/ void Bitmap::read()
{
	FS.readFileHeader(bucky);
	IS.readInfoHeader(bucky);
	int width = IS.getwidth();
	int height = IS.getheight();
	Img.setHeight(height);
	Img.setWidth(width);
	int size = width * height;
	Img.setSize(size);
	Img.readImage(bucky);
	//passar width e height para o ler pixeis
	if (openBMP == 1 && jaleu == 1)
	{
		//usar esta fun��o para a manipula��o dos bits xD
	}
	//return { /*byte0, byte1, size, reserved1, reserved2, offset, sizea, width, height, planes, bits, compression, imagesize, xresolution, yresolution, ncolours, importantcolours*/FS,IS };
	else {
		this->jaleu = 1;
	}
}

void Bitmap::close()
{
	bucky.close();
}

void Bitmap::imprimir()
{
	cout << FS;
	cout << endl;
	cout << IS;
	cout << endl;
    for(int i=0;i<imgSize();i++)
        cout << Img[i];
	cout << endl;
}

Pixel& Bitmap::operator[](int i)
{
	return Img[i];
}

int Bitmap::imgSize()
{
	return (Img.getSize());
}

int Bitmap::imgHeight()
{
	return (Img.getHeight());
}

int Bitmap::imgWidth()
{
    return (Img.getWidth());
}

void Bitmap::clearimg(int width,int height)
{
    Img.resetpixels(width,height);
}

void Bitmap::writePixelInfo()
{
    int size = imgSize();

        ofstream temp;
        temp.open(name + ".bin",ios::binary | ios::out);
        if (!temp.is_open())
        {
            cout << "erro";
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < size; i++)
        {
            temp << Img[i];

            if (i + 1 < size)
                temp << ",";
        }
}

void Bitmap::save(string file_name)
{
	ofstream temp;
	temp.open((file_name+".bmp"), ios::binary | ios::out); //ainda por terminar pois estamos a inserir "joao.bmp" e � suposto entrar o argumento (name) e adicionarmos .bmp no fim da string
	if (!temp.is_open()) {
		cout << "erro";
		exit(EXIT_FAILURE);
	}
	if (FS.writeFileHeader(temp) == false)
	{
		cerr << "Error Writing FileHeader";
	}
	if (IS.writeInfoHeader(temp) == false)
	{
		cerr << "Error Writing InfoHeader";
	}
	if (Img.writeImage(temp) == false)
	{
		cerr << "Error Writing Image";
	}
	temp.close();
}
