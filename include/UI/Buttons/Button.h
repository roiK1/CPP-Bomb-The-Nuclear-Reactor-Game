#pragma once
#include <string>
#include "Object.h"
#include "Textures.h"

class Button : public Object 
{
public:
	Button(sf::Vector2f pos,  const std::vector<sf::Texture>& textures);
	virtual ~Button() = default;
	bool isPressed(const sf::Vector2i& pos) const;
	virtual void execute() const= 0;
	void move(const sf::Vector2f& moveAmount);
	void setDefaultPosition();

private:
	sf::Vector2f m_defaultPos;
};