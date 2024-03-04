#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1000001;

vector<int> adj[MAXN];
bool visited[MAXN];

int Check(int u, int k) {
    int sumTree = 0;
    visited[u] = true;
    for (int i = 0; i < (int)adj[u].size(); i++)
        if (!visited[adj[u][i]]) {
            sumTree += Check(adj[u][i], k) + 1;
        }

    return max(0, sumTree-k);
}

int main() {
    int N, wynikowaLiczbaEkip = 0, wystarczajacaLiczbaEkip;

    scanf("%d", &N);
    
    for (int i = 0; i < N-1; i++) {
        int u, v;

        scanf("%d%d", &u, &v);
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    wystarczajacaLiczbaEkip = N;

    while (wynikowaLiczbaEkip < wystarczajacaLiczbaEkip) {
        int sprawdzanaLiczbaEkip = (wynikowaLiczbaEkip+wystarczajacaLiczbaEkip)/2;

        fill(visited, visited+N, false);

        if (Check(0, sprawdzanaLiczbaEkip) == 0)
            wystarczajacaLiczbaEkip = sprawdzanaLiczbaEkip;
        else
            wynikowaLiczbaEkip = sprawdzanaLiczbaEkip+1;
    }

    printf("%d\n", wynikowaLiczbaEkip);

    return 0;
}
