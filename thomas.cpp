#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
using namespace std;


void elimination (double a[11], double b[11], double c[11], double z[11], double x[11])
{
	printf("elimination");
	double m;
	int i, n;
for (int n=2;n<=a[0];n++)
	{
	m=a[n]/b[n-1];
	b[n]=b[n]-m*c[n-1];
	z[n]=z[n]-m*z[n-1];
	}
	n=a[0];
x[n]=z[n]/b[n];
for (i=a[0]-1;i>=1;i--)
	{
	x[i]=(z[i]-c[i]*x[i+1])/b[i];
	}
}



void write (double a1[11], double b1[11], double c1[11], double z1[11], double x1[11], double a2[11], double b2[11], double c2[11], double z2[11], double x2[11])
{
int n, i;
	a1[1]=0;
	n=a1[0];
FILE * output;
output = fopen ("thomasresults.txt", "w");	
fprintf(output,"Matrix 1 components and solution:\r\n");
fprintf(output,"A Array:\r\n");

printf("Matrix 1 components and solution:\r\n");
printf("A Array:\r\n");

	for (int y=1;y <= n;y++)
		{
		
		fprintf(output,"%5.2lf\t",a1[y]);
		}
		
	fprintf(output,"\r\n");
	fprintf(output,"\r\n");
	fprintf(output,"B Array:\r\n");
	for (int y=1;y <= n;y++)
		{
		
		fprintf(output,"%5.2lf\t",b1[y]);
		
		}
	fprintf(output,"\r\n");
	fprintf(output,"\r\n");
	fprintf(output,"c Array:\r\n");
	for (int y=1;y <= n;y++)
		{
		
		fprintf(output,"%5.2lf\t",c1[y]);
		
		}
	fprintf(output,"\r\n");
	fprintf(output,"\r\n");
	fprintf(output,"D Array:\r\n");
	for (int y=1;y <= n;y++)
		{
		
		fprintf(output,"%5.2lf\t",z1[y]);
		}
	fprintf(output,"\r\n");
	fprintf(output,"\r\n");
	fprintf(output,"Solutions:\r\n");
	i=1;
	for (int y=1;y <= n;y++)
		{
		
		fprintf(output,"X%i = %5.2lf\t",i, x1[y]);
		i++;
		}
	fprintf(output,"\r\n");
	fprintf(output,"\r\n");	
	
//these loops will be repeated to write the results from matrix 2

fprintf(output,"Matrix 2 components and solution:\r\n");
fprintf(output,"A Array:\r\n");



	for (int y=1;y <= n;y++)
		{
		
		fprintf(output,"%5.2lf\t",a2[y]);
		
		}
	fprintf(output,"\r\n");
	fprintf(output,"\r\n");
	fprintf(output,"B Array:\r\n");
	for (int y=1;y <= n;y++)
		{
		
		fprintf(output,"%5.2lf\t",b2[y]);
		
		}
	fprintf(output,"\r\n");
	fprintf(output,"\r\n");
	fprintf(output,"c Array:\r\n");
	for (int y=1;y <= n;y++)
		{
		
		fprintf(output,"%5.2lf\t",c2[y]);
		
		}
	fprintf(output,"\r\n");
	fprintf(output,"\r\n");
	fprintf(output,"D Array:\r\n");
	for (int y=1;y <= n;y++)
		{
		
		fprintf(output,"%5.2lf\t",z2[y]);
		}
	fprintf(output,"\r\n");
	fprintf(output,"\r\n");
	fprintf(output,"Solutions:\r\n");
	i=1;
	for (int y=1;y <= n;y++)
		{
		
		fprintf(output,"X%i = %5.2lf\t",i, x2[y]);
		i++;
		}	
	fprintf(output,"\r\n");
	fprintf(output,"\r\n");	
	fclose(output);
}



int main ()
{
//initial arrays necessary for calculation
double A1[11], B1[11], C1[11], Z1[11], X1[11], A2[11], B2[11], C2[11], Z2[11], X2[11], n, garbage;
	int y;
//arrays for saving input arrays for later output
double A1x[11], B1x[11], C1x[11], Z1x[11], A2x[11], B2x[11], C2x[11], Z2x[11];
printf("check");

	FILE * input;
input = fopen ("thomasdata.txt","r");
if (input == 0) { printf("OwOops");}
printf("check");
		//loop to read matrix 1 into arrays A1,  B1, and C1. 
fscanf(input,"%lf\r\n",&n);
printf("%lf",n);
A1[0]= n;
A1[1]=0;
fscanf(input,"%lf %lf\r\n",&B1[1], &C1[1]);

for (int j=2;j<=n;j++)
	{
		
		for(int i=j-2;i>0;i--)
		{
		fscanf(input,"%lf", &garbage);
		}
	if (j<n)
	{
		
		fscanf(input,"%lf, %lf, %lf\r\n", &A1[j], &B1[j], &C1[j]);
		A1x[j]=A1[j];
		B1x[j]=B1[j];
		C1x[j]=C1[j];
	}
	if (j=n)
	{
		fscanf(input,"%lf %lf\r\n", &A1[j], &B1[j]);
		A1x[j]=A1[j];
		B1x[j]=B1[j];	
	}
	
	}
	
printf("check");
			//loop to read matrix Z1
	for (int y=1;y <= n;y++)
		{
		
		fscanf(input,"%lf\r\n",&Z1[y]);
		Z1x[y]=Z1[y];
		}


//the same loops will be used to read the second matrix
/*
fscanf(input,"%lf\r\n",&n);
A2[0]= n;
A2[1]=0;
fscanf(input,"%lf %lf\r\n",&B1[1], &C1[1]);
y=2;
		
for (int j=2;j<=n;j++)
	{
		for(int i=y-2;i>0;i--)
		{
		fscanf(input,"%lf", &garbage);
		}
		if (j<n)
	{
		
		fscanf(input,"%lf, %lf, %lf\r\n", &A1[y], &B1[y], &C1[y]);
		A1x[y]=A1[y];
		B1x[y]=B1[y];
		C1x[y]=C1[y];
	}
	if (j=n)
	{
		fscanf(input,"%lf %lf\r\n", &A1[y], &B1[y]);
		A1x[y]=A1[y];
		B1x[y]=B1[y];	
	}
	y++;
	}


	for (int y=1;y <= n;y++)
		{
		
		fscanf(input,"%lf\r\n",&Z2[y]);
		Z2x[y]=Z2[y];
		}
*/
elimination(A1,B1,C1,Z1,X1);
elimination(A2,B2,C2,Z2,X2);
A1x[0]=A1[0];
A2x[0]=A2[0];
write(A1x,B1x,C1x,Z1x,X1,A2x,B2x,C2x,Z2x,X2);
		
fclose(input);
return 0;
}