/*
 * C Program to search for an element in a list using
 */
#include <stdio.h>
 
int search(int [], int, int);
int main()
{
    int size, index, key;
    int list[20];
    int count = 0;
    int i;
 
    printf("Enter the size of the list: ");
    scanf("%d", &size);
    index = size;
    printf("Printing the list:\n");
    for (i = 0; i < size; i++)
    {
        list[i] = rand() % size;
        printf("%d\t", list[i]);
    }
    printf("\nEnter the key to search: ");
    scanf("%d", &key);
    while (index > 0)
    {
        index = search(list, index - 1, key);
        /* In an array first position is indexed by 0 */
        printf("Key found at position: %d\n", index + 1);
        count++;
    }
    if (!count)
        printf("Key not found.\n");
    return 0;
}
int search(int array[], int size, int key)
{
    int location;
    if (array[size] == key)
    {
        return size;
    }
    else if (size == -1)
    {
        return -1;
    }
    else
    {
        return (location = search(array, size - 1, key));
    }
}