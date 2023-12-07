// GuessTheNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main()
{
srand(static_cast<unsigned int>(time(0)));
int secretNumber = rand() % 100 + 1;
int guess = 0;
int tries = 0;
cout << "\tWelcome to Guess My Number\n\n";
cout << "I Have Picked A Number"<<endl;
cout << "Can You Guess What It Is?"<<endl;

while (guess!=secretNumber)
{
	cout << "Enter a guess: ";
	cin >> guess;
	if (guess > secretNumber)
	{
		cout << "Too High!\n\n";
	}
	else if (guess < secretNumber)
	{
		cout << "Too Low!\n\n";
	}
	else
	{
		cout << "\nThat's It! You Got It In " << tries << " guesses!\n";
	}
	tries++;

}
return 0;

}

