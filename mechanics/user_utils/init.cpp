#include "init.h"

void create_profile(char* rc_path,Term* term, Screen* display)
{
	term->type("Hey, I see it's the first time that you're joining the adventure !", display);
	term->echo("");
	term->type("Ok, give me your name !", display);
	term->echo("");
	term->echo("Username: ");
}	

