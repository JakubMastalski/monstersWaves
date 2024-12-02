#include <iostream>

#include "Screen/BaseScreen.hpp"
#include "Utils/TimeStep.hpp"

class SplashScreen : public BaseScreen
{
public:
    explicit SplashScreen(float duration = 5.f);
    ~SplashScreen() = default;
public:
    void update() override;
    void render() override;
    void draw() override;
    void handleEvent() override;
private:
    void initWindow();

    sf::Font m_font;
    sf::Text m_text;
    Window m_window;
    float m_windowDuration;
    TimeStep m_timer;
};