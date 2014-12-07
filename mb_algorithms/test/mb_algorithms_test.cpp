/**
 *	@author ambreen2006@gmail.com
 * 	Tests for some of the algorithm implementation
 **/

#include<iostream>
#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include <mb_sorts.h>

using namespace std;

void print_array(int *array, size_t size)
{
  for(int i = 0; i < size; i++)
  {
      cout << " " << *(array + i);
  }
  
  cout << endl;
}

TEST(ALG_MERGE_SORT, elemntsAreSortedTest)
{
  int array[10] = {23,45,30,8,90};
  int p = 0, size = 5, r = size-1;

  print_array(array,5);
  
  mergesort(array, p, r);
  
  int k = 0;
  
  for(int i = p+1; i <=r; i++)
  {
    EXPECT_TRUE((array[k] <= array[i]));
    k++;
  }
  
  print_array(array,5);
}


TEST(ALG_MERGE_SORT, oneElementsTest)
{
  int array[10] = {23};
  int p = 0, size = 1, r = size-1;

  print_array(array,size);
  
  mergesort(array, p, r);
  
  int k = 0;
  
  for(int i = p+1; i <=r; i++)
  {
    EXPECT_TRUE((array[k] <= array[i]));
    k++;
  }
  
  print_array(array,size);
}

TEST(ALG_MERGE_SORT, threeElementsTest)
{
  int array[10] = {23,10,6};
  int p = 0, size = 3, r = size-1;

  print_array(array,size);
  
  mergesort(array, p, r);
  
  int k = 0;
  
  for(int i = p+1; i <=r; i++)
  {
    EXPECT_TRUE((array[k] <= array[i]));
    k++;
  }
  
  print_array(array,size);
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}

