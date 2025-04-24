#pragma once
#include <sfml/Graphics.hpp>
#include "Textures.h"
#include "Consts.h"
#include "Sounds.h"

using std::vector;
using std::string;

class Object
{
public:
	virtual ~Object() = default;
	Object(sf::Vector2f pos , const std::vector<sf::Texture>& textures);

	virtual void draw(sf::RenderWindow& window) const;
	sf::Vector2f getPos() const;
	bool checkCollison(const Object* object) const;
	void updateTextureTimer(const sf::Time& delta);
	void updateTexture();
	void nextTextureIndex();

protected:
	sf::Sprite m_object;
	const std::vector<sf::Texture>& m_textures;
	float m_animation_frame_time;
	sf::Time m_textureTimeElapsed;
	int m_textureIndex;
};