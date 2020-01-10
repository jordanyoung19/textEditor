#include "moveCursorRight.hpp"
#include "BooEditLog.hpp"
#include "EditorException.hpp"

void moveCursorRight::execute(EditorModel& model)
{
	currX = model.cursorColumn();
	currY = model.cursorLine();
	int endOfLine = model.line(currY).length() + 1;

	if (currX == endOfLine and currY == model.lineCount())
	{
		throw(EditorException("end of text"));
	}
	else if (currX == endOfLine)
	{
		int newX = 1;
		int newY = currY + 1;
		model.setCursorLine(newY);
		model.setCursorColumn(newX);
	}
	else
	{
		int newX = currX + 1;
		model.setCursorColumn(newX);
		model.setCursorLine(currY);
	}
}

void moveCursorRight::undo(EditorModel& model)
{
	//currently working here
	model.setCursorColumn(currX);
	model.setCursorLine(currY);
}

