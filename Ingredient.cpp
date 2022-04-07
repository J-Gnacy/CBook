#include "Ingredient.h"

std::string Ingredient::getName()
{
	return name;
}

void Ingredient::setAmount(float newAmount)
{
	amount = newAmount;
}

float Ingredient::getAmount() 
{
	return amount;
}
