#include "Sounds.h"

//-----------------------------------------------------------------------------
Sounds* Sounds::m_sounds = nullptr;

//-----------------------------------------------------------------------------
Sounds::Sounds()
{
    try {
        loadSoundBuffer(soundsType::buttonClick , "buttonClick.wav");
        loadMusic(musicType::countDown , "countdown.ogg");
        loadMusic(musicType::gameWin , "applause.wav");
        loadMusic(musicType::gameLose, "gameLose.wav");
        loadMusic(musicType::home, "pageHomeMusic.wav");
        loadSoundBuffer(soundsType::shootMissle , "shootMissile.wav");
        loadSoundBuffer(soundsType::humanDead , "humanDead.mp3");
        loadSoundBuffer(soundsType::missileExplotion , "MissileExplosion.ogg");
        loadSoundBuffer(soundsType::shootBullet , "shootBullet.wav");
        loadSoundBuffer(soundsType::gotHurt, "gotHurt.wav");
        loadSoundBuffer(soundsType::collectedSomething, "collectedSomeThing.mp3");
        loadSoundBuffer(soundsType::shieldInterception, "shieldInterception.mp3");
        loadMusic(musicType::startGame , "startGameBackground.mp3");
        loadMusic(musicType::help , "pageMenu.mp3");

    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

//-----------------------------------------------------------------------------
Sounds::~Sounds()
{
    if (m_sounds != nullptr)
    {
        delete m_sounds;
    }
}

//-----------------------------------------------------------------------------
Sounds* Sounds::instance()
{
    if (m_sounds == nullptr)
    {
        m_sounds = new Sounds();
    }
    return m_sounds;
}

//-----------------------------------------------------------------------------
void Sounds::loadSoundBuffer(soundsType soundName, const std::string& filePath)
{
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(filePath)) {
        throw std::runtime_error("Failed to load " + filePath);
    }

    m_soundBuffers[soundName] = std::move(buffer);
}

//-----------------------------------------------------------------------------
void Sounds::loadMusic(musicType musicName, const std::string& filePath)
{
    std::unique_ptr<sf::Music> music = std::make_unique<sf::Music>();

    if (!music->openFromFile(filePath)) {
        throw std::runtime_error("Failed to load music file: " + filePath);
    }

    m_musics[musicName] = std::move(music);
}

//-----------------------------------------------------------------------------
void Sounds::clearUnsed()
{
    for (auto it = m_playingSounds.begin(); it != m_playingSounds.end();)
    {
        if (it->getStatus() == sf::Sound::Status::Stopped)
        {
            it = m_playingSounds.erase(it); 
        }
        else
        {
            ++it; 
        }
    }

}

//-----------------------------------------------------------------------------
void Sounds::playMusic(musicType musicName)
{
    auto it = m_musics.find(musicName);
    if (it != m_musics.end()) {
        if (it->second->getStatus() == sf::Music::Paused)
        {
            it->second->setPlayingOffset(sf::Time::Zero);
        }
        it->second->play();
    }
    else {
        throw std::runtime_error("Music not found for the given music type.");
    }
}

//-----------------------------------------------------------------------------
void Sounds::playSounds(soundsType soundsName)
{
    clearUnsed();
    auto it = m_soundBuffers.find(soundsName);
    if (it != m_soundBuffers.end())
    {
        m_playingSounds.emplace_back(sf::Sound());
        m_playingSounds.back().setBuffer(it->second);
        m_playingSounds.back().play();
    }
    else
    {
        throw std::runtime_error("Sound not found for the given sound type.");
    }
}

//-----------------------------------------------------------------------------
void Sounds::pauseMusic(musicType musicName)
{
    auto it = m_musics.find(musicName);
    if (it != m_musics.end()) {
        it->second->pause();
    }
    else {
        throw std::runtime_error("Music not found for the given music type.");
    }
}
//-----------------------------------------------------------------------------
bool Sounds::isPlaying(soundsType soundName)
{
    for (const auto& sound : m_playingSounds) {
        if (sound.getStatus() == sf::SoundSource::Playing)
        {
            return true;
        }
    }

    return false;
}

//-----------------------------------------------------------------------------
bool Sounds::isPlaying(musicType musicName)
{
    auto it = m_musics.find(musicName);
    if (it != m_musics.end()) {
        return it->second->getStatus() == sf::SoundSource::Playing;
    }
    else {
        throw std::runtime_error("Music not found for the given music type.");
    }
}

//-----------------------------------------------------------------------------
