#include "SIM_Microprocessor.h"

SIM::SIM()
{
	SIM_IM =  &IM();		//SIM's Instruction Memory.
	SIM_DM =  &DM();		//SIM's Data Memory.
};

void SIM::ReadFile()
{
	std::ifstream File;
	std::string line;
	std::regex Header("\\S.I.M.\\s+\\d.\\d");
	char keyword;
	std::string filename, extension;
	int sizeOf, start;
	
	std::cout << "Enter the name of the file to read: ";
	std::cin >> filename;
	sizeOf = filename.length();
	start = sizeOf - 4;
	extension = filename.substr(start, sizeOf);
	if (extension != ".txt")
	{
		filename += ".txt";
		std::cout << "You haven't written extension. Did you mean " << filename << "? (Y/N)" << std::endl;
		std::cin >> keyword;
		if (!(keyword == 'y' || keyword == 'Y'))
			exit;
	}
	File.open(filename);
	if (File.is_open())
	{
		std::cout << "File is opened. Checking Header..." << std::endl;
		getline(File, line);
		if (std::regex_match(line, Header))
			std::cout << "Header found! Loading Instructions to Instruction Memory..." << std::endl;
	}
	while (!File.eof())
	{
		getline(File, line);
		SIM_IM->LoadToInstructionMemory(line);
	}

	std::cout << "Want to check the Instruction Memory? (Y/N)" << std::endl;
	std::cin >> keyword;
	if (keyword == 'Y' || keyword == 'y')
		SIM_IM->DisplayIM();
};

SIM::~SIM()
{};