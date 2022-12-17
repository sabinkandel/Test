
#include <iostream>
#include <iterator>
#include <map>
#include<vector>
using namespace std;

// finding combination through backtracking

void findNumbers(vector<double>& ar, double sum,vector<vector<double> >& res, vector<double>& r,int i) {
	if (sum == 0) {
		res.push_back(r);
		return;
	}
	while (i < ar.size() && sum - ar[i] >= 0) {
		r.push_back(ar[i]); 
		findNumbers(ar, sum - ar[i], res, r, i);
		i++;
		r.pop_back();
	}
}
vector<vector<double> > combinationSum(vector<double>&ar, double sum) {
	sort(ar.begin(), ar.end());
	ar.erase(unique(ar.begin(), ar.end()), ar.end());
	vector<double> r;
	vector<vector<double> > res;
	findNumbers(ar, sum, res, r, 0);
	return res;
}


int main()
{
	//creating Newspapers Datas
    map<string,vector<double>> a;
    vector<vector<double>> values = {{3,3,3,3,3,5,6},
                                     {2.5,2.5,2.5,2.5,4,4},
                                     {4 ,4, 4, 4 ,4, 4, 10},
                                     {1.5, 1.5 ,1.5 ,1.5 ,1.5 ,1.5, 1.5},
                                     {2, 2, 2 ,2, 2, 4 ,4}};
    vector<string> np = {"TOI","Hindu","ET","BM","HT"};
    for(int i = 0 ; i < 5; i++) a[np[i]] = values[i];

// maping data 

    map<double,string> npt;
    vector<double> v;
    for(auto i : a){
        double total = 0.0;
        for(int j = 0 ; j< 7; j++){
            total += i.second[j];
        }
 // cout<<i.first << total << endl;
        v.push_back(total);
       npt[total] = i.first;
    }

// taking ip and finding combinations
    int input;
    cin >> input;
    vector<vector<double> > op = combinationSum(v, input);
	
// printing combinations
    for(int i = 0 ; i< op.size();i++ ){
        for(int j = 0 ; j < op[i].size();j++)
        cout << npt[op[i][j]] << "  ";
        cout << endl;
    }
    
    return 0;
}