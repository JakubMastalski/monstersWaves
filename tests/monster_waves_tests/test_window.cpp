#include "Screen/Window.hpp"
#include <gtest/gtest.h>


class WindowTest : public ::testing::Test
{
protected:
    void createDefaultWindow()
    {
        m_window = std::make_unique< Window >();
    }

    std::unique_ptr< Window > m_window;
};
