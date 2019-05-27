//
//  main.cpp
//  TestRevisionP9
//
//  Created by Laura Walsh on 05/05/2019.
//  Copyright © 2019 Laura Walsh. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <unistd.h>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

void testTiming(){
    clock_t begin = clock();
    for(int i =0; i<1000; i++){
        usleep(100);
    }
    clock_t end = clock();
    
    double elapsed = double(end-begin);
    cout << "Time taken with N= " << 1000 << " is " << elapsed << "ms= " << elapsed/1000.00 << "s" << endl;
}

double average(vector<int> array, int N){
    int total=0;
    clock_t begin = clock();
    for(int i=0; i<N;i++){
        total+= array[i];
        usleep(100);
    }
    clock_t end = clock();
    
    double elapsed = double(end-begin);
    cout << "Time taken with N= " << N << " is " << elapsed << "ms= " << elapsed/1000.00 << "s" << endl;
    
    cout << endl << "average is: " << total/N;
    return total/N;
}

int countAboveAv(vector<int> &array, int N){
    int count=0;
    double av = average(array,N);
    clock_t begin = clock();
    for(int i=0; i<N; i++){
        if(array[i] > av) count++;
        usleep(100);
    }
    clock_t end = clock();
    
    double elapsed = double(end-begin);
    cout << "Time taken with N= " << N << " is " << elapsed << "ms= " << elapsed/1000.00 << "s" << endl;
    
    cout << endl << "amount above av is: " << count;
    
    return count;
}

int binarySearch (vector<int>& myArray, int first, int last, int value){
    if (first > last) return -1;
    usleep(100);
    int mid = first+last/2;
    
    if(myArray[mid] == value)
        return mid;
    else if(value < myArray[mid]) return binarySearch(myArray, first, mid-1, value);
    else  return binarySearch(myArray, mid+1, last, value);
    
}

int findFurthest(vector<int>& v, int N){
    int *temp = new int[N];
    //for each value find the closest other value
    for(int i =0; i<N; i++){
        int thisVal = v[i];
        int minDistance = INT_MAX;
        for(int j =0; j<N; j++){
            usleep(100);
            if (j!=i)
                if(abs(thisVal-v[j])<minDistance)
                    minDistance = abs(thisVal-v[j]);
        }
        temp [i] = minDistance;
    }
    //find the value with the furthest closest other value
    int maxDistance = temp[0];
    int furthest = v[0];
    for(int i = 1;i<N;i++)
        if(temp[i]>maxDistance){
            usleep(100);
            maxDistance = temp[i];
            furthest = v[i];
        }
    delete[] temp;
    return furthest;
}


int main(){
    
    testTiming();
    int N;
    cout << "Input the size of the vectot: " << endl;
    cin >> N;
    vector<int> array;
    srand((unsigned)time(NULL));
    for(int i=0; i<N; i++) array.push_back(rand()%100);
    for(int i=0; i< N; i++) cout << array[i] << ", ";
    
    double av = average(array, N);
    
    int count = countAboveAv(array, N);
    
    sort(array.begin(), array.end());
    
    clock_t begin = clock();
    binarySearch(array, 0, N, 10);
    clock_t end = clock();
    double elapsed = double(end-begin);
    cout << "Time to search:  " << elapsed << "ms= " << elapsed/1000.00 << "s" << endl;
    
    vector<int> array2;
    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++) array2.push_back(rand() % 100000);
    
    begin = clock();
    cout << "furthest value = " << findFurthest(array2, N) << endl;
    end = clock();
    
    elapsed = double(end - begin);
    cout << "Time taken to search " << N << " values = " << elapsed << " ms = "
    << elapsed / 1000.0 << " s" << endl << endl;

    
    return 0;
}


