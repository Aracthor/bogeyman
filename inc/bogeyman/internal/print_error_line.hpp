// Do NEVER include directly this file, it is already included by assert.hpp!

#define BOGEYMAN_PRINT_ERROR_LINE_TO_OUTPUT	0
#define BOGEYMAN_DONT_PRINT_ERROR_LINE		1

#define BOGEYMAN_DEFAULT_PRINT_ERROR_LINE	BOGEYMAN_PRINT_ERROR_LINE_TO_OUTPUT

#ifndef _BOGEYMAN_PRINT_ERROR_LINE_TO_OUTPUT
# define _BOGEYMAN_PRINT_ERROR_LINE_TO_OUTPUT	BOGEYMAN_DEFAULT_PRINT_ERROR_LINE
#endif // !_BOGEYMAN_PRINT_ERROR_LINE_TO_OUTPUT

#if _BOGEYMAN_PRINT_ERROR_LINE == BOGEYMAN_PRINT_ERROR_LINE_TO_OUTPUT
# include <iostream>
# define BOGEYMAN_PRINT_ERROR_LINE()	std::cerr << "Assertion error: " << __FILE__ << " line " << __LINE__ << std::endl
#elif _BOGEYMAN_PRINT_ERROR_LINE == BOGEYMAN_DONT_PRINT_ERROR_LINE
# define BOGEYMAN_PRINT_ERROR_LINE()
#else // !_BOGEYMAN_PRINT_ERROR_LINE_TO_OUTPUT
# define BOGEYMAN_PRINT_ERROR_LINE()
#endif // !_BOGEYMAN_PRINT_ERROR_LINE_TO_OUTPUT
