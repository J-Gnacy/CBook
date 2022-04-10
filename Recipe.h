#pragma once
#include <iostream>
#include "Ingredient.h"
#include <functional>
#include <vector>

class Recipe
{


private:

    std::vector<Ingredient*>IngredientList;

    const float recipeProductAmount;

    float recipeDesiredAmount;

    std::string recipeName;

    Unit recipeUnit;

    void ForEachIngredient(const std::function<void(Ingredient*)>& func);

public:

    Recipe(float desiredAmount, std::string desiredName, Unit desiredUnit)
        :recipeProductAmount(desiredAmount), recipeDesiredAmount(desiredAmount), recipeName(desiredName), recipeUnit(desiredUnit){};


    void AddIngredient(std::string name, float amount, Unit unitUsed);


    void DeleteIngredient(Ingredient* ingredient);

    void RecalculateRecipe(float newAmount);

    void ShowRecipe();

    float GetAmount();

    std::vector<Ingredient*> GetIngredientList();

    template<typename logged>
    static void Log(logged var);

    ~Recipe();

};