/*
    Shipping Calculator Assignment - Zachary Krantz

    Calculates the shipping charges for packages
     - Packages weighing over 50 pounds will not be shipped.
     - Less than or equal to 10 pounds is $3.00 per 500 miles
     - Greater than 10 pounds is $5.00 per 500 miles
     - If shipping further than 1,000 miles there is an additional charge of $10 per package.

    200
    1.5
*/

#include <stdio.h>

int main(void) {
    //Initialize shippingCost, weight, and distance variables
    int shippingCost = 0;
    double weight;
    int distance;

    //Clear other input prior in my terminal
    printf("\n\n\n\nShipping Cost Calculator:\n");

    //Get weight from user input
    printf("Enter the weight of your package (pounds): ");
    scanf("%lf", &weight);
    //If weight is greater than 50, give warning and return 1 from main()
    if(weight > 50) {
        printf("Sorry, we cannot ship packages heavier than 50 pounds!\n");
        return 1;
    }

    //Get distance from user input
    printf("Enter the distance for shipping (miles): ");
    scanf("%d", &distance);
    //If distance is greater than 1000 give user alert that there will be an upcharge, add upcharge to shippingCost
    if(distance > 1000) {
        printf("Due to the distance being further than 1,000 miles you will receive a $10.00 upcharge.\n");
        shippingCost += 10;
    }

    //If the distance divides evenly from 500 then use distance/500
    //Else add 1 to distance/500
    int numberOfSegments;
    if(distance % 500 == 0) {
        numberOfSegments = distance/500;
    } else {
        numberOfSegments = 1 + (distance / 500);
    }

    //From 0 to numberOfSegments 
    //If weight is less than or equal to 10 add 3 to shippingCost
    //Else add 5 to shippingCost
    for(int i = 0; i < numberOfSegments; i++) {
        if(weight <= 10) {
            shippingCost += 3;
        } else {
            shippingCost += 5;
        }
    }

    //Display shipping cost
    printf("Your shipping cost is %i.00.\n",shippingCost);

    //Return 0 to signify everything worked
    return 0;
}