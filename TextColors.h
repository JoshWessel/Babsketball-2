const int BLUE = 1;
const int GREEN = 2;
const int CYAN = 3;
const int RED = 4;
const int PURPLE = 5;
const int DARK_YELLOW = 6;
const int WHITE = 7;
const int DEFAULT = 7;
const int GRAY = 8;
const int BRIGHT_BLUE = 9;
const int BRIGHT_GREEN = 10;
const int BRIGHT_CYAN = 11;
const int BRIGHT_RED = 12;
const int PINK = 13;
const int YELLOW = 14;
const int BRIGHT_WHITE = 15;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void setDefaultTextColor()
{
	SetConsoleTextAttribute(h, DEFAULT);
}

void setTextColor(int textColor)
{
	SetConsoleTextAttribute(h, textColor);
}