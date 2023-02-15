#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, tmp;
    ios_base::sync_with_stdio(false);
    vector<int> distances;

    cin >> n;
   
   int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        sum += tmp;
        distances.push_back(tmp);
    }

    int halfSum = sum / 2;
    int minDiff = sum;

    int actualSum = 0, x, y;
    while (y < n && x < n)
    {
        if(actualSum < halfSum)
        {
            actualSum += distances[y];
            y++;
        }
        else
        {
            actualSum -= distances[x];
            x++;
        }

        int tmp = abs(halfSum - actualSum);
        if (tmp < minDiff) minDiff = tmp;
    }
    cout << halfSum - minDiff;
}