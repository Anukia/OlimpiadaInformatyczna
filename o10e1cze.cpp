#include <iostream>

using namespace std;
#define MAX_N 1001

int main()
{
    int pionowe[MAX_N] = { 0 }, poziome[MAX_N] = { 0 };
    int n, m, tmp, lpionowo = 0, lpoziomo = 0, wynik = 0;

    cin >> n;
    cin >> m;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> tmp;
        pionowe[tmp]++;
    }

    for (int i = 0; i < m - 1; i++)
    {
        cin >> tmp;
        poziome[tmp]++;
    }

    for (int koszt = MAX_N - 1; koszt > 0; koszt--)
    {
        wynik += (lpoziomo + 1) * pionowe[koszt] * koszt;
        lpionowo += pionowe[koszt];

        wynik += (lpionowo + 1) * poziome[koszt] * koszt;
        lpoziomo += poziome[koszt];
    }

    cout << wynik << "\n";
}