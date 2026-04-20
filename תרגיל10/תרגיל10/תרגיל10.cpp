#include <iostream>
#include <map>
#include <string>
using namespace std;
float getAverage(const map<string, int>& fruitPrice);
int main()
{
	map<string, int> prices = {
		{"Banana",10},
		{"Apple",8},
		{"Bread",7},
		{"milk",20},
		{"juice",15}
	};
	
	map<string, int>shopping_cart = {
		{"Banana",3},
		{"Bread",2},
		{"milk",1},
		{"buttle",3}

	};
	double total = 0;

	map <string, int>::iterator itSh = shopping_cart.begin();
	while(itSh!=shopping_cart.end()){
		if (prices.count(itSh->first) == 0)
			cout << itSh->first << " is not Exsist in the dictionary "<< endl;
		else {
				total += itSh->second * prices.at(itSh->first);
		}
		
		itSh++;
	}
	cout << total;
	cout << " average: " << getAverage(prices);

}
float getAverage(const map<string, int> &fruitPrice)
	{
		float average = 0.0;
		auto mystery = [&](const map<string, int>& m) {
			if (m.empty()) return;
			float sum = 0;
			for (auto const& it : m) {
				sum += it.second;
			}
			average = sum / m.size();
			};
		mystery(fruitPrice);
		return average;
	}


