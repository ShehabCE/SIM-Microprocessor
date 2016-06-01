#include "InstructionMemory.h"
#include <iostream>

IM::IM() 
{
	Locations.resize(1025);
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
			std::cout << i << "| " << Locations[i] << std::endl;
	}
}

IM::~IM()
{};