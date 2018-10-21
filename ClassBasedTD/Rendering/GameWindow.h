#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

namespace CBTD {
    namespace Rendering {
        class GameWindow
        {
            sf::RenderWindow* m_Window;
            bool m_Open;
            bool m_Fullscreen;

        public:
            GameWindow();
            ~GameWindow();
            void Show();
            void Hide();
            void Apply(bool recreateWindow = true);
            bool IsOpen();
            bool IsFullscreen();
            sf::RenderWindow* GetWindow();
        };
    }
}