#include "term.h"

#include <cstring>

Term::Term(int width, int height)
{
	this->surface = Surface(width, height);
	this->surface.fill(0, 0, 0);
	
	this->font = Font("./fonts/monospace.ttf", 22);

	this->cursorX = 0;
	this->cursorY = 0; 
}	

Surface Term::get_surface(void)
{
	return this->surface;
}

void Term::echo(const char* txt)
{
	if(strlen(txt) == 0)
		txt = " ";

	this->font.render(txt);
	this->surface.blit(this->font.get_surface(), this->cursorX, this->cursorY);
	this->cursorY += this->font.get_surface().get_height();
}


void Term::type(char* txt, Screen* display)
{
	std::string key;
	int cursor_position = this->cursorY;
	int saved_cursor;
	for(int i = 0; i < strlen(txt); i++)
	{
		key = std::string(1, txt[i]);
		this->echo(key.c_str());
		display->blit(this->surface, 0, 0);
		display->update();
		saved_cursor = this->cursorY;
		this->cursorY = cursor_position;
		this->cursorX += this->font.get_surface().get_width();
		SDL_Delay(50);
	}

	this->cursorY = saved_cursor;
	this->cursorX = 0;
}

void Term::clear(void)
{
	this->surface.fill(0, 0, 0);
	this->cursorY = 0;
	this->cursorX = 0;
}
