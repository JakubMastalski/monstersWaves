#include "BaseScreen.hpp"

BaseScreen::BaseScreen(Window* window) : m_window(window)
{
    // Empty body.
}
void BaseScreen::handleEvents()
{
    m_window->handleEvents();
}
bool BaseScreen::isRunning() const
{
    return m_window->isRunning();
}