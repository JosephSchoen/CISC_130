/** Joseph Schoen and Caleb Cutrer**/
#include <stdio.h>
#include <math.h>
int main ()
{
printf("PART 1\n\n");
/***SOLUTION FOR PART 1 below***/
/**Shift letters with a starting letter, and with a given number on how many positions to switch **/

char userC; //The letter the user enters in for the scan
int shiftNum; //The amount of positions the user wants to shift that letter

printf("Please enter a letter: ");
scanf(" %c", &userC);
printf("Please enter an integer: ");
scanf(" %i", &shiftNum);


if(shiftNum > 0 && userC >= 'A' && userC <= 'Z') //Testing the input values are actually alphabet characters and that the positions moved is positive
{
    int modC;
    modC = shiftNum%26; //Finding the reminder of the integer the user inputed by 26 so we can see how many spaces the character will need to move in the alphabet

    char userCOut; //The output character determined by userC with the given change in position value, and finding the remainder with the greatest value 'Z'
    userCOut = (modC + userC)%90;

    if(userCOut <= 26) //If you were to add values such as z and 2, you would wind up with a value of remainder 2, which is not be. B is 66, so we always need to add 64 to values that pass 90
    {
        char userCOut2;
        userCOut2 = userCOut + 64;

        printf("%c shifted %i positions is %c\n", userC, modC, userCOut2);
    }
    else //This will run if the modulus function does not have an input value greater than 90, so it does the circuit within the alphabet values
    {
        printf("%c shifted %i positions is %c\n", userC, modC, userCOut);
    }
}
else if(shiftNum > 0 && userC >= 'a' && userC <= 'z') //This second else if statement runs just like the first if statement, but for the lowercase letter values
{
    int modC;
    modC = shiftNum%26;

    char userCOut; //The output character determined by userC with the given characters
    userCOut = (userC + modC)%122; //We see 122 instead of 90 due to the value 'z' being 122 instead of 'Z' being 90

    if(userCOut <= 26)
    {
        char userCOut2;
        userCOut2 = userCOut + 96; //We add 96 this time since 'a' is 97, and before 'A' was 65

        printf("%c shifted %i positions is %c\n", userC, modC, userCOut2);
    }
    else
    {
        printf("%c shifted %i positions is %c\n", userC, modC, userCOut);
    }
}
else //This will run when the input was not a letter of the alphabet, or when the integer is not a positive number
{
    printf("Please write a letter character and a positive number\n");
}


printf("\n\nPART 2\n\n");
/***SOLUTION FOR PART 2 below***/
/** Take 3 integers, and then organize them in order from least to greatest **/

//Declaring 3 integer variables
int firstint;
int secondint;
int thirdint;

// Asking user to input values for each integer
printf("Please write a integer: ");
scanf(" %i", &firstint);
printf("Please write a integer: ");
scanf(" %i", &secondint);
printf("Please write a integer: ");
scanf(" %i", &thirdint);

/*Using conditional statements to identify the order of the integers
(it will be one of 6 possible sequences) and then using printf
to rearrange the integers so they are displayed in order of magnitude
(from least to greatest)*/

if(firstint > secondint && secondint > thirdint)
{
    printf("In order: %i, %i, %i\n", thirdint, secondint, firstint);
}
else if(firstint > thirdint && thirdint > secondint)
{
    printf("In order: %i, %i, %i\n", secondint, thirdint, firstint);
}
else if(secondint > firstint && firstint > thirdint)
{
    printf("In order: %i, %i, %i\n", thirdint, firstint, secondint);
}
else if(secondint > thirdint && thirdint > firstint)
{
    printf("In order: %i, %i, %i\n", firstint, thirdint, secondint);
}
else if(thirdint > firstint && firstint > secondint)
{
    printf("In order: %i, %i, %i\n", secondint, firstint, thirdint);
}
else if(thirdint > secondint && secondint > firstint)
{
    printf("In order: %i, %i, %i\n", firstint, secondint, thirdint);
}
else
{
    printf("The values you entered are not integers\n"); //This will run if the user inputs something that is not an integer
}


printf("\n\nSuper Challenge\n\n");
/***SOLUTION FOR the Super Challenge below***/
/** Create a tip calculator that asks the user for the amount they owe
on a restaurant bill and the percent tip they want to add. Display the tip
amount based on the tip percentage they specified as well as the total
amount they owe after adding the tip amount to the restaurant bill.**/

float bill; //For bill number inputed
float tipp; //For the percent inputed

//Asking the user for the bill amount and desired tip percentage
printf("Please write your check amount: ");
scanf(" %f", &bill);
printf("Please write your desired tip percentage: ");
scanf(" %f", &tipp);

/**Isolating any decimals in the bill amount that are beyond the hundredths
place value so they can be used in conditional statements to check for
correct input formatting. Variable names are just to keep the names short.
Coming from the bill, int1 would be integer 1 and f1 would be float 1 etc.**/
int billint1;
billint1 = bill; //Doing this truncates the anything beyond the decimal
float billf1;
billf1 = (bill - billint1)*100;
/*The decimal values in the bill (if any) are multiplied by 100 to convert the
decimals in the tenths and hundredths places into integers (ones and tens),
while leaving any decimal values (beyond the hundredths place) as decimals.*/
int billint2;
billint2 = billf1; //Truncate the values once again for the remaining decimals
float billf2;
billf2 = billf1 - billint2; /*Same step as the assignment in billf1. Any decimal
that is beyond the hundreths place in the original bill will now be displayed somewhere
between 0 and 1. If the bill was 16.436 this output for billf2 would be 0.6 */


// The process used for the bill is now used for the tip percentage
int tippint1;
tippint1 = tipp;
float tippf1;
tippf1 = (tipp - tippint1)*100;
int tippint2;
tippint2 = tippf1;
float tippf2;
tippf2 = tippf1 - tippint2;


if(billf2 < 0.98 && billf2 > 0.01) //This is checking if the bill inputed has a decimal in the thousanths place or farther. Also a set tolerance.
{
    printf("\nPlease enter a bill amount that has a value expressed in pennies, or to the hundreth place");
}
else if(tippf2 < 0.98 && tippf2 > 0.01) //This is checking if the tip percentage has a decimal in the thousanths place or farther. Also a set tolerance.
{
    printf("\nPlease enter a percentage that is expressed to the hundreths place");
}
else if(bill > 0 && tipp >= 0)
    /*If the bill and tip percentage do not have any numbers at the thousanths place or more, and
    the bill is a value greater than 0, and the tip is greater than or equal to zero, we can calculate
    the tip cost at that given percentage and the total bill amount with the tip*/
{
    float tipt;
    tipt = bill*(tipp/100); //Tip total. Get the percent into decimal form and multiply by bill

    /* This next section of code will round up the tip total. This is done by taking advantage
    of integers from a float number. We start by multiplying 1000 to the tip total, so we end up with
    our tip to be a number that is in the 1000s or 10000s. This allows us to see the last digit in the number
    which would be the number, if not 0, that would need to be accounted for to round up or down. This process
    is done by removing each layer of the number. For instance, the tip total is 12.045, this becomes 12,045.
    We know we want to round up since we have a 5. What the code does is remove each layer. 12,045 would be
    subtracted by 10,000, leaving 2,045. This is done until the 5 is alone, which is the variable tipt_one */

    float tiptf1; //The tip total in float form
    tiptf1 = tipt * 1000;
    int tiptint; //The integer version to rounding the bill after multiplying by 1000
    tiptint = tiptf1;
    int tipt_tenthousand;
    tipt_tenthousand = tiptint / 10000;
    int tipt_thousand; //Value after removing the the 5th digit
    tipt_thousand = tiptint - (tipt_tenthousand * 10000);
    int tipt_thousandt; //Value of tipt_thousand but just getting the value in the thousands place
    tipt_thousandt = tipt_thousand / 1000;
    int tipt_hundred;
    tipt_hundred = tipt_thousand - (tipt_thousandt * 1000);
    int tipt_hundredt;
    tipt_hundredt = tipt_hundred / 100;
    int tipt_ten;
    tipt_ten = tipt_hundred - (tipt_hundredt * 100);
    int tipt_tent;
    tipt_tent = tipt_ten / 10;
    int tipt_one;
    tipt_one = tipt_ten - (tipt_tent * 10);

    /* These next two if statements test if the value tipt_one is greater or equal to 5, or
    less than 5 to determine to round up or down */
    if(tipt_one >= 5)
    {
        /* If the tip total needs to round up, we shrink the original integer in the 10,000s place to
        the 1000s place, and add 10 to it. Then we truncate the remaining number that told us to round up.
        After all that, we put the decimal places back into place */
        int tipt_roundu;
        tipt_roundu = (tiptint + 10) * .1;
        float tipt_roundu1;
        tipt_roundu1 = tipt_roundu * .01;

        printf("The tip total will be: %.2f\n", tipt_roundu1); //Printing tip total

          float billt; //Bill total by adding the bill and the tip total
        billt = tipt_roundu1 + bill;

        /* This same rounding process for the tip total is used for the bill total in case it needs to
        be rounded from the addition of the bill and tip total */
        float billtf1;
        billtf1 = billt * 1000;
        int billtint;
        billtint = billtf1;
        int billt_tenthousand;
        billt_tenthousand = billtint / 10000;
        int billt_thousand; //Value after removing the the 5th digit
        billt_thousand = billtint - (billt_tenthousand * 10000);
        int billt_thousandt; //Value of tipt_thousand but just getting the 4th digit
        billt_thousandt = billt_thousand / 1000;
        int billt_hundred;
        billt_hundred = billt_thousand - (billt_thousandt * 1000);
        int billt_hundredt;
        billt_hundredt = billt_hundred / 100;
        int billt_ten;
        billt_ten = billt_hundred - (billt_hundredt * 100);
        int billt_tent;
        billt_tent = billt_ten / 10;
        int billt_one;
        billt_one = billt_ten - (billt_tent * 10);


        if(billt_one >= 5) //Same step for the rounding of the tip. This checks if it needs to be rounded up
        {
            int billt_roundu; //Same process for finalizing the tip total after being rounded. Truncate, and move decimals
            billt_roundu = (billtint + 10) * .1;
            float billt_roundu1;
            billt_roundu1 = billt_roundu * .01;

            printf("Your bill total will be: %.2f\n", billt_roundu1); //Printing bill total

        }
        else if(billt_one < 5) //This will run if the bill does not need to be ran. It will truncate without adding, and move decimals.
        {
            int billt_roundd;
            billt_roundd = billtint * .1;
            float billt_roundd1;
            billt_roundd1 = billt_roundd * .01;

            printf("Your bill total will be: %.2f\n", billt_roundd1); //Printing bill total
        }

    }

    else if(tipt_one < 5)
        /* This whole next section of this if conditional statement will run if the tip total needs
        to be rounded up in the hundreths place. Everything within this next branching of code is
        identical to the rounding up of the tip code. This section includes the code for rounding the
        tip total, adding the bill and tip totals, and then rounding the whole bill with tip if it
        needs to be rounded */
    {
        int tipt_roundd;
        tipt_roundd = tiptint * .1;
        float tipt_roundd1;
        tipt_roundd1 = tipt_roundd * .01;

        printf("The tip total will be: %.2f\n", tipt_roundd1); //Printing tip total

        float billt; //Bill total
        billt = tipt_roundd1 + bill;


        float billtf1;
        billtf1 = billt * 1000;
        int billtint;
        billtint = billtf1;
        int billt_tenthousand;
        billt_tenthousand = billtint / 10000;
        int billt_thousand; //Value after removing the the 5th digit
        billt_thousand = billtint - (billt_tenthousand * 10000);
        int billt_thousandt; //Value of tipt_thousand but just getting the 4th digit
        billt_thousandt = billt_thousand / 1000;
        int billt_hundred;
        billt_hundred = billt_thousand - (billt_thousandt * 1000);
        int billt_hundredt;
        billt_hundredt = billt_hundred / 100;
        int billt_ten;
        billt_ten = billt_hundred - (billt_hundredt * 100);
        int billt_tent;
        billt_tent = billt_ten / 10;
        int billt_one;
        billt_one = billt_ten - (billt_tent * 10);


         if(billt_one >= 5)
        {
            int billt_roundu; //Rounding up
            billt_roundu = (billtint + 10) * .1;
            float billt_roundu1;
            billt_roundu1 = billt_roundu * .01;

            printf("Your bill total will be: %.2f\n", billt_roundu1); //Printing bill total
        }
        else if(billt_one < 5)
        {
            int billt_roundd; //Rounding down
            billt_roundd = billtint * .1;
            float billt_roundd1;
            billt_roundd1 = billt_roundd * .01;

            printf("Your bill total will be: %.2f\n", billt_roundd1); //Printing bill total
        }
    }
    else //If it the tip does not pass to be rounded or not, this will run in case it errors out.
    {
        printf("An error has occured calculating your tip and bill, please try again");
    }
}
else if(bill < 0 || tipp < 0) //This will run if the user inputs a negative bill or tip percentage
{
    printf("\nPlease write a positive check amount and a positive percentage for your tip");
}
else //This will run if the inputs for the bill and tip percentage are not true to any prior conditional statements
{
    printf("\nPlease try again");
}

}

