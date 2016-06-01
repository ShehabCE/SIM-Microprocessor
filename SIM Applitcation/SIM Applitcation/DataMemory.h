#include <string>

#define DATAMEMORY_H
#if defined DATAMEMORY_H

struct variable
{
	std::string name = NULL;
	int value = 0;
};

class DM
{
protected:
	int address;
	variable MemoryBank[1024];


public:
	//ReadFromDataMemory
	//WriteToDataMemory
};

#endif