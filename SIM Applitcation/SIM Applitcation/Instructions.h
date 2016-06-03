#include <string>
#define INSTRUCTIONS_H
#if defined INSTRUCTIONS_H


//An abstract class with all possible (undefined) functionality of an instruction.
//Each derived class will inherit from that abstract class and redefine the methods inside to express certain functionality.
class InstructionType 
{
protected:
	int operand1, operand2, operand3;
	std::string Variable_name;
	int result;
	int JumpAddress;
public:
	virtual void perform() = 0;
	//virtual void WriteToDataMemory(int) = 0;
	//virtual int ReadFromDataMemory(std::string) = 0;
	//virtual int ReadFromInstructionMemory(std::string) = 0;
};

class ADD 
{
private:
	std::string in1, in2, out;
	int result;
public:
	ADD();
	int Perform(std::string, std::string);
	~ADD();
};

class MUL 
{
private:
	std::string in1, in2, out;
	int result;
public:
	MUL();
	int Perform(std::string, std::string);
	~MUL();
};

class SUB 
{
private:
	std::string in1, in2, out;
	int result;
public:
	SUB();
	int Perform(std::string, std::string);
	~SUB();
};
class NEG 
{
private:
	std::string in1, out;
	int result;
public:
	NEG();
	~NEG();
};
class JMP 
{};
class JMP0 
{};
class ASSIGN 
{};
class LESS 
{};
class LARGER 
{};
class ISEQUAL 
{};
class READ 
{};
class WRITE
{};
#endif