/*
Problem Statement:
A,B and C(three brothers) want to open a lemonade stall so that they can earn their pocket money. However, their father being a
skinflint miser has refused to invest a single dime in their business. They started discussing alternative ways of obtaining the
necessary capital.'A' tells that he heard his uncle discussing the safety scheme of his father's new piggy bank. The piggy bank 
has two locks which need to be supplied with positive numbers a and b with a < b which satisfy the condition a^ 2 + b^2- ab = the
number on the safe.
'B' knows that his uncle issued a book on prime numbers from a Library and checking with the book finds that the number on the safeis prime. He also finds out from the book that only primes of the form 3t+1 can be written in this form. Now it is up to you to 
help 'C'to put a and b together and crack the safe to start the lemonade business.
Input Format:
Number of primes
<List of Primes>
The primes can have at most 10 digits.
Output Format:
Number on the safe and Numbers a b
*/


//Solution


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

		// Picking numbers whose perfect squares are just less and just greater than N.
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

			// If value is less than prime number, increase the range on the right side by incrementing b by 2
			if(value < prime)
			{
				b=b+2;
			}

			// If value is greater than prime number, decrease the range on the left side by decrementing a  by 2
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
