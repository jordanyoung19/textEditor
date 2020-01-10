#include "backspace.hpp"
#include "EditorException.hpp"
#include "BooEditLog.hpp"

void backspace::execute(EditorModel& model)
{
	currX = model.cursorColumn();
	currY = model.cursorLine();
	prevLine = model.line(currY);

	if (currX == 1 and currY == 1)
	{
		throw(EditorException("nothing to delete"));
	}
	else if (currX == 1)
	{
		prevLineUp = model.line(currY - 1);
		std::string newLine = prevLineUp + prevLine;
		int newX = model.line(currY - 1).length() + 1;
		int newY = currY - 1;
		tempSwitch = 1;

		booEditLog("reaching here");

		model.setLine(currY - 1, newLine);
		model.removeLine(currY);
		model.subtractFromLineCount();
		model.setCursorColumn(newX);
		model.setCursorLine(newY);
	}
	else
	{
		std::string prevPart = prevLine.substr(0, currX-2);
		std::string endPart = prevLine.substr(currX - 1, prevLine.length());
		std::string newLine = prevPart + endPart;
		int newX = currX - 1;
		tempSwitch = 0;

		model.setLine(currY, newLine);
		model.setCursorColumn(newX);
	}
}

void backspace::undo(EditorModel& model)
{
	if (tempSwitch == 0)
	{
		model.setLine(currY, prevLine);
		model.setCursorColumn(currX);
	}
	else if (tempSwitch == 1)
	{
		model.addNewLine(currY - 1);
		model.addToLineCount();
		model.setLine(currY - 1, prevLineUp);
		model.setLine(currY, prevLine);
		model.setCursorColumn(currX);
		model.setCursorLine(currY);
	}
}