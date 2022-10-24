/*
 * C Program to Generate Pascal Triangle 1 D Array
 */
#include <stdio.h>
 
void main()
{
    int array[30], temp[30], i, j, k, l, num;           //using 2 arrays
 
    printf("Enter the number of lines to be printed: ");
    scanf("%d", &num);
    temp[0] = 1;
    array[0] = 1;
    for (j = 0; j < num; j++)
        printf(" ");
    printf(" 1\n");
    for (i = 1; i < num; i++)
    {
        for (j = 0; j < i; j++)
            printf(" ");
        for (k = 1; k < num; k++)
        {
            array[k] = temp[k - 1] + temp[k];      
        }
        array[i] = 1;
        for (l = 0; l <= i; l++)
        {
            printf("%3d", array[l]);
            temp[l] = array[l];
        }
        printf("\n");
    }
}