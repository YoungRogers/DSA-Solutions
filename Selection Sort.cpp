/*
    Glitch on gfg : not able to select cpp
    $: AC

*/


// { Driver Code Starts
#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends

class Solution
{
public:
    int select(int arr[], int i, int n)
    {
        // code here such that selectionSort() sorts arr[]
        // int n = sizeof(arr)/sizeof(arr[0]);

        int selectedMin = 2147483647;
        int idx = i;

        for (int x = i ; x < n; x++) {
            if (arr[x] < selectedMin) {
                selectedMin = arr[x];
                idx = x;
            }
        }

        return idx;

    }

    void selectionSort(int arr[], int n) {
        //code here

        //select n-1 elements and place them
        for (int i = 0 ; i < n - 1 ; i++) {
            //select candidate for position i
            int idx = select(arr, i, n);
            //std::cout<<"Selected idx: " << idx << " & arr[idx] :" << arr[idx] << endl;
            //printf("Selected idx: %d & arr[idx]: %d\n",idx,arr[idx]);
            swap(arr + i, arr + idx);
        }

    }
};

// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000], n, T, i;

    scanf("%d", &T);

    while (T--) {

        scanf("%d", &n);

        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        Solution ob;
        ob.selectionSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends
