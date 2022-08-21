#include "Babdul.h"

class Team
{
public:

	string teamName;
	int teamColor = DEFAULT;
	int numPlayers = 0;
	int maxPlayers;

	vector<Babdul> players;

	Team()
	{
		this->teamName = "Team";
		teamColor = DEFAULT;
		maxPlayers = 5;
		logger.info("Created team " + teamName);
	}

	Team(string name, int maxPlayers)
	{
		this->teamName = name;
		this->teamColor = DEFAULT;
		this->maxPlayers = maxPlayers;
		logger.info("Created team " + teamName);
	}

	Team(string name, int teamColor, int maxPlayers)
	{
		this->teamName = name;
		this->teamColor = teamColor;
		this->maxPlayers = maxPlayers;
		logger.info("Created team " + teamName);
	}

	void setTeamColor(int color)
	{
		teamColor = color;
	}

	void resetTeamColor()
	{
		teamColor = DEFAULT;
	}

	int getTeamColor()
	{
		if (teamColor >= 1 && teamColor <= 15)
		{
			return teamColor;
		}
		else
		{
			resetTeamColor();
			logger.warn("Team color not found, applying default color");
		}
	}

	void addPlayer(Babdul babPlayer)
	{
		players.push_back(babPlayer);
		numPlayers++;
	}

	void cutPlayer(int index)
	{
		players.erase(players.begin() + index);
		numPlayers--;
	}

	void cutAllPlayers()
	{
		players.clear();
	}

	void fillTeam()
	{
		for (int i = numPlayers; i < maxPlayers; i++)
		{
			Babdul bab;
			addPlayer(bab);
		}
	}

	string getTeamName()
	{
		return teamName;
	}

	void printTeamName()
	{
		setTextColor(getTeamColor());
		cout << getTeamName();
		setDefaultTextColor();
	}

	int getNumPlayers()
	{
		return numPlayers;
	}

	int getNumPlayersAtPosition(string position)
	{
		int count = 0;

		if (position == "PG")
		{
			for (int i = 0; i < numPlayers; i++)
			{
				if (players.at(i).getPosition() == "PG")
					count++;
			}
		}
		else if (position == "SG")
		{
			for (int i = 0; i < numPlayers; i++)
			{
				if (players.at(i).getPosition() == "SG")
					count++;
			}
		}
		else if (position == "SF")
		{
			for (int i = 0; i < numPlayers; i++)
			{
				if (players.at(i).getPosition() == "SF")
					count++;
			}
		}
		else if (position == "PF")
		{
			for (int i = 0; i < numPlayers; i++)
			{
				if (players.at(i).getPosition() == "PF")
					count++;
			}
		}
		else if (position == "C" || position == "C ")
		{
			for (int i = 0; i < numPlayers; i++)
			{
				if (players.at(i).getPosition() == "C ")
					count++;
			}
		}

		return count;
	}

	int findShortestPlayerIndex()
	{
		int shortestPlayerIndex = 0;

		for (int i = 1; i < players.size(); i++)
		{
			if (players.at(shortestPlayerIndex).getHeightInInches() > players.at(i).getHeightInInches())
			{
				shortestPlayerIndex = i;
			}
		}

		return shortestPlayerIndex;
	}
};
