/*YADANDLA ANUSHA 
  BACKEND ASSIGNMENT
AIM : To find number of possible bit string (either 0 or 1) of length n which don't have two contiguous zeroes in them */

/* 1 -> [0,1] = 2
   2 -> [01,11,10] = 3
   3 -> [011,111,101,010,110] = 5
As we observe it is the fibonacci number series 
So computing the fibonacci number in O(logn) time is needed */ 
#include<iostream>
#include<algorithm>

using namespace std;
void multiply(unsigned long long int[2][2],int[2][2]);
void prod(unsigned long long int);
unsigned long long int num = 1000000007;
unsigned long long int matrix[2][2] = {{1,1},{1,0}};

unsigned long long int bitstring(unsigned long long int k)
{
	prod(k-1);
	return matrix[0][0] % num;
}

void prod(unsigned long long int k)
{
	int m[2][2] = {{1,1},{1,0}};
	for(unsigned long long int i=0;i<k-1;i++)
		multiply(matrix,m);
}

void multiply(unsigned long long int matrix[2][2],int m[2][2])
{
	unsigned long long int a = matrix[0][0]*m[0][0] + matrix[0][1]*m[1][0];
	unsigned long long int b = matrix[0][0]*m[0][1] + matrix[0][1]*m[1][1];
	unsigned long long int c = matrix[1][0]*m[0][0] + matrix[1][1]*m[1][0];
	unsigned long long int d = matrix[1][0]*m[0][1] + matrix[1][1]*m[1][1];
	matrix[0][0] = a;
	matrix[0][1] = b;
	matrix[1][0] = c;
	matrix[1][1] = d;
}
int main()
{
	int t;
	cin>>t;  // number of test cases
	unsigned long long int a[t],a1[t];
	unsigned long long int b[t];
	for(int i=0;i<t;i++)
	{
		cin >> a[i];  //input values
		a1[i] = a[i];
	}
	sort(a,a + t); //sorting the input array for faster computation of t test cases
	//reduces the number of multiplications
	for(int i=0;i<t;i++)  
	{
		if(a[i]==0)
			b[i]=0;
		else if (i==0)
		{
			int h = distance(a1,find(a1, a1+t,a[i]));
			b[h] = bitstring(a[i]+2);
		}
		else
		{
			int h = distance(a1,find(a1, a1+t,a[i]));
			b[h] = bitstring(a[i]-a[i-1]+2);
		} 
	}
	for(int i=0;i<t;i++)
	{
		cout<<b[i]<<endl;
	}
}
