#include <iostream>
#include <fstream>

using namespace std;

ifstream f("main.in");

void citireMatrice(int &n, int &m, int A[][101])
{
    f>>n>>m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f>>A[i][j];
}

void formareSir(int n, int m, int A[][101], int v[], int &lungimeSir)
{
    lungimeSir = 0;
    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= n; i++)
            v[++lungimeSir] = A[i][j];
}

bool isPrim(int nr)
{
    if (nr < 2)
        return 0;
    for (int d = 2; d*d <= nr; d++)
        if (nr%d == 0)
            return 0;
    return 1;
}

bool isMagic(int n)
{
    do{
        if (!isPrim(n))
            return 0;
        n/=10;
    }while (n > 0);
    return 1;
}

void determinareSecventaMaxima(int n, int v[], int &inceputMax, int &lungimeMax)
{
    inceputMax = 0;
    lungimeMax = 0;
    int inceput = 1;
    int lungime = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isMagic(v[i]))
        {
            if (lungime == 0)
                inceput = i;
            lungime++;
        }
        else
        {
            if (lungime > lungimeMax)
            {
                lungimeMax = lungime;
                inceputMax = inceput;
            }
            lungime = 0;
        }
    }
}

void afisareSecventaMaxima(int v[],int inceput, int lungime)
{
    for (int i = inceput; i < inceput+lungime; i++)
        cout<<v[i]<<' ';
    if (lungime == 0)
        cout<<"Nu exista secventa";
}

int main()
{
    int n,m,lungimeSir;
    int inceput,lungime;
    int v[101][101];
    int A[10001];
    citireMatrice(n,m,v);
    formareSir(n,m,v,A,lungimeSir);
    determinareSecventaMaxima(lungimeSir,A,inceput,lungime);
    afisareSecventaMaxima(A,inceput,lungime);
    return 0;
}
