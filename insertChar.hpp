#ifndef INSERTCHAR_HPP
#define INSERTCHAR_HPP

#include "Command.hpp"
#include <string>

class insertChar: public Command
{
public:
	insertChar(char c);

	void execute(EditorModel& model) override;
	void undo(EditorModel& model) override;

private:
	std::string prevLine;
	char c;
	int currX;
	int currY;
};

#endif