#pragma once
#include "Screen/BaseScreen.hpp"

class InventoryScreen final : public BaseScreen
{
public:
    explicit InventoryScreen(Window* window);

public:
    void handleEvents() override;
    void update(float dt) override;
    void render() override;

private:
    std::vector< sf::RectangleShape >   m_squares;
    std::vector< sf::CircleShape >      m_circles;
};