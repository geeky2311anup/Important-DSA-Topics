#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> available(supplies.begin(), supplies.end());
        queue<int> recipeQueue;
        vector<string> createdRecipes;
        int lastSize = -1;

        
        for (int i = 0; i < recipes.size(); i++) {
            recipeQueue.push(i);
        }

        
        while ((int)available.size() > lastSize) {
            lastSize = available.size();
            int queueSize = recipeQueue.size();

            for (int i = 0; i < queueSize; i++) {
                int recipeIdx = recipeQueue.front();
                recipeQueue.pop();

                if (canBeCreated(ingredients[recipeIdx], available)) {
                    available.insert(recipes[recipeIdx]);
                    createdRecipes.push_back(recipes[recipeIdx]);
                } else {
                    recipeQueue.push(recipeIdx);
                }
            }
        }
        return createdRecipes;
    }

private:
   
    bool canBeCreated(vector<string>& ingredientList, unordered_set<string>& available) {
        for (const string& ingredient : ingredientList) {
            if (available.find(ingredient) == available.end()) {
                return false;
            }
        }
        return true;
    }
};