#include "FileManager.h"


void FileManager::saveFile() {
	file.open("guardado.txt");
	if (file.is_open())
	{
		file << "1 " << GetTop1() << endl;
		file << "2 " << GetTop2() << endl;
		file << "3 " << GetTop3() << endl;
		file << "4 " << GetTop4() << endl;
		file << "5 " << GetTop5() << endl;

		file << "6 " << GetLastGame() << endl;
		file << "7 " << GetTotalGames() << endl;

		file.close();
	}
	else cout << "Unable to open file";
}

void FileManager::loadFile() {
	string filePath = "guardado.txt";
	try {
		ifstream objFile(filePath);
		if (objFile.is_open()) {
			string line;
			int count = 0;
			while (getline(objFile, line)) {
				istringstream stringStream(line);
				char c;
				int number = 0;
				switch (line[0]) {
				case '1':
					stringStream >> c >> number;
					SetTop1(number);
					break;
				case '2':
					stringStream >> c >> number;
					SetTop2(number);
					break;
				case '3':
					stringStream >> c >> number;
					SetTop3(number);
					break;
				case '4':
					stringStream >> c >> number;
					SetTop4(number);
					break;
				case '5':
					stringStream >> c >> number;
					SetTop5(number);
					break;
				case '6':
					stringStream >> c >> number;
					SetLastGame(number);
					break;
				case '7':
					stringStream >> c >> number;
					SetTotalGames(number);
					break;
				}
			}
			objFile.close();
		}
		else {
			cout << "No se ha podido abrir el archivo: " << filePath << endl;
		}
	}
	catch (exception& ex) {
		cout << "Excepción al procesar el archivo: " << filePath << endl;
		cout << ex.what() << endl;
	}
}

bool FileManager::existFile(){
	ifstream f(string("guardado.txt").c_str());
	return f.good();
}