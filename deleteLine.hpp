#ifndef DELETELINE_HPP
#define DELETELINE_HPP

#include "Command.hpp"
#include <string>

class deleteLine : public Command
{
public:
	void execute(EditorModel& model) override;
	void undo(EditorModel& model) override;

private:
	int currX;
	int currY;
	std::string deletedLine;
};

#endif