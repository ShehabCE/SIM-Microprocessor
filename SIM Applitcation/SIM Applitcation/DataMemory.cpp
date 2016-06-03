#include "DataMemory.h"

DM::DM(): DataMemory_Pointer(0)
{
	MemoryBank.resize(1025);
};

void DM::DisplayDM()
{
	for (int i = 0; i < 1024; i++)
	{
		if (!(MemoryBank[i].name.empty()))
			std::cout << i << ") " << MemoryBank[i].name << " = " << MemoryBank[i].value << std::endl;
	}
};

int DM::ReadFromDataMemory(std::string S)
{
	for (int i = 0; i < 1024; i++)
	{
		if (MemoryBank[i].name == S)
			return MemoryBank[i].value;
	}
}

bool DM::CheckVariableInDM(std::string A)
{
	for (int i = 0; i < 1024; i++)
	{
		if (MemoryBank[i].name == A)
			return true;
	}
	return false;		//No variable found in DataMemory
}

void DM::WriteToDataMemory(std::string X, int Y)
{
	if (DataMemory_Pointer < 1024)
	{
		if (CheckVariableInDM(X) == false)		//Add a new slot.
		{
			MemoryBank[DataMemory_Pointer].name = X;
			MemoryBank[DataMemory_Pointer].value = Y;
			DataMemory_Pointer++;
		}
		else
		{
			OverwriteVariable(X, Y);

		}
	}
	else
		std::cerr << "Data Memory is full! Cannot add new variable." << std::endl;
}

void DM::OverwriteVariable(std::string var, int val)
{
	for (int i = 0; i < 1024; i++)
	{
		if (MemoryBank[i].name == var)
			MemoryBank[i].value = val;
	}
}

DM::~DM()
{
	MemoryBank.shrink_to_fit();		//Force Vector MemoryBack to release memory upon object destruction. 
};