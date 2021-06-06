#include "Account_Algorithm.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

void Account_Algorithm::Read_Data() {
	cout << "Enter First Name: ";
	cin >> FirstName;
	cout << endl;
	cout << "Enter Last name: ";
	cin >> LastName;
	cout << endl;
	cout << "Enter Phone Number: ";
	cin >> Phone_Number;
	cout << endl;
}

int Account_Algorithm::Get_Account_Num() {
	int i;
	int rand1, rand2, rand3;
	srand(time(0));
	rand1 = rand() % 100;
	rand2 = rand() % 100;
	rand3 = rand() % 100;
	Acc_Num = rand1 + rand2 + rand3;
	cout <<"Generated Account Number: " << Acc_Num;
	return 0;
}

void Account_Algorithm::Show_Data() {
	string cc = "+234";
	cout << endl;
	cout << "First Name: " << FirstName << endl;
	cout << "Last Name: " << LastName << endl;
	cout << "Phone Number:" << cc << Phone_Number << endl;
	cout << "Account Number: " << Acc_Num << endl;
}


void Account_Algorithm::Write_to_Rec() {
	fstream Bank;
	Bank.open("Bank_Model_Data.txt", ios::app);
	if (!Bank) {
		cout << endl << "File not created" << endl;
	}
	else {
		    Read_Data();
			Get_Account_Num();
			Bank << FirstName << endl;
			Bank << LastName << endl;
			Bank << Phone_Number << endl;
			Bank << Acc_Num << endl;
			cout << endl;
			Show_Data();
		}
	cout << "\nFile Successfully Created!" << endl;
	Bank.close();
}

void Account_Algorithm::Search_Rec() {
	int num;
	ifstream bank;
	bank.open("Bank_Model_Data.txt", ios::out);
	if (!bank) {
		cout << "File Not Found" << endl;
	}
	else {
		bank.seekg(0, ios::end);
		int count = bank.tellg() / sizeof(bank.tellg());
		cout << endl << "There are " << count << " record in the file." << endl;
		cout << "Enter Record Number to search (Each collection is mapped by an odd Number): ";
		cin >> num;
		bank.seekg((num - 1) * sizeof("Bank_Model_Data"));
		bank >> FirstName;
		bank >> LastName;
		bank >> Phone_Number;
		bank >> Acc_Num;
		Show_Data();
		cout << endl;
		bank.close();
	}
}

void Account_Algorithm::Edit_Rec() {
	int n;
	fstream Bank_write;
	Bank_write.open("Bank_Model_Data.txt", ios::in);
	if (!Bank_write) {
		cout << "File Not Found" << endl;
	}
	Bank_write.seekg(0, ios::end);
	int count = Bank_write.tellg() / sizeof(Bank_write.tellg());
	cout << endl << "There are " << count << " record in the file." << endl;
	cout << "Enter Record Number to Edit" << endl;
	cin >> n;
	cout << endl;
	Bank_write.seekg((n - 1) * sizeof("Bank_Model_Data.txt"));
	Bank_write >> FirstName;
	Bank_write >> LastName;
	Bank_write >> Phone_Number;
	Bank_write >> Acc_Num;
	cout << endl;
	cout << "The Record "<< n <<" has the following data:" << endl;
	Show_Data();
	Bank_write.close();
	//Now we open the file agian to edit data
	Bank_write.open("Bank_Model_Data.txt", ios::out|ios::in);
	Bank_write.seekp((n - 1) * sizeof("Bank_Model_Data.txt"));
	cout << endl;
	cout << "Enter Data to Modify: " << endl;
	Read_Data();
	Bank_write << FirstName << endl;
	Bank_write << LastName << endl;
	Bank_write << Phone_Number << endl;
	Bank_write << Acc_Num << endl;
	cout << endl;
	cout << "File Successfully Updated: " << endl;
}

void Account_Algorithm::Del_Ent_Rec() {
	remove("Bank_Model_Data.txt");
	cout << "File Deleted" << endl;
}

void Account_Algorithm::Del_a_Rec() {
	int num;
	int count;
	ifstream Bank_out;
	Bank_out.open("Bank_Model_Data.txt", ios::in);
	if (!Bank_out) {
		cout << "File not Found" << endl;
	}
		Bank_out.seekg(0, ios::end);
		count = Bank_out.tellg() / sizeof("Bank_Model_Data.txt");
		cout << "There are " << count << " number of Records in the file" << endl;
		cout << "Enter Record number to delete: ";
		cin >> num;
		cout << endl;
		Show_Data();
		cout << endl;
		fstream Bank_d;
		Bank_d.open("Tempfile.txt", ios::out|ios::in);
		Bank_out.seekg(0);
		for (int i = 0; i < count; i++) {
			Bank_out >> FirstName;
			Bank_out >> LastName;
			Bank_out >> Phone_Number;
			Bank_out >> Acc_Num;
			if (i == (num - 1)) {
				continue;
				Bank_d << FirstName;
				Bank_d << LastName;
				Bank_d << Phone_Number;
				Bank_d << Acc_Num;
			}
		}
		Bank_out.close();
		Bank_d.close();
		remove("Bank_Model_Data.txt");
		rename("Tempfile.txt","Bank_Model_Data.txt");
}

void Account_Algorithm::Find_Isogram(string str) {

	for (int i = 0; i < str.length(); i++) {

		int logic = ((str[i] == str[i + 1]));

		if (logic == true) {

			cout << "Not an Isogram" << " ";
			
		}
		else{

			cout << "ISOGRAM" << " ";

		}
	}
}

		  


