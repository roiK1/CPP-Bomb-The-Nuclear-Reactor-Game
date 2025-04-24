#pragma once
#include <sfml/Graphics.hpp>
#include<iostream>
#include <memory>
#include <unordered_map>
#include "Consts.h"
#include "ShootBullet.h"
#include "shootMissile.h"
#include "PlayerRescueHelicopter.h"
#include "NuclearReactor.h"
#include "TNTBomb.h"
#include "SomeStaticObject.h"
#include "Key.h"

using std::unique_ptr;
using std::map;
using std::vector;
using std::string;

class Enemy;
class Movement;
class Ammo;
class Present;
class PlayerRescueHelicopter;

using moveFunc = unique_ptr<Movement>(*)();
using createPresentFunc = unique_ptr<Present>(*)(const sf::Vector2f& pos, int& totalScore);
using shootFunc = unique_ptr<Ammo>(*)(const sf::Vector2f& pos);

class Factory
{
public:
	static map<MoveType, moveFunc>& getMoveMap();
	static map<AmmoType, shootFunc>& getShootMap();
	static vector<createPresentFunc>& getPresentVector();

	static bool registerMove(MoveType type, moveFunc moveFunction);
	static bool registerShoot(AmmoType type, shootFunc sf);
	static bool registerPresent(createPresentFunc createPresentFunction);

	static unique_ptr<Enemy> createSolider(const sf::Vector2f& pos , int& totalScore);
	static unique_ptr<Enemy> createTank(const sf::Vector2f& pos, int& totalScore);
	static unique_ptr<Ammo> createAmmo(AmmoType type , const sf::Vector2f& pos);
	static unique_ptr<Present> createPresent(const sf::Vector2f& pos, int& totalScore);
	static unique_ptr<NuclearReactor> createNuclearReactor(const sf::Vector2f& pos, int& totalScore);
	static unique_ptr<TNTBomb> createTNTBomb(const sf::Vector2f& pos);
	static unique_ptr<SomeStaticObject> createFence(const sf::Vector2f& pos);
	static unique_ptr<SomeStaticObject> createTree(const sf::Vector2f& pos);
	static unique_ptr<SomeStaticObject> createStone(const sf::Vector2f& pos);
	static unique_ptr<SomeStaticObject> createWall(const sf::Vector2f& pos);
	static unique_ptr<StaticObject> createGate(const sf::Vector2f& pos);
	static unique_ptr<StaticObject> createKey(const sf::Vector2f& pos, Gate* gate);
	static unique_ptr<PlayerRescueHelicopter> createHelicopter(sf::Vector2f pos, bool& missionSuccess,
															   bool& isBombPlanted);
};

