BigInteger quick_pow(BigInteger x,int N)
{
    //boundary condition
    if(x==0)
    {
        return 0;
    }
    if(x==1||N==0)
    {
        return 1;
    }
    //store x,x^2,x^4...until x^2^logN
    int n=log2(N);
    BigInteger arr[n+1];
    arr[0]=x;
 
    for (int i=1;i<=n;i++)
    {
        arr[i]=arr[i-1]*arr[i-1];
    }
 
    BigInteger result=1;
    int count=0;
    while(N!=1)//Calculating result according to the binary representation of N.
    {
        switch(N%2)
        {
        case 1:
            result*=arr[count];
            break;
        case 0:
            break;
        }
        count+=1;
        N>>=2;
    }
    result*=arr[count];
    return result;
}