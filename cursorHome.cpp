#include "cursorHome.hpp"

void cursorHome::execute(EditorModel& model)
{
	currX = model.cursorColumn();
	currY = model.cursorLine();

	int newX = 1;

	model.setCursorColumn(newX);
	model.setCursorLine(currY);
}

void cursorHome::undo(EditorModel& model)
{
	model.setCursorColumn(currX);
	model.setCursorLine(currY);
}