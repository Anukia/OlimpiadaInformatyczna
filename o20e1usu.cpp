#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 1000000;

int stos[MAXN+1];
int suma[MAXN+1];
int wynik[MAXN+1]; 
int w; 

int main()
{
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    int counter = 0;

    for(int i = 1; i <= n; i++)
    {
        char tmp;
        cin >> tmp;
        
        int value = tmp == 'b' ? 1 : -k;
    
        counter++;
        stos[counter] = i;
        suma[counter] = suma[counter-1] + value;

        if(counter >= k + 1 && suma[counter] - suma[counter - k - 1] == 0) 
        {
            for(int j = 0; j < k + 1; j++)
                wynik[w++] = stos[counter--];
        }
    }

    for(int i=0; i<n/(k+1); ++i)
    {
        for(int j=0; j<k+1; ++j)
            cout << wynik[--w] << ' ';
        cout << "\n";
    }
}