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
	int InstructionsCount;
	ADD *Instr_ADD = new ADD();
	SUB *Instr_SUB = new SUB();
	MUL *Instr_MUL = new MUL();
	LESS *Instr_LESS = new LESS();
	LARGER *Instr_LARGER = new LARGER();
	ISEQUAL *Instr_EQUAL = new ISEQUAL();
	NEG *Instr_NEG = new NEG();
	ASSIGN *Instr_ASSIGN = new ASSIGN();
	READ *Instr_READ = new READ();


public:
	SIM();
	void ReadFile();
	void Execute();
	~SIM();
};
#endif