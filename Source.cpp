#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "Account_Algorithm.h"

using namespace std;


int main() {
	string str;
	cout << "Type a Word: ";
	cin >> str;
	Account_Algorithm Account;
	//Account.Del_Ent_Rec();
	//Account.Read_Data();
	//Account.Get_Account_Num();
	//Account.Show_Data();
	//Account.Write_to_Rec();
	//Account.Search_Rec();
	//Account.Edit_Rec();
	//Account.Del_a_Rec();
	Account.Find_Isogram(str);
	//Account.Biometric(str);
}