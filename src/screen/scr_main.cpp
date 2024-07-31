// Exercising the Screen class
#include "screen.h"
#include <iostream>

using namespace std;

int main()
{
	auto myScreen = Screen{6,6}; // this screen prints K
	myScreen.clear(' ');
	//myScreen.forward();
	//myScreen.set('*');
	for (int i = 0; i < 5; i++)
	{
		myScreen.set('*');
		myScreen.down();
		/* code */
	}

	myScreen.move(6,1);
	myScreen.set('*');
	
	myScreen.move(1,4);
	myScreen.set('*');

	myScreen.move(2,3);
	myScreen.set('*');

	myScreen.move(3,2);
	myScreen.set('*');

	myScreen.move(4,3);
	myScreen.set('*');

	myScreen.move(5,5);
	myScreen.set('*');
	
	myScreen.move(6,6);
	myScreen.set('*');

	myScreen.display();
	cout << endl;

//-------------------------------------Exercise 4.6 Square Drawing test--------------------------------

	auto myScreen2 = Screen{8,8}; // second testing screen
	cout << endl;

	// test with an unclear 8x8 screen
	myScreen2.drawSquare(5,5,4);
	myScreen2.display();
	
	cout << endl;
	
	// test with clear screen 16x16 increased size, for length 8 square
	myScreen2.reSize(20,20);
	myScreen2.clear(' ');
	myScreen2.drawSquare(8,5,8);
	myScreen2.display();

	// error checking with starting coordinates that force square out of bounds 20x20
	cout << endl;
	 myScreen2.reSize(20,20);
	 myScreen2.clear(' ');
	 myScreen2.drawSquare(16,1,12);
	 myScreen2.display();

	return 0;
}

