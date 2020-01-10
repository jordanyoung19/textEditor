#ifndef MOVECURSORLEFT_HPP
#define MOVECURSORLEFT_HPP

#include "Command.hpp"

class moveCursorLeft : public Command
{
public:
	void execute(EditorModel& model) override;
	void undo(EditorModel& model) override;

private:
	int currX;
	int currY;
};


#endif