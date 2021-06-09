#include <iostream>
#include <ctime>
#include <chrono>
#include <math.h>
#include <algorithm>
using namespace std;

int linearSearchIterative( int* arr, int N, int value ){
    for ( int i = 0; i < N; i++)
        if ( arr[i] == value )
            return i;
    return -1;
}


int linearSearchRecursive(int* arr, int N, int item, int index) {
    if(N == 0)
        return - 1;
    else {
        if(arr[index] == item)
            return index;
        return linearSearchRecursive(arr, N - 1, item, index + 1);
    }
}

int binarySearch( int* arr, int N, int value ){
     int low = 0, high = N - 1;

     while ( low <= high ) {
         int mid = (low + high) / 2;

         if ( arr[ mid ] < value )
            low = mid + 1;
         else if ( arr[ mid ] > value )
            high = mid - 1;
         else
            return mid;
     }
     return -1;
}


int jumpSearch(int* arr, int N, int item) {
    int a = 0;
    int b = sqrt(N);

    while(arr[min(N, b) - 1] < item) {
        a = b;
        b = b + sqrt(N);
        if(a >= N)
            return -1;
    }

    while(arr[a] < item) {
        a = a + 1;
        if(a == min(b, N))
            return -1;
    }

    if(arr[a] == item)
        return a;
    else
        return -1;
}

void randArray(int*& arr, int size) {
    for(int i = 0; i < size; i++)
        arr[i] = rand() % (10 * size);
}

void sortArray(int*& arr, int N) {
    for(int i = 0; i < N - 1; i++) {
            int min = arr[i];
            int minPos = i;
        for(int j = i + 1; j < N; j++) {
                if(arr[j] < min) {
                    min = arr[j];
                    minPos = j;
                }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[minPos] = temp;
    }
}

int main() {

    const int test = 1000000;

    int* arr10 = new int[10];
    int* arr100 = new int[100];
    int* arr250 = new int[250];
    int* arr500 = new int[500];
    int* arr750 = new int[750];
    int* arr1000 = new int[1000];
    int* arr2000 = new int[2000];
    int* arr3000 = new int[3000];
    int* arr4000 = new int[4000];
    int* arr5000 = new int[5000];
    int* arr10000 = new int[10000];

    randArray(arr10, 10);
    randArray(arr100, 100);
    randArray(arr250, 250);
    randArray(arr500, 500);
    randArray(arr750, 750);
    randArray(arr1000, 1000);
    randArray(arr2000, 2000);
    randArray(arr3000, 3000);
    randArray(arr4000, 4000);
    randArray(arr5000, 5000);
    randArray(arr10000, 10000);

    sortArray(arr10, 10);
    sortArray(arr100, 100);
    sortArray(arr250, 250);
    sortArray(arr500, 500);
    sortArray(arr750, 750);
    sortArray(arr1000, 1000);
    sortArray(arr2000, 2000);
    sortArray(arr3000, 3000);
    sortArray(arr4000, 4000);
    sortArray(arr5000, 5000);
    sortArray(arr10000, 10000);


    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, milli > elapsedTime;


    cout << "-------------------------- N = 10 --------------------------" << endl;

    int N = 10;

    cout << "Algorithm-1" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr10, N, arr10[1]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    double avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr10, N, arr10[4]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr10, N, arr10[8]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr10, N, 11);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



     cout << "Algorithm-2" << endl;


    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr10, N, arr10[1], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr10, N, arr10[4], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr10, N, arr10[8], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr10, N, 101, 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


cout << "Algorithm-3" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr10, N, arr10[1]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr10, N, arr10[4]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr10, N, arr10[8]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr10, N, 101);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



    cout << "Algorithm-4" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr10, N, arr10[1]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr10, N, arr10[4]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr10, N, arr10[8]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr10, N, 101);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "-------------------------- N = 100 --------------------------" << endl;


    N = 100;
    cout << "Algorithm-1" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr100, N, arr100[10]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr100, N, arr100[40]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr100, N, arr100[80]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr100, N, 1001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



     cout << "Algorithm-2" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr100, N, arr100[10], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr100, N, arr100[40], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr100, N, arr100[80], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr100, N, 1001, 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



  cout << "Algorithm-3" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr100, N, arr100[10]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr100, N, arr100[40]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr100, N, arr100[80]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr100, N, 1001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "Algorithm-4" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr100, N, arr100[10]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr100, N, arr100[40]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr100, N, arr100[80]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr100, N, 1001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;








    cout << "-------------------------- N = 250 --------------------------" << endl;


    N = 250;
    cout << "Algorithm-1" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr250, N, arr250[25]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr250, N, arr250[100]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr250, N, arr250[200]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr250, N, 2501);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



     cout << "Algorithm-2" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr250, N, arr250[25], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr250, N, arr250[100], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr250, N, arr250[200], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr250, N, 2501, 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



  cout << "Algorithm-3" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr250, N, arr250[25]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr250, N, arr250[100]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr250, N, arr250[200]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr250, N, 2501);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "Algorithm-4" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr250, N, arr250[25]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr250, N, arr250[100]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr250, N, arr250[200]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr250, N, 2501);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    N = 500;

    cout << "-------------------------- N = 500 --------------------------" << endl;


    cout << "Algorithm-1" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr500, N, arr500[50]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr500, N, arr500[200]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr500, N, arr500[400]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr500, N, 5001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



     cout << "Algorithm-2" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr500, N, arr500[50], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr500, N, arr500[200], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr500, N, arr500[400], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr500, N, 5001, 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



  cout << "Algorithm-3" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr500, N, arr500[50]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr500, N, arr500[200]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr500, N, arr500[400]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr500, N, 5001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "Algorithm-4" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr500, N, arr500[50]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr500, N, arr500[200]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr500, N, arr500[400]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr500, N, 5001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



    N = 750;


    cout << "-------------------------- N = 750 --------------------------" << endl;


    cout << "Algorithm-1" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr750, N, arr750[75]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr750, N, arr750[300]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr750, N, arr750[600]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr750, N, 7501);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



     cout << "Algorithm-2" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr750, N, arr750[75], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr750, N, arr750[300], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr750, N, arr750[600], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr750, N, 7501, 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



  cout << "Algorithm-3" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr750, N, arr750[75]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr750, N, arr750[300]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr750, N, arr750[600]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr750, N, 7501);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "Algorithm-4" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr750, N, arr750[75]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr750, N, arr750[300]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr750, N, arr750[600]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr750, N, 7501);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    N = 1000;

    cout << "-------------------------- N = 1000 --------------------------" << endl;


    cout << "Algorithm-1" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr1000, N, arr1000[100]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr1000, N, arr1000[400]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr1000, N, arr1000[800]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr1000, N, 10001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "Algorithm-2" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr1000, N, arr1000[100], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr1000, N, arr1000[400], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr1000, N, arr1000[800], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr1000, N, 10001, 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



    cout << "Algorithm-3" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr1000, N, arr1000[100]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr1000, N, arr1000[400]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr1000, N, arr1000[800]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr1000, N, 10001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "Algorithm-4" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr1000, N, arr1000[100]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr1000, N, arr1000[400]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr1000, N, arr1000[800]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr1000, N, 10001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;





    N = 2000;




    cout << "-------------------------- N = 2000 --------------------------" << endl;


    cout << "Algorithm-1" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr2000, N, arr2000[200]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr2000, N, arr2000[800]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr2000, N, arr2000[1600]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr2000, N, 20001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "Algorithm-2" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr2000, N, arr2000[200], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr2000, N, arr2000[800], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr2000, N, arr2000[1600], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr2000, N, 20001, 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



    cout << "Algorithm-3" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr2000, N, arr2000[200]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr2000, N, arr2000[800]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr2000, N, arr2000[1600]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr2000, N, 20001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "Algorithm-4" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr2000, N, arr2000[200]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr2000, N, arr2000[800]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr2000, N, arr2000[1600]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr2000, N, 20001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;





    cout << "-------------------------- N = 3000 --------------------------" << endl;



    N = 3000;

    cout << "Algorithm-1" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr3000, N, arr3000[300]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr3000, N, arr3000[1200]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr3000, N, arr3000[2400]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr3000, N, 30001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "Algorithm-2" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr3000, N, arr3000[300], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr3000, N, arr3000[1200], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr3000, N, arr3000[2400], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr3000, N, 30001, 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



    cout << "Algorithm-3" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr3000, N, arr3000[300]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr3000, N, arr3000[1200]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr3000, N, arr3000[2400]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr3000, N, 30001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "Algorithm-4" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr3000, N, arr3000[300]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr3000, N, arr3000[1200]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr3000, N, arr3000[2400]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr3000, N, 30001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;







    cout << "-------------------------- N = 4000 --------------------------" << endl;



    N = 4000;


    cout << "Algorithm-1" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr4000, N, arr4000[400]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr4000, N, arr4000[1600]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr4000, N, arr4000[3200]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr4000, N, 40001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "Algorithm-2" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr4000, N, arr4000[400], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr4000, N, arr4000[1600], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr4000, N, arr4000[3200], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr4000, N, 40001, 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



    cout << "Algorithm-3" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr4000, N, arr4000[400]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr4000, N, arr4000[1600]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr4000, N, arr4000[3200]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr4000, N, 40001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "Algorithm-4" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr4000, N, arr4000[400]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr4000, N, arr4000[1600]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr4000, N, arr4000[3200]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr4000, N, 40001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;








    cout << "-------------------------- N = 5000 --------------------------" << endl;


    N = 5000;

    cout << "Algorithm-1" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr5000, N, arr5000[500]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr5000, N, arr5000[2000]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr5000, N, arr5000[4000]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr5000, N, 50001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "Algorithm-2" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr5000, N, arr5000[500], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr5000, N, arr5000[2000], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr5000, N, arr5000[4000], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr5000, N, 50001, 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



    cout << "Algorithm-3" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr5000, N, arr5000[500]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr5000, N, arr5000[2000]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr5000, N, arr5000[4000]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr5000, N, 50001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "Algorithm-4" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr5000, N, arr5000[500]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr5000, N, arr5000[2000]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr5000, N, arr5000[4000]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr5000, N, 50001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;





     cout << "-------------------------- N = 10000 --------------------------" << endl;


    N = 10000;

    cout << "Algorithm-1" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr10000, N, arr10000[1000]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr10000, N, arr10000[4000]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr10000, N, arr10000[8000]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchIterative(arr10000, N, 100001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "Algorithm-2" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr10000, N, arr10000[1000], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr10000, N, arr10000[4000], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr10000, N, arr10000[8000], 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        linearSearchRecursive(arr10000, N, 100001, 0);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



    cout << "Algorithm-3" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr10000, N, arr10000[1000]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr10000, N, arr10000[4000]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr10000, N, arr10000[8000]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        binarySearch(arr10000, N, 100001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "Algorithm-4" << endl;

    cout << "--A--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr10000, N, arr10000[1000]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--B--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr10000, N, arr10000[4000]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--C--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr10000, N, arr10000[8000]);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;


    cout << "--D--" << endl;
    startTime = std::chrono::system_clock::now();
    for(int i = 0; i < test; i++) {
        jumpSearch(arr10000, N, 100001);
    }

    elapsedTime = std::chrono::system_clock::now() - startTime;
    cout << elapsedTime.count();
    avg = elapsedTime.count() / test;
    cout << "Execution took " << avg << " milliseconds." << endl;



    delete[] arr10;
    delete[] arr100;
    delete[] arr250;
    delete[] arr500;
    delete[] arr750;
    delete[] arr1000;
    delete[] arr2000;
    delete[] arr3000;
    delete[] arr4000;
    delete[] arr5000;
    delete[] arr10000;


    return 0;
}
