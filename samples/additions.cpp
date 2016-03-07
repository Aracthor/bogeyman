#define _BOGEYMAN_PRINT_ERROR_LINE	1
#define _BOGEYMAN_ACTION_ON_FAILURE	2
#include "bogeyman/assert.hpp"

#include <iostream>

int	main()
{
    BOGEYMAN_ASSERT((2 + 2) == 5);

    bogeyman::Logger::getInstance().setLogFileName("additions.log");
    std::cout << bogeyman::Logger::getInstance().getErrorNumber() << std::endl;

    return 0;
}
