//this problem is same as three way partitioning problem
//OR Dutch National Flag Algorithm, or 3-way Partitioning 
/*Solution Algorithms-
a[1..Lo-1] zeroes (0)
a[Lo..Mid-] ones (1)
a[Mid..Hi] unknown
a[Hi+1..N] twos (2)

Steps Involved-
Lo := 1; Mid := 1; Hi := N;
while Mid <= Hi do
    Invariant: a[1..Lo-1]=0 and a[Lo..Mid-1]=1 and a[Hi+1..N]=2; a[Mid..Hi] are unknown.
    case a[Mid] in
        0: swap a[Lo] and a[Mid]; Lo++; Mid++
        1: Mid++
        2: swap a[Mid] and a[Hi]; Hi–
*/

// Sort the input array, the array is assumed to
// have values in {0, 1, 2}
void sort012(int a[], int arr_size)
{
    int lo = 0;   
    int hi = arr_size - 1; 
    int mid = 0;
 
    while (mid <= hi)
    {
        switch (a[mid])
        {
        case 0:
            swap(&a[lo++], &a[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(&a[mid], &a[hi--]);
            break;
        }
    }
}
