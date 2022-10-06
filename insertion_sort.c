#include <stdio.h>
int main()
{
    int n, i, j, temp;
    int arr[64];
 
    //Take an size of array
    printf("Enter number of elements\n");
    scanf("%d", &n);
    
    //Take an elements of array
    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
	
    // Insertion sort
    for (i = 1 ; i <= n - 1; i++) {
	    j = i;
            while ( j > 0 && arr[j-1] > arr[j]) {	        
                temp     = arr[j];
                arr[j]   = arr[j-1];
                arr[j-1] = temp;
                j--;
            }
    }
    
    //Print the sorted elements
    printf("Sorted list in ascending order:\n");
    for (i = 0; i <= n - 1; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
