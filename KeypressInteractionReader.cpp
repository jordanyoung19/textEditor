// KeypressInteractionReader.cpp
//
// ICS 45C Fall 2019
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "moveCursorRight.hpp"
#include "moveCursorLeft.hpp"
#include "moveCursorUp.hpp"
#include "moveCursorDown.hpp"
#include "insertChar.hpp"
#include "newLine.hpp"
#include "cursorHome.hpp"
#include "cursorEnd.hpp"
#include "deleteLine.hpp"
#include "backspace.hpp"
#include "BooEditLog.hpp"


// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    while (true)
    {
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            //booEditLog("tester");
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
            case 'X':
                return Interaction::quit();
            case 'Z':
                return Interaction::undo();
            case 'A':
                return Interaction::redo();
            case 'O':
                //booEditLog("tester 2");
                return Interaction::command(new moveCursorRight());
            case 'U':
                return Interaction::command(new moveCursorLeft());
            case 'J':
                return Interaction::command(new newLine());
            case 'M':
                return Interaction::command(new newLine());
            case 'I':
                return Interaction::command(new moveCursorUp());
            case 'K':
                return Interaction::command(new moveCursorDown());
            case 'Y':
                return Interaction::command(new cursorHome());
            case 'P':
                return Interaction::command(new cursorEnd());
            case 'D':
                return Interaction::command(new deleteLine());
            case 'H':
                return Interaction::command(new backspace());
            }
        }
        else
        {
            // The user pressed a normal key (e.g., 'h') without holding
            // down Ctrl; react accordingly
            booEditLog("test");
            return Interaction::command(new insertChar(keypress.code()));
        }
    }
}

