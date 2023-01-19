//A snake game with limited functionalities.


#include<iostream>
#include <conio.h>
#include<Windows.h>
#include <time.h>
using namespace std;



//initializing variables for the program. They are    all having Global scope


bool gameState;	//for the game being played or not(T or F)

#define width 30
#define height 30	//for the purpose of screenn size both of these are used



int positionX, positionY, Speed = 1;	//snake position along x-axis and along y-axis and speed
int targetX, targetY;		//position of the food for snake to eat


int score = 0;		//keeping a tally of scores

string snake = "0";

enum direction { STOP = 0, LEFT, UP, RIGHT, DOWN };	//enum used to describe integer values by some variables. 
direction dir; //this 



void setup()		//The structure of the game to start to function properly
{
	gameState = true;	//game is running

	srand(time(0));									//to generate random number for random positions each time

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 20;                   // Width of each character in the font
	cfi.dwFontSize.Y = 24;                  // Height of each character in the font
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Arial Black");    // Name of the font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	//for snake placement on screen
	positionX = rand() % width; //where our snake will be placed along x-cordinates
	positionY = rand() % height; //where our snake will be along y-cordinates
	//for food placement on screen
	targetX = rand() % width; //along x-cordinates
	targetY = rand() % height; //along y-cordinates

	//if food placement is equal to snake position
	if (targetX == positionX && targetY == positionY)
	{
		//until the values of the co-ordinates do not change
		while (targetX == positionX && targetY == positionY)
		{
			targetX = width % rand(); //along x-cordinates
			targetY = height % rand(); //along y-cordinates
		}
	}
	score = 0; //the score at the start of the game


}


void display_window()	//How and what should be shown on "screen"	on xsetting up the game
{
	system("cls"); //

	//top border
	for (int i = 0; i <= width; i++)
	{
		cout << "*";
	}
	cout << endl;

	//body
	for (int i = 0; i <= width; i++)
	{

		for (int j = 0; j <= height; j++)

		{
			//cout << "*";
			if (j == 0 || j == width - 1) //vertical boundary
			{
				cout << "*";
			}


			else	if (i == positionX && j == positionY) //snake position  the program
			{

				cout << snake;

			}


			else if (i == targetX && j == targetY)
			{
				cout << "%";
			}

			else 		//empty space in between 
			{
				cout << " ";
			}


		}
		cout << endl;
	}

	//bottom border
	for (int i = 0; i <= width; i++)
	{
		cout << "*";
	}
	cout << "Score = " << score;
}

void user_inputs()		//To comprehend the user interaction with our game and
{
	if (_kbhit())		//whenever a key is pressed on the keyboard, it checks it and returns its value
	{
		switch (_getch())  //this is used along the kbhit function to get the input from keyboar key
		{

		case 'a':					//to move left
		{
			if (dir != RIGHT)			//snake can not move to right while moing left

				dir = LEFT;

			break;
		}
		case 's':					//to move right
		{
			if (dir != LEFT)		//snake can not move to left while moving right

				dir = RIGHT;

			break;
		}
		case 'd':
		{
			if (dir != DOWN)		//snake can not move up while moving down

				dir = UP;

			break;
		}
		case 'w':			//to move down

		{
			if (dir != UP)			//snake can not move to right while moing 

				dir = DOWN;

			break;
		}



		}

	}


}




void game_function() {	 //This will respond to the user_interaction



	if (dir == RIGHT)
	{

		positionX += Speed;


	}
	else if (dir == LEFT)
	{

		positionX -= Speed;

	}
	else if (dir == UP)
	{

		positionY -= Speed;

	}
	else if (dir == DOWN)
	{

		positionY += Speed;

	}

	if (positionX == targetX && positionY == targetY)			//score increase
	{
		score++;
		snake += '0';

	}

	if (positionX == targetX && positionY == targetY)
	{
		targetX = rand() % width; //along x-cordinates
		targetY = rand() % height; //along y-cordinates

	}





	//snake collides with the borders

	if (positionX < 0 || positionX == width || positionY ==0 || positionY == height-1)
	{

		gameState = false;							//game will stop
		cout << endl << "\t\tGAME OVER." << endl;
		//	cout << "Your Score = " << score << endl;
		cout << endl << endl;


	}





}






int main()
{


	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	for (int i = 0; i < 100000; i++)
	{
		system("color 4e ");


		system("cls");

		//to make the font size larger a struct CONSOLE_FONT_INFOEX is used which has all the font and styles and can help to adjust it

		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 40;                   // Width of each character in the font
		cfi.dwFontSize.Y = 60;                  // Height of each character in the font
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		wcscpy_s(cfi.FaceName, L"Arial Black");    // Name of the font
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

		cout << "\t\tSNAKE GAME" << endl;
		cout << "Press any key to start" << endl;

		if (_kbhit())					//to start the game
		{
			goto started;
		}

		Sleep(1000);					//delays the execution by 1000 mili seconds

	}

started:		//game will be started 
	struct data {					//user data
		string name;
		double rollno;
	};
	struct data d;

	cout << "Enter name = ";
	cin >> d.name;
	cout << "Enter roll no.";
	cin >> d.rollno;

	setup();
	while (gameState == true)				//game begins
	{

		display_window();
		user_inputs();
		game_function();

		Sleep(35);



	}
	if (positionX ==0 || positionX == width || positionY == 0 || positionY == height-1)
	{
		cout << d.name << " " << d.rollno << " your score was " << score;
	}

	return 0;
}
