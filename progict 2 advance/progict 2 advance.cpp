
#include <iostream>
#include <cstdlib>
#include<string>
using namespace std;
enum EnLivel
{
	easy = 1, med = 2, hard = 3, mix = 4
};
enum TypeOpe
{
	add = 1, sub = 2, mul = 3, div1 = 4, mix1 = 5
};
struct StAnwsar
{
	int number1=0;
	int number2 = 0;
	EnLivel QueLivil;
	TypeOpe QueType;
	int ChoseAnawser = 0;
	int TrueAnawser = 0;
	bool AnawserReslt = false;

};
struct stQuizz
{
	StAnwsar anwsaeListe[100];
	short numberOfQusetins;
	EnLivel QusetinsLivel;
	TypeOpe OpType;
	short NumberOfWrongAnswer = 0;
	short NuberOfRightAnswer = 0;
	bool IsPass = false;
};
int Sim(int num1, int num2, TypeOpe Ope) {
	if (Ope == TypeOpe::add) {
		return num1 + num2;
	}
	else if (Ope == TypeOpe::sub) {
		return num1 - num2;
	}
	else if (Ope == TypeOpe::mul) {
		return num1 * num2;
	}
	else if (Ope == TypeOpe::div1) {
		return num1 / num2;
	}
	
}
int rondom123(int from, int to) {
	int rendome = rand() % (to - from + 1) + from;
	return rendome;
}
short howMonyQw() {
	short gameRawnd = 1;
	do
	{
		cout << "haw many qwitch 1 to 10 ? \n";
		cin >> gameRawnd;
	} while (gameRawnd < 1 || gameRawnd>10);
	return gameRawnd;
}
EnLivel howLivelQW() {
	short gameRawnd = 1;
	do
	{
		cout << "haw livle qwitch ease=1||med=2||hared=3||mix=4 ? \n";
		cin >> gameRawnd;
	} while (gameRawnd < 1 || gameRawnd>4);
	return (EnLivel)gameRawnd;
}
TypeOpe howOpretorlType() {
	short gameRawnd = 1;
	do
	{
		cout << "haw livle qwitch add=1||sub=2||mul=3||dicv=4||mix=5 ? \n";
		cin >> gameRawnd;
	} while (gameRawnd < 1 || gameRawnd>5);
	return (TypeOpe)gameRawnd;
}
TypeOpe GetRondomType() {
	int Op = rondom123(1, 4);
	return (TypeOpe)Op;
}
string stringOpType(TypeOpe x) {
	string Arry[5] = { "+", "-", "* ", "/ " };
	return Arry[x - 1];
}
string convirtLivle(EnLivel win) {
	string arryWin[5] = { "easy ", "med ", "hard ", "mix " };
	return arryWin[win - 1];
}
string convirtLivle(TypeOpe win) {
	string arryWin[6] = { "add ", "sub ", "mul ", "div1 ", "mix1 " };
	return arryWin[win - 1];
}
string GetfinlalText(bool pass) {
	if (pass)
		return ":)";
	else
		return ":(";
}
StAnwsar QwuseRownd(EnLivel Livel,TypeOpe Opretoin) {
	StAnwsar Anawser;
	if (Livel == EnLivel::mix) {
		Livel = (EnLivel)rondom123(1, 3);
	}
	if (Opretoin == TypeOpe::mix1) {
		Opretoin = (TypeOpe)rondom123(1, 4);
	}
	Anawser.QueType = Opretoin;
	switch (Livel)
	{
	case easy:
		Anawser.number1 = rondom123(1, 10);
		Anawser.number2 = rondom123(1, 10);
		Anawser.TrueAnawser = Sim(Anawser.number1, Anawser.number2, Anawser.QueType);
		Anawser.QueLivil = Livel;
		return Anawser;
		break;
	case med:
		Anawser.number1 = rondom123(10, 20);
		Anawser.number2 = rondom123(10, 20);
		Anawser.TrueAnawser = Sim(Anawser.number1, Anawser.number2, Anawser.QueType);
		Anawser.QueLivil = Livel;
		return Anawser;
		break;
	case hard:
		Anawser.number1 = rondom123(20, 30);
		Anawser.number2 = rondom123(20, 30);
		Anawser.TrueAnawser = Sim(Anawser.number1, Anawser.number2, Anawser.QueType);
		Anawser.QueLivil = Livel;
		return Anawser;
		break;
	default:
		break;
	}
	return Anawser;
}
void QuseGameRownd(stQuizz &quizz) {
	for (int i = 0; i < quizz.numberOfQusetins; i++) {
		quizz.anwsaeListe[i] = QwuseRownd(quizz.QusetinsLivel, quizz.OpType);
	}
}
void PrentQwuse(stQuizz& quizz,short NumberRownd) {
	cout << endl;
	cout << "question [" << NumberRownd + 1 << "/" << quizz.numberOfQusetins << "]\n\n";
	cout << to_string(quizz.anwsaeListe[NumberRownd].number1) + stringOpType(quizz.anwsaeListe[NumberRownd].QueType) + to_string(quizz.anwsaeListe[NumberRownd].number2) + "=" << endl;
	cout << "\n--------------------------" << endl<<endl;
}
int readUser() {
	int x=0;
	cout << "enter anawser :  ";
	cin >> x;
	return x;
}
void corectUserAnawser(stQuizz& quizz, short NumberASK) {
	if (quizz.anwsaeListe[NumberASK].ChoseAnawser != quizz.anwsaeListe[NumberASK].TrueAnawser) {
		quizz.anwsaeListe[NumberASK].AnawserReslt = false;
		quizz.NumberOfWrongAnswer++;
		cout << "worng anawser :(\n";
		cout << "the right anwesr is: ";
		cout << quizz.anwsaeListe[NumberASK].TrueAnawser<<endl;
	}
	else {
		quizz.anwsaeListe[NumberASK].AnawserReslt = true;
		quizz.NuberOfRightAnswer++;
		cout << "right Answer :)\n";
	}
	cout << endl;
}
void AskAndCorrectQuseList(stQuizz& quizz) {
	for (short i = 0; i < quizz.numberOfQusetins; i++) {
		PrentQwuse(quizz, i);
		quizz.anwsaeListe[i].ChoseAnawser = readUser();
		corectUserAnawser(quizz, i);
	}
	quizz.IsPass = (quizz.NuberOfRightAnswer >= quizz.NumberOfWrongAnswer);
}
void showFinal(stQuizz quizz) {
	cout << "----------------[game reslt]----------------\n\n";
	cout << "final reslt is " << GetfinlalText(quizz.IsPass)<<endl;
	cout << "----------------------------------------------\n";
	cout << "number of questions     :" <<quizz.numberOfQusetins<<endl;
	cout << "questions livel         :" << convirtLivle(quizz.QusetinsLivel) << endl;
	cout << "opType                  :" << convirtLivle(quizz.OpType) << endl;
	cout << "number of right answers :" << quizz.NuberOfRightAnswer << endl;
	cout << "number of wrong answers :" << quizz.NumberOfWrongAnswer << endl;
	cout << "----------------------------------------------\n";
}
void playMathGame() {
	stQuizz quizz;
	quizz.numberOfQusetins = howMonyQw();
	quizz.QusetinsLivel = howLivelQW();
	quizz.OpType = howOpretorlType();
	QuseGameRownd(quizz);
	AskAndCorrectQuseList(quizz);
	showFinal(quizz);

}

int main()
{
	srand((unsigned)time(NULL));
	playMathGame();
}


