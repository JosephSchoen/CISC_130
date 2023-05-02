#include <stdio.h>

int main ()

{
    /** Creating a string that contains up to 1000 characters**/
    int num; //Num is a random variable name to put in array
    num = 1000;
    char str[num];

    /** Prompting the user **/
    printf("Please enter your message: ");

    /** Creating i for the changing variable to create array, and then
    starting with position 0 of array and getting the character for it **/
    int i; //Standard i
    i = 0;

    str[i] = getchar();

    /** To get any character after the first, a loop is ran. It will use each
    position of the array to fill in the character typed by the user, and the
    loop will end once the user hits enter, which is '\n' **/
    while(str[i] != '\n')
    {
        i = i + 1;
        str[i] = getchar();
    }

    /** After the user clicks enter, the full message is typed, and we are in
    the next array slot, which we need to end the array. We do this by setting
    the array slot to be null or '\0' **/
    str[i] = '\0';

    /** Asking the user to either encrypt or decrypt the message **/
    int cryptin;
    printf("Would you like to (1) encrypt this message or (2) decrypt it: ");
    scanf(" %i", &cryptin);

    /** Resetting i to 0 to run the same loop as above **/
    int j;
    j = 0;
    char k; //Will be used for swapping characters for MESSS
    int strleng; //String length
    strleng = i - 1; //The last i is just null, we just need the char length
    i = 0; //Can reset i to 0 for using loops in the conditional statements
    /** If they want to encrypt by typing 1, the first if runs**/
    if(cryptin == 1)
    {
        /** First, we need to swap all the characters so the message is
        reversed. I did this by introducing k, setting the first element on the
        str of the loop to k, setting that element of that value to the last
        value, then setting the last term to k, which is the first element
        value. I have it set to run until j is half the value of the str length
        because we are swapping and two characters are swapped for one loop.  **/
        while(j < ((strleng / 2)))
        {
            k = str[j];
            str[j] = str[strleng - j];
            str[strleng - j] = k;
            j = j + 1;
        }

        /** This loop runs for all array values of i starting at 0, and when
        the array gets to its position where null is, the prompt will continue
        on to the next part.**/
        while(str[i] != '\0')
        {
            /** If the character in the position of str[i] is a letter, it
            will calculate the next letter for both lower case and upper case
            depending on the character value and the position the character
            is in for the array. **/

            if(str[i] >= 'a' && str[i] <= 'z')
            {
                /** If the string at position i is a lower case char, it will
                take the value of the char, add the value of i mod 26, or the
                position of the char within the alphabet, and add 1 to move
                the value. If the value is greater than z + 1, it will fit into
                the modulus and loop back to the beginning by adding the
                remainder to a with the conditional statements. I have the
                statements separate for my interpreting. Then the code runs
                after the conditional statements**/
                str[i] = (str[i] + (i % 26) + 1) % ('z' + 1);
                if(str[i] > 0 && str[i] < 27)
                {
                    str[i] = str[i] + 'a';
                }
                else if(0 == str[i])
                {
                    str[i] = str[i] + 'a';
                }
            }
            /** If the character at string position i is an upper case char
            it will run this set of code. The only difference between this
            and the lower case code, is the values are based on the upper case
            letter values. **/
            else if(str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = (str[i] + (i % 26) + 1) % ('Z' + 1);
                if(str[i] > 0 && str[i] < 27)
                {
                    str[i] = str[i] + 'A';
                }
                else if(0 == str[i])
                {
                    str[i] = str[i] + 'A';
                }
            }
            /** Once the code has either ran either conditional statements,
            or passed all of it, it will add 1 to i and check if the loop
            condition is true. Take note that all chars that are not letters
            will not run in the conditional statements and add 1 to i and run
            again in the while loop. **/
            i = i + 1;
        }
        /** Once the loop has ran for encrypting, it will display the encrypted
        string that has been moved accordingly by its element position. **/
        printf("Your decrypted message is:\n%s", str);
    }
    /** If the user wants to decrypt, the enter a 2 in for the variable
    cryptin. Then this code will run since the conditional statement
    is true. **/
    else if(cryptin == 2)
    {
        /** Loop will run if there is a char value in the element until it hits
        the null in the array. **/
        while(str[i] != '\0')
        {
            /** Instead of moving the char forward based on its position in the
            message, we now need to move it backwards based on its position. I
            started out with the same conditional statement searching for lower
            or upper case. I took the string value and subtracted by the value
            i mod 26 for the amount of characters within the alphabet it could
            rotate. Then I subtracted 1 from that value to move it one more
            place. If the string was less 'a' or 97, then it would not be
            within the range of the alphabet of lower case letters. I would
            then add 26 to the value to make it do one full cycle around
            the alphabet. **/
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = (str[i] - (i % 26) - 1);
                if(str[i] < 97)
                {
                    str[i] = str[i] + 26;
                }
            }
            /** This is the same as previously written, however it is for
            uppercase letters. Instead of 97 for 'a' it is 65 for 'A' and will
            do the same looping process if that is needed since it went below
            the value of 'A'.**/
            else if(str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = (str[i] - (i % 26) -1);
                if(str[i] < 65)
                {
                    str[i] = str[i] + 26;
                }
            }
            /** Once the code has either ran either conditional statements,
            or passed all of it, it will add 1 to i and check if the loop
            condition is true. Take note that all chars that are not letters
            will not run in the conditional statements and add 1 to i and run
            again in the while loop. **/
            i = i + 1;
        }

        j = 0; //Resetting j to 0 for loop

        /** Identical process as before for MESSS, reversing all the characters
        back after the whole thing has been decrypted, so it will output the
        original message. **/
        while(j < (strleng / 2))
        {
            k = str[j];
            str[j] = str[strleng - j];
            str[strleng - j] = k;
            j = j + 1;
        }

        /** Once the loop has ran for decrypting, it will display the decrypted
        string that has been moved accordingly by its element position. **/
        printf("Your decrypted message is:\n%s", str);
    }
    /** If the user enters a number in variable cryptin that is not 1 or 2, it
    will run here and ask them to re-enter a number that is 1 or 2. **/
    else
    {
        printf("Please enter only a 1 or a 2 for the encrypting or decrypting function");
    }
}
