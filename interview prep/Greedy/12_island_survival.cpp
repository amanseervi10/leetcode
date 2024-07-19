int minimumDays(int S, int N, int M)
{
    if((N<M) || (S>6 && 6*N<7*M)) return -1;

    return ceil(S*M/double(N));
}