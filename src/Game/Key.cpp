#include "Key.h"
#include "Player.h"
#include "Gate.h"

//-----------------------------------------------------------------------------
Key::Key(sf::Vector2f pos, Gate* gate)
	:StaticObject(pos, Textures::instance()->get(textureType::key)) , m_gate(gate)
{
	m_object.setScale(1.5f, 1.5f);
}

//-----------------------------------------------------------------------------
void Key::handleCollison(Player* player)
{
	m_isExists = false;
	Sounds::instance()->playSounds(soundsType::collectedSomething);
	m_gate->openGate();
}

//-----------------------------------------------------------------------------
