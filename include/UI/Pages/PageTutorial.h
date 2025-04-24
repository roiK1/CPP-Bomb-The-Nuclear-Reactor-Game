#pragma once
#include "Page.h"
#include "ButtonHome.h"

class PageTutorial : public Page
{
private:

public:
	PageTutorial(Controller& controller);
	~PageTutorial() = default;
	void update() override;
	void closePage() override;
};

