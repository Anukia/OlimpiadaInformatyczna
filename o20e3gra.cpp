#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 500000;
vector<int> edges [MAXN], towers;
bool safe[MAXN + 1];
    
   int main()
   { 
        int n, m, k;
        std::ios_base::sync_with_stdio(0);
        cin >> n >> m >> k;

        int a, b;
        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        
        for (int i = 1; i <= n; i++)
        {
            if(safe[i])
                continue;
            towers.push_back(i);
            safe[i] = true;

            for (int j = 0; j < edges[i].size(); j++)
            {
                int city = edges[i][j];
                safe[city] = true;

                for (int k = 0; k < edges[city].size(); k++)
                {
                    int city2 = edges[city][k];
                    safe[city2] = true;
                }
            }
        }

        cout << towers.size() << "\n";
        for (int i = 0; i < towers.size(); i++)
            cout << towers[i] << " ";
   }