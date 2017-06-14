//In order to finding all duplocates in array we taverse array and for an element we go to corresponding index and add size of array to
//that element after completing this
//We do another pass and on each index if num[i]/n is greater than 1 then corresponding index value is a duplicate element in that array

// function to find repeating elements
void printRepeating( int arr[], int n)
{
    // First check all the values that are
    // present in an array then go to that
    // values as indexes and increment by
    // the size of array
    for (int i = 0; i < n; i++)
    {
        int index = arr[i] % n;
        arr[index] += n;
    }
 
    // Now check which value exists more
    // than once by dividing with the size
    // of array
    for (int i = 0; i < n; i++)
    {
        if ((arr[i]/n) > 1)
            cout << i << " ";
    }
}
