#include <iostream>
#include <string>
#include <cstdarg>
using namespace std;

//BASE functions------------------------------------------------------------------//

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

//CORE functions-------------------------------------------------------------------//

string add1 (string el1, string el2, string &wynik, int &carryover, int iterator, int condition) {

	if ( iterator < condition ) {

		int sum = ( el1[iterator] - 48 ) + ( el2[iterator] - 48 ) + carryover;

		wynik += (char)  (sum%10+48);
		carryover = sum/10;
		
		return add1 ( el1, el2, wynik, carryover, iterator+1, condition );

	}

	else return wynik; 

}

string add2 (string elem, string &wynik, int &carryover, int iterator, int condition) {

	if ( iterator < condition ) {

		int sum = ( elem[iterator] - 48 ) + carryover;

		wynik += (char) sum%10;
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

	if ( carryover ) des += (char) carryover;

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

		wynik += (char)  (diff+48);
		
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

		wynik += (char)  (diff+48);
		
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
	diff2 ( el1, des, carryover, len1, len1 );

	if ( carryover ) des += (char) carryover;

	des = reverse ( des );

	return des;


}

string AddMany (const string* argv, string wynik, int iterator, int condition) {

	if ( iterator < condition ) {

		if ( wynik[0] == '-' && argv[iterator][0] == '-' )  {
			string copy = argv[iterator];
			if ( copy[0] == '+' ) copy.erase(0, 1);
			wynik = Add(wynik, copy);
		}

		else if (wynik[0] == '-' && argv[iterator][0] == '-') {
			wynik[0]=0;
			string copy = argv[iterator];
			copy[0]=0;
			wynik = '-'+Add(wynik, copy);

		}
		else if ( wynik[0]=='-' ) {
			string copy = argv[iterator];
			if ( copy[0] == '+' ) copy.erase(0, 1);
			wynik[0]=0;
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
			if ( smaller ( wynik, argv[iterator] ) ) {
				wynik = '-' + Diff(wynik, argv[iterator]);
			}
			else {
				wynik = Diff(wynik, argv[iterator]);
			}
		}

		return AddMany(argv, wynik, iterator+1, condition);
	}
	return wynik;

}

string Sum (int argc, const string* argv) {

	string wynik = "0";
	return AddMany( argv, wynik, 0, argc );

}

string Sum ( int argc, ... ) {

}

int main () {

	cout << Diff("100", "100");

}