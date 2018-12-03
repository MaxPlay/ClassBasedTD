#include "RendererCollection.h"

using namespace CBTD;
using namespace Rendering;

RendererCollection::RendererCollection(bool unique) : m_Renderers(), m_Unique(unique), m_Camera(nullptr)
{
}

RendererCollection::~RendererCollection()
{
    m_Renderers.clear();
}

bool RendererCollection::AddRenderer(Renderer * renderer)
{
    if (m_Unique && Contains(renderer))
        return false;
    m_Renderers.push_back(renderer);
    return true;
}

bool RendererCollection::RemoveRenderer(Renderer * renderer)
{
    auto element = std::find(m_Renderers.begin(), m_Renderers.end(), renderer);
    if (element == m_Renderers.end())
        return false;
    m_Renderers.erase(element);
    return true;
}

bool RendererCollection::Contains(Renderer * renderer) const
{
    return std::find(m_Renderers.begin(), m_Renderers.end(), renderer) != m_Renderers.end();
}

void RendererCollection::Order()
{
    std::sort(m_Renderers.begin(), m_Renderers.end());
}

void RendererCollection::OrderDescending()
{
    std::sort(m_Renderers.rbegin(), m_Renderers.rend());
}

void RendererCollection::Draw(sf::RenderTarget & target)
{
    if (m_Camera)
        target.setView(m_Camera->GetView());
    for (auto it = m_Renderers.begin(); it != m_Renderers.end(); it++)
    {
        (*it)->Draw(target);
    }
}

void RendererCollection::Dispose()
{
    for (size_t i = 0; i < m_Renderers.size(); i++)
        delete m_Renderers.at(i);
}

void RendererCollection::DisposeAndClear()
{
    Dispose();
    Clear();
}

void RendererCollection::Clear()
{
    m_Renderers.clear();
}

void RendererCollection::SetCamera(const Camera * camera)
{
    m_Camera = camera;
}
