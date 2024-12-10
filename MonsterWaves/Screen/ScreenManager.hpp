#include "Screen/BaseScreen.hpp"
#include <memory>
#include <stack>

class ScreenManager : public BaseScreen
{
	explicit ScreenManager(BaseScreen* windowPtr);
	void pushScreen(std::shared_ptr<BaseScreen> screen);
	void popScreen();
	void update(float deltaTime) override;
	void render() override;

private:
	std::stack<std::shared_ptr<BaseScreen>> m_screens;
};