#include <vector>
using namespace std;

vector <int> failure(const vector <int> &arr){
    int j = 0;
    
    vector <int> pi(arr.size(), 0);
    for(int i = 1; i < arr.size(); i++){
        while ( j > 0 && arr[i] != arr[j]){
            j = pi[j-1];
        }
        if(str[i] == str[j] ) {
            pi[i] = j + 1;
            j += 1;
        }
        else{
            pi[i] = 0;
        }
    }
}

bool kmp(const vector<int> &s,
        const vector<int> &p,
        const vector<int> &pi,
        ){
    int n = s.size();
    int m = p.size();
    int i = 0,j = 0;
    for(i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j]){
            j = pi[j-1];
        }
        if (s[i] == p[j]) {
            if (j == m - 1) {
                return true;    
            }

            else {
                j++;
            }
        }
    }
    return false;
}

