#include <vector>
#include <iostream>

using namespace std;

int main () {
    int n, trash, height;
    int result = 0;
    vector <int> stack;
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> trash;
        cin >> height;

        while(stack.empty() == false && height < stack.back()) {
            stack.pop_back();
        }

        if(stack.empty() == true || height > stack.back()) {
            stack.push_back(height);
            result++;
        }
    }

    cout << result;
}