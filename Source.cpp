#include <iostream>
#include <fstream>
#include <string>
#define end cout << endl;

using namespace std;

struct Music {
	string name;
	string author;
	int date;
	string text;
};

void Add(Music song) {
	int choice;
	string line;
	string name2;
	cout << "��� �� ������ �������� ����� \n1)� ����������\n2)� ����� \n��� �����: ";
	cin>>choice;
	if (choice == 1) {
	cout << "������� �������� �����: ";
	cin.ignore();
		getline(cin, song.name);
		end

	cout << "������� ������ �����: ";
		cin.ignore();
		getline(cin, song.author);
		end

	cout << "������� ���� �������� �����: ";
		cin >> song.date;
		end

	cout << "������� ����� �����: ";
		cin.ignore();
		while (true) {
			getline(cin, line);
			if (line.empty()) {
				end
				cout << "����� ����� �������!" << endl;
				break;
			}
			song.text += line+"\n";
			end
		}
		end
		cout << "������� �������� �����(�������� + �����): ";
		getline(cin, name2);
		ofstream file("./music/" + name2 + ".txt");
		if (file) {
			file << "��������: " << song.name << endl;
			file << "�����: " << song.author << endl;
			file << "���� ��������: " << song.date << endl;
				file << "����� �����: \n" << song.text << endl;
			file << "*************************************************************" << endl;
			file.close();
			cout << "����� ���� ������� ��������� � ��������� � ������� " << endl;
		}
		else cout << "Error 404!" << endl;

	}
	if (choice == 2) {
		string file_name2;
		cout << "������� �������� �����: ";
		cin >> file_name2;

	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int choice;
	Music song;
	cout << "\t\t������� �����\n1)��������\n2)�������\n3)��������\n4)����������\n5)�����\n��� �����: ";
	cin >> choice;

	switch (choice) {
	case 1: Add(song);
		break;
	//case 2: Delete();
	//	break;
	//case 3: Change();
	//	break;
	//case 4:	Show();
	//	break;
	//case 5:	Search();
	//	break;
	default: cout << "������������� ����" << endl;
		break;
	}

	return 0;
}