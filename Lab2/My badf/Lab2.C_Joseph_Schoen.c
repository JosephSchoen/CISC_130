/* Joseph Schoen */
#include <stdio.h>

int main ()
{   /** Solution for part 1 **/
    printf("PART 1\n\n");

    int a; // Simple variables are used for lab purposes only
    a = 10;
    int b;
    b = 9;
    int c;
    c = 8;

    printf("Initially, a is %i, b is %i, and c is %i\n\n", a, b, c);

    int d;  // Assigning new values of d, e, and f to replace a, b, and c values respectively
    d = a;
    int e;
    e = b;
    int f;
    f = c;

    b = d;
    c = e;
    a = f;

    printf("First swap, a is %i, b is %i, and c is %i\n\n", a, b, c);

    a = e;
    b = f;
    c = d;

    printf("Second swap, a is %i, b is %i, and c is %i\n\n", a, b, c);




    /** Solution for part 2**/
    printf("\n\nPART 2\n\n");

    float bill_total; //Total amount the food bill was
    bill_total = 24.31; //Any bill amount can be replaced in this to calculate different totals

    printf("With a bill of %.2f, tips at 10 percent is %.2f, at 15 percent is %.2f, and at 20 percent is %.2f\n\n", bill_total, bill_total*.10, bill_total*.15, bill_total*.20);
    printf("Your totals at each tip would be %.2f for 10 percent, %.2f for 15 percent, and %.2f for 20 percent\n\n", bill_total*1.10, bill_total*1.15, bill_total*1.20);




    /** Solution for part 3 **/
    printf("\n\nPART 3\n\n");

    int integer_a; //Starting integer put together
    integer_a = 2101;

    int one; //Placing variables for each specified place in the number from the ones place to the thousands place, and assigning in powers of 10.
    one = 1;
    int ten;
    ten = 10;
    int hundred;
    hundred = 100;
    int thousand;
    thousand = 1000;

    /**
    b, c, d, e, and f are the common variables. However, div in this case stands for division, and mod in the next one stands for modulus. The process I used here
    was to take the initial integer, and divide by 1000, that way you would end up with the first number in the thousands place in a ones place. Then I used modulus
    to remove the x amount of 1000 I just stated I had, and then be left with a value in the hundreds and repeated the process. Might not be the most logical, but it
    works well!
    **/

    int integer_bdiv;
    integer_bdiv = integer_a/thousand;
    int integer_bmod;
    integer_bmod = integer_a%thousand;

    int integer_cdiv;
    integer_cdiv = integer_bmod/hundred;
    int integer_cmod;
    integer_cmod = integer_bmod%hundred;

    int integer_ddiv;
    integer_ddiv = integer_cmod/ten;
    int integer_dmod;
    integer_dmod = integer_cmod%ten;

    int integer_ediv;
    integer_ediv = integer_dmod/one;

    int integer_f;
    integer_f = integer_bdiv*1 + integer_cdiv*10 + integer_ddiv*100 + integer_ediv*1000;


    printf("Values given from %i are b: %i, c: %i, d: %i, e: %i\n\n", integer_a, integer_bdiv, integer_cdiv, integer_ddiv, integer_ediv);

    printf("Initial value: %i and rearranged value: %i\n\n", integer_a, integer_f);


}

