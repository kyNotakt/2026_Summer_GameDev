#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <random>

struct Rate
{
    std::string name;
    int weight;
};

class Lottery
{
public:
    Lottery();
    ~Lottery();

    std::string drawTurn();
    int drawDamage();
    bool drawEvade();

private:
    std::vector<Rate> turnRates;
    std::vector<Rate> damageRates;
    std::vector<Rate> evadeRates;

    std::mt19937 gen;

    int weightedRandom(const std::vector<Rate>& rates);// ‹¤’Ê’Š‘I
};