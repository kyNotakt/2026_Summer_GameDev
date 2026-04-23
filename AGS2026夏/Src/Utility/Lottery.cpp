#include "Lottery.h"

Lottery::Lottery()
{
    std::random_device rd;
    gen = std::mt19937(rd());

    // ターン決め
    turnRates =
    {
        {"リプレイ", 20},
        {"ベル", 20},
        {"弱チェリー", 10},
        {"強チェリー", 10},
        {"弱スイカ", 5},
        {"強スイカ", 5},
        {"ハズレ", 30}
    };

    // ダメージ
    damageRates =
    {
        {"リプレイ", 20},
        {"ベル", 10},
        {"弱チェリー", 5},
        {"強チェリー", 5},
        {"弱スイカ", 5},
        {"強スイカ", 5},
        {"ハズレ", 50}
    };

    // 回避
    evadeRates = 
    { 
        {"リプレイ", 18},
        {"ベル", 10},
        {"弱チェリー", 10},
        {"強チェリー", 1},
        {"弱スイカ", 5},
        {"強スイカ", 1},
        {"ハズレ", 60} 
    };
}

Lottery::~Lottery()
{
}

std::string Lottery::drawTurn()
{
    return turnRates[weightedRandom(turnRates)].name;
}

int Lottery::drawDamage()
{
    return std::stoi(damageRates[weightedRandom(damageRates)].name);
}

bool Lottery::drawEvade()
{
    return evadeRates[weightedRandom(evadeRates)].name == "true";
}

int Lottery::weightedRandom(const std::vector<Rate>& rates)
{
    int total = 0;
    for (auto& r : rates)
    {
        total += r.weight;
    }

    std::uniform_int_distribution<> dist(0, total - 1);
    int rand = dist(gen);
    
    int current = 0;
    for (int i = 0; i < rates.size(); i++)
    {
        current += rates[i].weight;
        if (rand < current)
        {
            return i;
        }
    }
    return 0;
}
