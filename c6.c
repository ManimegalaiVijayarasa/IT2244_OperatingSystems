---------------------------------------------------------------------
vi kernal8.c

#include<stdio.h>
#include <stdlib.h> // for exit()
#include <unistd.h> // for sleep()

int main()
{
	printf("Program started.\n");
	
	printf("Sleeping for 3 seconds...\n");
	sleep(3); // pause for 3 seconds
	
	printf("Exiting the program.\n");
	exit(0);  //clean exit
	
	return 0;
}



gcc kernal8.c -o kernal8

./kernal8


Output:-

Program started.
Sleeping for 3 seconds...
Exiting the program.

--------------------------------------------------------------------

vi kernal9.c

#include<stdio.h>
#include <stdlib.h> // for exit()
#include <unistd.h> // for fork() , sleep()
#include <sys/wait.h> // for wait()

int main(){
	pid_t pid;
	
	printf("Parent process started. PID: %d\n", getpid());
	
	pid= fork(); // create a new child process
	
	if (pid < 0){
		perror("fork failed");
		exit(1);
	}
	
	if (pid==0) {
		//child process
		printf("Child process. PID %d, sleeping for 2 seconds...\n ", getpid());
		sleep(2);
		printf("Child process exiting.\n");
		exit(0); // child exits with status 0
	} else {
		// parent process
		int status;
		printf("Parent waiting for child to finish...\n");
		wait(&status); // wait for child to finish
		
		if (WIFEXITED(status)) { // WIFEXITED(status) returns true if child for terminated
			printf("Child exited with status : %d\n", WEXITSTATUS(status));
			// WEXITSTATUS(status) gets the actual exits code here (0)
		} else {
			printf("Child did not exit normally.\n");
		}
		printf("Parent process ending.\n");
	}
	
	return 0;
}

gcc kernal9.c -o kernal9

./kernal9


Output:-

Parent process started. PID: 9489
Parent waiting for child to finish...
Child process. PID 9490, sleeping for 2 seconds...
 Child process exiting.
Child exited with status : 0
Parent process ending.

-----------------------------------------------------------------------------------
/*exercise01:

First child: Slept for 1 second.
Second child: slept for 3 seconds.
Parent: Both children have finished.
*/

vi kernal10.c

#include<stdio.h>
#include <stdlib.h> // for exit()
#include <unistd.h> // for fork() , sleep()
#include <sys/wait.h> // for wait()

int main(){
	pid_t pid;
	
	printf("Parent process started. PID: %d\n", getpid());
	
	pid= fork(); // create a new child process
	
	if (pid < 0){
		perror("fork failed");
		exit(1);
	}
	
	if (pid==0) {
		//First child process
		printf("First Child process. PID %d, sleeping for 1 seconds...\n ", getpid());
		sleep(1);
		printf("First Child process exiting.\n");
		exit(0); // child exits with status 0
	} else {
		pid= fork(); // create a new child process
	
		if (pid < 0){
			perror("fork failed");
			exit(1);
		}
		
		if(pid==0) {
			//Second child process
			printf("Second Child process. PID %d, sleeping for 3 seconds...\n ", getpid());
			sleep(3);
			printf("Second Child process exiting.\n");
			exit(0); // child exits with status 0
		}
		else{
			// parent process
		int status;
		printf("Parent waiting for both children have finished...\n");
		wait(&status); // wait for child to finish
		
		if (WIFEXITED(status)) {
			printf("Child exited with status : %d\n", WEXITSTATUS(status));
		} else {
			printf("Child did not exit normally.\n");
		}
		printf("Parent process ending.\n");
		}
		
	}
	
	return 0;
}



gcc kernal10.c -o kernal10

./kernal10


Output:-

Parent process started. PID: 12689
Parent waiting for both children have finished...
First Child process. PID 12690, sleeping for 1 seconds...
Second Child process. PID 12691, sleeping for 3 seconds...
 First Child process exiting.
Child exited with status : 0
Parent process ending.






#include <stdio.h>
#include <stdlib.h>  // for exit()
#include <unistd.h>  // for fork(), sleep()
#include <sys/wait.h> // for wait()

int main() {
    pid_t pid1, pid2;
    int status;

    printf("Parent process started. PID: %d\n", getpid());

    // First child
    pid1 = fork();
    if (pid1 < 0) {
        perror("First fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        // First child process
        sleep(1);
        printf("First child: Slept for 1 second.\n");
        exit(0);
    }

    // Second child
    pid2 = fork();
    if (pid2 < 0) {
        perror("Second fork failed");
        exit(1);
    }

    if (pid2 == 0) {
        // Second child process
        sleep(3);
        printf("Second child: Slept for 3 seconds.\n");
        exit(0);
    }

    // Parent process waits for both children
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);

    printf("Parent: Both children have finished.\n");

    return 0;
}


Output:-

Parent process started. PID: 13969
First child: Slept for 1 second.
Second child: Slept for 3 seconds.
Parent: Both children have finished.


-----------------------------------------------------------------------------------------------------------------

/*exercise02:

First child: Sleeps for 2 second,exits with status 2.
Second child: sleeps for 1 seconds,exits with status 1.
Parent: waits twice , and prints which child(by PID or exit code) finished first and second.
*/

vi kernal11.c

#include <stdio.h>
#include <stdlib.h>     // exit()
#include <unistd.h>     // fork(), sleep()
#include <sys/wait.h>   // wait()

int main() {
    pid_t pid1, pid2;
    int status;
    pid_t finished_pid1, finished_pid2;

    printf("Parent process started. PID: %d\n", getpid());

    // First child
    pid1 = fork();
    if (pid1 < 0) {
        perror("First fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        sleep(2);
        printf("First child: Slept for 2 seconds.\n");
        exit(2); // Exit with status 2
    }

    // Second child
    pid2 = fork();
    if (pid2 < 0) {
        perror("Second fork failed");
        exit(1);
    }

    if (pid2 == 0) {
        sleep(1);
        printf("Second child: Slept for 1 second.\n");
        exit(1); // Exit with status 1
    }

    // Parent waits for both children and tracks the order
    finished_pid1 = wait(&status);
    if (WIFEXITED(status)) {
        printf("Parent: First finished child PID: %d, Exit status: %d\n", finished_pid1, WEXITSTATUS(status));
    }

    finished_pid2 = wait(&status);
    if (WIFEXITED(status)) {
        printf("Parent: Second finished child PID: %d, Exit status: %d\n", finished_pid2, WEXITSTATUS(status));
    }

    return 0;
}

gcc kernal11.c -o kernal11

./kernal11


Output:-

Parent process started. PID: 14109
Second child: Slept for 1 second.
Parent: First finished child PID: 14111, Exit status: 1
First child: Slept for 2 seconds.
Parent: Second finished child PID: 14110, Exit status: 2

---------------------------------------------------------------------------------------------------------------------------------------

/*exercise03:

The parent creates a child process.
The child creates a grandchild process.
The grandchild sleeps 2 seconds and exits with status 2.
The child waits for the grandchild, prints its exit status,
then exits with status 55.
*/

vi kernal12.c

#include <stdio.h>
#include <stdlib.h>     // exit()
#include <unistd.h>     // fork(), sleep()
#include <sys/wait.h>   // wait()

int main() {
    pid_t child_pid, grandchild_pid;
    int status;

    printf("Parent process started. PID: %d\n", getpid());

    child_pid = fork();
    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0) {
        // Inside child process
        printf("Child process started. PID: %d, Parent PID: %d\n", getpid(), getppid());

        grandchild_pid = fork();
        if (grandchild_pid < 0) {
            perror("Grandchild fork failed");
            exit(1);
        }

        if (grandchild_pid == 0) {
            // Inside grandchild process
            printf("Grandchild process started. PID: %d, Parent PID: %d\n", getpid(), getppid());
            sleep(2);
            printf("Grandchild: Slept 2 seconds. Exiting with status 2.\n");
            exit(2);
        } else {
            // Child waits for grandchild
            wait(&status);
            if (WIFEXITED(status)) {
                printf("Child: Grandchild exited with status %d.\n", WEXITSTATUS(status));
            } else {
                printf("Child: Grandchild did not exit normally.\n");
            }
            printf("Child: Exiting with status 55.\n");
            exit(55);
        }
    } else {
        // Parent process
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Parent: Child exited with status %d.\n", WEXITSTATUS(status));
        } else {
            printf("Parent: Child did not exit normally.\n");
        }
    }

    return 0;
}

gcc kernal12.c -o kernal12

./kernal12


Output:-

Parent process started. PID: 14214
Child process started. PID: 14215, Parent PID: 14214
Grandchild process started. PID: 14216, Parent PID: 14215
Grandchild: Slept 2 seconds. Exiting with status 2.
Child: Grandchild exited with status 2.
Child: Exiting with status 55.
Parent: Child exited with status 55.


