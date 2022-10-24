/*
     * C Program to Print the kth Element in the Array
     */
 
    #include <stdio.h>
    int main()
    {
        int arr[100], len, i, j, temp, n;
        printf("Enter the size of array");
 
        scanf("%d", &len);
        printf("\n Enter the array elements");
 
        for (i = 0; i < len; i++) 
        {
            scanf("%d", &arr[i]);
        }
 
        printf("\n Enter Which kth Number You want");
        scanf("%d", &n);
        printf("\n The %d th kth number is: %d", n, arr[n - 1]);
        return 0;
    }
    