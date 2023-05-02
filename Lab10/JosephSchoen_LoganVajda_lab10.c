/** Joseph Schoen and Logan Vajda **/
#include <stdio.h>
#include <string.h>


/** This program is designed to find if a student has a particular genetic
maladies. It will ask for 10 students names, ask how many genetic maladies
you are interested in, what the dna code for however many maladies, and
then it will ask for the names of them. Then it will show a list of all the
students and display if any students have certain maladies, or if they have
none. **/



/** PROBLEM ONE **/

/** This function takes a character array and a size, and it will call for a
character, so the user can enter a name, then press enter and it moves on to
the next index in the first dimension of the array for all student names.**/
void namearray(char arr[][20], int size)
{
    int i = 0;
    int j = 0;
    while(i < size)
    {
        printf("Please enter the name of person %i: ", (i + 1));

        j = 0;
        arr[i][j] = getchar();
        while(arr[i][j] != '\n')
        {
            j = j + 1;
            arr[i][j] = getchar();
        }
        arr[i][j] = '\0';
        i = i + 1;
    }
}

/** PROBLEM TWO **/

/** This reads the dna file and makes it into an array of 10 different
combinations of dna code. **/
void read_dna(char dna[10][1000])
{
    FILE* fp = fopen("dna.txt", "r"); // Open the dna file
    int dna_length = 1000;

    // This loop reads in the dna file
    int i = 0;
    while(fgets(dna[i], dna_length, fp) != NULL)
    {
        i = i + 1;
    }
    fclose(fp);
}

/** PROBLEM FOUR **/

/** This function checks to make sure the sequence for the dna entered is a
 valid sequence, using only A, C, G, and T in the sequence. If it does not,
the retval will equal 1 and be sent back, otherwise it will be 0. **/
int genetic_error(char arr[][20], int size, int i, int j)
{
    int retval = 0;

    if(arr[i][j] == '\0')
    {
        retval = 0;
    }
    else if(arr[i][j] == 'A')
    {
        retval = genetic_error(arr, size, i, (j + 1));
    }
    else if(arr[i][j] == 'C')
    {
        retval = genetic_error(arr, size, i, (j + 1));
    }
    else if(arr[i][j] == 'G')
    {
        retval = genetic_error(arr, size, i, (j + 1));
    }
    else if(arr[i][j] == 'T')
    {
        retval = genetic_error(arr, size, i, (j + 1));
    }
    else
    {
        retval = 1;
    }
    return retval;
}

/** This function will be given a character array and a size. This function
will let the user enter any sequence for the dna, by getting characters. Once
the user has typed their sequence and pressed enter, the function will call
another function to check if the sequence is valid, and the function call will
return a value in error, and if there is an error, which is == 1, then it let
the user know a valid sequence and rerun that same sequence location. **/
void genetic_array(char arr[][20], int size)
{
    int i = 0;
    int j = 0;
    int error = 0;
    while(i < size)
    {
        printf("Please enter the DNA sequence of interest %i: ", (i + 1));
        j = 0;
        arr[i][j] = getchar();
        while(arr[i][j] != '\n')
        {
            j = j + 1;
            arr[i][j] = getchar();
        }
        arr[i][j] = '\0';

        error = genetic_error(arr, j, i, 0);

        if(error == 1)
        {
            i = i;
            printf("Please re-enter the sequence using only characters 'A' 'C' 'T' and 'G'\n");
        }
        else if(0 == error)
        {
            i = i + 1;
        }
        error = 0;
    }
}

/** PROBLEM FIVE **/

/** This function asks for the names to the specific sequences that were
previously entered. Then allows the user to enter a name by getting the
characters and then moving to the next sequence. **/
void trait_array(char arr[][100], int size)
{
    int i = 0;
    int j = 0;
    while(i < size)
    {
        printf("What is the behavioral trait associated with genetic sequence %i: ", (i + 1));

        j = 0;
        arr[i][j] = getchar();
        while(arr[i][j] != '\n')
        {
            j = j + 1;
            arr[i][j] = getchar();
        }
        arr[i][j] = '\0';
        i = i + 1;
    }
}

/** PROBLEM SIX **/

/** This is the inside check for the sequence. If the first letter of the
sequence is equal to a char in the dna for that person, it will call this
function. This will test to see if the next index in both arrays are equal.
If they do not equal, it will end the loop and return a 0. If they are equal
up to the null terminator in the sequence given, then the student does have
that dna sequence in them so it will return a 1 instead. **/
int insideseq_match(char seq[][20], char dna[][1000], int inc, int i, int k, int j)
{
    int retval = 0;
    while(seq[inc][k] == dna[i][j])
    {
        if(seq[inc][k + 1] == '\0')
        {
            retval = 1;
        }
        j = j + 1;
        k = k + 1;
    }
    return retval;
}

/** This function takes in the sequences the user is looking for, and the dna
sequence for each person. It will check one dna strand with one sequence. It
will increment the dna until the first char in the sequence is equivalent to
the dna sequence at a certain index, and then it will call the function
insideseq_match to check if the whole sequence is true there. If the function
call results in a 1, being placed into check, it will set this functions retval
to 1 as well, and end the loop by setting j to 1000. If check does not equal 1,
it will reset k so it looks for the first char in the sequence, and continues
looking through the dna array. **/
int subseq_match(char seq[][20], char dna[][1000], int inc, int i)
{
    int retval = 0;
    int j = 0;
    int k = 0;
    int check;

    while(j < 1000)
    {
        if(seq[inc][k] == dna[i][j])
        {
            check = insideseq_match(seq, dna, inc, i, k, j);
            if(1 == check)
            {
                retval = 1;
                j = 1000;
            }
        }
        else
        {
            k = 0;
        }

        j = j + 1;
    }
    return retval;
}

/** This function fills the result array with either 1s or 0s. For each person,
it will read their dna and check each sequence given by how many genetic
sequences were given by the user. If a sequence is found in that persons dna,
it will fill the array in the second dimension for that sequence as a 1. After
all genetic sequences are tested, it will continue on to the next person, and
fill the array at the indexes of each sequence, until all dna sequences have
been tested. There is no return value since it is filling out an array. **/
void testing_maladies(int genetic_size, int result[][genetic_size], char dna[][1000], char seq[][20])
{
    int i = 0;
    int j = 0;
    while(i < 10)
    {
        j = 0;
        while(j < genetic_size)
        {
            result[i][j] = subseq_match(seq, dna, j, i);
            j = j + 1;
        }
        i = i + 1;
    }
}

/** This function displays all the contents that this program has been
diagnosing. For each person, it will see if the result array at each
sequence the user typed in has a value of 1, which means it is in the dna of
that person, and it will display the string for that specific sequence that
was named in the trait array. It will also set none equal to 1. If there is
no matches for that person, it will print out nothing since the value of none
did not change. Then it moves on to the next person and resets the nested loops
and reprints the whole process until all 10 people have been evaluated.**/
void display_maladies(char name_array[][20], int genetic_size, int result[][genetic_size], char trait[][100])
{
    int i = 0;
    int j = 0;
    int none = 0;
    while(i < 10)
    {
        none = 0;
        j = 0;

        printf("\n%s is predisposed to:\n", name_array[i]);

        while(j < genetic_size)
        {
            if(result[i][j] == 1)
            {
                printf("                %s \n", trait[j]);

                none = 1;
            }
            j = j + 1;
        }
        if(none == 0)
        {
            printf("                Nothing\n");
        }
        i = i + 1;
    }
}






int main()
{
    /** PROBLEM ONE **/
    /** A char array, that holds 10 names and each name is up to 20 characters
    in length is created. Then calls a function that allows the user to enter
    the desired names for each first dimension index. **/
    int narray_size = 10;
    int narray_size2 = 20;
    char name_array[narray_size][narray_size2];

    namearray(name_array, narray_size);

    /** PROBLEM TWO **/
    /** A char array is created for 10 different DNA sequences up to 1000
    characters long. Then the function read_dna is called to fill in the
    array. **/
    int num_people = 10;   // Max people
    int dna_length = 1000; // Max dna length
    char dna[num_people][dna_length];  // 2D array for storing dna samples for each person

    read_dna(dna);

    /** PROBLEM THREE **/

    /** This creates a size for how many sequences of dna the user wants,
    by asking for a scanf. Then removes the enter with getchar. **/
    int genetic_size = 0;
    printf("How many genetic sequences are you interested in? ");
    scanf(" %i", &genetic_size);
    getchar();

    /** PROBLEM FOUR **/

    /** This creates an char array of the generic size previously inputed, and
    the second dimension is the size of 20. It allows the user to type in the
    sequences of the dna by calling the function genetic_array. **/
    char genetic_seq[genetic_size][narray_size2]; //Using variable with the value of 20
    genetic_array(genetic_seq, genetic_size);

    /** PROBLEM FIVE **/

    /** This creates a char array of the generic size and the trait_size. Then
    it calls the trait_array. **/
    int trait_size = 100;
    char genetic_trait[genetic_size][trait_size];

    trait_array(genetic_trait, genetic_size);

    /** PROBLEM SIX **/

    /** A dna_result array is created that is for all 10 people, and allows for
    a check of each genetic maladies, for however many the user previously
    inputted. The function call testing_maladies is called and passes in
    arrays and integers, and then the display_maladies is called and sends
    arrays and integers as well. **/
    int dna_result[narray_size][genetic_size];

    testing_maladies(genetic_size, dna_result, dna, genetic_seq);

    display_maladies(name_array, genetic_size, dna_result, genetic_trait);








}
