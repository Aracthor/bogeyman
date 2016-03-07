#ifndef BOGEYMAN_LOGGER_HPP_
# define BOGEYMAN_LOGGER_HPP_

# include <fstream>

# define BOGEYMAN_DEFAULT_LOG_FILE	"bogeyman.log"

namespace bogeyman
{

class	Logger
{
public:
    static Logger&	getInstance();

private:
    static Logger	s_instance;


public:
    inline void		setLogFileName(const char* fileName);
    inline unsigned int	getErrorNumber() const;
    inline bool		logFileIsOk() const;


// Those functions are called by internals macros, do NOT call them directly.
public:
    inline void	logError();
    void	logErrorLine(const char* file, unsigned int line);


private:
    Logger();
    ~Logger();

private:
    void		initialize();
    bool		createLogFile();

private:
    inline bool		isInitialized() const;

private:
    std::ofstream	m_logFile;
    const char*		m_fileName;
    unsigned int        m_errorNumber;
    bool	        m_initialized;
};

}


# include "Logger.ipp"

#endif // !BOGEYMAN_LOGGER_HPP_
