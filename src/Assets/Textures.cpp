#include "Textures.h"

//-----------------------------------------------------------------------------
Textures* Textures::m_texturesInstance = nullptr;

//-----------------------------------------------------------------------------
Textures::Textures()
{
    try
    {
        // Load game objects
        for (int i = 0; i <= 19; ++i) {
            loadTexture(textureType::Player, "survivor-move_rifle_" + std::to_string(i) + ".png");
        }

        for (int i = 1; i <= 9; ++i) {
            loadTexture(textureType::RescueHelicopter, "helicopter_" + std::to_string(i) + ".png");
        }

        for (int i = 0; i <= 6; ++i) {
            loadTexture(textureType::EnemySolider, "EnemySolider_" + std::to_string(i) + ".png");
        }

        loadTexture(textureType::EnemyTank, "EnemyTank.png");
        loadTexture(textureType::nuclearReactor, "nuclearReactor.png");
        loadTexture(textureType::nuclearReactor, "nuclearReactor_1.png");
        loadTexture(textureType::bullet, "bullet.png");
        loadTexture(textureType::missile, "missile.png");
        loadTexture(textureType::presentAddLife, "presentAddLife.png");
        loadTexture(textureType::presentAddMissile, "presentAddMissile.png");
        loadTexture(textureType::tree, "tree.png");
        loadTexture(textureType::fence, "fence.png");
        loadTexture(textureType::fence, "fence_1.png");
        loadTexture(textureType::tntBomb, "tnt.png");
        loadTexture(textureType::longwall, "longwall.png");
        loadTexture(textureType::stone, "stone.png");
        loadTexture(textureType::gate, "Gate.png");
        loadTexture(textureType::key, "key.png");
        loadTexture(textureType::presentShield, "presentShield.png");
        loadTexture(textureType::shieldState, "shieldState.png");

        for (int i = 0; i <= 8; ++i) {
            loadTexture(textureType::missileExplotion, "Sprite_Effects_Explosion_00" + std::to_string(i) + ".png");
        }


        // Load backgrounds
        loadTexture(textureType::bgHome, "bgHome.png");
        loadTexture(textureType::bgTutorial, "bgTutorial.png");
        loadTexture(textureType::bgGame, "bgGame.png");
        loadTexture(textureType::bgGameEnded, "bgGameEnded.png");
        loadTexture(textureType::bgGameEndedlose, "bgGameEndedLose.png");
        loadTexture(textureType::bgGameEndedWin, "bgGameEndedWin.png");

        // Load buttons
        loadTexture(textureType::buttonExit, "exitButton.png");
        loadTexture(textureType::buttonStartGame, "startGameButton.png");
        loadTexture(textureType::buttonTutorial, "tutorialButton.png");
        loadTexture(textureType::buttonHome, "homeButton.png");
        loadTexture(textureType::buttonStartNewGame, "ButtonStartNewGame.png");
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Error loading texture: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

//-----------------------------------------------------------------------------
void Textures::loadTexture(textureType type, const std::string& filename)
{
    auto texture = sf::Texture();
    if (!texture.loadFromFile(filename))
    {
        throw std::runtime_error("Failed to load texture from file: " + filename);
    }
    m_textures[type].emplace_back(texture);
}

//-----------------------------------------------------------------------------
Textures::~Textures()
{
    if (m_texturesInstance != nullptr)
    {
        delete m_texturesInstance;
    }
}

//-----------------------------------------------------------------------------
Textures* Textures::instance()
{
    if (m_texturesInstance == nullptr)
    {
        m_texturesInstance = new Textures();
    }
    return m_texturesInstance;
}

//-----------------------------------------------------------------------------
const std::vector<sf::Texture>& Textures::get(textureType name)
{
    auto it = m_textures.find(name);
    if (it != m_textures.end())
    {
        return it->second;
    }
    throw std::runtime_error("Failed to find texture");
}

//-----------------------------------------------------------------------------

