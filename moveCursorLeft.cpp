#include "moveCursorLeft.hpp"
#include "EditorException.hpp"
#include "BooEditLog.hpp"

void moveCursorLeft::execute(EditorModel& model)
{
	currX = model.cursorColumn();
	currY = model.cursorLine();

	if (currX == 1 and currY == 1)
	{
		throw(EditorException("top of text"));
	}
	else if (currX == 1)
	{
		if (model.line(currY - 1).length() == 0)
		{
			int newX = 1;
			int newY = currY - 1;
			model.setCursorLine(newY);
			model.setCursorColumn(newX);
		}
		else
		{	
			int newX = model.line(currY - 1).length() + 1;
			int newY = currY - 1;
			model.setCursorLine(newY);
			model.setCursorColumn(newX);
		}
	}
	else
	{
		int newX = currX - 1;
		model.setCursorColumn(newX);
		model.setCursorLine(currY);
	}
}

void moveCursorLeft::undo(EditorModel& model)
{
	model.setCursorColumn(currX);
	model.setCursorLine(currY);
}