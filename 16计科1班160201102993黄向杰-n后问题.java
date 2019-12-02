class Queen{
    friend int nQueen(int);
    private:
        bool Place(int k);
        void Backtrace(int t);
        int n,* x;
        long sum;
};

bool Queen::Place(int k)
{
    for(int j=1;j<k;j++)
        if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
            return false;
    return true;
}

void Queen::Backtrace(int t)
{
    if(t>n)
        sum++;
    else
        for(int i=1;i<=n;i++)
        {
            x[t]=i;
            if(Place(t))
                Backtrace(t+1);
        }
}

int nQueen(int n)
{
    Queen X;
    X.n = n;
    X.sum = 0;
    int * P = new int[n+1];
    for(int i=0;i<=n;i++)
        p[i]=0;
    X.x=p;
    X.Backtrace(1);
    delete[]p;
    return X.sum;
}