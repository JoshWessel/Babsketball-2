#include <string>
#include <vector>

using namespace std;

class PlayHistory
{
public:

	vector<string> plays;

	void addPlay(string teamName, bool success, string play)
	{
		string playString = "";

		// Set teamName string to 15 characters
		if (teamName.length() >= 15)
		{
			teamName = teamName.substr(0, 12) + "...";
		}
		if (teamName.length() < 15)
		{
			while (teamName.length() < 15)
			{
				teamName = teamName + " ";
			}
		}

		// Set success string
		string successString = "Failure";
		if (success)
		{
			successString = "SUCCESS";
		}

		// Create playString
		playString = playString + teamName + " | " + successString + " | " + play;

		// Save playString
		plays.push_back(playString);
		logger.debug("Saved play! (Total saved plays: " + to_string(plays.size()) + ")");
	}

	void deletePlay(int index)
	{
		plays.erase(plays.begin() + index);
		logger.debug("Deleted play at index " + index);
	}

	void printHistoricalPlays()
	{
		cout << "Team Name       | Outcome | Play                                                          " << endl;
		cout << "==========================================================================================" << endl;
		cout << endl;

		for (int i = 0; i < plays.size(); i++)
		{
			if (plays.at(i).substr(18, 7) == "SUCCESS")
				setTextColor(GREEN);
			else
				setTextColor(DEFAULT);
			cout << plays.at(i) << endl;
			setTextColor(DEFAULT);
		}

		cout << endl;
		system("pause");
	}
};

PlayHistory allPlays;