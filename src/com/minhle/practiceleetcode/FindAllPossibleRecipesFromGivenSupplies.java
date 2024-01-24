package com.minhle.practiceleetcode;

import java.util.*;

public class FindAllPossibleRecipesFromGivenSupplies {

    String[] recipes;
    List<List<String>> ingredients;

    Set<String> supplies;
    Map<String, Integer> recipeIndex;
    Set<String> achievedRecipes;

    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        this.recipes = recipes;
        this.ingredients = ingredients;
        List<String> res = new ArrayList<>();

        this.supplies = new HashSet<>(Arrays.asList(supplies));
        this.recipeIndex = new HashMap<>();
        this.achievedRecipes = new HashSet<>();
        for (int i = 0; i < recipes.length; i++) {
            this.recipeIndex.put(recipes[i], i);
        }
        for (String recipe : recipes) {
            if (this.achievedRecipes.contains(recipe) | canMakeRecipe(recipe, new HashSet<>())) {
                res.add(recipe);
                achievedRecipes.add(recipe);
            }
        }

        return res;
    }

    private boolean canMakeRecipe(String recipe, Set<String> currentRecipes) {
        if (this.achievedRecipes.contains(recipe)) {
            return true;
        }
        if (!this.recipeIndex.containsKey(recipe)) {
            return false;
        }
        int index = this.recipeIndex.get(recipe);
        List<String> requirements = this.ingredients.get(index);
        for (String requirement : requirements) {
            if (requirement.equals(recipe)) {
                return false;
            }
            if (currentRecipes.contains(requirement)) {
                return false;
            }
        }
        currentRecipes.add(recipe);
        for (String requirement : requirements) {
            if (supplies.contains(requirement)) {
                continue;
            }
            else {

                if (canMakeRecipe(requirement, currentRecipes)) {
                    this.supplies.add(requirement);
                    continue;
                }
                else {
                    currentRecipes.remove(requirement);
                    return false;
                }
            }
        }
        this.supplies.add(recipe);
        this.achievedRecipes.add(recipe);
        return true;
    }
}
