#include<stdio.h>
int main()
{
    int n,mid,key,found=0;
    int comparisons=0;
    printf("Enter number of employee ID's: \n");
    scanf("%d",&n);
    int empID[n];
    printf("Enter %d employee ID's in ascending order: \n",n);
    for(int i=0;i<n;i++)
    scanf("%d",&empID[i]);
    printf("Enter employee ID to search: \n");
    scanf("%d",&key);
    int low=0;
    int high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        comparisons++;
        if(empID[mid]==key){
            found=1;
            break;
        }
        else if(empID[mid]<key)
        {
            
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(found){
        printf("employee ID %d is found at position %d \n",key,mid+1);
    }
    else{
        printf("Employee ID %d not found\n",key);
    }
    printf("Number of comparisons %d\n",comparisons);
    return 0;
}
