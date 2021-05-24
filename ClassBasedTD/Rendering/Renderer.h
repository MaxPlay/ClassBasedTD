#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

namespace CBTD
{
    class Renderer
    {
    protected:
        int m_Priority;

    public:
        Renderer(int priority) : m_Priority(priority) {}
        ~Renderer() {}

        virtual void Draw(sf::RenderTarget& target) = 0;
        int GetPriority() const { return m_Priority; }
        void SetPriority(int value) { m_Priority = value; }

        bool operator > (const Renderer& renderer) const
        {
            return (m_Priority > renderer.m_Priority);
        }

        bool operator < (const Renderer& renderer) const
        {
            return (m_Priority < renderer.m_Priority);
        }
    };
}