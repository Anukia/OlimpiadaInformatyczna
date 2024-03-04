#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int PMAXM; 
static inline int czy_liczba_jest_w_przedziale(int liczba, int przedzial_1, int przedzial_2) { 
    if(liczba == 0) return 0;
    if(przedzial_1 / liczba != przedzial_2 / liczba ) return 1; 
    if(przedzial_1 % liczba == 0) return 1;                    
    return 0;
}


void zapytanie() {
    int a,b,c,d; 
    scanf("%d%d%d%d",&a,&b,&c,&d);
    PMAXM = (int)sqrt(max(b, d)) + 5;
    int odp = 1; 
    for(int i = 2; i < PMAXM; i++) { 
        if(czy_liczba_jest_w_przedziale(i,a,b) && czy_liczba_jest_w_przedziale(i,c,d) ) odp = i;
    }

    for(int t = 1; t < PMAXM; t++) {
        int kan = b/t;
        if(czy_liczba_jest_w_przedziale(kan,a,b) && czy_liczba_jest_w_przedziale(kan,c,d))
            odp = max(odp,kan);
        kan = d/t;
        if(czy_liczba_jest_w_przedziale(kan,a,b) && czy_liczba_jest_w_przedziale(kan,c,d))
            odp = max(odp,kan);
    }
    printf("%d\n", odp);
}


int main() {
    int n; 
    scanf("%d",&n);
    for(int i = 0; i < n; i++) zapytanie();
}
