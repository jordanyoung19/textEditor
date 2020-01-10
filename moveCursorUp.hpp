#ifndef MOVECURSORUP_HPP
#define MOVECURSORUP_HPP

#include "Command.hpp"

class moveCursorUp : public Command
{
public:
	void execute(EditorModel& model) override;
	void undo(EditorModel& model) override;

private:
	int currX;
	int currY;
};

#endif

