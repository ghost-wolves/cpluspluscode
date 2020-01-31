#include <cstdio>

enum class Operation {
	Add,
	Subtract,
	Multiply,
	Divide
};

struct Calculator {

	Operation oper;

	Calculator(Operation opert) {
		oper = opert;
	};

	int calculate(int a, int b) {
		int result{};

		switch (oper) {
		case Operation::Add: {
			result = a + b;
			return result;
			break;
		}
		case Operation::Subtract: {
			result = a - b;
			return result;
			break;
		}
		case Operation::Multiply: {
			result = a * b;
			return result;
			break;
		}
		case Operation::Divide: {
			result = a / b;
			return result;
			break;
		}
		default: {
			printf("Error");
		}
		}
	}
};

int main() {
	Calculator Add = Operation::Add;
	Calculator Mins = Operation::Subtract;
	Calculator Times = Operation::Multiply;
	Calculator Divide = Operation::Divide;
	
	int a = Add.calculate(2, 3);
	int b = Mins.calculate(3, 2);
	int c = Times.calculate(3, 3);
	int d = Divide.calculate(100, 10);
	printf("The answers are %d, %d, %d, %d", a, b, c, d);
}

