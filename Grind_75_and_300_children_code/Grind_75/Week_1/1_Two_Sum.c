/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int main()
// {

// }
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
   int i = 0;
   int temp = 0;
   int remainHolder = 0;
   //returnSize = (int*)malloc(sizeof(int));
   *returnSize = 2;
   int *array = malloc(2*sizeof(int));
   for (i = 0; i<numsSize;i++){
    temp = nums[i];
    remainHolder = target - temp;
    int j = 0;
    int listJTemp = 0;
    for(j = i+1; j<(numsSize);j++){
       listJTemp = nums[j];
       if(listJTemp == remainHolder){
        array[0] = i;
        array[1] = j;
        return array;
       } 
    }
   } 
   return array;
}
int main(){
   int arrayTest[4]={2,5,4,7};
   int *b;
   b = malloc(sizeof(int));
   int *resultArray = twoSum(arrayTest, 4, 9, b);
   int i = 0;
   for (i = 0; i<*b;i++){
      printf("%d\n", *(resultArray+i));
   }
   free(resultArray);
   return 0;
}
