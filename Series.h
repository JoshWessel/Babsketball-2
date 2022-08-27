#include "BabdulGame.h";

class Series
{
	float seriesLength = 3.0f;

	int gamesPlayed = 0;

	int team1Wins = 0;
	int team2Wins = 0;

	BabdulManager babMan;

	vector<PlaySpotter> playSpotters;

public:

	Series(BabdulManager& babMan, vector<PlaySpotter> playSpotters)
	{
		this->babMan = babMan;
		this->playSpotters = playSpotters;
	}

	void setUpSeries()
	{
		system("cls");
		cout << "Welcome to the Series gamemode!" << endl << endl;
		cout << "Please enter a series length (best of 3, 5, 7): ";
		cin >> seriesLength;
		if (seriesLength == 3 || seriesLength == 5 || seriesLength == 7)
		{
			cout << seriesLength << " game series selected." << endl;
		}
		else
		{
			cout << "Invalid series length. Defaulting to a best of 3 series." << endl;
			seriesLength = 3;
		}
		cout << endl;

		system("pause");
		system("cls");
	}

	void playSeries()
	{
		setUpSeries();

		while (gamesPlayed <= seriesLength && team1Wins < (seriesLength / 2) && team2Wins < (seriesLength / 2))
		{
			preGame();

			BabdulGame game(babMan, playSpotters);

			int gameResult = game.playGame(babMan.gameLength, babMan.otLength, true, gamesPlayed + 1, (int)seriesLength);

			system("cls");
			if (gameResult == 1)
			{
				team1Wins++;
			}
			else if (gameResult == 2)
			{
				team2Wins++;
			}
			else
			{
				cout << "ERROR: game result does not equal 1 or 2" << endl;
				logger.error("Game result does not equal 1 or 2");
			}
			system("pause");

			checkSeriesEnd();

			gamesPlayed++;
		}
	}

	void preGame()
	{
		system("cls");

		cout << "========="; for (int i = 0; i < babMan.team1.getTeamName().length() + babMan.team2.getTeamName().length(); i++) { cout << "="; } cout << endl;
		babMan.team1.printTeamName(); cout << " | " << team1Wins << " : " << team2Wins << " | "; babMan.team2.printTeamName(); cout << endl;
		cout << "========="; for (int i = 0; i < babMan.team1.getTeamName().length() + babMan.team2.getTeamName().length(); i++) { cout << "="; } cout << endl;

		cout << "Welcome to game " << gamesPlayed + 1 << "!" << endl;
		system("pause");
	}

	void checkSeriesEnd()
	{
		if (team1Wins > (seriesLength / 2))
		{
			system("cls");

			cout << "========="; for (int i = 0; i < babMan.team1.getTeamName().length() + babMan.team2.getTeamName().length(); i++) { cout << "="; } cout << endl;
			babMan.team1.printTeamName(); cout << " | " << team1Wins << " : " << team2Wins << " | ";  babMan.team2.printTeamName(); cout << endl;
			cout << "========="; for (int i = 0; i < babMan.team1.getTeamName().length() + babMan.team2.getTeamName().length(); i++) { cout << "="; } cout << endl;
			cout << endl;
			cout << "CONGRATULATIONS "; babMan.team1.printTeamName(); cout << "! You have won the series!" << endl;
			system("pause");
		}
		if (team2Wins > (seriesLength / 2))
		{
			system("cls");

			cout << "========="; for (int i = 0; i < babMan.team1.getTeamName().length() + babMan.team2.getTeamName().length(); i++) { cout << "="; } cout << endl;
			babMan.team1.printTeamName(); cout << " | " << team1Wins << " : " << team2Wins << " | "; babMan.team2.printTeamName(); cout << endl;
			cout << "========="; for (int i = 0; i < babMan.team1.getTeamName().length() + babMan.team2.getTeamName().length(); i++) { cout << "="; } cout << endl;
			cout << endl;
			cout << "CONGRATULATIONS "; babMan.team2.printTeamName(); cout << "! You have won the series!" << endl;
			system("pause");
		}
	}



};