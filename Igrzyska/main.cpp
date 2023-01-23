//Magdalena Lipka
#include <iostream>
using namespace std;

class PLAYER_CLASS;
class CAESAR_CLASS;
class ARENA_CLASS;
class HUMAN_CLASS;
class BEAST_CLASS;
class BERSERKER_CLASS;


class PLAYER_CLASS {
	
	friend class CAESAR_CLASS;
	friend class ARENA_CLASS;
	friend class SQUAD_CLASS;

public:

	unsigned int maxhealth;
	unsigned int currenthealth;
	unsigned int attack;
	unsigned int agility;

	PLAYER_CLASS ( unsigned int max = 0, unsigned int current = 0, unsigned int damage = 0, unsigned int flex = 0 ) {
		maxhealth = max;
		currenthealth = current;
		attack = damage;
		agility = flex;
	}

	virtual unsigned int getRemainingHealth() {
		if ( (*this).maxhealth == 0 ) return 1;
		return (*this).currenthealth*100/(*this).maxhealth;
	}

	virtual unsigned int getCurrent() {
		return (*this).currenthealth;
	}

	virtual unsigned int getDamage() = 0;

	virtual unsigned int getAgility() {
		return (*this).agility;
	}

	virtual void takeDamage ( unsigned int damage ) {};

	virtual void applyWinnerReward() {
		(*this).agility += 2;
		(*this).attack += 2;
	}

	virtual void cure() {
		(*this).currenthealth = (*this).maxhealth;
	}

	virtual void printParams() = 0;

protected:

	virtual void die() {
		(*this).currenthealth = 0;
	}

};


class ListOfPlayers {

public:

	ListOfPlayers *prev;
	PLAYER_CLASS *player;
	ListOfPlayers *next;

	ListOfPlayers( ListOfPlayers *prev, PLAYER_CLASS *player, ListOfPlayers *next ) {
		(*this).prev = prev;
		(*this).player = player;
		(*this).next = next;
	}
};

class CAESAR_CLASS {

	friend class ARENA_CLASS;

public:

	unsigned int sentences;

	CAESAR_CLASS() {
		sentences = 0;
	}

	void judgeDeathOfLife ( PLAYER_CLASS* player ) {
		sentences++;
		if ( sentences%3 == 0 ) {
			(*player).die();
		}
	}
};

class HUMAN_CLASS: public virtual PLAYER_CLASS{

public:

	string ID;
	unsigned int defense;

	HUMAN_CLASS ( string id ) : PLAYER_CLASS() {
		(*this).ID = id;
		(*this).maxhealth = 200;
		(*this).currenthealth = 200;
		(*this).attack = 30;
		(*this).agility = 10;
		(*this).defense = 10;
	}

	virtual unsigned getDamage() {
		return (*this).attack;
	}

	virtual unsigned int getCurrent() {
		return (*this).currenthealth;
	}

	virtual unsigned int getDefense() {
		return (*this).defense;
	}	

	virtual void takeDamage ( unsigned int arg ) {
		int harm = (int) arg - ((*this).defense + (*this).agility);
		if ( harm < 0 ) return;
		if ( harm > (*this).currenthealth ) (*this).die();
		else (*this).currenthealth = (*this).currenthealth - arg + (*this).defense + (*this).agility;
	}

	virtual void printParams() {
		if ( (*this).currenthealth != 0 ) {
			cout << (*this).ID << ":" << (*this).maxhealth << ":" << (*this).currenthealth << ":" << (*this).getRemainingHealth() << "%:" << (*this).attack << ":" << (*this).agility << ":" << (*this).defense << endl;
		}
		else cout << (*this).ID << ":R.I.P." << endl;
	}
	
	void setid ( string id ) {
		(*this).ID = id;
	}
	
	void setcurrent ( unsigned int current ) {
		(*this).currenthealth = current;
	}
	
	void setmax( unsigned max ) {
		(*this).maxhealth = max;
	}
	
	void setattack ( unsigned int damage ) {
		(*this).attack = damage;
	}
	
	void setagility ( unsigned int flex ) {
		(*this).agility = flex;
	}
	
	void setdefense ( unsigned int shield ) {
		(*this).defense = shield;
	}
};

class BEAST_CLASS : public virtual PLAYER_CLASS{

public:

	string ID;

	BEAST_CLASS ( string id ) : PLAYER_CLASS() {
		(*this).ID = id;
		(*this).maxhealth = 150;
		(*this).currenthealth = 150;
		(*this).attack = 40;
		(*this).agility = 20;
	}

	virtual unsigned getDamage(){
		if ( (*this).getRemainingHealth() < 25 ) return 2*(*this).attack;
		return (*this).attack;
	}

	virtual void takeDamage ( unsigned int damage ) {
		int harm = (int) damage-((*this).agility/2);
		if ( harm < 0 ) return;
		if ( harm > (*this).currenthealth ) (*this).die(); 
		else (*this).currenthealth = (*this).currenthealth - damage + ((*this).agility/2);
	}
	
	virtual unsigned int getCurrent() {
		return (*this).currenthealth;
	}

	virtual void printParams() {
		if ( (*this).currenthealth != 0 ){
			cout << (*this).ID << ":" << (*this).maxhealth << ":" << (*this).currenthealth << ":" << (*this).getRemainingHealth() << "%:" << (*this).getDamage() << ":" << (*this).agility << endl;
		}
		else cout << (*this).ID << ":R.I.P." << endl;
	}

protected:

	void setid(string id) {
		(*this).ID = id;
	}

	void setcurrent ( unsigned int current ) {
		(*this).currenthealth = current;
	}

	void setmax ( unsigned max ) {
		(*this).maxhealth = max;
	}

	void setattack ( unsigned int damage ) {
		(*this).attack = damage;
	}

	void setagility ( unsigned int flex ) {
		(*this).agility = flex;
	}

};

class BERSERKER_CLASS : public HUMAN_CLASS, public BEAST_CLASS {

public:

	
	BERSERKER_CLASS ( string humanid, string beastid) : HUMAN_CLASS(humanid), BEAST_CLASS(beastid), PLAYER_CLASS() {
		
		HUMAN_CLASS::setid(humanid);
		HUMAN_CLASS::setagility(5);
		HUMAN_CLASS::setattack(35);
		HUMAN_CLASS::setcurrent(200);
		HUMAN_CLASS::setmax(200);
		HUMAN_CLASS::setdefense(15);
		BEAST_CLASS::setid(beastid);
		BEAST_CLASS::setmax(200);
		BEAST_CLASS::setcurrent(200);
		BEAST_CLASS::setattack(35);
		BEAST_CLASS::setagility(5);
		
	}

	unsigned int getDamage() {
		if ( getRemainingHealth() >= 25 || currenthealth == 0 ) return HUMAN_CLASS::getDamage();
		else return BEAST_CLASS::getDamage(); 
	}

	void takeDamage ( unsigned int damage ) {
		if ( getRemainingHealth() >= 25 || currenthealth == 0 ) HUMAN_CLASS::takeDamage(damage);
		else BEAST_CLASS::takeDamage(damage);  
	}

	void printParams() {
		if ( getRemainingHealth() >= 25 || currenthealth == 0 ) {
			HUMAN_CLASS::printParams();
		}
		else BEAST_CLASS::printParams();  
	}

	unsigned int getCurrent() {
		if ( getRemainingHealth() >= 25 || currenthealth == 0 ) return HUMAN_CLASS::getCurrent();
		else return BEAST_CLASS::getCurrent();
	}

	unsigned int getAgility() {
		if ( getRemainingHealth() >= 25 || currenthealth == 0 ) return HUMAN_CLASS::getAgility();
		else return BEAST_CLASS::getAgility();
	}

};

class SQUAD_CLASS : public PLAYER_CLASS {

public:

	string ID;
	ListOfPlayers *first;
	unsigned int playerscount;

	SQUAD_CLASS ( string id ) {
		ID = id;
		first = NULL;
		playerscount = 0;
	}

	void addPlayer ( PLAYER_CLASS *newplayer ) {
		if ( (*newplayer).getRemainingHealth() == 0 ) return;
		if ( first == NULL ) {
			playerscount++;
			ListOfPlayers *nowy = new ListOfPlayers(NULL, newplayer, NULL);
			first = nowy;
		}
		else {
			ListOfPlayers *temp = first;
			while ( 1 > 0 ) {
				if ( (*temp).player == newplayer ) return;
				if ( (*temp).next == NULL ) {
					ListOfPlayers *nowy = new ListOfPlayers(temp, newplayer, NULL);
					(*temp).next = nowy;
					playerscount++;
					break;
				}
				temp = (*temp).next;
			}
		}
	}

	unsigned int getRemainingHealth() {
		unsigned int health = 0;
		ListOfPlayers *temp = first;
		while ( temp != NULL ) {
			if ( health < (*(*temp).player).getRemainingHealth() ) health = (*(*temp).player).getRemainingHealth(); 
			temp = (*temp).next;
		}
		return health;
	}

	unsigned int getDamage() {
		unsigned int sum = 0;
		ListOfPlayers *temp = first;
		while ( temp != NULL ) {
			sum += (*(*temp).player).getDamage();
			temp = (*temp).next;
		}
		return sum;
	}

	void takeDamage ( unsigned int damage ) {
		ListOfPlayers *temp = first;
		int deadcounter = 0;
		while ( temp != NULL ) {
			(*(*temp).player).takeDamage(damage/playerscount);
			if ( (*(*temp).player).getRemainingHealth() == 0 ) {
				deadcounter++;
				//usuniecie z listy

				if ( temp == first && (*temp).next == NULL ) {
					first = NULL;
					break;
				}

				if ( (*temp).prev == NULL ) {
					first = (*temp).next;
					(*first).prev = NULL;
				}
				else {
					(*(*temp).prev).next = (*temp).next;
				}

				if ( (*temp).next == NULL ) {
					(*(*temp).prev).next = NULL;
				}
				else {
					(*(*temp).next).prev = (*temp).prev;
				}
	
			}
			temp = (*temp).next;
		}
		playerscount -= deadcounter;
	}

	unsigned int getCurrent() {
		if ( first == NULL ) return 0;
		else {
			return 1;
		}
	}

	unsigned int getAgility() {
		ListOfPlayers *temp = first;
		unsigned int pom = __UINT32_MAX__;
		while ( temp != NULL ) {
			if ( pom > (*(*temp).player).getAgility() ) pom = (*(*temp).player).getAgility();
			temp = (*temp).next;
		}
		return pom;
	}

	void cure() {
		ListOfPlayers *temp = first;
		while ( temp != NULL ) {
			(*(*temp).player).cure();
			temp = (*temp).next;
		}
	}

	void applyWinnerReward() {
		ListOfPlayers *temp = first;
		while ( temp != NULL ) {
			(*(*temp).player).applyWinnerReward();
			temp = (*temp).next;
		}
	}

	void printParams() {
		if ( first != NULL ) {
			ListOfPlayers *temp = first;
		
			cout << (*this).ID << ":" << playerscount << ":" << (*this).getRemainingHealth() << "%:" << (*this).getDamage() << ":" << (*this).getAgility() << endl;

			while ( temp != NULL ) {
				(*(*temp).player).printParams();
				temp = (*temp).next;
			}
		}
		else cout << ID << ":nemo" << endl;
	}

	void die() {
		ListOfPlayers *temp = first;
		while ( temp != NULL ) {
			(*(*temp).player).die();
			temp = (*temp).next;
		}
		first = NULL;
		//powinno jeszcze być
		playerscount = 0;
		//ale przeszło na bacy bez tego
	}

};

class ARENA_CLASS {

	friend PLAYER_CLASS;

private:

	CAESAR_CLASS *caesar;

public:

	ARENA_CLASS ( CAESAR_CLASS *Caesar ) {
		caesar = Caesar;
	}

	void fight ( PLAYER_CLASS* player1, PLAYER_CLASS* player2 ) {
		if ( (*player1).getRemainingHealth() == 0 || (*player2).getRemainingHealth() == 0 ) {
			return;
		}

		PLAYER_CLASS *first, *second;
	
		if ( (*player1).getAgility() > (*player2).getAgility() ) {
			first = player1;
			second = player2;
		}
		else if ( (*player1).getAgility() < (*player2).getAgility() ) {
			first = player2;
			second = player1;
		}
		else {
			first = player1;
			second = player2;
		}

		(*first).printParams();
		(*second).printParams();

		unsigned int attacks = 0;

		while ( 1 > 0 ) {
			if ( attacks == 40 || (*first).getRemainingHealth() < 10 || (*second).getRemainingHealth() < 10 ) {
				break;
			}

			if ( (*first).getRemainingHealth() > 0 ) {
				(*second).takeDamage( (*first).getDamage() );
				attacks++;
				(*second).printParams();
			}

			if ( attacks == 40 || (*first).getRemainingHealth() < 10 || (*second).getRemainingHealth() < 10 ) {
				break;
			}
			if ( (*second).getRemainingHealth() > 0 ) {
				(*first).takeDamage( (*second).getDamage() );
				attacks++;
				(*first).printParams();
			}
		}

		if ( (*first).getRemainingHealth() > 0 ) {
			if ( attacks%2 == 0 ) (*caesar).judgeDeathOfLife(first);
			(*first).printParams();
		}

		if ( (*second).getRemainingHealth() > 0 ) {
			if ( attacks%2 == 0 ) (*caesar).judgeDeathOfLife(second);
			(*second).printParams();
		}

		if ( (*first).getRemainingHealth() > 0 ) {
			(*first).applyWinnerReward();
			(*first).cure();
		}

		if ( (*second).getRemainingHealth() > 0 ) {
			(*second).applyWinnerReward();
			(*second).cure();
		}
		(*first).printParams();
		(*second).printParams();
	}

};
