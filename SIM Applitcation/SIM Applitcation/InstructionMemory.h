#include <string>
#include <vector>
#define INSTRUCTIONMEMORY_H
#if defined INSTRUCTIONMEMORY_H

class IM
{
private:
	std::vector<std::string> Locations;


public:
	IM();
	void LoadToInstructionMemory(int*, std::string);
	std::string LoadFromInstructionMemory(int*);
	//LoadToInstructionMemory
	//ReadFromInstructionMemory
	//AccessToInstructionMemory
	void DisplayIM();
	~IM();
};

#endif

