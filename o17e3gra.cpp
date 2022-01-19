#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, tmp;
    vector <int> cards;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >>  tmp;
        cards.push_back(tmp);
    }

    sort(cards.begin(), cards.end());

    int result = cards[0];

    for(int i = 1; i<n; i++) {
        result = max(result, cards[i] - result);
    }
    cout << result<<"\n";
}