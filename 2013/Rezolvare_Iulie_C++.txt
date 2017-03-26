#include <iostream>
#include <fstream>

using namespace std;

ifstream f("main.in");

struct Sir{
    int el;
    int fr;
};


void citesteSir(int &n, int v[])
{
    n = 0;
    do{
        n++;
        f>>v[n];
    }while (v[n] != 0);
    n--;
}

void afisSir (int n, Sir v[], char numeSir)
{
    for (int i = 1; i <= n; i++)
        cout<<v[i].el<<' '<<v[i].fr<<'\n';
    if (n == 0)
        cout<<"Sirul "<<numeSir<<" e vid";
    cout<<'\n';
}

int sumaCifra(int nr)
{
    int s = 0;
    while (nr)
    {
        s+=nr%10;
        nr/=10;
    }
    return s;
}

bool isPrim(int nr)
{
    if (nr < 2)
        return false;
    for (int d = 2; d*d < nr; d++)
        if (nr % d == 0)
            return false;
    return true;
}

void addEl(int &n, Sir Y[], int nou)
{
    int prezent = 0;
    for (int i = 1; i <= n; i++)
        if (Y[i].el == nou)
        {
            prezent = 1;
            Y[i].fr++;
        }
    if (!prezent)
    {
        n++;
        Y[n].el = nou;
        Y[n].fr = 1;
    }
}

void sortareCresc(int n, Sir v[])
{
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
            if (v[i].el > v[j].el)
            {
                Sir aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}

void formareY(int n, int v[], int &ySize, Sir Y[])
{
    ySize = 0;
    for (int i = 1; i<= n; i++)
        if (isPrim(sumaCifra(v[i])))
            addEl(ySize,Y,v[i]);
    sortareCresc(ySize,Y);
}


int main()
{
    int v[101];
    Sir y[101];
    int n,ySize;
    citesteSir(n,v);
    formareY(n,v,ySize,y);
    afisSir(ySize,y,'Y');
    return 0;
}
