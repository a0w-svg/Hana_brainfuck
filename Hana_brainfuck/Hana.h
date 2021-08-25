#pragma once
#include <iostream>
class Hana
{
private:
	static const int length = 30000;
	char data[length] = { 0 };
	char* data_p = nullptr;
	const char* br_program = nullptr;
	// Move the pointer to the left;
	void move_p_left();
	// Move the pointer to the right;
	void move_p_right();
	//Increment the memory cell under the pointer;
	void br_inc();
	// Decrement the memory cell under the pointer;
	void br_dec();
	// Output the character signified by the cell at the pointer;
	void br_puts();
	// Input a character and store it in the cell at the pointer;
	void br_gets();
	// Jump past the matching ] if the cell under the pointer is 0;
	void br_open_br();
	// Jump back to the matching [ if the cell under the pointer is non-zero;
	void br_close_br();
public:
	Hana(char code_br[]);
	void validation();
};

