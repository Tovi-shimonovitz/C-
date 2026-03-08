#pragma once
using namespace std;
#include <string>
#include <stdexcept>
class Account
{
private:
	long AccountNumber;
	int code;
	int balance;
	string email;
public:
	Account() : AccountNumber(0), code(0), balance(0), email("") {}
	Account(long AccountNumber = 0, int code = 0, int balance = 0, string email = "") 
		: AccountNumber(0), code(0), balance(0), email("")
    {
		string coil = ".co.il";
		string com = ".com";
		
		if (code < 1000 || code > 9999) {
			
			throw std::invalid_argument("ERROR: code must be of 4 digits!");
		}
		
		   
		if (email.find('@') == string::npos) {
			
			throw std::invalid_argument("ERROR: email must contain @!");
		}
		else {
			if (!((email.size() >= coil.size() && email.substr(email.size() - coil.size()) == coil)||
				(email.size() >= com.size() && email.substr(email.size() - com.size()) == com))) {
				throw std::invalid_argument("ERROR: email must end at .com or .co.il!");
			}
		}
		this->AccountNumber = AccountNumber;
		this->code = code;
		this->balance = balance;
		this->email = email;
	}
	long getAccountNumber() const { return AccountNumber; }
	int getCode() const { return code; }
	int getBalance() const { return balance; }
	string getEmail() const { return email; }
	
};

