#include <iostream>
#include <fstream>

using namespace std;

ifstream f("main.in");

void citireSir(int &n, int v[])
{
    f>>n;
    for (int i = 1; i <= n; i++)
            f>>v[i];
}

bool isPrefix(int nr, int prefix)
{
    while (nr > prefix)
    {
        nr/=10;
        if (nr == prefix)
            return true;
    }
    return false;
}

void determinareSecventaMaxima(int n, int v[], int &inceputMax, int &lungimeMax)
{
    inceputMax = 0;
    lungimeMax = 0;
    int inceput = 1;
    int lungime = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isPrefix(v[i],v[i-1]))
        {
            if (lungime == 0)
                inceput = i-1;
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
    if (lungime == 0)
        cout<<"Secventa este vida";
    else
        for (int i = inceput; i <= inceput+lungime; i++)
            cout<<v[i]<<' ';
}

int main()
{
    int n;
    int inceput,lungime;
    int v[101];
    citireSir(n,v);
    determinareSecventaMaxima(n,v,inceput,lungime);
    afisareSecventaMaxima(v,inceput,lungime);
    return 0;
}
