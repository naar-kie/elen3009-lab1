#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>
using namespace std;

// The unsigned integral type which is used to store the number of
// characters in a string is nested within the string class, so it
// is accessed using "string::size_type".
// The range of string::size_type is guaranteed to be large enough to store the maximum
// *size* of any string that can be held by the string class as well as any index into
// the string.

enum class Direction{HOME, FORWARD, BACK, UP, DOWN, END};

class Screen {
public:
	// Screen's constructor
	Screen(string::size_type height, string::size_type width, char bkground = '#');

	// get the Screen's height
	string::size_type height() const { return height_; }
	// get the Screen's width
	string::size_type width() const { return width_; }

	// place the cursor at the top-left corner of the screen
	void home() { cursor_ = 0;  return; }
	// place the cursor at the bottom-right corner of the screen
	void end() { cursor_ = width_ * height_ - 1; return; }
	// move the cursor one position to the right
	void forward();
	// move the cursor one position to the left
	void back();
	// move the cursor up one row
	void up();
	// move the cursor down one row
	void down();
	// move the cursor to the specified row and column
	void move(string::size_type row, string::size_type col);
	// move the cursor in the specified direction (HOME, FORWARD, BACK, UP, DOWN, END)
	void move(Direction dir); // no, it's not a necessity for clients of Screen because there are other member functions to move the cursor in any direction

	// get the character at the cursor's current position
	char get() const { return _screen[cursor_]; }
	// get the character at the specified row and column
	char get(string::size_type row, string::size_type col);

	// write a character on the screen at the current cursor position
	void set( char ch );
	// write a string of characters on the screen starting at the current cursor position
	void set( const string& s );
	// overwrite the entire screen with the specified character
	void clear( char bkground = '#');

	// resize the screen
	void reSize( string::size_type height, string::size_type width, char bkground = '#');
	// display the screen
	void display() const;
	// check whether the specified co-ordinates lie within the screen
	bool checkRange(string::size_type row, string::size_type col) const;

	void drawSquare(string::size_type row, string::size_type col, const int length_);

private:
	// constants
	// 0 represents the top-left screen element
	const string::size_type TOP_LEFT = 0;

	// private member functions
	string::size_type remainingSpace() const;
	string::size_type row() const;

	// private data members
	// (using a trailing underscore is a naming convention for private data - not a requirement)

	// number of Screen rows
	string::size_type height_;
	// number of Screen columns
	string::size_type width_;
	// default position of the Screen's cursor, use in-class initilisation
	string::size_type cursor_ = TOP_LEFT;
	// the Screen's data is stored as a string
	string _screen;
};


#endif

//-------------------------------------Exercise 4.7--------------------------------
// Internal representation of the Screen class is needed in order to implement the drawSqaure() function because we need access to control private member variables such as cursor in order to draw the square.
// This function should not form part of the responsibilities of a Screen object, because the screen should only render the screen (separation of duties/ layers)

//-------------------------------------Exercise 4.8--------------------------------
// A more intuitive approach might be to implement a 2D array, as this makes the code structure easier to understand and allows new developers to modify the code more easily due to its widespread use across programming languages. This also makes the positioning system more intuitive.
// A class's interface should remain unchanged because altering it might disrupt the functionality of existing code. The interface and core functionality should stay consistent to ensure compatibility, while changing the implementation can lead to improved functionality, better performance, or a more straightforward framework to comprehend
