#include <iostream>
#include <fstream>

using namespace std;

ifstream f("main.in");

void adaugareDivizoriLaSir(int &i, int v[], int nr)
{
    for (int d = 2; d < nr; d++)
    {
        if (nr % d == 0)
        {
            v[i] = d;
            i++;
        }
    }
    i--;
}

void formareSir(int &n, int v[])
{
    f>>n;
    int nr = 1;
    for (int i = 1; i <= 2*n*n; i++)
    {
        v[i] = nr;
        i++;
        adaugareDivizoriLaSir(i,v,nr);
        nr++;
    }
}

int ultimaCifra(int nr)
{
    return nr%10;
}

int primaCifra(int nr)
{
    while (nr > 9)
        nr/=10;
    return nr;
}

int cifraMaxima(int nr)
{
    int maxi = 0;
    while (nr)
    {
        if (nr%10 > maxi)
            maxi = nr%10;
        nr/=10;
    }
    return maxi;
}

void formareParteSuperiara(int n, int v[], int mat[][101])
{
    for (int i = 1; i < n; i++)
    {
        int j = 1;
        int aux = i;
        while (j <= i)
        {
            mat[j][aux] = ultimaCifra(v[n*n+1+i]);
            aux--;
            j++;
        }
    }
}

void formareDiagonala(int n, int v[], int mat[][101])
{
    for (int i = 1; i <= n; i++)
        mat[i][n-i+1] = cifraMaxima(v[n*n+i*i]);
}

void formareParteInferioara(int n, int v[], int mat[][101])
{
    for (int i = 2; i <= n; i++)
    {
        int j = n;
        int aux = i;
        while (j >= i)
        {
            mat[aux][j] = primaCifra(v[n*n + i + n]);
            j--;
            aux++;
        }
    }
}

void formareMatrice(int n, int v[], int mat[][101])
{
    formareParteSuperiara(n,v,mat);
    formareDiagonala(n,v,mat);
    formareParteInferioara(n,v,mat);
}

void initializareFrecventa(int fr[], int n)
{
    for (int i = 0; i <= n; i++)
        fr[i] = 0;
}

int maximColoana(int n, int mat[][101], int j)
{
    int fr[10];
    initializareFrecventa(fr,9);
    for (int i = 1; i <= n; i++)
        fr[mat[i][j]]++;
    int maxim = 0;
    for (int i = 9; i >= 0; i--)
        while (fr[i])
        {
            maxim = maxim*10+i;
            fr[i]--;
        }
    return maxim;
}

void afisareMaxime(int n, int mat[][101])
{
    for (int j = 1; j <= n; j++)
        cout<<maximColoana(n,mat,j)<<' ';
}


int main()
{
    int v[101];
    int mat[101][101];
    int n;
    int maxi = 0;
    formareSir(n,v);
    formareMatrice(n,v,mat);
    afisareMaxime(n,mat);
    return 0;
}
