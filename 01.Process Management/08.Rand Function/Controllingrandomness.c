//
// Created by prahadeeshwaran on 9/21/25.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    srand(100);  // fixed seed

    for (int i = 0; i < 5; i++) {
        printf("%d\n", rand());
    }
    return 0;
}

/* same sequency
677741240
611911301
516687479
1039653884
807009856
*/