#include<stdio.h>
int main()
{
    int a[6]={1,5,10,20,40,80};
    int b[5]={6,7,30,40,80};
    int c[8]={3,4,15,20,40,70,80,120};
    int n1=6,n2=5,n3=8;
    int i,j,k,m;
    i=j=k=0;
    while(i<n1 && j<n2 && k<n3)
    {
        if(a[i]==b[j] && b[j]==c[k])
        {
            printf("%d,",a[i]);
            i++;j++;k++;
        }
        else
        {

            a[i]<b[j]?(a[i]<c[k]?i++:k++):(b[j]<c[k]?j++:k++);
        }

    }
    return 0;
}
