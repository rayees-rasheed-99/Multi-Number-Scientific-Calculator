#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {

    char calc, operator, soperator;
    double number, total;
    double exponent;

    printf("=== Multi-Number and Scientific Calculator ===\n");

    while (1) {

        printf("\nChoose:\n");
        printf("A. Basic Calculator\n");
        printf("B. Scientific Calculator\n");
        printf("C. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &calc);


        /* =====================================================
                         BASIC CALCULATOR
           ===================================================== */

        switch (calc) {

        case 'A':
        case 'a':

            printf("\n=== Basic Calculator ===\n");

            printf("Enter starting number: ");
            scanf("%lf", &total);

            while (1) {

                printf("\nEnter operator (+, -, *, /) or C to exit: ");
                scanf(" %c", &operator);

                if (operator == 'C' || operator == 'c') {
                    break;
                }

                printf("Enter next number: ");
                scanf("%lf", &number);

                switch (operator) {

                case '+':

                    total += number;
                    break;

                case '-':

                    total -= number;
                    break;

                case '*':

                    total *= number;
                    break;

                case '/':

                    if (number == 0) {
                        printf("Error: Cannot divide by zero!\n");
                        continue;
                    }

                    total /= number;
                    break;

                default:

                    printf("Invalid operator! Try again.\n");
                    continue;
                }

                printf("Total: %.6lf\n", total);
            }

            break;


        /* =====================================================
                     SCIENTIFIC CALCULATOR
           ===================================================== */

        case 'B':
        case 'b':

            printf("\n=== Scientific Calculator ===\n");

            printf("Enter starting number: ");
            scanf("%lf", &total);

            while (1) {

                printf("\n--------------------------------\n");
                printf("Current value: %.6lf\n", total);
                printf("--------------------------------\n");

                printf("Choose operation:\n");

                printf("+  Addition\n");
                printf("-  Subtraction\n");
                printf("*  Multiplication\n");
                printf("/  Division\n");

                printf("1. Sin\n");
                printf("2. Cos\n");
                printf("3. Tan\n");
                printf("4. GIF (Greatest Integer Function)\n");
                printf("5. LIF (Least Integer Function)\n");
                printf("6. Exponential (e^x)\n");
                printf("7. Power (x^y)\n");
                printf("8. Logarithm (log10)\n");
                printf("9. Natural Logarithm (ln)\n");

                printf("C. Exit Scientific Calculator\n");

                printf("\nEnter operation: ");
                scanf(" %c", &soperator);


                /* ---------- EXIT ---------- */

                if (soperator == 'C' || soperator == 'c') {
                    break;
                }


                /* =================================================
                              BASIC OPERATIONS
                   ================================================= */

                if (soperator == '+' ||
                        soperator == '-' ||
                        soperator == '*' ||
                        soperator == '/') {

                    printf("Enter next number: ");
                    scanf("%lf", &number);

                    switch (soperator) {

                    case '+':

                        total += number;
                        break;

                    case '-':

                        total -= number;
                        break;

                    case '*':

                        total *= number;
                        break;

                    case '/':

                        if (number == 0) {
                            printf("Error: Cannot divide by zero!\n");
                            continue;
                        }

                        total /= number;
                        break;
                    }

                    printf("Result: %.6lf\n", total);

                    continue;
                }


                /* =================================================
                          SCIENTIFIC OPERATIONS
                   ================================================= */

                switch (soperator) {

                /* ---------- SIN ---------- */

                case '1':

                    total = sin(total * PI / 180.0);

                    printf("sin(current value) = %.6lf\n", total);

                    break;


                /* ---------- COS ---------- */

                case '2':

                    total = cos(total * PI / 180.0);

                    printf("cos(current value) = %.6lf\n", total);

                    break;


                /* ---------- TAN ---------- */

                case '3':

                    if (fabs(cos(total * PI / 180.0)) < 1e-10) {

                        printf("Error: tan is undefined for this angle.\n");

                    }
                    else {

                        total = tan(total * PI / 180.0);

                        printf("tan(current value) = %.6lf\n", total);
                    }

                    break;


                /* ---------- GIF ---------- */

                case '4':

                    total = floor(total);

                    printf("GIF = %.6lf\n", total);

                    break;


                /* ---------- LIF ---------- */

                case '5':

                    total = ceil(total);

                    printf("LIF = %.6lf\n", total);

                    break;


                /* ---------- EXPONENTIAL ---------- */

                case '6':

                    total = exp(total);

                    printf("e^x = %.6lf\n", total);

                    break;


                /* ---------- POWER ---------- */

                case '7':

                    printf("Enter exponent: ");
                    scanf("%lf", &exponent);

                    total = pow(total, exponent);

                    printf("Result = %.6lf\n", total);

                    break;


                /* ---------- LOGARITHM ---------- */

                case '8':

                    if (total <= 0) {

                        printf("Error: log is defined only for positive numbers.\n");

                    }
                    else {

                        total = log10(total);

                        printf("log10(x) = %.6lf\n", total);
                    }

                    break;


                /* ---------- NATURAL LOG ---------- */

                case '9':

                    if (total <= 0) {

                        printf("Error: ln is defined only for positive numbers.\n");

                    }
                    else {

                        total = log(total);

                        printf("ln(x) = %.6lf\n", total);
                    }

                    break;


                /* ---------- INVALID ---------- */

                default:

                    printf("Invalid operation! Try again.\n");
                }
            }

            break;

        case 'C':
        case 'c':

            printf("\nThank you for using the calculator!\n");
            return 0;

        default:

            printf("Invalid choice! Please choose A, B or C.\n");
        }
    }

    return 0;
}