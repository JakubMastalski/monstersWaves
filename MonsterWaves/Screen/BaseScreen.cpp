#include "Screen/BaseScreen.hpp"

BaseScreen::BaseScreen(Window* window) : m_window(window)
{
    // Empty body.
}

bool BaseScreen::isRunning() const
{
    return m_window->isRunning();
}