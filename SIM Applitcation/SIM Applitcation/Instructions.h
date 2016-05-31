#include <string>
#define INSTRUCTIONS_H
#if defined INSTRUCTIONS_H


//An abstract class with all possible (undefined) functionality of an instruction.
//Each derived class will inherit from that abstract class and redefine the methods inside to express certain functionality.
class InstructionType
{
private:
	int operand1, operand2, operand3;
	std::string Variable_name;
	int result;
	int JumpAddress;
public:
	virtual void perform() = 0;
	virtual void WriteToDataMemory(int) = 0;
	virtual int ReadFromDataMemory(std::string) = 0;
	virtual int ReadFromInstructionMemory(std::string) = 0;
};

class ADD : public InstructionType
{};
class MUL : public InstructionType
{};
class SUB : public InstructionType
{};
class NEG : public InstructionType
{};
class JUMP : public InstructionType
{};
class JUMP0 : public InstructionType
{};
class ASSIGN : public InstructionType
{};
class LESS : public InstructionType
{};
class LARGER : public InstructionType
{};
class ISEQUAL : public InstructionType
{};
class READ : public InstructionType
{};
class WRITE : public InstructionType
{};
//HALT is a bit useless here. Keep it for the time being.
class HALT : public InstructionType
{};
#endif