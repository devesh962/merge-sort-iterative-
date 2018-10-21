#include "mergeite.h"

void merge(int arr[],int l,int m,int h)
{

 int n1=m-l+1;
int n2=h-m;
int *L,*R;
L=malloc((n1+1)*sizeof(int));
R=malloc((n2+1)*sizeof(int));
int i,j,k;
for(i=1;i<=n1;i++)
L[i]=arr[i+l-1];
for(j=1;j<=n2;j++)
R[j]=arr[m+j];
i=1;
j=1;
k=l;
while(i<=n1 && j<=n2)
{
if(L[i]<R[j])
{
arr[k]=L[i];
i++;
}
else
{
arr[k]=R[j];
j++;
}
k++;
}
while(i<=n1)
arr[k++]=L[i++];
while(j<=n2)
arr[k++]=R[j++];
free(L);
free(R);


}

int min(int a,int b)
{
return a>b?b:a;
}

int mergesort(int arr[],int l,int h)
{
int i,m;
for(m=1;m<h-l;m+=m)
{
for(i=l;i<h;i+=m+m)
{
int from=i;
int mid=i+m-1;
int to=min(i+m+m-1,h);
merge(arr,from,mid,to);
}}
return 0;

}

