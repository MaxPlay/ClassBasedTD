#include <iostream>
#include <iomanip>
#include <fstream>
#include "Debug.h"

using namespace CBTD;
using namespace Core;

Debug* Debug::s_Instance = nullptr;

void Debug::PrintToConsole(DebugMessage type, const std::string & text)
{
    std::ostringstream fileOut;

    if (m_UseColor)
        SetConsoleColor(type);

    if (m_UseTimestamp)
    {
        std::ostringstream oss;
        GetCurrentTimestamp(oss, "%T");
        std::cout << oss.str() << ' ';
        if (m_UseLogfile)
            fileOut << oss.str() << ' ';
    }

    if (m_UseFlavor)
    {
        std::cout << GetFlavor(type);
        if (m_UseLogfile)
            fileOut << GetFlavor(type);
    }

    std::cout << text << std::endl;
    if (m_UseLogfile)
    {
        fileOut << text << std::endl;
        LogToFile(fileOut);
    }
}

void Debug::SetConsoleColor(DebugMessage type)
{
    switch (type)
    {
    case Debug::DebugMessage::Warning:
        SetConsoleTextAttribute(m_ConsoleHandle, COLOR_WARNING);
        break;
    case Debug::DebugMessage::Error:
        SetConsoleTextAttribute(m_ConsoleHandle, COLOR_ERROR);
        break;
    case Debug::DebugMessage::Critical:
        SetConsoleTextAttribute(m_ConsoleHandle, COLOR_CRITICAL);
        break;
    default:
        SetConsoleTextAttribute(m_ConsoleHandle, COLOR_DEFAULT);
        break;
    }
}

std::ostringstream& Debug::GetCurrentTimestamp(std::ostringstream & stream, const char* pattern)
{
    time_t time = std::time(nullptr);
    tm localTime;
    localtime_s(&localTime, &time);
    stream << std::put_time(&localTime, pattern);
    return stream;
}

const char* Debug::GetFlavor(DebugMessage type)
{
    switch (type)
    {
    case DebugMessage::Warning:
        return FLAVOR_WARNING;
    case DebugMessage::Error:
        return FLAVOR_ERROR;
    case DebugMessage::Critical:
        return FLAVOR_CRITICAL;
    default:
        return FLAVOR_DEFAULT;
    }
}

void Debug::LogToFile(std::ostringstream & stream)
{
    std::ofstream file;
    file.open(LOG_FILE_NAME, std::ios_base::app);
    file << stream.str();
}

Debug::Debug(bool color, bool flavor, bool logfile, bool timestamp) : m_UseColor(color), m_UseFlavor(flavor), m_UseLogfile(logfile), m_UseTimestamp(timestamp)
{
    m_ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Debug::Init(bool color, bool flavor, bool logfile, bool timestamp)
{
    if (s_Instance)
        return;

    s_Instance = new Debug(color, flavor, logfile, timestamp);
    std::ostringstream oss;
    oss << "Debugger initialized [";
    s_Instance->GetCurrentTimestamp(oss, "%F %T");
    oss << "]";
    SLog(oss.str());
}

bool Debug::GetUseColor() const
{
    return m_UseColor;
}

bool Debug::GetUseTimestamp() const
{
    return m_UseTimestamp;
}

bool Debug::GetUseFlavor() const
{
    return m_UseFlavor;
}

bool Debug::GetUseLogfile() const
{
    return m_UseLogfile;
}

void Debug::UseColor(bool useColor)
{
    m_UseColor = useColor;
}

void Debug::UseTimestamp(bool useTimestamp)
{
    m_UseTimestamp = useTimestamp;
}

void Debug::UseFlavor(bool useFlavor)
{
    m_UseFlavor = useFlavor;
}

void Debug::UseLogfile(bool useLogfile)
{
    m_UseLogfile = useLogfile;
}

void Debug::Log(const std::string& text)
{
    PrintToConsole(DebugMessage::Default, text);
}

void Debug::LogCritical(const std::string& text)
{
    PrintToConsole(DebugMessage::Critical, text);
}

void Debug::LogError(const std::string& text)
{
    PrintToConsole(DebugMessage::Error, text);
}

void Debug::LogWarning(const std::string& text)
{
    PrintToConsole(DebugMessage::Warning, text);
}
