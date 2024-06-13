#include "FileHeader.h"
//Alterado
FileHeader::FileHeader()
	:type(0), size (0), reserved1(0), reserved2(0), offset(0)
{
}
/*int16_t type;													
uint32_t size;													
uint16_t reserved1;
uint16_t reserved2;												
uint32_t offset; */
bool  FileHeader::readFileHeader(ifstream& ifs) {
	/* Recolher o caracter 'B' do File Header (1 bytes) */
	ifs.read((char*)&type, sizeof(uint16_t));										/* Recolher o caracter 'M' do File Header (1 bytes) */
	ifs.read((char*)&size, sizeof(uint32_t));										/* Recolher a variável Size do File Header (4 bytes) */
	ifs.read((char*)&reserved1, sizeof(uint16_t));									/* Recolher a variável BReserved do File Header (2 bytes) -> tem de ser 0 */
	ifs.read((char*)&reserved2, sizeof(uint16_t));									/* Recolher a variável BReserved1 do File Header (2 bytes) -> tem de ser 0 */
	if (reserved1 != 0 || reserved2 != 0) {
		return false;
		throw 2;
	}
	ifs.read((char*)&offset, sizeof(uint32_t));
	return true;
}
ostream& operator<<(ostream& o, const FileHeader& fh)
{
	o << "Tipo: " << fh.type << endl 
	  << "Tamanho: " << fh.size << endl 
      << "Byte Reservado1: " << fh.reserved1 
	  << endl << "Byte Reservado2: " 
	  << fh.reserved2 << endl << "Byte Offset: " 
	  << fh.offset << endl;
	return o;
}

bool  FileHeader::writeFileHeader(ofstream& ofs) {
	ofs.write((char*)&type, sizeof(uint16_t));
	ofs.write((char*)&size, sizeof(uint32_t));
	ofs.write((char*)&reserved1, sizeof(uint16_t));
	ofs.write((char*)&reserved2, sizeof(uint16_t));
	ofs.write((char*)&offset, sizeof(uint32_t));
	return true;
}
