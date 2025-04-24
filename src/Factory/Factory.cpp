#include "Factory.h"
#include "Enemy.h"
#include "Present.h"
#include "Movement.h"
#include <cstdlib>  // for rand
#include <ctime>  // for time
#include <iterator> 
#include <iostream> 

//-----------------------------------------------------------------------------
//   getContiner
//-----------------------------------------------------------------------------
map<MoveType, moveFunc>& Factory::getMoveMap()
{
    static map<MoveType , moveFunc> movementVec;
    return movementVec;
}
//-----------------------------------------------------------------------------
map<AmmoType, shootFunc>& Factory::getShootMap()
{
    static map<AmmoType, shootFunc> shootMap;
    return shootMap;
}

//-----------------------------------------------------------------------------
vector<createPresentFunc>& Factory::getPresentVector()
{
    static vector<createPresentFunc> presentsVector;
    return presentsVector;
}
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
//    register funcs
//-----------------------------------------------------------------------------
bool Factory::registerMove(MoveType type , moveFunc moveFunction)
{
    getMoveMap().emplace(type, moveFunction);
    return true;
}

//-----------------------------------------------------------------------------
bool Factory::registerShoot(AmmoType type, shootFunc sf)
{
    getShootMap().emplace(type , sf);
    return true;
}

//-----------------------------------------------------------------------------
bool Factory::registerPresent(createPresentFunc createPresentFunction)
{
    getPresentVector().emplace_back(createPresentFunction);
    return true;
}


//-----------------------------------------------------------------------------
//     create objects
//-----------------------------------------------------------------------------
unique_ptr<Enemy> Factory::createSolider(const sf::Vector2f& pos , int& totalScore)
{
    int randomIndex = std::rand() % getMoveMap().size();
    auto itRandomMove = getMoveMap().begin();
    std::advance(itRandomMove, randomIndex);

    return make_unique<Enemy>(  pos , itRandomMove->second(),
                                AmmoType::Bullet, std::make_unique<ShootBullet>(),
                                ENEMY_SOLIDER_SPEED,
                                Textures::instance()->get(textureType::EnemySolider) ,
                                totalScore , SCORE_KILL_SOLIDER);
}

//-----------------------------------------------------------------------------
unique_ptr<Enemy> Factory::createTank(const sf::Vector2f& pos , int& totalScore)
{
    return make_unique<Enemy>(  pos, getMoveMap()[MoveType::Sides](),
                                AmmoType::Missile, std::make_unique<ShootMissile>(),
                                ENEMY_TANK_SPEED,
                                Textures::instance()->get(textureType::EnemyTank) ,
                                totalScore , SCORE_KILL_TANK);
}

//-----------------------------------------------------------------------------
unique_ptr<Ammo> Factory::createAmmo(AmmoType type, const sf::Vector2f& pos)
{
    if (!getShootMap().contains(type))
    {
        return nullptr;
    }

    return getShootMap().at(type)(pos);
}

//-----------------------------------------------------------------------------
unique_ptr<Present> Factory::createPresent(const sf::Vector2f& pos, int& totalScore)
{
    return getPresentVector()[std::rand() % getPresentVector().size()](pos , totalScore);
}

//-----------------------------------------------------------------------------
unique_ptr<NuclearReactor> Factory::createNuclearReactor(const sf::Vector2f& pos, int& totalScore)
{
    return std::make_unique<NuclearReactor>(pos, totalScore);
}

//-----------------------------------------------------------------------------
unique_ptr<TNTBomb> Factory::createTNTBomb(const sf::Vector2f& pos)
{
    return std::make_unique<TNTBomb>(pos);
}

//-----------------------------------------------------------------------------
unique_ptr<SomeStaticObject> Factory::createFence(const sf::Vector2f& pos)
{
    return std::make_unique<SomeStaticObject>(pos , 
                Textures::instance()->get(textureType::fence) , INIT_FENCE_RESIST);
}

//-----------------------------------------------------------------------------
unique_ptr<SomeStaticObject> Factory::createTree(const sf::Vector2f& pos)
{
    return std::make_unique<SomeStaticObject>(pos,
        Textures::instance()->get(textureType::tree), INIT_TREE_RESIST);
}
//-----------------------------------------------------------------------------
unique_ptr<SomeStaticObject> Factory::createStone(const sf::Vector2f& pos)
{
    return std::make_unique<SomeStaticObject>(pos,
        Textures::instance()->get(textureType::stone), INIT_STONE_RESIST);
}

//-----------------------------------------------------------------------------
unique_ptr<SomeStaticObject> Factory::createWall(const sf::Vector2f& pos)
{
    return std::make_unique<SomeStaticObject>(pos,
        Textures::instance()->get(textureType::longwall), INIT_WALL_RESIST);
}

//-----------------------------------------------------------------------------
unique_ptr<StaticObject> Factory::createGate(const sf::Vector2f& pos )
{
    return std::make_unique<Gate>(pos );
}
//-----------------------------------------------------------------------------
unique_ptr<StaticObject> Factory::createKey(const sf::Vector2f& pos, Gate* gate)
{
    return std::make_unique<Key>(pos ,gate);
}

//-----------------------------------------------------------------------------
unique_ptr<PlayerRescueHelicopter> Factory::createHelicopter(sf::Vector2f pos,
                                    bool& missionSuccess, bool& isBombPlanted)
{
    return std::make_unique<PlayerRescueHelicopter>(pos , missionSuccess , isBombPlanted);
}

//-----------------------------------------------------------------------------