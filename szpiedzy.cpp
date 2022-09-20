#include <stdio.h>
#include <vector>

using namespace std;

#define MAX 1000000

int N;
int sledz[MAX];
char checked[MAX];
int sum[MAX];
vector<int> nieSledzeni;

int main(void)
{
  int spy, t, result;
  
  int a;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) 
  {
    scanf("%d", &a);
    sledz[i] = a - 1;
  }

  for (int i = 0; i < N; i++) sum[sledz[i]]++;

  for (int i = 0; i < N; i++)
    if (sum[i] == 0) 
        nieSledzeni.push_back(i);

  result = 0;
  while (!nieSledzeni.empty()) {
    spy = nieSledzeni.back();
    nieSledzeni.pop_back();

    if (checked[sledz[spy]] == 0) 
    {
      result++;
      checked[spy] = 1;
      checked[sledz[spy]] = 1;
      
      t = sledz[sledz[spy]];
      if (!checked[t] && --sum[t] == 0) nieSledzeni.push_back(t);
    }
  }

  for (int i = 0; i < N; i++)
    if (!checked[i]) {
      spy = i;
      while (!checked[spy] && !checked[sledz[spy]]) {
        result++;
        checked[spy] = 1;
        checked[sledz[spy]] = 1;
        spy = sledz[sledz[spy]];
      }
    }

  printf("%d\n", result);
}