#ifndef MOVECURSORDOWN_HPP
#define MOVECURSORDOWN_HPP

#include "Command.hpp"

class moveCursorDown : public Command
{
public:
	void execute(EditorModel& model) override;
	void undo(EditorModel& model) override;

private:
	int currX;
	int currY;
};

#endif