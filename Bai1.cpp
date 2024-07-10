#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

int main() {
	float a, b, c;
	cout << " Nhập vào số a : ";
	cin >> a;
	cout << " Nhập vào số b : ";
	cin >> b;
	cout << " Nhập vào số c : ";
	cin >> c;
	float result = 0.0;
	try {
		if (a - b == 0)
			throw "Không thể chia cho số 0 ! Điều này dẫn đến vô nghiệm";
		else 
			result = c / (a - b);
	}
	catch (const char* ex) {
		cout << " Lỗi : " << ex;
	}
	cout << "Kết quả : " << result;
}