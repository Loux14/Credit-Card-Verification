#include <stdio.h>
#include <math.h>

int main(void)
{
    // Get Card Number
    long cardnum = get_long("Card number: ");


    // Count digits
    int count;
    long carddigit = cardnum;
    for (count = 0; carddigit > 0; count++)
    {
        carddigit = carddigit / 10;
    }


    // Check length
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
    }
    else
    {
        //Prepare sums
        long cardnumber = cardnum;
        int sum1 = 0;
        int sum2 = 0;
        int dig1;
        int dig2;
        int dig2x2;
        int total;

        do
        {
            // Take out ultimate digit
            dig1 = cardnumber % 10;
            sum1 = sum1 + dig1;
            cardnumber = cardnumber / 10;


            //Take out penultimate digit
            dig2 = cardnumber % 10;
            dig2x2 = dig2 * 2;
            sum2 = sum2 + dig2x2;
            cardnumber = cardnumber / 10;
        }
        while(cardnumber >0);


        //Calculate Total
        total = sum1 + sum2;
        total = total % 10;


        //MASTERCARD, VISA, AMEX or INVALID
        if (total != 0)
        {
            printf("INVALID\n");
        }
        else
        {

            //Isolate 2 first digits
            long x = cardnum;
            do
            {
                x = x / 10;
            }
            while (x > 100);


            //Print result
            if (x / 10 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                if ((x / 10 == 5) && (0 < x % 10 || x % 10 < 6))
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    if(x == 34 || x == 37)
                    {
                        printf("AMEX\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }

            }

        }

    }

}