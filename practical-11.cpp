#include <iostream>
using namespace std;

int main()
{
    int a[100], n, i, key;
    int low, high, mid;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements in sorted order: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (a[mid] == key)
        {
            cout << "Element found at position " << mid + 1;
            return 0;
        }
        else if (key < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << "Element not found";

    return 0;
}