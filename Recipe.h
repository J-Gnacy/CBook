#pragma once
#include <iostream>
#include "Ingredient.h"
#include <functional>
#include <vector>

class Recipe
{


private:

    std::vector<Ingredient*>IngredientList;

    float recipeProductAmount;

    float recipeNewAmount;

    std::string recipeName;

public:

    Recipe(float desiredAmount, std::string desiredName)
        :recipeProductAmount(desiredAmount), recipeName(desiredName){};


    void AddIngredient(std::string name, float amount, Unit unitUsed);


    void DeleteIngredient(Ingredient* ingredient);

    void RecalculateRecipe(float newAmount);

    template<typename logged>
    void Log(logged var);

    void ShowRecipe();

    void ForEachIngredient(const std::function<void(Ingredient*)>& func);

    std::vector<Ingredient*> GetIngredientList();

    ~Recipe();

};