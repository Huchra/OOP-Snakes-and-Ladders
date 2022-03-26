#pragma once

#include "Card.h"
#include <fstream>

// [ CardOne ] Summary:
// Its Apply() Function: Decrements the value of the passing player�s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class CardTwo :	public Card
{
	// CardOne Parameters:
	int walletAmount; // the wallet value to decrease from the player

public:
	CardTwo(const CellPosition & pos); // A Constructor takes card position
	CardTwo(); // A Default Constructor 
	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	                                                  // by decrementing the player's wallet by the walletAmount data member
   virtual void Save(ofstream &OutFile, Type gameObject);// Saves the GameObject parameters to the file
   virtual void Load(ifstream& Infile); // Loads and Reads the GameObject parameters from the file

	virtual ~CardTwo(); // A Virtual Destructor
};