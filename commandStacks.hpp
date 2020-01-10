#ifndef COMMANDSTACKS_HPP
#define COMMANDSTACKS_HPP

#include "Command.hpp"
#include <stack>

class commandStack
{
public:
	commandStack();

	Command* getTopOfStack();

	void addToStack(Command* command);

	std::stack<Command*> comStack;

private:
};



#endif