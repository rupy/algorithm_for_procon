#include <iostream>

using namespace std;

typedef struct myqueue{
	string name;
	int t;
} MyQueue;

MyQueue queue[1000];
int head = 0, tail = 0;

void enqueue(MyQueue q){
	queue[tail] = q;
	++tail;
}

MyQueue dequeue(){
	++head;
	return queue[head - 1];
}

bool isEnmpy(){
	return head == tail;
}

int main(){

	int n, q, p[100000];
	string name;
	int t = 0;
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
	{
		cin >> name >> p[i];
		MyQueue qq;
		qq.name.append(name);
		qq.t = p[i];
		enqueue(qq);
	}
	while (true){
		if (isEnmpy()){
			break;
		}
		MyQueue qq = dequeue();
		qq.t -= q;
		if (qq.t > 0){
			t += 100;
			enqueue(qq);
		}else{
			t += 100 + qq.t;
			cout << qq.name << " " << t << endl;
		}
	}
	return 0;
}

/*
5 100
p1 150
p2 80
p3 200
p4 350
p5 20
*/