#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#define INSTRUCTIONMEMORY_H
#if defined INSTRUCTIONMEMORY_H

class IM
{
private:
	int PC;
	std::vector<std::string> Locations;
public:
	IM();
	void Inject_To_InstructionMemory(std::string);
	std::string LoadFromInstructionMemory(int);
	int GetPC();
	void DisplayIM();
	~IM();
};

#endif

