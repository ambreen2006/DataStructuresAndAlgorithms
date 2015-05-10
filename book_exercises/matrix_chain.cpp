#include <iostream>
#include <climits>

using namespace std;

const int MAX = 7;


void print_optimal_parens(int s[MAX][MAX],int i,int j)
{
	if (i == j)
	{
		cout << "A"<<i<<" ";         
	}
	else
	{
		cout << "( ";
		print_optimal_parens(s,i,s[i][j]);
		print_optimal_parens(s,s[i][j]+1,j);
		cout << " )";
	}
}



int matrix_chain_order(int rows,int p[MAX])
{

	int n = rows-1;
	int i,j,k,l,q;
	cout << "N = " << n << endl;
	// Create array m (for storing the cost) and s (for storing index that achieved the optimium partition)
	int m[n][n];
	int s[MAX][MAX];	// why is s rows n-1 and cols n-n? 
	for (int i = 1; i <= n; ++i)
	{
		m[i][i] = 0;	// we know that if it's just one matrix then there is no cost to parameterize
	}

	for (l = 2; l <= n ; ++l)
	{
		for ( i = 1; i <= (n-l+1); i++) 
		{
			j = i+l-1;
			m[i][j] = INT_MAX;

			for( k = i; k<=(j-1);k++)
			{
				//long long int q = m[i][k]+m[(k+1)][j] + (A[i-1][0]*A[k][0]*A[j][0]);

				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];		
				if(q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}

		}
	}

		print_optimal_parens(s,1,n);
		cout << endl;
}



int main(int argc, char** argv)
{
	int matrices[6][2] = {{30,35},{35,15},{15,5},{5,10},{10,20},{20,25}};
	int p[7] = {30,35,15,5,10,20,25};
	int n = sizeof(p)/sizeof(p[0]);
	cout << "size is " << n << endl;
	matrix_chain_order(n,p);
	return 0;
}
