//Magdalena Lipka//
#include <iostream>
#include <string>
#include <cstdarg>
using namespace std;


void rever (string origin, string &dest, int iterator) {
	if (iterator >= 0) {
		dest += origin[iterator];
		rever (origin, dest, iterator-1);
	}
}
string reverse(string napis) {
	string nowy = "";
	int licznik = 0;

	rever (napis, nowy, napis.length()-1);
	
	return nowy;
}

string add1 (string el1, string el2, string &wynik, int &carryover, int iterator, int condition) {

	if ( iterator < condition ) {

		int sum = ( el1[iterator] - 48 ) + ( el2[iterator] - 48 ) + carryover;

		wynik += (char)  ( sum%10 + 48 );
		carryover = sum/10;
		
		return add1 ( el1, el2, wynik, carryover, iterator+1, condition );

	}

	else return wynik; 

}
string add2 (string elem, string &wynik, int &carryover, int iterator, int condition) {

	if ( iterator < condition ) {

		int sum = ( elem[iterator] - 48 ) + carryover;

		wynik += (char) ( sum%10 + 48 );
		carryover = sum/10;
		
		return add2 ( elem, wynik, carryover, iterator+1, condition );

	}

	else return wynik; 

}
string Add (string el1, string el2) {

	int len1 = el1.length();
	int len2 = el2.length();

	if ( len1 > len2 ) {
		string pom = el1;
		el1 = el2;
		el2 = pom;
		int p = len1;
		len1 = len2;
		len2 = p;
	}
	
	string des = "";

	el1 = reverse(el1);
	el2 = reverse(el2);

	int carryover = 0;

	add1 ( el1, el2, des, carryover, 0, len1 );
	add2 ( el2, des, carryover, len1, len2 );

	if ( carryover ) des += (char) (carryover+48);

	des = reverse ( des );

	return des;

}

bool bychar (string s1, string s2, int iterator, int condition) {

	if ( iterator < condition ) {

		if ( s1[iterator] < s2[iterator] ) return true;
		else if ( s1[iterator] > s2[iterator] ) return false;
		else return bychar(s1, s2, iterator+1, condition);

	} 
	else return false;

}
bool smaller ( string s1, string s2 ) {

	if ( s1.length() < s2.length() ) return true;
	else if ( s1.length() > s2.length() ) return false;
	else {
		return bychar(s1, s2, 0, s1.length());
	}

}

string diff1 (string el1, string el2, string &wynik, int &carryover, int iterator, int condition) {
	if ( iterator < condition ) {

		int diff = ( el1[iterator] - 48 ) - ( el2[iterator] - 48 ) - carryover;

		if ( diff < 0 ) {
			diff += 10;
			carryover = 1;
		}
		else carryover = 0;

		wynik += (char) ( diff + 48 );
		
		return diff1 ( el1, el2, wynik, carryover, iterator+1, condition );
	}
	else return wynik; 
}
string diff2 (string elem, string &wynik, int &carryover, int iterator, int condition) {
	if ( iterator < condition ) {

		int diff = ( elem[iterator] - 48 ) - carryover;

		if ( diff < 0 ) {
			diff += 10;
			carryover = 1;
		}
		else carryover = 0;

		wynik += (char) ( diff + 48 );
		
		return diff2 ( elem, wynik, carryover, iterator+1, condition );
	}
	else return wynik; 
}
string Diff (string el1, string el2) {

	if ( smaller(el1, el2) ) {
		string pom = el1;
		el1 = el2;
		el2 = pom;
	}

	int len1 = el1.length();
	int len2 = el2.length();

	string des = "";

	el1 = reverse(el1);
	el2 = reverse(el2);

	int carryover = 0;

	diff1 ( el1, el2, des, carryover, 0, len2 );
	diff2 ( el1, des, carryover, len2, len1 );

	if ( carryover ) des += (char) ( carryover + 48 );

	des = reverse ( des );

	return des;


}

string deletezeros(string napis) {
	if ( napis[0] == '0' ) {
		napis.erase(0,1);
		return deletezeros(napis);
	}
	return napis;
}

string AddMany (const string* argv, string &wynik, int iterator, int condition) {
	if ( iterator < condition ) {
		if ( wynik[0] != '-' && argv[iterator][0] != '-' )  {
			string copy = argv[iterator];
			if ( copy[0] == '+' ) copy.erase(0, 1);
			wynik = Add(wynik, copy);
		}
		else if (wynik[0] == '-' && argv[iterator][0] == '-') {
			wynik.erase(0, 1);
			string copy = argv[iterator];
			copy.erase(0, 1);
			wynik = '-' + Add(wynik, copy);

		}
		else if ( wynik[0]=='-' ) {
			string copy = argv[iterator];
			if ( copy[0] == '+' ) copy.erase(0, 1);
			wynik.erase(0, 1);
			if ( smaller ( wynik, copy ) ) {
				wynik = Diff(wynik, copy);
			}
			else {
				wynik = '-' + Diff(wynik, copy);
			}
		}
		else {
			//arcgv[0]=='-'//
			string copy = argv[iterator];
			copy.erase(0, 1);
			if ( smaller ( wynik, copy ) ) {
				wynik = '-' + Diff(wynik, copy);
			}
			else {
				wynik = Diff(wynik, copy );
			}
		}
		if ( wynik[0] == '-' ) {
			wynik.erase(0, 1);
			wynik = deletezeros(wynik);
			wynik = '-' + wynik;
		}
		else wynik = deletezeros(wynik);
		if ( wynik == "" || wynik == "-0" || wynik == "-" ) wynik = "0";
		return AddMany(argv, wynik, iterator+1, condition);
	}
	return wynik;
}
string Sum (int argc, const string* argv) {

	string wynik = "0";
	return AddMany( argv, wynik, 0, argc );

}

string AddVa(va_list lista, string &wynik, int iterator, int condition) {
	if ( iterator < condition ) {

		string copy = va_arg(lista, char*);
		if ( wynik[0] != '-' && copy[0] != '-' )  {
			if ( copy[0] == '+' ) copy.erase(0, 1);
			wynik = Add(wynik, copy);
		}
		else if (wynik[0] == '-' && copy[0] == '-') {
			wynik.erase(0, 1);
			copy.erase(0, 1);
			wynik = '-' + Add(wynik, copy);

		}
		else if ( wynik[0]=='-' ) {
			if ( copy[0] == '+' ) copy.erase(0, 1);
			wynik.erase(0, 1);
			if ( smaller ( wynik, copy ) ) {
				wynik = Diff(wynik, copy);
			}
			else {
				wynik = '-' + Diff(wynik, copy);
			}
		}
		else {
			//arcgv[0]=='-'//
			copy.erase(0, 1);
			if ( smaller ( wynik, copy ) ) {
				wynik = '-' + Diff(wynik, copy);
			}
			else {
				wynik = Diff(wynik, copy);
			}
		}
		if ( wynik[0] == '-' ) {
			wynik.erase(0, 1);
			wynik = deletezeros(wynik);
			wynik = '-' + wynik;
		}
		else wynik = deletezeros(wynik);
		if ( wynik == "" || wynik == "-0" || wynik == "-" ) wynik = "0";
		return AddVa(lista, wynik, iterator+1, condition);
	} 
	else return wynik;
}
string Sum ( int argc, ... ) {
	string wynik = "0";
	va_list lista;
	va_start(lista, argc);
	return AddVa(lista, wynik, 0, argc );
}

void Sum ( string* wynik, int liczba, const string* napis ) {
	*wynik = Sum ( liczba, napis );
}
void Sum ( string* wynik, int liczba, ... ) {
	string des = "0";
	va_list lista;
	va_start(lista, liczba);
	*wynik = AddVa (lista, des, 0, liczba);
}
void Sum ( string &wynik, int liczba, const string* napis ) {
	wynik = Sum ( liczba, napis );
}
void Sum ( string &wynik, int liczba, ... ) {
	string des = "0";
	va_list lista;
	va_start(lista, liczba);
	wynik = AddVa (lista, des, 0, liczba);
}

//Mnozenia......................................................................//
//..............................................................................//

string addzeros(string zera, int iterator, int condition) {
	if ( iterator < condition ) {
		zera += "0";
		return addzeros(zera, iterator+1, condition);
	}
	else return zera;
}

string multchar (string wynik, int &carryover, string liczba, char mnoznik, int iterator, int condition) {
	if ( iterator < condition ) {
		int prod = ( liczba[iterator] - 48 )*( mnoznik - 48 ) + carryover;

		wynik += (char)  ( prod%10 + 48 );
		carryover = prod/10;
		
		return multchar ( wynik, carryover, liczba, mnoznik, iterator+1, condition );
	}
	else return wynik;
}
string mult2(string &wynik, int &carryover, string liczba1, string liczba2, int iterator, int condition ) {
	if ( iterator < condition ) {

		string pomwynik = "";
		int pomcarryover = 0;
		pomwynik = multchar ( pomwynik, pomcarryover, liczba1, liczba2[iterator], 0, liczba1.length() );

		if ( pomcarryover ) pomwynik += (char) ( pomcarryover + 48 );

		string pom1 = reverse ( wynik );
		string pom2 = reverse ( pomwynik ) + addzeros("", 0, iterator);

		wynik = reverse ( Add ( pom1, pom2 ) );

		return  mult2(wynik, carryover, liczba1, liczba2, iterator+1, condition);

	}
	else return wynik;
}
string MultTwo (string liczba1, string liczba2) {
	string des = "";

	int len1 = liczba1.length();
	int len2 = liczba2.length();
	if ( len1 == 0 || len2 == 0 ) return "0";

	liczba1 = reverse(liczba1);
	liczba2 = reverse(liczba2);

	int carryover = 0;

	des = mult2(des, carryover, liczba1, liczba2, 0, len2);
	if ( carryover ) des += (char) ( carryover + 48 );
	des = reverse(des);

	return des;
}

string MultMany (const string* argv, string &wynik, int iterator, int condition) {
	if ( iterator < condition ) {
		if ( wynik[0] != '-' && argv[iterator][0] != '-' )  {
			string copy = argv[iterator];
			if ( copy[0] == '+' ) copy.erase(0, 1);
			wynik = MultTwo(wynik, copy);
		}
		else if (wynik[0] == '-' && argv[iterator][0] == '-') {
			wynik.erase(0, 1);
			string copy = argv[iterator];
			copy.erase(0, 1);
			wynik = MultTwo(wynik, copy);

		}
		else if ( wynik[0]=='-' ) {
			string copy = argv[iterator];
			if ( copy[0] == '+' ) copy.erase(0, 1);
			wynik.erase(0, 1);
			wynik = '-' + MultTwo(wynik, copy);
			}
		else {
			//arcgv[0]=='-'//
			string copy = argv[iterator];
			copy.erase(0, 1);
			wynik = '-' + MultTwo(wynik, copy);
		}
		if ( wynik[0] == '-' ) {
			wynik.erase(0, 1);
			wynik = deletezeros(wynik);
			wynik = '-' + wynik;
		}
		else wynik = deletezeros(wynik);
		if ( wynik == "" || wynik == "-0" || wynik == "-" ) wynik = "0";
		return MultMany(argv, wynik, iterator+1, condition);
	}
	return wynik;
}
string Mult ( int argc, const string *argv ) {
	
	string wynik = "0";
	return MultMany( argv, wynik, 0, argc );

}

string MultVa (va_list lista, string &wynik, int iterator, int condition) {
	string copy = va_arg(lista, char*);
	if ( iterator < condition ) {
		if ( wynik[0] != '-' && copy[0] != '-' )  {
			if ( copy[0] == '+' ) copy.erase(0, 1);
			wynik = MultTwo(wynik, copy);
		}
		else if (wynik[0] == '-' && copy[0] == '-') {
			wynik.erase(0, 1);
			copy.erase(0, 1);
			wynik = MultTwo(wynik, copy);

		}
		else if ( wynik[0]=='-' ) {
			if ( copy[0] == '+' ) copy.erase(0, 1);
			wynik.erase(0, 1);
			wynik = '-' + MultTwo(wynik, copy);
			}
		else {
			//arcgv[0]=='-'//
			copy.erase(0, 1);
			wynik = '-' + MultTwo(wynik, copy);
		}
		if ( wynik[0] == '-' ) {
			wynik.erase(0, 1);
			wynik = deletezeros(wynik);
			wynik = '-' + wynik;
		}
		else wynik = deletezeros(wynik);
		if ( wynik == "" || wynik == "-0" || wynik == "-" ) wynik = "0";
		return MultVa(lista, wynik, iterator+1, condition);
	}
	return wynik;
}
string Mult ( int argc, ... ) {
	string wynik = "0";
	va_list lista;
	va_start(lista, argc);
	return MultVa(lista, wynik, 0, argc );
}


void Mult ( string* wynik, int liczba, const string* napis ) {
	*wynik = Mult ( liczba, napis );
}
void Mult ( string* wynik, int liczba, ... ) {
	string des = "0";
	va_list lista;
	va_start(lista, liczba);
	*wynik = MultVa (lista, des, 0, liczba);
}
void Mult ( string &wynik, int liczba, const string* napis ) {
	wynik = Mult ( liczba, napis );
}
void Mult ( string &wynik, int liczba, ... ) {
	string des = "0";
	va_list lista;
	va_start(lista, liczba);
	wynik = MultVa (lista, des, 0, liczba);
}





string Operation ( string (*funkcja) (int, const string*), int liczba, const string* napis ) {

	return funkcja(liczba, napis);

}
string Operation ( string (*funkcja) (int, const string*), int liczba, ... ) {
	
	va_list lista;
	va_start(lista, liczba);
	string des = "0";
	//return funkcja(va_lista, );

}
void Operation ( string *wynik, string (*funkcja) (int, const string*), int liczba, const string* napis ) {
	
}
void Operation ( string *wynik, string (*funkcja) (int, const string*), int liczba, ... ) {
	
}
void Operation ( string &wynik, string (*funkcja) (int, const string*), int liczba, const string* napis ) {
	
}
void Operation ( string &wynik, string (*funkcja) (int, const string*), int liczba, ... ) {
	
}

int main () {


	string napis[] = {"1", "2", "3", "4", "5"};

	string wynik = "1";

	//cout << multchar(wynik, carry, a, c, 0, a.length()) << endl;
	

	cout << MultMany ( napis, wynik, 0, 5 ) << endl;
	//cout << "carry: " << carry << endl;
	

	return 0;

}
