#include <iostream>
#include <list>

using namespace std;

void readList(list<int> &l){
    int n;
    cin >> n;

    while (n != -1){
        l.push_front(n);
        cin >> n;
    }
}

void cleanList(list<int> &l){
    while (!l.empty()){
        l.pop_front();
    }
}

int main(){
    list<int> l1;
    list<int>::iterator it;

    int x;
    int y;

    readList(l1);

    cin >> x >> y;

    for (it = l1.begin(); it != l1.end(); it++){
        if (*it == x){
            it++;
            l1.insert(it, y);
            break;
        }
    }

    for (it = l1.begin(); it != l1.end(); it++){
        cout << *it << " ";
    }
    
    cleanList(l1);

    return 0;
}