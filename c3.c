-------------------------------------------------
// Kernal in C

vi kernal1.c

#include<stdio.h>
#include <unistd.h>

int main(){
        printf("\nHello world");
        int f=fork();
        int p=getpid();

        printf("\n The pid is %d", p);
        printf("\n The pid id %d", f);

return 0;
}

press Esc
type :wq!

gcc kernal1.c -o kernal1

./kernal1


Output:-

Hello world
 The pid is 11463
 The pid id 11464Hello world
 The pid is 11464
 The pid id 0
------------------------------------------------------

vi kernal2.c

#include<stdio.h>
#include <unistd.h>

int main(){
	
        int f=fork();
		
		if(f==0)
		{
			printf("I am child\n");
		}
		else{
			printf("I am parent\n");
        }

return 0;
}

press Esc
type :wq!

gcc kernal2.c -o kernal2

./kernal2

Output:-
I am parent
I am child

-------------------------------------------------------


#include<stdio.h>
#include <unistd.h>

int main(){
	fork();
	
    printf("\nHello world\n");
        
return 0;
}



Output:- 
Hello world

Hello world
---------------------------------------------------------

#include<stdio.h>
#include <unistd.h>

int main(){
	fork();
	fork();
	
    printf("\nHello world\n");
        
return 0;
}


Output:-
Hello world

Hello world

Hello world
Hello world

---------------------------------------------------------
vi kernal3.c

#include<stdio.h>
#include <unistd.h>

int main(){

	int f = fork();
	
	if(f==0){
		printf("I am Child\n");
		printf("My parent ID %d\n", getppid());
	}
	else{
		int f1=fork();
		if(f1==0)
		{
			printf("I am Sibiling\n");
			printf("My parent ID %d\n", getppid());
		}
		else
		{
			printf("I am parent\n");
			printf("My Id %d\n",getpid());
			printf("My parent ID %d\n", getppid());
		}
	}

return 0;
}

press Esc
type :wq!

gcc kernal3.c -o kernal3

./kernal3

Output:-
I am parent
My Id 24179
My parent ID 2948
I am Child
My parent ID 24179
I am Sibiling
My parent ID 24179


