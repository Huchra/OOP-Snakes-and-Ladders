#include "CardThree.h"
#include "Ladder.h"

CardThree::CardThree(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (1 here)
}

CardThree::~CardThree()
{
}

CardThree::CardThree()
{
	cardNumber = 3;
}
void CardThree::ReadCardParameters(Grid * pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut ->PrintMessage("New Card Three .Click to continue...");
	int x,y;
	pIn->GetPointClicked(x,y);
	pOut ->ClearStatusBar();

}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid,pPlayer);
	Ladder*ladder=pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition().GetCellNum());
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (ladder==NULL)
	{
	pOut ->PrintMessage("There are no ladders ahead.Click to continue...");
	int x,y;
	pIn->GetPointClicked(x,y);
	pOut ->ClearStatusBar();
		return;
	}
	CellPosition ladderStart =ladder->GetPosition();
	pOut ->PrintMessage("Go to the start of the next ladder.Click to continue...");
	int x,y;
	pIn->GetPointClicked(x,y);
	pOut ->ClearStatusBar();
	pGrid->UpdatePlayerCell(pPlayer,ladderStart);
}
void CardThree::Save(ofstream &OutFile, Type gameObject)
{
	if ( gameObject == Cards )
	{
		OutFile << cardNumber << " " << position.GetCellNum()  << endl;
	}
}

void CardThree::Load(ifstream& Infile)
{
	int  CellposNum;
	Infile >> CellposNum;
	CellPosition Cellpos(CellposNum);
	position = Cellpos;
}
