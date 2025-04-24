#pragma once
#include "Page.h"
#include "ButtonExit.h"
#include "ButtonStartGame.h"
#include "ButtonTutorial.h"
#include "ButtonStartNewGame.h"

class PageHome : public Page
{
private:

public:
	PageHome(Controller& controller);
	~PageHome() = default;
	void update() override;
	void closePage() override;

};

