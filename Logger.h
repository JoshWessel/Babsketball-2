#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include <ctime>
#include <chrono>

using namespace std;

class Logger
{
	fstream logFile;

	string tab = "\t";
	string newLine = "\n";

	string applicationLogLevel = "DEBUG";

public:

	void debug(string msg)
	{
		if (applicationLogLevel == "DEBUG")
		{
			log("DEBUG", msg);
		}
	}

	void warn(string msg)
	{
		divider("/");
		log("WARN", msg);
		divider("/");
	}

	void error(string msg)
	{
		skipLine();
		divider("*");
		log("ERROR", msg);
		divider("*");
		skipLine();
	}

	void info(string msg)
	{
		log("INFO", msg);
	}

	void divider(string type)
	{
		logFile.open("logs.txt", std::fstream::app);
		for (int i = 0; i < 100; i++)
		{
			logFile << type;
		}
		logFile << newLine;
		logFile.close();
	}

	void skipLine()
	{
		logFile.open("logs.txt", std::fstream::app);
		logFile << newLine;
		logFile.close();
	}

	void log(string level, string msg)
	{
		logFile.open("logs.txt", std::fstream::app);

		// Find timestamp
		struct tm newTime;
		time_t now = time(0);
		localtime_s(&newTime, &now);
		string monthBuffer, dayBuffer, hourBuffer, minuteBuffer, secondBuffer = "";
		if (newTime.tm_mon < 10) { monthBuffer = "0"; }
		if (newTime.tm_mday < 10) { dayBuffer = "0"; }
		if (newTime.tm_hour < 10) { hourBuffer = "0"; }
		if (newTime.tm_min < 10) { minuteBuffer = "0"; }
		if (newTime.tm_sec < 10) { secondBuffer = "0"; }
		string curr_local_time =
			to_string(newTime.tm_year + 1900) + "/" + monthBuffer +
			to_string(newTime.tm_mon + 1) + "/" + dayBuffer +
			to_string(newTime.tm_mday) + " " + hourBuffer +
			to_string(newTime.tm_hour) + ":" + minuteBuffer +
			to_string(newTime.tm_min) + ":" + secondBuffer +
			to_string(newTime.tm_sec);

		// Write log line to log file
		logFile << curr_local_time << " - " << level << ": " << tab << msg;
		logFile << newLine;

		logFile.close();
	}

	void clear()
	{
		remove("logs.txt");
	}

};

// Global logger instance
Logger logger;