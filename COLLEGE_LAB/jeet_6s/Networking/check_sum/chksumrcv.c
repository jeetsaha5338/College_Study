/* Checksum CHECK */
#include <stdio.h>
#include <conio.h>
int main() {
	char msg[30];
	int temp,n, i, k, s, t=0, c[10], d[10], rem[10], sum[10], intsum[10], newsum[10], car[10], c1=0, c2=0, com[10];
	printf("Enter value of n: \n");
	scanf("%d",&n);
	printf("Enter the message: \n");
	scanf("%s",msg);
	k=0;
	while(msg[k]!='\0') {
		for(i=0;i<n;i++) {
			c[i] = msg[k] - 48;
			k++;
		}
		for(i=0;i<n;i++) {
			d[i] = msg[k] - 48;
			k++;
		}
		for(i=0;i<n;i++) {
			rem[i] = msg[k] - 48;
			k++;
		}
	}
	printf("\nVal1 = ");
	for(i=0;i<n;i++)
		printf("%d ",c[i]);
	printf("\nVal2 = ");
	for(i=0;i<n;i++)
		printf("%d ",d[i]);
	printf("\nChks = ");
	for(i=0;i<n;i++)
		printf("%d ",rem[i]);
	for(i=n-1;i>=0;i--) {
		intsum[i] = (c[i] + d[i] + c1)%2;
		c1 = (c[i] + d[i] + c1)/2;
	}
	printf("\nSum1 : ");
	for(i=0;i<n;i++) {
		printf("%d ",intsum[i]);
	}
	printf("\t\tCarry : %d",c1);
	if(c1==1){
		for(i=n-1;i>=0;i--) {
			temp = (intsum[i] + c1)%2;
			c1 = (intsum[i] + c1)/2;
			intsum[i]=temp;
		}
		printf("\nSum1 : ");
			for(i=0;i<n;i++) {
				printf("%d ",intsum[i]);
		}
	}
	for(i=n-1;i>=0;i--) {
		sum[i] = (intsum[i] + rem[i] + c2)%2;
		c2 = (intsum[i] + rem[i] + c2)/2;
	}
	printf("\nSum2 : ");
	for(i=0;i<n;i++) {
		//newsum[i]=sum[i];
		printf("%d ",sum[i]);
	}
	printf("\t\tCarry : %d",c2);
	if(c2==1){
		for(i=n-1;i>=0;i--) {
			temp = (sum[i] + c2)%2;
			c2 = (sum[i] + c2)/2;
			sum[i]=temp;
		}
		printf("\nSum2 : ");
			for(i=0;i<n;i++) {
				printf("%d ",sum[i]);
		}
	}
	for(i=n-1;i>=0;i--) {
		com[i]=!sum[i];
	}
	printf("\nComp : ");
	for(i=0;i<n;i++) {
        	printf("%d ",com[i]);
	}
	for(i=0;i<n;i++) {
    		if(com[i]!=0){
				t=1;
				break;
	    	}
			else {
				t=0;
	    	}
	}
	if(t==0)
	   	printf("\n\nThe message is correct.");
	else
		printf("\n\nThe message is damaged.");
	getch();
	printf("\n\n");
	return 0;
}
