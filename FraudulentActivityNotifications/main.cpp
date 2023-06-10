#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
/*
* Complete the 'activityNotifications' function below.
*
* The function is expected to return an INTEGER.
* The function accepts following parameters:
* 1. INTEGER_ARRAY expenditure

* 2. INTEGER d
*/

int activityNotifications(vector<int> expenditure, int d) {
    int i = d;
    int notices = 0;

    for (int j = i; j < expenditure.size(); j++){
        int lower = j - d;
        int upper = j - 1;
        int mid = d / 2;
        float medium;

        vector<int >expenditure_s(d);
        partial_sort_copy(expenditure.begin() + j - d, expenditure.begin() + j, expenditure_s.begin(), expenditure_s.end());

        if (d % 2 == 0){
            int sum = expenditure_s[mid] + expenditure_s[mid + 1];
            medium = sum / 2.0;
        }else{
            medium = expenditure_s[mid];
        }
        float constrain = medium * 2;
        if (expenditure[j] >= constrain){
            notices++;
        }
    }
    cout << notices;
}
int main()
{
    vector<int> expenditure;
    expenditure.push_back(2);
    expenditure.push_back(3);
    expenditure.push_back(4);
    expenditure.push_back(2);
    expenditure.push_back(3);
    expenditure.push_back(6);
    expenditure.push_back(8);
    expenditure.push_back(4);
    expenditure.push_back(5);

    activityNotifications(expenditure, 5);

//    vector<int> expenditure1(5);
//    partial_sort_copy(expenditure.begin() + 1, expenditure.begin() + 6, expenditure1.begin(), expenditure1.end());
//    for (int j: expenditure1){
//        cout << j << endl;
//
//    }



}