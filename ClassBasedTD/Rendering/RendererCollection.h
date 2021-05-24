#pragma once
#include <SFML/Graphics/RenderTarget.hpp>

#include <vector>
#include "Renderer.h"
#include "Camera.h"

namespace CBTD
{
    class Renderer;

    class RendererCollection
    {
        const Camera* m_Camera;
        std::vector<Renderer*> m_Renderers;
        bool m_Unique;

    public:
        RendererCollection(bool unique = false);
        ~RendererCollection();

        bool AddRenderer(Renderer& renderer);
        bool RemoveRenderer(Renderer& renderer);

        bool Contains(const Renderer& renderer) const;
        void Order();
        void OrderDescending();

        void Draw(sf::RenderTarget& target);
        void Dispose();
        void DisposeAndClear();
        void Clear();

        void SetCamera(const Camera* camera);
    };
}