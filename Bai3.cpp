#include <iostream>
#include <string>

using namespace std;

void tachKyTu(char* st) {
	while (*st != '\0') {
		cout << *st << "\t";
		st++;
	}
}

void chuyenChuHoa(char* st) {
	while (*st != '\0') {
		if (*st >= 'a' && *st <= 'z') {
			*st = *st - 32;
		}
		cout << *st << "";
		st++;
	}
}
void chuyenKyTuDauThanhChuHoa(char* st) {
	for (int i = 0; i < strlen(st); i++) {
		if (i == 0 || (i > 0 && st[i - 1] == 32)) {
			if (st[i] >= 97 && st[i] <= 122)
				st[i] = st[i] - 32;
		}
		else {
			if (st[i] >= 65 && st[i] <= 90)
				st[i] = st[i] + 32;
		}
	}
}
int main() {
	char* st = new char[100];
	if (st == nullptr) {
		cout << "Loi cap phat bo nho !" << endl;
		return 1;
	}
	cout << "Nhap chuoi : ";
	cin.getline(st, 100);

	cout << "Chuoi da nhap : " << st << endl;

	cout << "\nXuat tung ky tu cua chuoi ra man hinh : \n";
	tachKyTu(st);
	
	cout << "\nChuyen dang chu hoa : \n";
	chuyenChuHoa(st);

	cout << "\nChuyen cac ky tu dau thanh chu hoa : \n";
	chuyenKyTuDauThanhChuHoa(st);
	cout << st << endl;

	delete[] st;

	return 0;
}