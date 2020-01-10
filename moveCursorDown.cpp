#include "moveCursorDown.hpp"
#include "EditorException.hpp"

void moveCursorDown::execute(EditorModel& model)
{
	currX = model.cursorColumn();
	currY = model.cursorLine();

	if (currY == model.getLinesSize())
	{
		throw(EditorException("bottom of text"));
	}
	else if (currX > model.line(currY + 1).length())
	{
		int newY = currY + 1;
		int newX = model.line(currY + 1).length() + 1;
		model.setCursorColumn(newX);
		model.setCursorLine(newY);
	}
	else
	{
		int newY = currY + 1;
		model.setCursorColumn(currX);
		model.setCursorLine(newY);
	}
}

void moveCursorDown::undo(EditorModel& model)
{
	model.setCursorLine(currY);
	model.setCursorColumn(currX);
}