#include <vector>
#include <iostream>
#include <string>
#include "Player.h"
using namespace std;

Player::Player()
{
	name = NULL;
	playerID = NULL;
	territoryList = *(new vector<Territory*>);
	cards = new Hand();
	orderList = new OrdersList();
}

Player::Player(int* playerID, string* name, vector<Territory*> territoryList, Hand* cards, OrdersList* orderlist)
{
	this->playerID = playerID;
	this->name = name;
	this->territoryList = territoryList;
	this->cards = cards;
	this->orderList = orderlist;
}

Player::Player(const Player& p)
{
	this->playerID = p.playerID;
	this->name = p.name;
	this->territoryList = p.territoryList;
	this->cards = p.cards;
	this->orderList = p.orderList;
}

Player::~Player()
{
	delete playerID;
	playerID = nullptr;
	delete name;
	name = nullptr;
	delete cards;
	cards = nullptr;
	delete orderList;
	orderList = nullptr;
	for (auto p : territoryList)
	{
		delete p;
	}
	territoryList.clear();

}

Player& Player::operator=(const Player& p)
{
	this->playerID = p.playerID;
	this->name = p.name;
	this->territoryList = p.territoryList;
	this->cards = p.cards;
	this->orderList = p.orderList;
	return *this;
}

/*std:: istream& operator>>(std::istream& ins, Player& p1)
{
	ins >> p1.name;
	ins >> p1.cards;
	ins >> p1.territoryList;
	ins >> p1.orderList;
	return ins;
}*/

std::ostream& operator<<(std::ostream& outs, const Player& p1)
{
	outs << *(p1.playerID);
	outs << *(p1.name);
	outs << p1.cards;
	//outs << (p1.territoryList);
	//outs << p1.orderList;

	return outs;
}

vector<Territory*> Player::toAttack()
{
	vector<Territory*> territoriesToAttack;
	if (territoriesToAttack != territoryList) {
		for (auto it = territoriesToAttack.begin(); it != territoriesToAttack.end(); ++it) {
			territoriesToAttack.push_back(*it);
			std::cout << *it << std::endl;
		}
	}

	return territoriesToAttack;
}

vector<Territory*> Player::toDefend()
{

	vector<Territory*> territoriesToDefend = territoryList;

	for (auto i = territoriesToDefend.begin(); i != territoriesTo)
	for (auto defend = territoriesToDefend.begin(); defend != territoriesToDefend.end(); ++defend) {
		// territoriesToDefend.push_back(*defend);
		std::cout << *defend << std::endl;
	}
	return territoriesToDefend;
}

void Player::issueOrder(string order)
{
	if (order == "Deploy") {
		Deploy* deploy = new Deploy();
		orderList->addToListOfOrders(deploy);
	}
	else if (order == "Advance") {
		Advance* advance = new Advance();
		orderList->addToListOfOrders(advance);
	}
	else if (order == "Bomb") {
		Bomb* bomb = new Bomb();
		orderList->addToListOfOrders(bomb);
	}
	else if (order == "Blockade") {
		Blockade* block = new Blockade();
		orderList->addToListOfOrders(block);
	}
	else if (order == "Airlift") {
		Airlift* air = new Airlift();
		orderList->addToListOfOrders(air);
	}
	else if (order == "Negotiate") {
		Negotiate* negotiate = new Negotiate();
		orderList->addToListOfOrders(negotiate);
	}
	else {
		cout << "Error! Please enter one of the following orders: 1. Deploy, 2. Advance, 3. Bomb, 4. Blockade, 5 Airlift, 6. Negotiate." << endl;
	}
}

/*
void Player::issueOrder()
{
	Order* order = new Bomb();
	orderList.push_back(order);
	std::cout << *order << std::endl;
}*/

void Player::setName(const string& n) {
	*name = n;
}

vector<Territory*> Player::getTerritoryList() {
	return territoryList;
}