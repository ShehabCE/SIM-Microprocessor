#include "DataMemory.h"

DM::DM()
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

void DM::WriteToDataMemory(std::string X, int Y)
{

}

DM::~DM()
{};