#include <iostream>
#include <fstream>

using namespace std;

ifstream f("main.in");

void citesteSir(int &n, int v[])
{
    f>>n;
    for (int i = 1; i <= n; i++)
    {
        f>>v[i];
    }
}

void afisSir (int n, int v[], char numeSir)
{
    for (int i = 1; i <= n; i++)
        cout<<v[i]<<' ';
    if (n == 0)
        cout<<"Sirul "<<numeSir<<" e vid";
}

bool isPrim(int nr)
{
    if (nr < 2)
        return 0;
    for (int d = 2; d*d <= nr; d++)
        if (nr %d == 0)
            return 0;
    return 1;
}

int maximSir(int n, int v[])
{
    int maxi = 0;
    for (int i = 1; i <= n; i++)
        if (maxi < v[i])
            maxi = v[i];
    return maxi;
}

void addToSir(int &n, int v[], int nou)
{
    n++;
    v[n] = nou;
}

void formareY(int n, int v[], int &ySize, int Y[])
{
    ySize = 0;
    int maxi = maximSir(n,v);
    //cout<<maxi;
    for (int d = 2; d <= maxi; d++)
    {
        if (isPrim(d))
        {
            for (int i = 1; i <= n; i++)
                if (v[i] % d == 0 && (v[i]/d)%d != 0)
                {
                    addToSir(ySize,Y,d);
                    i = n;
                }
        }
    }
}

int main()
{
    int v[101];
    int y[101];
    int n,ySize;
    int maxi = 0;
    citesteSir(n,v);
    formareY(n,v,ySize,y);
    afisSir(ySize,y,'Y');
    return 0;
}
