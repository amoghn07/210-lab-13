#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    ifstream fin;
    vector <string> customers;
    vector <double> purchases;

    fin.open("customers.txt");
    //filling in array with all text file data
    if (fin.good()){
        int i = 0;
        while (!fin.eof()){
            fin >> purchases[i];
            fin.ignore();
            getline(fin, customers[i]);
            i++;
        }
        fin.close();
    }
    else{
        cout << "file not found.";
        return 1;
    }

    double bigBuy = *max_element(purchases.begin(), purchases.end());
    cout << "Total customer count for the day: " << customers.size() << endl;
    cout << "Biggest sale: " << bigBuy << endl;
    cout << "Smallest sale: " << *min_element(purchases.begin(), purchases.end()) << endl;
    cout << "Total Revenue: " << accumulate(purchases.begin(), purchases.end(), 0) << endl;

    vector<double>::iterator it;
    it = find(purchases.begin(), purchases.end(), bigBuy);
    string bigBuyPerson = customers.at(it - purchases.begin());

    cout << "Person who spent the most money: " << bigBuyPerson << endl;
    cout << "List of customers: \n";
    for (string person : customers) cout << '\t' << person << endl;
    return 0;
}