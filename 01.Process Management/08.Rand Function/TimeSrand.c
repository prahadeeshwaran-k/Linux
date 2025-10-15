//
// Created by prahadeeshwaran on 9/21/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*generally returns a representation of the current time,
often as a number of seconds since the Unix Epoch (like in C or PHP) or a specific time value.*/
int main() {
    srand(time(NULL));  // seed with current time

    for (int i = 0; i < 5; i++) {
        printf("%d\n", rand());
    }
    return 0;
}
