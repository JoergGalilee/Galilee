/*#include <stdio.h>


void DisplayNumber(float num[i]);
int main() {
    int element [10]={};
    
    int size = sizeof(element)/sizeof(element[0]);
    printf("The difference in the address is: %d \n",(int)( sizeof(element)/sizeof(element[0]));

    for (int i=0;i<size;i++){
    printf("Total elements the array can hold is: %d\n",element[i]);
    }
DisplayNumber(element[i]);
    printf("Total elements the array can hold is: %d\n",DisplayNumber);

    return 0;
}*/

#include <stdio.h>
int output(int arr[10]){
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("The size of this array is: %d\n", size);
    printf("Arrays first element: %d\n", arr[5]);
    return 0;
}
int main() {
    // Write C code here

    int arr[7] = {7,2,3,7,8,4};
    output(arr);
    int size = sizeof(arr)/ sizeof(arr[0]);
    printf("The size of this array is: %d\n", size);
    
    return 0;
}
