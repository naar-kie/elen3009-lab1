// Exercising the Screen class
#include "screen.h"
#include <iostream>

using namespace std;

int main()
{
	auto myScreen = Screen{6,6};
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
	
	
	
	
	
	// myScreen.down();
	// myScreen.set('*');
	// myScreen.move(3,3);
	// myScreen.set("---");

	myScreen.display();
	cout << endl;

	// myScreen.reSize(16,16);
	// myScreen.display();
	// myScreen.clear(' ');

	// myScreen.move(7,7);
	// myScreen.set("BIG");
	// myScreen.move(8,5);
	// myScreen.set("SCREEN");
	// myScreen.display();

	return 0;
}

