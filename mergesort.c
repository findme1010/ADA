#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cnt=0;
void merge(int arr[],int left,int mid,int right){
    int i,j,k,n1,n2;
    n1=mid-left+1;
    n2=right-mid;
    int *L=(int *)malloc(n1*sizeof(int));
    int *R=(int *)malloc(n2*sizeof(int));
    for(i=0;i<n1;i++)
        L[i]=arr[left+i];
    for(j=0;j<n2;j++)
        R[j]=arr[mid+1+j];
    i=j=0;
    k=left;
    while(i<n1 && j<n2){
        cnt++;
        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }
    while(i<n1)
        arr[k++]=L[i++];
    while(j<n2)
        arr[k++]=R[j++];

    free(L);
    free(R);
}

void mergesort(int arr[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void generateWorstCase(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    // Create temp array
    int* temp = (int*)malloc((right - left + 1) * sizeof(int));
    int index = 0;

    // Divide elements in alternate fashion for worst case
    for (int i = left; i <= right; i += 2)
        temp[index++] = arr[i];
    for (int i = left + 1; i <= right; i += 2)
        temp[index++] = arr[i];

    for (int i = left; i <= right; i++)
        arr[i] = temp[i - left];

    free(temp);

    // Recursive call
    generateWorstCase(arr, left, mid);
    generateWorstCase(arr, mid + 1, right);
}


void main(){
    FILE *f1,*f2,*f3,*f4;
    f1=fopen("bestms.txt","w");
    f2=fopen("avgms.txt","w");
    f3=fopen("worstms.txt","w");
    f4=fopen("ms_iteration.txt","w");
    srand(time(NULL));
    for(int n=10;n<=100;n+=10){
        int *arr=(int*)malloc(n*sizeof(int));

        fprintf(f4,"n=%d\nBestArray:- ",n);
        //best
        cnt=0;
        for(int i=0;i<n;i++){
            arr[i]=i+1;
            fprintf(f4,"%d ",arr[i]);
        }
        fprintf(f4,"\n");
        fprintf(f4,"BestSortedArray:-");
        mergesort(arr,0,n-1);
        for(int i=0;i<n;i++){
            fprintf(f4,"%d ",arr[i]);
        }
        fprintf(f4,"\n\n");
        fprintf(f1,"%d\t%d\n",n,cnt);

        //avg
        cnt=0;
        fprintf(f4,"\nAvgArray:- ");
        for(int i=0;i<n;i++){
            arr[i]=rand()%n;
            fprintf(f4,"%d ",arr[i]);
        }
        fprintf(f4,"\n");
        mergesort(arr,0,n-1);
        fprintf(f4,"AvgSortedArray:- ");
        for(int i=0;i<n;i++){
            fprintf(f4,"%d ",arr[i]);
        }
        fprintf(f4,"\n\n");
        fprintf(f2,"%d\t%d\n",n,cnt);

        //worst
        cnt = 0;
        fprintf(f4, "WorstCaseArray:- ");
        for(int i = 0; i < n; i++) 
            arr[i] = i + 1;
        generateWorstCase(arr, 0, n - 1);

        for(int i = 0; i < n; i++) 
            fprintf(f4, "%d ", arr[i]);
        fprintf(f4, "\n");
        mergesort(arr, 0, n - 1);
        fprintf(f4, "WorstSortedArray:- ");
        for(int i = 0; i < n; i++) 
            fprintf(f4, "%d ", arr[i]);
        fprintf(f4, "\n\n");
        fprintf(f3, "%d\t%d\n", n, cnt);

    }
}
