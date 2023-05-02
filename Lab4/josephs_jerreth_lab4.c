/*Joseph Schoen and Jarret Helmer*/
#include <stdio.h>
int main ()
{
srand((unsigned)time(NULL));

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
float randemerg_cost;

wage = 7.25;
hours = 40;
weeks = 52;
income = wage * hours * weeks;
taxes = income * .10;
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

printf("Welcome to the Game of Minimum Wage Life!\n");
printf("How many years would you like the simulation to run for? ");
scanf(" %i", &simyears);

float oldsavings;
    oldsavings = 0;

while(simcount <= simyears)
{
    printf("In Year %i:\n", simcount);
    int randhour;
    randhour = rand()%9;
    if(0 == randhour)
    {
        hours = 35;
        income = wage * hours * weeks;
        printf("Oh no, your hours decreased to 35 hours a week\n");
    }
    else
    {
        hours = 40;
        income = wage * hours * weeks;
    }

    int randemerg; //Emergency randomizer
    randemerg = rand()%2;
    if(0 == randemerg)
    {
        randemerg_cost = rand()%2899 + 100;
        printf("Oh no, you had an unforeseen cost of $%.2f\n", randemerg_cost);
    }
    else
    {
        randemerg_cost = 0;
    }

    int randrent;
    randrent = rand()%5;
    if(0 == randrent)
    {
        rent = rent * 1.10;
        printf("Oh no, your rent has increased by 10 percent!\n");
    }
    else
    {
        rent = rent;
    }
    float expenses;
    expenses = (rent + food + utilities + transportation + clothing + health + entertainment + misc) * 12 + taxes + randemerg_cost;
    float savings;
    savings = income - expenses;
    float newsavings;
    newsavings = oldsavings + savings;

    printf("Your total savings is $%.2f\n\n", newsavings);

    if(newsavings < 0)
    {
        int months;
        months = 1;

        while(months <= 12)
        {
            newsavings = (newsavings * 1.2);
            printf("Your credit card debt %.2f\n", newsavings);
            months = months + 1;
        }
    }
    else
    {
        newsavings = newsavings;
    }
    oldsavings = newsavings;
    simcount = simcount + 1;
}
}

