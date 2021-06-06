#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

class Account_Algorithm
{
private:
	string  FirstName;
	string  LastName;
	int Phone_Number;
	int Acc_Num;
public:
	void Read_Data();
	int Get_Account_Num();
	void Show_Data();
	void Write_to_Rec();
	void Search_Rec();
	void Edit_Rec();
	void Del_Ent_Rec();
	void Del_a_Rec();
	void Find_Isogram(string str);
};

