#include <iostream>
#include <conio.h>

using namespace std;

bool stopShotMeter = false;

DWORD WINAPI thread1(LPVOID pm)
{
	while (cin.get() != '\n') {
		int a = getchar();
	}
	logger.debug("Stopped shot meter");
	stopShotMeter = true;
	return 0;
}

class ShotMeter
{
	int width = 11;

	int needle = 0;

	int yMinSuccess = 3;
	int gMinSuccess = 5;
	int gMaxSuccess = 5;
	int yMaxSuccess = 7;

	int minGreenRating = 85;
	int maxBabdulishnessRating = 30;

	int numShots = 1;

	unsigned int seconds = 1000;

	void setLimits(int skill, int babdulishness)
	{
		if (skill >= minGreenRating && babdulishness <= maxBabdulishnessRating)
		{
			gMinSuccess = 5;
			gMaxSuccess = 5;
		}
		else
		{
			gMinSuccess = NULL;
			gMaxSuccess = NULL;
		}
	}

	void reset()
	{
		int needle = 0;

		int yMinSuccess = 3;
		int gMinSuccess = 5;
		int gMaxSuccess = 5;
		int yMaxSuccess = 7;
	}

	void displayMeter()
	{
		system("cls");

		for (int i = 0; i < width; i++)
		{
			if (i == width / 2 && gMinSuccess != NULL)
				setTextColor(GREEN);
			else if (i <= yMinSuccess || i >= yMaxSuccess)
				setTextColor(RED);
			else
				setTextColor(DARK_YELLOW);
			cout << "=";
		}
		cout << endl;

		for (int i = 0; i < width; i++)
		{
			if (needle == i)
			{
				if (i == width / 2 && gMinSuccess != NULL)
					setTextColor(GREEN);
				else if (i <= yMinSuccess || i >= yMaxSuccess)
					setTextColor(RED);
				else
					setTextColor(DARK_YELLOW);
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;

		for (int i = 0; i < width; i++)
		{
			if (i == width / 2 && gMinSuccess != NULL)
				setTextColor(GREEN);
			else if (i <= yMinSuccess || i >= yMaxSuccess)
				setTextColor(RED);
			else
				setTextColor(DARK_YELLOW);
			cout << "=";
		}
		cout << endl;

		setDefaultTextColor();
	}

	void displayFinalMeter(string outcome)
	{
		system("cls");

		for (int i = 0; i < width; i++)
		{
			if (i == width / 2 && gMinSuccess != NULL)
				setTextColor(GREEN);
			else if (i <= yMinSuccess || i >= yMaxSuccess)
				setTextColor(RED);
			else
				setTextColor(DARK_YELLOW);
			cout << "=";
		}
		cout << endl;

		if (outcome == "GREEN")
			setTextColor(GREEN);
		else if (outcome == "RED")
			setTextColor(RED);
		else
			setTextColor(DARK_YELLOW);

		for (int i = 0; i < width; i++)
		{
			if (needle == i)
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;

		for (int i = 0; i < width; i++)
		{
			if (i == width / 2 && gMinSuccess != NULL)
				setTextColor(GREEN);
			else if (i <= yMinSuccess || i >= yMaxSuccess)
				setTextColor(RED);
			else
				setTextColor(DARK_YELLOW);
			cout << "=";
		}
		cout << endl;

		setDefaultTextColor();
	}

	void shoot(int skill, int babdulishness)
	{
		needle = 0;
		stopShotMeter = false;

		HANDLE handle = CreateThread(NULL, 0, thread1, NULL, 0, NULL);
		logger.debug("Created thread");

		while (stopShotMeter == false)
		{
			for (int i = 0; i < width && stopShotMeter == false; i++)
			{
				needle++;
				Sleep(0.01 * seconds);
				displayMeter();

				if (stopShotMeter)
				{
					displayFinalMeter(checkIfScored());
					break;
				}
			}
			for (int i = width; i > 0 && stopShotMeter == false; i--)
			{
				needle--;
				Sleep(0.01 * seconds);
				displayMeter();

				if (stopShotMeter)
				{
					displayFinalMeter(checkIfScored());
					break;
				}
			}
		}
	}

	void printBar(string outcome)
	{
		cout << endl;
		for (int i = 0; i < width; i++)
		{
			if (outcome == "GREEN")
			{
				setTextColor(GREEN);
				cout << "$";
			}
			else if (outcome == "RED")
			{
				setTextColor(RED);
				cout << "X";
			}
			else
			{
				setTextColor(DARK_YELLOW);
				cout << "/";
			}
		}
		cout << endl;

		setDefaultTextColor();
	}

	string checkIfScored()
	{
		if (needle >= gMinSuccess && needle <= gMaxSuccess)
		{
			//printBar("GREEN");
			return "GREEN";
		}
		else if (needle >= yMinSuccess && needle <= yMaxSuccess)
		{
			//printBar("YELLOW");
			return "YELLOW";
		}
		else
		{
			//printBar("RED");
			return "RED";
		}

		reset();
	}

public:

	string playerShoot(int skill, int babdulishness)
	{
		logger.debug("Loading manual shot");
		cin.ignore();
		setLimits(skill, babdulishness);
		shoot(skill, babdulishness);
		logger.debug("Manual shot taken");
		return checkIfScored();
	}

	void shootMenu()
	{
		system("cls");

		cout << "How many shots would you like to shoot? ";
		cin >> numShots;
		cin.ignore();

		int shotsMade = 0;

		int i = 0;
		while (i < numShots)
		{
			i++;
			shoot(minGreenRating, maxBabdulishnessRating);
			string outcomeColor = checkIfScored();

			string outcome = "MISSED";
			if (outcomeColor != "RED")
			{
				outcome = "SCORED!";
				shotsMade++;
				if (outcomeColor == "YELLOW")
					outcome = "MIGHT HAVE SCORED";
			}
			cout << endl << outcome << endl;
			Sleep(0.5 * seconds);
		}

		system("cls");
		cout << "You made " + to_string(shotsMade) + "/" + to_string(numShots) << endl;
		system("pause");
	}

};