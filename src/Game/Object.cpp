#include "Object.h"

//-----------------------------------------------------------------------------
Object::Object(sf::Vector2f pos , const std::vector<sf::Texture>& textures)
	:m_textures(textures) , m_textureIndex(0) , m_textureTimeElapsed(sf::seconds(0)),
	 m_animation_frame_time(ANIMATION_FRAME_TIME)
{
	m_object.setTexture(m_textures[0]);
	m_object.setPosition(pos);
	m_object.setOrigin(m_object.getLocalBounds().width / 2.f,
					   m_object.getLocalBounds().height / 2.f);
}

//-----------------------------------------------------------------------------
void Object::draw(sf::RenderWindow& window) const
{
	window.draw(m_object);
}

//-----------------------------------------------------------------------------
sf::Vector2f Object::getPos() const
{
	return m_object.getPosition();
}

//-----------------------------------------------------------------------------
bool Object::checkCollison(const Object* object) const
{
	if (m_object.getGlobalBounds().intersects(object->m_object.getGlobalBounds()))
	{
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------
void Object::updateTextureTimer(const sf::Time& delta)
{
    m_textureTimeElapsed += delta;
    if (m_textureTimeElapsed >= sf::seconds(m_animation_frame_time))
    {
		m_textureTimeElapsed -= sf::seconds(m_animation_frame_time);
        ++m_textureIndex;
		m_textureIndex %= m_textures.size();
        updateTexture();
    }
}

//-----------------------------------------------------------------------------
void Object::updateTexture()
{
	m_object.setTexture(m_textures[m_textureIndex]);
}

//-----------------------------------------------------------------------------
void Object::nextTextureIndex()
{
	if (m_textureIndex + 1 < m_textures.size())
	{
		++m_textureIndex;
	}
}
//-----------------------------------------------------------------------------
