#ifndef BOGEYMAN_ASSERT_HPP_
# define BOGEYMAN_ASSERT_HPP_

# ifdef NDEBUG

#  include "bogeyman/internal/print_error_line.hpp"
#  include "bogeyman/internal/action_on_failure.hpp"

#  define	BOGEYMAN_ASSERT(expr)	\
    if (!(expr))			\
    {					\
	BOGEYMAN_PRINT_ERROR_LINE();	\
	BOGEYMAN_ACTION_ON_FAILURE();	\
    }
#  define	BOGEYMAN_ASSERT_FALSE(expr)	BOGEYMAN_ASSERT(!(expr))

# else // !NDEBUG
#  define	BOGEYMAN_ASSERT(expr)
#  define	BOGEYMAN_ASSERT_FALSE(expr)

# endif // !NDEBUG

#endif // !BOGEYMAN_ASSERT_HPP_
