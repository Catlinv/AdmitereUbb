#include <iostream>
#include <fstream>
#include <cstring>
#include <bits/stdc++.h>
 
using namespace std;
 
ifstream f("graf.in");
 
void citireMatrice(int &n, int A[][51])
{///Citeste din fisier elementele matricei patratice A
    f>>n;
    for (int  i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f>>A[i][j];
}
 
void afisareSir(int n, int X[])
{///Afiseaza elementele sirului de numere X
    if (n == 0)
        cout<<"Sirul X este vid";
    else
        for (int i = 1; i <= n; i++)
            cout<<X[i]<<' ';
}
 
void mutareElementeLaDreapta(int &n, int X[], int poz)
{///Muta toate elementele incepand cu pozitia "poz" cu un element la dreapta
    n++;
    for (int i = n; i >= poz; i--)
        X[i] = X[i-1];
}
 
bool isPrim(int nr)
{///Verifica daca numarul este unul prim
    if (nr < 2)
        return false;
    for (int d = 2; d*d <= nr; d++)
        if (nr % d == 0)
            return false;
    return true;
}
 
bool isSuperPrim(int nr)
{///Ia la rand numarul si toate prefixele sale, verificand daca toate sunt prime
    do{
        if (!isPrim(nr))
            return false;
        nr/=10;
    }while(nr > 0);
    return true;
}
 
void inserareElementInSirDescrescator(int &n, int X[], int el)
{///Insereaza un element dat, "el", in sirul X ordonat descrescator astfel incat sa se pastreze ordonarea, evitand inserarea elementelor deja prezente in sir
 
    int ok = 0; ///Verifica daca am inserat elementul
    for (int i = 1; i <= n && ok == 0; i++)
    {
        if (el == X[i])
        {///Nu se insereaza elemente identice
            ok = 1;
        }
        else
            if (el > X[i])
            {
                ok = 1; ///Am terminat de inserat
                mutareElementeLaDreapta(n,X,i);
                X[i] = el;
            }
    }
    if (ok == 0)///Daca nu am inserat elementul in vector, atunci il inseram la final
    {
        n++;
        X[n] = el;
        ok = 1;
    }
}
 
void parcurgereTriunghiStang(int n, int A[][51], int &lungimeSir, int X[])
{///Parcurge toate elementele din triunghiul stang al matricei partatice A si insereaza elementele superprime in sirul X
    for (int j = 1; j <= n/2; j++)
        for (int i = j + 1; i <= n-j; i++)
            if (isSuperPrim(A[i][j]))
                inserareElementInSirDescrescator(lungimeSir,X,A[i][j]);
}
 
void parcurgereTriunghiDrept(int n, int A[][51], int &lungimeSir, int X[])
{///Parcurge toate elementele din triunghiul drept al matricei partatice A si insereaza elementele superprime in sirul X
    for (int j = 1; j <= n/2; j++)
        for (int i = j + 1; i <= n-j; i++)
            if (isSuperPrim(A[i][n-j+1]))
                inserareElementInSirDescrescator(lungimeSir,X,A[i][n-j+1]);
}
 
void construireSirX(int n, int A[][51], int &lungimeSir, int X[])
{///Construieste sirul X parcurgand triunghiul stang si cel drept al matricei patratice A, inserand in sir elementel superprime
    parcurgereTriunghiStang(n,A,lungimeSir,X);
    parcurgereTriunghiDrept(n,A,lungimeSir,X);
}
 
 
int main()
{
    int n, lungimeSir = 0;
    int A[51][51];
    int X[2501];
    citireMatrice(n,A);
    construireSirX(n,A,lungimeSir,X);
    afisareSir(lungimeSir,X);
    return 0;
}