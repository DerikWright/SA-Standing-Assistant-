//SetUp.cpp
#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <string>
#include "SetUp.h" // header file used to store function declarations

using namespace std; // standard namespace

void setTimer(int* hour, int* min, int* sec) // take the memory of the parameters, so we can modify the sent parameters without writing multiple functions
{
	cout << "What is the desired length of time in which you would like to be seated?\n\n\n"
		<< "Hours: ";
	cin >> *hour; //set the number stored in hours memory 
	cout << "Minutes: ";
	cin >> *min; //set the number stored in the minutes memory
	cout << "Seconds: ";
	cin >> *sec; //set the number stored in the seconds memory
}

string setName()
{
	string username; // declare username as a variable
	cout << "Hello User!\n I am your personal health assistant. I am here to improve your overall health by reminding you to get up, and get active."
		<< "What is your name?\n"; // simple cout statements
	cin >> username;
	return (username); // return username
}
void StartTimer(string username, int hour, int min, int sec)
{
	int htos = hour * 3600, mtos = min * 60, total = htos + mtos + sec; // tos is total of seconds, so hours total seconds etc.. this is used to run our for loop
	for (int i = total; i > 0; i--) // for loop, it will run as long as the programs total seconds is not 0
	{
		cout << "\n\n" << username << " Time before you should get up: "; // inform user of their name and tells them how long before they should stand up
		sec--; // reduce seconds by 1
		cout << hour << ":" << min << ":" << sec; // print the remaining time on the timer to the user
		Sleep(1000); // sleep will just pause the program, 1000 is the time conversion for roughly 1 second
		if (hour > 0 && min == 0 && sec == 0) // check if hours needs to be reduced, by checking if we have more than 1 hour while our minutes and seconds are both 0
		{
			hour--; // reduce hours by 1
			min += 59; // reset minutes to 59
			sec += 60; // reset seconds to 60
		}
		else if (hour >= 0 && min >= 1 && sec == 0) // check if minutes needs to be reduced
		{
			min--; // reduce minutes by 1
			sec += 60; // reset seconds to 60
		}
		system("cls"); // clear screen for formatting, and readability
	}
}