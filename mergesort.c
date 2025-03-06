#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int low,int mid,int high)
{
int i=low,j=mid+1,k=low;
int c[1000000];
while(i<=mid && j<=high){
if(a[i]<a[j])
{
c[k]=a[i];
i++;
}
else
{
c[k]=a[j];
j++;
}
k++;
}
while(i<=mid)
{
c[k++]=a[i++];
}
for(i=low;i<=high;i++)
{
a[i]=c[i];
}
}
void mergesort(int a[],int low,int high)
{
if(low<high)
{
int mid=(low+high)/2;
mergesort(a,low,mid);
mergesort(a,mid+1,high);
merge(a,low,mid,high);
}
}
int main()
{
int i,n;
printf("enter the numbers of elements:");
scanf("%d",&n);
int arr[n];
srand(time(NULL));
for(i=0;i<n;i++){
arr[i]=rand()%50000;
}
clock_t start=clock();
mergesort(arr,0,n-1);
clock_t end=clock();
double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
printf("sorted array is:\t");
for(i=0;i<10;i++){
printf("%d\t",arr[i]);
}
printf("Time taken for sorting:%fseconds\n",time_taken);
return 0;
}



