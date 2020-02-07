#ifndef ADV_TERM_H
#define ADV_TERM_H

#include <loader.h>
//#include "../user_utils/init.h"

class Term 
{
	private:
		Surface surface;
		Font font;
		int cursorX;
		int cursorY;	
	public:
		Term(int width, int height);
		Surface get_surface(void);
		void echo(const char* txt);
		void type(char* txt, Screen* display);
		void clear(void);
};

#endif
