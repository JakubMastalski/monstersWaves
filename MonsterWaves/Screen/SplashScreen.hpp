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
    bool getsplashIsDone();
    void draw() override;
    void handleEvent() override;

    bool splashIsDone = { false };
private:
    void initWindow();

    sf::Font m_font;
    sf::Text m_text;
    float m_windowDuration;
    TimeStep m_timer;

};