-----------------------------------------------------------

vi kernal4.c

#include<stdio.h>
#include <unistd.h>

int main()
{
	fork();
	fork();
	printf("Hello world!\n");
	return 0;
}

gcc kernal4.c -o kernal4

./kernal4

Output:-

Hello world!
Hello world!
Hello world!
Hello world!

------------------------------
vi kernal5.c

#include<stdio.h>
#include <unistd.h>

int main()
{
	int f=fork();
	
	if(f==0)
	{
		printf("I am the child process\n");
		printf("My parent id is %d\n ",getppid());
	}
	else
	{
		printf("I am the parent\n");
		printf("My parent id is %d\n ",getpid());
	}
	return 0;
}

gcc kernal5.c -o kernal5

./kernal5
Output:-

I am the parent
My parent id is 14839
 I am the child process
My parent id is 14839

---------------------------------------------------
/*
print numbers from 1 to 10 and 
1 to 5 should print by child process and 
from 6 to 10 should be parent process
calculate summation of those numbers
*/

vi kernal6.c

#include<stdio.h>
#include <unistd.h>

int main(){
	
	int i;
	int sum_parent=0, sum_child=0;
	
		int f=fork();
		
		if(f==0)
		{
			printf("Print by child process..\n");
			for(i=1; i<=5; i++){
				printf("%d\n",i);
				sum_child=sum_child+i;
			}
			printf("summation of printing by child process is %d\n ", sum_child);
			
		}
		else
		{
			printf("Print by parent process\n");
			for(i=6; i<=10; i++){
				printf("%d\n",i);
				sum_parent=sum_parent+i;
			}
			printf("summation of printing by child process is %d\n ", sum_parent);
		}
	
	
	return 0;
}



// or without sum

#include<stdio.h>
#include <unistd.h>

int main(){
	
	int n;
	int sum=0;
	
		int id=fork();
		
		if(id==0)
		{
			n=1;
			printf("Print by child process..\n");	
		}
		else
		{
			n=6;
			printf("Print by parent process\n");	
		}
		
		for(int i=n; i<n+5; i++)
		{
			printf("%d\n",i);	
		}
	
	
	return 0;
}


gcc kernal6.c -o kernal6

./kernal6

Output:-

Print by parent process
6
7
8
9
10
summation of printing by child process is 40
 Print by child process..
1
2
3
4
5
summation of printing by child process is 15

 