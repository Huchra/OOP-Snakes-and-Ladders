#pragma once

#include "Action.h"

class EditCardAction : public Action
{           
	Card* CardCheck;
	bool CheckEdit;

public:
	EditCardAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~EditCardAction();
};


