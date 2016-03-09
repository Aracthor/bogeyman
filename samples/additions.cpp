#include "bogeyman/assert.hpp"
#include "bogeyman/Logger.hpp"

#include <iostream>

int	main()
{
    BOGEYMAN_ASSERT((2 + 2) == 4);
    BOGEYMAN_ASSERT((2 + 2) == 5);
    BOGEYMAN_ASSERT_FALSE((2 + 2) == 4);
    BOGEYMAN_ASSERT_FALSE((2 + 2) == 5);


    BOGEYMAN_ASSERT(false);
    BOGEYMAN_ASSERT(true);

    std::cout << "Logged errors: " << bogeyman::Logger::getInstance().getErrorNumber() << std::endl;
    
    return 0;
}
