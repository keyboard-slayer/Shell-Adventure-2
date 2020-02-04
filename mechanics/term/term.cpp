#include "term.h"

Term::Term(int width, int height)
{
	this->surface = Surface(width, height);
	this->surface.fill(0, 0, 0);
	
	this->font = Font("./fonts/monospace.ttf", 22);
	this->font.render("> Hey, this is a demo of Shell Adventure 2");
	this->surface.blit(this->font.get_surface(), 0, 0);
}	

Surface Term::get_surface(void)
{
	return this->surface;
}
