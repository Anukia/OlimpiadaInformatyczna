#include <vector>
#include <algorithm>
#include <iostream>
#define MAX_N (1000000)

using namespace std;

vector<int> Tmax;
int Tmin[2*MAX_N];

int Maks(int p, int k) {
    int ret = -999999999;
    p+=MAX_N;
    k+=MAX_N;
    while(p<=k){
        if((p%2)==1) ret = max(ret, Tmin[p]);
        if((k%2)==0) ret = max(ret, Tmin[k]);
        p = (p+1)/2;
        k = (k-1)/2;
    }
    return ret;
}

int main() 
{
    ios_base::sync_with_stdio(false);    
    int n, tmp, result = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        Tmin[MAX_N + i] = tmp;
        cin >> tmp;
        Tmax.push_back(tmp);
    }

    for(int i=MAX_N-1; i>0; i--)
        Tmin[i] = max(Tmin[i*2], Tmin[i*2+1]);


    int j = 1;
    for(int i =0; i < n; i++)
    {
        while (j<n && Maks(i,j-1)<=Tmax[j])
        {
            j++;
        }
        result = max(result, j-i);
    }

    cout << result << "\n";
}