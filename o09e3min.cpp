#include <iostream>

using namespace std;



int main()
{
    int n;
    char last, next;
    ios_base::sync_with_stdio(false);

    cin >> n;
    cin >> last;

    cout << last;
    for (int i=1; i<n-1; i++)
    {
        cin >> next;

        if (last != next)
        {
            if (last == '-')
                cout << '(';
            else
                cout << ')';
        }

        cout << '-';

        last = next;
    }

    if (last=='+')
        cout << ')';
}