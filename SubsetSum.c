#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

bool SubsetSum(uint32_t x[], uint32_t n, uint32_t v, uint32_t k){
  //Used all numbers to reach sum 0
  if(v == 0 && k == 0){
    return true;
  }
  //used up all numbers without reaching sum 0
  if(k != 0 && v == 0){
    return false;
  }
  //used up all numbers without reaching sum 0
  if(n == 0){
    return false;
  }
  int res1 = 0;
  if(k >= x[0]){
    //include the first number of the array in the sum
    res1 = SubsetSum(x + 1, n - 1, v - 1, k - x[0]);
  }
    //exclude the first number in the sum
    int res2 = SubsetSum(x + 1, n - 1, v, k);
    if(res1 || res2){
      return true;
    }
    else{
      return false;
    }

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


  int universal[10000];
  /*

  int universal[10000];
  for(int i = 0;i<100;i++){
    printf(" %d ", i);
    universal[i] = i + 1;
  }
  assert(!SubsetSum(universal,100,0,2));
  assert(!SubsetSum(universal,100,0,1));
  //assert(SubsetSum(universal,100,5,2));
  assert(SubsetSum(universal,100,99,2));
  //assert(SubsetSum(universal,100,80,2));
  //assert(!SubsetSum(universal,100,2,2));
  //assert(!SubsetSum(universal,0,2,5));
  //assert(!SubsetSum(universal,100,1,2));

*/

  printf("Random Tests");
  //Random Tests
  for(int i = 0; i < 100; i++)
      universal[i] = rand();
  int sum = 0;
  int curSum = 0;
  //2 element tests
  for(int i = 1; i < 50; i++)
  {
      for(int j = 0;j < 100;j++) {
          curSum = universal[rand() % 10000] + sum;
          assert(SubsetSum(universal, 10000, i, curSum));
      }
      sum += universal [i - 1];
  }

  printf("Passed");


  return 0;
}
