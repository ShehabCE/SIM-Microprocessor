#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#define INSTRUCTIONMEMORY_H
#if defined INSTRUCTIONMEMORY_H

class IM
{
private:
	std::vector<std::string> Locations;


public:
	IM();
	void Inject_To_InstructionMemory(int*, std::string);
	std::string LoadFromInstructionMemory(int);
	//LoadToInstructionMemory
	//ReadFromInstructionMemory
	//AccessToInstructionMemory
	void DisplayIM();
	~IM();
};

#endif

