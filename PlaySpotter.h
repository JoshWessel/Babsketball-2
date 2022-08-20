#include <string>
#include <vector>

#include "PlayHistory.h"

using namespace std;

class PlaySpotter
{
	vector<string> spottedOpponentPlays;

	string currentPlay;

public:

	PlaySpotter()
	{
		logger.debug("Creating PlaySpotter...");
		this->spottedOpponentPlays = {};
		this->currentPlay = "";
		logger.debug("Created PlaySpotter");
	}

	int countTimesPlayRun()
	{
		int count = 0;
		if (spottedOpponentPlays.size() > 0)
		{
			logger.debug("Searching spotted plays...");
			for (int i = 0; i < spottedOpponentPlays.size(); i++)
			{
				if (spottedOpponentPlays.at(i) == currentPlay)
				{
					count++;
					logger.debug("Play Spotted! (x" + to_string(count) + ")");
				}
			}
		}
		else
		{
			logger.debug("No successful plays to search");
		}
		
		return count;
	}

	void updateCurrentPlay(string action)
	{
		currentPlay = currentPlay + action;
		logger.debug("Play updated: " + currentPlay);
	}

	string getCurrentPlay()
	{
		return currentPlay;
	}

	void addSpottedPlay()
	{
		spottedOpponentPlays.push_back(currentPlay);
		logger.debug("Adding play to spotted plays: " + currentPlay);
	}

	void clearCurrentPlay()
	{
		currentPlay = "";
		logger.debug("Reset play spotter's current play");
	}

	void clearAllPlays()
	{
		spottedOpponentPlays = {};
		logger.debug("All plays cleared");
	}
};

bool verifySpotters(vector<PlaySpotter> spotters)
{
	string spotterType = typeid(spotters.at(0)).name();
	if (spotters.size() == 2 && typeid(spotters.at(0)).name() == typeid(spotters.at(1)).name() && spotterType == "class PlaySpotter")
	{
		return true;
	}
	else
	{
		return false;
	}
}