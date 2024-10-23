#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int reset(char top[], char middle[], char bottom[], char grid[], int whosTurn)
{
    system("clear");
    if (whosTurn == 0)
        printf("It is x's turn\n\n");
    else
        printf("It is o's turn\n\n");

    printf("%s", top);
    printf("%s", grid);
    printf("%s", middle);
    printf("%s", grid);
    printf("%s\n", bottom);

    return 0;
}

int winCheck(char xORo, char top[], char middle[], char bottom[], int* gameOver)
{
    if ((xORo == top[1] && xORo == top[5] && xORo == top[9])||(xORo == middle[1] && xORo == middle[5] && xORo == middle[9])||(xORo == bottom[1] && xORo == bottom[5] && xORo == bottom[9]))
    {
        printf("Game over!\n%c is the winner!\n", xORo);
        *gameOver = 1;
    }
    else if ((xORo == top[1] && xORo == middle[1] && xORo == bottom[1])||(xORo == top[5] && xORo == middle[5] && xORo == bottom[5])||(xORo == top[9] && xORo == middle[9] && xORo == bottom[9]))
    {
        printf("Game over!\n%c is the winner!\n", xORo);
        *gameOver = 1;
    }
    else if ((xORo == top[1] && xORo == middle[5] && xORo == bottom[9])||(xORo == top[9] && xORo == middle[5] && xORo == bottom[1]))
    {
        printf("Game over!\n%c is the winner!\n", xORo);
        *gameOver = 1;
    }
    else if (top[1] != ' ' && top[5] != ' ' && top[9] != ' ' && middle[1] != ' ' && middle[5] != ' ' && middle[9] != ' ' && bottom[1] != ' ' && bottom[5] != ' ' && bottom[9] != ' ')
    {
        printf("Game over!\nIt is a tie...\n");
        *gameOver = 1;
    }
    return 0;
}

int main()
{

    srand(time(0));                         // Uses the current time to get a seed for the next line
    int whosTurn = rand() % 2;             // Randomly generates 0 or 1

    char goNext;
    printf("The grid positions are as follows:\n\n");
    printf(" T1 | T2 | T3\n");
    printf("----|----|----\n");
    printf(" M1 | M2 | M3\n");
    printf("----|----|----\n");
    printf(" B1 | B2 | B3\n\n");
    printf("Are you ready to begin? (Y / N)\n");

    int noLoop = 0;

    while (noLoop == 0)
    {
        scanf("%c", &goNext);
        if (goNext == 'y' || goNext == 'Y')
        {
            system("clear");
            noLoop = 1;

            if (whosTurn == 0)
                printf("It is x's turn\n\n");
            else
                printf("It is o's turn\n\n");
        }
        else if (goNext == 'n' || goNext == 'N')
        {
            printf("Why not?\n");
            printf("Are you ready to begin? (Y / N)\n");
            scanf("%c", &goNext);
        }
        else
        {   
            printf("Unknown input...\n");
            printf("Are you ready to begin? (Y / N)\n");
            scanf("%c", &goNext);
        }
    }
    
    char top[] = {"   |   |  \n"};              // 1, 5, and 9 are the spots in the array for the grid locations
    char middle[] = {"   |   |  \n"};          // ex. t1 = top[1], t2 = top[5], and t3 = top[9]
    char bottom[] = {"   |   |  \n"};
    char grid[] = {"---|---|---\n"};  

    printf("%s", top);
    printf("%s", grid);
    printf("%s", middle);
    printf("%s", grid);
    printf("%s\n", bottom);

    char move[2];
    int gameOver = 0;
        
        while (gameOver == 0)
        {
            if (whosTurn == 0)  // 0 = x's turn
            {
                printf("What is your move?\n");
                scanf("%s", move);

                if (strcmp(move, "T1") == 0 || strcmp(move, "t1") == 0)
                {
                    if (top[1] == ' ')
                    {
                        top[1] = 'x';
                        whosTurn = 1;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 0;
                    }
                    
                }
                else if (strcmp(move, "T2") == 0 || strcmp(move, "t2") == 0)
                {
                    if (top[5] == ' ')
                    {
                        top[5] = 'x';
                        whosTurn = 1;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 0;
                    }
                }
                else if (strcmp(move, "T3") == 0 || strcmp(move, "t3") == 0)
                {
                    if (top[9] == ' ')
                    {
                        top[9] = 'x';
                        whosTurn = 1;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 0;
                    }
                }
                else if (strcmp(move, "M1") == 0 || strcmp(move, "m1") == 0)
                {
                    if (middle[1] == ' ')
                    {
                        middle[1] = 'x';
                        whosTurn = 1;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 0;
                    }
                }
                else if (strcmp(move, "M2") == 0 || strcmp(move, "m2") == 0)
                {
                    if (middle[5] == ' ')
                    {
                        middle[5] = 'x';
                        whosTurn = 1;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 0;
                    }
                }
                else if (strcmp(move, "M3") == 0 || strcmp(move, "m3") == 0)
                {
                    if (middle[9] == ' ')
                    {
                        middle[9] = 'x';
                        whosTurn = 1;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 0;
                    }
                }
                else if (strcmp(move, "B1") == 0 || strcmp(move, "b1") == 0)
                {
                    if (bottom[1] == ' ')
                    {
                        bottom[1] = 'x';
                        whosTurn = 1;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 0;
                    }
                }
                else if (strcmp(move, "B2") == 0 || strcmp(move, "b2") == 0)
                {
                    if (bottom[5] == ' ')
                    {
                        bottom[5] = 'x';
                        whosTurn = 1;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 0;
                    }
                }
                else if (strcmp(move, "B3") == 0 || strcmp(move, "b3") == 0)
                {
                    if (bottom[9] == ' ')
                    {
                        bottom[9] = 'x';
                        whosTurn = 1;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 0;
                    }
                }
                else
                {
                    printf("Invalid move, try again.\n");
                    whosTurn = 0;
                }
                winCheck('x', top, middle, bottom, &gameOver);
                if (gameOver == 1)
                    break;

            }
            

            if (whosTurn == 1)  // 1 = o's turn
            {
                printf("What is your move?\n");
                scanf("%s", move);

                if (strcmp(move, "T1") == 0 || strcmp(move, "t1") == 0)
                {
                    if (top[1] == ' ')
                    {
                        top[1] = 'o';
                        whosTurn = 0;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 1;
                    }
                }
                else if (strcmp(move, "T2") == 0 || strcmp(move, "t2") == 0)
                {
                    if (top[5] == ' ')
                    {
                        top[5] = 'o';
                        whosTurn = 0;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 1;
                    }
                }
                else if (strcmp(move, "T3") == 0 || strcmp(move, "t3") == 0)
                {
                    if (top[9] == ' ')
                    {
                        top[9] = 'o';
                        whosTurn = 0;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 1;
                    }
                }
                else if (strcmp(move, "M1") == 0 || strcmp(move, "m1") == 0)
                {
                    if (middle[1] == ' ')
                    {
                        middle[1] = 'o';
                        whosTurn = 0;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 1;
                    }
                }
                else if (strcmp(move, "M2") == 0 || strcmp(move, "m2") == 0)
                {
                    if (middle[5] == ' ')
                    {
                        middle[5] = 'o';
                        whosTurn = 0;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 1;
                    }
                }
                else if (strcmp(move, "M3") == 0 || strcmp(move, "m3") == 0)
                {
                    if (middle[9] == ' ')
                    {
                        middle[9] = 'o';
                        whosTurn = 0;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 1;
                    }
                }
                else if (strcmp(move, "B1") == 0 || strcmp(move, "b1") == 0)
                {
                    if (bottom[1] == ' ')
                    {
                        bottom[1] = 'o';
                        whosTurn = 0;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 1;
                    }
                }
                else if (strcmp(move, "B2") == 0 || strcmp(move, "b2") == 0)
                {
                    if (bottom[5] == ' ')
                    {
                        bottom[5] = 'o';
                        whosTurn = 0;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 1;
                    }
                }
                else if (strcmp(move, "B3") == 0 || strcmp(move, "b3") == 0)
                {
                    if (bottom[9] == ' ')
                    {
                        bottom[9] = 'o';
                        whosTurn = 0;
                        reset(top, middle, bottom, grid, whosTurn);
                    }
                    else
                    {
                        printf("Invalid move, try again\n");
                        whosTurn = 1;
                    }
                }
                else
                {
                    printf("Invalid move, try again.\n");
                    whosTurn = 1;
                }
                winCheck('o', top, middle, bottom, &gameOver);
                if (gameOver == 1)
                    break;
            }
        }
    return 0;
}