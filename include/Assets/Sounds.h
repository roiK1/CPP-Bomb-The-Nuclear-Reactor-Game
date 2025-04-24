#pragma once
#include <SFML/Audio.hpp>
#include <map>
#include <memory>
#include <iostream>
#include "Consts.h"

class Sounds
{
private:
    static Sounds* m_sounds;
    std::map<soundsType, sf::SoundBuffer> m_soundBuffers;
    std::map<musicType, std::unique_ptr<sf::Music>> m_musics;
    std::vector<sf::Sound> m_playingSounds;

    Sounds();  
    Sounds(const Sounds&) = delete;
    Sounds& operator=(const Sounds&) = delete;

public:
    ~Sounds();
    static Sounds* instance();

    void playSounds(soundsType soundsName);
    void playMusic(musicType musicName);
    void pauseMusic(musicType musicName);
    bool isPlaying(musicType musicName);
    bool isPlaying(soundsType musicName);
    void loadSoundBuffer(soundsType soundName, const std::string& filePath);
    void loadMusic(musicType soundName, const std::string& filePath);
    void clearUnsed();
};
