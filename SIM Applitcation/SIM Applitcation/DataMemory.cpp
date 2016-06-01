#include "DataMemory.h"

DM::DM()
{
	MemoryBank.resize(1025);
};

void DM::DisplayDM()
{

};

DM::~DM()
{
	for (int i = 0; i < 1024; i++)
	{
		if (!(MemoryBank[i].name.empty()))
			std::cout << i << ") " << MemoryBank[i].name << " = " << MemoryBank[i].value << std::endl;
	}
};