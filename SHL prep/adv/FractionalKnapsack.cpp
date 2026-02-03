#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Structure for an item which includes value and weight
struct Item {
    int value;
    int weight;
};

// Comparator to sort items by value/weight ratio
bool compareItems(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to solve Fractional Knapsack problem
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // 1. Sort items by value/weight ratio in descending order
    sort(items.begin(), items.end(), compareItems);

    double finalValue = 0.0;
    int currentWeight = 0;

    for (const auto& item : items) {
        if (currentWeight + item.weight <= capacity) {
            // Take the whole item
            currentWeight += item.weight;
            finalValue += item.value;
        } else {
            // Take fraction of the item
            int remaining = capacity - currentWeight;
            finalValue += item.value * ((double)remaining / item.weight);
            break; // Knapsack is full
        }
    }

    return finalValue;
}

int main() {
    int capacity = 50;
    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    cout << "Knapsack Capacity: " << capacity << endl;
    cout << "Items (Value, Weight):" << endl;
    for(const auto& item : items) {
        cout << "(" << item.value << ", " << item.weight << ")" << endl;
    }

    double maxValue = fractionalKnapsack(capacity, items);

    cout << fixed << setprecision(2);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
