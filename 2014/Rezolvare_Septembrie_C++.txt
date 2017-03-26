#include <iostream>
#include <fstream>

using namespace std;

ifstream f("main.in");

void citireMatrice(int &n, int mat[][101])
{
    f>>n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f>>mat[i][j];
}

bool isPrim(int nr)
{
   for (int d = 2; d*d <= nr; d++)
        if (nr%d == 0)
            return false;
   return true;
}

int numarCifre(int nr)
{
    if (nr == 0)
        return 1;
    int s = 0;
    while (nr)
    {
        nr/=10;
        s++;
    }
    return s;
}

int putereZece(int nr)
{
    int e = 1;
    while (nr)
    {
        e*=10;
        nr--;
    }
    return e;
}

bool isSuperPrim(int nr)
{
    int permutare = nr;
    int e = putereZece(numarCifre(nr)-1);
    do{
        permutare = permutare/e+(permutare%e)*10;
        if (isPrim(permutare))
            return true;
    }while (permutare != nr);

    return false;
}

void intershimbareElemente(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

void interschimbareTriunghiSuperiorCuInferior(int n, int mat[][101])
{
    for (int i = 1; i <= n / 2; i++)
        for (int j = i+1; j <= n-i; j++)
            intershimbareElemente(mat[i][j],mat[n-i+1][j]);
}

void interschimbareTriunghiStangaCuDreapta(int n, int mat[][101])
{
    for (int j = 1; j <= n / 2; j++)
        for (int i = j+1; i <= n-j; i++)
            if (mat[i][j] != mat[i][n-j+1] && isSuperPrim(mat[i][j]) && isSuperPrim(mat[i][n-j+1]))
                intershimbareElemente(mat[i][j],mat[i][n-j+1]);
}

void rezolvare(int n, int mat[][101])
{
    interschimbareTriunghiSuperiorCuInferior(n,mat);
    interschimbareTriunghiStangaCuDreapta(n,mat);
}

void afisareMatrice(int n, int mat[][101])
{
    for (int i = 1; i <= n; i++,cout<<'\n')
        for (int  j = 1; j <= n; j++)
            cout<<mat[i][j]<<' ';
}

int main()
{
    int v[101];
    int mat[101][101];
    int n;
    int maxi = 0;
    citireMatrice(n, mat);
    rezolvare(n,mat);
    afisareMatrice(n,mat);
    return 0;
}
