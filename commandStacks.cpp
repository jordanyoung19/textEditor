#include "commandStacks.hpp"
#include "BooEditLog.hpp"

commandStack::commandStack()
{
}

void commandStack::addToStack(Command* command)
{
	comStack.push(command);
}

Command* commandStack::getTopOfStack()
{
	Command* lastCommand = comStack.top();
	comStack.pop();

	return lastCommand;
}
