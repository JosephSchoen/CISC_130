/*Joseph Schoen and Jarret Helmer*/
#include <stdio.h>
int main ()
{
    srand((unsigned)time(NULL));

    /** The task for this lab is to create a simulation of making minimum wage
    and living on it. We need to create a program that takes all the monthly
    input variables given on the pdf, and calculate each years savings account
    total, assuming the user starts with 0 dollars in their account. There are
    also extra calculations such as less work hours, higher rent, and unforeseen
    costs that come up in yearly life. Any dollar values are in floats, and
    units of time are in integers. **/

    /** The following are the variables we are given for the users expenses
    and work load. They are named based on their subject. **/
    float wage;
    int hours;
    int weeks;
    float taxes;
    float rent;
    float food;
    float utilities;
    float transportation;
    float clothing;
    float health;
    float entertainment;
    float misc;
    float income;
    int simyears;
    int simcount;
    float randemerg_cost; /**This is for the calculation of the random emergency
    cost, in which is implemented in a conditional statement later on. **/

    /** Assigning values to all the variables above that are given in the pdf,
    except taxes and simyears since simyears will be a variable inputed by the
    user, and taxes need to be calculated on total income. **/
    wage = 7.25;
    hours = 40;
    weeks = 52;
    income = wage * hours * weeks;
    rent = 400;
    food = 125;
    utilities = 75;
    transportation = 100;
    clothing = 30;
    health = 125;
    entertainment = 50;
    misc = 100;
    simcount = 1;
    randemerg_cost = 0;

    /** Printing the beginning code, and then asking for how many years you
    want to run and see what your savings account would look like, given
    scenarios and circumstances that might come up while living during that
    period inputed for simyears. **/
    printf("Welcome to the Game of Minimum Wage Life!\n");
    printf("How many years would you like the simulation to run for? ");
    scanf(" %i", &simyears);

    /** Just like the fibonacci sequence, we need to have two original starting
    values, which we are calling old savings, and savings, and then a new
    savings account called newsavings. This is the first account because it
    needs to start at 0. **/
    float oldsavings;
    oldsavings = 0;

    /** For all the calculations in this game, we run it in a while loop, since
    we need to calculate each years income and expenses. The simcount will
    start at 1, and get larger by 1 each time the loop is ran until it is
    equivalent to the simyears entered by the user for the input years. **/
    while(simcount <= simyears)
    {
        printf("\nIn Year %i:\n", simcount); /* Prints the year # for the game */

        /** Random generation for if the hours will be 40 hours a week or 35
        hours a week. We do this with a modulus and a random number between
        0 and multiple billion. If we divide by 9, the remainder would be 0
        10 percent of the time. So we take the mod 9 of the random number.
        If the number that is randomized is equivalent to zero, it will change
        the hours per week to 35 hours, and recalculate the income, and then
        print that your hours have decreased for labor. **/
        int randhour;
        randhour = rand()%9;
        if(0 == randhour)
        {
            hours = 35;
            income = wage * hours * weeks;
            printf("Oh no, your hours decreased to 35 hours a week\n");
            taxes = income * .10; //Taxes are 10 percent of yearly income
        }
        /** However, if the modulus has a value that is not divisible by 9,
        it will have a remainder and therefore not equal to zero, which will
        happen approximately 90 percent of the time. Then it will leave the
        income like it normally was. This needs to be ran in each loop, since
        one year you may work 40 hours, and then the next could be 35 hours.**/
        else
        {
            hours = 40;
            income = wage * hours * weeks;
            taxes = income * .10;
        }

        /** The concept with the first randomizer is done here as well, except
        this one is for emergency costs. We created an integer and made a
        modulus for a randomizer. The mod we took was 2, since we want a 50
        percent change of a random cost happening. If the mod has a remainder
        of 0, it will output a random emergency cost. Within the first if
        statement, if the remainder is 0, a new modulus will run setting it
        equal to the variable randemerg_cost that was made in line 51. The mod
        ran will give a remainder between 100 and 3000, which is what was asked
        for in the prompt. Then it will print that you had an emergency cost
        and tell you how much the cost was. **/
        int randemerg;
        randemerg = rand()%2;
        if(0 == randemerg)
        {
            randemerg_cost = rand()%2900 + 100;
            printf("Oh no, you had an unforeseen cost of $%.2f\n", randemerg_cost);
        }
        /** If the modulus has a remainder of 1, it will remain the
        emergency cost at 0 and have no money spent on it. **/
        else
        {
            randemerg_cost = 0;
        }

        /** For this next randomizer, we want the rent to increase by 10
        percent, 20 percent of the time. The catch with this randomizer is
        that the rent will remain at the new raised price. So if in year 3
        we raise the rent by 10 percent, all remaining years would remain
        raised by 10 percent. To do this we make a new random variable
        for rent, and then have the random modulus be divided by 5
        for the remainder to be 0, 20 percent of the time. It would
        make the rent value increase by 10 percent if the mod is equal to 0,
        and then print that your rent has increased by 10 percent.**/
        int randrent;
        randrent = rand()%5;
        if(0 == randrent)
        {
            rent = rent * 1.10;
            printf("Oh no, your rent has increased by 10 percent!\n");
        }

        /** If the randomizer for rent has a remainder, the rent will not
        change values from the previous rent cost the year before. **/
        else
        {
            rent = rent;
        }

        /** These next three floats calculate the expenses and savings. We
        have income already calculated from above. We add up all our monthly
        expenses, and multiply by 12. Then add the taxes calculated about and
        the emergency cost, whether is it 0 or a random number. Then we
        calculate the savings by taking income and subtracting the expenses.
        We make a newsavings value by taking the last years saving value, and
        adding the current savings from this years total savings.  **/
        float expenses;
        expenses = (rent + food + utilities + transportation + clothing + health + entertainment + misc) * 12 + taxes + randemerg_cost;
        float savings;
        savings = income - expenses;
        float newsavings;
        newsavings = oldsavings + savings;

        /** The savings account value for the term year ran in the loop is
        printed out. **/
        printf("Your total savings is $%.2f\n", newsavings);

        /** For the challenge, we were to make a credit card balance if the
        users account went negative due to expenses outweighing their income.
        To do this, we made a conditional statement. If the saving account goes
        to below zero, the credit card balance will have interest and grow at
        20 percent a month. The credit debt will go away once paid off. We made
        an integer of 1 that is made for 12 months a year. The loop adds 20
        percent interest to the savings account for all 12 months, and then
        prints the users amount of debt after the year from the interest.**/
        if(newsavings < 0)
        {
            int months;
            months = 1;

            while(months <= 12)
            {
                newsavings = (newsavings * 1.2);
                months = months + 1;
            }
            printf("Your credit card debt $%.2f\n", newsavings);
        }

        /** If the users savings account is still 0 or greater,
        the savings account will not change. **/
        else
        {
            newsavings = newsavings;
        }

        /** At the end of the loop, the old savings is reassigned with the
        current savings value in the account. The simcount that starts at 1
        will also increase by 1 each time until it equals the amount of years
        the user inputed in the beginning of the program. **/
        oldsavings = newsavings;
        simcount = simcount + 1;
    }
}

