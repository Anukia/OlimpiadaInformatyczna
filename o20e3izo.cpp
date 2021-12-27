#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, izo;
    int result = 0;
    int izot[10000] = { 0 };
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> izo;

        result += izo;
        izot[izo]++;

    }

    int index = 0;

    for (int i = 0; i < n; i++) {
        while (izot[index] == 0) index++;
        if (2*(i + 1) > n + 1) {
            result += index;
            izot[index]--;
        }
        else if (2 * (i + 1) < n + 1) {
            result -= index;
            izot[index]--;
        }
        else {
            izot[index]--;
        }
    }

    cout << result;
}