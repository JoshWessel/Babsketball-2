#include "Series.h"

class GameModeManager
{

	int gameModeSelected = -1;
	int draftSize = 25;

public:

	void welcome()
	{
		while (gameModeSelected != 0)
		{
			logger.info("Displaying Game Modes");

			system("cls");
			setTextColor(DARK_YELLOW);
			cout << "O=====================================================================================================================================O" << endl;
			cout << "|                                         -   -   -      B A B S K E T B A L L      -   -   -                                         |" << endl;
			cout << "O=====================================================================================================================================O" << endl << endl;

			setDefaultTextColor();
			cout << "Available Game Modes" << endl;
			cout << endl;
			setTextColor(RED);
			cout << "     (0) Quit" << endl;
			cout << endl;
			setTextColor(GREEN);
			cout << "     (1) Quick Game" << endl;
			cout << "     (2) Series" << endl;
			setDefaultTextColor();
			cout << "     (3) 3-Point Contest" << endl;
			cout << endl;
			cout << "     (4) Manage Custom Babduls" << endl;

			cout << endl << "Please Select A Game Mode: ";
			cin >> gameModeSelected;
			logger.info("Game Mode Selected: " + to_string(gameModeSelected));

			// Set global objects:
			
			// 1. Setup play spotters
			logger.info("Setting up play spotters");
			PlaySpotter team1PlaySpotter;
			PlaySpotter team2PlaySpotter;
			vector<PlaySpotter> playSpotters;
			playSpotters.push_back(team1PlaySpotter);
			playSpotters.push_back(team2PlaySpotter);
			if (!verifySpotters(playSpotters))
			{
				logger.error("Spotter verification failed. There are either an incorrect number of spotters or the spotter type is incorrect");
			}

			// Single Game
			if (gameModeSelected == 1)
			{
				logger.info("Loading Quick Game...");

				cout << endl << endl << "Loading Quick Game..." << endl << endl;
				system("pause");

				// Setup Teams
				BabdulManager babManager;
				if (babManager.setup(draftSize) > 0)
				{
					BabdulGame game(babManager, playSpotters);
					game.playGame(babManager.gameLength, babManager.otLength, false, 1, 1);
				}
			}
			else if (gameModeSelected == 2)
			{
				logger.info("Loading Series...");

				cout << endl << endl << "Loading Series..." << endl << endl;
				system("pause");

				// Setup Teams
				BabdulManager babManager;
				if (babManager.setup(draftSize) > 0)
				{
					Series series(babManager, playSpotters);
					series.playSeries();
				}
			}
			else if (gameModeSelected == 3)
			{
				logger.info("Loading 3 Point Contest...");

				cout << endl << endl << "Loading 3-Point Contest..." << endl << endl;
				system("pause");
			}
			else if (gameModeSelected == 4)
			{
				logger.info("Loading Custom Babdul Manager...");

				BabdulManager babManager;
				babManager.manageCustomBabduls();
			}
			else if (gameModeSelected == 0)
			{
				logger.info("Exiting The Application...");

				cout << endl << "Thanks for Playing!" << endl << endl;
				system("pause");
			}
			else
			{
				logger.error("Game Mode not found");

				setTextColor(RED);
				cout << endl << "Game Mode not found" << endl << endl;
				setTextColor(DEFAULT);
				system("pause");
			}
		}
	}
};