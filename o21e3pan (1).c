#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

static inline int sprawdzZgodnosc(int liczba, int przedzial_1, int przedzial_2) { 
    if(liczba == 0) return 0;
    if(ceil((double)przedzial_1 / liczba) <= przedzial_2 / liczba ) return 1;                  
    return 0;
}


void zapytanie() {
    int a,b,c,d; 
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int sqrtM = (int)sqrt(max(b, d));
    int odp = 1; 
    for(int i = 2; i < sqrtM; i++) { 
        if(sprawdzZgodnosc(i,a,b) && sprawdzZgodnosc(i,c,d)) odp = i;
    }

    for(int i = 1; i < sqrtM; i++) {
        int k = b/i;
        if(sprawdzZgodnosc(k,a,b) && sprawdzZgodnosc(k,c,d))
            odp = max(odp,k);
        k = d/i;
        if(sprawdzZgodnosc(k,a,b) && sprawdzZgodnosc(k,c,d))
            odp = max(odp,k);
    }
    printf("%d\n", odp);
}


int main() {
    int n; 
    scanf("%d",&n);
    for(int i = 0; i < n; i++) zapytanie();
}
