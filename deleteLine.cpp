#include "deleteLine.hpp"
#include "BooEditLog.hpp"

void deleteLine::execute(EditorModel& model)
{
	currX = model.cursorColumn();
	currY = model.cursorLine();

	deletedLine = model.line(currY);

	if (model.getLinesSize() == 1)
	{
		int newX = 1;
		int newY = 1;

		model.setLine(currY, "");
		model.setCursorColumn(newX);
		model.setCursorLine(newY);
	}
	else if (currY == model.getLinesSize())
	{
		int newX = 1;

		model.setLine(currY, "");
		model.setCursorLine(currY);
		model.setCursorColumn(newX);
	}
	else if (currX > model.line(currY + 1).length())
	{
		int newX = model.line(currY + 1).length() + 1;

		model.removeLine(currY);

		model.setCursorColumn(newX);
		model.setCursorLine(currY);
		model.subtractFromLineCount();
	}
	else
	{
		model.removeLine(currY);
		model.subtractFromLineCount();
	}

	//model.removeLine(currY);

}

// problem of adding new line when line before didn't remove a line
void deleteLine::undo(EditorModel& model)
{
	model.addNewLine(currY - 1);
	model.addToLineCount();
	model.setLine(currY, deletedLine);
	model.setCursorColumn(currX);
	model.setCursorLine(currY);
}