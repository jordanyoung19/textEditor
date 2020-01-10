// EditorModel.cpp
//
// ICS 45C Fall 2019
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"
#include "BooEditLog.hpp"


EditorModel::EditorModel()
{
	currentCursorLine = 1;
	currentCursorColumn = 1;
	currentLineCount = 1;
	lines.push_back("");
	errorReport = "";
}


int EditorModel::cursorLine() const
{
    return currentCursorLine;
}


int EditorModel::cursorColumn() const
{
    return currentCursorColumn;
}


int EditorModel::lineCount() const
{
    return currentLineCount;
}


const std::string& EditorModel::line(int lineNumber) const
{
    static std::string line;
    line = lines.at(lineNumber - 1);
    return line;
}


const std::string& EditorModel::currentErrorMessage() const
{
    static std::string error;
    error = errorReport;
    return error;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
	errorReport = errorMessage;
}


void EditorModel::clearErrorMessage()
{
	errorReport = "";
}


void EditorModel::setCursorColumn(int col)
{
	currentCursorColumn = col;
}

void EditorModel::setCursorLine(int line)
{
	currentCursorLine = line;
}

void EditorModel::setLine(int line, std::string newLine)
{
	booEditLog(newLine);
	lines.at(line - 1) = newLine;
	booEditLog(lines.at(line - 1));
}

void EditorModel::addNewLine(int line)
{
	// finish off working here
	lines.insert(lines.begin() + line, "");
	//booEditLog(std::to_string(lines.size()));
	//booEditLog(lines.back());
}

void EditorModel::removeLine(int line)
{
	lines.erase(lines.begin() + line - 1);
}

void EditorModel::addToLineCount()
{
	currentLineCount = currentLineCount + 1;
}

void EditorModel::subtractFromLineCount()
{
	currentLineCount = currentLineCount - 1;
}

int EditorModel::getLinesSize()
{
	return lines.size();
}