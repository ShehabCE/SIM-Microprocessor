#include <string>
#include <vector>
#define INSTRUCTIONMEMORY_H
#if defined INSTRUCTIONMEMORY_H

class IM
{
private:
	int InstructionCount = 0;
	std::vector<std::string> Locations;


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

