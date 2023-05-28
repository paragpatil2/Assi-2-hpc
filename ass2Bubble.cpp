#include <iostream>
#include <omp.h>
#include <chrono>

using namespace std;

void bubbleSort(int arr[], int n) {
    #pragma omp parallel
    {
        for (int i = 0; i < n-1; i++) {
            #pragma omp for
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    std::swap(arr[j], arr[j+1]);
                }
            }
        }
    }
}

int main() {
    // int arr[] = {64, 34, 25, 12, 22, 11, 90};
    // int n = sizeof(arr)/sizeof(arr[0]);

    int n;
    cin >>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    

    auto startTime = std::chrono::high_resolution_clock::now();

    bubbleSort(arr, n);

    // Measure the end time
    auto endTime = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> duration = endTime - startTime;

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}
