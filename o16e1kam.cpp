#include <vector>
#include <iostream>

using namespace std;

int main () {
    int u, tmp;
    ios_base::sync_with_stdio(false);
    
    cin >> u;
    
    for(int i=0; i<u; i++) {
        int n;
        int result = 0;
        vector <int> stone;
        vector <int> stoneDiff;

        cin >> n;

        for(int j=0; j<n; j++) {
            cin >> tmp;
            stone.push_back(tmp);
        }

        for(int j=0; j<n-1; j++) {
            stoneDiff.push_back(stone[n-j-1] - stone[n-j-2]);
        }

        stoneDiff.push_back(stone[0]);

        for(int j = 0; j<n; j+=2) {
            result ^= stoneDiff[j];
        }

        if(result) cout << "TAK" << "\n";
        else cout << "NIE" << "\n";
    }
}