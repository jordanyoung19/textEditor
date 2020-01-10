#ifndef NEWLINE_HPP
#define NEWLINE_HPP

#include "Command.hpp"
#include <string>

class newLine : public Command
{
public:
	void execute(EditorModel& model) override;
	void undo(EditorModel& model) override;

private:
	int currX;
	int currY;
	std::string prevLine;
};

#endif