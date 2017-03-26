void salvareMaximLinie(int i, int n, int A[][101])
{
    int maxim = A[i][1];
    for (int  j = 1; j <= n; j++)
        if (A[i][j] > maxim)
            maxim = A[i][j];
    A[i][n+1] = maxim;
}

void salvareMinimLinie(int i, int n, int A[][101])
{
    int minim = A[i][1];
    for (int  j = 1; j <= n; j++)
        if (A[i][j] < minim)
            minim = A[i][j];
    A[i][0] = minim;
}

void salvareMaximColoana(int m, int j, int A[][101])
{
    int maxim = A[1][j];
    for (int  i = 1; i <= m; i++)
        if (A[i][j] > maxim)
            maxim = A[i][j];
    A[m+1][j] = maxim;
}

void salvareMinimColoana(int m, int j, int A[][101])
{
    int minim = A[1][j];
    for (int  i = 1; i <= m; i++)
        if (A[i][j] < minim)
            minim = A[i][j];
    A[0][j] = minim;
}

bool isSa(int m, int n, int A[][101], int i, int j)
{
    if (A[i][j] == A[0][j] && A[i][j] == A[i][n+1])
        return true;
    if (A[i][j] == A[m+1][j] && A[i][j] == A[i][0])
        return true;
    return false;
}

int numarElementeSa(int m, int n, int A[][101])
{
    int numarElemente = 0;
    for (int i = 1; i <= m; i++)
    {
        salvareMaximLinie(i,n,A);
        salvareMinimLinie(i,n,A);
    }
    for (int j = 1; j <= n; j++)
    {
        salvareMaximColoana(m,j,A);
        salvareMinimColoana(m,j,A);
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (isSa(m,n,A,i,j))
                numarElemente++;
    return numarElemente;
}