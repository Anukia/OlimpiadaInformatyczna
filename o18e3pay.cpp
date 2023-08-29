#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct patyczek
{
	int dlugosc; 
	char kolor;
};
bool operator<(const patyczek &a, const patyczek &b)
{
	return a.dlugosc < b.dlugosc;//if(a.dlugosc != b.dlugosc) return a.dlugosc < b.dlugosc;
	//return a.kol < b.kol;
}

void sprawdz(int i);
void popraw(int i);

vector <patyczek> patyczki;
int total, k, m;
patyczek result[3];
patyczek p;

int main()
{
    ios_base::sync_with_stdio(0);
	cin >> k;

	for(int i = 0; i < k; i++)
    {
		cin >> m;

		p.kolor = i + 1;
        total += m;
		for(int j = 0; j < m; j++)
        {
			cin >> p.dlugosc;
			patyczki.push_back(p);
		}
	}

    sort(patyczki.begin(), patyczki.end()); 
	
    for(int i = 0; i < 3; i++)
    {
		result[i].kolor = -i;
		result[i].dlugosc = -1;
	}

    for(int i = 0; i < total; i++)
    {
		sprawdz(i);
		popraw(i);
	}

    cout << "NIE\n";
}

void sprawdz(int i)
{ 
	int p1, p2;
	p1 = 1;
	p2 = 2; 

	if(result[1].kolor == patyczki[i].kolor) 
        p1 = 0;
	if(result[2].kolor == patyczki[i].kolor)
        p2 = 0;

	if(result[p1].dlugosc + result[p2].dlugosc > patyczki[i].dlugosc)
    {
		cout << (int)patyczki[i].kolor << " " << patyczki[i].dlugosc << " " 
        << (int)result[p1].kolor << " " << result[p1].dlugosc << " " 
        << (int)result[p2].kolor << " " << result[p2].dlugosc << endl;
		
        exit(0);
	}
}

void popraw(int i)
{
	int pw = 0;
	
    if(result[1].kolor == patyczki[i].kolor) pw = 1;
	if(result[2].kolor == patyczki[i].kolor) pw = 2;
	
    result[pw] = patyczki[i];
	
    sort(result, result+3);
}
