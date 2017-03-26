#include <iostream>
#include <fstream>

using namespace std;

ifstream f("main.in");

void citesteSir(int &n, int v[])
{
    f>>n;
    for (int i = 1; i <= n; i++)
        f>>v[i];
}

void afisSir (int n, int v[], char numeSir)
{
    for (int i = 1; i <= n; i++)
        cout<<v[i]<<' ';
    if (n == 0)
        cout<<"Sirul "<<numeSir<<" e vid";
    cout<<'\n';
}

void makeFrec(int nr,int fr[])
{
    for (int i = 0; i <= 9; i++)
        fr[i] = 0;
    do{
        fr[nr%10] = 1;
        nr/=10;
    }while (nr != 0);
}

bool isSimilar(int a, int b)
{
    if (a == b)
        return true;
    int fa[10];
    int fb[10];
    makeFrec(a,fa);
    makeFrec(b,fb);
    for (int i = 0; i <= 9; i++)
        if (fa[i] != fb[i])
            return false;
    return true;

}

void eliminareEl(int &n, int v[], int poz)
{
    for (int i = poz; i < n; i++)
        v[i] = v[i+1];
    n--;
}

void eliminareElIdentice(int &n, int v[])
{
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
            if (v[i] == v[j])
            {
                eliminareEl(n,v,j);
                j--;
            }
}

void addElemToSir(int &n, int v[], int el)
{
    n++;
    v[n] = el;
}

void formareR(int &n, int v[], int R[], int &RSize)
{
    RSize = 0;
    for (int i = 1; i < n; i++)
    {
        int ok = 0;
        for (int j = i+1; j <= n; j++)
            if (isSimilar(v[i],v[j]))
            {
                addElemToSir(RSize,R,v[j]);
                ok = 1;
                eliminareEl(n,v,j);
                j--;
            }
        if (ok)
        {
            addElemToSir(RSize,R,v[i]);
            eliminareEl(n,v,i);
            i--;
        }
    }
    eliminareElIdentice(RSize,R);
}

int main()
{
    int v[101],y[101];
    int n,ySize;
    citesteSir(n,v);
    formareR(n,v,y,ySize);
    afisSir(n,v,'X');
    afisSir(ySize,y,'R');
    return 0;
}
