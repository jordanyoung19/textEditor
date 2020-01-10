#include "insertChar.hpp"
#include "BooEditLog.hpp"

insertChar::insertChar(char c)
	: c{c}
{
}

void insertChar::execute(EditorModel& model)
{
	currX = model.cursorColumn();
	currY = model.cursorLine();
	prevLine = model.line(currY);
	std::string newLine = "";
	int newX = currX + 1;


	// int endOfLine = model.line(currY).length() + 1;
	if (currX == model.line(currY).length() + 1)
	{
		std::string newLine = prevLine + c;
		booEditLog("first");
		booEditLog(newLine);
		model.setLine(currY, newLine);
		model.setCursorColumn(newX);
		//int newX = currX + 1;
	}
	else
	{
		std::string prevPart = prevLine.substr(0, currX-1);
		std::string endPart = prevLine.substr(currX - 1, prevLine.length());
		std::string newLine = prevPart + c + endPart;
		model.setLine(currY, newLine);
		model.setCursorColumn(newX);
		booEditLog("second");
		booEditLog(newLine);
		//int newX = currX + 1;
	}

	// model.setNewLine(currY, newLine);
	// model.setCursorColumn(newX);
}

void insertChar::undo(EditorModel& model)
{
	model.setLine(currY, prevLine);
	model.setCursorColumn(currX);
}