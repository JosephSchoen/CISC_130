/** Joseph Schoen **/
#include <stdio.h>
#include <math.h>

/** This program is designed to run six different problems, which is stated
where each one is in the code. The following problems are:

1) Ask the user to enter a positive integer. Calculate the floor of the inputted value's square root
(i.e. calculate the closest integer value equal to, or less than, its square root.) Output the
results.

2) Ask the user to enter two positive integer. Calculate the greatest common divisor of the two
numbers. Output the results.

3) A perfect number is a positive integer that is equal to the sum of its factors excluding itself. For
example, 6 is a perfect number because 1+2+3 = 6. Ask the user to enter a positive integer, then
display the next largest perfect number.

4) Create and initialize an array of 10 integers. Print them out. To complete this task you are
allowed to call printf in 1 function outside of main.

5) Create and initialize two integers arrays that
contain 10 numbers a piece. Calculate and display their dot product. You are not allowed to use
printf but you can use your solution to problem 4.

6) Create and initialize a 10 by 10 2D array. Display it. You are not allowed to use printf but you
are allowed to use your solution from problem 4.

**/




/** PROBLEM ONE **/

/** This function takes the input integer the user gave, and then finds the
square root by the math function sqrt(). This will truncate any decimal place
values, since it is assigning to a variable. We are looking for the greatest
whole value square root, so this is perfect. Then is returns the value back. **/
int squaring(int sqrt_int)
{
    int result = sqrt(sqrt_int);
    return result;
}

/** The result from the squaring function is now displayed here if the coder
calls for it. In this I did call this function with the result of the sqrt()
command and display it using a printf. This is a void function. **/
void displaysqrt(int sqrt)
{
    printf("Your closest whole value square root is: %i\n", sqrt);
}


/** PROBLEM TWO **/

/** This integer function calculates the greatest common divisor of two integer
inputs. It does this by finding the largest value of the two integers, using a
conditional statement. Whichever is bigger will be set equal to i. Then a new
integer is made as a loop stopper called loop_end. This next loop runs when
loop_end does not equal 1. The loop checks with an if statement to see if both
the integers result in a remainder of 0 when the modulus of i (which is the
greatest value of the two integers) is true. If it is not, i will subtract 1.
It will continue until it finds a value of i that both integers will result
in a remainder of 0. Once it finds that value of i, it will return. **/
int divisor(int div_1, int div_2)
{
    int i;
    if(div_1 > div_2)
    {
        i = div_1;
    }
    else
    {
        i = div_2;
    }

    int loop_end = 0;

    while(loop_end != 1)
    {
        if(div_1%i == 0 && div_2%i == 0)
        {
            loop_end = 1;
        }
        else
        {
            i = i - 1;
        }
    }
    int result = i;
    return result;
}


/** This function is called to display the two divisor inputs the user entered,
and then displays them and the greatest common denominator. **/
void displaydivisor(int A, int B, int C)
{
    printf("The greatest common divisor of %i and %i is: %i\n", A, B, C);
}

/** PROBLEM THREE **/

/** This code for the function perfectnumtest is all the work for finding the
next perfect number. Whatever number the user inputs, will be placed in for
num_ask. 1 is added to that value, in the case that they entered a perfect
number. The main loop tests for if the loop_end equals 1, in which the number
is a perfect number. Within the next loop, i increases until it equals the
number that num_ask equals. Each time the value of i is a divisor, it adds
it to the variable a, then increases i by 1. Once i is equal to num_ask, the
loop ends. If the value of a is equivalent to num_ask, it sets the loop_end to
1 so the whole loop ends, if not, it increases num_ask by 1, resets i and a.
Whenever the loop completes, meaning it found the next perfect number, it will
return the value of num_ask. **/
int perfectnumtest(int num_ask)
{
    num_ask = num_ask + 1;
    int i = 1; //Incrementer
    int loop_end = 0; //Used to stop loop if it were to equal 1
    int a = 0; //Finding the value of all common divisors of the given number

    while(loop_end != 1)
    {
        while(i != num_ask)
        {
            if(0 == (num_ask % i))
            {
                a = a + i;
                i = i + 1;
            }
            else
            {
                i = i + 1;
            }

        }
        if(a == num_ask)
        {
            loop_end = 1;
        }
        else
        {
            i = 1;
            a = 0;
            num_ask = num_ask + 1;
        }
    }

    int result = num_ask;
    return result;
}

/** Displays the next perfect number based on the users input integer. **/
void displayperfectnum(int input, int perfectnum)
{
    printf("The next perfect number from %i is: %i\n", input, perfectnum);
}


/** PROBLEM FOUR **/

/** This function will be given the location of the array and the array size,
which would be called from another function. It will place a random number
into each index in the array, by using a while loop. There is a modulus for
the random number, that way all the numbers in each index will be between 0
and 9. This does not return anything, because it is simply replacing the values
of the indexes for the inputed array. **/
int initial_arr(int Arr[], int size)
{
    int i = 0;
    while(i < size)
    {
        Arr[i] = rand() % 10;
        i = i + 1;
    }
}

/** This function displays each index in an array. The caller needs to supply
an array, the size of the array, and either a 0 or an int for integer A. The
reason this is in place is so that, if there is a dot product that needs to be
displayed only when it is applicable. This function is used for problem four,
five and six. The code will increment i and display each index until each
index has been displayed, determined by the int size. Then the program moves
down a line for the next text. If there is a dot product that is put in the
calling of the function, which means a value that is not 0, it will also
display the dot product value. **/
void displayarray(int Arr[], int size, int A)
{
    int i = 0; //Incrementer
    printf("The following are in the array at each index: ");
    while(i < size)
    {
        printf("%i, ", Arr[i]); //Printing a specific index
        i = i + 1;
    }
    printf("\n");
    if(0 != A) //If there is a dot product value, it will display.
    {
        printf("The dot product is %i\n", A);
    }
}


/** PROBLEM FIVE **/

/** This function calculates the dot product of two arrays. It takes each index
of both arrays and multiplies them, and then adds that to the next index. The
int product is used to find the value of the two indices multiplied, and the
int total is used to add up all the values. Total starts at 0, and adds each
product to its value until it adds the product of each index in the array.
Once it is done with the loop, or all indices have been multiplied, it will
call the displayarray function to display the first array, and then the
second array, along with the dot product total the second time so it is
displayed correctly. The 0 is so no dot product will display when calling
the function. **/
int dotproductcalc(int A[], int B[], int sz)
{
    int i = 0;
    int product;
    int total = 0;
    while(i < sz)
    {
        product = A[i] * B[i];
        total = total + product;
        i = i + 1;
    }

    displayarray(A, sz, 0);
    displayarray(B, sz, total);
}

/** PROBLEM SIX **/

/** This function creates a two dimensional array and will display it. It
starts by being given the size of the array in rows and columns. It takes
those inputs and creates an integer array with the given inputs. Then two
incrementing variables are created. The loops place random variables in the
columns, or the second dimension. Once again, like problem four, it initializes
only numbers 0 through 9. j resets for each time the whole loop runs, since
it needs to put it a new second dimension based on the first. It does this
for each first dimension. Once all rows and columns are filled, it will display
the array using the  displayarr function. Using a loop for how many rows there
are, it will display the second dimension. 0 is in the last input so it does
not display a dot product, since this problem does not have that as a requested
result. **/
int twodarray(int size_row, int size_col)
{
    int Array[size_row][size_col];
    int i = 0;
    int j = 0;
    while(i < size_row)
    {
        j = 0;
        while(j < size_col)
        {
            Array[i][j] = rand() % 10;
            j = j + 1;
        }
        i = i + 1;
    }

    i = 0;
    while(i < size_row)
    {
        displayarray(Array[i], size_row, 0);
        i = i + 1;
    }
}

int main()
{
    srand((unsigned)time(NULL));


    /** PROBLEM ONE **/
    printf("PROBLEM ONE\n");

    int sqrt_int; //Making variable for find square root
    printf("Please enter a positive integer: ");
    scanf(" %i", &sqrt_int); //Asking user for the desired number

    /** This is calling the function squaring, with the input integer as
    variable sqrt_int that the user gave. It will return a value.**/
    int sqrt_result = squaring(sqrt_int);

    /** This will call a function to display the closest whole value that
    the square root could be, using the result from the squaring function. **/
    displaysqrt(sqrt_result);



    /** PROBLEM TWO **/
    printf("\nPROBLEM TWO\n");



    int div_1; //div is short for divisor, in this case divisor 1
    int div_2; //div used for divisor 2

    /** Asking the user for positive values in both integers **/
    printf("\nPlease enter a positive integer: ");
    scanf(" %i", &div_1);
    printf("Please enter another positive integer: ");
    scanf(" %i", &div_2);

    /** This is calling the function greatdiv, and giving the inputs
    of **/
    int greatdiv = divisor(div_1, div_2);

    /** This will call the void function to display the value of the
    greatest divisor of the two input values. **/
    displaydivisor(div_1, div_2, greatdiv);

    /** Problem THREE **/
    printf("\nPROBLEM THREE\n");

    int num_input; //Integer the user can input
    printf("Please enter a positive number: "); //Requesting int value
    scanf(" %i", &num_input);

    int nxtperfectnum = perfectnumtest(num_input); //Calling perfectnumtest

    /** Calls for the printf to display the next perfect number from the
    users input. **/
    displayperfectnum(num_input, nxtperfectnum);



    /** PROBLEM FOUR **/
    printf("\nPROBLEM FOUR\n");

    /** An array with a given size made in a variable is created. In this case,
    the array has 10 indices. Then the function intitial_arr is called to place
    in values to each index. The function will run and initialize it. We give
    the location of our array, and the size of it to the function. Once the
    function is complete, we then can display the array using displayarray
    function. This takes the inputs of the array, the array size, and a third
    input for if there is a dot product involved. If there is, the value should
    be 1, if not, the value is then 0. **/
    int arr_sz = 10;
    int array[arr_sz];
    initial_arr(array, arr_sz);

    displayarray(array, arr_sz, 0);



    /** PROBLEM FIVE **/
    printf("\nPROBLEM FIVE\n");

    /** Just like problem four, we created an array with 10 indices. We then
    create a second array and do the same thing. Once both arrays are
    initialized, we then call a new function. This function is dotproductcalc.
    This function takes both arrays as an input, and then the size of them.
    This will calculate the dot product, and eventually use the same display
    function that problem four used, but within the function we just called.**/
    int Arrayfirst[arr_sz];
    int Arraysecond[arr_sz];

    initial_arr(Arrayfirst, arr_sz);
    initial_arr(Arraysecond, arr_sz);

    dotproductcalc(Arrayfirst, Arraysecond, arr_sz);


    /** PROBLEM SIX **/
    printf("\nPROBLEM SIX\n");

    /** This code calls the function twodarray. This function creates a two
    dimensional array using two sizes. One size is for the rows, the other
    is for the amount of columns. In our case, we want a 10x10 array. We can
    use the same arr_sz we have been previously using, and then the function
    will create the array with those sizes and initialize it. **/

    twodarray(arr_sz, arr_sz);
}

