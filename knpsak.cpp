#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    int weight;
    int profit;
    double ratio;
    int index;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    cout << "=== KNAPSACK PROBLEM MENGGUNAKAN GREEDY ALGORITHM ===" << endl;
    cout << "NIM: 23533780 (angka 0 diganti dengan 11)" << endl;
    cout << "Kapasitas maksimal knapsack: 15" << endl << endl;
    
   vector<Item> items = {
        {2, 20, 0, 1},   // Digit ke-1 = 2
        {3, 30, 0, 2},   // Digit ke-2 = 3
        {5, 50, 0, 3},   // Digit ke-3 = 5
        {3, 30, 0, 4},   // Digit ke-4 = 3
        {3, 30, 0, 5},   // Digit ke-5 = 3
        {7, 70, 0, 6},   // Digit ke-6 = 7
        {8, 80, 0, 7},   // Digit ke-7 = 8
        {11, 110, 0, 8}  // Digit ke-8 = 0 (diubah menjadi 11)
    };
    
    int capacity = 15;
    
    for (int i = 0; i < items.size(); i++) {
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    sort(items.begin(), items.end(), compare);
    
    cout << "Tabel item setelah diurutkan berdasarkan rasio profit/weight:" << endl;
    cout << "Objek\tWeight\tProfit\tRasio" << endl;
    cout << "------------------------------------" << endl;
    for (int i = 0; i < items.size(); i++) {
        cout << items[i].index << "\t" << items[i].weight << "\t" 
             << items[i].profit << "\t" << fixed << setprecision(3) 
             << items[i].ratio << endl;
    }
    
    cout << "\nProses Greedy:" << endl;
    cout << "===============" << endl;
    
    vector<int> selected;
    int totalWeight = 0;
    int totalProfit = 0;
    
    for (int i = 0; i < items.size(); i++) {
        if (totalWeight + items[i].weight <= capacity) {
            selected.push_back(items[i].index);
            totalWeight += items[i].weight;
            totalProfit += items[i].profit;
            
            cout << "Pilih objek " << items[i].index 
                 << " (weight=" << items[i].weight 
                 << ", profit=" << items[i].profit 
                 << ", rasio=" << fixed << setprecision(3) << items[i].ratio << ")" << endl;
            cout << "Total weight: " << totalWeight << "/" << capacity << endl;
            cout << "Total profit: " << totalProfit << endl << endl;
        } else {
            cout << "Objek " << items[i].index 
                 << " tidak dapat dimasukkan (weight=" << items[i].weight 
                 << ", sisa kapasitas=" << (capacity - totalWeight) << ")" << endl;
        }
    }
    
    cout << "HASIL AKHIR:" << endl;
    cout << "============" << endl;
    cout << "Objek yang dipilih: ";
    for (int i = 0; i < selected.size(); i++) {
        cout << selected[i];
        if (i < selected.size() - 1) cout << ", ";
    }
    cout << endl;
    cout << "Total weight: " << totalWeight << "/" << capacity << endl;
    cout << "Total profit: " << totalProfit << endl;
    cout << "Efisiensi: " << fixed << setprecision(2) 
         << (double)totalWeight / capacity * 100 << "%" << endl;
    
    return 0;
}
