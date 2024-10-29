#include <gtest/gtest.h>

#include "Window.hpp"

class WindowTest : public ::testing::Test
{
protected:
    void createDefaultWindow()
    {
        m_window = std::make_unique< Window >();
    }

    std::unique_ptr< Window > m_window;
};
