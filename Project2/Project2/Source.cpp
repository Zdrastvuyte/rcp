#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	string name, filename, choice, prob, userchoice, retry;
	string RPC = "Paper";
	int probab, userc;
	vector <int> proba(3,0);
	cout << "Name: ";
	getline(cin, name);
	filename = name + ".txt";
	
	fstream probability(filename, ios::in | ios::out);
	

	if (!probability)
		cout << "The file has not been opened" << endl;
	else {
		
			cout << "Hi " << name << endl << "Rock beats scissors, paper beats rock and scissors beat papers" << endl << "I'm going to choose one of them...";
			do {
			for (int counter = 0; counter < 3; counter++) {
				getline(probability, prob);
				stringstream(prob) >> probab;
				proba.at(counter) = probab;
			}
			if (proba.at(0) < proba.at(1)) {
				RPC = "Scissors";
				if (proba.at(1) < proba.at(2)) {
					RPC = "Rock";
				}
			}
			else if (proba.at(0) < proba.at(2)) {
				RPC = "Rock";
			}
			else if (proba.at(0) == proba.at(1) && proba.at(0) == proba.at(2))
				RPC = "Paper";

			cout << endl << "I chose! What's your choice?" << endl << "1. Rock" << endl << "2. Paper" << endl << "3. Scissors" << endl;
			getline(cin, userchoice);
			stringstream(userchoice) >> userc;
			probability.close();
			probability.open(filename, ios::trunc | ios::in | ios::out);
			switch (userc)
			{
			case 1: //probability.clear(); User chose rock
				probability << ++proba.at(0) << endl << proba.at(1) << endl << proba.at(2);
				if (RPC == "Scissors")
					cout << "You won" << endl;
				else if (RPC == "Paper")
					cout << "Haha I won" << endl;
				else
					cout << "Tie!" << endl;
				break;
			case 2: //probability.clear(); User chose paper
				probability << proba.at(0) << endl << ++proba.at(1) << endl << proba.at(2);
				if (RPC == "Scissors")
					cout << "Haha I won" << endl;
				else if (RPC == "Paper")
					cout << "Tie!" << endl;
				else
					cout << "You won" << endl;
				break;
			case 3: //probability.clear(); User chose scissors
				probability << proba.at(0) << endl << proba.at(1) << endl << ++proba.at(2);
				if (RPC == "Rock")
					cout << "Haha Iwon" << endl;
				else if (RPC == "Scissor")
					cout << "Tie!" << endl;
				else
					cout << "You won" << endl;
				break;
			default:
				cout << "wrong answer" << endl;
			}

			cout << endl << "My choice was " << RPC << endl;
			cout << "Retry? Y/N" << endl;
			getline(cin, retry);
		} while (retry == "Y" || retry == "y");
		
		probability.close();
	}

	return 0;
}