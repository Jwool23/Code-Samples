#include <iostream>
using namespace std;

// # 1 
//setting the template
/*template <typename T>
int binarySearch(T arr[], int n, T target) 
{
    int left = 0, right = n - 1, mid; //sets the first, last, and middle array element and midpoint
    while (left <= right) {
        mid = (left + right) / 2; // calculates midpoint
        if (arr[mid] == target) {
            return mid;
        }
        else if (target < arr[mid]) {
            right = mid - 1; //if the value is in lower half
        }
        else {
            left = mid + 1; //if the value is in upper half
        }
    }
    return -1;
}

int main() 
{
    int arr[] = { 1, 3, 4, 5, 8, 9 }; //setting the array
    cout << binarySearch(arr, 6, 3) << endl;
    cout << binarySearch(arr, 6, 10) << endl;
    return 0;
}
*/

// #2
template<typename T>
double median(T* arr, int n)
{
    int minIndex;
    T temp; 
    // make a temporary array to return the median
    for (int i = 0; i < n; ++i) 
    {
        minIndex = i;
        for (int j = i + 1; j < n; ++j) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
    // use a nested for loop to sort the unsorted arrays and fills the sorted array in temp
    if (n % 2 == 1) 
    {
        return arr[n / 2];
    }
    else 
    {
        return (arr[n / 2] + arr[(n - 1) / 2]) / 2.0; 
    }
    // returns the median of the array
}

template<typename T>
double median(T* arr, int n);

int main()
{
    int arr1[] = { 3, 4, 9, 1, 2, 5 };
    double arr2[] = { 4.5, 9.0, 1.7 };
    //setting the arrays
    cout << median(arr1, 6) << endl;
    cout << median(arr2, 3) << endl;
    //finding the medians of the arrays
    return 0;
}




// #3
/*template <class eType>
eType* reshape(eType** array2d, int n, int m)
{
    // dynamically allocating memory
    eType* array1d = (eType*)malloc(sizeof(eType) * n * m);
    int k = 0;
    // copying values from 2d to 1d array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            array1d[k] = array2d[i][j];
            k++;
        }
    }
    // returning 1d array
    return array1d;
}


int main(int argc, char const* argv[])
{
    // specifieng n and m
    int n = 3;
    int m = 4;
    //creating a 2d array with n*m dimensions
    int** arr_int = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
    {
        arr_int[i] = (int*)malloc(sizeof(int) * m);
    }

    //filling the array with values 1 to (n*m)
    cout << "In 2D: " << endl;
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr_int[i][j] = k;
            k++;
            cout << arr_int[i][j] << " ";
        }
        cout << endl;
    }
    // using reshape function to convert 2d array to 1d array to return it to a new variable
    int* arr_int_1d = reshape<int>(arr_int, n, m);
    // output the content of 1d array
    cout << "Converted to 1D" << endl;
    for (int i = 0; i < n * m; i++)
    {
        cout << arr_int_1d[i] << " ";
    }



    return 0;
}*/