#include<stdio.h>
#include<math.h>
int check(int n,int a)
{
    int k=0;
    while(n%a==0)
    {
        k++;
        n=n/a;
    }
    return k;
}
int main()
{
    int n,p_2,p_3,p_5;
    printf("Enter The Number:");
    scanf("%d",&n);
    p_2=check(n,2);
    p_3=check(n,3);
    p_5=check(n,5);
    if(pow(2,p_2)*pow(3,p_3)*pow(5,p_5)==n)
        printf("Ugly\n");
    else
        printf("\nError\n");
    return 0;
}
