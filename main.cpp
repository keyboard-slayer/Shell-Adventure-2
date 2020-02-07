#include <loader.h>
#include <unistd.h>

#include <cstdlib>
#include <cstdio>
#include <tuple>

#include "mechanics/user_utils/init.h"
#include "mechanics/term/term.h"

std::tuple<bool, char*> check_user_registration(void)
{
	char* HOMEPATH = secure_getenv("HOME");
	char* path = (char* )malloc(sizeof(char) * (strlen(HOMEPATH) + 7));

	sprintf(path, "%s/.advrc", HOMEPATH);
	
	return std::make_tuple(access(path, F_OK) != 0, path);
}


int main(int argc, char* argv[])
{
	Screen root(800, 600, "Shell Adventure");
	Event event;

	Term term(800, 600);
	
	std::tuple<bool, char*> rc_data = check_user_registration();
	
	if(std::get<0>(rc_data)) {
		create_profile(std::get<1>(rc_data), &term, &root);
	}	

	root.blit(term.get_surface(), 0, 0);
	root.update();

	SDL_Delay(2000);
	term.clear();
	term.type("Shell Adventure 2.0 !", &root);
	term.type("Technical demo", &root);
	SDL_Delay(2000);
}
