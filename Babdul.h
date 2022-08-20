#include "Sliders.h"
#include "Attributes.h"
#include "Logger.h"
#include "PlayResults.h"

#define BABDULISHNESS	attributes.babdulishness
#define SHOT_CLOSE		attributes.shotClose
#define SHOT_MID		attributes.shotMid
#define SHOT_3			attributes.shot3
#define PASS_ACC		attributes.passAccuracy
#define PER_D			attributes.perimeterD
#define INT_D			attributes.interiorD
#define SHOT_CONTEST	attributes.shotContest
#define BLOCK			attributes.block
#define DEF_REB			attributes.defRebound
#define OFF_REB			attributes.offRebound
#define SPEED			attributes.speed
#define STRENGTH		attributes.strength

using namespace std;

class Babdul
{

public:
	string babName;
	string position;
	int age;
	int weight;
	pair<int, int> height;

	int overall;

	string tier;
	string build;

	Sliders sliders;

	Attributes attributes;
	Attributes draftAttributes;

	// Box Score Stats
	int points;
	int blocks;
	int assists;
	int rebounds;
	int turnovers;

	//float babdulishness;

	//// Shooting Attributes
	//int shotClose;
	//int shotMid;
	//int shot3;

	//// Playmaking Attributes
	//int passAccuracy;

	//// Defense Attributes
	//int perimeterD;
	//int interiorD;
	//int shotContest;
	//int block;

	//// Rebounding Attributes
	//int defRebound;
	//int offRebound;

	//// Athleticism Attributes
	//int strength;
	//int speed;

	int location;

	string matchupName;

	bool ballCarrier = false;
	bool wasPasser = false;
	bool isRebounder = false;

	bool isInDraft = true;

	vector<string> playerTiers = {
		"Rotation  ",	// +5  - +10
		"Starter   ",	// +10 - +15
		"All-Star  ",	// +15 - +20
		"Superstar "	// +20 - +30
	};

	vector<string> ALL_Builds = {
		"All_Around   ",
		"Shooter      ",
		"Playmaker    ",
		"Defender     ",
		"Slasher      ",
		"Rebounder    ",
		"Paint_Scorer ",
		"Shot_Blocker "
	};

	vector<string> PG_Builds = {
		"All_Around   ",
		"Shooter      ",
		"Playmaker    ",
		"Defender     "
	};

	vector<string> SG_Builds = {
		"All_Around   ",
		"Shooter      ",
		"Playmaker    ",
		"Slasher      ",
		"Defender     "
	};

	vector<string> SF_Builds = {
		"All_Around   ",
		"Shooter      ",
		"Playmaker    ",
		"Slasher      ",
		"Defender     "
	};

	vector<string> PF_Builds = {
		"All_Around   ",
		"Shooter      ",
		"Rebounder    ",
		"Defender     ",
		"Paint_Scorer ",
		"Shot_Blocker "
	};

	vector<string> C_Builds = {
		"All_Around   ",
		"Shooter      ",
		"Paint_Scorer ",
		"Rebounder    ",
		"Defender     ",
		"Shot_Blocker "
	};

	vector<string> babNames = {
		"Babdul ",
		"Cabdul ",
		"Dabdul ",
		"Fabdul ",
		"Gabdul ",
		"Habdul ",
		"Jabdul ",
		"Kabdul ",
		"Labdul ",
		"Mabdul ",
		"Nabdul ",
		"Pabdul ",
		"Qabdul ",
		"Rabdul ",
		"Sabdul ",
		"Tabdul ",
		"Vabdul ",
		"Wabdul ",
		"Xabdul ",
		"Yabdul ",
		"Zabdul ",

		"Blabdul",
		"Bwabdul",
		"Chabdul",
		"Clabdul",
		"Crabdul",
		"Drabdul",
		"Flabdul",
		"Frabdul",
		"Glabdul",
		"Grabdul",
		"Klabdul",
		"Plabdul",
		"Prabdul",
		"Quabdul",
		"Scabdul",
		"Shabdul",
		"Slabdul",
		"Smabdul",
		"Snabdul",
		"Stabdul",
		"Spabdul",
		"Swabdul",
		"Thabdul",
		"Trabdul",
		"Twabdul",
		"Wrabdul",
		"Zlabdul"//,

		/*"Douggg ",
		"Bouggg ",
		"Gouggg ",
		"Houggg ",
		"Jouggg ",
		"Kouggg ",
		"Louggg ",
		"Mouggg ",
		"Nouggg ",
		"Oouggg ",
		"Pouggg ",
		"Qouggg ",
		"Rouggg ",
		"Souggg ",
		"Touggg ",
		"Vouggg ",
		"Wouggg ",
		"Xouggg ",
		"Youggg ",
		"Zouggg ",
		
		"Crougg ",
		"Drougg ",
		"Brougg ",
		"Grougg ",
		"Glougg ",
		"Slougg ",
		"Snougg ",
		"Smougg ",
		"Swougg ",
		"Stougg ",
		"Stroug ",
		"Wrougg ",
		"Chougg ",
		"Dwougg ",
		"Jrougg ",
		"Zlougg ",
		"Klougg ",
		"Blougg ",
		"Flougg ",
		"Frougg ",
		"Pnougg ",
		"Thougg ",

		"Meeeee ",
		"Youuuu ",
		"2Bad4U ",
		"Suxalot",
		"Stinky ",
		"Smelly ",
		"Sloppy ",
		"Snoozy ",
		"Slorpy ",
		"Slurpy ",
		"Clumpy ",
		"Notfast",
		"Verybad"*/
	};

	string generateTier()
	{
		int chance = rand() % 10 + 1;

		if (chance <= 3)				// 1, 2, 3
			return playerTiers.at(0);
		else if (chance <= 7)			// 4, 5, 6, 7
			return playerTiers.at(1);
		else if (chance <= 9)			// 8, 9
			return playerTiers.at(2);
		else if (chance == 10)			// 10
			return playerTiers.at(3);
	}

	string generateBuild(string position)
	{
		if (position == "PG")
		{
			int chance = rand() % PG_Builds.size();
			return PG_Builds.at(chance);
		}
		else if (position == "SG")
		{
			int chance = rand() % SG_Builds.size();
			return SG_Builds.at(chance);
		}
		else if (position == "SF")
		{
			int chance = rand() % SF_Builds.size();
			return SF_Builds.at(chance);
		}
		else if (position == "PF")
		{
			int chance = rand() % PF_Builds.size();
			return PF_Builds.at(chance);
		}
		else if (position == "C ")
		{
			int chance = rand() % C_Builds.size();
			return C_Builds.at(chance);
		}
		else
		{
			cout << "Invalid position. Defaulting to All-Around build" << endl;
			return "All_Around";
		}
	}

	string generatePosition(pair<int, int> height)
	{
		// PG 5,10 -  6,4
		// SG 6,1  -  6,8
		// SF 6,5  -  6,10
		// PF 6,7  -  6,11
		// C  6,9  -  7,7

		if (height.first == 5)
		{
			return "PG";
		}
		else if (height.first == 6)
		{
			if (height.second == 0)
			{
				return "PG";
			}
			else if (height.second == 1)
			{
				int PGorSG_1 = rand() % 10 + 1;
				if (PGorSG_1 < 10)
				{
					return "PG";
				}
				else
				{
					return "SG";
				}
			}
			else if (height.second == 2)
			{
				int PGorSG_2 = rand() % 10 + 1;
				if (PGorSG_2 < 9)
				{
					return "PG";
				}
				else
				{
					return "SG";
				}
			}
			else if (height.second == 3)
			{
				int PGorSG_3 = rand() % 10 + 1;
				if (PGorSG_3 < 6)
				{
					return "PG";
				}
				else
				{
					return "SG";
				}
			}
			else if (height.second == 4)
			{
				int PGorSG_4 = rand() % 10 + 1;
				if (PGorSG_4 < 3)
				{
					return "PG";
				}
				else
				{
					return "SG";
				}
			}
			else if (height.second == 5)
			{
				int SGorSF_5 = rand() % 10 + 1;
				if (SGorSF_5 < 8)
				{
					return "SG";
				}
				else
				{
					return "SF";
				}
			}
			else if (height.second == 6)
			{
				int SGorSF_6 = rand() % 10 + 1;
				if (SGorSF_6 < 5)
				{
					return "SG";
				}
				else
				{
					return "SF";
				}
			}
			else if (height.second == 7)
			{
				int SGorSForPF_7 = rand() % 10 + 1;
				if (SGorSForPF_7 < 2)
				{
					return "SG";
				}
				else if (SGorSForPF_7 < 9)
				{
					return "SF";
				}
				else
				{
					return "PF";
				}
			}
			else if (height.second == 8)
			{
				int SForPF_8 = rand() % 10 + 1;
				if (SForPF_8 < 7)
				{
					return "SF";
				}
				else
				{
					return "PF";
				}
			}
			else if (height.second == 9)
			{
				int SForPForC_9 = rand() % 10 + 1;
				if (SForPForC_9 < 5)
				{
					return "SF";
				}
				else if (SForPForC_9 < 10)
				{
					return "PF";
				}
				else
				{
					return "C ";
				}
			}
			else if (height.second == 10)
			{
				int SForPForC_10 = rand() % 10 + 1;
				if (SForPForC_10 < 2)
				{
					return "SF";
				}
				else if (SForPForC_10 < 9)
				{
					return "PF";
				}
				else
				{
					return "C ";
				}
			}
			else if (height.second == 11)
			{
				int PForC_10 = rand() % 10 + 1;
				if (PForC_10 < 4)
				{
					return "PF";
				}
				else
				{
					return "C ";
				}
			}
		}
		else if (height.first == 7)
		{
			return "C ";
		}
	}

	pair<int, int> generateHeight()
	{
		vector<pair<int, int>> heights = {
			
			make_pair(5,10),

			make_pair(5,11),

			make_pair(6,0),
			make_pair(6,0),

			make_pair(6,1),
			make_pair(6,1),
			make_pair(6,1),

			make_pair(6,2),
			make_pair(6,2),
			make_pair(6,2),
			make_pair(6,2),

			make_pair(6,3),
			make_pair(6,3),
			make_pair(6,3),
			make_pair(6,3),
			make_pair(6,3),

			make_pair(6,4),
			make_pair(6,4),
			make_pair(6,4),
			make_pair(6,4),
			make_pair(6,4),

			make_pair(6,5),
			make_pair(6,5),
			make_pair(6,5),
			make_pair(6,5),
			make_pair(6,5),
			make_pair(6,5),

			make_pair(6,6),
			make_pair(6,6),
			make_pair(6,6),
			make_pair(6,6),
			make_pair(6,6),
			make_pair(6,6),
			make_pair(6,6),
			make_pair(6,6),

			make_pair(6,7),
			make_pair(6,7),
			make_pair(6,7),
			make_pair(6,7),
			make_pair(6,7),
			make_pair(6,7),
			make_pair(6,7),
			make_pair(6,7),
			make_pair(6,7),

			make_pair(6,8),
			make_pair(6,8),
			make_pair(6,8),
			make_pair(6,8),
			make_pair(6,8),
			make_pair(6,8),
			make_pair(6,8),
			make_pair(6,8),
			make_pair(6,8),
			make_pair(6,8),

			make_pair(6,9),
			make_pair(6,9),
			make_pair(6,9),
			make_pair(6,9),
			make_pair(6,9),
			make_pair(6,9),
			make_pair(6,9),
			make_pair(6,9),
			make_pair(6,9),

			make_pair(6,10),
			make_pair(6,10),
			make_pair(6,10),
			make_pair(6,10),
			make_pair(6,10),
			make_pair(6,10),
			make_pair(6,10),

			make_pair(6,11),
			make_pair(6,11),
			make_pair(6,11),
			make_pair(6,11),
			make_pair(6,11),
			make_pair(6,11),

			make_pair(7,0),
			make_pair(7,0),
			make_pair(7,0),
			make_pair(7,0),

			make_pair(7,1),
			make_pair(7,1),
			make_pair(7,1),

			make_pair(7,2),
			make_pair(7,2),

			make_pair(7,3),

			make_pair(7,4),

			make_pair(7,5),

			make_pair(7,6),

			make_pair(7,7)
		};

		int heightIndex = rand() % heights.size();
		return heights.at(heightIndex);
	}

	int generateWeight(int heightInInches)
	{
		int variation = rand() % 20 - 10;

		if (heightInInches < 72)
			return variation + 180;
		else if (heightInInches < 74)
			return variation + 200;
		else if (heightInInches < 76)
			return variation + 210;
		else if (heightInInches < 78)
			return variation + 220;
		else if (heightInInches < 80)
			return variation + 230;
		else if (heightInInches < 82)
			return variation + 240;
		else if (heightInInches < 84)
			return variation + 250;
		else if (heightInInches < 86)
			return variation + 280;
		else if (heightInInches >= 86)
			return variation + 300;
	}

	string generateBabName()
	{
		int nameIndex = rand() % babNames.size();
		return babNames.at(nameIndex);
	}

	void tierAdjustments()
	{
		if (tier == "Rotation  ")
		{
			int baseAdd = 2;
			int baseSub = 8;

			BABDULISHNESS = BABDULISHNESS -		(rand() % baseAdd - baseSub);
			SHOT_CLOSE = SHOT_CLOSE +			(rand() % baseAdd - baseSub);
			SHOT_3 = SHOT_3 +					(rand() % baseAdd - baseSub);
			SHOT_MID = SHOT_MID +				(rand() % baseAdd - baseSub);
			PASS_ACC = PASS_ACC +				(rand() % baseAdd - baseSub);
			PER_D = PER_D +						(rand() % baseAdd - baseSub);
			INT_D = INT_D +						(rand() % baseAdd - baseSub);
			SHOT_CONTEST = SHOT_CONTEST +		(rand() % baseAdd - baseSub);
			BLOCK = BLOCK +						(rand() % baseAdd - baseSub);
			DEF_REB = DEF_REB +					(rand() % baseAdd - baseSub);
			OFF_REB = OFF_REB +					(rand() % baseAdd - baseSub);
			SPEED = SPEED +						(rand() % baseAdd - baseSub);
			STRENGTH = STRENGTH +				(rand() % baseAdd - baseSub);
		}
		else if (tier == "Starter   ")
		{
			int baseAdd = 8;
			int baseSub = 2;

			BABDULISHNESS = BABDULISHNESS -		(rand() % baseAdd - baseSub);
			SHOT_CLOSE = SHOT_CLOSE +			(rand() % baseAdd - baseSub);
			SHOT_3 = SHOT_3 +					(rand() % baseAdd - baseSub);
			SHOT_MID = SHOT_MID +				(rand() % baseAdd - baseSub);
			PASS_ACC = PASS_ACC +				(rand() % baseAdd - baseSub);
			PER_D = PER_D +						(rand() % baseAdd - baseSub);
			INT_D = INT_D +						(rand() % baseAdd - baseSub);
			SHOT_CONTEST = SHOT_CONTEST +		(rand() % baseAdd - baseSub);
			BLOCK = BLOCK +						(rand() % baseAdd - baseSub);
			DEF_REB = DEF_REB +					(rand() % baseAdd - baseSub);
			OFF_REB = OFF_REB +					(rand() % baseAdd - baseSub);
			SPEED = SPEED +						(rand() % baseAdd - baseSub);
			STRENGTH = STRENGTH +				(rand() % baseAdd - baseSub);
		}
		else if (tier == "All-Star  ")
		{
			int baseAdd = 10;
			int floorRaise = 5;

			BABDULISHNESS = BABDULISHNESS -		(rand() % baseAdd + floorRaise);
			SHOT_CLOSE = SHOT_CLOSE +			(rand() % baseAdd + floorRaise);
			SHOT_3 = SHOT_3 +					(rand() % baseAdd + floorRaise);
			SHOT_MID = SHOT_MID +				(rand() % baseAdd + floorRaise);
			PASS_ACC = PASS_ACC +				(rand() % baseAdd + floorRaise);
			PER_D = PER_D +						(rand() % baseAdd + floorRaise);
			INT_D = INT_D +						(rand() % baseAdd + floorRaise);
			SHOT_CONTEST = SHOT_CONTEST +		(rand() % baseAdd + floorRaise);
			BLOCK = BLOCK +						(rand() % baseAdd + floorRaise);
			DEF_REB = DEF_REB +					(rand() % baseAdd + floorRaise);
			OFF_REB = OFF_REB +					(rand() % baseAdd + floorRaise);
			SPEED = SPEED +						(rand() % baseAdd + floorRaise);
			STRENGTH = STRENGTH +				(rand() % baseAdd + floorRaise);
		}
		else if (tier == "Superstar ")
		{
			int baseAdd = 15;
			int floorRaise = 8;

			BABDULISHNESS = BABDULISHNESS -		(rand() % baseAdd + floorRaise);
			SHOT_CLOSE = SHOT_CLOSE +			(rand() % baseAdd + floorRaise);
			SHOT_3 = SHOT_3 +					(rand() % baseAdd + floorRaise);
			SHOT_MID = SHOT_MID +				(rand() % baseAdd + floorRaise);
			PASS_ACC = PASS_ACC +				(rand() % baseAdd + floorRaise);
			PER_D = PER_D +						(rand() % baseAdd + floorRaise);
			INT_D = INT_D +						(rand() % baseAdd + floorRaise);
			SHOT_CONTEST = SHOT_CONTEST +		(rand() % baseAdd + floorRaise);
			BLOCK = BLOCK +						(rand() % baseAdd + floorRaise);
			DEF_REB = DEF_REB +					(rand() % baseAdd + floorRaise);
			OFF_REB = OFF_REB +					(rand() % baseAdd + floorRaise);
			SPEED = SPEED +						(rand() % baseAdd + floorRaise);
			STRENGTH = STRENGTH +				(rand() % baseAdd + floorRaise);
		}
		else
		{
			cout << "Invalid tier" << endl;
		}
	}

	void buildAdjustments()
	{
		if (this->build == "All_Around   ")
		{
			BABDULISHNESS		-= 5;
			SHOT_CLOSE			+= 8;
			SHOT_3				+= 5;
			SHOT_MID			+= 5;
			PASS_ACC			+= 5;
			PER_D				+= 2;
			INT_D				+= 2;
			SHOT_CONTEST		+= 5;
			BLOCK				+= 2;
			DEF_REB				+= 5;
			OFF_REB				+= 2;
			SPEED				+= 5;
			STRENGTH			+= 5;
		}
		else if (this->build == "Shooter      ")
		{
			BABDULISHNESS		-= 0;
			SHOT_CLOSE			+= 5;
			SHOT_3				+= 10;
			SHOT_MID			+= 10;
			PASS_ACC			+= 0;
			PER_D				-= 5;
			INT_D				-= 10;
			SHOT_CONTEST		-= 5;
			BLOCK				-= 10;
			DEF_REB				-= 5;
			OFF_REB				-= 5;
			SPEED				-= 2;
			STRENGTH			-= 10;
		}
		else if (this->build == "Playmaker    ")
		{
			BABDULISHNESS		-= 5;
			SHOT_CLOSE			+= 2;
			SHOT_3				+= 2;
			SHOT_MID			+= 8;
			PASS_ACC			+= 10;
			PER_D				+= 5;
			INT_D				-= 10;
			SHOT_CONTEST		+= 5;
			BLOCK				-= 10;
			DEF_REB				+= 0;
			OFF_REB				+= 0;
			SPEED				+= 10;
			STRENGTH			-= 8;
		}
		else if (this->build == "Defender     ")
		{
			BABDULISHNESS		-= 5;
			SHOT_CLOSE			+= 0;
			SHOT_3				-= 10;
			SHOT_MID			-= 8;
			PASS_ACC			-= 5;
			PER_D				+= 8;
			INT_D				+= 8;
			SHOT_CONTEST		+= 10;
			BLOCK				+= 5;
			DEF_REB				+= 5;
			OFF_REB				+= 0;
			SPEED				+= 2;
			STRENGTH			+= 5;
		}
		else if (this->build == "Slasher      ")
		{
			BABDULISHNESS		-= 0;
			SHOT_CLOSE			+= 10;
			SHOT_3				-= 2;
			SHOT_MID			+= 8;
			PASS_ACC			+= 8;
			PER_D				+= 8;
			INT_D				-= 5;
			SHOT_CONTEST		+= 8;
			BLOCK				+= 0;
			DEF_REB				+= 2;
			OFF_REB				+= 8;
			SPEED				+= 10;
			STRENGTH			+= 8;
		}
		else if (this->build == "Rebounder    ")
		{
			BABDULISHNESS		-= 0;
			SHOT_CLOSE			+= 8;
			SHOT_3				-= 5;
			SHOT_MID			+= 5;
			PASS_ACC			-= 2;
			PER_D				-= 8;
			INT_D				+= 5;
			SHOT_CONTEST		+= 2;
			BLOCK				+= 2;
			DEF_REB				+= 10;
			OFF_REB				+= 10;
			SPEED				+= 2;
			STRENGTH			+= 10;
		}
		else if (this->build == "Shot_Blocker ")
		{
			BABDULISHNESS		-= 0;
			SHOT_CLOSE			+= 2;
			SHOT_3				-= 10;
			SHOT_MID			-= 8;
			PASS_ACC			-= 5;
			PER_D				-= 5;
			INT_D				+= 10;
			SHOT_CONTEST		+= 10;
			BLOCK				+= 10;
			DEF_REB				+= 8;
			OFF_REB				+= 0;
			SPEED				-= 2;
			STRENGTH			+= 10;
		}
		else if (this->build == "Paint_Scorer ")
		{
			BABDULISHNESS		-= 2;
			SHOT_CLOSE			+= 10;
			SHOT_3				-= 5;
			SHOT_MID			+= 2;
			PASS_ACC			+= 0;
			PER_D				-= 10;
			INT_D				+= 2;
			SHOT_CONTEST		+= 0;
			BLOCK				+= 2;
			DEF_REB				+= 5;
			OFF_REB				+= 8;
			SPEED				-= 2;
			STRENGTH			+= 10;
		}
		else
		{
			cout << "Build not found" << endl;
		}
	}

	int generateShotClose(int height)
	{
		int base = height - 10;

		if (build == "Paint_Scorer " && base < 80)
			base += 10;

		int variation = rand() % 30 - 15;
		return (base + variation);
	}

	int generateShotMid(int height)
	{
		int base = height - 10;
		if (height < 70)
			base += 10;
		if (height < 75)
			base += 10;
		if (height < 78)
			base += 10;
		if (height >= 80)
			base += 2;
		if (height >= 82)
			base -= 2;

		if (build == "Shooter      " && base < 80)
			base += 10;

		if (base < (SHOT_3 - 10))
		{
			base = SHOT_3 - 10;
		}

		int variation = rand() % 10 - 5;
		return base;
	}

	int generateShot3(int height)
	{
		int base = height - 10;
		if (height < 70)
			base += 10;
		if (height < 75)
			base += 10;
		if (height < 78)
			base += 10;
		if (height >= 80)
			base += 2;
		if (height >= 82)
			base -= 8;

		if (build == "Shooter      " && base < 80)
			base += 10;

		int variation = rand() % 10 - 5;
		return (base + variation);
	}

	int generatePassAccuracy(int height)
	{
		int base = height - 12;
		if (height < 70)
			base += 10;
		if (height < 75)
			base += 8;
		if (height < 78)
			base += 8;
		if (height >= 80)
			base += 2;
		if (height >= 82)
			base -= 5;

		if (build == "Playmaker    " && base < 80)
			base += 10;

		int variation = rand() % 10 - 5;
		return (base + variation);
	}
	
	int generateSpeed(int height)
	{
		int base = height - 10;
		if (height < 70)
			base += 10;
		if (height < 75)
			base += 8;
		if (height < 78)
			base += 8;
		if (height >= 80)
			base -= 5;
		if (height >= 82)
			base -= 15;

		int variation = rand() % 10 - 5;
		return (base + variation);
	}

	int generateStrength(int height)
	{
		int base = (weight / 5) - 10;
		if (height < 70)
			base -= 25;
		if (height < 75)
			base -= 8;
		if (height < 78)
			base += 5;
		if (height >= 80)
			base += 8;
		if (height >= 82)
			base += 10;

		if (build == "Defender     " && base < 80 && (position == "C " || position == "PF"))
			base += 10;
		
		int variation = rand() % 10 - 5;
		return (base + variation);
	}

	int generatePerimeterD(int height)
	{
		int base = height - 10;
		if (height < 70)
			base += 2;
		if (height < 75)
			base += 5;
		if (height < 78)
			base += 10;
		if (height >= 80)
			base -= 5;
		if (height >= 82)
			base -= 10;

		if (build == "Defender     " && base < 80)
			base += 10;

		int variation = rand() % 10 - 5;
		return (base + variation);
	}

	int generateInteriorD(int height)
	{
		int base = height - 10;
		if (height < 70)
			base -= 40;
		if (height < 75)
			base -= 30;
		if (height < 78)
			base -= 5;
		if (height >= 80)
			base += 8;
		if (height >= 82)
			base += 10;

		if (build == "Defender     " && base < 80)
			base += 10;

		int variation = rand() % 10 - 5;
		return (base + variation);
	}

	int generateShotContest(int height)
	{
		int base = height - 15;
		if (height < 70)
			base -= 5;
		if (height < 75)
			base += 0;
		if (height < 78)
			base += 5;
		if (height >= 80)
			base += 5;
		if (height >= 82)
			base += 5;

		if (build == "Defender     " && base < 80)
			base += 10;

		int variation = rand() % 10 - 5;
		return (base + variation);
	}

	int generateBlock(int height)
	{
		int base = height - 10;
		if (height < 70)
			base -= 45;
		if (height < 75)
			base -= 35;
		if (height < 78)
			base -= 15;
		if (height >= 78)
			base -= 2;
		if (height >= 82)
			base += 2;

		if (build == "Shot_Blocker " && base < 80)
			base += 10;

		int variation = rand() % 10 - 5;
		return (base + variation);
	}

	int generateDefRebound(int height)
	{
		int base = height - 10;
		if (height < 70)
			base -= 10;
		if (height < 75)
			base -= 5;
		if (height < 78)
			base += 2;
		if (height >= 78)
			base += 5;
		if (height >= 82)
			base += 5;

		if (build == "Rebounder    " && base < 80)
			base += 10;

		int variation = rand() % 10 - 5;
		return (base + variation);
	}

	int generateOffRebound(int height)
	{
		int base = height - 10;
		if (height < 70)
			base -= 30;
		if (height < 75)
			base -= 20;
		if (height < 78)
			base += 2;
		if (height >= 78)
			base += 5;
		if (height >= 82)
			base += 5;

		if (build == "Rebounder    " && base < 80)
			base += 10;

		int variation = rand() % 25 - 15;
		return (base + variation);
	}

	int generateBabdulishness()
	{
		int base = rand() % 50 + 25;
		return (base);
	}

	int heightInInches(pair<int,int> height)
	{
		// 5ft = 60 inches
		// 6ft = 72 inches
		// 7ft = 84 inches

		return ((height.first * 12) + height.second);
	}

	int calculateOverall(int babdulishness, int shotClose, int shotMid, int shot3, int passAccuracy, int perimeterD, int interiorD, int shotContest, int block, int defRebound, int offRebound, int speed, int strength)
	{
		int overall = (
			((100 - babdulishness)	* 4) +
			(shotClose				* 3) +
			(shotMid				* 3) +
			(shot3					* 4) +

			(passAccuracy			* 2) +

			(perimeterD				* 2) +
			(interiorD				* 2) +
			(shotContest			* 4) +
			(block					* 1) +

			(defRebound				* 2) +
			(offRebound				* 1) +

			(speed					* 2) +
			(strength				* 2)
			) / 28;

		return overall;
	}

	void generateDraftAttributes()
	{
		draftAttributes.babdulishness	= BABDULISHNESS		+ rand() % 10 - 5;
		draftAttributes.shotClose		= SHOT_CLOSE		+ rand() % 10 - 5;
		draftAttributes.shotMid			= SHOT_MID			+ rand() % 10 - 5;
		draftAttributes.shot3			= SHOT_3			+ rand() % 10 - 5;
		draftAttributes.passAccuracy	= PASS_ACC			+ rand() % 10 - 5;
		draftAttributes.perimeterD		= PER_D				+ rand() % 10 - 5;
		draftAttributes.interiorD		= INT_D				+ rand() % 10 - 5;
		draftAttributes.shotContest		= SHOT_CONTEST		+ rand() % 10 - 5;
		draftAttributes.block			= BLOCK				+ rand() % 10 - 5;
		draftAttributes.defRebound		= DEF_REB			+ rand() % 10 - 5;
		draftAttributes.offRebound		= OFF_REB			+ rand() % 10 - 5;
		draftAttributes.speed			= SPEED				+ rand() % 10 - 5;
		draftAttributes.strength		= STRENGTH			+ rand() % 10 - 5;
	}

public:
	
	Babdul()
	{
		babName = generateBabName();
		age = rand() % 7 + 18;
		height = generateHeight();
		weight = generateWeight(heightInInches(height));
		position = generatePosition(height);
		tier = generateTier();
		build = generateBuild(position);

		BABDULISHNESS = generateBabdulishness();

		SHOT_CLOSE = generateShotClose(heightInInches(height));
		SHOT_3 = generateShot3(heightInInches(height));
		SHOT_MID = generateShotMid(heightInInches(height));

		PASS_ACC = generatePassAccuracy(heightInInches(height));

		PER_D = generatePerimeterD(heightInInches(height));
		INT_D = generateInteriorD(heightInInches(height));
		SHOT_CONTEST = generateShotContest(heightInInches(height));
		BLOCK = generateBlock(heightInInches(height));

		DEF_REB = generateDefRebound(heightInInches(height));
		OFF_REB = generateOffRebound(heightInInches(height));

		SPEED = generateSpeed(heightInInches(height));
		STRENGTH = generateStrength(heightInInches(height));

		tierAdjustments();
		buildAdjustments();

		generateDraftAttributes();

		overall = calculateOverall(BABDULISHNESS, SHOT_CLOSE, SHOT_MID, SHOT_3, PASS_ACC, PER_D, INT_D, SHOT_CONTEST, BLOCK, DEF_REB, OFF_REB, SPEED, STRENGTH);

		points = 0;
		blocks = 0;
		assists = 0;
		rebounds = 0;
		turnovers = 0;

		statCorrect();
		resetSliders(1);
	}

	Babdul(string babName)
	{
		this->babName = babName;
		age = rand() % 7 + 18;
		height = generateHeight();
		weight = generateWeight(heightInInches(height));
		position = generatePosition(height);
		tier = generateTier();
		build = generateBuild(position);

		BABDULISHNESS = generateBabdulishness();

		SHOT_CLOSE = generateShotClose(heightInInches(height));
		SHOT_3 = generateShot3(heightInInches(height));
		SHOT_MID = generateShotMid(heightInInches(height));

		PASS_ACC = generatePassAccuracy(heightInInches(height));

		PER_D = generatePerimeterD(heightInInches(height));
		INT_D = generateInteriorD(heightInInches(height));
		SHOT_CONTEST = generateShotContest(heightInInches(height));
		BLOCK = generateBlock(heightInInches(height));

		DEF_REB = generateDefRebound(heightInInches(height));
		OFF_REB = generateOffRebound(heightInInches(height));

		SPEED = generateSpeed(heightInInches(height));
		STRENGTH = generateStrength(heightInInches(height));

		tierAdjustments();
		buildAdjustments();

		generateDraftAttributes();

		overall = calculateOverall(BABDULISHNESS, SHOT_CLOSE, SHOT_MID, SHOT_3, PASS_ACC, PER_D, INT_D, SHOT_CONTEST, BLOCK, DEF_REB, OFF_REB, SPEED, STRENGTH);

		points = 0;
		blocks = 0;
		assists = 0;
		rebounds = 0;
		turnovers = 0;

		statCorrect();
		resetSliders(1);
	}

	Babdul(string babName, pair<int,int> height, int weight, string position, string tier, string build, float babdulishness, int shotClose, int shotMid, int shot3, int passAccuracy, int perimeterD, int interiorD, int shotContest, int block, int defRebound, int offRebound, int speed, int strength)
	{
		this->babName = babName;
		age = rand() % 7 + 18;
		this->weight = weight;
		this->height = height;
		this->position = position;
		this->tier = tier;
		this->build = build;
		
		BABDULISHNESS = babdulishness;
		
		SHOT_CLOSE = shotClose;
		SHOT_3 = shot3;
		SHOT_MID = shotMid;
		
		PASS_ACC = passAccuracy;

		PER_D = perimeterD;
		INT_D = interiorD;
		SHOT_CONTEST = shotContest;
		BLOCK = block;

		DEF_REB = defRebound;
		OFF_REB = offRebound;

		SPEED = speed;
		STRENGTH = strength;

		generateDraftAttributes();

		overall = calculateOverall(babdulishness, shotClose, shotMid, shot3, passAccuracy, perimeterD, interiorD, shotContest, block, defRebound, offRebound, speed, strength);

		points = 0;
		blocks = 0;
		assists = 0;
		rebounds = 0;
		turnovers = 0;

		statCorrect();
		resetSliders(1);
	}

	Babdul(string babName, pair<int, int> height, int weight, string position, string tier, string build, float babdulishness, int shotClose, int shotMid, int shot3, int passAccuracy, int perimeterD, int interiorD, int shotContest, int block, int defRebound, int offRebound, int speed, int strength, bool isInDraft)
	{
		this->babName = babName;
		age = rand() % 7 + 18;
		this->weight = weight;
		this->height = height;
		this->position = position;
		this->tier = tier;
		this->build = build;

		BABDULISHNESS = babdulishness;

		SHOT_CLOSE = shotClose;
		SHOT_3 = shot3;
		SHOT_MID = shotMid;

		PASS_ACC = passAccuracy;

		PER_D = perimeterD;
		INT_D = interiorD;
		SHOT_CONTEST = shotContest;
		BLOCK = block;

		DEF_REB = defRebound;
		OFF_REB = offRebound;

		SPEED = speed;
		STRENGTH = strength;

		generateDraftAttributes();

		overall = calculateOverall(babdulishness, shotClose, shotMid, shot3, passAccuracy, perimeterD, interiorD, shotContest, block, defRebound, offRebound, speed, strength);

		this->isInDraft = isInDraft;

		points = 0;
		blocks = 0;
		assists = 0;
		rebounds = 0;
		turnovers = 0;

		statCorrect();
		resetSliders(1);
	}

	Babdul(int nameIndex)
	{
		// Randomize Babnames
		auto rng = std::default_random_engine{};
		std::shuffle(std::begin(babNames), std::end(babNames), rng);

		babName = babNames.at(nameIndex);
		age = rand() % 7 + 18;
		height = generateHeight();
		weight = generateWeight(heightInInches(height));
		position = generatePosition(height);
		tier = generateTier();
		build = generateBuild(position);

		BABDULISHNESS = generateBabdulishness();

		SHOT_CLOSE = generateShotClose(heightInInches(height));
		SHOT_3 = generateShot3(heightInInches(height));
		SHOT_MID = generateShotMid(heightInInches(height));

		PASS_ACC = generatePassAccuracy(heightInInches(height));

		PER_D = generatePerimeterD(heightInInches(height));
		INT_D = generateInteriorD(heightInInches(height));
		SHOT_CONTEST = generateShotContest(heightInInches(height));
		BLOCK = generateBlock(heightInInches(height));

		DEF_REB = generateDefRebound(heightInInches(height));
		OFF_REB = generateOffRebound(heightInInches(height));

		SPEED = generateSpeed(heightInInches(height));
		STRENGTH = generateStrength(heightInInches(height));

		tierAdjustments();
		buildAdjustments();

		generateDraftAttributes();

		overall = calculateOverall(BABDULISHNESS, SHOT_CLOSE, SHOT_MID, SHOT_3, PASS_ACC, PER_D, INT_D, SHOT_CONTEST, BLOCK, DEF_REB, OFF_REB, SPEED, STRENGTH);

		points = 0;
		blocks = 0;
		assists = 0;
		rebounds = 0;
		turnovers = 0;

		statCorrect();
		resetSliders(1);

		logger.info("\tCreated Babdul: " + this->getBabName());
	}

	string getBabName() { return this->babName; }

	int getAge() { return this->age; }

	int getWeight() { return this->weight; }

	pair<int, int> getHeight() { return this->height; }
	int getHeightInInches() { return ((height.first * 12) + height.second);	}

	string getPosition() { return this->position; }

	string getTier() { return this->tier; }
	string getBuild() { return this->build; }

	void resetSliders(int sliderNum) { sliders.setSliders("Default", sliderNum); }

	float getBabdulishness() { return BABDULISHNESS; }
	
	int getShotClose() { return SHOT_CLOSE; }
	int getShotMid() { return SHOT_MID; }
	int getShot3() { return SHOT_3; }
	int getPassAccuracy() { return PASS_ACC; }
	int getPerimeterD() { return PER_D; }
	int getInteriorD() { return INT_D; }
	int getShotContest() { return SHOT_CONTEST; }
	int getBlock() { return BLOCK; }
	int getDefRebound() { return DEF_REB; }
	int getOffRebound() { return OFF_REB; }
	int getSpeed() { return SPEED; }
	int getStrength() { return STRENGTH; }

	int getOverall() { return this->overall; }

	int getPoints() { return this->points; }

	int getBlocks() { return this->blocks; }

	int getAssists() { return this->assists; }

	int getRebounds() { return this->rebounds; }

	int getTurnovers() { return this->turnovers; }

	void addPoints(int points) { this->points += points; }
	void setPoints(int points) { this->points = points; }

	void addBlock() { this->blocks += 1; }

	void addAssist() { this->assists += 1; }

	void addDefRebound() { this->rebounds += 1; }
	void addOffRebound() { this->rebounds += 1; }

	void addTurnover() { this->turnovers += 1; }

	int getLocation() { return this->location; }
	void setLocation(int loc) { this->location = loc; }

	bool getBallCarrier() { return this->ballCarrier; }
	void setBallCarrier(bool bc) { this->ballCarrier = bc; }

	bool getWasPasser() { return this->wasPasser; }
	void setWasPasser(bool wp) { this->wasPasser = wp; }

	bool getIsRebounder() { return this->isRebounder; }
	void setIsRebounder(bool ir) { this->isRebounder = ir; }

	bool getIsInDraft() { return this->isInDraft; }
	void setIsInDraft(bool isInDraft) { this->isInDraft = isInDraft; }

	string getMatchup() { return matchupName; }
	void setMatchup(string matchupName) { this->matchupName = matchupName; }
	
	void printStats()
	{
		cout << endl;
		cout << "---------------------------" << endl;
		cout << "Name:              " << getBabName() << endl;
		cout << "---------------------------" << endl;
		cout << "Tier:              " << getTier() << endl;
		cout << "Build:             " << getBuild() << endl;
		cout << "---------------------------" << endl;
		cout << "Overall:           " << getOverall() << endl
			<< endl;			    
		cout << "Babdulishness:     " << getBabdulishness() << endl 
			<< endl;			    
		cout << "Shot Close:        " << getShotClose() << endl;
		cout << "Shot Mid:          " << getShotMid() << endl;
		cout << "Shot 3:            " << getShot3() << endl
			<< endl;			    
		cout << "Passing Accuracy:  " << getPassAccuracy() << endl
			<< endl;
		cout << "Perimeter Defense: " << getPerimeterD() << endl;
		cout << "Interior Defense:  " << getInteriorD() << endl;
		cout << "Shot Contest:      " << getShotContest() << endl;
		cout << "Block:             " << getBlock() << endl
			<< endl;			    
		cout << "Defensive Rebound: " << getDefRebound() << endl;
		cout << "Offensive Rebound: " << getOffRebound() << endl
			<< endl;			    
		cout << "Speed:             " << getSpeed() << endl;
		cout << "Strength:          " << getStrength() << endl;
		cout << "---------------------------" << endl;
		cout << endl;
	}

	void printStatsHorizontally()
	{
		//cout << "             BabName Position Tier       Build         Age Weight Height      Overall Babdulishness S-Close S-Mid S-3 PSAC Per-D Int-D S-Contest Block Def-Reb Off-Reb Speed Strength" << endl;
		//cout << "             ========================================================================================================================================================================" << endl;
		cout << 
			getBabName() << " " <<
			getPosition() << "       " <<
			getTier() << " " <<
			getBuild() << " " <<
			getAge() << "  " <<
			getWeight() << "    " <<
			getHeight().first << "ft ";

		if (getHeight().second < 10)
			cout << getHeight().second << "in     ";
		else
			cout << getHeight().second << "in    ";

		cout <<
			getOverall() << "      " <<
			getBabdulishness() << "            " <<
			getShotClose() << "      " <<
			getShotMid() << "    " <<
			getShot3() << "  " <<
			getPassAccuracy() << "   " <<
			getPerimeterD() << "    " <<
			getInteriorD() << "    " <<
			getShotContest() << "        " <<
			getBlock() << "    " <<
			getDefRebound() << "      " <<
			getOffRebound() << "      " <<
			getSpeed() << "    " <<
			getStrength() << "" <<
			endl;
		cout << "             ------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}

	void printOffensiveStatsHorizontally(int teamColor)
	{
		//cout << "BabName Position Overall Babdulishness S-Close S-Mid S-3 PSAC Per-D Int-D S-Contest Block Def-Reb Off-Reb Speed Strength" << endl;
		//cout << "========================================================================================================================" << endl;
		setTextColor(teamColor);
		cout << getBabName() << " ";
		//setTextColor(GRAY);
		setTextColor(DEFAULT);
		cout << getPosition() << "       ";
		cout << getOverall() << "      ";
		setTextColor(BRIGHT_WHITE);
		cout << getBabdulishness() << "            ";
		cout << getShotClose() << "      ";
		cout << getShotMid() << "    ";
		cout << getShot3() << "  ";
		cout << getPassAccuracy() << "   ";
		setTextColor(GRAY);
		/*cout << getPerimeterD() << "    ";
		cout << getInteriorD() << "    ";
		cout << getShotContest() << "        ";
		cout << getBlock() << "    ";
		cout << getDefRebound() << "      ";*/
		cout << "  " << "    ";
		cout << "  " << "    ";
		cout << "  " << "        ";
		cout << "  " << "    ";
		cout << "  " << "      ";
		setTextColor(BRIGHT_WHITE);
		cout << getOffRebound() << "      ";
		cout << getSpeed() << "    ";
		cout << getStrength() << "";
		cout << endl;
		setTextColor(DEFAULT);
	}

	void printDefensiveStatsHorizontally()
	{
		//cout << "BabName Position Overall Babdulishness S-Close S-Mid S-3 PSAC Per-D Int-D S-Contest Block Def-Reb Off-Reb Speed Strength" << endl;
		//cout << "========================================================================================================================" << endl;
		//setTextColor(teamColor);
		cout << getBabName() << " ";
		//setTextColor(GRAY);
		setTextColor(DEFAULT);
		cout << getPosition() << "       ";
		cout << getOverall() << "      ";
		setTextColor(BRIGHT_WHITE);
		cout << getBabdulishness() << "            ";
		setTextColor(GRAY);
		/*cout << getShotClose() << "      ";
		cout << getShotMid() << "    ";
		cout << getShot3() << "  ";
		cout << getPassAccuracy() << "   ";*/
		cout << "  " << "      ";
		cout << "  " << "    ";
		cout << "  " << "  ";
		cout << "  " << "   ";
		setTextColor(BRIGHT_WHITE);
		cout << getPerimeterD() << "    ";
		cout << getInteriorD() << "    ";
		cout << getShotContest() << "        ";
		cout << getBlock() << "    ";
		cout << getDefRebound() << "      ";
		setTextColor(GRAY);
		/*cout << getOffRebound() << "      ";
		cout << getSpeed() << "    ";
		cout << getStrength() << "";*/
		cout << "  " << "      ";
		cout << "  " << "    ";
		cout << "  " << "";
		cout << endl;
		setTextColor(DEFAULT);
	}

	void statCorrect()
	{
		if (this->age > 99)
			this->age = 99;
		else if (this->age < 1)
			this->age = 1;

		if (this->weight > 999)
			this->weight = 999;
		else if (this->weight < 1)
			this->weight = 1;

		if (this->height.first > 9)
			this->height.first = 9;
		else if (this->height.first < 1)
			this->height.first = 1;

		if (this->height.second > 11)
			this->height.second = 11;
		else if (this->height.second < 0)
			this->height.second = 0;

		if (this->overall > 99)
			this->overall = 99;
		else if (this->overall < 25)
			this->overall = 25;
		
		if (BABDULISHNESS > 99)
			BABDULISHNESS = 99;
		else if (BABDULISHNESS < 10)
			BABDULISHNESS = 10;

		if (SHOT_CLOSE > 99)
			SHOT_CLOSE = 99;
		else if (SHOT_CLOSE < 10)
			SHOT_CLOSE = 10;

		if (SHOT_MID > 99)
			SHOT_MID = 99;
		else if (SHOT_MID < 10)
			SHOT_MID = 10;

		if (SHOT_3 > 99)
			SHOT_3 = 99;
		else if (SHOT_3 < 10)
			SHOT_3 = 10;

		if (PASS_ACC > 99)
			PASS_ACC = 99;
		else if (PASS_ACC < 10)
			PASS_ACC = 10;

		if (PER_D > 99)
			PER_D = 99;
		else if (PER_D < 10)
			PER_D = 10;

		if (INT_D > 99)
			INT_D = 99;
		else if (INT_D < 10)
			INT_D = 10;

		if (SHOT_CONTEST > 99)
			SHOT_CONTEST = 99;
		else if (SHOT_CONTEST < 10)
			SHOT_CONTEST = 10;

		if (BLOCK > 99)
			BLOCK = 99;
		else if (BLOCK < 10)
			BLOCK = 10;

		if (SPEED > 99)
			SPEED = 99;
		else if (SPEED < 10)
			SPEED = 10;

		if (this->DEF_REB > 99)
			this->DEF_REB = 99;
		else if (this->DEF_REB < 10)
			this->DEF_REB = 10;

		if (this->OFF_REB > 99)
			this->OFF_REB = 99;
		else if (this->OFF_REB < 10)
			this->OFF_REB = 10;

		if (this->STRENGTH > 99)
			this->STRENGTH = 99;
		else if (this->STRENGTH < 10)
			this->STRENGTH = 10;
	}

	bool shoot(Babdul& defender, int numPasses, int numDrives, int timesPlayRun)
	{
		int success = rand() % 100 + 1;

		int newBabdulishness = ((BABDULISHNESS * sliders.slider_babdulishness) / (numPasses + 1)) - (numDrives * 5);
		int newSkill = 0;

		if (location == 7)
		{
			newSkill = ((SHOT_CLOSE * sliders.slider_shotClose) + (numPasses * 5) + (numDrives * 5));
			if (build == "Slasher      ")
			{
				newSkill += 2;
				newBabdulishness -= 2;
			}
		}
		else if (location == 6)
			newSkill = ((SHOT_MID * sliders.slider_shotMid) + (numPasses * 5) + (numDrives * 5));
		else if (location < 6)
			newSkill = ((SHOT_3 * sliders.slider_shot3) + (numPasses * 5) + (numDrives * 5));

		if (defender.getBuild() == "Defender     ")
		{
			newSkill -= 5;
		}

		if (build == "Shooter      ")
		{
			newSkill += 3;
			newBabdulishness -= 3;
		}

		if (build == "All_Around   ")
		{
			newSkill += 1;
			newBabdulishness -= 1;
		}

		int timesRunModifier = 1;
		if (timesPlayRun > 1) { timesRunModifier = timesPlayRun; }
		newSkill -= ((defender.getShotContest() * defender.sliders.slider_shotContest) / 7) * timesRunModifier;

		int percentChance = newSkill - newBabdulishness + 1;
		if (percentChance < 0) { percentChance = 0; }
		//cout << endl << "B:" << newBabdulishness << " S: " << newSkill << " (" << newSkill-newBabdulishness << "%)" << endl;

		/*unsigned int seconds = 1000;
		cout << endl << "Shooting";
		Sleep(0.2 * seconds);
		cout << " .";
		Sleep(0.2 * seconds);
		cout << " .";
		Sleep(0.2 * seconds);
		cout << " .";
		Sleep(0.2 * seconds);
		cout << endl << "Chance: " << success << endl;*/

		//cout << endl << "B:" << newBabdulishness << " S: " << newSkill << endl << "Chance: " << success << ". ";
		if (newSkill + ((defender.getShotContest() * defender.sliders.slider_shotContest) / 7) > success && success > newSkill)
			playResults.pr_7_reason = "Defender's shot contest altered the shot";
			//cout << "Defender's shot contest altered the shot" << endl;
		else if (newSkill + ((defender.getShotContest() * defender.sliders.slider_shotContest) / 7) * timesRunModifier > success&& success > newSkill)
			playResults.pr_7_reason = "The defense recognizes this play (run " + to_string(timesPlayRun) + "x), improving the defenders shot contest";
		else if (success < newBabdulishness)
			playResults.pr_7_reason = "Too much babdulishness";
			//cout << "Too much Babdulishness" << endl;
		else if (success > newSkill)
			playResults.pr_7_reason = "Not enough skill";
			//cout << "Insufficient shooting skill" << endl;

		playResults.pr_4_range = "B: " + to_string(newBabdulishness) + " S: " + to_string(newSkill);
		playResults.pr_5_roll = to_string(success);

		if (success > newBabdulishness && success < newSkill)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool shoot(Babdul& passer, Babdul& defender, int numPasses, int numDrives, int timesPlayRun)
	{
		int success = rand() % 100 + 1;

		int newBabdulishness = ((BABDULISHNESS * sliders.slider_babdulishness) / (numPasses + 1)) - (numDrives * 5);
		int newSkill = 0;

		if (location == 7)
		{
			newSkill = ((SHOT_CLOSE * sliders.slider_shotClose) + (numPasses * 5) + (numDrives * 5));
			if (build == "Slasher      ")
			{
				newSkill += 2;
				newBabdulishness -= 2;
			}
		}
		else if (location == 6)
			newSkill = ((SHOT_MID * sliders.slider_shotMid) + (numPasses * 5) + (numDrives * 5));
		else if (location < 6)
			newSkill = ((SHOT_3 * sliders.slider_shot3) + (numPasses * 5) + (numDrives * 5));

		if (passer.getBuild() == "Playmaker    ")
		{
			newSkill += 2;
			newBabdulishness -= 2;
		}

		if (defender.getBuild() == "Defender     ")
		{
			newSkill -= 5;
		}

		if (build == "Shooter      ")
		{
			newSkill += 3;
			newBabdulishness -= 3;
		}

		if (build == "All_Around   ")
		{
			newSkill += 1;
			newBabdulishness -= 1;
		}

		int timesRunModifier = 1;
		if (timesPlayRun > 1) { timesRunModifier = timesPlayRun; }
		newSkill -= ((defender.getShotContest() * defender.sliders.slider_shotContest) / 7) * timesRunModifier;

		int percentChance = newSkill - newBabdulishness + 1;
		if (percentChance < 0) { percentChance = 0; }
		//cout << endl << "B:" << newBabdulishness << " S: " << newSkill << " (" << newSkill - newBabdulishness << "%)" << endl;

		/*unsigned int seconds = 1000;
		cout << endl << "Shooting";
		Sleep(0.2 * seconds);
		cout << " .";
		Sleep(0.2 * seconds);
		cout << " .";
		Sleep(0.2 * seconds);
		cout << " .";
		Sleep(0.2 * seconds);
		cout << endl << "Chance: " << success << endl << endl;*/
		
		//cout << endl << "B:" << newBabdulishness << " S: " << newSkill << endl << "Chance: " << success << ". ";
		if (newSkill + ((defender.getShotContest() * defender.sliders.slider_shotContest) / 7) > success && success > newSkill)
			playResults.pr_7_reason = "Defender's shot contest altered the shot";
		//cout << "Defender's shot contest altered the shot" << endl;
		else if (newSkill + ((defender.getShotContest() * defender.sliders.slider_shotContest) / 7) * timesRunModifier > success&& success > newSkill)
			playResults.pr_7_reason = "The defense recognizes this play (run " + to_string(timesPlayRun) + "x), improving the defenders shot contest";
		else if (success < newBabdulishness)
			playResults.pr_7_reason = "Too much babdulishness";
			//cout << "Too much Babdulishness" << endl;
		else if (success > newSkill)
			playResults.pr_7_reason = "Not enough skill";
			//cout << "Insufficient shooting skill" << endl;

		playResults.pr_4_range = "B: " + to_string(newBabdulishness) + " S: " + to_string(newSkill);
		playResults.pr_5_roll = to_string(success);

		if (success > newBabdulishness && success < newSkill)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string shootChance(Babdul& passer, Babdul& defender, int numPasses, int numDrives, int timesPlayRun)
	{
		int newBabdulishness = ((BABDULISHNESS * sliders.slider_babdulishness) / (numPasses + 1)) - (numDrives * 5);
		int newSkill = 0;

		if (location == 7)
		{
			newSkill = ((SHOT_CLOSE * sliders.slider_shotClose) + (numPasses * 5) + (numDrives * 5));
			if (build == "Slasher      ")
			{
				newSkill += 2;
				newBabdulishness -= 2;
			}
		}
		else if (location == 6)
			newSkill = ((SHOT_MID * sliders.slider_shotMid) + (numPasses * 5) + (numDrives * 5));
		else if (location < 6)
			newSkill = ((SHOT_3 * sliders.slider_shot3) + (numPasses * 5) + (numDrives * 5));

		if (passer.getBuild() == "Playmaker    ")
		{
			newSkill += 2;
			newBabdulishness -= 2;
		}

		if (defender.getBuild() == "Defender     ")
		{
			newSkill -= 5;
		}

		if (build == "Shooter      ")
		{
			newSkill += 3;
			newBabdulishness -= 3;
		}

		if (build == "All_Around   ")
		{
			newSkill += 1;
			newBabdulishness -= 1;
		}

		int timesRunModifier = 1;
		if (timesPlayRun > 1) { timesRunModifier = timesPlayRun; }
		newSkill -= ((defender.getShotContest() * defender.sliders.slider_shotContest) / 7) * timesRunModifier;

		int percentChance = newSkill - newBabdulishness - 1;
		if (percentChance < 0) { percentChance = 0; }
		else if (percentChance > 100) { percentChance = 100; }

		string buffer = "";
		if (percentChance < 10) { buffer = "  "; }
		else if (percentChance < 100) { buffer = " "; }
		return buffer + to_string(percentChance) + "%";
	}

	bool pass(Babdul& defender, int numPasses, int numDrives)
	{
		int success = rand() % 100 + 1;

		int newBabdulishness = (((BABDULISHNESS * sliders.slider_babdulishness) / 4) / (numPasses + 1));
		int newSkill = ((PASS_ACC * sliders.slider_passAccuracy) + (numPasses * 5) + (numDrives * 5));

		if (build == "Playmaker    ")
		{
			newSkill += 3;
			newBabdulishness -= 3;
		}

		if (build == "All_Around   ")
		{
			newSkill += 1;
			newBabdulishness -= 1;
		}

		//cout << endl << "B:" << newBabdulishness << " S: " << newSkill << endl << "Chance: " << success << ". ";
		if (success < newBabdulishness)
			playResults.pr_7_reason = "Too much babdulishness";
			//cout << "Too much Babdulishness" << endl;
		else if (success > newSkill)
			playResults.pr_7_reason = "Not enough passing accuracy";
			//cout << "Insufficient passing accuracy" << endl;

		playResults.pr_4_range = "B: " + to_string(newBabdulishness) + " S: " + to_string(newSkill);
		playResults.pr_5_roll = to_string(success);

		if (success > newBabdulishness && success < newSkill)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string passChance(Babdul& defender, int numPasses, int numDrives)
	{
		int newBabdulishness = (((BABDULISHNESS * sliders.slider_babdulishness) / 4) / (numPasses + 1));
		int newSkill = ((PASS_ACC * sliders.slider_passAccuracy) + (numPasses * 5) + (numDrives * 5));

		if (build == "Playmaker    ")
		{
			newSkill += 3;
			newBabdulishness -= 3;
		}

		if (build == "All_Around   ")
		{
			newSkill += 1;
			newBabdulishness -= 1;
		}

		int percentChance = newSkill - newBabdulishness - 1;
		if (percentChance < 0) { percentChance = 0; }
		else if (percentChance > 100) { percentChance = 100; }

		string buffer = "";
		if (percentChance < 10) { buffer = "  "; }
		else if (percentChance < 100) { buffer = " "; }
		return buffer + to_string(percentChance) + "%";
	}

	bool drive(Babdul& defender, int numPasses, int numDrives)
	{
		int success = rand() % 100 + 1;

		int newBabdulishness = (((BABDULISHNESS * sliders.slider_babdulishness) / 3) / (numPasses + 1));
		int newSkill = ((SPEED * sliders.slider_speed) + (numPasses * 5) + (numDrives * 5));

		if (build == "Slasher      ")
		{
			newSkill += 3;
			newBabdulishness -= 3;
		}

		if (build == "All_Around   ")
		{
			newSkill += 1;
			newBabdulishness -= 1;
		}

		//cout << endl << "B:" << newBabdulishness << " S: " << newSkill << endl << "Chance: " << success << ". ";
		if (success < newBabdulishness)
			playResults.pr_7_reason = "Too much babdulishness";
			//cout << "Too much Babdulishness" << endl;
		else if (success > newSkill)
			playResults.pr_7_reason = "Not enough speed";
			//cout << "Insufficient speed" << endl;
		else if (SPEED < (defender.getPerimeterD() - (numPasses + (numDrives * 2))))
			playResults.pr_7_reason = "Defender's perimeter defense prevented the drive";
			//cout << "The defender's perimeter D prevented the drive and forced a turnover" << endl;

		playResults.pr_4_range = "B: " + to_string(newBabdulishness) + " S: " + to_string(newSkill);
		playResults.pr_5_roll = to_string(success);

		if (success > newBabdulishness && success < newSkill && SPEED >= ((defender.getPerimeterD() * defender.sliders.slider_perimeterD) - (numPasses + (numDrives * 2))))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string driveChance(Babdul& defender, int numPasses, int numDrives)
	{
		int newBabdulishness = (((BABDULISHNESS * sliders.slider_babdulishness) / 3) / (numPasses + 1));
		int newSkill = ((SPEED * sliders.slider_speed) + (numPasses * 5) + (numDrives * 5));

		if (build == "Slasher      ")
		{
			newSkill += 3;
			newBabdulishness -= 3;
		}

		if (build == "All_Around   ")
		{
			newSkill += 1;
			newBabdulishness -= 1;
		}

		int percentChance = newSkill - newBabdulishness - 1;
		if (percentChance < 0) { percentChance = 0; }
		else if (percentChance > 100) { percentChance = 100; }

		if (SPEED < ((defender.getPerimeterD() * defender.sliders.slider_perimeterD) - (numPasses + (numDrives * 2))))
			percentChance = 0;

		string buffer = "";
		if (percentChance < 10) { buffer = "  "; }
		else if (percentChance < 100) { buffer = " "; }
		return buffer + to_string(percentChance) + "%";
	}

	bool backDown(Babdul& defender)
	{
		int success = rand() % 100 + 1;

		int newBabdulishness = (BABDULISHNESS * sliders.slider_babdulishness);
		int newSkill = (STRENGTH * sliders.slider_strength);

		if (build == "Paint_Scorer ")
		{
			newSkill += 3;
			newBabdulishness -= 3;
		}

		if (build == "All_Around   ")
		{
			newSkill += 1;
			newBabdulishness -= 1;
		}

		int variation = rand() % 10 - 5;
		int defenderInteriorD = (defender.getInteriorD() * defender.sliders.slider_interiorD) + variation - 10;

		//cout << endl << "B:" << newBabdulishness << " S: " << newSkill << endl << "Chance: " << success << ". ";
		if (success < newBabdulishness)
			playResults.pr_7_reason = "Too much babdulishness";
			//cout << "Too much Babdulishness" << endl;
		else if (success > newSkill)
			playResults.pr_7_reason = "Not enough strength";
			//cout << "Insufficient strength" << endl;
		else if (STRENGTH < defenderInteriorD)
			playResults.pr_7_reason = "Defender's interior defense prevented the back down attempt";
			//cout << "The defender's interior D prevented the back down attempt and forced a turnover" << endl;

		playResults.pr_4_range = "B: " + to_string(newBabdulishness) + " S: " + to_string(newSkill);
		playResults.pr_5_roll = to_string(success);

		if (success > newBabdulishness && success < newSkill && (STRENGTH * sliders.slider_strength) > defenderInteriorD)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string backDownChance(Babdul& defender)
	{
		int newBabdulishness = (BABDULISHNESS * sliders.slider_babdulishness);
		int newSkill = (STRENGTH * sliders.slider_strength);

		if (build == "Paint_Scorer ")
		{
			newSkill += 3;
			newBabdulishness -= 3;
		}

		if (build == "All_Around   ")
		{
			newSkill += 1;
			newBabdulishness -= 1;
		}

		int variation = rand() % 10 - 5;
		int defenderInteriorD = (defender.getInteriorD() * defender.sliders.slider_interiorD) + variation - 10;

		int percentChance = newSkill - newBabdulishness - 1;
		if (percentChance < 0) { percentChance = 0; }
		else if (percentChance > 100) { percentChance = 100; }

		if ((STRENGTH * sliders.slider_strength) <= defenderInteriorD)
			percentChance = 0;

		string buffer = "";
		if (percentChance < 10) { buffer = "  "; }
		else if (percentChance < 100) { buffer = " "; }
		return buffer + to_string(percentChance) + "%";
	}
	
	bool attemptBlock()
	{
		int success = rand() % 100 + 1;
		
		int newSkill = ((BLOCK * sliders.slider_block) - 25);
		int newBabdulishness = (BABDULISHNESS * sliders.slider_babdulishness);

		if (build == "Shot_Blocker ")
		{
			newSkill += 3;
			newBabdulishness -= 3;
		}

		if (build == "All_Around   ")
		{
			newSkill += 1;
			newBabdulishness -= 1;
		}

		if (success > newBabdulishness && success < newSkill)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool attemptDefRebound()
	{
		int success = rand() % 100 + 1;

		int newSkill = ((DEF_REB * sliders.slider_defRebound) - 25);
		int newBabdulishness = (BABDULISHNESS * sliders.slider_babdulishness);

		if (build == "Rebounder    ")
		{
			newSkill += 3;
			newBabdulishness -= 3;
		}

		if (build == "All_Around   ")
		{
			newSkill += 1;
			newBabdulishness -= 1;
		}

		if (success > newBabdulishness && success < newSkill)
		{
			logger.debug(babName + " (" + to_string(getDefRebound()) + " DR) def rebound attempt: SUCCESS");
			return true;
		}
		else
		{
			logger.debug(babName + " (" + to_string(getDefRebound()) + " DR) def rebound attempt: FAILED");
			return false;
		}
	}

	bool attemptOffRebound()
	{
		int success = rand() % 100 + 1;

		int newSkill = ((OFF_REB * sliders.slider_offRebound) - 25);
		int newBabdulishness = (BABDULISHNESS * sliders.slider_babdulishness);

		if (build == "Rebounder    ")
		{
			newSkill += 3;
			newBabdulishness -= 3;
		}

		if (build == "All_Around   ")
		{
			newSkill += 1;
			newBabdulishness -= 1;
		}

		if (success > newBabdulishness && success < newSkill)
		{
			logger.debug(babName + " (" + to_string(getOffRebound()) + " OR) off rebound attempt: SUCCESS");
			return true;
		}
		else
		{
			logger.debug(babName + " (" + to_string(getOffRebound()) + " OR) off rebound attempt: FAILED");
			return false;
		}
	}
};

bool compareBabName(const Babdul& b1, const Babdul& b2)
{
	return b1.babName < b2.babName;
}

bool compareAge(const Babdul& b1, const Babdul& b2)
{
	return b1.age < b2.age;
}

bool compareWeight(const Babdul& b1, const Babdul& b2)
{
	return b1.weight < b2.weight;
}

bool compareHeight(const Babdul& b1, const Babdul& b2)
{
	if (b1.height.first == b2.height.first)
		return b1.height.second > b2.height.second;
	else
		return b1.height.first > b2.height.first;
}

bool comparePosition(const Babdul& b1, const Babdul& b2)
{
	return b1.position < b2.position;
}

bool compareTier(const Babdul& b1, const Babdul& b2)
{
	return b1.tier < b2.tier;
}

bool compareBuild(const Babdul& b1, const Babdul& b2)
{
	return b1.build < b2.build;
}

bool compareBabdulishness(const Babdul& b1, const Babdul& b2)
{
	return b1.BABDULISHNESS < b2.BABDULISHNESS;
}

bool compareOverall(const Babdul& b1, const Babdul& b2)
{
	return b1.overall > b2.overall;
}

bool comparePoints(const Babdul& b1, const Babdul& b2)
{
	return b1.points > b2.points;
}

bool compareBlocks(const Babdul& b1, const Babdul& b2)
{
	return b1.blocks > b2.blocks;
}

bool compareAssists(const Babdul& b1, const Babdul& b2)
{
	return b1.assists > b2.assists;
}

bool compareShotClose(const Babdul& b1, const Babdul& b2)
{
	return b1.SHOT_CLOSE > b2.SHOT_CLOSE;
}

bool compareShotMid(const Babdul& b1, const Babdul& b2)
{
	return b1.SHOT_MID > b2.SHOT_MID;
}

bool compareShot3(const Babdul& b1, const Babdul& b2)
{
	return b1.SHOT_3 > b2.SHOT_3;
}

bool comparePassAcc(const Babdul& b1, const Babdul& b2)
{
	return b1.PASS_ACC > b2.PASS_ACC;
}

bool comparePerimeterD(const Babdul& b1, const Babdul& b2)
{
	return b1.PER_D > b2.PER_D;
}

bool compareInteriorD(const Babdul& b1, const Babdul& b2)
{
	return b1.INT_D > b2.INT_D;
}

bool compareShotContest(const Babdul& b1, const Babdul& b2)
{
	return b1.SHOT_CONTEST > b2.SHOT_CONTEST;
}

bool compareBlock(const Babdul& b1, const Babdul& b2)
{
	return b1.BLOCK > b2.BLOCK;
}

bool compareDefRebound(const Babdul& b1, const Babdul& b2)
{
	return b1.DEF_REB > b2.DEF_REB;
}

bool compareOffRebound(const Babdul& b1, const Babdul& b2)
{
	return b1.OFF_REB > b2.OFF_REB;
}

bool compareSpeed(const Babdul& b1, const Babdul& b2)
{
	return b1.SPEED > b2.SPEED;
}

bool compareStrength(const Babdul& b1, const Babdul& b2)
{
	return b1.STRENGTH > b2.STRENGTH;
}