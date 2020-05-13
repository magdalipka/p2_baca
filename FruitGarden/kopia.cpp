
#include <iostream>
using namespace std;

class FRUIT_CLASS;
class BRANCH_CLASS;
class WOOD_CLASS;
class GARDEN_CLASS;

class FRUIT_CLASS {

	private:
	BRANCH_CLASS *parent;
	FRUIT_CLASS *prev;
	FRUIT_CLASS *next;
	unsigned int weight;
	unsigned int length;
	
	public:

	FRUIT_CLASS() {
		this->prev = NULL;
		this->next = NULL;
		this->weight = 0;
		this->length = 0;
		this->parent = NULL;
	}

	FRUIT_CLASS(BRANCH_CLASS* rodzic, FRUIT_CLASS* poprzedni, FRUIT_CLASS* nastepny, unsigned int waga, unsigned int dlugosc) {
		prev = poprzedni;
		next = nastepny;
		weight = waga;
		length = dlugosc;
		parent = rodzic;
	}

	FRUIT_CLASS(const FRUIT_CLASS& origin) {
		prev = NULL;
		next = NULL;
		parent = NULL;
		weight = origin.weight;
		length = origin.length;
	}

	void setnext(FRUIT_CLASS* arg) {
		next = arg;
	}

	void setprev(FRUIT_CLASS* arg) {
		prev = arg;
	}

	void setLength(unsigned int arg) {
		length = arg;
	}

	void setWeight(unsigned int arg) {
		weight = arg;
	}

	void setparent(BRANCH_CLASS* arg) {
		parent = arg;
	}

	FRUIT_CLASS* getnext() {
		return next;
	}

	FRUIT_CLASS* getprev() {
		return prev;
	}
	
	unsigned int getLength() {
		return length;
	}

	unsigned int getWeight() {
		return weight;
	}

	void growthFruit() {
		weight++;
	}

	void fadeFruit() {
		if ( weight > 0 ) weight--;
	}

	void pluckFruit() {
		weight = 0;
	}

	BRANCH_CLASS* getBranchPointer() {
		return parent;
	}
};



class BRANCH_CLASS {

	private:	
	WOOD_CLASS *parent;
	BRANCH_CLASS* prev;
	BRANCH_CLASS *next;
	FRUIT_CLASS *first;
	FRUIT_CLASS *last;
	unsigned int height;
	unsigned int length;

	public:

	BRANCH_CLASS() {
		parent = NULL;
		prev = NULL;
		next = NULL;
		first = NULL;
		last = NULL;
		height = 0;
		length = 0;
	}

	BRANCH_CLASS(WOOD_CLASS* rodzic, BRANCH_CLASS* poprzednia, BRANCH_CLASS* nastepna, FRUIT_CLASS* pierwszy, FRUIT_CLASS* ostatni, unsigned int wysokosc, unsigned int dlugosc) {
		parent = rodzic;
		prev = poprzednia;
		next = nastepna;
		first = pierwszy;
		last = ostatni;
		height = wysokosc;
		length = dlugosc;
	}

	BRANCH_CLASS(const BRANCH_CLASS& origin) {
		prev = NULL;
		next = NULL;
		length = origin.length;
		height = origin.height;
		FRUIT_CLASS* zrodlo = origin.first;
		if ( zrodlo == NULL ) {
			last = NULL;
			first = NULL;
			return;
		}
		FRUIT_CLASS* ostatniododany = new FRUIT_CLASS(*zrodlo);
		(*ostatniododany).setparent(this);
		first = ostatniododany;
		while ( zrodlo->getnext() != NULL ) {
			zrodlo = zrodlo->getnext();
			FRUIT_CLASS* nowyowoc = new FRUIT_CLASS(*zrodlo);
			nowyowoc->setparent(this);
			ostatniododany->setnext(nowyowoc);
			ostatniododany = nowyowoc;
		}
		last = ostatniododany;
	}

	~BRANCH_CLASS() {
		FRUIT_CLASS* fruit = first;
		FRUIT_CLASS* pom;
		while ( fruit != NULL ) {
			pom = fruit->getnext();
			delete fruit;
			fruit = pom;
		}
	}

	void setFirst(FRUIT_CLASS* arg) {
		first = arg;
	}

	void setLast(FRUIT_CLASS* arg) {
		last = arg;
	}

	void setnext( BRANCH_CLASS* arg ) {
		next = arg;
	}

	void setprev( BRANCH_CLASS* arg ) {
		prev = arg;
	}

	void setHeight(unsigned int arg) {
		height = arg;
	}

	void setLength(unsigned int arg) {
		length = arg;
	}

	void setparent(WOOD_CLASS* arg) {
		parent = arg;
	}

	WOOD_CLASS* getparent() {
		return parent;
	}

	FRUIT_CLASS* getFirst() {
		return first;
	}

	FRUIT_CLASS* getLast() {
		return last;
	}

	BRANCH_CLASS* getnext() {
		return next;
	}
	
	BRANCH_CLASS* getprev() {
		return prev;
	}

	unsigned int getHeight() {
		return height;
	}

	unsigned int getLength() {
		return length;
	}

	FRUIT_CLASS* getFruitPointer(unsigned int arg) {
		FRUIT_CLASS* iterator = first;
		while ( iterator != NULL ) {
			if ( iterator->getLength() == arg ) return iterator;
			iterator = iterator->getnext();
		}
		return NULL;
	}

	WOOD_CLASS* getWoodPointer() {
		return parent;
	}

	unsigned int getWeightsTotal() {
		unsigned int sum = 0;
		FRUIT_CLASS* iterator = first;
		while ( iterator != NULL ) {
			sum += iterator->getWeight();
			iterator = iterator->getnext();
		}
		return sum;
	}

	unsigned int getFruitsTotal() {
		unsigned int sum = 0;
		FRUIT_CLASS* iterator = first;
		while ( iterator != NULL ) {
			iterator = iterator->getnext();
			sum++;
		}
		return sum;
	}

	void growthBranch() {
		FRUIT_CLASS* iterator = first;
		while ( iterator != NULL ) {
			iterator->growthFruit();
			iterator = iterator->getnext();
		}
		length += 1;
		if ( length%2 == 0 ) {
			if (first != NULL) {
				FRUIT_CLASS* nowy = new FRUIT_CLASS(this, last, NULL, 0, length );
				last->setnext(nowy);
				last = nowy;
			}
			else {
				FRUIT_CLASS* nowy = new FRUIT_CLASS(this, NULL, NULL, 0, length );
				first = nowy;
				last = first;
			}
		}
	}

	void fadeBranch() {
		if ( length != 0 ) {
			length-=1;
			if ( length != 0 ) { 
				FRUIT_CLASS* iterator = first;
				while ( iterator != NULL ) {
					iterator->fadeFruit();
					iterator = iterator->getnext();
				}
				if ( last->getLength() > length ) {
					if ( last == first ) {
						delete last;
						last = NULL;
						first = NULL;
					}
					else {
						FRUIT_CLASS* pom = last->getprev();
						pom->setnext(NULL);
						delete last;
						last = pom;
					}
				}
			}
		}
	}

	void harvestBranch( unsigned int arg ) {
		FRUIT_CLASS* iterator = first;
		while ( iterator != NULL ) {
			if ( iterator->getWeight() >= arg ) iterator->pluckFruit();
			iterator = iterator->getnext();
		}
	}

	void cutBranch( unsigned int arg ) {
		length = arg;
		FRUIT_CLASS* iterator = first;
		while ( iterator != NULL ) {
			if ( iterator->getLength() > length ) {
				if ( iterator->getprev() == NULL && iterator->getnext() == NULL ) {
					first = NULL;
					last = NULL;
					delete iterator;
				}
				else if ( iterator->getprev() == NULL ){
					FRUIT_CLASS* pom;
					while ( iterator != NULL ) {
						pom = iterator->getnext();
						delete iterator;
						iterator = pom;
					}	
					first = NULL;
					last = NULL;
				}
				else if ( iterator->getnext() == NULL ) {
					last = iterator->getprev();
					last->setnext(NULL);
					delete iterator;
				}
				else {
					iterator->getprev()->setnext(NULL);
					last = iterator->getprev();
					FRUIT_CLASS* pom;
					while ( iterator != NULL ) {
						pom = iterator->getnext();
						delete iterator;
						iterator = pom;
					}
				}
				break;
			}
			iterator = iterator->getnext();
		}
	}
};


class WOOD_CLASS {
	private:
	GARDEN_CLASS *parent;
	BRANCH_CLASS *first;
	BRANCH_CLASS *last;
	WOOD_CLASS *next;
	WOOD_CLASS *prev;
	unsigned int number;
	unsigned int height;

	public:

	WOOD_CLASS() {
		parent = NULL;
		first= NULL;
		last = NULL;
		next = NULL;
		prev = NULL;
		number = 0;
		height = 0;
	}

	WOOD_CLASS(GARDEN_CLASS* rodzic, BRANCH_CLASS* pierwszy, BRANCH_CLASS* ostatni, WOOD_CLASS* nastepny, WOOD_CLASS* poprzedni , unsigned int numer, unsigned int wysokosc) {
		parent = rodzic;
		first = pierwszy;
		last = ostatni;
		next = nastepny;
		prev = poprzedni;
		number = numer;
		height = wysokosc;
	}

	WOOD_CLASS( const WOOD_CLASS& origin ) {
		height = origin.height;
		prev = NULL;
		next = NULL;

		if ( origin.first == NULL ) {
			first = NULL;
			last = NULL;
		}
		else {
			BRANCH_CLASS* zrodlo = origin.first;
			BRANCH_CLASS* ostatniododana = new BRANCH_CLASS(*zrodlo);
			ostatniododana->setparent(this);
			first = ostatniododana;
			while ( zrodlo->getnext() != NULL ) {
				zrodlo = zrodlo->getnext();
				BRANCH_CLASS* nowagalaz = new BRANCH_CLASS(*zrodlo);
				nowagalaz->setparent(this);
				ostatniododana->setnext(nowagalaz);
				nowagalaz->setprev(ostatniododana);
				ostatniododana = nowagalaz;	
			}
			last = ostatniododana;
		}
	}
	~WOOD_CLASS() {
		BRANCH_CLASS* iterator = first;
		BRANCH_CLASS* pom;
		while ( iterator != NULL ) {
			pom = iterator->getnext();
			delete iterator;
			iterator = pom;
		}
	}

	void setparent( GARDEN_CLASS* arg ) {
		parent = arg;
	}

	void setnext( WOOD_CLASS* arg ) {
		next = arg;
	}

	void setprev( WOOD_CLASS* arg ) {
		prev = arg;
	}

	void setNumber(unsigned int arg) {
		number = arg;
	}

	void setfirst(BRANCH_CLASS* arg) {
		first = arg;
	}

	void setlast(BRANCH_CLASS* arg) {
		last = arg;
	}


	unsigned int getBranchesTotal() {
		BRANCH_CLASS* iterator = first;
		unsigned int sum = 0;
		while ( iterator != NULL ) {
			iterator = iterator->getnext();
			sum++;
		}
		return sum;
	}

	unsigned int getFruitsTotal() {
		unsigned int sum = 0;
		BRANCH_CLASS* iterator = first;
		while( iterator != NULL ) {
			sum += iterator->getFruitsTotal();
			iterator = iterator->getnext();
		}
		return sum;
	}

	unsigned int getWeightsTotal() {
		unsigned int sum = 0;
		BRANCH_CLASS* iterator = first;
		while( iterator != NULL ) {
			sum += iterator->getWeightsTotal();
			iterator = iterator->getnext();
		}
		return sum;
	}
	WOOD_CLASS* getnext() {
		return next;
	}

	WOOD_CLASS* getprev() {
		return prev;
	}

	unsigned int getNumber() {
		return number;
	}

	unsigned int getHeight() {
		return height;
	}

	BRANCH_CLASS* getfirst() {
		return first;
	}

	BRANCH_CLASS* getlast() {
		return last;
	}


	void growthWood() {
		BRANCH_CLASS* iterator = first;
		while ( iterator != NULL ) {
			iterator->growthBranch();
			iterator = iterator->getnext();
		}
		height++;
		if ( height%3 == 0 ) {
			BRANCH_CLASS* nowa = new BRANCH_CLASS(this, last, NULL, NULL, NULL, height, 0);
			if ( first == NULL ) first = nowa;
			else last->setnext(nowa);
			last = nowa;
		}
	}

	void fadeWood() {
		if ( height != 0 ) {
			height--;
			if ( height >= 2 ) {
				BRANCH_CLASS* iterator = first;
				while ( iterator != NULL ) {
					iterator->fadeBranch();
					iterator = iterator->getnext();
				}
				if ( last->getHeight() > height ) {
					if ( last == first ) {
						delete last;
						last = NULL;
						first = NULL;
					}
					else {
						BRANCH_CLASS* nowaostatnia = last->getprev();
						delete last;
						last = nowaostatnia;
						last->setnext(NULL);
					}
				}
			}
		}
	}

	void harvestWood( unsigned int arg ) {
		BRANCH_CLASS* iterator = first;
		while ( iterator != NULL ) {
			iterator->harvestBranch(arg);
			iterator = iterator->getnext();
		}
	}

	void cutWood( unsigned int arg ) {
		height = arg;

		BRANCH_CLASS* iterator = first;
		while ( iterator != NULL ) {
			if ( iterator->getHeight() > height ) {

				if ( iterator->getnext() == NULL && iterator->getprev() == NULL ) {
					last = NULL;
					first = NULL;
					delete iterator;
				}
				else if (iterator->getnext() == NULL ) {
					last = iterator->getprev();
					last->setnext(NULL);
					delete iterator;
				}
				else if ( iterator->getprev() == NULL ) {
					first = NULL;
					last = NULL;
					BRANCH_CLASS* pom;
					while ( iterator != NULL ) {
						pom = iterator->getnext();
						delete iterator;
						iterator = pom;
					}
				}
				else {
					iterator->getprev()->setnext(NULL);
					last = iterator->getprev();
					BRANCH_CLASS* pom;
					while ( iterator != NULL ) {
						pom = iterator->getnext();
						delete iterator;
						iterator = pom;
					}
				}
				break;
			}
			iterator = iterator->getnext();
		}
	}

	void cloneBranch(BRANCH_CLASS* origin) {
		if ( origin == NULL ) return;
		BRANCH_CLASS* iterator = first;
		while ( iterator != NULL ) {
			if ( iterator->getLength() == 0 ) {
				BRANCH_CLASS* nowagalaz = new BRANCH_CLASS(*origin);
				BRANCH_CLASS* poprzednik = iterator->getprev();
				BRANCH_CLASS* nastepnik = iterator->getnext();
				nowagalaz->setparent(this);
				nowagalaz->setHeight(iterator->getHeight());
				nowagalaz->setprev(poprzednik);
				nowagalaz->setnext(nastepnik);
				if ( poprzednik != NULL ) poprzednik->setnext(nowagalaz);
				else first = nowagalaz;
				if ( nastepnik != NULL ) nastepnik->setprev(nowagalaz);
				else last = nowagalaz;
				delete iterator;
				break;
			}
			iterator = iterator->getnext();
		}
	}
	
	GARDEN_CLASS* getGardenPointer() {
		return parent;
	}

	BRANCH_CLASS* getBranchPointer(unsigned int arg) {
		BRANCH_CLASS* iterator = first;
		while (iterator != NULL ) {
			if ( iterator->getHeight() == arg ) return iterator;
			iterator = iterator->getnext();
		}
		return NULL;
	}
};

class GARDEN_CLASS {
	private:
	WOOD_CLASS *first;
	WOOD_CLASS *last;
	unsigned int quantity;
	unsigned int maxinlist;
	public:

	GARDEN_CLASS() {
		first = NULL;
		last = NULL;
		quantity = 0;
		maxinlist = 0;
	}
	~GARDEN_CLASS() {
		WOOD_CLASS* iterator = first;
		WOOD_CLASS* pom;
		while ( iterator != NULL ) {
			pom = iterator->getnext();
			delete iterator;
			iterator = pom;
		}
	}

	unsigned int getWoodsTotal() {
		return quantity;
	}

	unsigned int getBranchesTotal() {
		unsigned int sum = 0;
		WOOD_CLASS* iterator = first;
		while ( iterator != NULL ) {
			sum += iterator->getBranchesTotal();
			iterator = iterator->getnext();
		}
		return sum;
	}

	unsigned int getFruitsTotal() {
		unsigned int sum = 0;
		WOOD_CLASS* iterator = first;
		while ( iterator != NULL ) {
			sum += iterator->getFruitsTotal();
			iterator = iterator->getnext();
		}
		return sum;
	}

	unsigned int getWeightsTotal() {
		unsigned int sum = 0;
		WOOD_CLASS* iterator = first;
		while ( iterator != NULL ) {
			sum += iterator->getWeightsTotal();
			iterator = iterator->getnext();
		}
		return sum;
	}

	void plantWood() {

		if ( quantity == 0 ) {
			WOOD_CLASS* nowe = new WOOD_CLASS(this, NULL, NULL, NULL, NULL, 0, 0);
			last = nowe;
			first = nowe;
			maxinlist = 0;
		}
		else if ( maxinlist + 1 == quantity ) {
			WOOD_CLASS* nowe = new WOOD_CLASS(this, NULL, NULL, NULL, last, 1+maxinlist, 0 );
			last->setnext(nowe);
			last = nowe;
			maxinlist = last->getNumber();
		}
		else if ( first->getNumber() != 0 ) {
			WOOD_CLASS* nowe = new WOOD_CLASS(this, NULL, NULL, first, NULL, 0, 0);
			first->setprev(nowe);
			first = nowe;
		}
		else {
			WOOD_CLASS* pom = first;
			while ( pom != NULL ) {
				if ( pom->getnext() != NULL && pom->getNumber() + 1 < pom->getnext()->getNumber() ) {
					WOOD_CLASS* nastepnik = pom->getnext();
					WOOD_CLASS* nowe = new WOOD_CLASS(this, NULL, NULL, nastepnik, pom, 1+pom->getNumber(), 0);
					pom->setnext(nowe);
					nastepnik->setprev(nowe);
					break;
				}
				pom = pom->getnext();
			}
		}
		quantity++;
	}

	void extractWood(unsigned int arg) {
		if ( quantity != 0 ) { 
			if ( quantity == 1 && first->getNumber() != arg ) return;
			if ( quantity == 1 && first->getNumber() == arg ) {
				delete first;
				first = NULL;
				last = NULL;
				maxinlist = 0;
				quantity--;
			}
			else if ( first->getNumber() == arg ) {
				WOOD_CLASS* nowyfirst = first->getnext();
				delete first;
				first = nowyfirst;
				first->setprev(NULL);
				quantity--;
			}
			else if ( last->getNumber() == arg ) {
				WOOD_CLASS* nowylast = last->getprev();
				delete last;
				last = nowylast;
				maxinlist = (*last).getNumber();
				quantity--;
			}
			else {
				WOOD_CLASS* iterator = first;
				while ( iterator != NULL ) {
					if ( iterator->getNumber() == arg ) {
						WOOD_CLASS* poprzednik = iterator->getprev();
						WOOD_CLASS* nastepnik = iterator->getnext();
						if (poprzednik != NULL) poprzednik->setnext(nastepnik);
						else first = nastepnik;
						if (nastepnik != NULL) nastepnik->setprev(poprzednik);
						else last = poprzednik;
						delete iterator;
						quantity--;
						break;
					}
					iterator = iterator->getnext();
				}
			}
			if (last!= NULL) maxinlist = last->getNumber();
			else maxinlist = 0;
		}
	}

	void growthGarden() {
		WOOD_CLASS* iterator = first;
		while ( iterator != NULL ) {
			iterator->growthWood();
			iterator = iterator->getnext();
		}
	}

	void fadeGarden() {
		WOOD_CLASS* iterator = first;
		while ( iterator != NULL ) {
			iterator->fadeWood();
			iterator = iterator->getnext();
		}
	}

	void harvestGarden( unsigned int arg ) {
		WOOD_CLASS* iterator = first;
		while ( iterator != NULL ) {
			iterator->harvestWood(arg);
			iterator = iterator->getnext();
		}
	}

	void cloneWood(unsigned int arg) {
		WOOD_CLASS* iterator = first;
		while ( iterator != NULL ) {
			if ( iterator->getNumber() == arg ) {
				WOOD_CLASS* nowe = new WOOD_CLASS(*iterator);
				nowe->setparent(this);
				if ( maxinlist + 1 == quantity ) {
					nowe->setNumber(maxinlist+1);
					nowe->setnext(NULL);
					nowe->setprev(last);
					(*last).setnext(nowe);
					last = nowe;
					maxinlist += 1;
					quantity++;
				}
				else if ( first->getNumber() != 0 ) {
					nowe->setnext(first);
					first->setprev(nowe);
					nowe->setNumber(0);
					nowe->setprev(NULL);
					first = nowe;
					quantity++;
				}
				else {
					WOOD_CLASS* iterator = first;
					while ( iterator != NULL ) {
						if (  iterator->getnext() != NULL && 1+iterator->getNumber() < iterator->getnext()->getNumber() ) {
							WOOD_CLASS* nastepnik = iterator->getnext();
							nowe->setnext(nastepnik);
							nowe->setprev(iterator);
							nowe->setNumber(1+iterator->getNumber());
							nastepnik->setprev(nowe);
							iterator->setnext(nowe);
							break;
						}
						iterator = iterator->getnext();
					}
				}
				maxinlist = last->getNumber();
				break;
			}
			iterator = iterator->getnext();
		}


	}

	WOOD_CLASS* getWoodPointer(unsigned int arg) {
		WOOD_CLASS* iterator = first;
		while ( iterator != NULL ) {
			if ( iterator->getNumber() == arg ) return iterator;
			iterator = iterator->getnext();
		}
		return NULL;
	}
};


