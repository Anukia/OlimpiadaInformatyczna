#include <iostream>
#include <vector>
using namespace std;
constexpr int modulo = 1000000000;

int main()
{
    ios::sync_with_stdio(false);
    vector<char>c;
    int n;
    char temp;
    cin >> n;
    n--;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        c.push_back(temp);
    }
    if (c[0] == '+')
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        vector<long>w(n, 1);
        for (int i = 1; i < n - 1; i++)
        {
            if ((c[i] == '+') && (c[i + 1] == '-'))
            {
                for (int j = i + 1; j < n; j++)
                {
                    w[j] += w[j - 1];
                    w[j] %= modulo;
                }
            }
        }
        cout << w[n - 1] << endl;
        return 0;
    }
}
