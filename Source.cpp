#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "Account_Algorithm.h"


using namespace std;

#define DISPLAY std::cout << "Good";

template <typename X>
void sq_rt(X value) {
	int result = std::sqrt(value);
	std::cout << result;
}



int main() {
	Account_Algorithm Account;
	//Account.Del_Ent_Rec();
	//Account.Retrieve_Data();
	//Account.Get_Account_Num();
	//Account.Show_Data();
	//Account.Write_to_Rec();
	Account.Search_Rec();
	//Account.Edit_Rec();
	//Account.Del_a_Rec();
	//Account.Find_Isogram(str);
	//Account.Biometric(str);
}