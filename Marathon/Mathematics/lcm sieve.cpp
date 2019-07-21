
// lcm[n]=lcm(1,2,3,....n);
int primeflag[maxn];
ll lcm[maxn];
void lcm_sieve()
{
    fill(lcm,lcm+maxn,1LL);
    
    for(ll i=2;i<=maxn;i++)
    {
        if(!primeflag[i])
        {
            for(ll j=i*i;j<maxn;j+=i)
            {
                primeflag[j]=1;
            }
            ll t=i;
            while(t<maxn)
            {
                lcm[t]=i;
                t*=i;
            }
        }
    }
    for(int i=2;i<maxn;i++)
    {
        lcm[i]=(lcm[i-1]*lcm[i])%mod;
    }
}
