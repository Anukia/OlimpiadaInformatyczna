#include <iostream>
#include <vector>

using namespace std;

const int MAXWAGA = 6500;

int n, m, tmp, minWaga = 6500;

int main()
{
    ios_base::sync_with_stdio(0);
	cin >> n;

    vector<int> wagi (n,0);
    vector<int> poczatkowo (n,0);
    vector<int> oczekiwane (n,0);
    vector<int> sprawdzone (n,0);

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
        wagi[i] = tmp;

		minWaga = min(minWaga, tmp);
	}    
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
        tmp--;
        poczatkowo[i] = tmp;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
        tmp--;
		oczekiwane[tmp] = poczatkowo[i]; //na miejscu słonia x stoi początkowo słoń[x]
	}

	long long wynik = 0;
	for (int i = 0; i < n; i++)
		if (!sprawdzone[i])
		{
			int minLokalne = 6500; 
			long long sumaWag = 0; 
			int slon = i;
			int nCykl = 0; 

			while(true) 
			{
				minLokalne = min(minLokalne, wagi[slon]);
				sumaWag += wagi[slon];
				slon = oczekiwane[slon];
				sprawdzone[slon] = true;
				nCykl++;
				if (slon == i)
					break;
			}

			wynik += min(sumaWag + (nCykl-2)*(long long)minLokalne, 
                        sumaWag + minLokalne + (nCykl +1 )*(long long)minWaga);
		}
	cout << wynik;
}