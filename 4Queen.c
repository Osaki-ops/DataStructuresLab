#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include "Stack_adt.h" // Assuming the header file is named "stack.h"

// Function to solve the 4 Queens problem
void solveFourQueens()
{
    
    struct stack* queenStack;
    queenStack = create_stack();
    int solutions = 0;

    int queenPositions[4]; // Array to store queen positions in each column

    int col = 0;
    queenPositions[col] = 0;

    while (col >= 0)
    {
        if (col >= 4)
        {
            // Found a solution
            printf("Solution %d: ", solutions + 1);
            for (int i = 0; i < 4; i++)
            {
                printf("(%d,%d) ", i, queenPositions[i]);
            }
            printf("\n");
            solutions++;

            col--;
            popStack(queenStack); // Remove the last queen position
            queenPositions[col]++;
        }

        if (queenPositions[col] >= 4)
        {
            col--;
            popStack(queenStack); // Remove the last queen position
            queenPositions[col]++;
        }
        else
        {
            bool hit = false;
            for (int i = 0; i < col; i++)
            {
                if (queenPositions[col] == queenPositions[i] || abs(col - i) == abs(queenPositions[col] - queenPositions[i]))
                {
                    hit = true;
                    break;
                }
            }

            if (!hit)
            {
                pushStack(queenStack, (void*)&queenPositions[col]);

                col++;
                if (col < 4)
                {
                    queenPositions[col] = 0;
                }
            }
            else
            {
                queenPositions[col]++;
            }
        }
    }

    printf("Total solutions: %d\n", solutions);

    
}

int main()
{
    solveFourQueens();

    return 0;
}
