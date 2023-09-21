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
	cout << "Как вы хотите добавить песню \n1)С клавиатуры\n2)С файла \nВаш выбор: ";
	cin>>choice;
	if (choice == 1) {
	cout << "Введите название песни: ";
	cin.ignore();
		getline(cin, song.name);
		end

	cout << "Введите автора песни: ";
		cin.ignore();
		getline(cin, song.author);
		end

	cout << "Введите дату создания песни: ";
		cin >> song.date;
		end

	cout << "Введите текст песни: ";
		cin.ignore();
		while (true) {
			getline(cin, line);
			if (line.empty()) {
				end
				cout << "Текст песни записан!" << endl;
				break;
			}
			song.text += line+"\n";
			end
		}
		end
		cout << "Введите название файла(название + автор): ";
		getline(cin, name2);
		ofstream file("./music/" + name2 + ".txt");
		if (file) {
			file << "Название: " << song.name << endl;
			file << "Автор: " << song.author << endl;
			file << "Дата создания: " << song.date << endl;
				file << "Текст песни: \n" << song.text << endl;
			file << "*************************************************************" << endl;
			file.close();
			cout << "Песня была успешно добавлена и сохранена в каталог " << endl;
		}
		else cout << "Error 404!" << endl;

	}
	if (choice == 2) {
		string file_name2;
		cout << "Введите название файла: ";
		cin >> file_name2;

	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int choice;
	Music song;
	cout << "\t\tКаталог песен\n1)Добавить\n2)Удалить\n3)Изменить\n4)Отобразить\n5)Поиск\nВаш выбор: ";
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
	default: cout << "Неправильнный ввод" << endl;
		break;
	}

	return 0;
}