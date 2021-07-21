#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define DIM 3


//void change(int *,int *);
void change(int (*)[DIM]);

int main()
{
	//int arr;
	//int arr[DIM];
	int arr2[DIM][DIM]={0}; // This way of initialisation of 2d array works at the time of declaration
	//int *NFL;
	printf("Hello Hi! \n");
	printf("Hello Hi Inside Master! \n");
	//printf("Changed inside branch! \n");
	printf("Hello Hi I have entered selfgravity branch ! \n");
	//arr=0;
	//NFL=(int *)calloc(10,sizeof(int));
	//printf("size of NFL = %lu \n",sizeof(NFL));
	//printf("size of int = %lu \n",sizeof(int));
	// After the execution of this code one can see that size(NFL) does not give 10 or (10*4)
	// infact the sizeof(NFL) returns 8 irrespective of whether in calloc we have 10, 100 or whatever
	//printf("printing before initialisation\n");
	//for(int i=0;i<DIM;i++)
	//{
		//printf("arr[%d] = %d \n", i, arr[i]);
	//}
	
	printf("printing arr2d before initialisation\n");
	for(int i=0;i<DIM;i++)
	{
		for (int j=0;j<DIM;j++)
		{
			printf("arr2[%d][%d] = %d \n", i, j, arr2[i][j]);
		}
	}
	
	printf("Address of arr2 = %p \n", arr2); //We need %p to print address in C++ while %u in C
	//printf("Address of arr = %p\n", arr);
	
	printf("Address of arr2 = %p \n", &arr2[0][0]);
	//printf("Address of arr = %p\n", &arr[0]);
	
	//changing entries
	for(int i=0;i<DIM;i++)
	{
		//arr[i]=i+1;
		for(int j=0;j<DIM;j++)
		{
			arr2[i][j]=i-j;
		}
	}
	
	for(int arr=0;arr<DIM;arr++)
	{
		//arr[arr]=arr+1;
		printf("Hello. Testing !\n"); // This line doesn't create any problem, while the above one definitely does.
	}

	printf("printing after initialisation\n");
	for(int i=0;i<DIM;i++)
	{
		//printf("arr[%d] = %d \n", i, arr[i]);
		for (int j=0;j<DIM;j++)
		{
			printf("arr2[%d][%d] = %d \n", i,j,arr2[i][j]);
		}
	}
	
	int (*p)[DIM]; //array to pointer used for passing 2d array in function.
	
	//p = &arr2[0][0];
	//int i=2;
	//int j=1;
	//printf(" HELLO ! arr2[i][j] = %d \n",*(p+(i*DIM)+j));
	
	p = arr2;
	
	change(p);
	
	printf("printing after calling change function\n");
	for(int i=0;i<DIM;i++)
	{
		//printf("a = %d \n", a);
		//printf("arr[%d] = %d \n",i,arr[i]);
		for (int j=0;j<DIM;j++)
		{
			printf("arr2[%d][%d] = %d \n", i,j,arr2[i][j]);
		}
	}
	
	//printf("printing arr variable NOT array = %ds \n", arr);
	
	return (0);
}

//void change(int *x,int *y)
/*{
	for(int i=0;i<DIM;i++)
	{
		x[i]=(int)pow(i,2.0);
		for(int j=0;j<DIM;j++)
		{
			y[i][j]=i+j;
		}
		//x[i]=0;
	}
	
	printf("printing within change function\n");
	for(int i=0;i<DIM;i++)
	{
		printf("x[%d] = %d \n", i, x[i]);
		for (int j=0;j<DIM;j++)
		{
			printf("x[%d][%d] = %d \n", i,j,y[i][j]);
		}
	}
}*/

void change(int (*y)[DIM])
{
	for(int i=0;i<DIM;i++)
	{
		for(int j=0;j<DIM;j++)
		{
			*( *(y + i) + j) = i + j;
		}
	}

	printf("printing within change function\n");
	for(int i=0;i<DIM;i++)
	{
		for (int j=0;j<DIM;j++)
		{
			printf("arr2[%d][%d] = %d \n", i,j,2*(*( *(y + i) + j)));
		}
	}
	printf("Check %p \n", *(y+1));

}
