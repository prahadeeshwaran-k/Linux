#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int p1[2]; // Pipe 1: Parent writes, Child reads
    int p2[2]; // Pipe 2: Child writes, Parent reads

    pipe(p1);
    pipe(p2);

    if (fork() == 0)
    {
        // -------- CHILD PROCESS --------
        close(p1[1]); // close write end of p1
        close(p2[0]); // close read end of p2

        char from_parent[20], to_parent[20];

        while (1)
        {
            read(p1[0], from_parent, sizeof(from_parent));
            printf("Child received: %s\n", from_parent);

            printf("Child: ");
            scanf("%s", to_parent);

            write(p2[1], to_parent, strlen(to_parent) + 1);
        }
    }
    else
    {
        // -------- PARENT PROCESS --------
        close(p1[0]); // close read end of p1
        close(p2[1]); // close write end of p2

        char to_child[20], from_child[20];

        while (1)
        {
            printf("Parent: ");
            scanf("%s", to_child);

            write(p1[1], to_child, strlen(to_child) + 1);

            read(p2[0], from_child, sizeof(from_child));
            printf("Parent received: %s\n", from_child);
        }
    }

    return 0;
}
