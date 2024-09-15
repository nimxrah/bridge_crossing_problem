#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min_r(vector <int>& r_bridge){
    int min_r = r_bridge[0];
    int k = 0;
    for (int i = 1; i<r_bridge.size(); ++i){
        if (r_bridge[i]<min_r){
            min_r = r_bridge[i];
            k = i;
        }
    }
    return k;
}

pair<int, int> min12_l(vector<int>& l_bridge){
    int min_l1 = l_bridge[0], min_l2 = INT_MAX;
    int k = 0, j = 0;
    for (int i = 1; i < l_bridge.size(); ++i) {
        if (l_bridge[i] < min_l1) {
            min_l2 = min_l1;
            min_l1 = l_bridge[i];
            j = k;
            k = i;
        } else if (l_bridge[i] < min_l2) {
            min_l2 = l_bridge[i];
            j = i;
        }
    }
    return {k, j};

}

pair<int, int> max12_l(vector <int>& l_bridge){
    int max_l1 = l_bridge[0], max_l2 = INT_MIN;
    int k = 0, j = 0;
    for (int i = 1; i < l_bridge.size(); ++i) {
        if (l_bridge[i] > max_l1) {
            max_l2 = max_l1;
            max_l1 = l_bridge[i];
            j = k;
            k = i;
        } else if (l_bridge[i] > max_l2) {
            max_l2 = l_bridge[i];
            j = i;
        }
    }
    return {k, j};
}


int main(){
    vector <int> people(5);
    vector <int> l_bridge(5);
    char ch;
    for(int i = 0; i<5; i++){
        cin>>ch;
        cin>>people[i];
    }
    for (int i = 0; i<5; i++){
        l_bridge[i] = people[i];
    }

    vector <int> r_bridge;
    int result = 0;

    auto [min_l1, min_l2] = min12_l(l_bridge);
    r_bridge.push_back(l_bridge[min_l1]);
    r_bridge.push_back(l_bridge[min_l2]);

    if (min_l1>min_l2){
        l_bridge.erase(l_bridge.begin()+min_l1);
        l_bridge.erase(l_bridge.begin()+min_l2);
    }
    else{
        l_bridge.erase(l_bridge.begin()+min_l2);
        l_bridge.erase(l_bridge.begin()+min_l1);
    }

    result+=max(r_bridge[0],r_bridge[1]);

    int min_rb  = min_r(r_bridge);

    result += r_bridge[min_rb];
    l_bridge.push_back(r_bridge[min_rb]);
    r_bridge.erase(r_bridge.begin()+min_rb);

    auto [max_l1, max_l2] = max12_l(l_bridge);
    r_bridge.push_back(l_bridge[max_l1]);
    r_bridge.push_back(l_bridge[max_l2]);
    int maxx1 = l_bridge[max_l1];
    int maxx2 = l_bridge[max_l2];
    if (max_l1>max_l2){
        l_bridge.erase(l_bridge.begin()+max_l1);
        l_bridge.erase(l_bridge.begin()+max_l2);
    }
    else{
        l_bridge.erase(l_bridge.begin()+max_l2);
        l_bridge.erase(l_bridge.begin()+max_l1);
    }

    result+=max(maxx1,maxx2);

    min_rb  = min_r(r_bridge);

    result += r_bridge[min_rb];
    l_bridge.push_back(r_bridge[min_rb]);
    r_bridge.erase(r_bridge.begin()+min_rb);


    auto [min_l11, min_l22] = min12_l(l_bridge);
    r_bridge.push_back(l_bridge[min_l11]);
    r_bridge.push_back(l_bridge[min_l22]);
     int minn1 = l_bridge[min_l11];
    int minn2 = l_bridge[min_l22];
    if (min_l11>min_l22){
        l_bridge.erase(l_bridge.begin()+min_l11);
        l_bridge.erase(l_bridge.begin()+min_l22);
    }
    else{
        l_bridge.erase(l_bridge.begin()+min_l22);
        l_bridge.erase(l_bridge.begin()+min_l11);
    }

    result+=max(minn1,minn2);

    min_rb  = min_r(r_bridge);

    result += r_bridge[min_rb];
    l_bridge.push_back(r_bridge[min_rb]);
    r_bridge.erase(r_bridge.begin()+min_rb);


    auto [max_l11, max_l22] = max12_l(l_bridge);
    r_bridge.push_back(l_bridge[max_l11]);
    r_bridge.push_back(l_bridge[max_l22]);
    maxx1 = l_bridge[max_l11];
    maxx2 = l_bridge[max_l22];
    if (max_l11>max_l22){
        l_bridge.erase(l_bridge.begin()+max_l11);
        l_bridge.erase(l_bridge.begin()+max_l22);
    }
    else{
        l_bridge.erase(l_bridge.begin()+max_l22);
        l_bridge.erase(l_bridge.begin()+max_l11);
    }

    result+=max(maxx1,maxx2);

     cout << "Total result: " << result << endl;
    return 0;
}
