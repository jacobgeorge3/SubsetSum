#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

/*
bool combinationUtil(int arr[], int n, int r, int index, int data[], int i, int check);
//Different Idea
bool SubsetSum(int x[], int n, int k, int v)
{
    // A temporary array to store all combination one by one
    int data[k];

    return combinationUtil(x, n, k, 0, data, 0, v);
}


bool combinationUtil(int arr[], int n, int r, int index, int data[], int i, int check)
{
    int sum;
    // Ccheck current combination
    if (index == r)
    {
      int j;
        for (j=0; j<r; j++)
            sum += data[j];
      return sum = check;
    }

    // When no more elements are there to put in data[]
    if (i >= n)
        return false;

    // current is included, put next at next location
    data[index] = arr[i];
    combinationUtil(arr, n, r, index+1, data, i+1, check);

    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    combinationUtil(arr, n, r, index, data, i+1, check);
}
*/


int SubsetSum(uint x[], uint n, uint k, uint v) {
  // used up all numbers to reach sum 0
  if (v == 0 && k == 0){
    return true;
  }
  // used up all numbers without reaching sum 0
  if (v!=0 && k == 0){
    return false;
  }
  // used up all numbers without reaching sum 0
  if (n == 0){
    return false;
  }

  int res1 = 0;
  if (v >= x[0]){
    // include the first number of the array in the sum
    res1 = SubsetSum(x + 1, n -1, k - 1, v - x[0]);
  }

  // exclude the first number in the sum
  int res2 = SubsetSum(x + 1, n - 1, k, v);
return res1 || res2;
}




/*


int SubsetSum(uint x[], uint n, uint k, uint v) {
  mergeSort(x, 0, n- 1);//Sort array in hopes of quickness
  printf("Sorted\n");
  int temp[k];//Only possible size of subarray
  int big = n;
  for(int i = 0; i < n; i++){
    if(x[i] > v){
      big = i;
    }
  }

  for(int out = k; out > -1; out--){
    int in = 0;
    while(in < big){
      int sum = 0;
      for(int p = 0; p < k; p++){
        temp[p] = x[in + k];
        sum += x[in + k];
      }
      if(sum == v){
        return true;
      }
      in++;
    }
    printf("Test");
  }
  return false;

}


int main(void){

  int arr[5] = {1, 8, 6, 4, 3};
  assert(!SubsetSum(arr, 5, 3, 9));
  assert(SubsetSum(arr, 5, 2, 9));
  assert(!SubsetSum(arr, 5, 3, 2));
  assert(SubsetSum(arr, 5, 2, 7));
  assert(SubsetSum(arr, 5, 5, 22));
  assert(!SubsetSum(arr, 5, 5, 10));
  assert(SubsetSum(arr, 5, 4, 14));
  assert(!SubsetSum(arr, 5, 2, 2));

  printf("Passed");

  /*int universal[100];
  int accounted [100];
  int randInd;
  for(int i = 0;i<100;i++)
    universal[i] = i+1;
    assert(!SubsetSum(universal,100,2,0));
  assert(!SubsetSum(universal,100,1,0));
  assert(SubsetSum(universal,100,2,5));
  assert(SubsetSum(universal,100,2,99));
  assert(SubsetSum(universal,100,2,80));
  assert(!SubsetSum(universal,100,2,2));
  assert(!SubsetSum(universal,0,5,2));
  assert(!SubsetSum(universal,100,2,1));

  //Random Tests
  for(int i = 0;i<100;i++)
      universal[i] = rand()%(1<<10);
  int sum = 0;
  int curSum = 0;
  //2 element tests
  for(int i = 1;i<30;i++)
  {
    for(int j = 0;j<30;j++) {
        randInd = rand() % 100;
        for(int k = 1;k<i;k++) {
            if(accounted[k] == randInd){
                randInd = rand() % 100;
                k = 1;
            }

        }
        curSum = universal[randInd] + sum;
        assert(SubsetSum(universal, 100, i, curSum));
    }
    accounted[i] = randInd;
    sum =curSum;
}





  return 0;
}
*/
