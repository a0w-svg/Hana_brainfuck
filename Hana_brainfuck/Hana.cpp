#include "Hana.h"

Hana::Hana(char code_br[])
{
	br_program = code_br;
	data_p = data;
}

void Hana::move_p_left()
{	
	--data_p;
}

void Hana::move_p_right()
{
	++data_p;
}

void Hana::br_inc()
{
	if(data_p != NULL)
		(*data_p)++;
}

void Hana::br_dec()
{
	if(data_p != NULL)
		(*data_p)--;
}

void Hana::br_puts()
{
	std::cout << *data_p;
}

void Hana::br_gets()
{
	std::cin >> *data_p;
}

void Hana::br_open_br()
{
	int bracket_l = 1;
	if (*data_p == '\0')
	{
		do
		{
			br_program++;
			if (*br_program == '[')
				bracket_l++;
			else if (*br_program == ']')
				bracket_l--;
		} while (bracket_l != 0);
	}
}

void Hana::br_close_br()
{
	int bracket_p = 0;
	do{
		if (*br_program == '[')
			bracket_p++;
		else if (*br_program == ']')
			bracket_p--;
		br_program--;
	} while (bracket_p != 0);
}

void Hana::validation()
{
	while (*br_program)
	{
		switch (*br_program)
		{
		case '>':
			move_p_right();
			break;
		case '<':
			move_p_left();
			break;
		case '+':
			br_inc();
			break;
		case '-':
			br_dec();
			break;
		case '.':
			br_puts();
			break;
		case ',':
			br_gets();
			break;
		case '[':
			br_open_br();
			break;
		case ']':
			br_close_br();
			break;
		}
		br_program++;
	}
}
