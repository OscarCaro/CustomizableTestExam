// Test Laura

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

typedef char tSolutions [70];
int main () {
	ifstream file;
	string question = "", auxString;
	int i = 0, j = 0, k = 0, correct = 0, wrong = 0, blank= 0, score = 0, numQuestionChange;
	tSolutions realSolution;
	tSolutions userSolution;
	char answer, userAnswer, aux, cambioChar, revisionChar;
	bool cambio = false;
	cout << left << setw(20) << "Instrucciones:" << right  << "v: verdadero" << endl;
	cout << setw(20) << "" << right << "f: falso" << endl;
	cout << setw(20) << "" << right << "-: no se/ no respondo" << endl << endl;
	cout << left << setw(20) << "Puntuacion:" << right  << "Acierto: +2 pto" << endl;
	cout << setw(20) << "" << right << "Fallo: -1 pto" << endl;
	cout << setw(20) << "" << right << "Sin responder: +0 pto" << endl << endl;

	file.open("questions.txt");
	if (file.is_open()) {
		getline(file, question);
		while (question != "#" ) {

			file.get (answer);
			file.get (aux);

			cout << question << endl;
			cout << "Respuesta (v/f/-): ";
			cin >> userAnswer;
			cin.ignore();
			userSolution[i] = userAnswer;
			realSolution[i] = answer;
			getline(file, question);
			i++;
		}

	cout << endl << "¿Desea cambiar alguna respuesta?(s/n): ";
	cin.get(cambioChar);
	cin.ignore();
	if (cambioChar == 's' || cambioChar == 'S') {
		cambio = true;
	}
	if (cambio) {
	cout << "Número de pregunta (0 para terminar): ";
	cin >> numQuestionChange;
		while (cambio) {
			file.close();
			file.open("questions.txt");
			if (file.is_open()) {
				for(int a = 0; a < (numQuestionChange - 1) * 2; a++){
					getline(file, auxString);
				}
				getline(file, question);
				if (question != "#" ) {

					file.get (answer);
					file.get (aux);

					cout << question << endl;
					cout << "Respuesta (v/f/-): ";
					cin >> userAnswer;
					cin.ignore();
					userSolution[numQuestionChange - 1] = userAnswer;
					}
				cout << "Número de pregunta (0 para terminar): ";
				cin >> numQuestionChange;
				if (numQuestionChange == 0) {
					cambio = false;
				}
			}
		}
	}
	file.close();
	while (j < i) {
	if (realSolution[j] == userSolution[j]) {
		score += 2;
		correct++;
	} else if (userSolution [j] == '-') {
		blank++;
	} else if (realSolution[j] != userSolution[j]) {
		score--;
		wrong++;
	}
	j++;
	}
	cout << endl << "Respuestas correctas: " << correct << endl;
	cout << "Respuestas erróneas: " << wrong << endl;
	cout << "Respuestas en blanco: " << blank << endl << endl;
	cout << "Puntuación total: " << score * 10.0 / (i * 2) << "/10" << endl << endl;
	cin.ignore();
	cout << "¿Ver preguntas falladas? (s/n): ";

	cin.get(revisionChar);
	cin.get(aux);
	if (revisionChar == 's' || revisionChar == 'S') {
		while (k < i) {
			if (userSolution [k] == '-' || realSolution[k] != userSolution[k]) {
				file.open("questions.txt");
					if (file.is_open()) {
						for(int i = 0; i < ((k) * 2); i++){
							getline(file, auxString);
						}
						getline(file, question);
						file.get (answer);
						file.get (aux);

						cout << question << endl;
						cout << "Respuesta: " << answer << endl;
					}
				file.close();
			}
			k++;
		}
	}



	}
	return 0;
}




