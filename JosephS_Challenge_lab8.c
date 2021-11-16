/** Joseph Schoen and Rabia Malik **/
#include <stdio.h>

/** In this program, we are making a censor for naughty language in a phrase
the user can enter. We are asking a user to input a phrase using arrays, and
the phrase can be up to 1000 characters long. We can assume all chars are lower
case. Then the program needs to check for the curse words the user typed in the
phrase the user entered. The user could enter the word darn, or shucks. Note
that if the user enters darn, the program needs to recognize only that word.
That means cedarn, or darner, is not a curse word. If the curse word is in the
phrase, we need to blur it out with asterisks for each char we are replacing.
At the end, we tell the user if they used a bad word, or if they did not use a
bad word, and then give them their phrase back. If the phrase had a bad word,
this would display the bad word being blurred out. **/


/** This function is used to let the user first input any curse words that they
would like the system to blur out. It does this by taking an input of the array
curse, which is a 2d array of 10 by 10, and then uses getchar to get each
string in the second dimension. The user presses just enter to continue,
and the loop stops. It is a void function, because it is just replacing
values within the array. **/
void censorinput(char curseword[][10], int size)
{
    int i = 0; //Incrementer
    int j = 0; //Incrementer
    int stopper = 0; //Will stop the loop for getting curse words

    while(1 != stopper)
    {
        printf("Enter a word to censor, or enter to continue: ");
        j = 0;
        curseword[i][j] = getchar();
        while(curseword[i][j] != '\n')
        {
            j = j + 1;
            curseword[i][j] = getchar();
        }

        /** If the user presses enter at the beginning of entering the next
        curse word, this code will recognize that the user wants to be done,
        and stop the loop by setting the variable stopper to 1. **/
        if(curseword[i][0] == '\n')
        {
            stopper = 1;
        }

        curseword[i][j] = '\0';

        i = i + 1;
    }
    /** This tells the user the code is done running. **/
    printf("Your curse words have been recorded!\n\n");
}


/** This function contains 4 inputs. The first input is an array, which is a
full string phrase, and the size of that array as well. The third is an array that
contains a string that is a curse word, and then the size of that array is also
inputed.  **/
int censor(char phrase[], int psize, char curses[][10], int csize)
{
    /** Incrementing variables for loops **/
    int i = 0;
    int j = 0;
    int k = 0;
    int cinc = 0; //This one is curse word incrementer

    int match; //Used to end a loop
    int foul; //Used to return if the phrase contains any foul words

    /** This loop will go through each index in the phrase string **/
    while(phrase[i] != '\0')
    {
        /** If the first letter of the curse word matches the letter in the
        phrase at index i, this will run **/
        k = 0;


        /** This just skips checking for naughty words if there is a space in
        the phrase at index i. **/
        if(phrase[i] ==  ' ')
        {
            i = i;
        }

        /** If there is a character in the phrase at index i, this runs. **/
        else
        {
            /** Setting an incrementer and a loop stopper to their initial
            values for each time this runs. **/

            cinc = 0;
            match = 1;

            /** This first loop checks for each curse word that the user
            entered. It checks the first letter of each curse word to the index
            of the phrase, and if it does not, it goes to the next index of
            the curse word array. It will run until it it is equal to or
            greater than csize. **/
            while(cinc < csize)
            {
                /** If the first letter of the curse word equals the phrase
                letter at index i. **/
                if(phrase[i] == curses[cinc][0])
                {
                    /** If the letters equal each other at index 0, or saying i is
                    equal to 0, or the phrase at index - 1, so the index before they
                    equaled, is a space, this will run. **/
                    if(i == 0 || phrase[i - 1] == ' ')
                    {
                        j = 0; //Setting j = 0 for every time this is looped

                        /** This loop will go through the whole curse string, unless
                        the index in the phrase does not equal the index in the curse
                        string. Then it will set match equivalent to 0 and end the
                        loop. **/
                        while(curses[cinc][j] != '\0' && match == 1)
                        {
                            /** phrase index starts at i, so we just add j as we
                            increment both curses and phrase arrays. **/
                            if(curses[cinc][j] != phrase[i + j])
                            {
                                match = 0; // match is false, so we end the loop
                            }
                            j = j + 1; //Incrementing the loop by 1
                        }

                        /** If the previous loop ran, so all the letters aligned in
                        order, the last position of the curses should be at index j
                        and at null. If this is true, we run this if statement. **/
                        if(curses[cinc][j] == '\0')
                        {
                            /** If the phrase has a space after the curse word, or
                            is at the end of the phrase array with a null, this will
                            run. The reason is that we only want the word darn to be
                            blurred out. If we consider darner, the letter e comes
                            after n, so there is not a space or a null in that location
                            for the phrase string. **/
                            if(phrase[i + j] == ' ' || phrase[i + j] == '\0')
                            {
                                foul = 1; //This states that there is a foul word
                                k = 0; //Set to 0 each time this code is ran

                                /** While k is less than j, which j was left at a value
                                in the previous loop, we replace all those indices in
                                the array with * to blur them out. It will blur out
                                the whole curse word, and only if it is just the curse
                                word. **/
                                while(k < j)
                                {
                                    phrase[i + k] = '*';
                                    k = k + 1; //Incrementing
                                }
                            }

                        }
                    }
                    /** Coming from the previous if statement, we know that if i is not
                    at 0, or the starting point of the array, or it does not have a
                    space before the phrase at index i, then it is not a foul word. For
                    example, the word cedarn has a e before the d, so there is not a
                    space, but there is a letter. Since there is not a space, this
                    cannot be considered as a foul word, so foul is set to 0 and the
                    program moves on.**/
                    else if(phrase[i - 1] != ' ')
                    {
                        foul = 0;
                    }

                }
                /** This incrementers the curse word incrementer, to check if
                the next curse word entered has a first letter equal to the
                phrase at index i. **/
                cinc = cinc + 1;
            }
        }

        /** Skip to the next word **/
        i = i + 1;
    }
    /** After this has ran, we return the foul integer value, and the array
    does not need to be returned, since if we made any changes it just simply
    changed the index value at that location. **/
    return foul;
}
int main()
{
    /** This creates a character two dimensional array, a 10 by 10 array, for the user
    to enter their desires curse words they would like blurred out in the
    phrase. Then it calls the function censorinput to let the user actually
    get the characters for the curse words the user wants. **/
    int csize = 10;
    char curse[csize][csize]; // the curse word array

    censorinput(curse, csize);


    /** A phrase needs to be entered by the user. This is done by creating a
    string, with a size of 1000 indices. Once it is created, we ask the user
    to enter a phrase. **/
    int isize = 1000;
    char input[isize];
    printf("Please enter a phrase: ");

    int j = 0; //Incrementing variable

    /** A loop runs to get all the characters of the phrase. We get the first
    char, and then run a loop to get the rest. Once the user presses enter,
    the loop ends and we set that last index to null. **/
    input[j] = getchar();
    while(input[j] != '\n')
    {
        j = j + 1;
        input[j] = getchar();
    }
    input[j] = '\0';

    /** Calling the censor function to see if there are any curse words in the
    phrase that was typed by the user. The curse word is only darn. **/
    int foul = censor(input, isize, curse, csize); //Only array name

    /** When foul is returned from the function, it will either come back at 0
    or a 1. If foul is 1, that means it detected a curse word, and if it came
    back as 0, there was no curse word. There is a printf for both scenarios,
    in which either applaud or deny the user.**/
    if(1 == foul)
    {
        printf("\nThere was potty language in your phrase. It was censored. See below:\n");
    }
    else if(1 != foul)
    {
        printf("\nYour sentence was clean. Here is what you entered:\n");
    }

    /** This prints out the phrase the user entered, but it will blur out any
    curse words if the user had entered them. **/
    printf("%s\n", input);

    /** This just ends the function main. **/
    return 0;
}
