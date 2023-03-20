#include "RightFielderObject.h"

RightFielderObject::RightFielderObject(string license, string dataPath)
{
	// Set license string and set path to datafiles (.dat, etc)
	mdRightFielderObj->SetLicenseString(license.c_str());
	dataFilePath = dataPath;

	// If you see a different date than expected, check your license string and either download the new data files or use the Melissa Updater program to update your data files.  
	mdRightFielderObj->SetPathToRightFielderFiles(dataFilePath.c_str());
	mdRightFielder::ProgramStatus pStatus = mdRightFielderObj->InitializeDataFiles();

	if (pStatus != mdRightFielder::NoError)
	{
		cout << "Failed to Initialize Object." << endl;
		cout << pStatus << endl;
		return;
	}

	cout << "                 DataBase Date: " + string(mdRightFielderObj->GetDatabaseDate()) << endl;
	cout << "               Expiration Date: " + string(mdRightFielderObj->GetLicenseExpirationDate()) << endl;

	/**
	 * This number should match with the file properties of the Melissa Object binary file.
	 * If TEST appears with the build number, there may be a license key issue.
	 */
	cout << "                Object Version: " + string(mdRightFielderObj->GetBuildNumber()) << endl;
}

// This will call the lookup function to process the input as well as generate the result codes
void RightFielderObject::ExecuteObjectAndResultCodes(DataContainer& data)
{
	// These are the configuarble pieces of the Right Fielder Object. We are setting what kind of information we want to be looked up
	// SetUserPattern Method - Ex. Social Security Number

	//mdRightFielder.SetUserPattern("SSN", "[0-9]{3}-[0-9]{2}-[0-9]{4}");
	mdRightFielderObj->Parse(data.Input);
	data.ResultCodes = mdRightFielderObj->GetResults();

	// ResultsCodes explain any issues Right Fielder Object has with the object.
	// List of result codes for Right Fielder Object
	// https://wiki.melissadata.com/?title=Result_Code_Details#RightFielder_Object
}
