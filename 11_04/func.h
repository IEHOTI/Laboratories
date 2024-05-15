#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void RandArr(int n, vector<int>& weights, vector<int>& values, int& W) {
    int w=0, v=0;
    for (int i = 0; i < n; i++) {
        int weight = rand() % 20 + 1; // генерация веса от 1 до 20
        int value = rand() % 50 + 1;  // генерация стоимости от 1 до 50
        w += weight;
        v += value;
        weights.push_back(weight);
        values.push_back(value);
    }
    W = rand() % (150-50+1) + 50; // генерация значения максимального веса от 50 до 200
    cout << "Сумма всех сгенерированных весов: " << w << " Сумма всех сгенерированных стоимостей: " << v << endl;
    if (n <= 10) {
        for (int i = 0; i < n; i++) {
            cout << "Позиция " << i << " Сгенерированный вес: " << weights[i] << " Сгенерированная стоимость: " << values[i] << endl;
        }
    }
}

int Greedy(int n, int W, vector<int>& weights, vector<int>& values) {
    // сортируем грузы по убыванию стоимости за вес
    vector<pair<double, int>> cost;
    for (int i = 0; i < n; i++) {
        cost.push_back({ (double)(values[i] / weights[i]), i });
    }
    sort(cost.rbegin(), cost.rend());
    int totalV = 0; // итоговое значение
    int currentW = 0; // текущий вес
    for (int i = 0; i < n; i++) {
        int k = cost[i].second;
        if (currentW + weights[k] <= W) {
            totalV += values[k];
            currentW += weights[k];
        }
    }

    return totalV;
}

int Dynamic(int n, int W, vector<int>& weights, vector<int>& values) {
    vector<int> MaxW(W + 1, 0); // хранение максимальной стоимости

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {
            MaxW[w] = max(MaxW[w], MaxW[w - weights[i]] + values[i]); // берется наибольшее значение
        }
    }
    return MaxW[W];
}
void bagBacktrack(vector<int>& weights, vector<int>& values, int W, int i, int current_weight, int current_value, int& max_value) {
    if (current_weight > W) {
        return;
    }
    if (i == weights.size()) {
        max_value = max(max_value, current_value);
        return;
    }
    // попробовать добавить текущий предмет
    bagBacktrack(weights, values, W, i + 1, current_weight + weights[i], current_value + values[i], max_value);
    // пропустить текущий предмет
    bagBacktrack(weights, values, W, i + 1, current_weight, current_value, max_value);
}
int Backtrack(vector<int>& weights, vector<int>& values, int W) {
    int max_value = 0;
    bagBacktrack(weights, values, W, 0, 0, 0, max_value);
    return max_value;
}