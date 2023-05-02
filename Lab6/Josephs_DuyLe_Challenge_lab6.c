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
    char callerreq_arr[asz][asz2]; //The caller request array
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
    available specialists. Then the caller can input, by typing in the name
    of the specialist. The program will tell the caller who to go to for
    that specialty. The caller can type in as many specialists as they want
    per request. The caller can then end the call by typing Z. Then, the next
    caller will get to do the same process.
    **/

    getchar(); //Making sure no undefined characters remain
    int k = 0; //New incrementing variable
    int loop_stopper = 0; //To stop a loop that is nested in a loop.
    int n = 0; //n is the main incrementer, since I needed more incrementers
    while(n < callers)
    {
        printf("\nHello caller %i!\n", (n + 1));
        printf("Our hospital has specialists in the following field:\n");

        j = 0;

        /** This loop displays all the specialists **/
        while(j < specialists)
        {
            printf("%i. %s\n", (j + 1), specarr[j]);
            j = j + 1;
        }

        j = 0;
        /**
        This next loop has many nested loops. It first checks if the user typed
        'Z'. If they did not the code will run. What the code is doing is asking
        for the user to type in the specialty name. Then, it will find what
        specialty they typed in was in terms of the specialty array. Once it
        finds what specialty it is, it will add 1 to the index it is in.
        **/
        while(callerreq_arr[i][j] != 'Z' && callerreq_arr[i - 1][j] != 'Z')
        {
            printf("Please type in specialty you are interested in contacting (Type 'Z' when complete): ");

            j = 0;
            //Getting the string the caller requested
            callerreq_arr[i][j] = getchar();
            while(callerreq_arr[i][j] != '\n')
            {
                j = j + 1;
                callerreq_arr[i][j] = getchar();
            }
            callerreq_arr[i][j] = '\0';

            j = 0;
            k = 0;

            /**
            If the user inputs Z, it will tell the user the call is done,
            and it will bypass the rest of this main loop and go to the
            next caller.**/
            if(callerreq_arr[i][j] == 'Z')
            {
                printf("You have requested to end the call.\n");
            }
            /**
            In here, if the user types in a specialty, this system looks for
            the specialty that the user typed based on the specarr and finding
            the first index for the specialty array. It tests each char to make
            sure both strings are equal to each other, once it finds it, it
            gives the value of j for the index of specarr that can be used
            later on. This program is ran in different ways to account for the
            checking of chars, if one does not equal another it may need to
            restart, therefore a new loop. Take note, if the user does not
            input the specialty char by char exactly, this will most definitely
            break!
            **/
            else
            {
                if(callerreq_arr[i][k] != specarr[j][k])
                {
                    while(callerreq_arr[i][k] != specarr[j][k] && loop_stopper != 1)
                    {
                        /** If the first char ends up equaling each other,
                        it will now check for the second char in each second
                        dimension array, and if they both equal each other
                        to null, it continues on.**/
                        while(callerreq_arr[i][k] == specarr[j][k] && callerreq_arr[i][k] != '\0')
                        {
                            k = k + 1;
                            if(callerreq_arr[i][j] == '\0')
                            {
                                /** If each char is equal to each other in both
                                arrays, then it will end the loop by setting
                                this variable to 1. It will only do this
                                once it knows both are equal to null. **/
                                loop_stopper = 1;
                            }
                        }
                        j = j + 1;

                    }
                }
                else if(callerreq_arr[i][k] == specarr[j][k])
                {
                    while(callerreq_arr[i][k] == specarr[j][k] && callerreq_arr[i][k] != '\0')
                    {
                        k = k + 1;
                        if(callerreq_arr[i][j] == '\0')
                        {

                            loop_stopper = 1;
                        }
                        /** This will run if it finds a character that does not
                        have the same value as the other array, and find a new
                        string that does equal it. **/
                        if(callerreq_arr[i][k] != specarr[j][k])
                            while(callerreq_arr[i][k] != specarr[j][k] && loop_stopper != 1)
                            {
                                while(callerreq_arr[i][k] == specarr[j][k] && callerreq_arr[i][k] != '\0')
                                {
                                    k = k + 1;
                                    if(callerreq_arr[i][j] == '\0')
                                    {
                                        loop_stopper = 1;
                                    }
                                }
                                j = j + 1; //For the 2nd dimension of specarr
                            }
                    }
                }

            }
            loop_stopper = 0; //This resets to 0 for the next specialty

            /** In here, if the array does not have Z as the main char, it
            will tell you what the specialty is and who to contact. At the
            end it adds a value of + 1 to the array of requests. This array
            is later used to find the most requested specialty. **/
            if(callerreq_arr[i][j] != 'Z')
            {
                printf("For %s, you should contact %s.\n", specarr[j], docarr[j]);
                /** This last line is adding 1 to the value of the request
                array in a specific element designated to each specialist. **/
                reqarr[j] = reqarr[j] + 1;
            }

            i = i + 1; //Incrementing for the requesting loop

        }
        i = i + 1; //Incrementing for the array of requests by caller

        n = n + 1; //Incrementing the caller loop
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
