#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

void merge(long A[],int p, int q, int r)
{
	size_t n1 = q-p+1;
	size_t n2 = r-q;

	long L[n1+1];
	long R[n2+1];

	int i = 0;
	int j = 0;

	for (i = 0; i < n1; ++i)
	{	
		L[i] = A[p+i];
	}
	L[i] = LONG_MAX;

	for (j = 0; j < n2; ++j)
	{
		R[j] = A[q+j+1];
	}
	R[j] = LONG_MAX;

	i = 0;
	j = 0;
	
	for (int k = p; k <= r; k++)
	{
		if(L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}

}

void merge_sort(long A[], int p,int r)
{
	if(p < r)
	{
		int q = floor(((p+r)/2));
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q,r);
	}
}

void print_array(long A[],size_t len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << A[i] << " " ;
	}
}

int main(int argc, char **argv)
{


	long A[] = {5,2,7};
	size_t len = sizeof(A)/ sizeof(long);
	cout << endl;

	cout << "Before: " ;
	print_array(A,len);
	cout << endl;
	merge_sort(A,0,len-1);
	cout << "After:  ";
	print_array(A,len);
	cout << endl;


	long B[] = {5,2,4,7,1,3,2,6};
	len = sizeof(B)/ sizeof(long);
	cout << endl;

	cout << "Before: " ;
	print_array(B,len);
	cout << endl;
	merge_sort(B,0,len-1);
	cout << "After:  ";
	print_array(B,len);
	cout << endl;


	return 0;
}