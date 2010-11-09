#include <iostream>
#include <string>

#include "dump.h"

void volcarXml(const std::string &filename)
{
	TiXmlDocument doc(filename.c_str());
	bool loadOkay = doc.LoadFile();
	if (loadOkay)	{
		std::cout << "Archivo: " << filename << std::endl;
		dump_to_stdout ( &doc ); // defined later in the tutorial
	} else {
		std::cout << "Error al cargar " << filename << std::endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc > 1) {
		volcarXml(argv[1]);
	}
	return 0;
}
