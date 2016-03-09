// Do NEVER include directly this file, it is already included by assert.hpp!

#ifndef _BOGEYMAN_ACTION_ON_FAILURE
# define _BOGEYMAN_ACTION_ON_FAILURE	BOGEYMAN_DEFAULT_ACTION_ON_FAILURE
#endif // !_BOGEYMAN_ACTION_ON_FAILURE

#if _BOGEYMAN_ACTION_ON_FAILURE == BOGEYMAN_ABORT_ON_FAILURE
# include <cstdlib>
# define BOGEYMAN_ACTION_ON_FAILURE()	abort()
#elif _BOGEYMAN_ACTION_ON_FAILURE == BOGEYMAN_EXIT_ON_FAILURE
# include <cstdlib>
# define BOGEYMAN_FAILURE_RETURN_VALUE	2
# define BOGEYMAN_ACTION_ON_FAILURE()	exit(BOGEYMAN_FAILURE_RETURN_VALUE)
#elif _BOGEYMAN_ACTION_ON_FAILURE == BOGEYMAN_LOG_ON_FAILURE
# include "bogeyman/Logger.hpp"
# define BOGEYMAN_ACTION_ON_FAILURE()	bogeyman::Logger::getInstance().logError()
#elif _BOGEYMAN_ACTION_ON_FAILURE == BOGEYMAN_DO_NOTHING_ON_FAILURE
# define BOGEYMAN_ACTION_ON_FAILURE()
#else // !_BOGEYMAN_ABORT_ON_FAILURE
# error "Unrecognized value in parameter macro _BOGEYMAN_ACTION_ON_FAILURE."
#endif // !_BOGEYMAN_ABORT_ON_FAILURE
