#include <iostream>
#include <fstream>
#include <cstddef>
#include "Hana.h"

int main(int argc, char **argv)
{
	char* buff = nullptr;
	if (argc > 2)
	{
		std::cerr << "Usage" << argv[0] << " <filename>" << std::endl;
		exit(1);
	}
	// get the source stream;
	std::ifstream source;
	source.open(argv[1]);
	if (source.good() == true)
	{
		std::cout << "interpret code from: " << argv[1] << std::endl;
		source.seekg(0, std::ios::end);
		size_t len = source.tellg();
		source.seekg(0, std::ios::beg);
		buff = new char[len];
		source.read(buff, len);
		source.close();
	}
	else
	{
		std::cerr << "Invalid file: " << argv[1] << std::endl;
		exit(1);
	}
	Hana hana = Hana(buff);
	hana.validation();
	return 0;
}