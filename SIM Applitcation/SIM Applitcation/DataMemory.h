#include <string>
#include <vector>
#include <iostream>

#define DATAMEMORY_H
#if defined DATAMEMORY_H

struct variable
{
	std::string name;
	int value = 0;
};

class DM
{
private:
	std::vector<variable> MemoryBank;

public:
	DM();
	void DisplayDM();
	int ReadFromDataMemory(std::string);
	void WriteToDataMemory(std::string, int);
	//ReadFromDataMemory
	//WriteToDataMemory
	~DM();
};

#endif