#include "Screen/BaseScreen.hpp"
#include "Utils/TimeStep.hpp"

class SplashScreen : public BaseScreen
{
public:
    SplashScreen(Window window, float duration = 5.f);
    ~SplashScreen() = default;
public:
    void update() override;
    void render() override;
    void draw() override;
    void handleEvent() override;

   virtual bool windowIsDone();
private:
    void initWindow();

    sf::Font m_font;
    sf::Text m_text;

    float m_windowDuration;
    TimeStep m_timer;
};