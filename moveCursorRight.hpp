#ifndef MOVECURSORRIGHT_HPP
#define MOVECURSORRIGHT_HPP

#include "Command.hpp"

class moveCursorRight : public Command
{
public:
	void execute(EditorModel& model) override;
	void undo(EditorModel& model) override;

private:
	int currX;
	int currY;
};

#endif