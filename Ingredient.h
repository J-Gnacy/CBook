#pragma once
#include <iostream>

enum Unit { g, kg, l, ml };

class Ingredient
{
    friend class Recipe;

    std::string name;
    float amount;
    Unit usedUnit;

    Ingredient(std::string newName, float newAmount, Unit newUnit)
        : name(newName), amount(newAmount), usedUnit(newUnit)
    {

    }

    Ingredient(Ingredient* ingredient)
        : name(ingredient->name), amount(ingredient->amount), usedUnit(ingredient->usedUnit)
    {

    }

public:
    std::string getName();

    void setAmount(float newAmount);

    float getAmount();

};

