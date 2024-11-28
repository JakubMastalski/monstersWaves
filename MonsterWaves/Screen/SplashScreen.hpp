#include "BaseScreen.hpp"

class SplashScreen : public BaseScreen
{
public:
    SplashScreen();
    ~SplashScreen = default;

    void update() override;
    void render() override;
    void handleEvent() override;
    bool windowIsDone() ovveride;
private:
    sf::Text m_text;
};