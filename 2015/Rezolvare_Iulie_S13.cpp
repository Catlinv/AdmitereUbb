int cautareBinaraIterativ(int n, int A[], int v)
{
    int st = 1;
    int fr = n;
    int mij;
    while (st <= dr)
    {
        mij = (st+dr)/2;
        if (A[mij] == v)
            return mij;
        if (A[mij] > v)
            dr = mij;
        else
            st = mij;
    }
    return -1;
}

int cautareBinaraRecursiv(int n, int A[], int v, int st, int dr)
{
    if (st > dr)
        return -1;
    else
        if (A[(st+dr)/2] == v)
            return ((st+dr)/2);
        else
            if (A[(st+dr)/2] > v)
                return cautareBinaraRecursiv(n,A,v,st,(st+dr)/2);
            else
                return cautareBinaraRecursiv(n,A,v,(st+dr)/2,dr);
}