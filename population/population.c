#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int n = 0;
    int s, e;

    // prompt user for starting population
    do
    {
        s = get_int("start population : ");
    }
    while (s < 9);

    // prompt user for end population
    do
    {
        e = get_int("end population : ");
    }
    while (e < s);

    // calculate number of years
    while (s < e)
    {
        s = s + (s / 3) - (s / 4);
        n++;
    }

    // print number of years
    printf("Years: %i\n", n);

}
