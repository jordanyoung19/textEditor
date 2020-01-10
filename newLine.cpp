#include "newLine.hpp"
#include "BooEditLog.hpp"

void newLine::execute(EditorModel& model)
{
	currX = model.cursorColumn();
	currY = model.cursorLine();
	int newX;
	int newY;

	// if cursor is at beginning of line
	if (currX == 1)
	{
		model.addNewLine(currY - 1);
		newX = 1;
		newY = currY + 1;
	}
	// if cursor is at end of line
	else if (currX == model.line(currY).length() + 1)
	{
		model.addNewLine(currY);
		newX = 1;
		newY = currY + 1;
	}
	// if cursor is anywhere in the middle of the line
	else
	{
		prevLine = model.line(currY);
		std::string prevPart = prevLine.substr(0, currX-1);
		std::string endPart = prevLine.substr(currX - 1, prevLine.length());
		model.addNewLine(currY - 1);
		model.setLine(currY, prevPart);
		model.setLine(currY + 1, endPart);
		newX = 1;
		newY = currY +1;
	}

	model.addToLineCount();
	model.setCursorColumn(newX);
	model.setCursorLine(newY);
}

void newLine::undo(EditorModel& model)
{
	booEditLog("test: ");
	booEditLog(std::to_string(currY));
	model.setLine(currY, prevLine);
	model.removeLine(currY);
	model.setCursorColumn(currX);
	model.setCursorLine(currY);
	model.subtractFromLineCount();
}