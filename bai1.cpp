#include<iostream>
using namespace std;

class tong{
	public:
		int songuyen(int a, int b){
			return a+b;
		}
};
int main(){
	int A, B;
	cin >> A >> B;
	tong s;
	int sum = s.songuyen(A,B);
	cout << sum << endl;
	return 0;
}
