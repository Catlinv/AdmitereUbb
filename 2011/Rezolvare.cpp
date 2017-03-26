#include <iostream>

using namespace std;

void citesteSir(int &n, int v[])
{
    int x;
    n = 1;
    do{
        cin>>x;
        v[n] = x;
        n++;
    }while (x != 0);
    n-=2;
}

int inversulNumarului(int n)
{
    int nn = 0;
    while (n)
    {
        nn= nn*10+n%10;
        n/=10;
    }
    return nn;
}

bool isPalindrom(int n)
{
    return (n == inversulNumarului(n));
}

void sortareDesc(int n, int v[])
{
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
            if (v[i] < v[j])
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}

void afisSir (int n, int v[])
{
    for (int i = 1; i <= n; i++)
        cout<<v[i]<<' ';
    if (n == 0)
        cout<<"Sirul Y e vid";
}

void formareY(int n, int v[], int y[], int &ySize)
{
    if (isPalindrom(v[1]))
    {
        ySize++;
        y[ySize] = v[1];
    }
    for (int i = 2; i <= n; i++)
        if (v[i] != v[i-1])
            if (isPalindrom(v[i]))
            {
                ySize++;
                y[ySize] = v[i];
            }
}


int main()
{
    int v[101],y[101];
    int n,ySize = 0;
    citesteSir(n,v);
    sortareDesc(n,v);
    formareY(n,v,y,ySize);
    afisSir(ySize,y);
    return 0;
}
