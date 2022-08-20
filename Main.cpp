#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <Windows.h>

#include "GameModeManager.h"

using namespace std;

// Ideas to add:

// - Alternate game modes
//		- Regular Game (current thing)
//		- 7 Game Series (series length can be specified)
//		- 3 Point Contest
//		- Season / Playoffs
//		- MyGM
// - Add more attributes
//		- Fatigue
//		- Clutch Factor
// - Add quarters / halftime
// - Add pause menu options
//		- Adjust matchups
//		- Call timeout
//		- Substitutions
// - Intentional fouling (automatic by default, can toggle it in pause menu settings)
// - Free throws, draw foul attribute
// - Combine pregame menus into a single menu
// - Save/load teams
// - Increase team size to allow subs

// Bugs to fix:

// - Add tipoff and ballhandler selection at the beginning of overtimes
// - Fix overtime game end conditions (currently ending at end of shot clock, while game clock goes into negatives)
// - Make matchups persistent throughout a series

int main()
{
	// Remove existing logs
	logger.clear();

	logger.info("=== EXECUTION STARTING ===");
	logger.skipLine();

	// Set Random Seed
	logger.info("Setting a random seed");
	srand(time(0));

	// Set Window Size
	logger.info("Preparing window");
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, 0, 0, 1920, 1050, TRUE);

	// Run application
	logger.info("Starting Application");
	GameModeManager gameModeManager;
	gameModeManager.welcome();

	// End game message
	logger.skipLine();
	logger.info("=== EXECUTION COMPLETE ===");



}