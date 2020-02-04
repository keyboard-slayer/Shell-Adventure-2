#include <loader.h>

#include "mechanics/term/term.h"

int main(int argc, char* argv[])
{
	Screen root(800, 600, "Shell Adventure");
	root.fill(0, 0, 0);
	Term term(800, 600);

	root.blit(term.get_surface(), 0, 0);
	root.update();
	SDL_Delay(2000);
}
