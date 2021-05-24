#include "Camera.h"

using namespace CBTD;

Camera::Camera(sf::RenderTarget* target) : m_target(target)
{
    m_view = sf::View();
    Reset();
}

Camera::~Camera()
{
}

sf::Vector2f Camera::GetPosition() const
{
    return m_position;
}

float Camera::GetRotation() const
{
    return m_rotation;
}

float Camera::GetZoom() const
{
    return 1 / m_zoom;
}

const sf::RenderTarget* Camera::GetTarget() const
{
    return m_target;
}

const sf::View& Camera::GetView() const
{
    return m_view;
}

void Camera::SetPosition(float x, float y)
{
    m_position.x = x;
    m_position.y = y;
    Update();
}

void Camera::SetPosition(sf::Vector2f pos)
{
    m_position.x = pos.x;
    m_position.y = pos.y;
    Update();
}

void Camera::SetRotation(float rot)
{
    m_rotation = rot;
    Update();
}

void Camera::SetZoom(float zoom)
{
    if (fabs(zoom) <= 0.0001f)
        m_zoom = 10000.f;
    else
        m_zoom = 1 / zoom;
    Update();
}

void Camera::SetTarget(sf::RenderTarget* target)
{
    m_target = target;
    Update();
}

void Camera::Reset()
{
    m_position = sf::Vector2f(0.f, 0.f);
    m_rotation = 0.f;
    m_zoom = 1.f;
    Update();
}

void Camera::Update()
{
    m_view.setCenter(m_position);
    m_view.setRotation(m_rotation);
    sf::Vector2u targetSize = m_target->getSize();

    m_view.setSize(sf::Vector2f(targetSize.x * m_zoom, targetSize.y * m_zoom));
}
