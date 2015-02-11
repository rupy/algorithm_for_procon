#include <iostream>

using namespace std;

int stack[1000];
int p;

void push(int a){
	stack[p] = a;
	++p;
}

int pop(){
	--p;
	return stack[p];
}

int main(){
	char s[1000];
	int a, b;
	while (cin >> s){
		switch (s[0]){
			case '+':
				b = pop();
				a = pop();
				push(a + b);
				break;
			case '-':
				b = pop();
				a = pop();
				push(a - b);
				break;
			case '*':
				b = pop();
				a = pop();
				push(a * b);
				break;
			case '/':
				b = pop();
				a = pop();
				push(a / b);
				break;
			default:
				push(atoi(s));
				break;
		}
	}
	cout << pop() << endl;

	return 0;

}