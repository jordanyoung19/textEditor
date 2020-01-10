#include "cursorEnd.hpp"

void cursorEnd::execute(EditorModel& model)
{
	currX = model.cursorColumn();
	currY = model.cursorLine();

	int newX = model.line(currY).length() + 1;

	model.setCursorColumn(newX);
	model.setCursorLine(currY);
}

void cursorEnd::undo(EditorModel& model)
{
	model.setCursorColumn(currX);
	model.setCursorLine(currY);
}