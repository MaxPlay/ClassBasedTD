#include "Settings.h"

using namespace CBTD;
using namespace Core;

Settings* Settings::s_Instance = 0;

Settings::Settings()
{
    m_VideoSettings = VideoSettings();
}

Settings::~Settings()
{
}

void Settings::Print()
{

}

void Settings::Load()
{

}

void Settings::Save()
{

}

VideoSettings & Settings::GetVideoSettings()
{
    return m_VideoSettings;
}
