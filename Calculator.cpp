#include <iostream>

int main() {
    int x, y, wynik;
    char operacja;

    std::cout << "Podaj pierwsza liczbe: ";
    std::cin >> x;

    std::cout << "Podaj operacje (+ lub -): ";
    std::cin >> operacja;

    std::cout << "Podaj druga liczbe: ";
    std::cin >> y;

    asm (
        "mov %[x], %%eax\n\t"
        "mov %[y], %%ebx\n\t"
        "cmp $'+', %[operacja]\n\t"
        "je addition\n\t"
        "cmp $'-', %[operacja]\n\t"
        "je subtraction\n\t"
        "jmp koniec\n\t"

        "addition:\n\t"
        "add %%ebx, %%eax\n\t"
        "jmp koniec\n\t"

        "subtraction:\n\t"
        "sub %%ebx, %%eax\n\t"
        "jmp koniec\n\t"

        "subtraction:\n\t"
        "sub %%ebx, %%eax\n\t"
        "jmp koniec\n\t"

        "subtraction:\n\t"
        "sub %%ebx, %%eax\n\t"
        "jmp koniec\n\t"

        "koniec:\n\t"
        "mov %%eax, %[wynik]"
        : [wynik] "=r" (wynik)
        : [x] "r" (x), [y] "r" (y), [operacja] "r" (operacja)
        : "%eax", "%ebx"
    );

    std::cout << "Wynik: " << wynik << std::endl;

    return 0;
}