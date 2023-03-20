#include <iostream>
#include <string>
#include <cstdlib>
#include <list>

#include "mdRightFielder.h"
#include "RightFielderObject.h"
#include "DataContainer.h"

using namespace std;

// function declarations
void ParseArguments(string& license, string& testInput, string& dataPath, int argc, char** argv);
void RunAsConsole(string license, string testInput, string dataPath);
list<string> SplitResultCodes(string s, string delimiter);

int main(int argc, char* argv[])
{
	// Variables
	string license = "";
	string testInput = "";
	string dataPath = "";

	ParseArguments(license, testInput, dataPath, argc, argv);
	RunAsConsole(license, testInput, dataPath);

	return 0;
}

void ParseArguments(string& license, string& testInput, string& dataPath, int argc, char* argv[])
{
	for (int i = 1; i < argc; i++)
	{
		if (string(argv[i]) == "--license" || string(argv[i]) == "-l")
		{
			if (argv[i + 1] != NULL)
			{
				license = argv[i + 1];
			}
		}
		if (string(argv[i]) == "--rfinput" || string(argv[i]) == "-r")
		{
			if (argv[i + 1] != NULL)
			{
				testInput = argv[i + 1];
			}
		}
		if (string(argv[i]) == "--dataPath" || string(argv[i]) == "-d")
		{
			if (argv[i + 1] != NULL)
			{
				dataPath = argv[i + 1];
			}
		}
	}
}

void RunAsConsole(string license, string testInput, string dataPath)
{
	cout << "\n\n======== WELCOME TO MELISSA RIGHT FIELDER OBJECT WINDOWS C++ =======\n" << endl;
	
	RightFielderObject* rightFielderObject = new RightFielderObject(license, dataPath);

	bool shouldContinueRunning = true;

	while (shouldContinueRunning)
	{
		DataContainer dataContainer = DataContainer();

		if (testInput.empty())
		{
			cout << "\nFill in each value to see the Right Fielder Object results" << endl;
			cout << "Right Fielder Input: ";

			string input;
			getline(cin, input);

			strcpy_s(dataContainer.Input, input.c_str());
		}
		else
		{
			strcpy_s(dataContainer.Input, testInput.c_str());
		}

		// Print user input
		cout << "\n============================== INPUTS ==============================\n" << endl;
		cout << "\t   Right Fielder Input: " + string(dataContainer.Input)                 << endl;

		// Execute Right Fielder Object
		rightFielderObject->ExecuteObjectAndResultCodes(dataContainer);

		// Print output
		cout << "\n============================== OUTPUT ==============================\n"                       << endl;
		cout << "\n\tRightFielder Object Information:"                                                           << endl;
		cout << "\t          AddressLine1: " + string(rightFielderObject->mdRightFielderObj->GetAddress())       << endl;
		cout << "\t          AddressLine2: " + string(rightFielderObject->mdRightFielderObj->GetAddress2())      << endl;
		cout << "\t          AddressLine3: " + string(rightFielderObject->mdRightFielderObj->GetAddress3())      << endl;
		cout << "\t                  City: " + string(rightFielderObject->mdRightFielderObj->GetCity())          << endl;
		cout << "\t                 State: " + string(rightFielderObject->mdRightFielderObj->GetState())         << endl;
		cout << "\t                   Zip: " + string(rightFielderObject->mdRightFielderObj->GetPostalCode())    << endl;
		//rightFielderObject->mdRightFielderObj->GetFullNameNext();
		//cout << "\t              FullName: " + string(rightFielderObject->mdRightFielderObj->GetFullName())      << endl;
		//rightFielderObject->mdRightFielderObj->GetDepartmentNext();
		//cout << "\t            Department: " + string(rightFielderObject->mdRightFielderObj->GetDepartment())    << endl;
		//rightFielderObject->mdRightFielderObj->GetCompanyNext();
		//cout << "\t               Company: " + string(rightFielderObject->mdRightFielderObj->GetCompany())       << endl;
		//cout << "\t               Country: " + string(rightFielderObject->mdRightFielderObj->GetCountry())       << endl;
		//cout << "\t              LastLine: " + string(rightFielderObject->mdRightFielderObj->GetLastLine())      << endl;
		//rightFielderObject->mdRightFielderObj->GetPhoneNext();
		//cout << "\t                 Phone: " + string(rightFielderObject->mdRightFielderObj->GetPhone())         << endl;
		//rightFielderObject->mdRightFielderObj->GetPhoneTypeNext();
		//cout << "\t             PhoneType: " + string(rightFielderObject->mdRightFielderObj->GetPhoneType())     << endl;
		//rightFielderObject->mdRightFielderObj->GetEmailNext();
		//cout << "\t                 Email: " + string(rightFielderObject->mdRightFielderObj->GetEmail())         << endl;
		//rightFielderObject->mdRightFielderObj->GetURLNext();
		//cout << "\t                   Url: " + string(rightFielderObject->mdRightFielderObj->GetURL())           << endl;
		//rightFielderObject->mdRightFielderObj->GetUserFieldNext("SSN");
		//cout << "\t             UserField: " + string(rightFielderObject->mdRightFielderObj->GetUserField("SSN"))<< endl;
		//rightFielderObject->mdRightFielderObj->GetUnrecognizedNext();
		//cout << "\t          Unrecognized: " + string(rightFielderObject->mdRightFielderObj->GetUnrecognized())  << endl;
		cout << "\t          Result Codes: " + dataContainer.ResultCodes                                         << endl;

		list<string> rs = SplitResultCodes(dataContainer.ResultCodes, ",");
		list<string>::iterator it;

		for (it = rs.begin(); it != rs.end(); it++)
		{
			printf("        %s: %s", it->c_str(), rightFielderObject->mdRightFielderObj->GetResultCodeDescription(it->c_str(), rightFielderObject->mdRightFielderObj->ResultCodeDescriptionLong));
			cout << endl;
		}

		bool isValid = false;
		if (!testInput.empty()) 
		{
			isValid = true;
			shouldContinueRunning = false;
		}
		while (!isValid)
		{
			string testAnotherResponse;

			cout << "\nTest Right Fielder Again? (Y/N)" << endl;
			getline(cin, testAnotherResponse);

			if (!testAnotherResponse.empty())
			{
				if (testAnotherResponse == "y" || testAnotherResponse == "Y")
				{
					isValid = true;
				}
				else if (testAnotherResponse == "n" || testAnotherResponse == "N")
				{
					isValid = true;
					shouldContinueRunning = false;
				}
				else
				{
					cout << "Invalid Response, please respond 'Y' or 'N'" << endl;
				}
			}
		}
	}
	cout << "\n=============== THANK YOU FOR USING MELISSA C++ OBJECT =============\n" << endl;
}

/// <summary>
/// This function splits the resultCodes based on a delimiter
/// </summary>
/// <param name="s">the resultCode string</param>
/// <param name="delimiter"the delimiter string></param>
/// <returns></returns>
list<string> SplitResultCodes(string s, string delimiter) {
	list<string> resultCodes;

	size_t pos = 0;
	string token;

	while ((pos = s.find(delimiter)) != string::npos) {
		token = s.substr(0, pos);
		resultCodes.push_back(token);
		s.erase(0, pos + delimiter.length());
	}

	// push back the last resultCode
	resultCodes.push_back(s);

	return resultCodes;
}
