#include <iostream>
#include <math.h>
using namespace std;


// Function to checkif a given number is prime or not
int isprime(long long n)
{
	if(n==2)
		return 1;
	if(n<2||n%2==0)
		return 0;
	for(int i=3;i*i<=n;i=i+2)
	{
		if(!(n%i))
			return 0;
	}
	return 1;
}

int main() {
    
    long long a,b;
    int no_of_primes=0;
    int found,i;
    cin>>no_of_primes;
    long long primes[no_of_primes];
    
    for(i =0;i<no_of_primes; i++)
        cin>>primes[i];
        
    for(i=0;i<no_of_primes;i++)
    {
        int prime = primes[i];
        			
        if(!isprime(prime))
        {
            //cout <<"Number entered is not a prime number!!\n";
            continue;
        }
        
        
        // Check if the prime is of the form 3t+1
        if( (prime-1)%3 != 0)
        {
            //cout<<"Prime number is not of form 3t+1 \n";
            continue;
        }

        double num = sqrt(prime);
        found =0;
        a = floor(num);
        b = ceil(num);
        while( (a>=1) && (b<100000))
        {
            long long value = a*a+b*b-a*b;
       
            if(value == prime)
            {
                found = 1;
                break;
            }
            if(value < prime)
            {
                b=b+2;
            }
            else if(value > prime)
            {
                a=a-2;
            }
        }
    
        if(found)
        {
            cout<<prime<<" "<<a<<" "<<b<<"\n";
        }
    }
	return 0;
}