#pragma once

#include "Card.h"
#include <fstream>

class CardFour :	public Card
{
	
public:
	CardFour(const CellPosition & pos); // A Constructor takes card position
	CardFour(); // A Default Constructor 
	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of CardOne which is: walletAmount
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	                                                  // by decrementing the player's wallet by the walletAmount data member
	virtual void Save(ofstream &OutFile, Type gameObject);// Saves the GameObject parameters to the file
	virtual void Load(ifstream& Infile); // Loads and Reads the GameObject parameters from the file
	virtual ~CardFour(); // A Virtual Destructor
};