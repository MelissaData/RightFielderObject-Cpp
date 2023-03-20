#include<iostream>
#include <string>

#include "mdRightFielder.h"
#include "DataContainer.h"

using namespace std;

#ifndef RIGHTFIELDER_H
#define RIGHTFIELDER_H

class RightFielderObject
{
public:
	// Path to Right Fielder Object data files (.dat, etc)
	string dataFilePath;

	// Create instance of Melissa Right Fielder Object
	mdRightFielder* mdRightFielderObj = new mdRightFielder;

	RightFielderObject(string license, string dataPath);

	// This will call the lookup function to process the input as well as generate the result codes
	void ExecuteObjectAndResultCodes(DataContainer& data);
};

#endif
