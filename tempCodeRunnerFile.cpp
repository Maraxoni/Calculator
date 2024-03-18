int main() {
    float num1, num2;
    char operation;

    cout << "Enter operation: ";
    cin >> num1 >> operation >> num2;

    if (cin && operation == '+' || operation == '-' || operation == '*' || operation == '/') {
        float result = calculate(num1, num2, operation);

        cout << "Result: " << result << endl;
    }
    else {
        cout << "Invalid input!" << endl;
    }

    return 0;
}