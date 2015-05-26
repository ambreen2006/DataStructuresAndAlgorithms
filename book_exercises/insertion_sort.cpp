#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &vect)
{
	for(int elem : vect)
	{
		cout << elem << " ";
	}
	cout << endl;
}

int main(int argc, char **argv)
{

	vector<int> array = {5,2,4,6,1,3};

	printVector(array);

	for (int j = 1; j < array.size(); j++)
	{
		int key = array[j];
		int i = j-1;
		while(i >= 0 && array[i] > key)
		{
			array[i+1] = array[i];
			i--;
		}
		array[i+1] = key;
	}

	printVector(array);
	return 0;
}