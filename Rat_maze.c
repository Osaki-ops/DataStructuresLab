#include <stdio.h>
#include <stdbool.h>
#include "Stack_adt.h"


int maze[7][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 1, 1, 1},
    {1, 1, 0, 1, 1, 1, 0, 0, 0, 1},
    {1, 1, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
};

struct Spot
{
    int row;
    int col;
};

bool isValidSpot(int row, int col, struct stack* visitedStack);

bool isSpotVisited(int row, int col, struct stack* visitedStack)
{
    struct node* current = visitedStack->top;

    while (current != NULL)
    {
        struct Spot* spot = (struct Spot*)(current->data);
        if (spot->row == row && spot->col == col)
            return true;

        current = current->link;
    }

    return false;
}

void printPath(struct stack* visitedStack)
{
    struct node* current = visitedStack->top;

    while (current != NULL)
    {
        struct Spot* spot = (struct Spot*)(current->data);
        printf("(%d, %d) ", spot->row, spot->col);
        current = current->link;
    }

    printf("\n");
}

bool ratInMaze(int row, int col, struct stack* visitedStack)
{
    if (!isValidSpot(row, col, visitedStack))
        return false;

    struct Spot* currentSpot = (struct Spot*)malloc(sizeof(struct Spot));
    currentSpot->row = row;
    currentSpot->col = col;

    pushStack(visitedStack, currentSpot);

    if (row == 6 && col == 6)
    {
        printf("Path found: ");
        printPath(visitedStack);
        return true;
    }

    bool pathFound = false;

    // Move right
    if (ratInMaze(row, col + 1, visitedStack))
        pathFound = true;

    // Move down
    if (!pathFound && ratInMaze(row + 1, col, visitedStack))
        pathFound = true;

    // Move left
    if (!pathFound && ratInMaze(row, col - 1, visitedStack))
        pathFound = true;

    // Move up
    if (!pathFound && ratInMaze(row - 1, col, visitedStack))
        pathFound = true;

    if (!pathFound)
        popStack(visitedStack);

    return pathFound;
}

bool isValidSpot(int row, int col, struct stack* visitedStack)
{
    return (row >= 0 && row < 7 && col >= 0 && col < 10 && maze[row][col] == 0 && !isSpotVisited(row, col, visitedStack));
}

int main()
{
    struct stack* visitedStack = create_stack();

    int startRow, startCol;

    printf("Enter the starting position (row and column): ");
    scanf("%d%d", &startRow, &startCol);

    if (!isValidSpot(startRow, startCol, visitedStack))
    {
        printf("Invalid starting position.\n");
        return 0;
    }

    if (!ratInMaze(startRow, startCol, visitedStack))
        printf("No path found.\n");

    return 0;
}
