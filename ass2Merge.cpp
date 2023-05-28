#include <iostream>
#include<omp.h>
#include<chrono>

using namespace std;
void merge(int a[10],int i1,int mid,int j1)
{
    int i=i1;
    int j=mid+1;
    int k=0;
    int temp[100];
    while(i<=mid&&j<=j1)
    {
        if(a[i]>a[j])
        {
            temp[k++]=a[j++];
        }
        else
        temp[k++]=a[i++];
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=j1)
    temp[k++]=a[j++];
    
    for(i=i1,j=0;i<=j1;i++,j++)
    {
        a[i]=temp[j];
    }
 
}
void mergesort(int a[10],int i,int j)
{
    if(i<j)
    {
        int mid=(i+j)/2;
        #pragma omp parallel sections
        {
            #pragma omp section
            {
        mergesort(a,i,mid);
            }
            #pragma omp section
            {
        mergesort(a,mid+1,j);
            }
        }
        merge(a,i,mid,j);
    }
}
int main()
{
    int a[10]={2,3,1,4,6,5,9,8,7,0};
    auto startTime = std::chrono::high_resolution_clock::now();
    mergesort(a,0,9);
    cout << "Sorted Array is:" << endl; 
    for(int i=0;i<=9;i++)
    {
       cout<<a[i] << " ";
    }
    cout << endl;
    // Measure the end time
    auto endTime = std::chrono::high_resolution_clock::now();

    // Calculate the duration
    std::chrono::duration<double> duration = endTime - startTime;

    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;
   return 0;
}