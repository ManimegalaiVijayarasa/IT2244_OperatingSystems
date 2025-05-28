--------------------------------------------------

/*   //syntax for if else
	
if(condition){
	//body of if statement;
}
else{
	// body of else statement
}
*/

// q1.Enter your age and verify your aligible or not for election voting using if else condition

vi ifelse.c

#include<stdio.h>

int main(){
	int age;
	printf("Enter your age : ");
	scanf("%d", &age);
	printf("Your age is :%d ",age);
	
	if(age<0){
		printf("\nInvalid age.");
	}
	else if(age>=18){
		printf("\nYou are eligible for election voting.");
	}
	else{
		printf("\nYou are not eligible for electionvoting.");
	}

return 0;	
}

press Esc
type :wq!


gcc ifelse.c -o ifelse    

./ifelse
	

Output:-
Enter your age : 24
Your age is :24
You are eligible for election voting.

//or
Enter your age : 17
Your age is :17
You are not eligible for electionvoting.

--------------------------------------------------
// Ternary operator

/* // syntax

test_condition ? expression1 : expression2;
*/

vi ternary.c

#include<stdio.h>
int main(){
	int age;
	printf("Enter your age : ");
	scanf("%d", &age);
	printf("Your age is :%d ",age);
	
	(age>=18) ? printf("You are eligible for election voting.") : printf("\nYou are not eligible for electionvoting.");

return 0;	
}

press Esc
type :wq!

gcc ternary.c -o ternary
./ternary


Output:-
Enter your age : 24
Your age is :24 
You are eligible for election voting.

//or
Enter your age : 12
Your age is :12 
You are not eligible for electionvoting.

----------------------------------------------------

// switch case
/* // syntax
	
	switch (expression) {
  case x:
    // code block
    break;
  case y:
    // code block
    break;
  default:
    // code block
}

*/


vi switchCase.c

#include<stdio.h>
int main(){
	int day;
	printf("Enter the number between 1 to 7 : ");
	scanf("%d", &day);
	printf("You entered : ", day);

switch (day) {
  case 1:
    printf("Today is Monday");
    break;
  case 2:
    printf("Today is Tuesday");
    break;
  case 3:
    printf("Today is Wednesday");
    break;
  case 4:
    printf("Today is Thursday");
    break;
  case 5:
    printf("Today is Friday");
    break;
  case 6:
    printf("Today is Saturday");
    break;
  case 7:
    printf("Today is Sunday");
    break;
  default:
  printf("Invalid number.");
	
}

return 0;	
}

press Esc
type :wq!

gcc switchCase.c -o switchCase

./switchCase


Output:-
Enter the number between 1 to 7  : 5
You entered : Today is Friday

----------------------------------------------------
/*
example:-
write a code for small astrology based on your life path number for that get date of birth from user then calculate life path number.(use switch case)


Date:23

	Calculation for life path number:
			a=date%10
			b=date/10
			c=a+b
		
		if life path number:
			1:Lucky
			2:Carefuly do your work
			3:Storger
			4:Happy
			5:Can get help
			6:Doubt
			7:Sad
			8:Like
			9:Courage

*/

vi lifePath.c

#include<stdio.h>
int main(){
	int date;
	printf("Enter the date : ");
	scanf("%d", &date);
	printf("You entered :%d ", date);
	
	int a= date%10;
	int b= date/10;
	int c= a+b;
	
	switch (c) {
		case 1:
			printf("\nLucky. ");
			break;
		case 2:
			printf("\nCarefuly do your work. ");
			break;
		case 3:
			printf("\nStorger ");
			break;
		case 4:
			printf("\nHappy. ");
			break;
		case 5:
			printf("\nCan get help. ");
			break;
		case 6:
			printf("\nDoubt. ");
			break;
		case 7:
			printf("\nSad. ");
			break;
		case 8:
			printf("\nLike. ");
			break;
		case 9:
			printf("\nCourage ");
			break;
		default :
			printf("Invalid number");
	}
	

return 0;	
}

press Esc
type :wq!

gcc lifePath.c -o lifePath

./lifePath


Output:-
Enter the date : 23
You entered :23
Can get help. 
----------------------------------------------------

// for loop

/*
syntax
for (expression 1; expression 2; expression 3) {
  // code block to be executed
}
*/

/*
Give list of numbers then calculate the summation and multiplication using for loop
example:-
		1 2 3 4 5
		summation=15
		multiplication=120

*/
vi forloop.c

#include<stdio.h>
int main(){
	
    int numbers[] = {1, 2, 3, 4, 5};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    
    int summation = 0;
    int multiplication = 1;
    
    for (int i = 0; i < length; i++) {
        summation += numbers[i];
        multiplication *= numbers[i];
    }
    
    printf("Summation = %d\n", summation);
    printf("Multiplication = %d\n", multiplication);
    
    return 0;
}


press Esc
type :wq!

gcc forloop.c -o forloop

./forloop

Output:-
Summation = 15
Multiplication = 120


----------------------------------------------------
/* while loop
syntax
while (condition) {
  // code block to be executed
}
*/

/*
print the integers from 1 to 10 using while loop

*/

vi whileloop.c

#include<stdio.h>

int main() {
    int i = 1;

    while (i <= 10) {
        printf("%d ", i);
        i++;
    }

    return 0;
}

press Esc
type :wq!

gcc whileloop.c -o whileloop

./whileloop

Output:-
1 2 3 4 5 6 7 8 9 10

----------------------------------------------------
/*
	 Fibbonacci series
	Output:- First 10 fibonacci numbers:
			 0 1 1 2 3 5 8 13 21 34

*/

vi fibbonacci.c

#include <stdio.h>

int main() {
    int n; 
	printf("Enter the number you want fibonacci : ");
	scanf("%d", &n);
	
    int first = 0, second = 1, next;

    printf("First" ,n, " Fibonacci numbers:\n");
    printf("%d %d ", first, second);

    for (int i = 3; i <= n; i++) {
        next = first + second;
        printf("%d ", next);
        
        first = second;
        second = next;
    }
    printf("\n");

    return 0;
}


press Esc
type :wq!

gcc fibbonacci.c -o fibbonacci

./fibbonacci


Output:-
Enter the number you want fibonacci : 10
First0 1 1 2 3 5 8 13 21 34


----------------------------------------------------

// calculate the factorial of a non-negative integer

vi factorial.c

#include <stdio.h>


int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num;

    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative integers.\n");
    } else {
        printf("Factorial of %d is %lld\n", num, factorial(num));
    }

    return 0;
}



press Esc
type :wq!

gcc factorial.c -o factorial

./factorial

Output:-
Enter a non-negative integer: 5
Factorial of 5 is 120

//or
Enter a non-negative integer: 0
Factorial of 0 is 1

//or
Enter a non-negative integer: -1
Factorial is not defined for negative integers.

----------------------------------------------------

// Accepts two strings ars input from the user and concatenates the two strings displays the concatinated result

vi concatinate.c

#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], result[200];

    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);

    // Remove the newline character added by fgets
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remove the newline character added by fgets
    str2[strcspn(str2, "\n")] = '\0';

    // Concatenate the two strings
    strcpy(result, str1);  // Copy first string to result
    strcat(result, str2);  // Append second string to result

    printf("Concatenated String: %s\n", result);

    return 0;
}


press Esc
type :wq!

gcc concatinate.c -o concatinate

./concatinate

Output:-
Enter the first string: Manimegalai
Enter the second string: Vijayarasa
Concatenated String: ManimegalaiVijayarasa

----------------------------------------------------
//takes a binary number(as an integer) as input and converts it to its decimal equivalent.

vi binaryToDecimal.c

#include <stdio.h>
#include <math.h>

int main() {
    int binary, decimal = 0, remainder, base = 1;

    printf("Enter a binary number: ");
    scanf("%d", &binary);

    while (binary > 0) {
        remainder = binary % 10;        
        decimal += remainder * base;    
        binary /= 10;                  
        base *= 2;                      
    }
	
    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}


press Esc
type :wq!

gcc binaryToDecimal.c -o binaryToDecimal

./binaryToDecimal

Output:-
Enter a binary number: 101
Decimal equivalent: 5

//or
Enter a binary number: 1010
Decimal equivalent: 10

----------------------------------------------------