#pragma once
#include <SFML/Graphics.hpp>

namespace CBTD {
    namespace Rendering {
        class Camera
        {
        public:
            Camera(sf::RenderTarget* target);
            ~Camera();

            sf::Vector2f GetPosition();
            float GetRotation();
            float GetZoom();
            const sf::RenderTarget* GetTarget();
            const sf::View& GetView();

            void SetPosition(float x, float y);
            void SetPosition(sf::Vector2f pos);
            void SetRotation(float rot);
            void SetZoom(float zoom);
            void SetTarget(sf::RenderTarget* target);
            void Reset();

        private:
            sf::Vector2f m_position;
            float m_rotation;
            float m_zoom;
            sf::RenderTarget* m_target;

            sf::View m_view;

            void Update();
        };

    }
}