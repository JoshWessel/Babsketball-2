#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
//#include <algorithm>
#include <random>
#include <time.h>
//#include <cmath>

using namespace std;

class Sliders
{
public:

	string sliderSetName = "Default";

	// Babdulishness
	float slider_babdulishness;

	// Shooting Attributes
	float slider_shotClose;
	float slider_shotMid;
	float slider_shot3;

	// Playmaking Attributes
	float slider_passAccuracy;

	// Defense Attributes
	float slider_perimeterD;
	float slider_interiorD;
	float slider_shotContest;
	float slider_block;

	// Rebounding Attributes
	float slider_defRebound;
	float slider_offRebound;

	// Athmeticism Attributes
	float slider_strength;
	float slider_speed;

	Sliders()
	{
		sliderSetName = "Default";

		slider_babdulishness = 1.0f;

		slider_shotClose = 1.0f;
		slider_shotMid = 1.0f;
		slider_shot3 = 1.0f;

		slider_passAccuracy = 1.0f;

		slider_perimeterD = 1.0f;
		slider_interiorD = 1.0f;
		slider_shotContest = 1.0f;
		slider_block = 1.0f;

		slider_defRebound = 1.0f;
		slider_offRebound = 1.0f;

		slider_strength = 1.0f;
		slider_speed = 1.0f;
	}

	Sliders(string sliderSetName)
	{
		this->sliderSetName = sliderSetName;

		slider_babdulishness = 1.0f;

		slider_shotClose = 1.0f;
		slider_shotMid = 1.0f;
		slider_shot3 = 1.0f;

		slider_passAccuracy = 1.0f;

		slider_perimeterD = 1.0f;
		slider_interiorD = 1.0f;
		slider_shotContest = 1.0f;
		slider_block = 1.0f;

		slider_defRebound = 1.0f;
		slider_offRebound = 1.0f;

		slider_strength = 1.0f;
		slider_speed = 1.0f;
	}

	void setSliders(string sliderSetName, float sliders)
	{
		this->sliderSetName = sliderSetName;

		slider_babdulishness = sliders;

		slider_shotClose = sliders;
		slider_shotMid = sliders;
		slider_shot3 = sliders;

		slider_passAccuracy = sliders;

		slider_perimeterD = sliders;
		slider_interiorD = sliders;
		slider_shotContest = sliders;
		slider_block = sliders;

		slider_defRebound = sliders;
		slider_offRebound = sliders;

		slider_strength = sliders;
		slider_speed = sliders;
	}

	void setSliders(string sliderSetName, float slider_babdulishness, float slider_shotClose, float slider_shotMid, float slider_shot3, float slider_passAccuracy, float slider_perimeterD, float slider_interiorD, float slider_shotContest, float slider_block, float slider_defRebound, float slider_offRebound, float slider_strength, float slider_speed)
	{
		this->sliderSetName = sliderSetName;

		this->slider_babdulishness = slider_babdulishness;

		this->slider_shotClose = slider_shotClose;
		this->slider_shotMid = slider_shotMid;
		this->slider_shot3 = slider_shot3;

		this->slider_passAccuracy = slider_passAccuracy;

		this->slider_perimeterD = slider_perimeterD;
		this->slider_interiorD = slider_interiorD;
		this->slider_shotContest = slider_shotContest;
		this->slider_block = slider_block;

		this->slider_defRebound = slider_defRebound;
		this->slider_offRebound = slider_offRebound;

		this->slider_strength = slider_strength;
		this->slider_speed = slider_speed;
	}

	void setSliderName(string name)
	{
		this->sliderSetName = name;
	}

	void setSlider(string sliderName, float sliderNum)
	{
		if (sliderName == "babdulishness" || sliderName == "Babdulishness")
		{
			this->slider_babdulishness = sliderNum;
		}
		else if (sliderName == "shotClose" || sliderName == "ShotClose")
		{
			this->slider_shotClose = sliderNum;
		}
		else if (sliderName == "shotMid" || sliderName == "ShotMid")
		{
			this->slider_shotMid = sliderNum;
		}
		else if (sliderName == "shot3" || sliderName == "Shot3")
		{
			this->slider_shot3 = sliderNum;
		}
		else if (sliderName == "passAccuracy" || sliderName == "PassAccuracy")
		{
			this->slider_passAccuracy = sliderNum;
		}
		else if (sliderName == "perimeterD" || sliderName == "PerimeterD")
		{
			this->slider_perimeterD = sliderNum;
		}
		else if (sliderName == "interiorD" || sliderName == "InteriorD")
		{
			this->slider_interiorD = sliderNum;
		}
		else if (sliderName == "shotContest" || sliderName == "ShotContest")
		{
			this->slider_shotContest = sliderNum;
		}
		else if (sliderName == "block" || sliderName == "Block")
		{
			this->slider_block = sliderNum;
		}
		else if (sliderName == "defRebound" || sliderName == "DefRebound")
		{
			this->slider_defRebound = sliderNum;
		}
		else if (sliderName == "offRebound" || sliderName == "OffRebound")
		{
			this->slider_offRebound = sliderNum;
		}
		else if (sliderName == "strength" || sliderName == "Strength")
		{
			this->slider_strength = sliderNum;
		}
		else if (sliderName == "speed" || sliderName == "Speed")
		{
			this->slider_speed = sliderNum;
		}
		else
		{
			cout << "Slider " << sliderName << " not found" << endl;
		}
	}

	void printSliders()
	{
		cout << endl;
		cout << "----------------------------" << endl;
		cout << sliderSetName << endl;
		cout << "----------------------------" << endl;
		cout << "  (1)  Babdulishness     " << slider_babdulishness << endl;
		cout << "                         " << endl;
		cout << "  (2)  Shot Close        " << slider_shotClose << endl;
		cout << "  (3)  Shot Mid          " << slider_shotMid << endl;
		cout << "  (4)  Shot 3            " << slider_shot3 << endl;
		cout << "                         " << endl;
		cout << "  (5)  Pass Accuracy     " << slider_passAccuracy << endl;
		cout << "                         " << endl;
		cout << "  (6)  Perimeter D       " << slider_perimeterD << endl;
		cout << "  (7)  Interior D        " << slider_interiorD << endl;
		cout << "  (8)  Shot Contest      " << slider_shotContest << endl;
		cout << "  (9)  Block             " << slider_block << endl;
		cout << "                         " << endl;
		cout << "  (10) Def Rebound       " << slider_defRebound << endl;
		cout << "  (11) Off Rebound       " << slider_offRebound << endl;
		cout << "                         " << endl;
		cout << "  (12) Strength          " << slider_strength << endl;
		cout << "  (13) Speed             " << slider_speed << endl;
		cout << "----------------------------" << endl;
	}

	void printSlidersHorizontally()
	{
		int buffer = 20 - sliderSetName.length();
		string bufferString = "";

		for (int i = 0; i < buffer; i++)
		{
			bufferString = bufferString + " ";
		}

		cout << sliderSetName << bufferString <<
			slider_babdulishness;	if (slider_babdulishness == 0	|| slider_babdulishness == 1	|| slider_babdulishness == 2)	{ cout << "  "; }; cout << "           " <<
			slider_shotClose;		if (slider_shotClose == 0		|| slider_shotClose == 1		|| slider_shotClose == 2)		{ cout << "  "; }; cout << "     " <<
			slider_shotMid;			if (slider_shotMid == 0			|| slider_shotMid == 1			|| slider_shotMid == 2)			{ cout << "  "; }; cout << "   " <<
			slider_shot3;			if (slider_shot3 == 0			|| slider_shot3 == 1			|| slider_shot3 == 2)			{ cout << "  "; }; cout << " " <<
			slider_passAccuracy;	if (slider_passAccuracy == 0	|| slider_passAccuracy == 1		|| slider_passAccuracy == 2)	{ cout << "  "; }; cout << "  " <<
			slider_perimeterD;		if (slider_perimeterD == 0		|| slider_perimeterD == 1		|| slider_perimeterD == 2)		{ cout << "  "; }; cout << "   " <<
			slider_interiorD;		if (slider_interiorD == 0		|| slider_interiorD == 1		|| slider_interiorD == 2)		{ cout << "  "; }; cout << "   " <<
			slider_shotContest;		if (slider_shotContest == 0		|| slider_shotContest == 1		|| slider_shotContest == 2)		{ cout << "  "; }; cout << "       " <<
			slider_block;			if (slider_block == 0			|| slider_block == 1			|| slider_block == 2)			{ cout << "  "; }; cout << "   " <<
			slider_defRebound;		if (slider_defRebound == 0		|| slider_defRebound == 1		|| slider_defRebound == 2)		{ cout << "  "; }; cout << "     " <<
			slider_offRebound;		if (slider_offRebound == 0		|| slider_offRebound == 1		|| slider_offRebound == 2)		{ cout << "  "; }; cout << "     " <<
			slider_speed;			if (slider_speed == 0			|| slider_speed == 1			|| slider_speed == 2)			{ cout << "  "; }; cout << "   " <<
			slider_strength << ""
		<< endl;
		cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
	}

	void printSlidersHeader()
	{
		cout << "# Slider Preset       Babdulishness S-Close S-Mid S-3 PSAC Per-D Int-D S-Contest Block Def-Reb Off-Reb Speed Strength" << endl;
		cout << "=====================================================================================================================" << endl;
	}



};








