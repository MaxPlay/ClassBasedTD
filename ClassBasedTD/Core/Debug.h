#pragma once
#include <Windows.h>
#include <string>
#include <sstream>

namespace CBTD {
    namespace Core {
        class Debug
        {
        public:
            enum class DebugMessage
            {
                Default = 0,
                Warning,
                Error,
                Critical
            };

        private:
            Debug(bool color, bool flavor, bool logfile, bool timestamp);

            static Debug* s_Instance;
            HANDLE m_ConsoleHandle;
            bool m_UseColor;
            bool m_UseTimestamp;
            bool m_UseFlavor;
            bool m_UseLogfile;

            const char* FLAVOR_CRITICAL = "[CRITICAL] ";
            const char* FLAVOR_DEFAULT = "[LOG] ";
            const char* FLAVOR_ERROR = "[ERROR] ";
            const char* FLAVOR_WARNING = "[WARNING] ";

            const char* LOG_FILE_NAME = "debug.log";

            const int COLOR_CRITICAL = BACKGROUND_RED | BACKGROUND_INTENSITY;
            const int COLOR_DEFAULT = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
            const int COLOR_ERROR = FOREGROUND_RED | FOREGROUND_INTENSITY;
            const int COLOR_WARNING = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

            void PrintToConsole(DebugMessage type, const std::string& text);

            void SetConsoleColor(DebugMessage type);
            std::ostringstream& GetCurrentTimestamp(std::ostringstream& stream, const char* pattern);
            const char* GetFlavor(DebugMessage type);
            void LogToFile(std::ostringstream& stream);

        public:
            static void Init(bool useColor = true, bool useFlavor = true, bool useLogfile = true, bool useTimestamp = true);

            bool GetUseColor() const;
            bool GetUseTimestamp() const;
            bool GetUseFlavor() const;
            bool GetUseLogfile() const;

            void UseColor(bool useColor);
            void UseTimestamp(bool useTimestamp);
            void UseFlavor(bool useFlavor);
            void UseLogfile(bool useLogfile);

            void Log(const std::string& text);
            void LogCritical(const std::string& text);
            void LogError(const std::string& text);
            void LogWarning(const std::string& text);

            inline static void SLog(const std::string& text) { s_Instance->Log(text); }
            inline static void SLogCritical(const std::string& text) { s_Instance->LogCritical(text); }
            inline static void SLogError(const std::string& text) { s_Instance->LogError(text); }
            inline static void SLogWarning(const std::string& text) { s_Instance->LogWarning(text); }
            inline static Debug& GetInstance() { return *s_Instance; }
        };
    }
}