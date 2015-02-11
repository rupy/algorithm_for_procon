#include <iostream>

using namespace std;

typedef struct process{
	string name;
	int t;
} Process;

Process queue[1000];
int head = 0, tail = 0;

void enqueue(Process q){
	queue[tail] = q;
	++tail;
}

Process dequeue(){
	++head;
	return queue[head - 1];
}

bool isEnmpy(){
	return head == tail;
}

int main(){

	// TODO: ERROR CHECK
	int n, q, p[100000];
	string name;
	int t = 0;
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
	{
		cin >> name >> p[i];
		Process pp;
		pp.name += name;
		pp.t = p[i];
		enqueue(pp);
	}
	while (true){
		if (isEnmpy()){
			break;
		}
		Process pp = dequeue();
		pp.t -= q;
		if (pp.t > 0){
			t += 100;
			enqueue(pp);
		}else{
			t += 100 + pp.t;
			cout << pp.name << " " << t << endl;
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