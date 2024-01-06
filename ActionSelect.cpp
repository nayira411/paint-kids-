#include "ActionSelect.h"
/*#include "..\ApplicationManager.h"*/
#include "ApplicationManager.h"

/*#include "..\GUI\GUI.h"*/
#include "GUI/GUI.h"

ActionSelect::ActionSelect(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
//Omar
void ActionSelect::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	int x, y, index=-1;
	pGUI->GetPointClicked(x, y);//double click
	CFigure *figSelected = pManager->GetFigure(x, y, index);
	if (figSelected != NULL)
	{
		if (!(figSelected->IsSelected()))
		{
			
			figSelected->SetSelected(true);
			figSelected->ChngDrawClr(pGUI->getCrntHighlightColor());
			figSelected->ChngFillClr(pGUI->getCrntHighlightColor());
			pManager->UpdateInterface();
			pGUI->ClearStatusBar();
			pGUI->PrintMessage(figSelected->GetInfo());
		}
		else
		{
			figSelected->SetSelected(false);
			figSelected->ChngDrawClr(pGUI->getCrntDrawColor());
			figSelected->ChngFillClr(pGUI->getCrntFillColor());
			pManager->UpdateInterface();
			pGUI->ClearStatusBar();
		}
	}
	
}
