#include <string>
#include <iostream>
#define INSTRUCTIONS_H
#if defined INSTRUCTIONS_H


//An abstract class with all possible (undefined) functionality of an instruction.
//Each derived class will inherit from that abstract class and redefine the methods inside to express certain functionality.
//class InstructionType 
//{
//protected:
//	int operand1, operand2, operand3;
//	std::string Variable_name;
//	int result;
//	int JumpAddress;
//public:
//	virtual void perform() = 0;
//	//virtual void WriteToDataMemory(int) = 0;
//	//virtual int ReadFromDataMemory(std::string) = 0;
//	//virtual int ReadFromInstructionMemory(std::string) = 0;
//};

class ADD 
{
private:
	int result;
public:
	ADD();
	int Perform(int, int);
	~ADD();
};

class MUL 
{
private:
	int result;
public:
	MUL();
	int Perform(int, int);
	~MUL();
};

class SUB 
{
private:
	int result;
public:
	SUB();
	int Perform(int, int);
	~SUB();
};

class NEG 
{
private:
	int result;
public:
	NEG();
	int Perform(int);
	~NEG();
};/*
class JMP 
{
private:
	int PC_Address;
public:
	JMP();
	std::string Perform(int);
	~JMP();
};
class JMP0 
{
private:
	int PC_Address;
public:
	JMP0();
	std::string Perform(int, int);
	~JMP0();
};*/
class ASSIGN 
{
private:
	int result;
public:
	ASSIGN();
	int Perform(int);
	~ASSIGN();
};
class LESS 
{
private:
	int result;
public:
	LESS();
	int Perform(int, int);
	~LESS();
};
class LARGER 
{
private:
	int result;
public:
	LARGER();
	int Perform(int, int);
	~LARGER();

};
class ISEQUAL 
{
private:
	int result;
public:
	ISEQUAL();
	int Perform(int, int);
	~ISEQUAL();
};
class READ 
{
private:
	int result;
public:
	READ();
	int Perform(std::string);
	~READ();

};
#endif