#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

const sf::Vector2f PLAYER_FIRST_POS(300.f, 120.f);
const sf::Vector2f NUCLEAR_REACTOR_POS(GAME_BG_WIDTH - 270.f, GAME_BG_HIGH - 250.f);
const sf::Vector2f HELICOPTER_POS(300.f, 300.f);
const sf::Vector2f KEY_POS(2381.49, 2306.23);

const std::vector<sf::Vector2f> TNT_POSITIONS
{ sf::Vector2f(277.757f, 673.805f), sf::Vector2f(268.421f, 1552.f),
  sf::Vector2f(2380.68f, 3986.14f) ,  sf::Vector2f(374.8,2538.04) };

const std::vector<sf::Vector2f> solidersPos
{
    sf::Vector2f(2388.71f, 993.74f), sf::Vector2f(2162.88f, 993.74f),
    sf::Vector2f(1989.41f, 993.74f), sf::Vector2f(785.522f, 993.74f),
    sf::Vector2f(608.593f, 993.74f), sf::Vector2f(180.527f, 993.74f),
    sf::Vector2f(457.054f, 993.74f), sf::Vector2f(174.92f, 1677.96f),
    sf::Vector2f(2403.4f, 1678.49f), sf::Vector2f(156.504f, 3060.93f),
    sf::Vector2f(258.429f, 2634.33f), sf::Vector2f(565.665f, 2634.33f),
    sf::Vector2f(665.914f, 2483.5f), sf::Vector2f(162.348f, 2483.5f),
    sf::Vector2f(414.985f, 2483.5f), sf::Vector2f(516.358f, 2483.5f),
    sf::Vector2f(288.141f, 2483.5f), sf::Vector2f(1365.32f, 4840.31f),
    sf::Vector2f(1365.32f, 4567.13f), sf::Vector2f(1518.97f, 4338.67f),
    sf::Vector2f(1667.56f, 4213.6f), sf::Vector2f(1992.89f, 4213.6f),
    sf::Vector2f(2340.7f, 4213.6f), sf::Vector2f(2173.42, 2665.12),
    sf::Vector2f(1870.98, 2665.12) , sf::Vector2f(1419.37, 2665.12) ,
    sf::Vector2f(1145.86, 2665.12) , sf::Vector2f(969.939, 2940.9),
    sf::Vector2f(789.657, 3211.45) , sf::Vector2f(2286.41, 3694.11) ,
    sf::Vector2f(1433.06, 3794.11) , sf::Vector2f(1939.22, 3794.11),
    sf::Vector2f(1183.33, 3794.11)
};

const std::vector<sf::Vector2f> tanksPos{
    sf::Vector2f(159.569f, 1231.14f), sf::Vector2f(961.516f, 1231.14f),
    sf::Vector2f(1280.51f, 1231.14f), sf::Vector2f(1940.7f, 1231.14f),
    sf::Vector2f(2245.19f, 2029.86f), sf::Vector2f(1775.12f, 2179.8f),
    sf::Vector2f(748.466f, 2054.04f), sf::Vector2f(203.735f, 2103.48f),
    sf::Vector2f(2403.58f, 3210.95f), sf::Vector2f(156.504f, 3212.5f),
    sf::Vector2f(2059.7f, 4006.63f), sf::Vector2f(1506.92f, 4006.63f),
    sf::Vector2f(156.025f, 4233.38f), sf::Vector2f(156.025f, 3781.03f),
    sf::Vector2f(280.025f, 4757.28f)
};

const std::vector<sf::Vector2f> presentsPos{
    sf::Vector2f(283.808f, 580.503f), sf::Vector2f(2392.96f, 1331.82f),
    sf::Vector2f(1997.38f, 682.734f), sf::Vector2f(1021.8f, 2181.37f),
    sf::Vector2f(2274.29f, 2899.17f), sf::Vector2f(400.012f, 3259.92f),
    sf::Vector2f(1536.38f, 3217.76f), sf::Vector2f(402.548f, 4137.05f),
    sf::Vector2f(277.721f, 3730.91f), sf::Vector2f(1055.79f, 4833.24f)
};

const std::vector<sf::Vector2f> stonePos{
    sf::Vector2f(2252.07, 110.266), sf::Vector2f(1756.26, 365.143),
    sf::Vector2f(2352.17, 687.48), sf::Vector2f(1580.75, 1207.91),
    sf::Vector2f(411.1, 1207.91),
    sf::Vector2f(2005.98, 4836.26), sf::Vector2f(2031.8, 4737.38),
    sf::Vector2f(2031.8, 4561.45), sf::Vector2f(2133.57, 4561.45),
    sf::Vector2f(2387.33, 4561.45), sf::Vector2f(2387.33, 4384.78),
    sf::Vector2f(2059.96, 4384.78), sf::Vector2f(1710.27, 4485.38),
    sf::Vector2f(1560.85, 4609.97), sf::Vector2f(1560.85, 4836.15),
    sf::Vector2f(1921.45, 4635.24),
    sf::Vector2f(2401.68f, 4064.19f), sf::Vector2f(2249.62f, 3989.86f),
    sf::Vector2f(2402.03f, 3887.36f), sf::Vector2f(946.749f, 3793.72f),
    sf::Vector2f(2318.54f, 1859.85f), sf::Vector2f(1886.31f, 1684.45f),
    sf::Vector2f(1101.4f, 1640.14f), sf::Vector2f(653.133f, 1801.14f)
};

const std::vector<sf::Vector2f> treesPos{
    sf::Vector2f(2276.92f, 3887.36f), sf::Vector2f(2253.47f, 4084.96f),
    sf::Vector2f(313.583f, 4673.5f), sf::Vector2f(2015.94f, 2870.7f),
    sf::Vector2f(1765.18f, 3216.09f),
    sf::Vector2f(2200.83, 687.48), sf::Vector2f(1728.06, 1207.91),
    sf::Vector2f(460.651, 1207.91), sf::Vector2f(389.243, 589.616),
    sf::Vector2f(389.243, 764.882), sf::Vector2f(188.386, 764.882),
    sf::Vector2f(188.386, 591.357), sf::Vector2f(2380.24, 1413.98),
    sf::Vector2f(2233.1, 1413.98), sf::Vector2f(1956.28, 1413.98),
    sf::Vector2f(1758.48, 1413.98), sf::Vector2f(1582.01, 1413.98),
    sf::Vector2f(1383.95, 1413.98), sf::Vector2f(1188.61, 1413.98),
    sf::Vector2f(966.703, 1413.98), sf::Vector2f(745.671, 1413.98),
    sf::Vector2f(546.555, 1413.98), sf::Vector2f(347.598, 1413.98),
    sf::Vector2f(173.478, 1413.98),
    sf::Vector2f(1907.1, 4836.26), sf::Vector2f(1907.1, 4737.38),
    sf::Vector2f(2031.8, 4664.88), sf::Vector2f(2286.72, 4561.45),
    sf::Vector2f(2211.79, 4384.78), sf::Vector2f(1859.03, 4384.78),
    sf::Vector2f(1560.85, 4760.83), sf::Vector2f(1460.71, 4836.15),
    sf::Vector2f(1720.33, 4583.08), sf::Vector2f(176.373, 2602.97)
    , sf::Vector2f(277.994, 2602.97),
    sf::Vector2f(453.936, 2602.97), sf::Vector2f(553.577, 2602.97),
    sf::Vector2f(652.542, 2602.97)
};


const std::vector<sf::Vector2f> fencePos{
    sf::Vector2f(168.068f, 2702.08f), sf::Vector2f(294.249f, 2702.08f),
    sf::Vector2f(443.169f, 2702.08f), sf::Vector2f(642.714f, 2702.08f),
    sf::Vector2f(743.211f, 2702.08f), sf::Vector2f(743.211f, 2601.78f),
    sf::Vector2f(743.211f, 2503.85f), sf::Vector2f(743.211f, 2383.57f),
    sf::Vector2f(594.041f, 2383.57f), sf::Vector2f(496.253f, 2383.57f),
    sf::Vector2f(371.502f, 2383.57f), sf::Vector2f(293.763f, 2383.57f),
    sf::Vector2f(193.013f, 2383.57f), sf::Vector2f(168.402f, 2383.57f)
};
