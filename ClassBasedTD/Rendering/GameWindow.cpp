#include "GameWindow.h"
#include "../Core/Settings.h"

using namespace CBTD;

GameWindow::GameWindow()
{
    m_Window = new sf::RenderWindow();
    Apply();
}

GameWindow::~GameWindow()
{
    if (m_Open)
        m_Window->close();

    delete m_Window;
}

void GameWindow::Show()
{
    m_Window->setVisible(true);
    m_Open = true;
}

void GameWindow::Hide()
{
    m_Window->setVisible(false);
    m_Open = false;
}

void GameWindow::Apply(bool recreateWindow)
{
    const VideoSettings& settings = Settings::GetSettings().GetVideoSettings();
    if (recreateWindow)
        m_Window->create(settings.Mode, settings.Title, settings.Fullscreen ? sf::Style::Fullscreen : sf::Style::Default, settings.Context);
    //TODO: Set Icon m_Window->setIcon()
    m_Window->setMouseCursorVisible(settings.ShowMouse);
    m_Window->setMouseCursorGrabbed(settings.GrabMouse);
    m_Window->setVerticalSyncEnabled(settings.VSync);
    Show();
}

bool GameWindow::IsOpen() const
{
    return m_Open;
}

bool GameWindow::IsFullscreen() const
{
    return m_Fullscreen;
}

sf::RenderWindow* GameWindow::GetWindow() const
{
    return m_Window;
}
