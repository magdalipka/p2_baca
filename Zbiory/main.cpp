//Magdalena Lipka//
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int add(int x, int y) {
	if (y == 0 ) return x;
	else {
		int carry = x & y;
		add( x ^ y, carry << 1 );
	} 
}
void increment ( int &n ) {
	n = add(n, 1);
}
void substraction( int &x, int &m ) {
	if ( !(x & m) ) {
		x = x ^ m;
		m <<= 1;
		substraction( x, m );
	}
}
int substract(int &x, int m) {
	substraction(x, m);
	x = x^m;
	return x;
}
int decrement(int &x) {
	return substract(x, 1);
}
int chartoint(char a) {
	if (a == '0') return 0;
	else return 1;
}
string inttobinstring(int liczba) {
	switch (liczba) {
	case 0:
	   return "00000";
	break;
	case 1:
	    return "00001";
	break;
	case 2:
	    return "00010";
	break;
	case 3:
	    return "00011";
	break;
	case 4:
	    return "00100";
	break;
	case 5:
	    return "00101";
	break;
	case 6:
	    return "00110";
	break;
	case 7:
	    return "00111";
	break;
	case 8:
	    return "01000";
	break;
	case 9:
	    return "01001";
	break;
	case 10:
	    return "01010";
	break;
	case 11:
	    return "01011";
	break;
	case 12:
	    return "01100";
	break;
	case 13:
	    return "01101";
	break;
	case 14:
	    return "01110";
	break;
	case 15:
	    return "01111";
	break;
	case 16:
	    return "10000";
	break;
	case 17:
	    return "10001";
	break;
	case 18:
	    return "10010";
	break;
	case 19:
	    return "10011";
	break;
	case 20:
	    return "10100";
	break;
	case 21:
	    return "10101";
	break;
	case 22:
	    return "10110";
	break;
	case 23:
	    return "10111";
	break;
	case 24:
	    return "11000";
	break;
	case 25:
	    return "11001";
	break;
	case 26:
	    return "11010";
	break;
	case 27:
	    return "11011";
	break;
	case 28:
	    return "11100";
	break;
	case 29:
	    return "11101";
	break;
	case 30:
	    return "11110";
	break;
	case 31:
	    return "11111";
	break;
	}
}

int calculatevalue ( string text, int &i, int value ) {
	value = add((unsigned int) (value<<1), chartoint(text.at(i)) );
	increment(i);
	value = add( (unsigned int)(value<<1), chartoint(text.at(i)) ) ;
	increment(i);
	value = add( (unsigned int)(value<<1), chartoint(text.at(i))  );
	increment(i);
	value = add( (unsigned int)(value<<1), chartoint(text.at(i))  );
	increment(i);
	value = add( (unsigned int)(value<<1), chartoint(text.at(i)) ) ;
	//std::cout << "value: " << value << std::endl;
	return value;
}
int insertnapis( string text, int &i, int *set ) {

	if ( i >= text.length() ) return 1;
	else {
		if ( text.at(i) != ' ' ) {
			int value = calculatevalue(text, i, 0);
			if ( (*set>>value)%2 == 0 ) {
				*set = add( *set, 1<<value);
				//cout << "inserted " << value << endl;
			}
		}
		increment(i);
		insertnapis(text, i, set);
	} 
}
void Insert( string text, int* set ) {

	int i = 0;
	insertnapis(text, i, set);	

}
void Emplace ( string text, int* set ) {

	*set = 0;
	int i = 0;

	Insert(text, set);

}
int erasenapis( string text, int &i, int *set ) {

	if ( i >= text.length() ) return 1;
	else {
		if ( text.at(i) != ' ' ) {
			int value = calculatevalue(text, i, 0);
			if ( (*set>>value)%2 != 0 ) {
				*set = substract( *set, 1<<value);
				//cout << "erased " << value << endl;
			}
		}
		increment(i);
		erasenapis(text, i, set);
	} 

}
void Erase ( string text, int* set ) {
	
	int i = 0;

	erasenapis(text, i, set);

}
void printset (stringstream &copy, int set, int &licznik, int &czypierwszy) {

	if ( licznik > 0 ) {
	
		if ( (set>>licznik)%2 != 0 ) {
			if( !czypierwszy ) copy << " ";
			else czypierwszy = 0;
			copy << inttobinstring(licznik);
		}
		decrement(licznik);
		printset(copy, set, licznik, czypierwszy);
	}
} 
void Print ( int set, std::string* text ) {

	if (set == 0) *text = "empty";
	else {
		int a = 31;
		stringstream result;
		int czy = 1;
		printset( result, set, a, czy);
		if ( (set%2) != 0) result << " " << "00000";

		*text = result.str();
	}

}
bool Emptiness ( int set ) {
	if( set == 0 ) return 1;
	else return 0;
}
bool Nonempty ( int set ) {
	if( set != 0 ) return 1;
	else return 0;
}
bool Disjoint( int set1, int set2 ) {
	if ( (set1 & set2) == 0 ) return 1;
	else return false;
}
bool Conjunctive( int set1 ,int set2 ) {
	if( ( set1 & set2 ) != 0 ) return 1;
	else return 0;
}
bool Inclusion( int set1, int set2 ) {
	if( (set1&set2) == set1 ) return 1;
	else return 0;
}
bool Equality( int set1, int set2) {
	if ( set1 == set2 ) return 1;
	else return 0;
}
void Union( int set1, int set2, int* result) {
	*result = set1 | set2;
}
void Intersection( int set1, int set2, int* result ) {
	*result = set1 & set2;
}
void Symmetric( int set1, int set2, int* result ) {
	*result = set1 ^ set2;
}
void Difference( int set1, int set2, int* result ) {
	*result = set1 & (~set2);
}
void Complement( int set, int* result ) {
	*result = ~set;
}

int liczenie(unsigned int set, int i, int &suma) {

	if ( i >=32 ) return 1;
	else {
		int dodajnik = (set>>i)%2;
		if ( dodajnik != 0 ) increment(suma);
		increment(i);
		liczenie(set, i, suma);
	}
}
bool LessThen( int set1, int set2 ) {
	int sum1 = 0;
	int sum2 = 0;
	int i = 0;
	liczenie((unsigned int)set1, i, sum1);
	i = 0;
	liczenie((unsigned int)set2, i, sum2);


	if( sum1<sum2 ) return 1;
	else if ( sum1==sum2 ) {
		if( (unsigned int)(set1) < (unsigned int)(set2) ) return 1;
		else return 0;
	}
	else return 0;
}
bool LessEqual( int set1, int set2 ) {

	int sum1 = 0;
	int sum2 = 0;
	int i = 0;
	liczenie(set1, i, sum1);
	i = 0;
	liczenie(set2, i, sum2);


	if( sum1<sum2 ) return 1;
	else if ( sum1==sum2 ) {
		if( (unsigned int)(set1) <= (unsigned int)(set2) ) return 1;
		else return 0;
	}
	else return 0;
}
bool GreatEqual( int set1, int set2 ) {

	int sum1 = 0;
	int sum2 = 0;
	int i = 0;
	liczenie(set1, i, sum1);
	i = 0;
	liczenie(set2, i, sum2);


	if( sum1>sum2 ) return 1;
	else if ( sum1==sum2 ) {
		if( (unsigned int)(set1) >= (unsigned int)(set2) ) return 1;
		else return 0;
	}
	else return 0;
}
bool GreatThen( int set1, int set2 ) {

	int sum1 = 0;
	int sum2 = 0;
	int i = 0;
	liczenie(set1, i, sum1);
	i = 0;
	liczenie(set2, i, sum2);


	if( sum1>sum2 ) return 1;
	else if ( sum1==sum2 ) {
		if( (unsigned int)(set1) > (unsigned int)(set2) ) return 1;
		else return 0;
	}
	else return 0;
}
bool Member ( string text, int set ) {

	int napis;
	Emplace(text, &napis);
	string check;
	cout << endl << check << endl;
	Print(napis, &check);
	if ( Inclusion(napis, set) ) return 1;
	else return 0;

}


int main(){

int set=0;
    Emplace("", &set);
    if(Member("11111", set))cout<<"true1";
    Emplace("11111", &set);
    if(Member("", set))cout<<"true2";
    Emplace("11111 00011 10100      ", &set);
    if(Member("11111", set))cout<<"true3";
    Emplace("11111 00011 10100      ", &set);
    if(Member("00000", set))cout<<"true4";
    Emplace("11111 00011 10100      ", &set);
    if(Member(" ", set))cout<<"true5";
    Emplace("                           00001 01001", &set);
    if(Member("11111", set))cout<<"true6";

}