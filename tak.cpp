#include <algorithm>
#include <iostream>

#define MAX_N 500001

using namespace std;

int n;
long long m, d;
long long taxi[MAX_N];

int findTaxi()
{
    if (taxi[0] < m-d)
        return 0;
    
    int k = 0;
    while(k+1 < n && taxi[k+1] >= m-d) k++;
    
    long long lastTaxt = taxi[k];
    while(k+1 < n)
    {
        taxi[k] = taxi[k+1];
        k++;
    }
    n--;

    long long position = 0;
    for(int i=0; i<n; i++)
    {
        if(2*(d - position) + m - d <= lastTaxt) return i+1;
        
        if(d - position > taxi[i]) return 0;
        
        position += (taxi[i] - (d - position));
        
        if(position >= m) return i+1;
        
        if(position > d) position = d;
    }
    if(2*(d - position) + m - d <= lastTaxt) return n+1;
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m;
    cin >> d;
    cin >> n;
    
    for(int i=0; i<n; i++) cin >> taxi[i];
    
    sort(taxi, taxi + n, greater<long long>());

    int result = findTaxi();

    cout << result << "\n";
}