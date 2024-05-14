#include <cstdio>
#include <algorithm>
using namespace std;

constexpr int N = 1001, INF = 2000000007, M = 1000000;



int main()
{
  int liczbaParTablic, liczbaWierszy, liczbaKolumn;
  int tab[2][N][N], tmp[2*M+1];
  pair<int,int> wartoscMinimalnaNumerWiersza[2][N];

  scanf("%d",&liczbaParTablic);

  for(int numerParyTablic=1; numerParyTablic <= liczbaParTablic; numerParyTablic++)
  {
    scanf("%d %d", &liczbaWierszy, &liczbaKolumn);
    for(int numerTablicyWParze = 0; numerTablicyWParze < 2; numerTablicyWParze++)
    {
      for(int i = 0; i < liczbaWierszy; i++){
        int minimalnyElementWiersza = INF;
        for(int j = 0; j < liczbaKolumn; j++){ 
          scanf("%d", &tab[numerTablicyWParze][i][j]);
          tab[numerTablicyWParze][i][j] += M;
          minimalnyElementWiersza = min(minimalnyElementWiersza,tab[numerTablicyWParze][i][j]);
        }
        wartoscMinimalnaNumerWiersza[numerTablicyWParze][i] = make_pair(minimalnyElementWiersza, i);
      }
      sort(wartoscMinimalnaNumerWiersza[numerTablicyWParze],wartoscMinimalnaNumerWiersza[numerTablicyWParze]+liczbaWierszy);
    }
    bool czyPodobne = true;
    for(int i=0; i<liczbaWierszy; i++)
      if(wartoscMinimalnaNumerWiersza[0][i].first != wartoscMinimalnaNumerWiersza[1][i].first)
      {
        czyPodobne = false;
        break;
      }
    if(!czyPodobne){
      printf("NIE\n");
      continue;
    }

    int numerWierszaTab1 = wartoscMinimalnaNumerWiersza[0][0].second, numerWierszaTab2 = wartoscMinimalnaNumerWiersza[1][0].second, numerOdpowiadajacejKolumny[N];
    for(int i=0; i<liczbaKolumn; i++)
      tmp[tab[1][numerWierszaTab2][i]] = numerParyTablic*N+i;
    for(int i=0; i<liczbaKolumn; i++){
      int a = tmp[tab[0][numerWierszaTab1][i]];
      if(a<numerParyTablic*N){
        czyPodobne=false;
        break;
      }
      a %= N;
      numerOdpowiadajacejKolumny[i] = a;
    }
    if(!czyPodobne){
      printf("NIE\n");
      continue;
    }
    for(int i=1; i<liczbaWierszy && czyPodobne; i++){
      numerWierszaTab1 = wartoscMinimalnaNumerWiersza[0][i].second;
      numerWierszaTab2 = wartoscMinimalnaNumerWiersza[1][i].second;
      for(int j=0;j<liczbaKolumn;j++)
        if(tab[0][numerWierszaTab1][j] != tab[1][numerWierszaTab2][numerOdpowiadajacejKolumny[j]]){
          czyPodobne = false;
          break;
        }
    }
    if(!czyPodobne)
      printf("NIE\n");
    else
      printf("TAK\n");
  }
  return 0;
}

