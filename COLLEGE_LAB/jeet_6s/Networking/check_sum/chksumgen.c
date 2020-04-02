/* Checksum GEN of two segments of data*/
#include <stdio.h>
#include <conio.h>
int main() {
	char ch, a[10], b[10], msg[30];
	int n, i, k, s, c[10], d[10], sum[10], car=0, com[10],temp;
	printf("Enter the segments length n:  ");
	scanf("%d",&n);
	printf("Enter 1st value: \n");
	scanf("%s",a);
	printf("Enter 2nd value: \n");
	scanf("%s",b);
	for(i=0;i<n;i++) {
		c[i] = a[i] - 48;
		d[i] = b[i] - 48;
	}
	for(i=n-1;i>=0;i--) {
		sum[i] = (c[i] + d[i] + car)%2;
		car=(c[i] + d[i] + car)/2;

	}
	printf("Sum of 2 numbers: \n");
	for(i=0;i<n;i++) {
		printf("%d",sum[i]);
	}
	printf("\nCarry of sum :: %d\n",car);
	if(car==1){
		for(i=n-1;i>=0;i--){
			temp=(sum[i]+car)%2;
			car=(sum[i]+car)/2;
			sum[i]=temp;
		}
		printf("\nSum of 2 numbers: \n");
		for(i=0;i<n;i++)
			printf("%d",sum[i]);
	}
	for(i=n-1;i>=0;i--) {
		com[i]=!sum[i];
	}
	printf("\nThe Checksum is:  \n");
	for(i=0;i<n;i++)
		printf("%d",com[i]);
	printf("\nThe message is:   ");
	k=0;
	for(i=0;i<n;i++){
		msg[k++]=a[i];
	}
	for(i=0;i<n;i++) {
		msg[k++]=b[i];
	}
	for(i=0;i<n;i++) {
		ch = (char)(com[i]+48);
		msg[k++]=ch;
	}
	msg[k]='\0';
	printf("%s",msg);
	printf("\n");
	getch();
	return 0;
}