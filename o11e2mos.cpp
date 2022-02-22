#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int n, t1, t2, tx, ty, counter, result;
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    cin >> t1;
    result = t1;

    if (n >= 2) {
        cin >> t2;
        result = t2;
        counter = 2;

        if (n%2 == 1) {
            cin >> tx;
            result += tx + t1 ;
            counter++;
        }

        while (counter < n) {
            cin >> tx;
            cin >> ty;
            
            if (tx + t1 <= t2 + t2) result += tx + ty + 2*t1; //szybszy lata
            else result += ty+ 2*t2 + t1; //dziadki idom 

            counter += 2;
        }
    }

    cout << result << "\n";
}