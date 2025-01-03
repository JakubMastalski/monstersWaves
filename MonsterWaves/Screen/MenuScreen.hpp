#pragma once

#include "Screen/BaseScreen.hpp"

class MenuScreen final : public BaseScreen
{
public:
	explicit MenuScreen(Window* window);
public:
    void handleEvents() override;
    void update(float dt) override;
    void render() override;

private:
    sf::Font m_font;
    sf::Text m_text;
};
