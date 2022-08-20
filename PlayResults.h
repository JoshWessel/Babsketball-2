#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

//#include "Logger.h"
//#include "TextColors.h"

using namespace std;

class PlayResults
{
	void resetPlayResultsVariables()
	{
		pr_1_introduction = "";
		pr_2_playerOptions = "";
		pr_3_playerChoice = "";

		pr_4_range = "";
		pr_5_roll = "";

		pr_6_result = "";
		pr_7_reason = "";

		pr_8_rebound = "";
		pr_9_rebounder = "";

		skipPostPlay = false;
	}

	void verifyVariables()
	{
		if (pr_6_result == "")
		{
			pr_6_result = "Result not set...";
			logger.error("No result set for the current play");
		}
	}

	void setResultColor(string result)
	{
		if (result == "SUCCESS")
			setTextColor(BRIGHT_GREEN);
		else
			setTextColor(BRIGHT_RED);
	}

	void setReboundColor(string rebound)
	{
		if (rebound == "OFFENSIVE REBOUND")
			setTextColor(BRIGHT_GREEN);
		else if (rebound == "DEFENSIVE REBOUND")
			setTextColor(BRIGHT_RED);
		else
			setTextColor(DEFAULT);
	}

public:
	string pr_1_introduction = "";
	string pr_2_playerOptions = "";
	string pr_3_playerChoice = "";

	string pr_4_range = "";
	string pr_5_roll = "";

	string pr_6_result = "";
	string pr_7_reason = "";

	string pr_8_rebound = "";
	string pr_9_rebounder = "";

	bool skipPostPlay = false;

	void printResults()
	{
		verifyVariables();

		cout << endl;
		cout << "====================== OVERVIEW ======================" << endl;
		cout << "Players Choice:   " << pr_3_playerChoice << endl;
		cout << "Range:            " << pr_4_range << endl;
		cout << "Roll:             " << pr_5_roll << endl;
		cout << "======================= RESULT =======================" << endl;
		cout << "RESULT:           "; setResultColor(pr_6_result); cout << pr_6_result << endl; setDefaultTextColor();
		cout << "Reason:           "; setResultColor(pr_6_result); cout << pr_7_reason << endl; setDefaultTextColor();
		if (pr_3_playerChoice == "SHOOT" && !skipPostPlay)
		{
			cout << "====================== POSTPLAY ======================" << endl;
			cout << "Rebound:          "; setReboundColor(pr_8_rebound); cout << pr_8_rebound << endl; setDefaultTextColor();
			cout << "Rebounder:        "; cout << pr_9_rebounder << endl;
		}
		cout << "======================================================" << endl << endl;

		resetPlayResultsVariables();
	}
};

PlayResults playResults;