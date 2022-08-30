#include <iostream>
#include <conio.h>

using namespace std;

bool stopShotMeter = false;

DWORD WINAPI thread1(LPVOID pm)
{
	while (cin.get() != '\n') {
		int a = getchar();
	}
	logger.info("Stopped shot meter");
	stopShotMeter = true;
	return 0;
}

class ShotMeter
{
	int width = 10;

public:

	int needle = 0;

	int minSuccess = 3;
	int maxSuccess = 6;

	bool scored = false;

	int numShots = 1;

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
			shoot();
			if (checkIfScored())
				shotsMade++;
		}

		system("cls");
		cout << "You made " + to_string(shotsMade) + "/" + to_string(numShots) << endl;
		system("pause");
	}

	void displayMeter()
	{
		system("cls");

		for (int i = 0; i < width; i++)
		{
			setTextColor(GREEN);
			if (i <= minSuccess || i >= maxSuccess)
				setTextColor(RED);
			cout << "=";
		}
		cout << endl;

		for (int i = 0; i < width; i++)
		{
			if (needle == i)
			{
				setTextColor(GREEN);
				if (i <= minSuccess || i >= maxSuccess)
					setTextColor(RED);
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
			setTextColor(GREEN);
			if (i <= minSuccess || i >= maxSuccess)
				setTextColor(RED);
			cout << "=";
		}
		cout << endl;

		setDefaultTextColor();
	}

	void shoot()
	{
		needle = 0;
		scored = false;
		stopShotMeter = false;

		unsigned int seconds = 1000;

		HANDLE handle = CreateThread(NULL, 0, thread1, NULL, 0, NULL);

		while (stopShotMeter == false)
		{
			logger.debug(to_string(stopShotMeter));
			for (int i = 0; i < width && stopShotMeter == false; i++)
			{
				needle++;
				Sleep(0.01 * seconds);
				displayMeter();

				if (stopShotMeter)
					break;
			}
			for (int i = width; i > 0 && stopShotMeter == false; i--)
			{
				needle--;
				Sleep(0.01 * seconds);
				displayMeter();

				if (stopShotMeter)
					break;
			}
		}
	}

	bool checkIfScored()
	{
		if (needle >= minSuccess && needle <= maxSuccess)
		{
			cout << "SCORED!" << endl;
			system("pause");
			return true;
		}
		else
		{
			cout << "MISSED" << endl;
			system("pause");
			return false;
		}
	}
};