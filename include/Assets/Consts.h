#pragma once
#include <sfml/Graphics.hpp>

//-------------------------------------------------
//Bonders
const float WINDOW_WIDTH(1500);
const float WINDOW_HIGH(950);

const float GAME_BG_WIDTH(2560);
const float GAME_BG_HIGH(5000);

//-------------------------------------------------
//Objects
enum class textureType
{
    Player, EnemySolider, EnemyTank ,
    RescueHelicopter, nuclearReactor ,
    bullet , missile , missileExplotion , 
    tree , fence, tntBomb , shieldState,
    longwall, stone , gate, key,

    presentAddLife , presentAddMissile , presentShield,

    bgHome , bgTutorial , bgGame ,
    bgGameEnded , bgGameEndedlose,  bgGameEndedWin ,

    buttonExit , buttonStartGame , buttonTutorial , 
    buttonHome , buttonStartNewGame ,
};

//-------------------------------------------------
//sounds and music
enum class soundsType
{
    buttonClick , shootMissle , shootBullet ,
    missileExplotion , gotHurt , shieldInterception,
    collectedSomething , humanDead
};

enum class musicType
{
    startGame , home , gameLose, gameWin , countDown,
    help
};

//-------------------------------------------------
//Directions
const sf::Vector2f LEFT(-1.f, 0.f);
const sf::Vector2f RIGHT(1.f, 0.f);
const sf::Vector2f UP(0.f, -1.f);
const sf::Vector2f DOWN(0.f, 1.f);
const sf::Vector2f STAY(0.f, 0.f);
const sf::Vector2f UP_LEFT(-1.f, -1.f);
const sf::Vector2f UP_RIGHT(1.f, -1.f);
const sf::Vector2f DOWN_LEFT(-1.f, 1.f);
const sf::Vector2f DOWN_RIGHT(1.f, 1.f);

//-------------------------------------------------
//Positions
const float MAX_APPROACH_TO_PLAYER(250.f);

//-------------------------------------------------
//Objects Speeds
const float PLAYER_SPEED(600.f);
const float ENEMY_SOLIDER_SPEED(120.F);
const float ENEMY_TANK_SPEED(50.F);
const float BULLET_SPEED(900.F);
const float MISSILE_SPEED(400.F);
const float HELICOPTER_SPEED(2600.F);

//-------------------------------------------------
//Damage
const int BULLET_DAMAGE(2.f);
const int MISSILE_DAMAGE(10.f);
const float PLAYER_SHOOT_COOLDOWN(0.1f);
const float MISSILE_EXPLOTION_DAMAGE(MISSILE_DAMAGE);

//-------------------------------------------------
//Other
const int INIT_PLAYER_LIFES(350);
const int INIT_ENEMY_SOLIDER_LIFES(BULLET_DAMAGE * 3);
const int INIT_ENEMY_TANK_LIFES(MISSILE_EXPLOTION_DAMAGE);
const int INIT_ROCKETS_NUM(7);
const int INIT_TREE_RESIST(BULLET_DAMAGE * 1);
const int INIT_FENCE_RESIST(BULLET_DAMAGE *4);
const int INIT_STONE_RESIST(BULLET_DAMAGE *2);
const int INIT_WALL_RESIST(2000);
const int MIN_TNT_BOMBS_FOR_EXPLOTION(4);

//-------------------------------------------------
//Presents
const int PRESENT_LIFE_AMOUNT = 50;
const int PRESENT_MISSILE_AMOUNT = 4;

//-------------------------------------------------
enum class AmmoType
{
	None , Bullet, Missile , Explotion
};

enum class MoveType
{
	Smart , Sides
};
//-------------------------------------------------
//timers
const float BASIC_GAME_END_TIME(60.f * 2.5f);
const float NUCLEAR_EXPLOTION_TIME(20.6f);
const float ANIMATION_FRAME_TIME(0.2f);
const float MISSILE_EXPLOTION_TIME(3.f);
const float SHIELD_PROTECTION_TIME(7.f);

//-------------------------------------------------
//score
const int SCORE_KILL_SOLIDER(100);
const int SCORE_KILL_TANK(500);
const int SCORE_GIFT(50);
const int SCORE_PLANTED_BOMB(2000);

//-------------------------------------------------
//size
const sf::Vector2f BUTTON_SIZE(112, 112);