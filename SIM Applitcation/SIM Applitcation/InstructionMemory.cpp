#include "InstructionMemory.h"

IM::IM() 
{
	Locations.resize(1025);
};

void IM::Inject_To_InstructionMemory(int* index, std::string instr)
{
	Locations[*index] = instr;
}

std::string IM::LoadFromInstructionMemory(int index)
{
	if(!(Locations[index].empty()))
		return Locations[index];		//Making sure it returns an actual instruction.
}

void IM::DisplayIM()
{
	std::cout << "----------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < 1024; i++)
	{
		if (!(Locations[i].empty()))
			std::cout << i << "| " << std::setprecision(5) << std::fixed << Locations[i] << std::endl;
	}
	std::cout << "----------------------------------------------------------------------------" << std::endl;
}

IM::~IM()
{};