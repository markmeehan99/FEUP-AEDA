#include "HomeGame.h"
#include "Game.h"
#include <string>
#include <iostream>
#include <fstream>


HomeGame::HomeGame(){

}
HomeGame::HomeGame(int age_limit, string name, double price, int rating,
		string platform, string genre, Empresa *publisher) :
		Game(age_limit, name, price, rating, platform, genre, publisher) {

}

void HomeGame::importGameInfo(string file, BST<Empresa*> empresas) {

	file += ".txt";
	ifstream is(file);

	string name, age, price, rating, platform, genre, publisher, totalPlayTime;

	if (is.is_open()) {
		getline(is, name);
		getline(is, age);
		getline(is, price);
		getline(is, rating);
		getline(is, platform);
		getline(is, genre);
		getline(is, publisher);
		getline(is, totalPlayTime);

		ID++;
		this->age_limit = stoi(age);
		this->name = name;
		this->price = stoi(price);
		this->rating = stoi(rating);
		this->platform = platform;
		this->genre = genre;
		this->id = ID;


		BSTItrIn<Empresa*> itr(empresas);
		while(!itr.isAtEnd()){
			if (itr.retrieve()->getName() == publisher){
				this->publisher = itr.retrieve();
				break;
			}
			itr.advance();
		}
	} else
		cout << "Nao abriu file" << endl;
}
