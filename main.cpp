#include <iostream>
#include <fstream>
#include <random>
using namespace std;

uniform_int_distribution<int> u(0, 1000);

default_random_engine e;

int main() {
    cout << "please input the number of edges you want to generated\n";
    int number;
    cin >> number;
    getchar();
    ofstream os;
    string fileName = "random" + to_string(number) + ".txt";

    os.open(fileName, ios::app);

    string firstLine = to_string(number + 1);
    os << firstLine << endl;
    char  r;
    string string1;

    for(int i = 0; i < number; ++i) {
        r = 'a' + rand() % 26;
        string1 = to_string(u(e)) + " " + r + " " + to_string(u(e));
//        cout << string1 << endl;
        os << string1  << "\n";
    }

    os.close(); //关闭文件
    cout << "automaton with " << number << " edges is produced and stored in " << fileName << endl;
    return 0;
}
