#include <stdio.h>
int  unimodal_array (int array[],int start,int end);
int main() {
    int array[]={2, 4, 7, 10, 14, 12, 9, 6, 3};
    int n=sizeof (array)/sizeof (array[0]);
    int start=0;
    int end =n-1;
    int max =unimodal_array(array,start,end);
    printf("max element :%d ",array[max]);

    return 0;
}
int  unimodal_array (int array[],int start,int end)
{
   if (start==end)
       return start;
    int mid=(start+end)/2;
    if(array[mid]>array[mid-1]&&array[mid]>array[mid+1])
    {
        return mid ;
    }
    else if (array[mid] > array[mid + 1]) {
        return unimodal_array(array, start, mid);
    } else {
        return unimodal_array(array, mid + 1, end);
    }
}