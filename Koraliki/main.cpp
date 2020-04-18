//Magdalena Lipka//
#include <iostream>
using namespace std;

struct Con {
	int with;
	char With1;
	char With2;
	char With3;
	Con *next;
};
typedef struct Con *con;

struct Koralik {
	int id;
	Koralik *next;
	Con *first_outgoing;
	Con *first_incoming;
};
typedef struct Koralik *koralik;


struct Sznur {
	char ID1;
	char ID2;
	char ID3;
	Sznur *next;
	Koralik *koral;
};
typedef struct Sznur *sznur;

sznur HEAD = NULL;

Sznur* findsznur(char ID1, char ID2, char ID3) {
	sznur p = HEAD;
	while ( p != NULL ) {
		if ( (*p).ID1 == ID1 && (*p).ID2 == ID2 && (*p).ID3 == ID3 ) return p;
		p = (*p).next;
	}
	return NULL;
}

Koralik* findkoralik(int id, char ID1, char ID2, char ID3) {
	koralik p = (*findsznur(ID1, ID2, ID3)).koral;
	while ( p != NULL ) {
		if ( (*p).id == id ) return p;
		p = (*p).next;
	}
	return NULL;
}

Sznur* findLASTsznur() {
	sznur p = HEAD;
	while (p != NULL) {
		if((*p).next == NULL) return p;
		p = (*p).next;
	}
	return NULL;
}

Koralik* findLASTkoralik(char ID1, char ID2, char ID3) {
	sznur sz = findsznur(ID1, ID2, ID3);
	koralik p = (*sz).koral;
	while ( p != NULL ) {
		if((*p).next == NULL) return p;	
		p = (*p).next;
	}
	return p; 
}

void Add_Sznur_S (char ID1, char ID2, char ID3) {
	if(findsznur(ID1, ID2, ID3) == NULL) {
		sznur p;
		p = new Sznur;
		(*p).ID1 = ID1;
		(*p).ID2 = ID2;
		(*p).ID3 = ID3;
		(*p).koral = NULL;

		if (HEAD == NULL) {
			HEAD = p;
			(*p).next = NULL;
		}
		else {
			if ( ( (*HEAD).ID1 > (*p).ID1 ) || ( (*HEAD).ID1 == (*p).ID1 && (*HEAD).	ID2 > (*p).ID2 ) || ( (*HEAD).ID1 == (*p).ID1 && (*HEAD).ID2 == (*p).ID2 && (*HEAD).ID3 > (*p).ID3 ) ) {
				(*p).next = HEAD;
				HEAD = p;
			}
			else {
				sznur temp = HEAD;
				while ( (*temp).next != NULL ) {

					if ( ( (*(*temp).next).ID1 > (*p).ID1 ) || ( (*(*temp).next).ID1 == 	(*p).ID1 && (*(*temp).next).ID2 > (*p).ID2 ) || ( (*(*temp).next).	ID1 == (*p).ID1 && (*(*temp).next).ID2 == (*p).ID2 && (*(*temp).	next).ID3 == (*p).ID3 ) ) {
						(*p).next = (*temp).next;
						(*temp).next = p;
						break;
					}

					temp = (*temp).next;
				}
				if ( (*temp).next == NULL ) {
						(*p).next = (*temp).next;
						(*temp).next = p;            
				}
			}
		}
	}
}

void Add_Koralik_B ( int id, char ID1, char ID2, char ID3 ) {
	if ( findsznur(ID1, ID2, ID3) != NULL && findkoralik(id, ID1, ID2, ID3) == NULL ) {
		koralik p = new Koralik;
		(*p).first_incoming = NULL;
		(*p).first_outgoing = NULL;
		(*p).id = id;
		sznur sznurek = findsznur(ID1, ID2, ID3);

		if (sznurek != NULL) {
			if ( (*sznurek).koral == NULL ) {
				(*sznurek).koral = p;
				(*p).next = NULL; 
			}
			else {
				if ( (*(*sznurek).koral).id > (*p).id ) {
					 (*p).next =  (*sznurek).koral;
					 (*sznurek).koral = p;  
				}
				else {
					koralik temp = (*sznurek).koral;
					while ( (*temp).next != NULL ) {

						if ( (*(*temp).next).id > (*p).id ) {
							(*p).next = (*temp).next;
							(*temp).next = p;
							break;
						}

						temp = (*temp).next;
					}
					if ( (*temp).next == NULL ) {
							(*p).next = (*temp).next;
							(*temp).next = p;            
					}

				}
			}
		}
	}
}

void Add_Connection_L ( int id_sender, char Sender1, char Sender2, char Sender3, int id_receiver, char Receiver1, char Receiver2, char Receiver3 ) {
	
	if ( findsznur(Sender1, Sender2, Sender3) != NULL && findsznur(Receiver1, Receiver2, Receiver3) != NULL && findkoralik(id_sender, Sender1, Sender2, Sender3) != NULL && findkoralik(id_receiver, Receiver1, Receiver2, Receiver3) != NULL ) {

		koralik sender = findkoralik(id_sender, Sender1, Sender2, Sender3);
		koralik receiver = findkoralik(id_receiver, Receiver1, Receiver2, Receiver3);

		con sender_module = new Con;
		con receiver_module = new Con;
		(*sender_module).with = id_receiver;
		(*sender_module).With1 = Receiver1;
		(*sender_module).With2 = Receiver2;
		(*sender_module).With3 = Receiver3;
		(*receiver_module).with = id_sender;
		(*receiver_module).With1 = Sender1;
		(*receiver_module).With2 = Sender2;
		(*receiver_module).With3 = Sender3;

		if ( (*sender).first_outgoing == NULL ) {
			(*sender).first_outgoing = sender_module;
			(*sender_module).next = NULL;
		}
		else {
			if ( ( (*(*sender).first_outgoing).With1 > Receiver1 ) || ( (*(*sender).first_outgoing).With1 == Receiver1 && (*(*sender).first_outgoing).With2 > Receiver2 ) || ( (*(*sender).first_outgoing).With1 == Receiver1 && (*(*sender).first_outgoing).With2 == Receiver2 && (*(*sender).first_outgoing).With3 > Receiver3 ) || ( (*(*sender).first_outgoing).With1 == Receiver1 && (*(*sender).first_outgoing).With2 == Receiver2 && (*(*sender).first_outgoing).With3 == Receiver3 && (*(*sender).first_outgoing).with > id_receiver ) ) {
				(*sender_module).next = (*sender).first_outgoing;
				(*sender).first_outgoing = sender_module;
			}
			else {
				con temp = (*sender).first_outgoing;
				while ( (*temp).next != NULL ) {
					if ( ( (*(*temp).next).With1 > Receiver1 ) || ( (*(*temp).next).With1 == Receiver1 && (*(*temp).next).With2 > Receiver2 ) || ( (*(*temp).next).With1 == Receiver1 && (*(*temp).next).With2 == Receiver2 && (*(*temp).next).With3 > Receiver3 ) || ( (*(*temp).next).With1 == Receiver1 && (*(*temp).next).With2 == Receiver2 && (*(*temp).next).With3 == Receiver3 && (*(*temp).next).with > id_receiver ) ) {
						(*sender_module).next = (*temp).next;
						(*temp).next = sender_module;
						break;
					}
					temp = (*temp).next;
				}
				if ((*temp).next == NULL) {
					(*sender_module).next = (*temp).next;
					(*temp).next = sender_module;
				}

			}

		}
		//-------------------------------------------------//
		if ( (*receiver).first_incoming == NULL ) {
			(*receiver).first_incoming = receiver_module;
			(*receiver_module).next = NULL;
			//cout << " added first receiver " << (*receiver).id << (*sender).id;
		}
		else {
			if ( ( (*(*receiver).first_incoming).With1 > Sender1 ) || ( (*(*receiver).first_incoming).With1 == Sender1 && (*(*receiver).first_incoming).With2 > Sender2 ) || ( (*(*receiver).first_incoming).With1 == Sender1 && (*(*receiver).first_incoming).With2 == Sender2 && (*(*receiver).first_incoming).With1 > Sender3 ) || ( (*(*receiver).first_incoming).With1 == Sender1 && (*(*receiver).first_incoming).With2 == Sender2 && (*(*receiver).first_incoming).With3 == Sender3 && (*(*receiver).first_incoming).with > id_sender ) ) {
				(*receiver_module).next = (*receiver).first_incoming;
				(*receiver).first_incoming = receiver_module;
				//cout << " added receiver at the beginning" << (*receiver).id << " " << (*sender).id;
			}
			else {
				con temp = (*receiver).first_incoming;
				while ((*temp).next != NULL) {
					if ( ( (*(*temp).next).With1 > Sender1 ) || ( (*(*temp).next).With1 == Sender1 && (*(*temp).next).With2 > Sender2 ) || ( (*(*temp).next).With1 == Sender1 && (*(*temp).next).With2 == Sender2 && (*(*temp).next).With3 > Sender3 ) || ( (*(*temp).next).With1 == Sender1 && (*(*temp).next).With2 == Sender2 && (*(*temp).next).With3 == Sender3 && (*(*temp).next).with > id_sender ) ) {
						(*receiver_module).next = (*temp).next;
						(*temp).next = receiver_module;
						//cout << " added receiver in the middle";
						break;
					}
					temp = (*temp).next;
				}
				if ( (*temp).next == NULL ) {
					(*receiver_module).next = (*temp).next;
					(*temp).next = receiver_module;
					//cout << " added receiver at the end";
				}
			}
		}
	}
}

void Del_Connection_U ( int sender, char Sender1, char Sender2, char Sender3, int receiver, char Receiver1, char Receiver2, char Receiver3 ) {

	if ( findsznur(Sender1, Sender2, Sender3) != NULL && findsznur(Receiver1, Receiver2, Receiver3) != NULL && findkoralik(sender, Sender1, Sender2, Sender3) != NULL && findkoralik(receiver, Receiver1, Receiver2, Receiver3) != NULL && (*findkoralik(receiver, Receiver1, Receiver2, Receiver3)).first_incoming != NULL && (*findkoralik(sender, Sender1, Sender2, Sender3)).first_outgoing != NULL) {
		con sender_module = (*findkoralik(sender, Sender1, Sender2, Sender3)).first_outgoing;
		con receiver_module = (*findkoralik(receiver, Receiver1, Receiver2, Receiver3)).first_incoming;

		if ( (*sender_module).with = receiver && (*sender_module).With1 == Receiver1 && (*sender_module).With2 == Receiver2 && (*sender_module).With3 == Receiver3 ) {
			//usuwanie jesli pierwszy//
			(*findkoralik(sender, Sender1, Sender2, Sender3)).first_outgoing = (*sender_module).next;
			delete(sender_module);
		}
		else {
			//usuwanie niepierwszego//
			while( (*sender_module).next != NULL ) {
				if ( (*(*sender_module).next).with == receiver && (*(*sender_module).next).With1 == Receiver1 && (*(*sender_module).next).With2 == Receiver2 && (*(*sender_module).next).With3 == Receiver3 ) {
					con temp = (*sender_module).next;
					(*sender_module).next = (*(*sender_module).next).next;
					delete(temp);
					break;
				}
				sender_module = (*sender_module).next;
			}
		}

		if ( (*receiver_module).with == sender && (*receiver_module).With1 == Sender1 && (*receiver_module).With2 == Sender2 && (*receiver_module).With3 == Sender3 ) {
			//usuwanie jesli pierwszy//
			(*findkoralik(receiver, Receiver1, Receiver2, Receiver3)).first_incoming = (*receiver_module).next;
			delete(receiver_module);
		}
		else {
			//usuwnie jesli niepierwszy//
			while ( (*receiver_module).next != NULL ) {
				if ( (*(*receiver_module).next).with == sender && (*(*receiver_module).next).With1 == Sender1 && (*(*receiver_module).next).With2 == Sender2 && (*(*receiver_module).next).With3 == Sender3 ) {
					con temp = (*receiver_module).next;
					(*receiver_module).next = (*(*receiver_module).next).next;
					delete(temp);
					break;
				}
				receiver_module = (*receiver_module).next;
			}
		}

	}
}

void Del_Koralik_D ( int id, char ID1, char ID2, char ID3 ) {
	if( findsznur(ID1, ID2, ID3) != NULL && findkoralik(id, ID1, ID2, ID3) != NULL ) {
		koralik koral = findkoralik(id, ID1, ID2, ID3);
		//usuwanie wychodzacych polaczen//
		con temp = (*koral).first_outgoing;
		while ( temp != NULL ) {

			Del_Connection_U( id, ID1, ID2, ID3, (*temp).with, (*temp).With1, (*temp).With2, (*temp).With3 );

			temp = (*temp).next;
		}
		delete((*koral).first_outgoing);
		(*koral).first_outgoing == NULL;

		//usuwanie przychodzacych polaczen//

		temp = (*koral).first_incoming;
		while ( temp != NULL ) {

			Del_Connection_U( (*temp).with, (*temp).With1, (*temp).With2, (*temp).With3, id, ID1, ID2, ID3 );

			temp = (*temp).next;
		}
		delete((*koral).first_incoming);
		(*koral).first_incoming = NULL;

		//usuwanie koralika ze sznurka//
		if ( koral == (*findsznur(ID1, ID2, ID3)).koral ) {
			(*findsznur(ID1, ID2, ID3)).koral = (*koral).next;
			delete(koral);
		}
		else {
			koralik temp = (*findsznur(ID1, ID2, ID3)).koral;
			while( (*temp).next != NULL ) {
				if ( (*(*temp).next).id == id ) {
					koralik pom = (*temp).next;
					(*temp).next = (*(*temp).next).next;
					delete((*temp).next);
					break;
				}
				temp = (*temp).next;
			}
		}
	}
}

void Move_M (int killed, char Killed1, char Killed2, char Killed3, char Born1, char Born2, char Born3) {

	Add_Koralik_B(killed, Born1, Born2, Born3);

	//skopiowanie powiazan killed do born//

	//skopiowanie polaczen wychodzacych//

	con temp = (*findkoralik(killed, Killed1, Killed2, Killed3)).first_outgoing;
	while ( temp != NULL ) {
		Add_Connection_L(killed, Born1, Born2, Born3, (*temp).with, (*temp).With1, (*temp).With2, (*temp).With3);
		temp = (*temp).next;
	}

	//skopiowanie polaczen przychodzacych//

	temp = (*findkoralik(killed, Killed1, Killed2, Killed3)).first_incoming;
	while( temp != NULL ) {
		Add_Connection_L((*temp).with, (*temp).With1, (*temp).With2, (*temp).With3, killed, Born1, Born2, Born3);
		temp = (*temp).next;
	}

	//usuniecie starego koalika//
	Del_Koralik_D(killed, Killed1, Killed2, Killed3);

}

void Del_Sznur_R ( char ID1, char ID2, char ID3 ) {
	koralik temp = NULL;
	if ( findsznur(ID1, ID2, ID3) != NULL && (*findsznur(ID1, ID2, ID3)).koral != NULL)  temp = (*findsznur(ID1, ID2, ID3)).koral;
	while ( temp != NULL ) {
		Del_Koralik_D((*temp).id, ID1, ID2, ID3);
		temp = (*temp).next;
	}

	sznur pom = findsznur(ID1, ID2, ID3);
	if( pom == HEAD && pom != NULL) {
		HEAD = (*pom).next;
		delete(pom);
	}
	else if (pom != NULL) {
		pom = HEAD;
		while ( (*pom).next != NULL ) {
			if ( (*pom).next == findsznur(ID1, ID2, ID3) ) {
				sznur tokill = (*pom).next;
				(*pom).next = (*(*pom).next).next;
				delete(tokill);
				break;
			}
			pom = (*pom).next;
		}
	}


}

void Print () {
	sznur tempSZNUR = HEAD;

	while (tempSZNUR != NULL) {

		cout << (*tempSZNUR).ID1 << (*tempSZNUR).ID2 << (*tempSZNUR).ID3 << endl;

		koralik tempKORAL = (*tempSZNUR).koral;

		while (tempKORAL != NULL) {

			//while na wiazania
			if ( (*tempKORAL).id == 0 ) cout << "000 ";
			else if((*tempKORAL).id <10) cout << "00" << (*tempKORAL).id << " ";
			else if ((*tempKORAL).id < 100) cout << "0" << (*tempKORAL).id << " ";
			else cout << (*tempKORAL).id << " ";

			con tempCON =(*tempKORAL).first_outgoing;
			while ( tempCON != NULL ) {
				cout << (*tempCON).With1 << (*tempCON).With2 << (*tempCON).With3 << " ";
				if ( (*tempCON).with == 0 ) cout << "000 ";
				else if((*tempCON).with <10) cout << "00" << (*tempCON).with << " ";
				else if ((*tempCON).with < 100) cout << "0" << (*tempCON).with << " ";
				else cout << (*tempCON).with << " ";
				tempCON = (*tempCON).next;
			}
			cout << endl;

			tempKORAL = (*tempKORAL).next;
		}

		//cout << endl;

		tempSZNUR = (*tempSZNUR).next;
	}
}

int main () {

	char TYPE;
	do {

		cin >> TYPE;
		int id1, id2;
		char ID1, ID2, ID3, IDa, IDb, IDc;
		

		switch ( TYPE ) {
			case 'S':
				cin >> ID1 >> ID2 >> ID3;
				Add_Sznur_S(ID1, ID2, ID3);
			break;
			case 'B':
				cin >> id1 >> ID1 >> ID2 >> ID3;
				Add_Koralik_B(id1, ID1, ID2, ID3);
			break;
			case 'L':
			
				cin >> id1 >> ID1 >> ID2 >> ID3 >> id2 >> IDa >> IDb >> IDc;
				Add_Connection_L(id1, ID1, ID2, ID3, id2, IDa, IDb, IDc);
			break;
			case 'U':
				cin >>  id1 >> ID1 >> ID2 >> ID3 >> id2 >> IDa >> IDb >> IDc;
				Del_Connection_U(id1, ID1, ID2, ID3, id2, IDa, IDb, IDc);
			break;
			case 'D':
				cin >> id1 >> ID1 >> ID2 >> ID3;
				Del_Koralik_D(id1, ID1, ID2, ID3);
			break;
			case 'M':
				cin >> id1 >> ID1 >> ID2 >> ID3 >> IDa >> IDb >> IDc;
				Move_M(id1, ID1, ID2, ID3, IDa, IDb, IDc);
			break;
			case 'R':
				cin >>ID1 >> ID2 >> ID3;
				Del_Sznur_R(ID1, ID2, ID3);
			break;
			case 'P':
				Print();
			break;
		}


	} while ( TYPE != 'F' );
	
	sznur temp = HEAD;
	while (temp != NULL) {
		Del_Sznur_R((*temp).ID1, (*temp).ID2, (*temp).ID3);
		temp = (*temp).next;
	}
}