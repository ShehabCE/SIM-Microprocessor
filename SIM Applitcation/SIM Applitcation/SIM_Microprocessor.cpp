#include "SIM_Microprocessor.h"

int Lookup(std::string);
void ReadThreeOperands(std::string, int&, std::string&, std::string&, std::string&);
void ReadTwoOperands(std::string, int&, std::string&, std::string&);
void ReadOneOperand(std::string, int&, std::string&);

SIM::SIM()
{};

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
		SIM_IM->Inject_To_InstructionMemory(line);
	}

	InstructionsCount = SIM_IM->GetPC();			//Size of my Instruction Memory.
	std::cout << "Want to check the Instruction Memory? (Y/N)" << std::endl;
	std::cin >> keyword;
	if (keyword == 'Y' || keyword == 'y')
		SIM_IM->DisplayIM();
};

void SIM::Execute()
{
	int int_operand2 = 0, int_operand3 = 0, int_operand1 = 0;
	int OPCODE;
	int cursor = 0;	int SizeOfIM = InstructionsCount;
	std::string CurrentInstruction;
	std::string operation;
	std::string operand1, operand2, operand3;

	//The following loop is the execution of Instruction and Writing to Data Memory.
	for (int j = 0; j < SizeOfIM; j++)		//Looping through the Whole Instruction Memory till the end.
	{
		CurrentInstruction = SIM_IM->LoadFromInstructionMemory(j);		//Fetch Instruction.
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
			///////////////////////////////////////////////////////////////////////////////////////////////////
		case 1:
			ReadThreeOperands(CurrentInstruction, cursor, operand1, operand2, operand3);
			if (isdigit(operand2[0]))
				int_operand2 = operand2[0] - '0';		//Convert from '9' to 9.
			else
				int_operand2 = SIM_DM->ReadFromDataMemory(operand2);
			
			if (isdigit(operand3[0]))
				int_operand3 = operand3[0] - '0';
			else
				int_operand3 = SIM_DM->ReadFromDataMemory(operand3);

			int_operand1 = Instr_ADD->Perform(int_operand2,int_operand3);
			SIM_DM->WriteToDataMemory(operand1, int_operand1);

			break;

			///////////////////////////////////////////////////////////////////////////////////////////////////
		case 2:
			ReadThreeOperands(CurrentInstruction, cursor, operand1, operand2, operand3);
			if (isdigit(operand2[0]))
				int_operand2 = operand2[0] - '0';		//Convert from '9' to 9.
			else
				int_operand2 = SIM_DM->ReadFromDataMemory(operand2);

			if (isdigit(operand3[0]))
				int_operand3 = operand3[0] - '0';
			else
				int_operand3 = SIM_DM->ReadFromDataMemory(operand3);

			int_operand1 = Instr_SUB->Perform(int_operand2, int_operand3);
			SIM_DM->WriteToDataMemory(operand1, int_operand1);
			//SUB

			break;

			///////////////////////////////////////////////////////////////////////////////////////////////////
		case 3:
			ReadThreeOperands(CurrentInstruction, cursor, operand1, operand2, operand3);
			//MUL
			if (isdigit(operand2[0]))
				int_operand2 = operand2[0] - '0';		//Convert from '9' to 9.
			else
				int_operand2 = SIM_DM->ReadFromDataMemory(operand2);

			if (isdigit(operand3[0]))
				int_operand3 = operand3[0] - '0';
			else
				int_operand3 = SIM_DM->ReadFromDataMemory(operand3);

			int_operand1 = Instr_MUL->Perform(int_operand2, int_operand3);
			SIM_DM->WriteToDataMemory(operand1, int_operand1);

			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////
		case 4:
			ReadThreeOperands(CurrentInstruction, cursor, operand1, operand2, operand3);
			//LARGER

			if (isdigit(operand2[0]))
				int_operand2 = operand2[0] - '0';		//Convert from '9' to 9.
			else
				int_operand2 = SIM_DM->ReadFromDataMemory(operand2);

			if (isdigit(operand3[0]))
				int_operand3 = operand3[0] - '0';
			else
				int_operand3 = SIM_DM->ReadFromDataMemory(operand3);

			int_operand1 = Instr_LARGER->Perform(int_operand2, int_operand3);
			SIM_DM->WriteToDataMemory(operand1, int_operand1);
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////
		case 5:
			ReadThreeOperands(CurrentInstruction, cursor, operand1, operand2, operand3);
			//LESS
			if (isdigit(operand2[0]))
				int_operand2 = operand2[0] - '0';		//Convert from '9' to 9.
			else
				int_operand2 = SIM_DM->ReadFromDataMemory(operand2);

			if (isdigit(operand3[0]))
				int_operand3 = operand3[0] - '0';
			else
				int_operand3 = SIM_DM->ReadFromDataMemory(operand3);

			int_operand1 = Instr_LESS->Perform(int_operand2, int_operand3);
			SIM_DM->WriteToDataMemory(operand1, int_operand1);

			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////
		case 6:
			ReadThreeOperands(CurrentInstruction, cursor, operand1, operand2, operand3);
			//ISEQUAL

			if (isdigit(operand2[0]))
				int_operand2 = operand2[0] - '0';		//Convert from '9' to 9.
			else
				int_operand2 = SIM_DM->ReadFromDataMemory(operand2);

			if (isdigit(operand3[0]))
				int_operand3 = operand3[0] - '0';
			else
				int_operand3 = SIM_DM->ReadFromDataMemory(operand3);

			int_operand1 = Instr_EQUAL->Perform(int_operand2, int_operand3);
			SIM_DM->WriteToDataMemory(operand1, int_operand1);
			
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////
		case 7:
			ReadTwoOperands(CurrentInstruction, cursor, operand1, operand2);
			//NEG
			if (isdigit(operand2[0]))
				int_operand2 = operand2[0] - '0';		//Convert from '9' to 9.
			else
				int_operand2 = SIM_DM->ReadFromDataMemory(operand2);

			int_operand1 = Instr_NEG->Perform(int_operand2);
			SIM_DM->WriteToDataMemory(operand1, int_operand1);

			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////
		case 8:
			ReadTwoOperands(CurrentInstruction, cursor, operand1, operand2);
			//JMP0
			int_operand2 = stoi(operand2);
			int_operand1 = SIM_DM->ReadFromDataMemory(operand1);
			if (int_operand1 == 0)
				if (int_operand2 > 0 && int_operand2 <= SizeOfIM)
					j = int_operand1;
				else std::cerr << "**ERROR: Jump Addres out of Range!." << std::endl;
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////
		case 9:
			ReadTwoOperands(CurrentInstruction, cursor, operand1, operand2);
			//ASSIGN
			break;
			if (isdigit(operand2[0]))
				int_operand2 = operand2[0] - '0';		//Convert from '9' to 9.
			else
				int_operand2 = SIM_DM->ReadFromDataMemory(operand2);

			int_operand1 = Instr_ASSIGN->Perform(int_operand2);
			SIM_DM->WriteToDataMemory(operand1, int_operand1);
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////
		case 10:
			ReadOneOperand(CurrentInstruction, cursor, operand1);
			//JMP
			int_operand1 = stoi(operand1);
			if (int_operand1 > 0 && int_operand1 <= SizeOfIM)
				j = int_operand1;		//assigned the new address to iterator to fetch.
			else std::cerr << "**ERROR: Jump Addres out of Range!." << std::endl;
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////
		case 11:
			ReadOneOperand(CurrentInstruction, cursor, operand1);
			//READ
			int_operand1 = Instr_READ->Perform(operand1);
			SIM_DM->WriteToDataMemory(operand1, (int)int_operand1);
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////
		case 12:
			ReadOneOperand(CurrentInstruction, cursor, operand1);
			//WRITE
			std::cout << operand1 << " = " << SIM_DM->ReadFromDataMemory << std::endl;
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////
		case 13:
			//Halt
			std::cout << "Halt!" << std::endl;
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////
		case 100:
			std::cerr << "Unidentified Instruction Type." << std::endl;
			break;
			///////////////////////////////////////////////////////////////////////////////////////////////////
		}
		// ADD A,B,0
		//Example: operation = "ADD"	operand1 = "A"	operand2 = "B"	operand3 = "0"

	}
}

SIM::~SIM()
{
	delete SIM_IM, SIM_DM, Instr_ADD, Instr_SUB, Instr_MUL, Instr_LARGER, 
		Instr_LESS, Instr_EQUAL, Instr_ASSIGN, Instr_NEG, Instr_READ;
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
	else if (S == "HALT")
		OperationNumber = 13;
	else 
		OperationNumber = 100;		//What kind of sorcery is this!

	return OperationNumber;		

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