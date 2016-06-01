#include "SIM_Microprocessor.h"

SIM::SIM()
{
	//std::map <std::string, ADD*> HashTable;
	//HashTable["ADD"] = new ADD();
	//InstrEntry = { "ADD", "SUB", "MUL", "NEG", "JUMP", "JUMP0", "ASSIGN", "LESS", "LARGER", "EQUAL", "READ", "WRITE", "HALT" };
	//std::cout << "SIM Object insantiated." << std::endl;
	//InstructionCount = &count;
	//SIM_IM =  &IM();		//SIM's Instruction Memory.
	//SIM_DM =  &DM();		//SIM's Data Memory.
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
		if (line.empty())
			continue;		//Skip empty lines.
		SIM_IM->LoadToInstructionMemory(InstructionCount, line);
		(*InstructionCount)++;
	}

	std::cout << "Want to check the Instruction Memory? (Y/N)" << std::endl;
	std::cin >> keyword;
	if (keyword == 'Y' || keyword == 'y')
		SIM_IM->DisplayIM();
};

void SIM::Execute()
{
	std::string CurrentInstruction;
	for (int j = 0; j < *InstructionCount; j++)
	{
		CurrentInstruction = SIM_IM->LoadFromInstructionMemory[*InstructionCount];
		//Got an instruction. Check first word? If valid, read operands corresponding to instruction. (Handle errors).
		//Each instruction will be instantiated once in the SIM constructor.
		//Whenever there is a match, use Instruction.Execute() method.
		//Else, print a nonsense statement. 
		//Use unordered_map ??
	}
}

SIM::~SIM()
{
	//delete SIM_IM, SIM_DM, InstructionCount;
	//delete []InstrEntry;
};