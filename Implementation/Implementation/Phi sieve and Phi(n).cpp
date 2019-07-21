#include<bits/stdc++.h>
using namespace std;


// Computes and prints totien of all numbers
// smaller than or equal to n.
void computeTotient(int n)
{
    // Create and initialize an array to store
    // phi or totient values
    long long phi[n+1];
    for (int i=1; i<=n; i++)
        phi[i] = i; // indicates not evaluated yet
                    // and initializes for product
                    // formula.
 
    // Compute other Phi values
    for (int p=2; p<=n; p++)
    {
        // If phi[p] is not computed already,
        // then number p is prime
        if (phi[p] == p)
        {
            // Phi of a prime number p is
            // always equal to p-1.
            phi[p] = p-1;
 
            // Update phi values of all
            // multiples of p
            for (int i = 2*p; i<=n; i += p)
            {
               // Add contribution of p to its
               // multiple i by multiplying with
               // (1 - 1/p)
               phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }
 
    // Print precomputed phi values
    for (int i=1; i<=n; i++)
      cout << "Totient of " << i << " is "
           << phi[i] << endl;
}

int phi(int n)
{    
    int result = n;   // Initialize result as n
 
    // Consider all prime factors of n and subtract their
    // multiples from result
    for (int p=2; p*p<=n; ++p)
    {
        // Check if p is a prime factor.
        if (n % p == 0)
        {
            // If yes, then update n and result 
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
 
    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
    return result;
}

int main()
{
    int n;
    for (n=1; n<=10; n++)
      printf("phi(%d) = %d\n", n, phi(n));
     computeTotient(12);
    return 0;
}