#include <stdio.h>

unsigned long long calculate(unsigned long long int base, unsigned long long int exp, unsigned long long mod)
{
    unsigned long long result = 1;

    
    for (unsigned long long i = 0; i < exp; i++)
    {
        result = (result * base) % mod; 
    }

    return result;
}

int main()
{
    unsigned long long base, exponent, modulus, result;

    
    printf("Enter Base (positive integer): ");
    scanf("%llu", &base);

    
    printf("Enter Exponent (non-negative integer): ");
    scanf("%llu", &exponent);

    
    printf("Enter Modulus (integer >= 2): ");
    scanf("%llu", &modulus);

    
    if (base < 1)
    {
        printf("Invalid input for base. It should be a positive integer.\n");
        return 1;
    }

    if (modulus < 2)
    {
        printf("Invalid input for modulus. It should be >= 2.\n");
        return 1;
    }

    
    result = calculate(base, exponent, modulus);

    
    printf("Result: %llu\n", result);

    return 0;
}
