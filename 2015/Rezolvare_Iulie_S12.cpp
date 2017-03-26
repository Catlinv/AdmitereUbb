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

int permutareMaxima(int n)
{
    int maxim = n;
    int e = putereZece(numarCifre(n) - 1);
    int permutare = n;
    do{
        permutare = permutare/e + (permutare%e)*10;
        if (permutare > maxim)
            maxim = permutare;
    }while (permutare != n);

    return maxim;
}