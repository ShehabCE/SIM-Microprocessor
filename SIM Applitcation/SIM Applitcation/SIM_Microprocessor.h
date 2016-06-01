#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <regex>

#include "InstructionMemory.h"
#include "DataMemory.h"

#define SIM_MICROPROCESSOR_H
#if defined SIM_MICROPROCESSOR_H


class SIM : public IM, public DM
{
	//int *InstructionMemory = new int[1024];
	//variable DataMemory[1024];

public:
	SIM();
	void ReadFile();
	~SIM();
};



#endif