#include "InstructionMemory.h"

IM::IM(): PC(0)
{
	Locations.resize(1024);
};

void IM::Inject_To_InstructionMemory(std::string instr)
{
	if (PC < 1024)
	{
		Locations[PC] = instr;
		PC++;
	}
	else
		std::cerr << "**ERROR: Instruction Memory full! Cannot add more instructions." << std::endl;

}

std::string IM::LoadFromInstructionMemory(int index)
{
	if (index < 1024)
	{
		if (!(Locations[index].empty()))
			return Locations[index];		//Making sure it returns an actual instruction.
	}
	std::cerr << "**ERROR: index of Instruction Memory went out of range!." << std::endl;
}

int IM::GetPC()
{
	return PC;
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
{
	Locations.shrink_to_fit();		//Forcing to release memory allocated to vector.
};