#include "screen.h"

// 1. in Private, "const string::size_type TOP_LEFT = 0" - const before a variable: defines constant value that cannot be changed after initialization

// Screen's constructor
Screen::Screen(string::size_type height, string::size_type width, char bkground):
	height_{height},// initialises height_ with height
	width_{width},  // initialises width_ with width
	_screen(height * width, bkground)	// size of _screen is height * width
										// all positions initialized with
										// character value of bkground
{ /* all the work is done in the member initialization list */ }

void Screen::forward()
{   // advance cursor_ one screen element
	++cursor_;

	// wrap around if the cursor_ is at the end of the screen
	if ( cursor_ == _screen.size()) home();

	return;
}

void Screen::back()
{   // move cursor_ backward one screen element
	// check for top of screen; wrap around
	if ( cursor_ == TOP_LEFT )
		end();
	else
		--cursor_;

	return;
}

void Screen::up()
{   // move cursor_ up one row of screen
	// can wrap around to bottom
	if ( row() == 1 ){ // at top?
		cursor_ = _screen.size() - width_ + cursor_;
	}
	else
		cursor_ -= width_;

	return;
}

void Screen::down()
{   // move cursor_ down one row of screen
	// can wrap around to top -> could implement to move left by adding +1 and TOP_LEFT
	if ( row() == height_){
		cursor_ = width_ - (_screen.size() - cursor_);
	}
	else
		cursor_ += width_;

	return;
}

void Screen::move( string::size_type row, string::size_type col )
{   // move cursor_ to absolute position
	// valid screen position?
	if ( checkRange( row, col ) )
	{
		// row location
		auto row_loc = (row-1) * width_;
		cursor_ = row_loc + col - 1;
	}

	return;
}

void Screen::move(Direction dir)
{
	Direction home_ = Direction::HOME;
	Direction forward_ = Direction::FORWARD;
	Direction back_ = Direction::BACK;
	Direction up_ = Direction::UP;
	Direction down_ = Direction::DOWN;
	Direction end_ = Direction::END;

	if (dir == home_) home();
	else if (dir == forward_) forward();
	else if (dir == back_) back();
	else if (dir == up_) up();
	else if (dir == down_) down();
	else if (dir == end_) end();
	else return;
}

char Screen::get( string::size_type row, string::size_type col )
{
	// position cursor_
	move( row, col );
	// the other get() member function
	return get();
}

void Screen::set( char ch )
{
	if ( ch == '\0' )
		cerr << "Screen::set warning: " << "null character (ignored).\n";
	else _screen[cursor_] = ch;

	return;
}

void Screen::set( const string& s ) // 2. const as a constant function parameter: defines which the variable is passed by reference and it's value cannot be changed by the function
{   // write string beginning at current cursor_ position
	auto space = remainingSpace();
	auto len = s.size();
	if ( space < len ) {
		cerr << "Screen::set - Truncating, "
			<< "space available: " << space
			<< ", string length: " << len
			<< endl;
		len = space;
	}

	_screen.replace( cursor_, len, s );
	cursor_ += len - 1;

	return;
}

void Screen::clear( char bkground )
{   // reset the cursor and clear the screen
	cursor_ = TOP_LEFT;
	// assign the string
	_screen.assign(
		// with size() characters
		_screen.size(),
		// of value bkground
		bkground
		);

	return;
}

void Screen::reSize( string::size_type h, string::size_type w, char bkground )
{   // can only *increase* a screen's size to height h and width w
	// remember the content of the screen
	string local{_screen};
	auto local_pos = TOP_LEFT;

	// replaces the string to which _screen refers
	_screen.assign(      // assign the string
		h * w,           // with h * w characters
		bkground         // of value bkground
		);

	// copy content of old screen into the new one
	for ( string::size_type ix = 0; ix < height_; ++ix )
	{ // for each row
		string::size_type offset = w * ix; // row position
		for ( string::size_type iy = 0; iy < width_; ++iy )
			// for each column, assign the old value
			_screen.at(offset + iy) = local[ local_pos++ ]; // .at() method returns a reference to the character at specified position on the screen
	}

	height_ = h;
	width_ = w;
	// cursor_ remains unchanged

	return;
}

void Screen::display() const
{
	for ( string::size_type ix = 0; ix < height_; ++ix )
	{ // for each row
		string::size_type offset = width_ * ix; // row position
		for ( string::size_type iy = 0; iy < width_; ++iy )
			// for each column, write element
			cout << _screen[ offset + iy ];
		cout << endl;
	}
	return;
}

bool Screen::checkRange( string::size_type row, string::size_type col ) const // 3. const after member functions: creates a read-only function that cannot modify the state of the object 
{   // validate coordinates
	if (row < 1 || row > height_ || col < 1 || col > width_)
	{
		cerr << "Screen coordinates ("<< row << ", " << col << " ) out of bounds.\n";
		return false;
	}
	return true;
}

string::size_type Screen::remainingSpace() const
{   // includes current position
	auto size = width_ * height_;
	return(size - cursor_);
}

string::size_type Screen::row() const
{   // return current row
	return (cursor_ + width_)/width_;
}

