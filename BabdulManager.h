#include "Team.h"

class BabdulManager
{
public:

	int numUsers = 1;
	int gameLength = 30;
	int otLength = 15;
	int shotClockLength = 5;

	vector<Babdul> draftClass;
	vector<Babdul> customBabdulsInDraft;
	vector<Babdul> savedBabduls;

	Team team1;
	Team team2;

	vector<Team> teams;

	Babdul babReference;

	int setup(int draftSize)
	{
		int option = -1;
		while (option != 1 && option != 2)
		{
			system("cls");
			setTextColor(DARK_YELLOW);
			cout << "O=====================================================================================================================================O" << endl;
			cout << "|                                               -   -   -      S E T U P      -   -   -                                               |" << endl;
			cout << "O=====================================================================================================================================O" << endl << endl;

			setDefaultTextColor();
			cout << "Please select one of the available setup options:" << endl;

			setTextColor(RED);
			cout << "     0 Back" << endl;
			setTextColor(GRAY);
			cout << "     1 Dev Mode" << endl;
			setTextColor(GREEN);
			cout << "     2 Play" << endl;
			setDefaultTextColor();
			cout << "     3 Settings" << endl;
			cout << endl;
			cin >> option;

			if (option == 0)
			{
				return -1;
			}
			else if (option == 1)
			{
				createTeams(true);
				createDraftClass(customBabdulsInDraft, draftSize);
				draft(true);
			}
			else if (option == 2)
			{
				numUsersMenu();
				createTeams(false);
				//loadSavedBabdulsFromFile();
				//manageCustomBabduls();
				createDraftClass(customBabdulsInDraft, draftSize);
				draft(false);
			}
			else if (option == 3)
			{
				settings(draftSize);
			}
			else
			{
				cout << "Invalid option. Please select one of the available options" << endl << endl;
				system("pause");
			}
			return 1;
		}
	}

	void settings(int draftSize)
	{
		int option = -1;
		while (option != 0)
		{
			system("cls");
			cout << "O=====================================================================================================================================O" << endl;
			cout << "|                                            -   -   -      S E T T I N G S      -   -   -                                            |" << endl;
			cout << "O=====================================================================================================================================O" << endl << endl;

			cout << "Please select one of the available setup options:" << endl;

			cout << "     0 Back" << endl;
			cout << "     1 Game Settings" << endl;
			cout << "     2 Manage Custom Babduls" << endl;
			cout << endl;
			cin >> option;

			if (option == 0)
			{
				setup(draftSize);
			}
			else if (option == 1)
			{
				gameSettings();
			}
			else if (option == 2)
			{
				manageCustomBabduls();
			}
			else
			{
				cout << "Invalid option. Please select one of the available options" << endl << endl;
				system("pause");
			}
		}
	}

	void numUsersMenu()
	{
		system("cls");
		cout << "O=====================================================================================================================================O" << endl;
		cout << "|                                             -   -   -      P L A Y E R S      -   -   -                                             |" << endl;
		cout << "O=====================================================================================================================================O" << endl << endl;

		cout << endl << endl;

		cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "How many players would like to play? (0, 1, 2)                                                                                      ";
		cin >> numUsers;
		cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;

		cout << endl << endl;
		system("pause");
	}

	void gameSettings()
	{
		int option = -1;
		while (option != 0)
		{
			system("cls");
			cout << "O=====================================================================================================================================O" << endl;
			cout << "|                                               -   -   -      S E T U P      -   -   -                                               |" << endl;
			cout << "O=====================================================================================================================================O" << endl << endl;

			cout << endl << endl;

			cout << "Please enter the number of the option to edit" << endl << endl;
			cout << "(0) BACK" << endl;
			cout << "(1) GAME LENGTH:\t" << gameLength << endl;
			cout << "(2) OT LENGTH:\t\t" << otLength << endl;
			cout << "(3) SHOT CLOCK:\t\t" << shotClockLength << endl;
			cout << endl;

			cin >> option;
			if (option == 1)
			{
				cout << "NEW GAME LENGTH: ";
				cin >> gameLength;
				if (gameLength < 1) { gameLength = 5; }
				else if (gameLength > 99) { gameLength = 99; }
			}
			else if (option == 2)
			{
				cout << "NEW OT LENGTH: ";
				cin >> otLength;
				if (otLength < 1) { otLength = 5; }
				else if (otLength > 99) { otLength = 99; }
			}
			else if (option == 3)
			{
				cout << "NEW SHOT CLOCK: ";
				cin >> shotClockLength;
				if (shotClockLength < 1) { shotClockLength = 1; }
				else if (shotClockLength > 30) { shotClockLength = 30; }
			}
			else if (option != 0)
			{
				cout << "Invalid option. Please select one of the available options." << endl;
				system("pause");
			}
		}
	}

	void printAvailableColors()
	{
		cout << "Available colors:";
		setTextColor(1); cout << " Blue"; setDefaultTextColor(); cout << "(1)";
		setTextColor(2); cout << " Green"; setDefaultTextColor(); cout << "(2)";
		setTextColor(3); cout << " Cyan"; setDefaultTextColor(); cout << "(3)";
		setTextColor(4); cout << " Red"; setDefaultTextColor(); cout << "(4)";
		setTextColor(5); cout << " Purple"; setDefaultTextColor(); cout << "(5)";
		setTextColor(6); cout << " Dark Yellow"; setDefaultTextColor(); cout << "(6)";
		setTextColor(7); cout << " White"; setDefaultTextColor(); cout << "(7)";
		setTextColor(8); cout << " Gray"; setDefaultTextColor(); cout << "(8)";
		setTextColor(9); cout << " Bright Blue"; setDefaultTextColor(); cout << "(9)";
		setTextColor(10); cout << " Bright Green"; setDefaultTextColor(); cout << "(10)";
		setTextColor(11); cout << " Bright Cyan"; setDefaultTextColor(); cout << "(11)";
		setTextColor(12); cout << " Bright Red"; setDefaultTextColor(); cout << "(12)";
		setTextColor(13); cout << " Pink"; setDefaultTextColor(); cout << "(13)";
		setTextColor(14); cout << " Yellow"; setDefaultTextColor(); cout << "(14)";
		setTextColor(15); cout << " Bright White"; setDefaultTextColor(); cout << "(15)";
		cout << endl;
	}

	void createTeams(bool sim)
	{
		if (!sim)
		{
			system("cls");
			cout << "=========================" << endl;
			cout << "PREGAME STEP: SETUP TEAMS" << endl;
			cout << "=========================" << endl << endl;

			if (numUsers == 2)
			{
				// Team 1 Creation
				cout << "----------------------------------" << endl;
				cout << "Player 1 please enter a team name: ";
				string team1Name;
				cin >> team1Name;
				Team userTeam1(team1Name, 5);
				cout << endl;
				printAvailableColors();
				cout << "Player 1 please enter a team color (enter the number 1-15): ";
				int team1Color = 0;
				while (team1Color < 1 || team1Color > 15)
				{
					cin >> team1Color;
					if (team1Color < 1 || team1Color > 15)
					{
						cout << endl << "Color unavailable, please select a number between 1 and 15: ";
						logger.info("User selected color " + to_string(team1Color) + ", which is unavailable. User was asked to select an available color (1-15)");
					}
					else
					{
						userTeam1.setTeamColor(team1Color);
						logger.info("Team 1 color set to " + userTeam1.getTeamColor());
					}
				}
				team1 = userTeam1;
				cout << endl << endl << "Welcome ";	team1.printTeamName(); cout << "!" << endl << endl;

				// Team 2 Creation
				cout << "----------------------------------" << endl;
				cout << "Player 2 please enter a team name: ";
				string team2Name;
				cin >> team2Name;
				Team userTeam2(team2Name, 5);
				cout << endl;
				printAvailableColors();
				cout << "Player 2 please enter a team color (enter the number 1-15): ";
				int team2Color = 0;
				while (team2Color < 1 || team2Color > 15)
				{
					cin >> team2Color;
					if (team2Color < 1 || team2Color > 15)
					{
						cout << endl << "Color unavailable, please select a number between 1 and 15: ";
						logger.info("User selected color " + to_string(team2Color) + ", which is unavailable. User was asked to select an available color (1-15)");
					}
					else
					{
						userTeam2.setTeamColor(team2Color);
						logger.info("Team 2 color set to " + userTeam2.getTeamColor());
					}
				}
				team2 = userTeam2;
				cout << endl << endl << "Welcome "; team2.printTeamName(); cout << "!" << endl << endl;
			}
			else if (numUsers == 1)
			{
				// Team 1 Creation
				cout << "----------------------------------" << endl;
				cout << "Please enter a team name: ";
				string team1Name;
				cin >> team1Name;
				Team userTeam1(team1Name, 5);
				team1 = userTeam1; cout << endl;
				printAvailableColors();
				cout << "Player 1 please enter a team color (enter the number 1-15): ";
				int team1Color = 0;
				while (team1Color < 1 || team1Color > 15)
				{
					cin >> team1Color;
					if (team1Color < 1 || team1Color > 15)
					{
						cout << "Color unavailable, please select a number between 1 and 15: ";
						logger.info("User selected color " + to_string(team1Color) + ", which is unavailable. User was asked to select an available color (1-15)");
					}
					else
					{
						userTeam1.setTeamColor(team1Color);
						logger.info("Team 1 color set to " + userTeam1.getTeamColor());
					}
				}
				team1 = userTeam1;
				cout << endl << endl << "Welcome "; team1.printTeamName(); cout << "!" << endl << endl;

				// Team 2 Creation
				Team team_2("AI", DEFAULT, 5);
				team2 = team_2;
			}
			else if (numUsers == 0)
			{
				Team team_1("AI 1", BLUE, 5);
				team1 = team_1;

				Team team_2("AI 2", YELLOW, 5);
				team2 = team_2;
			}

			system("pause");
		}
		else
		{
			if (numUsers == 2)
			{
				Team team_1("Player 1", BRIGHT_BLUE, 5);
				team1 = team_1;

				Team team_2("Player 2", BRIGHT_GREEN, 5);
				team2 = team_2;
			}
			else if (numUsers == 1)
			{
				Team team_1("Player", BRIGHT_BLUE, 5);
				team1 = team_1;

				Team team_2("AI", BRIGHT_GREEN, 5);
				team2 = team_2;
			}
			else if (numUsers == 0)
			{
				Team team_1("AI 1", BRIGHT_BLUE, 5);
				team1 = team_1;

				Team team_2("AI 2", BRIGHT_GREEN, 5);
				team2 = team_2;
			}
		}
	}

	void manageCustomBabduls()
	{
		string option = "-1";

		while (option != "0")
		{
			if (savedBabduls.size() > 0)
				writeSavedBabdulsToFile();
			loadSavedBabdulsFromFile();

			system("cls");
			cout << "==============" << endl;
			cout << "CUSTOM BABDULS" << endl;
			cout << "==============" << endl << endl;


			cout << "BabNumber Babname           Overall Position Draftable" << endl;
			cout << "======================================================" << endl;
			for (int i = 0; i < savedBabduls.size(); i++)
			{
				string numberGap = "";
				if (i > 10)
					numberGap = " ";

				int nameLength = savedBabduls.at(i).getBabName().length();
				int nameBuffer = 18 - nameLength;
				string nameBufferString = "";
				for (int i = 0; i < nameBuffer; i++)
				{
					nameBufferString = nameBufferString + " ";
				}

				cout << i + 1 << "         " << numberGap;
				cout << savedBabduls.at(i).getBabName() << nameBufferString;
				cout << savedBabduls.at(i).getOverall() << "      ";
				cout << savedBabduls.at(i).getPosition() << "       ";
				if (savedBabduls.at(i).getIsInDraft()) { cout << "Yes" << endl; } else { cout << "No" << endl; }
				cout << "------------------------------------------------------" << endl;
			}

			cout << endl << "Toggle which players should be entered into the draft using the BabNumber." << endl;
			cout << "Press n to create a new player." << endl;
			cout << "Press d to delete a player." << endl;
			cout << "Press 0 to save and finish." << endl << endl;

			cin >> option;


			if (option == "0")
			{
				cout << "Going back..." << endl;
			}
			else if (option == "d" || option == "D")
			{
				int deleteOption;
				cout << "Enter the number of the player you wish to delete: ";
				cin >> deleteOption;

				if (deleteOption > 0 && deleteOption <= savedBabduls.size())
				{
					savedBabduls.erase(savedBabduls.begin() + deleteOption - 1);
				}
				else
				{
					cout << "Could not find the specified index" << endl;
				}
			}
			else if (option == "n" || option == "N")
			{
				createCustomBabdulMenu(999999);
			}
			else
			{
				int optionInt = stoi(option);
				cout << "optionInt: " << optionInt << endl;

				if (optionInt <= savedBabduls.size() && optionInt > 0)
				{
					if (savedBabduls.at(optionInt - 1).getIsInDraft())
					{
						savedBabduls.at(optionInt - 1).setIsInDraft(false);
					}
					else
					{
						savedBabduls.at(optionInt - 1).setIsInDraft(true);
					}
				}
				else
				{
					cout << "Invalid input" << endl;
				}
			}
		}

		// Add custom babduls that should be in draft
		for (int i = 0; i < savedBabduls.size(); i++)
		{
			if (savedBabduls.at(i).getIsInDraft())
			{
				customBabdulsInDraft.push_back(savedBabduls.at(i));
			}
		}

		// Remove custom babduls that should not be in draft
		for (int i = 0; i < customBabdulsInDraft.size(); i++)
		{
			if (!customBabdulsInDraft.at(i).getIsInDraft())
			{
				customBabdulsInDraft.erase(customBabdulsInDraft.begin() + i);
			}
		}
	}

	void createDraftClass(int size)
	{
		for (int i = 0; i < size; i++)
		{
			Babdul bab;
			draftClass.push_back(bab);
		}
	}

	void createDraftClass(vector<Babdul> userBabduls, int size)
	{
		logger.info("Creating draft class...");
		for (int i = 0; i < userBabduls.size(); i++)
		{
			draftClass.push_back(userBabduls.at(i));
		}
		for (int i = 0; i < (size - userBabduls.size()); i++)
		{
			Babdul bab(i);
			draftClass.push_back(bab);
		}

		if (draftClass.size() == size)
		{
			logger.skipLine();
			logger.divider("=");
			logger.info("SUCCESS! " + to_string(draftClass.size()) + "/" + to_string(size) + " Babduls successfully added to the draft class");
			logger.divider("=");
			logger.skipLine();
		}
		else
		{
			logger.skipLine();
			logger.warn("SUCCESS - draft class created with warning: " + to_string(draftClass.size()) + "/" + to_string(size) + " Babduls added to draft");
			logger.skipLine();
		}
	}

	void createCustomBabdul(string name, pair<int, int> height, int weight, string position, string tier, string build, float babdulishness, int shotClose, int shotMid, int shot3, int passAccuracy, int perimeterD, int interiorD, int shotContest, int block, int defRebound, int offRebound, int speed, int strength, bool isInDraft)
	{
		Babdul customBab(name, height, weight, position, tier, build, babdulishness, shotClose, shotMid, shot3, passAccuracy, perimeterD, interiorD, shotContest, block, defRebound, offRebound, speed, strength, isInDraft);
		//customBabdulsInDraft.push_back(customBab);
		savedBabduls.push_back(customBab);
	}

	void createCustomBabdulMenu(int draftsize)
	{
		system("cls");

		if (customBabdulsInDraft.size() >= draftsize)
		{
			cout << "Draft class is full" << endl;
			return;
		}

		cout << "====================" << endl;
		cout << "CREATE CUSTOM BABDUL" << endl;
		cout << "====================" << endl << endl;

		system("cls");
		cout << "Please enter a name for your Babdul: ";
		string name;
		cin >> name;
		cout << endl;

		cout << "Please enter a height (feet) value for " << name << ": ";
		int height_feet;
		cin >> height_feet;
		cout << endl;

		cout << "Please enter a height (inches) value for " << name << ": ";
		int height_inches;
		cin >> height_inches;
		cout << endl;

		cout << "Please enter a weight value for " << name << ": ";
		int weight;
		cin >> weight;
		cout << endl;

		// WEIGHT VERIFICATION // --------------------------------------------------------------------------------------------------
		if (weight < 100)
			weight = 100;
		if (weight > 999)
			weight = 999;
		// ---------------------------------------------------------------------------------------------------------------------------

		cout << "Please enter a position (PG,SG,SF,PF,C) value for " << name << ": ";
		string position;
		cin >> position;
		cout << endl;

		// POSITION VERIFICATION // --------------------------------------------------------------------------------------------------

		if (position.at(0) == '0' || position.at(0) == '1' || position.at(0) == '2' || position.at(0) == '3' || position.at(0) == '4' || position.at(0) == '5' || position.at(0) == '6' || position.at(0) == '7' || position.at(0) == '8' || position.at(0) == '9')
		{
			cout << "Position not found, defaulting to PG." << endl;
			position = "PG";
		}
		else
		{
			// Capitalize letters if not already capitalized
			position.at(0) = toupper(position.at(0));
			if (position.length() > 1)
				position.at(1) = toupper(position.at(1));

			if (position == "C")
				position = "C ";

			if (position != "PG" && position != "SG" && position != "SF" && position != "PF" && position != "C ")
			{
				cout << "Position not found, defaulting to PG." << endl;
				position = "PG";
			}
		}
		// ---------------------------------------------------------------------------------------------------------------------------

		cout << "Please enter a tier ("; for (int i = 0; i < babReference.playerTiers.size(); i++) { cout << babReference.playerTiers.at(i); if (i != babReference.playerTiers.size()) { cout << ", "; } }; cout << ") value for " << name << ". (Please use capitals and underscores to match option): ";
		string tier;
		cin >> tier;
		cout << endl;

		// TIER VERIFICATION // ------------------------------------------------------------------------------------------------------

		// Add whitespace to tier
		if (tier.length() < 10)
		{
			for (int i = tier.length(); i < 10; i++)
			{
				tier = tier + " ";
			}
		}

		// Capitalize first letter if not already capitalized
		tier.at(0) = toupper(tier.at(0));

		if (tier == "All-star")
			tier = "All-Star";

		bool tierFound = false;
		for (int i = 0; i < babReference.playerTiers.size(); i++)
		{
			if (tier == babReference.playerTiers.at(i))
			{
				tierFound = true;
			}
		}

		if (tierFound == false)
		{
			cout << "Tier not found, defaulting to the lowest tier." << endl;
			tier = babReference.playerTiers.at(0);
		}
		// ---------------------------------------------------------------------------------------------------------------------------

		cout << "Please enter a build (";
		if (position == "PG")
		{
			for (int i = 0; i < babReference.PG_Builds.size(); i++)
			{
				cout << babReference.PG_Builds.at(i);
				if (i != babReference.PG_Builds.size())
					cout << ", ";
			}
		}
		else if (position == "SG")
		{
			for (int i = 0; i < babReference.SG_Builds.size(); i++)
			{
				cout << babReference.SG_Builds.at(i);
				if (i != babReference.SG_Builds.size())
					cout << ", ";
			}
		}
		else if (position == "SF")
		{
			for (int i = 0; i < babReference.SF_Builds.size(); i++)
			{
				cout << babReference.SF_Builds.at(i);
				if (i != babReference.SF_Builds.size())
					cout << ", ";
			}
		}
		else if (position == "PF")
		{
			for (int i = 0; i < babReference.PF_Builds.size(); i++)
			{
				cout << babReference.PF_Builds.at(i);
				if (i != babReference.PF_Builds.size())
					cout << ", ";
			}
		}
		else if (position == "C ")
		{
			for (int i = 0; i < babReference.C_Builds.size(); i++)
			{
				cout << babReference.C_Builds.at(i);
				if (i != babReference.C_Builds.size())
					cout << ", ";
			}
		}
		cout << ") value for " << name << ". (Please use capitals and underscores to match option): ";
		string build;
		cin >> build;
		cout << endl;

		// BUILD VERIFICATION // -----------------------------------------------------------------------------------------------------

		// Add whitespace to build
		if (build.length() < 13)
		{
			for (int i = build.length(); i < 13; i++)
			{
				build = build + " ";
			}
		}

		// Capitalize first letter if not already capitalized
		build.at(0) = toupper(build.at(0));

		bool buildFound = false;
		if (position == "PG")
		{
			for (int i = 0; i < babReference.PG_Builds.size(); i++)
			{
				if (build == babReference.PG_Builds.at(i))
					buildFound = true;
			}
		}
		else if (position == "SG")
		{
			for (int i = 0; i < babReference.SG_Builds.size(); i++)
			{
				if (build == babReference.SG_Builds.at(i))
					buildFound = true;
			}
		}
		else if (position == "SF")
		{
			for (int i = 0; i < babReference.SF_Builds.size(); i++)
			{
				if (build == babReference.SF_Builds.at(i))
					buildFound = true;
			}
		}
		else if (position == "PF")
		{
			for (int i = 0; i < babReference.PF_Builds.size(); i++)
			{
				if (build == babReference.PF_Builds.at(i))
					buildFound = true;
			}
		}
		else if (position == "C ")
		{
			for (int i = 0; i < babReference.C_Builds.size(); i++)
			{
				if (build == babReference.C_Builds.at(i))
					buildFound = true;
			}
		}

		if (buildFound == false)
		{
			cout << "Build not found, defaulting to All Around build." << endl;
			build = babReference.ALL_Builds.at(0);
		}
		// ---------------------------------------------------------------------------------------------------------------------------

		cout << "Please enter a babdulishness value for " << name << ": ";
		float babdulishness;
		cin >> babdulishness;
		cout << endl;

		cout << "Please enter a shot close value for " << name << ": ";
		int shotClose;
		cin >> shotClose;
		cout << endl;

		cout << "Please enter a shot mid value for " << name << ": ";
		int shotMid;
		cin >> shotMid;
		cout << endl;

		cout << "Please enter a shot 3 value for " << name << ": ";
		int shot3;
		cin >> shot3;
		cout << endl;

		cout << "Please enter a pass accuracy value for " << name << ": ";
		int passAccuracy;
		cin >> passAccuracy;
		cout << endl;

		cout << "Please enter a perimeter defense value for " << name << ": ";
		int perimeterD;
		cin >> perimeterD;
		cout << endl;

		cout << "Please enter an interior defense value for " << name << ": ";
		int interiorD;
		cin >> interiorD;
		cout << endl;

		cout << "Please enter a shot contest value for " << name << ": ";
		int shotContest;
		cin >> shotContest;
		cout << endl;

		cout << "Please enter a block value for " << name << ": ";
		int block;
		cin >> block;
		cout << endl;

		cout << "Please enter a defensive rebound value for " << name << ": ";
		int dReb;
		cin >> dReb;
		cout << endl;

		cout << "Please enter a offensive rebound value for " << name << ": ";
		int oReb;
		cin >> oReb;
		cout << endl;

		cout << "Please enter a speed value for " << name << ": ";
		int speed;
		cin >> speed;
		cout << endl;

		cout << "Please enter a strength value for " << name << ": ";
		int strength;
		cin >> strength;
		cout << endl;

		cout << "Would you like to enter " << name << " into the draft? (y/n) ";
		string isInDraft = "Yes";
		bool isInDraftBool = true;
		cin >> isInDraft;
		if (isInDraft == "y" || isInDraft == "Y" || isInDraft == "yes" || isInDraft == "Yes")
			isInDraftBool = true;
		else
			isInDraftBool = false;
		cout << endl;

		fstream savedBabdulsFile;
		savedBabdulsFile.open("custom_babduls.txt", std::fstream::app);
		string tab = "\t";
		string newLine = "\n";
		savedBabdulsFile << newLine;
		savedBabdulsFile << isInDraft;
		savedBabdulsFile << tab;
		savedBabdulsFile << name;
		savedBabdulsFile << tab;
		savedBabdulsFile << height_feet;
		savedBabdulsFile << tab;
		savedBabdulsFile << height_inches;
		savedBabdulsFile << tab;
		savedBabdulsFile << weight;
		savedBabdulsFile << tab;
		savedBabdulsFile << position;
		savedBabdulsFile << tab;
		savedBabdulsFile << tier;
		savedBabdulsFile << tab;
		savedBabdulsFile << build;
		savedBabdulsFile << tab;
		savedBabdulsFile << babdulishness;
		savedBabdulsFile << tab;
		savedBabdulsFile << shotClose;
		savedBabdulsFile << tab;
		savedBabdulsFile << shotMid;
		savedBabdulsFile << tab;
		savedBabdulsFile << shot3;
		savedBabdulsFile << tab;
		savedBabdulsFile << passAccuracy;
		savedBabdulsFile << tab;
		savedBabdulsFile << perimeterD;
		savedBabdulsFile << tab;
		savedBabdulsFile << interiorD;
		savedBabdulsFile << tab;
		savedBabdulsFile << shotContest;
		savedBabdulsFile << tab;
		savedBabdulsFile << block;
		savedBabdulsFile << tab;
		savedBabdulsFile << dReb;
		savedBabdulsFile << tab;
		savedBabdulsFile << oReb;
		savedBabdulsFile << tab;
		savedBabdulsFile << speed;
		savedBabdulsFile << tab;
		savedBabdulsFile << strength;

		savedBabdulsFile.close();

		createCustomBabdul(name, make_pair(height_feet, height_inches), weight, position, tier, build, babdulishness, shotClose, shotMid, shot3, passAccuracy, perimeterD, interiorD, shotContest, block, dReb, oReb, speed, strength, true);
	}

	void writeSavedBabdulsToFile()
	{
		fstream savedBabdulsFile;
		savedBabdulsFile.open("temp.txt", std::fstream::app);
		string tab = "\t";
		string newLine = "\n";

		for (int i = 0; i < savedBabduls.size(); i++)
		{
			string isInDraft = "true";
			if (savedBabduls.at(i).getIsInDraft())
				isInDraft = "true";
			else
				isInDraft = "false";

			if (i != 0)
				savedBabdulsFile << newLine;
			savedBabdulsFile << isInDraft;
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getBabName();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getHeight().first;
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getHeight().second;
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getWeight();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getPosition();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getTier();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getBuild();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getBabdulishness();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getShotClose();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getShotMid();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getShot3();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getPassAccuracy();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getPerimeterD();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getInteriorD();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getShotContest();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getBlock();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getDefRebound();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getOffRebound();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getSpeed();
			savedBabdulsFile << tab;
			savedBabdulsFile << savedBabduls.at(i).getStrength();
		}

		savedBabdulsFile.close();
		remove("custom_babduls.txt");
		rename("temp.txt", "custom_babduls.txt");
	}

	void loadSavedBabdulsFromFile()
	{
		fstream savedBabdulsFile;
		savedBabdulsFile.open("custom_babduls.txt");
		savedBabduls.clear();

		while (!savedBabdulsFile.eof())
		{
			string isInDraftString;
			getline(savedBabdulsFile, isInDraftString, '\t');
			bool isInDraft = true;
			if (isInDraftString == "true")
				isInDraft = true;
			else
				isInDraft = false;

			string name;
			getline(savedBabdulsFile, name, '\t');

			string height_feet_string;
			int height_feet;
			getline(savedBabdulsFile, height_feet_string, '\t');
			stringstream ssHeight(height_feet_string);
			ssHeight >> height_feet;

			string height_inches_string;
			int height_inches;
			getline(savedBabdulsFile, height_inches_string, '\t');
			stringstream ssHeight2(height_inches_string);
			ssHeight2 >> height_inches;

			string weight_string;
			int weight;
			getline(savedBabdulsFile, weight_string, '\t');
			stringstream ssWeight(weight_string);
			ssWeight >> weight;

			string position;
			getline(savedBabdulsFile, position, '\t');

			string tier;
			getline(savedBabdulsFile, tier, '\t');

			string build;
			getline(savedBabdulsFile, build, '\t');

			string babdulishness_string;
			int babdulishness;
			getline(savedBabdulsFile, babdulishness_string, '\t');
			stringstream ssBabdulishness(babdulishness_string);
			ssBabdulishness >> babdulishness;

			string shotClose_string;
			int shotClose;
			getline(savedBabdulsFile, shotClose_string, '\t');
			stringstream ssshotClose(shotClose_string);
			ssshotClose >> shotClose;

			string shotMid_string;
			int shotMid;
			getline(savedBabdulsFile, shotMid_string, '\t');
			stringstream ssshotMid(shotMid_string);
			ssshotMid >> shotMid;

			string shot3_string;
			int	shot3;
			getline(savedBabdulsFile, shot3_string, '\t');
			stringstream ssshot3(shot3_string);
			ssshot3 >> shot3;

			string passAccuracy_string;
			int	passAccuracy;
			getline(savedBabdulsFile, passAccuracy_string, '\t');
			stringstream sspassAccuracy(passAccuracy_string);
			sspassAccuracy >> passAccuracy;

			string perimeterD_string;
			int	perimeterD;
			getline(savedBabdulsFile, perimeterD_string, '\t');
			stringstream ssperimeterD(perimeterD_string);
			ssperimeterD >> perimeterD;

			string interiorD_string;
			int	interiorD;
			getline(savedBabdulsFile, interiorD_string, '\t');
			stringstream ssinteriorD(interiorD_string);
			ssinteriorD >> interiorD;

			string shotContest_string;
			int	shotContest;
			getline(savedBabdulsFile, shotContest_string, '\t');
			stringstream ssshotContest(shotContest_string);
			ssshotContest >> shotContest;

			string block_string;
			int	block;
			getline(savedBabdulsFile, block_string, '\t');
			stringstream ssblock(block_string);
			ssblock >> block;

			string dReb_string;
			int	dReb;
			getline(savedBabdulsFile, dReb_string, '\t');
			stringstream ssdReb(dReb_string);
			ssdReb >> dReb;

			string oReb_string;
			int	oReb;
			getline(savedBabdulsFile, oReb_string, '\t');
			stringstream ssoReb(oReb_string);
			ssoReb >> oReb;

			string speed_string;
			int	speed;
			getline(savedBabdulsFile, speed_string, '\t');
			stringstream ssspeed(speed_string);
			ssspeed >> speed;

			string strength_string;
			int	strength;
			getline(savedBabdulsFile, strength_string);
			stringstream ssstrength(strength_string);
			ssstrength >> strength;

			Babdul savedBabdul(name, make_pair(height_feet, height_inches), weight, position, tier, build, babdulishness, shotClose, shotMid, shot3, passAccuracy, perimeterD, interiorD, shotContest, block, dReb, oReb, speed, strength, isInDraft);
			savedBabduls.push_back(savedBabdul);
		}

		savedBabdulsFile.close();
	}

	void draft(bool sim)
	{
		system("cls");
		int picksMade = 0;

		cout << "================================" << endl;
		cout << "PREGAME STEP: NUMBER OF DRAFTERS" << endl;
		cout << "================================" << endl << endl;

		int numPlayers = 0;
		if (!sim)
		{
			cout << "How many players will be participating in the draft (0, 1, 2)? ";
			cin >> numPlayers;
		}
		else
		{
			numPlayers = 0;
		}

		// Determine first pick
		int firstPick = rand() % 2 + 1;
		int secondPick = -1;
		if (firstPick == 1)
			secondPick = 2;
		else if (firstPick == 2)
			secondPick = 1;

		// Validate pick order
		if (firstPick != 1 && firstPick != 2)
		{
			logger.error("Unable to determine draft pick order. First pick should be 1 or 2, but instead it is " + to_string(firstPick) + ". Defaulting to 1");
			firstPick = 1;
		}
		if (secondPick != 1 && secondPick != 2)
		{
			logger.error("Unable to determine draft pick order. Second pick should be 1 or 2, but instead it is " + to_string(secondPick) + ". Defaulting to 2");
			secondPick = 2;
		}

		if (numPlayers == 0)
		{
			while (picksMade < 10)
			{
				autoPickPlayer(firstPick);
				autoPickPlayer(secondPick);
				if (picksMade == 8)
				{
					picksMade += 2;
				}
				else
				{
					autoPickPlayer(secondPick);
					autoPickPlayer(firstPick);

					picksMade += 4;
				}
			}
		}
		else if (numPlayers == 1)
		{
			while (picksMade < 10)
			{
				if (firstPick == 1)
				{
					pickPlayer(1, 101);
					autoPickPlayer(2);
					if (picksMade == 8)
					{
						picksMade += 2;
					}
					else
					{
						autoPickPlayer(2);
						pickPlayer(1, 101);

						picksMade += 4;
					}
				}
				else
				{
					autoPickPlayer(2);
					pickPlayer(1, 101);
					if (picksMade == 8)
					{
						picksMade += 2;
					}
					else
					{
						pickPlayer(1, 101);
						autoPickPlayer(2);

						picksMade += 4;
					}
				}
			}
		}
		else
		{
			while (picksMade < 10)
			{
				pickPlayer(firstPick, 101);
				pickPlayer(secondPick, 101);
				if (picksMade == 8)
				{
					picksMade += 2;
				}
				else
				{
					pickPlayer(secondPick, 101);
					pickPlayer(firstPick, 101);

					picksMade += 4;
				}
			}
		}

		assignLocations(team1);
		assignLocations(team2);

		system("cls");
		cout << "The final rosters: " << endl;

		printTeam(team1);
		printTeam(team2);

		system("pause");
	}

	void assignLocations(Team& t)
	{
		for (int i = 0; i < t.getNumPlayers(); i++)
		{
			t.players.at(i).setLocation(i + 1);
		}
	}

	void autoPickPlayer(int player)
	{
		draftClass = sortBy(draftClass, "Overall");

		int randSelection;
		if (draftClass.size() >= 3)
			randSelection = rand() % 3;
		else
			randSelection = rand() % draftClass.size();

		if (player == 1)
			team1.addPlayer(draftClass.at(randSelection));
		else if (player == 2)
			team2.addPlayer(draftClass.at(randSelection));

		draftClass.erase(draftClass.begin() + randSelection);
	}

	void pickPlayer(int player, int sortby)
	{
		system("cls");
		cout << "===========================================================================================================" << endl;
		if (player == 1)
		{
			cout << "PLAYER 1 ("; team1.printTeamName(); cout << ") IS ON THE CLOCK" << endl;
		}
		if (player == 2)
		{
			cout << "PLAYER 2 ("; team2.printTeamName(); cout << ") IS ON THE CLOCK" << endl;
		}

		cout << "===========================================================================================================" << endl;
		cout << "Enter the Babnumber to select a player from the list below. Sort the list by entering the corresponding 10X number" << endl;

		cout << endl;
		if (player == 1)
		{
			printDraftClass(team1, sortby);
			cout << endl;
			printTeam(team1);
		}
		else if (player == 2)
		{
			printDraftClass(team2, sortby);
			cout << endl;
			printTeam(team2);
		}

		cout << endl;

		bool selected = false;

		int selection;
		cin >> selection;

		if (selection >= 100)
		{
			pickPlayer(player, selection);
		}
		else if (selection < 100 && selection > 0)
		{
			cout << "Confirm drafting " << draftClass.at(selection - 1).getBabName() << "? (y/n) ";

			char confirm;
			cin >> confirm;

			if (confirm == 'y' || confirm == 'Y')
			{
				cout << endl << "Draft Pick Confirmed" << endl;
				cout << "You have selected " << draftClass.at(selection - 1).getBabName() << ". " << draftClass.at(selection - 1).getBabName() << "'s stats are the following:" << endl;
				draftClass.at(selection - 1).printStats();
				selected = true;
				system("pause");
			}
			else
			{
				pickPlayer(player, sortby);
			}

			if (selected == true)
			{
				if (player == 1)
				{
					team1.addPlayer(draftClass.at(selection - 1));
				}
				else if (player == 2)
				{
					team2.addPlayer(draftClass.at(selection - 1));
				}

				draftClass.erase(draftClass.begin() + (selection - 1));
			}
		}
	}

	string placeHolderTemplate(int attribute)
	{
		int newVal = attribute;

		//int offsetChance = rand() % 4 + 1; // 1-4
		//if (offsetChance == 1)
		//	newVal -= 5;
		//else if (offsetChance == 2)
		//	newVal += 5;

		if (attribute > 95)
			return "A+";
		else if (attribute > 90)
			return "A ";
		else if (attribute > 85)
			return "A-";
		else if (attribute > 80)
			return "B+";
		else if (attribute > 75)
			return "B ";
		else if (attribute > 70)
			return "B-";
		else if (attribute > 65)
			return "C+";
		else if (attribute > 60)
			return "C ";
		else if (attribute > 55)
			return "C-";
		else if (attribute > 50)
			return "D+";
		else if (attribute > 45)
			return "D ";
		else
			return "D-";
	}

	string placeholderValues(Babdul& babdul, string attribute)
	{
		if (attribute == "babdulishness")
		{
			int newVal = babdul.draftAttributes.babdulishness;

			//int offsetChance = rand() % 4 + 1; // 1-4
			//if (offsetChance == 1)
			//	newVal -= 5;
			//else if (offsetChance == 2)
			//	newVal += 5;

			if (newVal < 30)
				return "A+";
			else if (newVal < 35)
				return "A ";
			else if (newVal < 40)
				return "A-";
			else if (newVal < 45)
				return "B+";
			else if (newVal < 50)
				return "B ";
			else if (newVal < 55)
				return "B-";
			else if (newVal < 60)
				return "C+";
			else if (newVal < 65)
				return "C ";
			else if (newVal < 75)
				return "C-";
			else if (newVal < 85)
				return "D+";
			else if (newVal < 95)
				return "D ";
			else
				return "D-";
		}

		else if (attribute == "shotClose")
			return placeHolderTemplate(babdul.draftAttributes.shotClose);

		else if (attribute == "shotMid")
			return placeHolderTemplate(babdul.draftAttributes.shotMid);

		else if (attribute == "shot3")
			return placeHolderTemplate(babdul.draftAttributes.shot3);

		else if (attribute == "passAccuracy")
			return placeHolderTemplate(babdul.draftAttributes.passAccuracy);

		else if (attribute == "perimeterD")
			return placeHolderTemplate(babdul.draftAttributes.perimeterD);

		else if (attribute == "interiorD")
			return placeHolderTemplate(babdul.draftAttributes.interiorD);

		else if (attribute == "shotContest")
			return placeHolderTemplate(babdul.draftAttributes.shotContest);

		else if (attribute == "block")
			return placeHolderTemplate(babdul.draftAttributes.block);

		else if (attribute == "defReb")
			return placeHolderTemplate(babdul.draftAttributes.defRebound);

		else if (attribute == "offReb")
			return placeHolderTemplate(babdul.draftAttributes.offRebound);

		else if (attribute == "speed")
			return placeHolderTemplate(babdul.draftAttributes.speed);

		else if (attribute == "strength")
			return placeHolderTemplate(babdul.draftAttributes.strength);
	}

	void printDraftClass(Team team, int sortby)
	{
		cout << "BabNumber BabName Position Build         Age Weight Height       Babdulishness S-Close S-Mid S-3 PSAC Per-D Int-D S-Contest Block Def-Reb Off-Reb Speed Strength" << endl;
		cout << "          101     102      103           104 105    106          107           108     109   110 111  112   113   114       115   116     117     118   119" << endl;
		cout << "================================================================================================================================================================" << endl;

		string sortString = "BabName";

		if (sortby == 101)
			sortString = "BabName";
		else if (sortby == 102)
			sortString = "Position";
		else if (sortby == 103)
			sortString = "Build";
		else if (sortby == 104)
			sortString = "Age";
		else if (sortby == 105)
			sortString = "Weight";
		else if (sortby == 106)
			sortString = "Height";
		else if (sortby == 107)
			sortString = "babdulishness";
		else if (sortby == 108)
			sortString = "shotClose";
		else if (sortby == 109)
			sortString = "shotMid";
		else if (sortby == 110)
			sortString = "shot3";
		else if (sortby == 111)
			sortString = "passAccuracy";
		else if (sortby == 112)
			sortString = "perimeterD";
		else if (sortby == 113)
			sortString = "interiorD";
		else if (sortby == 114)
			sortString = "shotContest";
		else if (sortby == 115)
			sortString = "block";
		else if (sortby == 116)
			sortString = "defReb";
		else if (sortby == 117)
			sortString = "offReb";
		else if (sortby == 118)
			sortString = "speed";
		else if (sortby == 119)
			sortString = "strength";

		draftClass = sortBy(draftClass, sortString);

		for (int i = 0; i < draftClass.size(); i++)
		{
			string babdulishnessPH = placeholderValues(draftClass.at(i), "babdulishness");
			string shotClosePH = placeholderValues(draftClass.at(i), "shotClose");
			string shotMidPH = placeholderValues(draftClass.at(i), "shotMid");
			string shot3PH = placeholderValues(draftClass.at(i), "shot3");
			string passAccuracyPH = placeholderValues(draftClass.at(i), "passAccuracy");
			string perimeterDPH = placeholderValues(draftClass.at(i), "perimeterD");
			string interiorDPH = placeholderValues(draftClass.at(i), "interiorD");
			string shotContestPH = placeholderValues(draftClass.at(i), "shotContest");
			string blockPH = placeholderValues(draftClass.at(i), "block");
			string defRebPH = placeholderValues(draftClass.at(i), "defReb");
			string offRebPH = placeholderValues(draftClass.at(i), "offReb");
			string speedPH = placeholderValues(draftClass.at(i), "speed");
			string strengthPH = placeholderValues(draftClass.at(i), "strength");

			string gap = "";
			if (draftClass.at(i).getHeight().second != 10 && draftClass.at(i).getHeight().second != 11)
			{
				gap = " ";
			}

			int extraNameSpaces = 7 - draftClass.at(i).getBabName().length();
			string extraNameSpace = "";
			if (extraNameSpaces >= 1)
			{
				for (int i = 0; i < extraNameSpaces; i++)
				{
					extraNameSpace = extraNameSpace + " ";
				}
			}

			string ageGap = "";
			if (draftClass.at(i).getAge() < 10)
				ageGap = " ";

			string weightGap = "";
			if (draftClass.at(i).getWeight() < 100)
			{
				if (draftClass.at(i).getWeight() >= 10)
				{
					weightGap = " ";
				}
				else if (draftClass.at(i).getWeight() < 10)
				{
					weightGap = "  ";
				}
			}

			if (i < 9)
			{
				cout << (i + 1) << "         " <<
					draftClass.at(i).getBabName() << extraNameSpace << " " <<
					draftClass.at(i).getPosition() << "       " <<
					draftClass.at(i).getBuild() << " " <<
					draftClass.at(i).getAge() << ageGap << "  " <<
					draftClass.at(i).getWeight() << weightGap << "   " <<
					draftClass.at(i).getHeight().first << "ft " << draftClass.at(i).getHeight().second << "in     " << gap <<
					babdulishnessPH << "            " <<
					shotClosePH << "      " <<
					shotMidPH << "    " <<
					shot3PH << "  " <<
					passAccuracyPH << "   " <<
					perimeterDPH << "    " <<
					interiorDPH << "    " <<
					shotContestPH << "        " <<
					blockPH << "    " <<
					defRebPH << "      " <<
					offRebPH << "      " <<
					speedPH << "    " <<
					strengthPH << " " <<
					endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << (i + 1) << "        " <<
					draftClass.at(i).getBabName() << extraNameSpace << " " <<
					draftClass.at(i).getPosition() << "       " <<
					draftClass.at(i).getBuild() << " " <<
					draftClass.at(i).getAge() << ageGap << "  " <<
					draftClass.at(i).getWeight() << weightGap << "   " <<
					draftClass.at(i).getHeight().first << "ft " << draftClass.at(i).getHeight().second << "in     " << gap <<
					babdulishnessPH << "            " <<
					shotClosePH << "      " <<
					shotMidPH << "    " <<
					shot3PH << "  " <<
					passAccuracyPH << "   " <<
					perimeterDPH << "    " <<
					interiorDPH << "    " <<
					shotContestPH << "        " <<
					blockPH << "    " <<
					defRebPH << "      " <<
					offRebPH << "      " <<
					speedPH << "    " <<
					strengthPH << " " <<
					endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			}
		}
		cout << endl;
	}

	void printTeam(Team team)
	{
		cout << endl;
		cout << "Team Name: "; team.printTeamName(); cout << endl;
		cout << "Size: " << team.getNumPlayers() << endl << endl;
		cout << "BabNumber BabName Position Tier       Build         Age Weight Height      Overall Babdulishness S-Close S-Mid S-3 PSAC Per-D Int-D S-Contest Block Def-Reb Off-Reb Speed Strength" << endl;
		cout << "==================================================================================================================================================================================" << endl;

		team.players = sortBy(team.players, "Overall");

		for (int i = 0; i < team.getNumPlayers(); i++)
		{
			if (i < 9)
			{
				cout << i + 1 << "         " <<
					team.players.at(i).getBabName() << " " <<
					team.players.at(i).getPosition() << "       " <<
					team.players.at(i).getTier() << " " <<
					team.players.at(i).getBuild() << " " <<
					team.players.at(i).getAge() << "  " <<
					team.players.at(i).getWeight() << "    " <<
					team.players.at(i).getHeight().first << "ft ";

					if (team.players.at(i).getHeight().second < 10)
						cout << team.players.at(i).getHeight().second << "in     ";
					else
						cout << team.players.at(i).getHeight().second << "in    ";

					cout <<
					team.players.at(i).getOverall() << "      " <<
					team.players.at(i).getBabdulishness() << "            " <<
					team.players.at(i).getShotClose() << "      " <<
					team.players.at(i).getShotMid() << "    " <<
					team.players.at(i).getShot3() << "  " <<
					team.players.at(i).getPassAccuracy() << "   " <<
					team.players.at(i).getPerimeterD() << "    " <<
					team.players.at(i).getInteriorD() << "    " <<
					team.players.at(i).getShotContest() << "        " <<
					team.players.at(i).getBlock() << "    " <<
					team.players.at(i).getDefRebound() << "      " <<
					team.players.at(i).getOffRebound() << "      " <<
					team.players.at(i).getSpeed() << "    " <<
					team.players.at(i).getStrength() << "" <<
					endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			}
			else
			{
				cout << i + 1 << "        " <<
					team.players.at(i).getBabName() << " " <<
					team.players.at(i).getPosition() << "       " <<
					team.players.at(i).getTier() << " " <<
					team.players.at(i).getBuild() << " " <<
					team.players.at(i).getAge() << "  " <<
					team.players.at(i).getWeight() << "    " <<
					team.players.at(i).getHeight().first << "ft ";

					if (team.players.at(i).getHeight().second < 10)
						cout << team.players.at(i).getHeight().second << "in     ";
					else
						cout << team.players.at(i).getHeight().second << "in    ";

					cout <<
					team.players.at(i).getOverall() << "      " <<
					team.players.at(i).getBabdulishness() << "            " <<
					team.players.at(i).getShotClose() << "      " <<
					team.players.at(i).getShotMid() << "    " <<
					team.players.at(i).getShot3() << "  " <<
					team.players.at(i).getPassAccuracy() << "   " <<
					team.players.at(i).getPerimeterD() << "    " <<
					team.players.at(i).getInteriorD() << "    " <<
					team.players.at(i).getShotContest() << "        " <<
					team.players.at(i).getBlock() << "    " <<
					team.players.at(i).getDefRebound() << "      " <<
					team.players.at(i).getOffRebound() << "      " <<
					team.players.at(i).getSpeed() << "    " <<
					team.players.at(i).getStrength() << "" <<
					endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			}
		}
		cout << endl;
	}

	vector<Babdul> sortBy(vector<Babdul> players, string sortBy)
	{
		if (sortBy == "babname" || sortBy == "BabName" || sortBy == "Babname" || sortBy == "babName")
		{
			std::sort(players.begin(), players.end(), compareBabName);
		}
		else if (sortBy == "age" || sortBy == "Age")
		{
			std::sort(players.begin(), players.end(), compareAge);
		}
		else if (sortBy == "weight" || sortBy == "Weight")
		{
			std::sort(players.begin(), players.end(), compareWeight);
		}
		else if (sortBy == "height" || sortBy == "Height")
		{
			std::sort(players.begin(), players.end(), compareHeight);
		}
		else if (sortBy == "position" || sortBy == "Position")
		{
			std::sort(players.begin(), players.end(), comparePosition);
		}
		else if (sortBy == "tier" || sortBy == "Tier")
		{
			std::sort(players.begin(), players.end(), compareTier);
		}
		else if (sortBy == "build" || sortBy == "Build")
		{
			std::sort(players.begin(), players.end(), compareBuild);
		}
		else if (sortBy == "babdulishness" || sortBy == "Babdulishness")
		{
			std::sort(players.begin(), players.end(), compareBabdulishness);
		}
		else if (sortBy == "overall" || sortBy == "Overall")
		{
			std::sort(players.begin(), players.end(), compareOverall);
		}
		else if (sortBy == "points" || sortBy == "Points")
		{
			std::sort(players.begin(), players.end(), comparePoints);
		}
		else if (sortBy == "blocks" || sortBy == "Blocks")
		{
			std::sort(players.begin(), players.end(), compareBlocks);
		}
		else if (sortBy == "assists" || sortBy == "Assists")
		{
			std::sort(players.begin(), players.end(), compareAssists);
		}
		else if (sortBy == "shotClose" || sortBy == "ShotClose")
		{
			std::sort(players.begin(), players.end(), compareShotClose);
		}
		else if (sortBy == "shotMid" || sortBy == "ShotMid")
		{
			std::sort(players.begin(), players.end(), compareShotMid);
		}
		else if (sortBy == "shot3" || sortBy == "Shot3")
		{
			std::sort(players.begin(), players.end(), compareShot3);
		}
		else if (sortBy == "PassAccuracy" || sortBy == "passAccuracy")
		{
			std::sort(players.begin(), players.end(), comparePassAcc);
		}
		else if (sortBy == "perimeterD" || sortBy == "PerimeterD")
		{
			std::sort(players.begin(), players.end(), comparePerimeterD);
		}
		else if (sortBy == "interiorD" || sortBy == "InteriorD")
		{
			std::sort(players.begin(), players.end(), compareInteriorD);
		}
		else if (sortBy == "shotContest" || sortBy == "ShotContest")
		{
			std::sort(players.begin(), players.end(), compareShotContest);
		}
		else if (sortBy == "block" || sortBy == "Block")
		{
			std::sort(players.begin(), players.end(), compareBlock);
		}
		else if (sortBy == "defReb" || sortBy == "DefReb")
		{
			std::sort(players.begin(), players.end(), compareDefRebound);
		}
		else if (sortBy == "offReb" || sortBy == "OffReb")
		{
			std::sort(players.begin(), players.end(), compareOffRebound);
		}
		else if (sortBy == "speed" || sortBy == "Speed")
		{
			std::sort(players.begin(), players.end(), compareSpeed);
		}
		else if (sortBy == "strength" || sortBy == "Strength")
		{
			std::sort(players.begin(), players.end(), compareStrength);
		}
		else
		{
			cout << "Sort By value not found" << endl;
		}

		return players;
	}
};