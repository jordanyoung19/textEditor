// InteractionProcessor.cpp
//
// ICS 45C Fall 2019
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"
#include "commandStacks.hpp"
#include "BooEditLog.hpp"


// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    view.refresh();
    commandStack undoStack = commandStack();
    commandStack redoStack = commandStack();

    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();
        if (interaction.type() == InteractionType::quit)
        {
            //testing here
            // for (int i = 1; i != undoStack.comStack.size(); i++)
            // {
            //     delete undoStack.getTopOfStack();
            // }
            //booEditLog(undoStack.comStack[0]);

            break;
        }
        else if (interaction.type() == InteractionType::undo)
        {
            if (undoStack.comStack.size() > 0)
            {
                Command* tempCommand = undoStack.getTopOfStack();
                tempCommand->undo(model);
                redoStack.addToStack(tempCommand);
            }
            view.refresh();
        }
        else if (interaction.type() == InteractionType::redo)
        {
            if (redoStack.comStack.size() > 0)
            {
                // come back here later
                Command* tempCommand = redoStack.getTopOfStack();
                tempCommand->execute(model);
                undoStack.addToStack(tempCommand);
                //delete tempCommand;
            }
            view.refresh();
        }
        else if (interaction.type() == InteractionType::command)
        {
            Command* command = interaction.command();

            try
            {
                command->execute(model);
                undoStack.addToStack(command);
                model.clearErrorMessage();
            }
            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.

            //delete command;
        }
    }
}

