/* *
 * 	author : ambreen2006@gmail.com
 * 	Implementation for various algorithms described in mb_sorts.h
 * */


#include <math.h>
#include <stdlib.h>
#include <climits>

#include "mb_sorts.h"

using namespace std;

void merge(int* arrayA, int p, int q, int r);

void merge(int* arrayA, int p, int q, int r)
{
  
    int n1 = q - p + 1; // when both q and p are 0 we still need one element
    int n2 = r - q;
    int *temp1 = (int *) malloc((sizeof(int)*(n1+1)));
    int *temp2 = (int *) malloc((sizeof(int)*(n2+1)));
    ;
    for(int i = 0; i < n1; i++)
    {
      *(temp1+i) = *(arrayA+p+i);
    }

    *(temp1+n1) = INT_MAX;
    
    
    for(int j = 0; j < n2; j++)
    {
      *(temp2+j) = *(arrayA+j+(q+1));
    }
    
    *(temp2+n2) = INT_MAX;
    
    int i = 0, j = 0;
    for(int k = p; k <= r; k++)
    {
      if( *(temp1+i) <= *(temp2+j))
      {
	  *(arrayA+k) = *(temp1+i);
	  i++;
      }
      else
      {
	  *(arrayA+k) = *(temp2+j);
	  j++;
      }
    }
    
    free(temp1);
    free(temp2);
    
}

void mergesort(int* arrayA, int p, int r)
{
  if(p < r)
  {
    int q = floor((p+r) / 2);
    mergesort(arrayA, p, q);
    mergesort(arrayA, q+1, r);
    merge(arrayA, p, q, r);
  }
}
