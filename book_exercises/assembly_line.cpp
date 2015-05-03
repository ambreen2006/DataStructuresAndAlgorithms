/**
  *	Dynamic programming - fastest way algorithm implementation from "Introduction to Algorithms"
  *
  */

#include <iostream>

using namespace std;

void fastest_way(int a[][6],int t[][5],int e[],int x[],int n)
{
	int f1[6];
	int f2[6];
	int l1[6],l2[6];

	// Calculate the first entry and station cost for both the lines
	f1[0] = e[0]+a[0][0];
	f2[0] = e[1]+a[1][0];

	for(int j = 1; j < n; j++)
	{
		if( ( f1[j-1]+a[0][j] ) <= ( f2[j-1]+t[1][j-1]+a[0][j] ) )
		{
			f1[j] = f1[j-1]+a[0][j];
			l1[j] = 0;
		}
		else
		{
			f1[j] = f2[j-1]+t[1][j-1]+a[0][j];
			l1[j] = 1;
		}

		if( (f2[j-1] + a[1][j] ) <= (f1[j-1] + t[0][j-1]+a[1][j]) )
		{
			f2[j] = f2[j-1] + a[1][j];
			l2[j] = 1;
		}
		else
		{
			f2[j] = f1[j-1] + t[0][j-1] + a[1][j];
			l2[j] = 0;
		}

	}


	int fastest;
	int lane;
	if (f1[n-1]+x[0] <= f2[n-1]+x[1])
	{
		fastest = f1[n-1]+x[0];
		lane = 0;
	}
	else 
	{
		fastest = f2[n-1]+x[1];
		lane = 1;
	}

	cout << "Fastest time " << fastest << endl;
}


int main(int argc,char **argv)
{
	int e[2] = {2,4};
	int a[2][6] = {{7,9,3,4,8,4},
				   {8,5,6,4,5,7}};

	int t[2][5] = {{2,4,1,3,4},
				   {2,1,2,2,1}};

	int x[2] = {3,2};

	fastest_way(a,t,e,x,6);
	return 0;
}