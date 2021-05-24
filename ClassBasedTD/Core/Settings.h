#pragma once
#include <SFML/Window.hpp>
#include "Debug.h"

namespace CBTD {
    struct VideoSettings
    {
        VideoSettings() : Mode(sf::VideoMode(200, 200)), Context(sf::ContextSettings()), Fullscreen(false), ShowMouse(true), GrabMouse(false), VSync(false), Icon(""), Title("Class Based Tower Defense")
        {
        }

        sf::VideoMode Mode;
        sf::ContextSettings Context;
        bool Fullscreen;
        bool ShowMouse;
        bool GrabMouse;
        bool VSync;
        std::string Icon;
        std::string Title;
    };

    class Settings
    {
    private:
        static Settings* s_Instance;
    public:
        inline static Settings& GetSettings()
        {
            if (!s_Instance)
                s_Instance = new Settings();
            return *s_Instance;
        }

    private:
        Settings();
        ~Settings();
        const char* SETTINGS_FILE = "game.settings";
        VideoSettings m_VideoSettings;

    public:
        void Print();
        void Load();
        void Save();

        VideoSettings& GetVideoSettings();
    };
}