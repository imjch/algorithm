BigInteger pow(BigInteger x,int N)
{
    if (N==1){
         return x;
    }
    if (N==0){
         return 1;
    }
    if (N%2==0) {
         return pow(x*x,N>>=2);
    }
    else {
         return x*pow(x*x, N>>=/2);
    }
}

