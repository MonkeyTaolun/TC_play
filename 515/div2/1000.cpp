#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NewItemShopTwo{
public:
  int string2int(string a){
    //cout << "this is string   " << a << endl;
    int total = 0;
    for(int i = 0; i < a.size(); ++i){
      total *= 10;
      total += a[i] - '0';
    }
    //cout << total << endl;
    return total;
  }
  void spitbycomma(string a, vector<int>& aa, vector <int>& bb, vector <int>& cc){
    int begin = a.find(',', 0);
    int end   = a.rfind(',');
    //cout << "this is end line " << end << endl;
    //cout << string2int(a.substr(0, begin)) << endl;
    aa.push_back(string2int(a.substr(0, begin)));
    //cout << "tghs " <<a[begin+1] << endl;
    //cout << "sadfasdf " <<a[end-1] << endl; 
    //cout << string2int(a.substr(begin+1, end - begin -1)) << endl;
    bb.push_back(string2int(a.substr(begin+1, end - begin - 1)));
    //cout << string2int(a.substr(end+1, a.size() - end)) << endl;
    cc.push_back(string2int(a.substr(end+1,a.size())));
  }
  void convertData(string a, vector<int>& aa, vector <int>& bb, vector <int>& cc){
    int loc1 = 0;
    int loc2 = 0;
    while(a.find(' ', loc1) != string::npos){
      loc2 = a.find(' ', loc1);
      string temp = a.substr(loc1, loc2);
      //cout << temp << endl;
      spitbycomma(temp, aa, bb,cc);
      loc1 = loc2 + 1;
    }
    //cout << a.substr(loc1, a.size()) << endl;
    spitbycomma(a.substr(loc1, a.size()), aa, bb,cc);
  }
  double getMaximum(vector <string> customers){
    vector <int> a_t;
    vector <int> a_c;
    vector <int> a_p;
    vector <int> b_t;
    vector <int> b_c;
    vector <int> b_p;
    convertData(customers[0], a_t, a_c, a_p);
    convertData(customers[1], b_t, b_c, b_p);
    return 0;    
  }
};

int main(){
  NewItemShopTwo nist;
  vector <string> a;
  a.push_back("8,1,80 16,100,11");
  a.push_back("12,10,90 13,30,5");
  //cout << nist.string2int("1235") << endl;
  cout << nist.getMaximum(a) << endl;
}