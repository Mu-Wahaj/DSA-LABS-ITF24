#include <iostream>
using namespace std;

bool findKthLargest(const int *arr, int n, int k, int &val)
{
    if (k < 1 || k > n)
        return false;

    int count;

    for (int i = 0; i < n; i++)
    {
        count = 0;

        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[i])
                count++;
        }

        if (count == k - 1)
        {
            val = arr[i];
            return true;
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter " << n << " unique integers:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    int result;

    if (findKthLargest(arr, n, k, result))
        cout << k << "th largest element is: " << result << endl;
    else
        cout << "Invalid value of k!" << endl;

    delete[] arr;

    return 0;
}