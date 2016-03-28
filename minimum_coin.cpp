#include <iostream>
using namespace std;
  
// INF to define a very large number
#define INF 9999 

/*
Function: min_coin_sum
Arguments:
int sum : The sum to be obtained from the given set of coins
int coin[]: set of coins to be used
int temp_count[] : set of number of times each coin must be used at least if that coin is used
eg if temp_count[i] =2, then we must use coin[i] atleast twice.
int n	: number of coins to be used
Returns:
min : Minimum number of coins used to obtain the Sum.
*/

int min_coin_sum(int sum,int coin[],int temp_count[],int n)
{
	int temp_min = INF;
	int min = INF;
	if(sum == 0)
		return 0;

	if(sum < 0)
		return INF;

	for(int j=0; j < n ; j++)
	{

		// if the coin is greater than the change to be obtained
		if(coin[j] > sum)
			continue;

		/*if the coin "a" has not been used "b" times before,
			use it "b" times */
		if(temp_count[j] != 0)
		{
			int temp_sum = sum - coin[j]*temp_count[j];
			if(temp_sum<0)
				continue;
			int temp_coin_count = temp_count[j];
			temp_count[j]=0;

			// recursively find minimum of new sum after using "a" coin "b" times
			temp_min = min_coin_sum(temp_sum,coin,temp_count,n)+temp_coin_count;
			temp_count[j]=temp_coin_count;
		}

		/* if the coin "a" has been used "b" times before,
			 use coin "a" once */
		else if(temp_count[j] == 0)
		{
			int temp_sum = sum - coin[j];
			if(temp_sum <0)
				continue;
			// recursively find minimum of new sum after using "a" once
			temp_min = min_coin_sum(temp_sum,coin,temp_count,n)+1;

		}
		min = min < temp_min? min : temp_min;
	}

	return min;
}

/*
Main:
*/
int main()
{

	int i,sum =0, n=0;
	int coin[10], count[10];

	// Minimum number of coins to get the sum initialised to INF
	int min = INF;

	cout<<"\n Enter the Sum to be Obtained:\n";
	cin>>sum;

	cout<<"\n Enter the number of denominations:\n";
	cin>>n;

	cout<<"\nEnter the coins to be used:\n";
	for( i =0 ; i < n ; i++)
	{
		cin>>coin[i];
	}
	cout<<"\n Enter the respective counts:\n ";
	for( i =0 ; i < n ; i++)
	{
		cin>>count[i];
	}

	min = min_coin_sum(sum,coin,count,n);

	// if minimum is Infinity , we haven't find a way to get minimum coins for the given num.
	if(min == INF)
		cout<<"\n No ways of getting the required sum with given denominations\n";
	else
		cout<<"\n Minimum number of coins required to get sum is :"<<min <<"\n";
} 
