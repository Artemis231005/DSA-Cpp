#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Item {
public:
    int price, weight;
};

bool comp(Item &a, Item &b) {
    return (double)a.price/a.weight > (double)b.price/b.weight;
}

double maxValue(vector<Item> items, int n, int w) {
    sort(items.begin(), items.end(), comp);
    double totalValue = 0;

    for (int i=0; i<n; i++) {
        if (items[i].weight <= w) {
            totalValue += items[i].price;
            w -= items[i].weight;
        } else {
            totalValue += (((double)(items[i].price) / ((double)items[i].weight)) * w);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, m, p, w, we;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> items;

    cout << "Enter price and weight: ";
    for (int i=0; i<n; i++) {
        cin >> p >> we;
        items.push_back({p, we});
    }

    cout << "Enter weight of the bag: ";
    cin >> w;

    cout << "The maximum total value that can be placed in the bag is: " << maxValue(items, n, w);
    return 0;
}