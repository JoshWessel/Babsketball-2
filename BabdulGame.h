#include "BabdulManager.h"
#include "PlaySpotter.h"

#define BC team1.players.at(currPlayerIndex)
#define DF team2.players.at(randDefenderIndex)

class BabdulGame
{
	int numUsers = 1;

	int team1Score = 0;
	int team2Score = 0;

	int shotClock = 5;
	int time = 0;
	int gameLength;
	int shotClockLength = 5;

	int tipOffWinner = 1;

	int numPasses;
	int numDrives;
	int numCurrDrives;
	bool changePossession = false;

	bool needMatchupUpdate = false;

	bool isOvertime = false;

	bool isASeries = false;
	int gameNumber = 1;
	int gamesInSeries = 1;

	BabdulManager babMan;

	Sliders gameSliders;

	PlaySpotter team1PlaySpotter;
	PlaySpotter team2PlaySpotter;

public:

	BabdulGame(BabdulManager& babMan, vector<PlaySpotter> playSpotters)
	{
		logger.info("Initializing Game...");
		this->babMan = babMan;
		numUsers = babMan.numUsers;
		logger.info("Number of users: " + to_string(numUsers));

		gameLength = babMan.gameLength;
		logger.info("Game length: " + to_string(gameLength));
		shotClockLength = babMan.shotClockLength;
		logger.info("Shot clock length: " + to_string(shotClockLength));

		team1PlaySpotter = playSpotters.at(0);
		team2PlaySpotter = playSpotters.at(1);
		logger.info("Assigned play spotters");

		allPlays.deleteAllPlays();

		logger.skipLine();
		logger.divider("=");
		logger.info("SUCCESS! Game successfully initialized");
		logger.divider("=");
		logger.skipLine();
	}

	void resetPossession()
	{
		shotClock = shotClockLength;
		numPasses = 0;
		numDrives = 0;
		numCurrDrives = 0;
		changePossession = true;

		team1PlaySpotter.clearCurrentPlay();
		team2PlaySpotter.clearCurrentPlay();
	}

	void resetShotClock()
	{
		shotClock = shotClockLength;
	}

	void applyGameSlidersToPlayers()
	{
		// Team 1
		for (int i = 0; i < babMan.team1.getNumPlayers(); i++)
		{
			babMan.team1.players.at(i).sliders = gameSliders;
		}

		// Team 2
		for (int i = 0; i < babMan.team2.getNumPlayers(); i++)
		{
			babMan.team2.players.at(i).sliders = gameSliders;
		}
	}

	void applyGameSlidersToPlayers(Team team)
	{
		for (int i = 0; i < team.getNumPlayers(); i++)
		{
			team.players.at(i).sliders = gameSliders;
		}
	}

	void tipOff()
	{
		system("cls");

		tipOffWinner = rand() % 2 + 1;
		if (tipOffWinner == 1)
		{
			cout << "======================"; for (int i = 0; i < babMan.team1.getTeamName().length(); i++) { cout << "="; } cout << endl;
			babMan.team1.printTeamName(); cout << " has won the tipoff..." << endl;
			cout << "======================"; for (int i = 0; i < babMan.team1.getTeamName().length(); i++) { cout << "="; } cout << endl;

			if (numUsers >= 1)
			{
				cout << endl;
				babMan.printTeam(babMan.team1);
				cout << endl << "Please select a player to start with: ";
				string startPlayer;
				cin >> startPlayer;

				if (startPlayer.length() < 7)
					startPlayer = startPlayer + " ";

				bool startPlayerFound = false;
				for (int i = 0; i < babMan.team1.players.size(); i++)
				{
					string newBabName = babMan.team1.players.at(i).getBabName();
					transform(newBabName.begin(), newBabName.end(), newBabName.begin(), ::tolower);
					string startPlayerToLower = startPlayer;
					transform(startPlayerToLower.begin(), startPlayerToLower.end(), startPlayerToLower.begin(), ::tolower);

					if (startPlayerToLower == newBabName)
					{
						babMan.team1.players.at(i).setBallCarrier(true);
						cout << endl << babMan.team1.players.at(i).getBabName() << " has the ball to start." << endl << endl;
						babMan.team1.players.at(i).printStats();
						startPlayerFound = true;
					}
				}

				if (startPlayerFound == false)
				{
					cout << "Start player " << startPlayer << " not found. Defaulting to shortest player..." << endl;
					babMan.team1.players.at(babMan.team1.findShortestPlayerIndex()).setBallCarrier(true);
					cout << endl << babMan.team1.players.at(babMan.team1.findShortestPlayerIndex()).getBabName() << " has the ball to start." << endl << endl;
					babMan.team1.players.at(babMan.team1.findShortestPlayerIndex()).printStats();
				}
			}
			else
			{
				cout << endl << "AI selecting starting player..." << endl;
				babMan.team1.players.at(babMan.team1.findShortestPlayerIndex()).setBallCarrier(true);
				cout << endl << babMan.team1.players.at(babMan.team1.findShortestPlayerIndex()).getBabName() << " has the ball to start." << endl << endl;
				babMan.team1.players.at(babMan.team1.findShortestPlayerIndex()).printStats();
			}
		}
		else if (tipOffWinner == 2)
		{
			cout << "======================"; for (int i = 0; i < babMan.team2.getTeamName().length(); i++) { cout << "="; } cout << endl;
			babMan.team2.printTeamName(); cout << " has won the tipoff..." << endl;
			cout << "======================"; for (int i = 0; i < babMan.team2.getTeamName().length(); i++) { cout << "="; } cout << endl;

			if (numUsers >= 2)
			{
				cout << endl;
				babMan.printTeam(babMan.team2);
				cout << endl << "Please select a player to start with: ";
				string startPlayer;
				cin >> startPlayer;

				if (startPlayer.length() < 7)
					startPlayer = startPlayer + " ";

				bool startPlayerFound = false;
				for (int i = 0; i < babMan.team2.players.size(); i++)
				{
					string newBabName = babMan.team2.players.at(i).getBabName();
					transform(newBabName.begin(), newBabName.end(), newBabName.begin(), ::tolower);
					string startPlayerToLower = startPlayer;
					transform(startPlayerToLower.begin(), startPlayerToLower.end(), startPlayerToLower.begin(), ::tolower);

					if (startPlayerToLower == newBabName)
					{
						babMan.team2.players.at(i).setBallCarrier(true);
						cout << endl << babMan.team2.players.at(i).getBabName() << " has the ball to start." << endl << endl;
						babMan.team2.players.at(i).printStats();
						startPlayerFound = true;
					}
				}

				if (startPlayerFound == false)
				{
					cout << "Start player " << startPlayer << " not found. Defaulting to shortest player..." << endl;
					babMan.team2.players.at(babMan.team2.findShortestPlayerIndex()).setBallCarrier(true);
					cout << endl << babMan.team2.players.at(babMan.team2.findShortestPlayerIndex()).getBabName() << " has the ball to start." << endl << endl;
					babMan.team2.players.at(babMan.team2.findShortestPlayerIndex()).printStats();
				}
			}
			else
			{
				cout << endl << "AI selecting starting player..." << endl;
				babMan.team2.players.at(babMan.team2.findShortestPlayerIndex()).setBallCarrier(true);
				cout << endl << babMan.team2.players.at(babMan.team2.findShortestPlayerIndex()).getBabName() << " has the ball to start." << endl << endl;
				babMan.team2.players.at(babMan.team2.findShortestPlayerIndex()).printStats();
			}
		}

		cout << endl;
		system("pause");
	}

	int playGame(int timeLimit, int overtimeLimit, bool isASeries, int gameNumberInSeries, int gamesInSeries)
	{
		if (isASeries)
		{
			this->isASeries = true;
			this->gameNumber = gameNumberInSeries;
			this->gamesInSeries = gamesInSeries;
		}

		system("cls");
		applyGameSlidersToPlayers();

		setDefaultMatchups(babMan.team1, babMan.team2);
		setDefaultMatchups(babMan.team2, babMan.team1);

		cout << "======================" << endl;
		cout << "PREGAME STEP: MATCHUPS" << endl;
		cout << "======================" << endl;

		cout << endl << "Would either team like to adjust their defensive matchups? (y/n) ";

		string editMatchupsYN;
		cin >> editMatchupsYN;
		if (editMatchupsYN == "y" || editMatchupsYN == "Y")
		{
			adjustMatchupsMenu(babMan.team1, babMan.team2);
		}
		else
		{
			cout << "Using default matchups. You can edit matchups midgame in the pause menu." << endl;
		}

		// Game loop
		if (numUsers == 0 || numUsers == 1 || numUsers == 2)
		{
			gameLoop(numUsers, timeLimit);
		}
		else
		{
			logger.error("Invalid number of users");
		}

		system("cls");
		babMan.team1.printTeamName(); cout << " " << team1Score << ":" << team2Score << " "; babMan.team2.printTeamName(); cout << endl << endl;

		if (team1Score > team2Score)
		{
			babMan.team1.printTeamName(); cout << " Wins!" << endl << endl;
		}
		else if (team2Score > team1Score)
		{
			babMan.team2.printTeamName(); cout << " Wins!" << endl << endl;
		}
		else
		{
			if (isASeries)
				return overtime(overtimeLimit);
			else
				overtime(overtimeLimit);
		}

		printBoxScore();

		logger.skipLine();
		logger.divider("=");
		logger.info("GAME FINISHED");
		logger.divider("=");
		logger.skipLine();

		if (isASeries)
		{
			if (team1Score > team2Score)
			{
				resetPoints();
				return 1;
			}
			else if (team1Score < team2Score)
			{
				resetPoints();
				return 2;
			}
		}
		else
		{
			resetPoints();
			return 0;
		}
	}

	void gameLoop(int numPlayers, int timeLimit)
	{
		// Tip off
		tipOff();

		// No Players (AI vs AI)
		if (numPlayers == 0)
		{
			// Player 1 starts
			if (tipOffWinner == 1)
			{
				while (time < timeLimit)
				{
					possession(babMan.team1, babMan.team2, 1, true); // AI
					if (time < timeLimit)
					{
						possession(babMan.team2, babMan.team1, 2, true); // AI
					}
				}
			}
			// Player 2 starts
			else if (tipOffWinner == 2)
			{
				while (time < timeLimit)
				{
					possession(babMan.team2, babMan.team1, 2, true); // AI
					if (time < timeLimit)
					{
						possession(babMan.team1, babMan.team2, 1, true); // AI
					}
				}
			}

		}
		// 1 Player
		else if (numPlayers == 1)
		{
			// Player 1 starts
			if (tipOffWinner == 1)
			{
				while (time < timeLimit)
				{
					possession(babMan.team1, babMan.team2, 1, false);
					if (time < timeLimit)
					{
						possession(babMan.team2, babMan.team1, 2, true); // AI
					}
				}
			}
			// Player 2 starts
			else if (tipOffWinner == 2)
			{
				while (time < timeLimit)
				{
					possession(babMan.team2, babMan.team1, 2, true); // AI
					if (time < timeLimit)
					{
						possession(babMan.team1, babMan.team2, 1, false);
					}
				}
			}
		}
		// 2 Player
		else if (numPlayers == 2)
		{
			// Player 1 starts
			if (tipOffWinner == 1)
			{
				while (time < timeLimit)
				{
					possession(babMan.team1, babMan.team2, 1, false);
					if (time < timeLimit)
					{
						possession(babMan.team2, babMan.team1, 2, false);
					}
				}
			}
			// Player 2 starts
			else if (tipOffWinner == 2)
			{
				while (time < timeLimit)
				{
					possession(babMan.team2, babMan.team1, 2, false);
					if (time < timeLimit)
					{
						possession(babMan.team1, babMan.team2, 1, false);
					}
				}
			}
		}
	}

	int overtime(int overtimeLimit)
	{
		cout << "We're tied! Get ready for overtime..." << endl << endl;
		system("pause");

		system("cls");

		time = 0;

		isOvertime = true;

		gameLoop(numUsers, overtimeLimit);

		system("cls");
		babMan.team1.printTeamName(); cout << " " << team1Score << ":" << team2Score << " "; babMan.team2.printTeamName(); cout << endl << endl;

		if (team1Score > team2Score)
		{
			babMan.team1.printTeamName(); cout << " Wins!" << endl << endl;
		}
		else if (team2Score > team1Score)
		{
			babMan.team2.printTeamName(); cout << " Wins!" << endl << endl;
		}
		else
			overtime(overtimeLimit);

		if (isASeries)
		{
			if (team1Score > team2Score)
				return 1;
			else
				return 2;
		}
		else
		{
			return 0;
		}
	}

	void resetPoints()
	{
		team1Score = 0;
		team2Score = 0;

		for (int i = 0; i < babMan.team1.getNumPlayers(); i++)
		{
			babMan.team1.players.at(i).setPoints(0);
		}

		for (int i = 0; i < babMan.team2.getNumPlayers(); i++)
		{
			babMan.team2.players.at(i).setPoints(0);
		}
	}

	void printCourt(Team& t)
	{
		string pos1 = "      ";
		string pos2 = "      ";
		string pos3 = "      ";
		string pos4 = "      ";
		string pos5 = "      ";
		string pos6 = "      ";
		string pos7 = "  |   ";

		for (int i = 0; i < t.getNumPlayers(); i++)
		{
			if (t.players.at(i).getLocation() == 1)
				pos1 = t.players.at(i).getBabName();
			else if (t.players.at(i).getLocation() == 2)
				pos2 = t.players.at(i).getBabName();
			else if (t.players.at(i).getLocation() == 3)
				pos3 = t.players.at(i).getBabName();
			else if (t.players.at(i).getLocation() == 4)
				pos4 = t.players.at(i).getBabName();
			else if (t.players.at(i).getLocation() == 5)
				pos5 = t.players.at(i).getBabName();
			else if (t.players.at(i).getLocation() == 6)
				pos6 = t.players.at(i).getBabName();
			else if (t.players.at(i).getLocation() == 7)
				pos7 = t.players.at(i).getBabName();
			else
				cout << t.players.at(i).getBabName() << " has an invalid position" << endl;
		}

		cout << "|----------------------------------" << endl;
		cout << "|  " << pos4 << endl;
		cout << "|--------------------. " << endl;
		cout << "|                     \\ " << endl;
		cout << "|                      \\ " << endl;
		cout << "|                       \\ " << pos2 << endl;
		cout << "|                        \\ " << endl;
		cout << "|--------------------     \\ " << endl;
		cout << "|                   |--.   \\ " << endl;
		cout << "|  ---.             |   \\   | " << endl;
		cout << "|  |   \\            |    \\   | " << endl;
		cout << "|  |O" << pos7 << pos6 << "   |     |   | " << pos1 << endl;
		cout << "|  |   /            |    /   | " << endl;
		cout << "|  ---'             |   /   | " << endl;
		cout << "|                   |--'   / " << endl;
		cout << "|--------------------     / " << endl;
		cout << "|                        / " << endl;
		cout << "|                       / " << pos3 << endl;
		cout << "|                      / " << endl;
		cout << "|                     / " << endl;
		cout << "|--------------------' " << endl;
		cout << "|  " << pos5 << endl;
		cout << "|----------------------------------" << endl << endl;
	}

	void printTeamAttributes(Team& t, Babdul& bc, Team& defenders, Babdul& defender)
	{
		vector<Babdul> tempTeam = babMan.sortBy(t.players, "Overall");
		cout << "Babname Position Overall Tier       Build         Babdulishness S-Close S-Mid S-3 PSAC Off-Reb Speed Strength Points Blocks Assists Turnovers | Guarded By Contest Block Per-D Int-D" << endl;
		cout << "==============================================================================================================================================|=====================================" << endl;
		for (int i = 0; i < t.getNumPlayers(); i++)
		{
			Babdul p = tempTeam.at(i);
			cout << p.getBabName() << " " <<
				p.getPosition() << "       " <<
				p.getOverall() << "      " <<
				p.getTier() << " " <<
				p.getBuild() << " " <<
				p.getBabdulishness() << "            " <<
				p.getShotClose() << "      " <<
				p.getShotMid() << "    " <<
				p.getShot3() << "  " <<
				p.getPassAccuracy() << "   " <<
				p.getOffRebound() << "      " <<
				p.getSpeed() << "    " <<
				p.getStrength() << "       " <<
				p.getPoints() << "      " <<
				p.getBlocks() << "      " <<
				p.getAssists() << "       " <<
				p.getTurnovers() << "         | "; setTextColor(GRAY); cout <<
				findGuardedBy(p, defenders).getBabName() << "    " <<
				findGuardedBy(p, defenders).getShotContest() << "      " <<
				findGuardedBy(p, defenders).getBlock() << "    " <<
				findGuardedBy(p, defenders).getPerimeterD() << "    " <<
				findGuardedBy(p, defenders).getInteriorD() <<
				endl;
			setDefaultTextColor();
			cout << "----------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------" << endl;
		}
		printBCDF(t, bc, defender);
	}

	void printBCDF(Team& t, Babdul& bc, Babdul& defender)
	{
		cout << endl;
		cout << "              BabName Position Overall Babdulishness S-Close S-Mid S-3 PSAC Per-D Int-D S-Contest Block Def-Reb Off-Reb Speed Strength" << endl;
		cout << "              ========================================================================================================================" << endl;
		cout << "Ball Carrier: "; bc.printOffensiveStatsHorizontally(t.getTeamColor());
		cout << "Defended by:  "; defender.printDefensiveStatsHorizontally();
	}

	Babdul& findGuardedBy(Babdul& player, Team& dTeam)
	{
		for (int i = 0; i < dTeam.getNumPlayers(); i++)
		{
			if (dTeam.players.at(i).getBabName() == player.getMatchup())
			{
				return dTeam.players.at(i);
			}
		}
		logger.error("Unable to find " + player.getBabName() + "'s matchup");
	}

	void printBoxScore()
	{
		babMan.team1.players = babMan.sortBy(babMan.team1.players, "Points");
		cout << endl; babMan.team1.printTeamName(); cout << endl << endl;
		cout << "Babname Position Overall Tier       Build         Points Rebounds Assists Blocks Turnovers" << endl;
		cout << "==========================================================================================" << endl;
		for (int i = 0; i < babMan.team1.getNumPlayers(); i++)
		{
			Babdul p = babMan.team1.players.at(i);
			cout << p.getBabName() << " " <<
				p.getPosition() << "       " <<
				p.getOverall() << "      " <<
				p.getTier() << " " <<
				p.getBuild() << " " <<
				p.getPoints() << "      " <<
				p.getRebounds() << "        " <<
				p.getAssists() << "       " <<
				p.getBlocks() << "      " <<
				p.getTurnovers() <<
				endl;
			cout << "------------------------------------------------------------------------------------------" << endl;
		}

		babMan.team2.players = babMan.sortBy(babMan.team2.players, "Points");
		cout << endl; babMan.team2.printTeamName(); cout << endl << endl;
		cout << "Babname Position Overall Tier       Build         Points Rebounds Assists Blocks Turnovers" << endl;
		cout << "==========================================================================================" << endl;
		for (int i = 0; i < babMan.team2.getNumPlayers(); i++)
		{
			Babdul p = babMan.team2.players.at(i);
			cout << p.getBabName() << " " <<
				p.getPosition() << "       " <<
				p.getOverall() << "      " <<
				p.getTier() << " " <<
				p.getBuild() << " " <<
				p.getPoints() << "      " <<
				p.getRebounds() << "        " <<
				p.getAssists() << "       " <<
				p.getBlocks() << "      " <<
				p.getTurnovers() <<
				endl;
			cout << "------------------------------------------------------------------------------------------" << endl;
		}

		system("pause");
	}

	void scoreBoard(Team& team1)
	{
		int timeRemaining = gameLength - time;
		if (isOvertime)
			timeRemaining = babMan.otLength - time;

		// Set clock colors
		int timeRemainingColor = DEFAULT;
		if (timeRemaining <= shotClockLength)
			timeRemainingColor = RED;
		int shotClockRemainingColor = DEFAULT;
		if (shotClock <= 2)
			shotClockRemainingColor = RED;

		for (int i = 0; i < babMan.team1.getTeamName().length() + babMan.team2.getTeamName().length() + 49; i++) { cout << "="; }
		if ((gameLength - time) > 9) { cout << "="; }
		cout << "==========================="; for (int i = 0; i < team1.getTeamName().length(); i++) { cout << "="; } cout << "===========================================" << endl;

		babMan.team1.printTeamName(); cout << " " << team1Score << ":" << team2Score << " "; babMan.team2.printTeamName(); cout << "     Time Remaining: "; setTextColor(timeRemainingColor); cout << timeRemaining; setDefaultTextColor(); cout << "     SHOTCLOCK: "; setTextColor(shotClockRemainingColor); cout << shotClock; setDefaultTextColor(); cout << "     ";
		cout << "POSSESSION --------------- "; team1.printTeamName(); cout << " --------------- POSSESSION     Game " << gameNumber << " of " << gamesInSeries << endl;

		for (int i = 0; i < babMan.team1.getTeamName().length() + babMan.team2.getTeamName().length() + 49; i++) { cout << "="; }
		if ((gameLength - time) > 9) { cout << "="; }
		cout << "==========================="; for (int i = 0; i < team1.getTeamName().length(); i++) { cout << "="; } cout << "===========================================" << endl;
	}

	void recordHistoricalPlay(int currTeamNum, string teamName, bool success)
	{
		string currPlay = "";
		if (currTeamNum == 1) { currPlay = team1PlaySpotter.getCurrentPlay(); }
		else if (currTeamNum == 2) { currPlay = team2PlaySpotter.getCurrentPlay(); }
		allPlays.addPlay(teamName, success, currPlay);
	}

	void possession(Team& team1, Team& team2, int currTeamNum, bool AIPossession)
	{
		int timeRemaining = gameLength - time;
		if (isOvertime)
			timeRemaining = babMan.otLength - time;

		logger.skipLine();
		logger.divider("-");
		logger.info("Time Remaining: " + to_string(timeRemaining));
		logger.info("Score: " + babMan.team1.getTeamName() + " " + to_string(team1Score) + " | " + babMan.team2.getTeamName() + " " + to_string(team2Score));
		logger.info("Possession: " + team1.getTeamName());
		logger.skipLine();

		babMan.assignLocations(team1);

		resetShotClock();

		changePossession = false;
		while (!changePossession && time < gameLength)
		{
			system("cls");
			scoreBoard(team1);

			int currTeam, oppoTeam;

			if (currTeamNum == 1)
			{
				currTeam = 1;
				oppoTeam = 2;
			}
			else if (currTeamNum == 2)
			{
				currTeam = 2;
				oppoTeam = 1;
			}
			else
			{
				logger.error("Invalid team number");
			}

			// Find Ball Carrier and his matchup
			if (needMatchupUpdate)
			{
				updateMatchups(numDrives, team1, team2);
				needMatchupUpdate = false;
			}
			int currPlayerIndex = getCurrPlayerIndex(team1);
			int randDefenderIndex = getDefenderIndex(team1, team2);

			printCourt(team1);
			printTeamAttributes(team1, BC, team2, DF);

			// Shot clock turnover
			if (shotClock == 0)
			{
				playResults.pr_6_result = "FAILURE";
				playResults.pr_7_reason = "Shot clock expired";
				recordHistoricalPlay(currTeamNum, team1.getTeamName(), false);
				BC.addTurnover();
				resetPossession();
				switchBallCarriers(BC, DF);
				team1.players.at(findPasserIndex(team1)).setWasPasser(false);

				playResults.printResults();

				if (time + 1 < gameLength)
				{
					if (!AIPossession)
						if (numUsers == 1)
							outletPass(team2, team1, DF, true);
						else
							outletPass(team2, team1, DF, false);
					else
						if (numUsers == 1)
							outletPass(team2, team1, DF, false);
						else
							outletPass(team2, team1, DF, true);
				}
			}
			// If time left on shotclock
			else
			{
				cout << endl; team1.printTeamName(); cout << "'s " << BC.getBabName() << " currently has the ball, defended by " << DF.getBabName() << ". Please select an option below:" << endl;

				string psd;
				// AI Decision
				if (AIPossession)
				{
					psd = AI_Decision(BC, DF);

					string choice;
					if (psd == "s")
					{
						choice = "shoot";
					}
					else if (psd == "p")
					{
						choice = "pass";
					}
					else if (psd == "d")
					{
						choice = "drive";
					}
					else if (psd == "b")
					{
						choice = "back down";
					}
				}
				// Player Decision
				else
				{
					// Calculate Chances
					int timesThisPlayHasBeenRun = 0;
					if (currTeamNum == 1)
					{
						timesThisPlayHasBeenRun = team1PlaySpotter.countTimesPlayRun();
					}
					else if (currTeamNum == 2)
					{
						timesThisPlayHasBeenRun = team2PlaySpotter.countTimesPlayRun();
					}
					string passChance = BC.passChance(DF, numPasses, numDrives);
					string driveChance = BC.driveChance(DF, numPasses, numDrives);
					string backDownChance = BC.backDownChance(DF);
					string shootChance = BC.shootChance(team1.players.at(findPasserIndex(team1)), DF, numPasses, numDrives, timesThisPlayHasBeenRun);

					// Print options
					cout << endl;
					cout << "         ================|================|================|================|================|================|================|" << endl;
					cout << "Options: Pause (/)       | Pass (p [name])| Drive (d)      | Back Down (b)  | Shoot (s)      | Hold (h)       | Babdul (!)     |" << endl;
					cout << "Chance:   -              | " + passChance + "           | " + driveChance + "           | " + backDownChance + "           | " + shootChance + "           | -              |  10%           |" << endl;
					cout << "         ================|================|================|================|================|================|================|" << endl;
					cout << endl;
					cout << "Choice: ";
					cin >> psd;
				}

				if (psd == "/" && !AIPossession)
				{
					pauseMenu(team1);
				}
				else if (psd == "/rm")
				{
					randomizeMatchups(babMan.team2, babMan.team1);
					cout << endl << "Randomized matchups. I hope you know what you're doing!" << endl << endl;

					// Prevent time change
					shotClock++;
					time--;
				}
				else if (psd == "/dm")
				{
					setDefaultMatchups(babMan.team2, babMan.team1);
					cout << endl << "Reset matchups to default." << endl << endl;

					// Prevent time change
					shotClock++;
					time--;
				}
				else if (psd == "/ct")
				{
					playResults.pr_6_result = "SUCCESS";
					playResults.pr_7_reason = "Turn conceded. You're so nice!";
					cout << endl << "Conceding Turn..." << endl << endl;

					// Prevent time change
					shotClock++;
					time--;

					resetPossession();
					switchBallCarriers(BC, DF);
					team1.players.at(findPasserIndex(team1)).setWasPasser(false);

					playResults.printResults();

					if (time + 1 < gameLength)
					{
						if (numUsers == 1)
							outletPass(team2, team1, DF, true);
						else
							outletPass(team2, team1, DF, false);
					}
				}
				else if (psd == "!" && !AIPossession)
				{
					playResults.pr_3_playerChoice = "BABDUL";
					int miracleShot = rand() % 10 + 1;
					if (miracleShot == 10)
					{
						int points;
						if (BC.getLocation() < 6)
							points = 3;
						else
							points = 2;

						if (currTeamNum == 1)
							team1Score += points;
						else if (currTeamNum == 2)
							team2Score += points;

						cout << endl << BC.getBabName() << " Scored!" << endl << endl;

						playResults.pr_6_result = "SUCCESS";
						playResults.pr_7_reason = BC.getBabName() + " is so bad but somehow he still scored!";
						playResults.skipPostPlay = true;

						BC.addPoints(points);

						if (numPasses > 0)
							team1.players.at(findPasserIndex(team1)).addAssist();

						recordHistoricalPlay(currTeamNum, team1.getTeamName(), true);
						resetPossession();
						switchBallCarriers(BC, DF);
						team1.players.at(findPasserIndex(team1)).setWasPasser(false);

						playResults.printResults();

						if (time + 1 < gameLength)
						{
							if (numUsers == 1)
								outletPass(team2, team1, DF, true);
							else
								outletPass(team2, team1, DF, false);
						}
					}
					else
					{
						int randMessage = rand() % 12 + 1;
						if (randMessage == 1)
						{
							playResults.pr_7_reason = "So close! But actually not really...";
						}
						else if (randMessage == 2)
						{
							playResults.pr_7_reason = BC.getBabName() + " passes to the ref...";
						}
						else if (randMessage == 3)
						{
							playResults.pr_7_reason = BC.getBabName() + " tries to do a backflip and winds up with a broken nose. But it's probably fine...";
						}
						else if (randMessage == 4 && BC.getLocation() != 6 && BC.getLocation() != 7)
						{
							playResults.pr_7_reason = BC.getBabName() + " attempts a standing dunk from the 3 point line. So of course that didn't work...";
						}
						else if (randMessage == 4)
						{
							playResults.pr_7_reason = BC.getBabName() + " falls asleep and turns it over. He gets stepped on by " + DF.getBabName() + ", so that woke " + BC.getBabName() + " up and he's fine.";
						}
						else if (randMessage == 5)
						{
							playResults.pr_7_reason = "You probably regret choosing this option. But here's a smiley face to help you feel better :)";
						}
						else if (randMessage == 6)
						{
							playResults.pr_7_reason = BC.getBabName() + " has an existential crisis while contemplating the suspicious coincidence that everybody's name ends in abdul, and no one has any last names...and then he turns it over...";
						}
						else if (randMessage == 7)
						{
							playResults.pr_7_reason = BC.getBabName() + " has an alergic reaction to the air, and turns it over...";
						}
						else if (randMessage == 8)
						{
							playResults.pr_7_reason = BC.getBabName() + " looked at the defense, saw that they were sad, and thought he'd cheer them up by giving them the ball...";
						}
						else if (randMessage == 9)
						{
							playResults.pr_7_reason = BC.getBabName() + " remembers that he doesn't know how to play basketball, drops the ball, and runs away crying...but he's back on defense so it's ok";
						}
						else if (randMessage == 10)
						{
							playResults.pr_7_reason = BC.getBabName() + " looks in his reflection off the floor, has a heart attack, dies, revives himself with the power of sheer babdulishness, and then gets back on defense...";
						}
						else if (randMessage == 11)
						{
							playResults.pr_7_reason = BC.getBabName() + " gets sneezed on by the defender and blatantly flops trying to draw a foul. Little does " + BC.getBabName() + " know that there are no fouls in Babsketball, or refs...";
						}
						else if (randMessage == 12)
						{
							playResults.pr_7_reason = BC.getBabName() + " is a babdul. So that's a turnover...";
						}

						playResults.pr_6_result = "FAILURE";

						BC.addTurnover();
						recordHistoricalPlay(currTeamNum, team1.getTeamName(), false);
						resetPossession();
						switchBallCarriers(BC, DF);
						team1.players.at(findPasserIndex(team1)).setWasPasser(false);

						playResults.printResults();

						if (time + 1 < gameLength)
						{
							if (numUsers == 1)
								outletPass(team2, team1, DF, true);
							else
								outletPass(team2, team1, DF, false);
						}
					}
				}
				else if (psd == "h" || psd == "H")
				{
					playResults.pr_3_playerChoice = "HOLD";

					playResults.pr_6_result = "SUCCESS";
					playResults.pr_7_reason = BC.getBabName() + " held the ball";

					playResults.printResults();
				}
				else if (psd == "s" || psd == "S")
				{
					playResults.pr_3_playerChoice = "SHOOT";
					if (currTeamNum == 1)
					{
						team1PlaySpotter.updateCurrentPlay(BC.getBabName() + "=s/");
					}
					else if (currTeamNum == 2)
					{
						team2PlaySpotter.updateCurrentPlay(BC.getBabName() + "=s/");
					}

					int timesThisPlayHasBeenRun = 0;
					if (currTeamNum == 1)
					{
						timesThisPlayHasBeenRun = team1PlaySpotter.countTimesPlayRun();
					}
					else if (currTeamNum == 2)
					{
						timesThisPlayHasBeenRun = team2PlaySpotter.countTimesPlayRun();
					}

					bool shotAttempt;
					if (numPasses > 0)
						shotAttempt = BC.shoot(team1.players.at(findPasserIndex(team1)), DF, numPasses, numDrives, timesThisPlayHasBeenRun);
					else if (numPasses == 0)
						shotAttempt = BC.shoot(DF, numPasses, numDrives, timesThisPlayHasBeenRun);

					bool blockAttempt;
					if (BC.getHeightInInches() >= DF.getHeightInInches() + 4)
						blockAttempt = false;
					else
						blockAttempt = DF.attemptBlock();

					// Shot attempt is successful, defense is unable to defend
					if (shotAttempt && !blockAttempt)
					{
						int points;
						if (BC.getLocation() < 6)
							points = 3;
						else
							points = 2;

						if (currTeamNum == 1)
							team1Score += points;
						else if (currTeamNum == 2)
							team2Score += points;

						playResults.pr_6_result = "SUCCESS";
						playResults.pr_7_reason = BC.getBabName() + " scored " + to_string(points) + " points!";
						playResults.skipPostPlay = true;

						if (currTeamNum == 1)
						{
							team1PlaySpotter.addSpottedPlay();
						}
						else if (currTeamNum == 2)
						{
							team2PlaySpotter.addSpottedPlay();
						}

						BC.addPoints(points);

						if (numPasses > 0)
							team1.players.at(findPasserIndex(team1)).addAssist();

						recordHistoricalPlay(currTeamNum, team1.getTeamName(), true);
						resetPossession();
						switchBallCarriers(BC, DF);
						team1.players.at(findPasserIndex(team1)).setWasPasser(false);

						playResults.printResults();

						if (time + 1 < gameLength)
						{
							if (!AIPossession)
								if (numUsers == 1)
									outletPass(team2, team1, DF, true);
								else
									outletPass(team2, team1, DF, false);
							else
								if (numUsers == 1)
									outletPass(team2, team1, DF, false);
								else
									outletPass(team2, team1, DF, true);
						}
					}
					// shot attempt is on target, but defense blocks the shot
					else if (blockAttempt)
					{
						playResults.pr_6_result = "FAILURE";
						playResults.pr_7_reason = DF.getBabName() + " blocked the shot!";
						playResults.skipPostPlay = true;

						team2.players.at(randDefenderIndex).addBlock();

						recordHistoricalPlay(currTeamNum, team1.getTeamName(), false);
						resetPossession();
						switchBallCarriers(BC, DF);
						team1.players.at(findPasserIndex(team1)).setWasPasser(false);

						playResults.printResults();

						if (time + 1 < gameLength)
						{
							if (!AIPossession)
								if (numUsers == 1)
									outletPass(team2, team1, DF, true);
								else
									outletPass(team2, team1, DF, false);
							else
								if (numUsers == 1)
									outletPass(team2, team1, DF, false);
								else
									outletPass(team2, team1, DF, true);
						}
					}
					// shot attempt is unsuccessful
					else if (!shotAttempt)
					{
						team1.players.at(findPasserIndex(team1)).setWasPasser(false);

						playResults.pr_6_result = "FAILURE";

						if (findRebounder(team1, team2) == 1)
						{
							// Check offensive rebounders
							for (int i = 0; i < team1.getNumPlayers(); i++)
							{
								if (team1.players.at(i).getIsRebounder() == true)
								{
									team1.players.at(i).addOffRebound();
									team1.players.at(i).setIsRebounder(false);

									playResults.pr_8_rebound = "OFFENSIVE REBOUND";
									playResults.pr_9_rebounder = team1.players.at(i).getBabName() + " (" + to_string(team1.players.at(i).getOffRebound()) + " OFF REB)";

									shotClock = shotClockLength;
									numPasses = 0;
									numDrives = 0;
									numCurrDrives = 0;

									switchBallCarriers(BC, team1.players.at(i));

									if (currTeamNum == 1)
									{
										team1PlaySpotter.updateCurrentPlay("[" + BC.getBabName() + "=OR]");
										recordHistoricalPlay(currTeamNum, team1.getTeamName(), false);
										team1PlaySpotter.clearCurrentPlay();
									}
									else if (currTeamNum == 2)
									{
										team2PlaySpotter.updateCurrentPlay("[" + BC.getBabName() + "=OR]");
										recordHistoricalPlay(currTeamNum, team1.getTeamName(), false);
										team2PlaySpotter.clearCurrentPlay();
									}
									playResults.printResults();
								}
							}
						}
						else
						{
							// Check defensive rebounders
							for (int i = 0; i < team2.getNumPlayers(); i++)
							{
								if (team2.players.at(i).getIsRebounder() == true)
								{
									team2.players.at(i).addDefRebound();
									team2.players.at(i).setIsRebounder(false);

									playResults.pr_8_rebound = "DEFENSIVE REBOUND";
									playResults.pr_9_rebounder = team2.players.at(i).getBabName() + " (" + to_string(team2.players.at(i).getDefRebound()) + " DEF REB)";

									recordHistoricalPlay(currTeamNum, team1.getTeamName(), false);
									resetPossession();
									switchBallCarriers(BC, team2.players.at(i));

									playResults.printResults();

									if (time + 1 < gameLength)
									{
										if (!AIPossession)
											if (numUsers == 1)
												outletPass(team2, team1, DF, true);
											else
												outletPass(team2, team1, DF, false);
										else
											if (numUsers == 1)
												outletPass(team2, team1, DF, false);
											else
												outletPass(team2, team1, DF, true);
									}
								}
							}
						}
					}
				}
				else if (psd == "p" || psd == "P")
				{
					if (currTeamNum == 1)
					{
						team1PlaySpotter.updateCurrentPlay(BC.getBabName() + "=p/");
					}
					else if (currTeamNum == 2)
					{
						team2PlaySpotter.updateCurrentPlay(BC.getBabName() + "=p/");
					}

					string passTo;
					bool targetFound = false;
					int checkedTeammates = 0;
					if (AIPossession)
					{
						// Randomly find a pass target on the AI's team
						int passTarget = rand() % 5;

						// Increment the target if they try to pass to themselves
						if (BC.getBabName() == team1.players.at(passTarget).getBabName())
						{
							if (passTarget == 0)
								passTarget++;
							else
								passTarget--;
						}

						passTo = team1.players.at(passTarget).getBabName();
					}
					else
					{
						cout << "To:     ";
						cin >> passTo;
						cout << endl;
					}

					if (passTo.length() == 6)
						passTo = passTo + " ";

					playResults.pr_3_playerChoice = "PASS TO " + passTo;

					// If the target is the ball carrier
					string lowerBabName = BC.getBabName();
					transform(lowerBabName.begin(), lowerBabName.end(), lowerBabName.begin(), ::tolower);
					transform(passTo.begin(), passTo.end(), passTo.begin(), ::tolower);
					if (passTo == lowerBabName && !AIPossession)
					{
						playResults.pr_6_result = "FAILURE";
						playResults.pr_7_reason = BC.getBabName() + " tried to pass to himself";

						BC.addTurnover();
						recordHistoricalPlay(currTeamNum, team1.getTeamName(), false);
						resetPossession();
						switchBallCarriers(BC, DF);
						team1.players.at(findPasserIndex(team1)).setWasPasser(false);

						playResults.printResults();

						if (time + 1 < gameLength)
						{
							if (numUsers == 1)
								outletPass(team2, team1, DF, true);
							else
								outletPass(team2, team1, DF, false);
						}
					}

					for (int i = 0; i < team1.getNumPlayers(); i++)
					{
						string newBabName = team1.players.at(i).getBabName();
						transform(newBabName.begin(), newBabName.end(), newBabName.begin(), ::tolower);
						string newPassTo = passTo;
						transform(newPassTo.begin(), newPassTo.end(), newPassTo.begin(), ::tolower);

						if (newBabName == newPassTo)
						{
							targetFound = true;
							bool passAttempt = BC.pass(DF, numPasses, numDrives);

							// Pass attempt is successful
							if (passAttempt)
							{
								playResults.pr_6_result = "SUCCESS";
								playResults.pr_7_reason = BC.getBabName() + " passed to " + passTo;

								numPasses++;
								numCurrDrives = 0;

								if (BC.getLocation() > 5)
									exitPaint(BC, team1);

								switchBallCarriers(BC, team1.players.at(i));
								if (numPasses > 0)
									switchPasser(team1.players.at(findPasserIndex(team1)), BC);
								else
									BC.setWasPasser(true);

								playResults.printResults();
							}
							// Pass attempt is unsuccessful
							else
							{
								playResults.pr_6_result = "FAILURE";
								playResults.pr_7_reason = BC.getBabName() + " turns it over while trying to pass to " + passTo;

								BC.addTurnover();
								recordHistoricalPlay(currTeamNum, team1.getTeamName(), false);
								resetPossession();
								switchBallCarriers(BC, DF);
								team1.players.at(findPasserIndex(team1)).setWasPasser(false);

								playResults.printResults();

								if (time + 1 < gameLength)
								{
									if (!AIPossession)
										if (numUsers == 1)
											outletPass(team2, team1, DF, true);
										else
											outletPass(team2, team1, DF, false);
									else
										if (numUsers == 1)
											outletPass(team2, team1, DF, false);
										else
											outletPass(team2, team1, DF, true);
								}
							}
							checkedTeammates = 0;
						}

						if (targetFound)
							break;

						checkedTeammates++;
						if (checkedTeammates >= 5)
						{
							playResults.pr_6_result = "FAILURE";
							playResults.pr_7_reason = passTo + " is on the bench!" + BC.getBabName() + " turns it over while trying to pass to " + passTo;

							BC.addTurnover();
							recordHistoricalPlay(currTeamNum, team1.getTeamName(), false);
							resetPossession();
							switchBallCarriers(BC, DF);
							team1.players.at(findPasserIndex(team1)).setWasPasser(false);

							playResults.printResults();

							if (time + 1 < gameLength)
							{
								if (!AIPossession)
									if (numUsers == 1)
										outletPass(team2, team1, DF, true);
									else
										outletPass(team2, team1, DF, false);
								else
									if (numUsers == 1)
										outletPass(team2, team1, DF, false);
									else
										outletPass(team2, team1, DF, true);
							}
						}
					}
				}
				else if (psd == "d" || psd == "D")
				{
					playResults.pr_3_playerChoice = "DRIVE";
					if (currTeamNum == 1)
					{
						team1PlaySpotter.updateCurrentPlay(BC.getBabName() + "=d/");
					}
					else if (currTeamNum == 2)
					{
						team2PlaySpotter.updateCurrentPlay(BC.getBabName() + "=d/");
					}

					// Player drives out of bounds
					if (numCurrDrives > 2)
					{
						playResults.pr_6_result = "FAILURE";
						playResults.pr_7_reason = BC.getBabName() + " drives out of bounds";

						BC.addTurnover();
						recordHistoricalPlay(currTeamNum, team1.getTeamName(), false);
						resetPossession();
						switchBallCarriers(BC, DF);
						team1.players.at(findPasserIndex(team1)).setWasPasser(false);

						playResults.printResults();

						if (time + 1 < gameLength)
						{
							if (!AIPossession)
								if (numUsers == 1)
									outletPass(team2, team1, DF, true);
								else
									outletPass(team2, team1, DF, false);
							else
								if (numUsers == 1)
									outletPass(team2, team1, DF, false);
								else
									outletPass(team2, team1, DF, true);
						}
					}
					else
					{
						bool driveAttempt = BC.drive(DF, numPasses, numDrives);

						// Drive is successful
						if (driveAttempt)
						{
							numDrives++;
							numCurrDrives++;
							playResults.pr_6_result = "SUCCESS";
							if (numCurrDrives == 1)
							{
								playResults.pr_7_reason = BC.getBabName() + " drives and is at the free throw line";
								BC.setLocation(6);
							}
							else if (numCurrDrives == 2)
							{
								playResults.pr_7_reason = BC.getBabName() + " drives and is at the basket";
								BC.setLocation(7);
							}
							else
							{
								cout << endl << BC.getBabName() << " drives." << endl << endl;
							}

							needMatchupUpdate = true;

							playResults.printResults();
						}
						// Drive is not successful
						else
						{
							playResults.pr_6_result = "FAILURE";

							BC.addTurnover();
							recordHistoricalPlay(currTeamNum, team1.getTeamName(), false);
							resetPossession();
							switchBallCarriers(BC, DF);
							team1.players.at(findPasserIndex(team1)).setWasPasser(false);

							playResults.printResults();

							if (time + 1 < gameLength)
							{
								if (!AIPossession)
									if (numUsers == 1)
										outletPass(team2, team1, DF, true);
									else
										outletPass(team2, team1, DF, false);
								else
									if (numUsers == 1)
										outletPass(team2, team1, DF, false);
									else
										outletPass(team2, team1, DF, true);
							}
						}
					}
				}
				else if (psd == "b" || psd == "B")
				{
					playResults.pr_3_playerChoice = "BACK DOWN";
					if (currTeamNum == 1)
					{
						team1PlaySpotter.updateCurrentPlay(BC.getBabName() + "=b/");
					}
					else if (currTeamNum == 2)
					{
						team2PlaySpotter.updateCurrentPlay(BC.getBabName() + "=b/");
					}

					// Player drives out of bounds
					if (numCurrDrives > 2)
					{
						playResults.pr_6_result = "FAILURE";
						playResults.pr_7_reason = BC.getBabName() + " backs down out of bounds";

						BC.addTurnover();
						recordHistoricalPlay(currTeamNum, team1.getTeamName(), false);
						resetPossession();
						switchBallCarriers(BC, DF);
						team1.players.at(findPasserIndex(team1)).setWasPasser(false);

						playResults.printResults();

						if (time + 1 < gameLength)
						{
							if (!AIPossession)
								if (numUsers == 1)
									outletPass(team2, team1, DF, true);
								else
									outletPass(team2, team1, DF, false);
							else
								if (numUsers == 1)
									outletPass(team2, team1, DF, false);
								else
									outletPass(team2, team1, DF, true);
						}
					}
					else
					{
						bool backDownAttempt = BC.backDown(DF);

						// Drive is successful
						if (backDownAttempt)
						{
							numDrives++;
							numCurrDrives++;
							playResults.pr_6_result = "SUCCESS";
							if (numCurrDrives == 1)
							{
								playResults.pr_7_reason = BC.getBabName() + " backs down and is at the high post";
								BC.setLocation(6);
							}
							else if (numCurrDrives == 2)
							{
								playResults.pr_7_reason = BC.getBabName() + " backs down and is at the basket";
								BC.setLocation(7);
							}

							playResults.printResults();

						}
						// Drive is not successful
						else
						{
							playResults.pr_6_result = "FAILURE";
							playResults.pr_7_reason = BC.getBabName() + " was unable to back down the defender";

							BC.addTurnover();
							recordHistoricalPlay(currTeamNum, team1.getTeamName(), false);
							resetPossession();
							switchBallCarriers(BC, DF);
							team1.players.at(findPasserIndex(team1)).setWasPasser(false);

							playResults.printResults();

							if (time + 1 < gameLength)
							{
								if (!AIPossession)
									if (numUsers == 1)
										outletPass(team2, team1, DF, true);
									else
										outletPass(team2, team1, DF, false);
								else
									if (numUsers == 1)
										outletPass(team2, team1, DF, false);
									else
										outletPass(team2, team1, DF, true);
							}
						}
					}
				}
				else
				{
					playResults.pr_3_playerChoice = "NONE";
					playResults.pr_6_result = "FAILURE";
					playResults.pr_7_reason = BC.getBabName() + " chooses to do nothing and loses the ball";
					BC.addTurnover();
					recordHistoricalPlay(currTeamNum, team1.getTeamName(), false);
					resetPossession();
					switchBallCarriers(BC, DF);
					team1.players.at(findPasserIndex(team1)).setWasPasser(false);

					playResults.printResults();

					if (time + 1 < gameLength)
					{
						if (!AIPossession)
							if (numUsers == 1)
								outletPass(team2, team1, DF, true);
							else
								outletPass(team2, team1, DF, false);
						else
							if (numUsers == 1)
								outletPass(team2, team1, DF, false);
							else
								outletPass(team2, team1, DF, true);
					}
				}

				shotClock--;
				time++;

				system("pause");
				cout << endl;
			}
		}
	}

	void exitPaint(Babdul& bab, Team& teammates)
	{
		int total = (teammates.getNumPlayers() + 1) * (teammates.getNumPlayers() + 2) / 2;

		for (int i = 0; i < teammates.getNumPlayers(); i++)
		{
			total -= teammates.players.at(i).getLocation();
		}

		bab.setLocation(total);
	}

	void switchBallCarriers(Babdul& oldBC, Babdul& newBC)
	{
		oldBC.setBallCarrier(false);
		newBC.setBallCarrier(true);
	}

	void switchPasser(Babdul& oldBC, Babdul& newBC)
	{
		oldBC.setWasPasser(false);
		newBC.setWasPasser(true);
	}

	char AI_Decision(Babdul& bc, Babdul& df)
	{
		bool AIIsSmart = true;
		int isAISmart = rand() % 10 + 1;

		if (isAISmart < 4)
			AIIsSmart = false;

		if (AIIsSmart)
		{
			if (shotClock <= 1)
				return 's';

			else if (bc.getStrength() > df.getStrength() && bc.getLocation() != 7 && bc.getStrength() > 75)
				return 'b';

			else if (bc.getSpeed() > df.getSpeed() + 5 && bc.getLocation() != 7 && bc.getSpeed() > 75)
				return 'd';

			else if (bc.getShot3() > df.getShotContest() + 10 && bc.getLocation() <= 5 && bc.getShot3() > 80)
				return 's';

			else if (bc.getShotMid() > df.getShotContest() + 10 && bc.getLocation() == 6 && bc.getShotMid() > 80)
				return 's';

			else if (bc.getShotClose() > df.getShotContest() && bc.getLocation() == 7 && bc.getShotClose() > 70)
				return 's';

			else
				return 'p';
		}
		else
		{
			int randDecision = rand() % 4;
			if (randDecision == 0 && bc.getLocation() == 7 && bc.getShotClose() >= 70)
				return 's';
			else if (randDecision == 0 && bc.getLocation() == 6 && bc.getShotMid() >= 70)
				return 's';
			else if (randDecision == 0 && bc.getLocation() <= 5 && bc.getShot3() >= 70)
				return 's';
			else if (randDecision == 1 && bc.getSpeed() >= 70)
				return 'd';
			else if (randDecision == 2 && bc.getStrength() >= 70)
				return 'b';
			else
				return 'p';
		}
	}

	void outletPass(Team& t, Team& t2, Babdul& outletPasser, bool AI)
	{
		system("pause");
		system("cls");

		scoreBoard(t);

		cout << endl;
		cout << "==========================="; for (int i = 0; i < t.getTeamName().length(); i++) { cout << "="; } cout << "===========================" << endl;
		cout << ">>>>>>  FAST  BREAK >>>>>> "; t.printTeamName(); cout << " >>>>>> FAST  BREAK  >>>>>>" << endl;
		cout << "==========================="; for (int i = 0; i < t.getTeamName().length(); i++) { cout << "="; } cout << "===========================" << endl;
		cout << endl;

		printOutletPassOptions(t);

		if (AI)
		{
			t.players = babMan.sortBy(t.players, "speed");
			cout << endl << endl; t.printTeamName(); cout << " selects " << t.players.at(0).getBabName() << " to bring the ball up." << endl << endl;
		}
		else
		{
			string outletTarget;
			cout << endl << endl << outletPasser.getBabName() << " currently has the ball. " << endl << endl;
			cout << "Who would you like to outlet the ball to? (Enter current ball handler's name to bring it up without an outlet pass): ";
			cin >> outletTarget;

			if (outletTarget.length() == 6)
				outletTarget = outletTarget + " ";

			bool foundOutletTarget = false;
			for (int i = 0; i < t.getNumPlayers(); i++)
			{
				string newBabName = t.players.at(i).getBabName();
				transform(newBabName.begin(), newBabName.end(), newBabName.begin(), ::tolower);
				string newOutletTarget = outletTarget;
				transform(newOutletTarget.begin(), newOutletTarget.end(), newOutletTarget.begin(), ::tolower);

				if (newOutletTarget == newBabName)
				{
					switchBallCarriers(outletPasser, t.players.at(i));
					outletPasser.setWasPasser(true);
					cout << endl << endl << t.players.at(i).getBabName() << " will bring the ball up." << endl << endl;
					foundOutletTarget = true;
				}
			}

			if (!foundOutletTarget)
			{
				cout << endl << endl << outletTarget << " is on the bench! " << outletPasser.getBabName() << " will bring the ball up himself." << endl << endl;
			}
		}
	}

	void printOutletPassOptions(Team& t)
	{
		vector<Babdul> tempTeam = babMan.sortBy(t.players, "Overall");
		cout << "Babname Position Overall Tier       Build         Babdulishness S-Close S-Mid S-3 PSAC Off-Reb Speed Strength Points Rebounds Assists Blocks Turnovers" << endl;
		cout << "======================================================================================================================================================" << endl;
		for (int i = 0; i < t.getNumPlayers(); i++)
		{
			Babdul p = tempTeam.at(i);
			cout << p.getBabName() << " " <<
				p.getPosition() << "       " <<
				p.getOverall() << "      " <<
				p.getTier() << " " <<
				p.getBuild() << " " <<
				p.getBabdulishness() << "            " <<
				p.getShotClose() << "      " <<
				p.getShotMid() << "    " <<
				p.getShot3() << "  " <<
				p.getPassAccuracy() << "   " <<
				p.getOffRebound() << "      " <<
				p.getSpeed() << "    " <<
				p.getStrength() << "       " <<
				p.getPoints() << "      " <<
				p.getRebounds() << "        " <<
				p.getAssists() << "       " <<
				p.getBlocks() << "      " <<
				p.getTurnovers() <<
				endl;
			cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

		}
	}

	int findPasserIndex(Team team)
	{
		for (int i = 0; i < team.getNumPlayers(); i++)
		{
			if (team.players.at(i).getWasPasser())
			{
				return i;
			}
		}
		return 0;
	}

	int findRebounder(Team& offensiveReboundingTeam, Team& defensiveReboundingTeam)
	{
		// Variable numbers of rebounders
		int numDefensiveRebounders = rand() % 3 + 2; // 2-4
		int numOffensiveRebounders = rand() % 3 + 1; // 1-3

		offensiveReboundingTeam.players = babMan.sortBy(offensiveReboundingTeam.players, "offReb");
		defensiveReboundingTeam.players = babMan.sortBy(defensiveReboundingTeam.players, "defReb");

		// Check for skilled offensive rebounder
		int variation = rand() % 2;
		int randDR = rand() % numDefensiveRebounders;
		if (numOffensiveRebounders > 0)
		{
			int randOR = rand() % numOffensiveRebounders;

			bool offreb = offensiveReboundingTeam.players.at(randOR).attemptOffRebound();
			bool defreb = defensiveReboundingTeam.players.at(randDR).attemptDefRebound();

			if (offreb && !defreb)
			{
				offensiveReboundingTeam.players.at(randOR).setIsRebounder(true);
				logger.debug("[OFF REBOUND] " + offensiveReboundingTeam.players.at(randOR).getBabName());
				return 1;
			}
			else if (!offreb && defreb)
			{
				defensiveReboundingTeam.players.at(randDR).setIsRebounder(true);
				logger.debug("[DEF REBOUND] " + defensiveReboundingTeam.players.at(randDR).getBabName());
				return 2;
			}
			// 50/50
			else
			{
				bool rebounderFound = false;

				for (int i = 0; i < numDefensiveRebounders; i++)
				{
					bool reboundSuccess = defensiveReboundingTeam.players.at(i).attemptDefRebound();
					if (reboundSuccess)
					{
						defensiveReboundingTeam.players.at(i).setIsRebounder(true);
						logger.debug("[DEF REBOUND] " + defensiveReboundingTeam.players.at(i).getBabName());
						rebounderFound = true;
						return 2;
					}
				}

				if (!rebounderFound && numOffensiveRebounders > 0)
				{
					for (int i = 0; i < numOffensiveRebounders; i++)
					{
						bool reboundSuccess = offensiveReboundingTeam.players.at(i).attemptOffRebound();
						if (reboundSuccess)
						{
							offensiveReboundingTeam.players.at(i).setIsRebounder(true);
							logger.debug("[OFF REBOUND] " + offensiveReboundingTeam.players.at(i).getBabName());
							rebounderFound = true;
							return 1;
						}
					}
				}

				// If no rebounder is found, select a random defensive rebounder
				int randRebounderIndex = rand() % 5; // 0-4
				defensiveReboundingTeam.players.at(randRebounderIndex).setIsRebounder(true);
				logger.debug("[DEF REBOUND] " + defensiveReboundingTeam.players.at(randRebounderIndex).getBabName());
				return 2;
			}
		}
		// random defensive rebounder
		else if (numOffensiveRebounders == 0)
		{
			int randRebounderIndex = rand() % 5; // 0-4
			defensiveReboundingTeam.players.at(randRebounderIndex).setIsRebounder(true);
			logger.debug("[DEF REBOUND] " + defensiveReboundingTeam.players.at(randRebounderIndex).getBabName());
			return 2;
		}

		logger.error("No rebounder found");
	}

	void restartGame()
	{
		// Reset Player Stats
		for (int i = 0; i < babMan.team1.getNumPlayers(); i++)
		{
			babMan.team1.players.at(i).points = 0;
			babMan.team1.players.at(i).rebounds = 0;
			babMan.team1.players.at(i).assists = 0;
			babMan.team1.players.at(i).blocks = 0;
		}
		// Reset Player Stats
		for (int i = 0; i < babMan.team2.getNumPlayers(); i++)
		{
			babMan.team2.players.at(i).points = 0;
			babMan.team2.players.at(i).rebounds = 0;
			babMan.team2.players.at(i).assists = 0;
			babMan.team2.players.at(i).blocks = 0;
		}

		team1Score = 0;
		team2Score = 0;

		shotClock = babMan.shotClockLength;
		time = 0;

		isOvertime = false;

		numPasses = 0;
		numDrives = 0;
		numCurrDrives = 0;

		// Create new game
		playGame(babMan.gameLength, babMan.otLength, isASeries, gameNumber, gamesInSeries);
	}

	void pauseMenu(Team& t)
	{
		int option = -1;
		while (option != 0)
		{
			system("cls");

			scoreBoard(t);

			cout << endl;
			cout << "==============================================================================================================" << endl;
			cout << "  <  <  <  <  <  <  <  <  <  <  <  <  <  <  <  <  PAUSE MENU  >  >  >  >  >  >  >  >  >  >  >  >  >  >  >  >  " << endl;
			cout << "==============================================================================================================" << endl;

			cout << endl << endl;
			cout << "  ------------------------" << endl;
			cout << "  (0) Return to Game      " << endl;
			cout << "  ------------------------" << endl;
			cout << "  (1) Restart Game        " << endl;
			cout << "  ------------------------" << endl;
			cout << "  (2) Adjust Sliders      " << endl;
			cout << "  ------------------------" << endl;
			cout << "  (3) Adjust Matchups     " << endl;
			cout << "  ------------------------" << endl;
			cout << "  (4) Box Score           " << endl;
			cout << "  ------------------------" << endl;
			cout << "  (5) Play History        " << endl;
			cout << "  ------------------------" << endl;

			cout << endl << "Please select one of the above options (enter the option number): ";
			cin >> option;

			cout << endl;
			if (option == 0)
			{
				cout << endl << "Returning to game..." << endl << endl;
			}
			else if (option == 1)
			{
				char confirm;
				cout << endl << "Confirm selection of " << option << "? (y/n) ";
				cin >> confirm;

				if (confirm == 'y' || confirm == 'Y')
				{
					cout << "Selection Confirmed" << endl;

					if (option == 1)
					{
						system("cls");
						cout << "The final rosters: " << endl;

						babMan.printTeam(babMan.team1);
						babMan.printTeam(babMan.team2);
						cout << endl;
						restartGame();
					}
					else if (option == 2)
					{
					}
				}
				else
				{
					cout << endl << "Selection Cancelled" << endl;
				}
			}
			else if (option == 2)
			{
				adjustSliders();
			}
			else if (option == 3)
			{
				adjustMatchupsMenu(babMan.team1, babMan.team2);
			}
			else if (option == 4)
			{
				system("cls");
				printBoxScore();
			}
			else if (option == 5)
			{
				system("cls");
				allPlays.printHistoricalPlays();
			}
			else
			{
				cout << endl << "Invalid selection. Please enter a valid number." << endl << endl;
				system("pause");
			}
		}

		// Prevent time change
		shotClock++;
		time--;
	}

	void adjustSliders()
	{
		int option = 1;

		while (option != 0)
		{
			system("cls");
			gameSliders.printSliders();
			cout << endl;
			cout << "Please select an option to modify the sliders:" << endl << endl;
			cout << "(0) Back to pause menu" << endl;
			cout << "(1) Reset sliders to defaults" << endl;
			cout << "(2) Set all sliders at once" << endl;
			cout << "(3) Set an individual slider" << endl;
			cout << "(4) Load slider preset" << endl;
			cout << endl;

			cin >> option;

			// (0) Back to pause menu
			if (option == 0)
			{
				cout << "Returning to pause menu..." << endl;
			}
			// (1) Reset sliders to defaults
			else if (option == 1)
			{
				gameSliders.setSliders("Default", 1.0f);
			}
			// (2) Set all sliders at once
			else if (option == 2)
			{
				float newSlider;
				cout << "Please enter the new slider value (any decimal between 0 and 2): ";
				cin >> newSlider;

				if (newSlider < 0)
					gameSliders.setSliders("Custom", 0);
				else if (newSlider > 2)
					gameSliders.setSliders("Custom", 2);
				else
					gameSliders.setSliders("Custom", newSlider);
			}
			// (3) Set an individual slider
			else if (option == 3)
			{
				int newSliderName = -1;
				float newSliderValue = 1;

				cout << "Please enter the number of the slider you would like to change: ";
				cin >> newSliderName;

				cout << endl << endl;

				if (newSliderName == 1)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for babdulishness (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("babdulishness", newSliderValue);
				}
				else if (newSliderName == 2)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for shot close (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("shotClose", newSliderValue);
				}
				else if (newSliderName == 3)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for shot mid (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("shotMid", newSliderValue);
				}
				else if (newSliderName == 4)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for shot 3 (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("shot3", newSliderValue);
				}
				else if (newSliderName == 5)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for pass accuracy (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("passAccuracy", newSliderValue);
				}
				else if (newSliderName == 6)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for perimeter D (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("perimeterD", newSliderValue);
				}
				else if (newSliderName == 7)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for interior D (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("interiorD", newSliderValue);
				}
				else if (newSliderName == 8)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for shot contest (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("shotContest", newSliderValue);
				}
				else if (newSliderName == 9)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for block (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("block", newSliderValue);
				}
				else if (newSliderName == 10)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for def rebound (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("defRebound", newSliderValue);
				}
				else if (newSliderName == 11)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for off rebound (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("offRebound", newSliderValue);
				}
				else if (newSliderName == 12)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for strength (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("strength", newSliderValue);
				}
				else if (newSliderName == 13)
				{
					gameSliders.setSliderName("Custom");
					cout << "Please enter the new slider value for speed (any decimal between 0 and 2): ";
					cin >> newSliderValue;
					if (newSliderValue > 2) { newSliderValue = 2; }
					else if (newSliderValue < 0) { newSliderValue = 0; }
					gameSliders.setSlider("speed", newSliderValue);
				}
				else
				{
					cout << "Invalid number" << endl;
				}
			}
			else if (option == 4)
			{
				// Setup Sliders

				Sliders preset_Default; // Default
				preset_Default.setSliders("Default", 1);

				Sliders preset_AllMaxed; // Max All
				preset_AllMaxed.setSliders("Max All", 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2);

				Sliders preset_AllMined; // Min All
				preset_AllMined.setSliders("Min All", 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

				Sliders preset_Offense; // Offense Oriented
				preset_Offense.setSliders("Offense Oriented", 0.5, 1.5, 1.5, 1.5, 2, 0.5, 0.5, 0.5, 0.5, 0.5, 1.5, 1.5, 1.5);

				Sliders preset_Defense; // Defense Oriented
				preset_Defense.setSliders("Defense Oriented", 0.8, 0.8, 0.8, 0.8, 0.8, 1.5, 1.5, 1.5, 1.5, 1.5, 0.5, 0.8, 0.8);

				Sliders preset_NoBabdulishness; // No Babdulishness
				preset_NoBabdulishness.setSliders("No Babdulishness", 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);

				Sliders preset_PerfectPassing; // Perfect Passing
				preset_PerfectPassing.setSliders("Perfect Passing", 0, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1);

				// Display Options
				system("cls");
				gameSliders.printSlidersHeader();
				cout << "(0) Back" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
				cout << "(1) "; preset_Default.printSlidersHorizontally();
				cout << "(2) "; preset_AllMaxed.printSlidersHorizontally();
				cout << "(3) "; preset_AllMined.printSlidersHorizontally();
				cout << "(4) "; preset_Offense.printSlidersHorizontally();
				cout << "(5) "; preset_Defense.printSlidersHorizontally();
				cout << "(6) "; preset_NoBabdulishness.printSlidersHorizontally();
				cout << "(7) "; preset_PerfectPassing.printSlidersHorizontally();
				cout << endl;
				int option;
				cout << "Please enter the number of the desired slider preset: ";
				cin >> option;
				if (option == 0)
				{
					gameSliders = gameSliders;
				}
				else if (option == 1)
				{
					gameSliders = preset_Default;
				}
				else if (option == 2)
				{
					gameSliders = preset_AllMaxed;
				}
				else if (option == 3)
				{
					gameSliders = preset_AllMined;
				}
				else if (option == 4)
				{
					gameSliders = preset_Offense;
				}
				else if (option == 5)
				{
					gameSliders = preset_Defense;
				}
				else if (option == 6)
				{
					gameSliders = preset_NoBabdulishness;
				}
				else if (option == 7)
				{
					gameSliders = preset_PerfectPassing;
				}
				else
				{
					cout << "Invalid Number" << endl;
				}
			}
		}

		applyGameSlidersToPlayers();
	}

	void adjustMatchupsMenu(Team& team1, Team& team2)
	{
		int teamSelect = 1;

		while (teamSelect != 0)
		{
			system("cls");
			cout << "=============" << endl;
			cout << "EDIT MATCHUPS" << endl;
			cout << "=============" << endl;
			cout << endl;

			cout << "(0) Exit" << endl;
			cout << "(1) "; team1.printTeamName(); cout << endl;
			cout << "(2) "; team2.printTeamName(); cout << endl;
			cout << endl;

			cout << "Which team would like to adjust their matchups? (0/1/2) ";
			cin >> teamSelect;

			system("cls");
			if (teamSelect == 2)
			{
				int option = -1;

				while (option != 0)
				{
					displayMatchups(team1, team2);
					cout << endl;
					cout << "(0)     Back" << endl;
					cout << "(1)-(5) Set Matchup" << endl;
					cout << "(6)     Default Matchups" << endl;

					cout << endl << "Please select one of the available options: ";
					cin >> option;

					if (option == 0)
					{
						cout << "Going back..." << endl;
					}
					else if (option > 0 && option < 6)
					{
						int playerToSwitch;
						cout << "Which player would you like to switch onto " << team2.players.at(option - 1).getBabName() << "? (1-5) ";
						cin >> playerToSwitch;

						string tempMatchup = team1.players.at(playerToSwitch - 1).getMatchup();
						team1.players.at(playerToSwitch - 1).setMatchup(team1.players.at(option - 1).getMatchup());
						team1.players.at(option - 1).setMatchup(tempMatchup);
					}
					else if (option == 6)
					{
						setDefaultMatchups(team1, team2);
					}
				}
			}
			else if (teamSelect == 1)
			{
				int option = -1;

				while (option != 0)
				{
					displayMatchups(team2, team1);
					cout << endl;
					cout << "0   Back" << endl;
					cout << "1-5 Set Matchup" << endl;
					cout << "6   Default Matchups" << endl;

					cout << endl << "Please select one of the available options: ";
					cin >> option;

					if (option == 0)
					{
						cout << "Going back..." << endl;
					}
					else if (option > 0 && option < 6)
					{
						int playerToSwitch;
						cout << "Which player would you like to switch onto " << team1.players.at(option - 1).getBabName() << "? (1-5) ";
						cin >> playerToSwitch;

						string tempMatchup = team2.players.at(playerToSwitch - 1).getMatchup();
						team2.players.at(playerToSwitch - 1).setMatchup(team2.players.at(option - 1).getMatchup());
						team2.players.at(option - 1).setMatchup(tempMatchup);
					}
					else if (option == 6)
					{
						setDefaultMatchups(team2, team1);
					}
				}
			}
		}
	}

	void displayMatchups(Team& team1, Team& team2)
	{
		system("cls");
		cout << "=============" << endl;
		cout << "EDIT MATCHUPS" << endl;
		cout << "=============" << endl;

		// Player 0
		cout << endl;
		int player0MatchupIndex = findDefensiveMatchupIndex(team1.players.at(0), team2);
		cout << "             BabName Position Tier       Build         Age Weight Height      Overall Babdulishness S-Close S-Mid S-3 PSAC Per-D Int-D S-Contest Block Def-Reb Off-Reb Speed Strength" << endl;
		cout << "             ========================================================================================================================================================================" << endl;
		cout << "Opponent 1:  ";
		team1.players.at(0).printStatsHorizontally();
		cout << "Defended by: ";
		team2.players.at(player0MatchupIndex).printStatsHorizontally();

		// Player 1
		cout << endl;
		int player1MatchupIndex = findDefensiveMatchupIndex(team1.players.at(1), team2);
		cout << "             BabName Position Tier       Build         Age Weight Height      Overall Babdulishness S-Close S-Mid S-3 PSAC Per-D Int-D S-Contest Block Def-Reb Off-Reb Speed Strength" << endl;
		cout << "             ========================================================================================================================================================================" << endl;
		cout << "Opponent 2:  ";
		team1.players.at(1).printStatsHorizontally();
		cout << "Defended by: ";
		team2.players.at(player1MatchupIndex).printStatsHorizontally();

		// Player 2
		cout << endl;
		int player2MatchupIndex = findDefensiveMatchupIndex(team1.players.at(2), team2);
		cout << "             BabName Position Tier       Build         Age Weight Height      Overall Babdulishness S-Close S-Mid S-3 PSAC Per-D Int-D S-Contest Block Def-Reb Off-Reb Speed Strength" << endl;
		cout << "             ========================================================================================================================================================================" << endl;
		cout << "Opponent 3:  ";
		team1.players.at(2).printStatsHorizontally();
		cout << "Defended by: ";
		team2.players.at(player2MatchupIndex).printStatsHorizontally();

		// Player 3
		cout << endl;
		int player3MatchupIndex = findDefensiveMatchupIndex(team1.players.at(3), team2);
		cout << "             BabName Position Tier       Build         Age Weight Height      Overall Babdulishness S-Close S-Mid S-3 PSAC Per-D Int-D S-Contest Block Def-Reb Off-Reb Speed Strength" << endl;
		cout << "             ========================================================================================================================================================================" << endl;
		cout << "Opponent 4:  ";
		team1.players.at(3).printStatsHorizontally();
		cout << "Defended by: ";
		team2.players.at(player3MatchupIndex).printStatsHorizontally();

		// Player 4
		cout << endl;
		int player4MatchupIndex = findDefensiveMatchupIndex(team1.players.at(4), team2);
		cout << "             BabName Position Tier       Build         Age Weight Height      Overall Babdulishness S-Close S-Mid S-3 PSAC Per-D Int-D S-Contest Block Def-Reb Off-Reb Speed Strength" << endl;
		cout << "             ========================================================================================================================================================================" << endl;
		cout << "Opponent 5:  ";
		team1.players.at(4).printStatsHorizontally();
		cout << "Defended by: ";
		team2.players.at(player4MatchupIndex).printStatsHorizontally();
	}

	void setDefaultMatchups(Team& team1, Team& team2)
	{
		// Default matchups, matching up defensive shot contest against opponent shot 3
		team1.players = babMan.sortBy(team1.players, "shot3");
		team2.players = babMan.sortBy(team2.players, "shotContest");

		for (int i = 0; i < team1.getNumPlayers(); i++)
		{
			team1.players.at(i).setMatchup(team2.players.at(i).getBabName());
		}
	}

	void updateMatchups(int numDrives, Team& team1, Team& team2)
	{
		if (numDrives > 0)
		{
			for (int i = 0; i < team1.getNumPlayers(); i++)
			{
				int currDefenderIndex;
				for (int j = 0; j < team2.getNumPlayers(); j++)
				{
					if (team2.players.at(j).getBabName() == team1.players.at(i).getMatchup())
					{
						currDefenderIndex = j;
					}
				}
				int newDefenderIndex = currDefenderIndex + numDrives;
				if (newDefenderIndex >= 5)
				{
					newDefenderIndex -= 5;
				}

				team1.players.at(i).setMatchup(team2.players.at(newDefenderIndex).getBabName());
				logger.debug("[MATCHUP CHANGE] Changed " + team1.players.at(i).getBabName() + "'s matchup from index " + to_string(currDefenderIndex) + " to " + to_string(newDefenderIndex));
			}
		}
	}

	int getCurrPlayerIndex(Team& team1)
	{
		for (int i = 0; i < team1.getNumPlayers(); i++)
		{
			if (team1.players.at(i).getBallCarrier() == true)
			{
				return i;
			}
		}
		logger.error("Unable to find current player index");
	}

	int getDefenderIndex(Team& team1, Team& team2)
	{
		for (int i = 0; i < team1.getNumPlayers(); i++)
		{
			if (team1.players.at(i).getBallCarrier() == true)
			{
				for (int j = 0; j < team2.getNumPlayers(); j++)
				{
					if (team2.players.at(j).getBabName() == team1.players.at(i).getMatchup())
					{
						return j;
					}
				}
			}
		}
		logger.error("Unable to find defender index");
	}

	void randomizeMatchups(Team& team1, Team& team2)
	{
		string randSortBy;
		int randomMatchupValue = rand() % 24;

		if (randomMatchupValue == 0) { randSortBy = "babname"; }
		else if (randomMatchupValue == 1) { randSortBy = "age"; }
		else if (randomMatchupValue == 2) { randSortBy = "weight"; }
		else if (randomMatchupValue == 3) { randSortBy = "height"; }
		else if (randomMatchupValue == 4) { randSortBy = "position"; }
		else if (randomMatchupValue == 5) { randSortBy = "tier"; }
		else if (randomMatchupValue == 6) { randSortBy = "build"; }
		else if (randomMatchupValue == 7) { randSortBy = "babdulishness"; }
		else if (randomMatchupValue == 8) { randSortBy = "overall"; }
		else if (randomMatchupValue == 9) { randSortBy = "points"; }
		else if (randomMatchupValue == 10) { randSortBy = "blocks"; }
		else if (randomMatchupValue == 11) { randSortBy = "assists"; }
		else if (randomMatchupValue == 12) { randSortBy = "shotClose"; }
		else if (randomMatchupValue == 13) { randSortBy = "shotMid"; }
		else if (randomMatchupValue == 14) { randSortBy = "shot3"; }
		else if (randomMatchupValue == 15) { randSortBy = "passAccuracy"; }
		else if (randomMatchupValue == 16) { randSortBy = "perimeterD"; }
		else if (randomMatchupValue == 17) { randSortBy = "interiorD"; }
		else if (randomMatchupValue == 18) { randSortBy = "shotContest"; }
		else if (randomMatchupValue == 19) { randSortBy = "block"; }
		else if (randomMatchupValue == 20) { randSortBy = "defReb"; }
		else if (randomMatchupValue == 21) { randSortBy = "offReb"; }
		else if (randomMatchupValue == 22) { randSortBy = "speed"; }
		else if (randomMatchupValue == 23) { randSortBy = "strength"; }
		else { randSortBy = "shotContest"; cout << "Can't find randomized matchup, defaulting to shotContest." << endl; }

		team1.players = babMan.sortBy(team1.players, "shot3");
		team2.players = babMan.sortBy(team2.players, randSortBy);

		for (int i = 0; i < team1.getNumPlayers(); i++)
		{
			team1.players.at(i).setMatchup(team2.players.at(i).getBabName());
		}
	}

	int findDefensiveMatchupIndex(Babdul& offensivePlayer, Team& team2)
	{
		for (int i = 0; i < team2.getNumPlayers(); i++)
		{
			if (team2.players.at(i).getBabName() == offensivePlayer.getMatchup())
			{
				return i;
			}
		}
		cout << "Could not find defensive matchup" << endl;
		return 0;
	}

};