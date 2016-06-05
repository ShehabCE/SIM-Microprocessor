#include "Instructions.h"

ADD::ADD()
{};
int ADD::Perform(int in1, int in2)
{
	result = in1 + in2;
	return result;
}
ADD::~ADD()
{};
///////////////////////////////////////////////////////////
MUL::MUL()
{};
int MUL::Perform(int in1, int in2)
{
	result = in1*in2;
	return result;
}
MUL::~MUL()
{};
///////////////////////////////////////////////////////////
SUB::SUB()
{};
int SUB::Perform(int in1, int in2)
{
	result = in1 - in2;
	return result;
}
SUB::~SUB()
{};
///////////////////////////////////////////////////////////
NEG::NEG()
{};
int NEG::Perform(int in1)
{
	result = in1*-1;
	return result;
}
NEG::~NEG()
{};
///////////////////////////////////////////////////////////
ASSIGN::ASSIGN()
{};
int ASSIGN::Perform(int in1)
{
	return result;
}
ASSIGN::~ASSIGN()
{};
///////////////////////////////////////////////////////////
LESS::LESS()
{};

int LESS::Perform(int in1, int in2)
{
	if (in1 < in2)
		result = 1;
	else
		result = 0;
	return result;

}
LESS::~LESS()
{};
///////////////////////////////////////////////////////////
LARGER::LARGER()
{};

int LARGER::Perform(int in1, int in2)
{
	if (in1 > in2)
		result = 1;
	else
		result = 0;
	return result;
}
LARGER::~LARGER()
{};

///////////////////////////////////////////////////////////
ISEQUAL::ISEQUAL()
{};

int ISEQUAL::Perform(int in1, int in2)
{
	if (in1 == in2)
		result = 1;
	else
		result = 0;
	return result;
}

ISEQUAL::~ISEQUAL()
{};
///////////////////////////////////////////////////////////
READ::READ()
{};

int READ::Perform(std::string var)
{
	std::cout << var << " = ";
	std::cin >> result;
	return (int)result;
}
READ::~READ()
{};