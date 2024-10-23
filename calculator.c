#include <stdio.h>
#include <string.h>

int main()
{
    char operation[10];
    float num1, num2, ans;
    
    printf("Enter your calculation:\n");
    scanf("%f %s %f", &num1, operation, &num2);

    if (strcmp(operation, "+") == 0 || strcmp(operation, "plus") == 0)
    {
        ans = num1 + num2;
        printf("%.0f + %.0f = %.0f\n", num1, num2, ans);
    }

    else if (strcmp(operation, "-") == 0 || strcmp(operation, "minus") == 0)
    {
        ans = num1 - num2;
        printf("%.0f - %.0f = %.0f\n", num1, num2, ans);
    }

    else if (strcmp(operation, "x") == 0 || strcmp(operation, "times") == 0)
    {
        ans = num1 * num2;
        printf("%.0f x %.0f = %.0f\n", num1, num2, ans);
    }

    else if (strcmp(operation, "/") == 0 || strcmp(operation, "divide") == 0)
    {
        ans = num1 / num2;
        printf("%.0f ÷ %.0f = %.2f\n", num1, num2, ans);
    }
    return 0;
}