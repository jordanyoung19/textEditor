#include "moveCursorUp.hpp"
#include "EditorException.hpp"

void moveCursorUp::execute(EditorModel& model)
{
	currX = model.cursorColumn();
	currY = model.cursorLine();

	if (currY == 1)
	{
		throw(EditorException("top of text"));
	}
	else if (currX > model.line(currY - 1).length())
	{
		int newY = currY - 1;
		int newX = model.line(currY - 1).length() + 1;
		model.setCursorColumn(newX);
		model.setCursorLine(newY);
	}
	else
	{
		int newY = currY - 1;
		model.setCursorColumn(currX);
		model.setCursorLine(newY);
	}
}

void moveCursorUp::undo(EditorModel& model)
{
	model.setCursorColumn(currX);
	model.setCursorLine(currY);
}