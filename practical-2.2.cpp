//call by value
#include <iostream>   
#include <cstdlib>    
using namespace std;

int main() {
    int n;   
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = (int*) malloc(n * sizeof(int));

    if (arr == NULL) {
        cout << "Memory Allocation Failed" << endl;
        return 0;    }

    cout << "Enter the elements:"<< endl;
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);  
    }

    cout << "Array elements in reverse order:" << endl;
    for (int i = n - 1; i >= 0; i--) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    free(arr);

    return 0; 
}
 //call by reference
 #include <iostream>
using namespace std;

void callByReference(int &x) {

    x = 22; 
    cout << "Inside function value of x = " << x << endl; 
}

int main() {
   
    int b;

    b = 11;

    cout << "Before function call value of b = " << b << endl;

    callByReference(b);

    cout << "After function call value of b = " << b << endl;

    return 0;
}
