#include <stdio.h>
#include <stdlib.h>

int search(int key, int *a, int left, int right)
{

}

int rek_search(int key, int *a, int left, int right)
{
    int middle = (left + right) / 2;

    if(left <= right)
    {
        if(key == a[middle])
        {
            return middle;
        }
        else if(key < a[middle])
        {
            return rek_search(key, a, left, (middle - 1));
        }
        else
        {
            return rek_search(key, a, (middle + 1), right);
        }
    }

    return -1;
}

int main()
{
    int arr[] = {0, 10, 20, 30, 40, 50, 60, 70};
    int idx = rek_search(40, arr, 0, 7);

    if(idx != -1)
    {
        printf("found: %d\n", arr[idx]);
    }
    else
    {
        printf("Not found\n");
    }

    return 0;
}
