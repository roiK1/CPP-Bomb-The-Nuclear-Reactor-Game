#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include <memory>
#include <stdexcept>
#include "Consts.h"

class Textures
{
private:
    static Textures* m_texturesInstance;

    std::map<textureType, std::vector<sf::Texture>> m_textures;

    Textures();
    Textures(const Textures&) = delete;
    Textures& operator=(const Textures&) = delete;

    void loadTexture(textureType type, const std::string& filename);

public:
    ~Textures();
    static Textures* instance();
    const std::vector<sf::Texture>& get(textureType name);
};
