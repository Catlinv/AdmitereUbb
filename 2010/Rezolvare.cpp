#include <iostream>

using namespace std;

void citeste(int &n)
{
    ///Se citeste de la tastatura dimensiunea matricei patatice
    cin>>n;
}

bool isPrim(int nr)
{
    if (nr < 2)
        return 0;
    for (int d = 2; d*d <= nr; d++)
        if (nr % d == 0)
            return 0;
    return 1;
}

int elementPrimDeOrdinM(int m)
{
    if (m == 1)
        return 2;
    m--;
    int nr = 3;
    while (m > 0)
    {
        if (isPrim(nr))
            m--;
        nr+=2;
    }
    return nr - 2;
}


void formeazaMatrice(int n, int v[][100])
{
    ///Pune elementele sub diagonala
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            v[i][j] = i;
    ///Pune elementele peste diagonala
    int ordin_elem = 1;
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
        {
            v[i][j] = elementPrimDeOrdinM(ordin_elem);
            ordin_elem++;
        }
}


void afiseazaMatrice(int n, int v[][100])
{
    for (int i = 1; i <= n; i++,cout<<'\n')
        for (int j = 1; j <= n; j++)
            cout<<v[i][j]<<' ';
}



int main()
{
    int v[100][100];
    int n;
    citeste(n);
    formeazaMatrice(n,v);
    afiseazaMatrice(n,v);

    return 0;
}
