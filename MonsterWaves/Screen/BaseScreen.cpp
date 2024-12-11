#include "BaseScreen.hpp"

BaseScreen::BaseScreen(std::unique_ptr<Window> Window) : m_window(std::move(Window))
{
    // Empty body.
}
bool BaseScreen::isRunning() const
{
    return m_window->isRunning();
}