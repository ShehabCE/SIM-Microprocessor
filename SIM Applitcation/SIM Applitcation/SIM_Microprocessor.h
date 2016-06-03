#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <regex>

#include "InstructionMemory.h"
#include "DataMemory.h"
#include "Instructions.h"

#define SIM_MICROPROCESSOR_H
#if defined SIM_MICROPROCESSOR_H


class SIM 
{
private:
						//Note to self. Initiliazed in constructor won't affect in actual objects when using it in methods.
	IM *SIM_IM = new IM();
	DM *SIM_DM = new DM();
	int count = 0;
	int *InstructionCount = &count;
	//std::string InstrEntry[];
	//int *InstructionMemory = new int[1024];
	//variable DataMemory[1024];
public:
	SIM();
	void ReadFile();
	void Execute();
	~SIM();
};
#endif