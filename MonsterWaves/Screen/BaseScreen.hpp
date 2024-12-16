#pragma once

#include "Screen/Window.hpp"

#include <memory>

class BaseScreen
{
public:
    explicit BaseScreen(Window* window);

    virtual ~BaseScreen() = default;

public:
    virtual void handleEvents() = 0;
    virtual void update(float dt) = 0;
    virtual void render() = 0;

public:
    [[nodiscard]] bool isRunning() const;

protected:
    std::unique_ptr< Window > m_window;

    sf::Event                 m_event{};
};