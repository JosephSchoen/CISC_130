/** Joseph Schoen and Rabia Malik **/
#include <stdio.h>

/** In this program, we are making a censor for naughty language in a phrase
the user can enter. We are asking a user to input a phrase using arrays, and
the phrase can be up to 1000 characters long. We can assume all chars are lower
case. Then the program needs to check is the curse word 'darn' is typed in the
phrase the user entered. It is important to note the only curse word is darn.
That means cedarn, or darner, is not a curse word. If the curse word is in the
phrase, we need to blur it out with asterisks for each char we are replacing.
At the end, we tell the user if they used a bad word, or if they did not use a
bad word, and then give them their phrase back. If the phrase had a bad word,
this would display the bad word being blurred out. **/


/** This function contains 4 inputs. The first input is an array, which is a
full string phrase, and the size of that array as well. The third is an array that
contains a string that is a curse word, and then the size of that array is also
inputed.  **/
int censor(char phrase[], int psize, char curses[], int csize)
{
    /** Incrementing variables for loops **/
    int i = 0;
    int j = 0;
    int k = 0;

    int match; //Used to end a loop
    int foul; //Used to return if the phrase contains any foul words

    /** This loop will go through each index in the phrase string **/
    while(phrase[i] != '\0')
    {
        /** If the first letter of the curse word matches the letter in the
        phrase at index i, this will run **/
        if(phrase[i] == curses[0])
        {
            /** If the letters equal each other at index 0, or saying i is
            equal to 0, or the phrase at index - 1, so the index before they
            equaled, is a space, this will run. **/
            if(i == 0 || phrase[i - 1] == ' ')
            {
                j = 0; //Setting j = 0 for every time this is looped
                match = 1; // matching is true

                /** This loop will go through the whole curse string, unless
                the index in the phrase does not equal the index in the curse
                string. Then it will set match equivalent to 0 and end the
                loop. **/
                while(curses[j] != '\0' && match == 1)
                {
                    /** phrase index starts at i, so we just add j as we
                    increment both curses and phrase arrays. **/
                    if(curses[j] != phrase[i + j])
                    {
                        match = 0; // match is false, so we end the loop
                    }
                    j = j + 1; //Incrementing the loop by 1
                }
                /** If the previous loop ran, so all the letters aligned in
                order, the last position of the curses should be at index j
                and at null. If this is true, we run this if statement. **/
                if(curses[j] == '\0')
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
    /** Setting a curse word that is darn. We do this by creating a size,
    and then making an array of that size. Since we are using darn, we
    just made the size 5, and then individually place in the char
    values in to each index.**/
    int csize = 5;
    char curse[csize]; // the curse word array
    curse[0] = 'd';
    curse[1] = 'a';
    curse[2] = 'r';
    curse[3] = 'n';
    curse[4] = '\0';

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
