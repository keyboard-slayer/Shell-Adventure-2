#ifndef ADV_TERM_H
#define ADV_TERM_H

#include <loader.h>
//#include "../utils/user_data.h"

class Term 
{
	private:
		Surface surface;
		Font font;
	
	public:
		Term(int width, int height);
		Surface get_surface(void);
};

#endif
