#include "Recipe.h"


void Recipe::AddIngredient(std::string name, float amount, Unit unitUsed)
{

    Ingredient* newIngredient = new Ingredient(name, amount, unitUsed);
    IngredientList.push_back(newIngredient);


}
void Recipe::DeleteIngredient(Ingredient* ingredient)
{
    delete ingredient;
}

void Recipe::RecalculateRecipe(float newAmount)
{
    float ratio = recipeProductAmount / newAmount;
    float temporaryAmount;

    for(int i = 0; i < IngredientList.size(); i++)
    {
        temporaryAmount=IngredientList[i]->getAmount();
        temporaryAmount = temporaryAmount / ratio;
        IngredientList[i]->setAmount(temporaryAmount);
    }
}

void Recipe::ShowRecipe()
{
    Log("Recipe name: " + recipeName);
    
}

void Recipe::ForEachIngredient(const std::function<void(Ingredient*)>& func)
{
    for (int i = 0; i < IngredientList.size(); i++)
    {
        func(IngredientList[i]);
    }
}

std::vector<Ingredient*> Recipe::GetIngredientList()
{
    return IngredientList;
}

Recipe::~Recipe()
{
    for (int i = 0; i < IngredientList.size(); i++)
    {

        std::cout << "Test destroyed\n";
        DeleteIngredient(IngredientList[i]);
    }
}

template<typename logged>
void Recipe::Log(logged var)
{
    std::cout << var << "\n";
}