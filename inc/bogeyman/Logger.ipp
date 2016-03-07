namespace bogeyman
{


Logger&
Logger::getInstance()
{
    if (!s_instance.isInitialized())
    {
	s_instance.initialize();
    }
    return s_instance;
}

Logger
Logger::s_instance;


Logger::Logger()
{
}

Logger::~Logger()
{
}


void
Logger::setLogFileName(const char* fileName)
{
    m_fileName = fileName;
}

unsigned int
Logger::getErrorNumber() const
{
    return m_errorNumber;
}

bool
Logger::logFileIsOk() const
{
    return m_logFile.good();
}


void
Logger::logError()
{
    m_errorNumber++;
}

void
Logger::logErrorLine(const char* file, unsigned int line)
{
    if (m_logFile.is_open() || this->createLogFile())
    {
	m_logFile << "Assertion error: " << file << " line " << line << std::endl;
    }
}


void
Logger::initialize()
{
    m_fileName = BOGEYMAN_DEFAULT_LOG_FILE;
}

bool
Logger::createLogFile()
{
    m_logFile.open(m_fileName);
    return m_logFile.is_open();
}


bool
Logger::isInitialized() const
{
    return m_initialized;
}


}
