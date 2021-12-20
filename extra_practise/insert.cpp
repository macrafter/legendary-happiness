#include <iostream>
using namespace std;


class mylist {
    int arr[10];
    int cnt = 0;

public:
    void add(int v) {
        arr[cnt] = v;
        cnt++;
    }

    void remove() {
        cnt--;
    }

    void print() {
        for(int i = 0; i < cnt; i++)
            cout << arr[i] << endl;
    }

    int size() {
        return cnt;
    }
};


int main() {

    mylist lst;

    while(true) {
        char menu;

        cout << "Options:" << endl;
        cout << "1. i to insert" << endl;
        cout << "2. d to delete" << endl;
        cout << "3. l to list" << endl;
        cout << "4. q to exit" << endl;
        cout << "Enter command:";
        cin >> menu;

        if(menu == 'q')
            return 0;
        else if(menu == 'i')
        {   
            if(lst.size() == 10){
                cout << "max value inserted" << endl;
            }else{
                // insert into list
                cout << "enter the value:";
                int value;
                cin >> value;
                // save value
                lst.add(value);
            }
        } 
        else if(menu == 'd') 
        {
            // delete from list
            if(lst.size()==0){
                cout << "No please stop" << endl;
            }else{
                lst.remove();
            }
        }   
        else if(menu == 'l')
        {
            lst.print();
        }
    }

    return 0;
}

