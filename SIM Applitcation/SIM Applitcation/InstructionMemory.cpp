#include "InstructionMemory.h"
#include <iostream>

IM::IM() 
{
	InstructionCount = 0;
};

void IM::LoadToInstructionMemory(std::string instr)
{
	Locations[InstructionCount] = instr;
	InstructionCount++;
}

void IM::DisplayIM()
{
	for (int i = 0; i <= InstructionCount; i++)
	{
		if (!(Locations[i].empty()))
			std::cout << Locations[i] << std::endl;
	}
}

IM::~IM()
{};