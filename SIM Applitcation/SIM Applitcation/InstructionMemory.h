#include <string>
#define INSTRUCTIONMEMORY_H
#if defined INSTRUCTIONMEMORY_H

class IM
{
protected:
	int address;
	int InstructionCount;
	std::string Locations[1024];


public:
	IM();
	void LoadToInstructionMemory(std::string);
	//LoadToInstructionMemory
	//ReadFromInstructionMemory
	//AccessToInstructionMemory
	void DisplayIM();
	~IM();
};

#endif

