/** Joseph S and Duy Le **/
#include <stdio.h>

int main()
{
    int asz = 10; //A size for dimension 1
    int asz2 = 50; //A size for dimension 2
    char docarr[asz][asz2]; //Array for doctor names
    char specarr[asz][asz2]; //Array for specialties of doctors

    /** Asking for how many doctors you have using a scanf **/
    int doctors;
    printf("How many specialists does your hospital have? ");
    scanf(" %i", &doctors);
    getchar(); //Getting rid of anything after the enter

    int i = 0; //Incrementing variables
    int j = 0;

    /** In here we will ask for the doctors name, and the specialty the doctor
    has. The beginning of the loop asks for the doctors name, then a nested
    loop that allows you to type a string, and adds the null at the end. The
    same happens for specialty. By having another nested loop, setting j = 0
    and then getting a string for the specialty of that doctor. This will
    increment each time it is ran until we have utilized all desired doctors. **/
    while(i < doctors)
    {
        j = 0; //Always resetting j = 0 for nested loop
        printf("Please enter the name of doctor number %i:", (i + 1));
        docarr[i][j] = getchar();
        while(docarr[i][j] != '\n')
        {
            j = j + 1;
            docarr[i][j] = getchar();
        }
        docarr[i][j] = '\0';

        j = 0;
        printf("Please enter the specialty of doctor number %i:", (i + 1));
        specarr[i][j] = getchar();
        while(specarr[i][j] != '\n')
        {
            j = j + 1;
            specarr[i][j] = getchar();
        }
        specarr[i][j] = '\0';

        i = i + 1;
    }

    /** Asks for how many callers are calling in in need of a specialist,
    or multiple specialists. **/
    int callers;
    printf("\n How many people need to be linked to specialists? ");
    scanf(" %i", &callers);

    printf("\n******** LINKING WILL COMMENCE NOW ********\n");

    int specialists = i; // Making an int for the amount of specialties
    i = 0; //Resetting the increments
    j = 0;
    int specinter = 0; //Specialty interests the caller wants
    int reqarr[specialists]; //Array for requested specialists

    /** Setting 0 into all elements of requested array, based on how many
    specialists there are. **/
    while(i < specialists)
    {
        reqarr[i] = 0;
        i = i + 1;
    }

    i = 0;

    /** This loop is ran for each caller. It starts off labeling all the
    available specialists. Then the caller can input, using the number
    associated with the specialist, the specialist they want, and it will
    tell them who to go to. They can request a specialist as many times as
    they want, and once they are done they must enter -1. Once -1 is entered,
    It will reset the specialty interest variable so it can be ran for the
    next caller, and increments to the next caller using the loop. **/
    while(i < callers)
    {
        printf("\nHello caller %i!\n", (i + 1));
        printf("Our hospital has specialists in the following field:\n");

        j = 0;
        while(j < specialists)
        {
            printf("%i. %s\n", (j + 1), specarr[j]);
            j = j + 1;
        }

        while(specinter != -1)
        {
            printf("Select the specialty you are interested in contacting (Enter -1 when done): ");
            scanf(" %i", &specinter);

            if(specinter != -1)
            {
                printf("For %s, you should contact %s.\n", specarr[specinter - 1], docarr[specinter - 1]);
                /** This last line is adding 1 to the value of the request
                array in a specific element designated to each specialist. **/
                reqarr[specinter - 1] = reqarr[specinter - 1] + 1;
            }
        }
        specinter = 0;
        i = i + 1;
    }


    i = 0; //Resetting incrementers
    j = 0;
    int maxarr[specialists]; //New array for the most requested specialist
    int max = 0; //Amount of times the most requested specialist was requested

    /** This loop checks if the max value is less than the element at i in the
    request array, then it will replace the max value with that value in the
    element of the request array, since it is how many times that specialist
    has been called. If there is a max value then equal to an element later on
    in the array, it will add 1 to j, which can be randomized later to choose.
    However, if a new reqarr element is greater than those before it, it will
    reset j and replace the max value. The maxarr is just placing in the i
    value into the element, that way it will show how many specialists there
    are at that amount of requests. **/
    while(i < specialists)
    {
        if(max < reqarr[i])
        {
            j = 0;
            max = reqarr[i];
            maxarr[j] = i;
        }
        else if(max == reqarr[i])
        {
            j = j + 1;
            maxarr[j] = i;
        }
        i = i + 1;
    }
    /** If there is two or more specialists that are requested an equal amount
    of times, and that is also the max value, then it will take a random number
    and use the remainder to randomly select one of the specialists that had
    that max number of requests. Otherwise, the specialist with the most
    requests will just be displayed in the else statement. Both printf commands
    will print out the specialist and the amount of times they were requested. **/
    if(j != 0)
    {
        /** There is a (j + 1) for the fact that we are pulling from elements
        in an array and they start at 0 and not 1. **/
        int random = rand()%(j + 1);
        int k = maxarr[random];
        printf("\n%s had the most requests (%i), you should consider hiring more of them!\n", specarr[k], max);
    }
    else
    {
        printf("\n%s had the most requests (%i), you should consider hiring more of them!\n", specarr[maxarr[j]], max);
    }

}
