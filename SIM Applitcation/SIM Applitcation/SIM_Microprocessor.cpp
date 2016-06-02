#include "SIM_Microprocessor.h"

int Lookup(std::string);
void ReadThreeOperands(std::string, int&, std::string&, std::string&, std::string&);
void ReadTwoOperands(std::string, int&, std::string&, std::string&);
void ReadOneOperand(std::string, int&, std::string&);

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
	int OPCODE;
	int cursor = 0;	int SizeOfIM = count;
	std::string CurrentInstruction;
	std::string operation;
	std::string operand1, operand2, operand3;

	for (int j = 0; j < SizeOfIM; j++)		//Looping through the Whole Instruction Memory till the end.
	{
		CurrentInstruction = SIM_IM->LoadFromInstructionMemory(j);
		//This block of code is reading the operation type and stores it in operation variable.
		while (1)
		{
			if (operation.empty())
				operation = CurrentInstruction[cursor];
			else
				operation += CurrentInstruction[cursor];
			cursor++;
			if (CurrentInstruction[cursor] == ' ')
			{
				cursor++;
				break;
			}
		}
		OPCODE = Lookup(operation);
		//Calling a function to read the operands based on what type of instruction it is.
		switch (OPCODE)
		{

		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			ReadThreeOperands(CurrentInstruction, cursor, operand1, operand2, operand3);
			//Call 3 operands read function.
			//To do.
			break;
		
		case 7:
		case 8:
		case 9:
			//Call 2 operands read function.
			//To do.
			break;

		case 10:
		case 11:
		case 12:
			//Call  operands read function.
			//To do.
			break;

		case 13:
			//Halt
			break;
		
		default:
			std::cerr << "Unidentified Instruction Type." << std::endl;
			break;
		}
		// ADD A,B,0
		//Example: operation = "ADD"	operand1 = "A"	operand2 = "B"	operand3 = "0"

	}
}

SIM::~SIM()
{
	//delete SIM_IM, SIM_DM, InstructionCount;
	//delete []InstrEntry;
};

int Lookup(std::string S)
{
	int OperationNumber;

	//Start of Three Operand-Instructions.
	if (S == "ADD")
		OperationNumber = 1;
	else if (S == "SUB")
		OperationNumber = 2;
	else if (S == "MUL")
		OperationNumber = 3;
	else if (S == "LESS")
		OperationNumber = 4;
	else if (S == "LARGER")
		OperationNumber = 5;
	else if (S == "EQUAL")
		OperationNumber = 6;
	//Start of Two Operand-Instructions.
	else if (S == "NEG")
		OperationNumber = 7;
	else if (S == "JMP0")
		OperationNumber = 8;
	else if (S == "ASSIGN")
		OperationNumber = 9;
	//Start of One Operand-Instructions.
	else if (S == "JMP")
		OperationNumber = 10;
	else if (S == "READ")
		OperationNumber = 11;
	else if (S == "WRITE")
		OperationNumber = 12;
	else return 13;		//HALT.

}

void ReadThreeOperands(std::string LINE, int& cursor, std::string& IN1, std::string& IN2, std::string& OUT)
{
	int CountCommas = 0, EndOfLine = LINE.length();

	//Keep reading operands till hits end of instruction.

	while (CountCommas < 1)		//IN1
	{
		if (LINE[cursor] == ' ')
			continue;		//SKIP.

		if (IN1.empty())
			IN1 = LINE[cursor];
		else
			IN1 += LINE[cursor];
		cursor++;
		if (LINE[cursor] == ',')
		{
			CountCommas++;
			cursor++;
		}
	}

	while (true)		//IN2
	{
		if (LINE[cursor] == ' ')
			continue;		//SKIP.

		if (IN2.empty())
			IN2 = LINE[cursor];
		else
			IN2 += LINE[cursor];
		cursor++;
		if (LINE[cursor] == ',')
		{
			CountCommas++;
			cursor++;
		}
	}

	while (CountCommas < 3)		//OUT
	{
		if (LINE[cursor] == ' ')
			continue;		//SKIP.

		if (OUT.empty())
			OUT = LINE[cursor];
		else
			OUT += LINE[cursor];
		cursor++;
		if (cursor == EndOfLine)
			break;
	}
}

void ReadTwoOperands(std::string LINE, int& cursor, std::string& IN1, std::string& OUT)
{
	int CountCommas = 0, EndOfLine = LINE.length();

	//Keep reading operands till hits end of instruction.

	while (CountCommas < 1)		//IN1
	{
		if (LINE[cursor] == ' ')
			continue;		//SKIP.

		if (IN1.empty())
			IN1 = LINE[cursor];
		else
			IN1 += LINE[cursor];
		cursor++;
		if (LINE[cursor] == ',')
		{
			CountCommas++;
			cursor++;
		}
	}

	while (true)		//OUT
	{
		if (LINE[cursor] == ' ')
			continue;		//SKIP.

		if (OUT.empty())
			OUT = LINE[cursor];
		else
			OUT += LINE[cursor];
		cursor++;
		if (cursor == EndOfLine)
			break;
	}
}

void ReadOneOperand(std::string LINE, int& cursor, std::string& OUT)
{
	int EndOfLine = LINE.length();

	while (true)		//OUT
	{
		if (LINE[cursor] == ' ')
			continue;		//SKIP.

		if (OUT.empty())
			OUT = LINE[cursor];
		else
			OUT += LINE[cursor];
		cursor++;
		if (cursor == EndOfLine)
			break;
	}
}