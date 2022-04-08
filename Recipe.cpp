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
    float ratio = recipeDesiredAmount / newAmount;
    recipeDesiredAmount = newAmount;
    float temporaryAmount;

    auto recalculateFormula = [&](Ingredient* ingredient) {
        temporaryAmount = ingredient->GetAmount();
        temporaryAmount = temporaryAmount / ratio;
        ingredient->SetAmount(temporaryAmount); };

    ForEachIngredient(recalculateFormula);
}

void Recipe::ShowRecipe()
{
    Log("Recipe name: " + recipeName);
    std::cout << "   Amount: ";
    Log(recipeDesiredAmount);

    auto showAllIngredients = [&](Ingredient* ingredient) {
        Log((ingredient->GetName()));
        Log(ingredient->GetAmount());
    };

    ForEachIngredient(showAllIngredients);


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
    auto logRemoveMessage = [&](Ingredient* ingredient) {
        Log((ingredient->GetName()) + " removed");
        DeleteIngredient(ingredient);
    };

    ForEachIngredient(logRemoveMessage);

}

template<typename logged>
void Recipe::Log(logged var)
{
    std::cout << var << "\n";
}