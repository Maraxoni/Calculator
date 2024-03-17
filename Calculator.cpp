#include <iostream>

int main() {
    float x, y, result;
    char operation;

    std::cout << "Give first number: ";
    std::cin >> x;

    std::cout << "Select operation (+,-,*,/): ";
    std::cin >> operation;

    std::cout << "Give second number: ";
    std::cin >> y;

    asm (
        "fld %[x]\n\t"
        "fld %[y]\n\t"
        "cmp $'+', %[operation]\n\t"
        "je addition\n\t"
        "cmp $'-', %[operation]\n\t"
        "je subtraction\n\t"
        "cmp $'*', %[operation]\n\t"
        "je multiplication\n\t"
        "cmp $'/', %[operation]\n\t"
        "je division\n\t"
        "jmp finish\n\t"

        "addition:\n\t"
        "faddp\n\t"
        "jmp finish\n\t"

        "subtraction:\n\t"
        "fsubp\n\t"
        "jmp finish\n\t"

        "multiplication:\n\t"
        "fmulp\n\t"
        "jmp finish\n\t"

        "division:\n\t"
        "fdivp\n\t"
        "jmp finish\n\t"

        "finish:\n\t"
        "fstp %[result]"
        : [result] "=t" (result) // Poprawiona składnia "=t"
        : [x] "m" (x), [y] "m" (y), [operation] "m" (operation)
        : "memory"
    );

    std::cout << "Result: " << result << std::endl;

    return 0;
}
