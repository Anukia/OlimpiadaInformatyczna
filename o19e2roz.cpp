#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int p;
    vector <long long> fibonacci;
    ios_base::sync_with_stdio(false);
    
    fibonacci.push_back(1);
    fibonacci.push_back(1);

    for (int i = 2; i < 90; i++) {
        fibonacci.push_back(fibonacci[i-1] + fibonacci[i-2]);
    }

    cin >> p;
    
    for(int i=0; i<p; i++) {
        long long k;
        int result = 0;

        cin >> k;

        while (k > 0)
        {
            long long tmp = k;
            for(int j = 0; j < 90; j++) {
                tmp = min(tmp,  abs(k-fibonacci[j]));
            }

            k = tmp;
            result++;
        }

        cout << result<< "\n";
    }
}