#include <vector>
#include <iostream>

using namespace std;

int n, tmp;
vector<int> result;
vector<int> cakes;

void check(int pos)
{
    int next = pos % n + 1;
    int prev = (pos + n - 2) % n + 1;
    
    int nextValue = cakes[next] * (1 + (result[next] != next));
    int pozValue = cakes[pos] * (1 + (result[prev] == prev));
    
    if (nextValue < pozValue) 
    {
        result[pos] = pos;
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);    
    cin >> n;
    cakes.push_back(-1);
    result.push_back(-1);
    for(int i = 1; i <= n; i++)
    {
        cin >> tmp;
        cakes.push_back(tmp);
        result.push_back(i % n + 1);
    }

    for (int i = 0; i<2; i++)
    {
        for (int pos = 1; pos <= n; pos++) 
        {
            check(pos);
        }
    }
    for (int i = 0; i<2; i++)
    {
        for (int pos = n; pos >= 1; pos--) 
        {
            check(pos);
        }
    }


    for (int i = 1; i <= n; i++) 
    {
        if(i != 1)
            cout << " ";
        cout << result[i];
    }
}