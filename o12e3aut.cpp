#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int n, m, k;
const int MAXK = 100000;

struct przystanek {
  int x, y, p;                  
} przys[MAXK];                

bool kryt(przystanek a, przystanek b)
{
  return (a.x != b.x ? a.x < b.x : a.y < b.y);
}

map < int, int >mapa;          

void licz()
{
  sort(przys, przys + k, kryt); 
  mapa.insert(make_pair(0, 0)); 
  
  for (int i = 0; i < k; ++i) {
    map < int, int >::iterator it = mapa.upper_bound(przys[i].y);
    int ilu;
    ilu = (--it)->second + przys[i].p;
    ++it;
    while (it != mapa.end() && it->second < ilu) {
      mapa.erase(it++);
    }
    mapa[przys[i].y] = max(mapa[przys[i].y], ilu);
  }
  printf("%d\n", (--mapa.end())->second);
}

int main()
{
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; ++i)
    scanf("%d %d %d", &przys[i].x, &przys[i].y, &przys[i].p);  licz();
  return 0;
}
