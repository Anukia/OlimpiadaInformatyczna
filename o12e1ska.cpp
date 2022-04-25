#include <vector>
#include <iostream>

#define MAX_N 1000001

using namespace std;



int main() {
    int key[MAX_N] {0};
    int checked[MAX_N] {0};
    int n, tmp, result = 0;

    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        key[i] = tmp;
    }

    for (int i = 1; i <=n; i++)
    {
        int j = i;
        while (checked[j] == 0)
        {
            checked[j] = i;
            j = key[j];
        }

        if (checked[j] == i) 
        {
            result++;
        }
    }
    cout << result;
}