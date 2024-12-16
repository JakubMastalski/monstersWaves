#include "BaseScreen.hpp"

BaseScreen::BaseScreen(Window* window) : m_window(window)
{
    // Empty body.
}

<<<<<<< HEAD

=======
>>>>>>> develop
bool BaseScreen::isRunning() const
{
    return m_window->isRunning();
}