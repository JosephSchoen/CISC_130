/** Joseph Schoen **/
#include <stdio.h>
#include <stdlib.h>

/** In this lab, we are given a series of short tasks to utilize the recursion
process. There are nine different tasks, or problems, that are in this file.**/

/** PROBLEM ONE **/

/** In this, the main calls the function with an integer that has a value of 0,
and the user gets to enter a positive number. If the user enters a negative
number, they must try again. Whenever the number is a positive, the function
will return that value to the function call. **/
int positiveint(int a)
{
    printf("Please enter a positive number: ");
    scanf(" %i", &a);

    int retval = 0;
    //Base Case
    if(0 <= a)
    {
        retval = a;
    }
    //General Case
    else
    {
        retval = positiveint(a);
    }
    return retval;
}

/** PROBLEM TWO **/

/** This function takes a base input, and an exponent input to perform an
exponential action. An int retval is created for a return value of what the
exponential value is. The function takes the exponent, and if it is divisible
by 2, it will divide the exponent by 2, and keep doing that until it hits
the base case, which is the base. Once it finds how many times the base needs
to be multiplied, it will take that value and double it, since we split the
exponent in half to do half the work, and then we essentially multiply them
together, or square the value. Otherwise, the exponent is not divisible by
2, it will multiple the function of the exponent - 1 to base, so it becomes
a even number power, and then once it finishes running, it will utilize
the last multiplication of base.**/
int powerfunc(int base, int exp)
{
    int retval = 0;
    //Base Case
    if(1 == exp)
    {
        retval = base;
    }
    //General Cases
    else if(exp % 2 == 0)
    {
        retval = powerfunc(base, (exp / 2));
        retval = retval * retval;
    }
    else if(exp % 2 == 1)
    {
        retval = base * powerfunc(base, (exp - 1));
    }
    return retval;
}

/** PROBLEM THREE **/

/** This function fills an array. The main uses an array, with a size of int
size, and an incrementing i starting at 0. Then, we need to fill the int arr
with numbers ranging from 5 to 267. The random variable is assigned an int that
is between 5 and 267. Then at index that is 1 less than the size, the function
puts in the last value into that index, and then sets the next index to null.
Then the function is voided. **/
void fillarr(int arr[], int size, int i)
{
    int random = (rand() % 263) + 5;
    //Base Case
    if((i + 1) == size)
    {
        arr[i] = random;
        arr[i + 1] = '\0';
    }
    //General Case
    else
    {
        arr[i] = random;
        fillarr(arr, size, (i + 1));
    }
}

/** PROBLEM FOUR **/

/** This function is given the same inputs as problem three, with the arr, size
and an incrementing i variable. It will print out each array index as i is inc
until at (i + 1) is equivalent to size. Then it will display the last position
which would be i, then void the function.**/
void displayarr(int arr[], int size, int i)
{
    //Base Case
    if((i + 1) == size)
    {
        printf("%i", arr[i]);
    }
    //General Case
    else
    {
        printf("%i, ", arr[i]);
        displayarr(arr, size, (i + 1));
    }
}

/** PROBLEM FIVE **/

/** This function reverses the array that is already created. The already
created array is arr, and the one we want to put the reverse numbers in to is
arr2. They both have the same size, and i is an incrementing variable. Starting
at i for arr2, and size for arr, the function will set in values for the arr2
by going from last to first indexes in the original array. Once the size
is equivalent to 0, the function voids. **/
void reversearr(int arr[], int arr2[], int size, int i)
{
    //Base Case
    if(0 == size)
    {
        //Ends the function, since it just needs to be voided
    }
    //General Case
    else
    {
        arr2[i] = arr[size - 1];
        reversearr(arr, arr2, (size - 1), (i + 1));
    }
}

/** PRBOLEM SIX **/

/** This function checks for if an integer the user gives is in the array that
is inputed to this function. The main call sends a number the user gave, the
array created, and the size of that array. It will check each index starting
at the last index, and go to index 0. If one index in the array is equivalent
to the number the user gave, it will add 1 to retval. Once the whole array
has been checked, it will return that value. **/
int arraycheck(int num, int arr[], int size)
{
    int retval = 0;
    //Base Case
    if(-1 == size)
    {
        retval = retval;
    }
    //General Cases
    else if(num == arr[size])
    {
        retval = 1 + arraycheck(num, arr, (size - 1));
    }
    else
    {
        retval = arraycheck(num, arr, (size - 1));
    }
    return retval;
}

/** PROBLEM SEVEN **/

/** This function will allow the user to fill a character array with a string.
There is an arr, size, and incrementing variable i given for the function. It
will get char each time the function is ran, and if the user does not press
enter, it will keep running to the general case and setting retval equal to the
function call with i incremented by 1. If the user presses enter, the array at
position i will be changed to null, and the retval will be set to i to be given
back to the retval that was first called. That retval is the string length, and
will be given back. **/
int fillchararr(char arr[], int size, int i)
{
    int retval = 0;
    arr[i] = getchar();

    //Base Case
    if(arr[i] == '\n')
    {
        arr[i] = '\0';
        retval = i;
    }
    //General Case
    else
    {
        retval = fillchararr(arr, size, (i + 1));
    }
    return retval;
}

/** PROBLEM EIGHT **/

/** This function will check for any vowels in the char array that is given,
at int size, with an incrementing i variable. While i is less than size, the
function will see if at position i, if the value in the index is a vowel, lower
or upper case. If it is, it will add 1 to the retval, it if is not, it will
keep incrementing i until it is equivalent to the size. When it does, it just
returns the retval equal to retval, and hands it all the way back. Then the
function will return the retval, which is the amount of vowels in the string
inputed. **/
int vowelcheck(char arr[], int size, int i)
{
    int retval = 0;
    //Base Case
    if(i == size)
    {
        retval = retval;
    }
    //General Cases
    else if(arr[i] == 'a' || arr[i] == 'A')
    {
        retval = 1 + vowelcheck(arr, size, (i + 1));
    }
    else if(arr[i] == 'e' || arr[i] == 'E')
    {
        retval = 1 + vowelcheck(arr, size, (i + 1));
    }
    else if(arr[i] == 'i' || arr[i] == 'I')
    {
        retval = 1 + vowelcheck(arr, size, (i + 1));
    }
    else if(arr[i] == 'o' || arr[i] == 'O')
    {
        retval = 1 + vowelcheck(arr, size, (i + 1));
    }
    else if(arr[i] == 'u' || arr[i] == 'U')
    {
        retval = 1 + vowelcheck(arr, size, (i + 1));
    }
    else
    {
        retval = vowelcheck(arr, size, (i + 1));
    }
    return retval;
}

/** PROBLEM NINE **/

/** This function checks to see if a string is a palindrome. With a char array,
a size, or length, and an incrementing i variable. It checks for the last
position of the string, length, and the first, i and if the indexes at both
are equivalent to each other. If they are, it will call the function again, but
with length decremented by 1, and i incremented by 1, and it will keep doing
this. If they do not equal, it will just go straight to the last else statement
and void. If they do equal each other, eventually i will be greater than size,
or equivalent to, depending on if it is an odd or even number amount of chars,
and it will let the user know that it is a palindrome, then void. **/
void palindrome(char arr[], int length, int i)
{
    //Base Case
    if(i > length || i == length)
    {
        printf("Your string is a palindrome!\n");
    }
    //General Cases
    else if(arr[i] == arr[length])
    {
        palindrome(arr, (length - 1), (i + 1));
    }
    else
    {
        printf("Your string is NOT a palindrome!\n");
    }
}

int main()
{
    srand((unsigned)time(NULL)); //So random function will work


    /** PROBLEM TWO **/
    /** Creating two variables, base and exponent, and calling the positiveint
    function to give them values. Then creating a int powering, which is the
    result of the base to the exponent values. This is done by calling the
    function powerfunc, which needs 3 inputs of the exponent. Then, it will
    print out the base to the exponent, and what that value is. **/

    int base = 0;
    int exponent = 0;
    printf("Fast powering:\n");
    printf("Enter a base\n");
    base = positiveint(base);
    printf("Enter a exponent\n");
    exponent = positiveint(exponent);

    int powering = powerfunc(base, exponent);
    printf("%i^%i = %i\n", base, exponent, powering);


    /** PROBLEM THREE **/

    /** This function asks for an array size, which is done by calling the
    positiveint function and put into the array_size int. Then an array is
    created with the size of the array_size value. Then it calls the func
    fillarr with the input of the arr, array_size, and 0 for incrementing.
    After this it will call the displayarr, so it can be printed. **/
    printf("\nRandom array:\n");
    printf("Enter an array size\n");

    int array_size = 0;
    array_size = positiveint(array_size);

    int arr[array_size];
    fillarr(arr, array_size, 0);
    displayarr(arr, array_size, 0);

    /** PROBLEM FIVE **/

    /** This takes use of the original array in problem three, and reverses it.
    A new array is created, arr2, with the same size. Then it calls the reverse
    function, which takes both arrays, their size, and incrementing starting at
    0. Then it will show the original array, A, and the reverse array, B, by
    calling the displayarr function, which prints each index.**/
    printf("\n\nReversed random array:\n");
    int arr2[array_size];
    reversearr(arr, arr2, array_size, 0);
    printf("Array A:\n");
    displayarr(arr, array_size, 0);
    printf("\nArray B:\n");
    displayarr(arr2, array_size, 0);

    /** PROBLEM SIX **/

    /** An int numcheck is created, and is set equal to a positive number the
    user inputs from the positiveint function. Then a new int numtimes is
    created. It set to the arraycheck function, and hands in the numcheck value
    the array and the array_size. The function will return a value of how many
    times that number appears in the array. Then a printf is ran to show how
    many times the number appears. **/
    int numcheck = 0;
    printf("\n\nCounting occurrences:\n");
    printf("Select a number to search for:\n");
    numcheck = positiveint(numcheck);

    int numtimes = 0;
    numtimes = arraycheck(numcheck, arr, array_size);

    printf("%i appeared %i time(s)\n", numcheck, numtimes);

    /** PROBLEM SEVEN/EIGHT **/

    /** A new array size int is created, and given a value using positiveint.
    Then a char array is made with the size given by the user. The string
    length is then created and set equal to the fillchararr function. The
    function is ran and will return how long the function is. After that,
    a new int vowel is created. That now filled char array is given
    for the vowelcheck function. It will count how many vowels are in the
    string and return it to the int vowel. Then a printf will display how many
    vowels were in the string. **/
    int chararr_size = 0;
    int str_length = 0;
    printf("\nCounting vowels:\n");
    printf("Enter the max character length for your message:\n");
    chararr_size = positiveint(chararr_size);

    getchar(); //To get rid of any completed user inputs

    printf("Please enter a string: ");
    char chararr[chararr_size];
    int str_len = fillchararr(chararr, chararr_size, 0);

    int vowel = 0;
    vowel = vowelcheck(chararr, chararr_size, 0);
    printf("There are %i vowels in your string!\n", vowel);

    /** PROBLEM NINE **/

    /** A new char array is created, with a size of 100 indicies. An int palind
    is also created. The user enters a string, and the string length is given
    back, along with a filled char array. Then the palindrome function is
    called. It gives the char array, 1 less than the string length, and 0 for
    incrementing. **/
    printf("\nPalindrome check:\n");

    int arr_size = 100;
    char chararr2[arr_size];
    int palind = 0;

    printf("Please enter a string: ");
    str_len = fillchararr(chararr2, arr_size, 0);
    palindrome(chararr2, (str_len - 1), 0);

}
