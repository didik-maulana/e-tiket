using namespace std;

void out(string a) {
    cout << a << endl;
}

void input(string a) {
    cout << a;
}

void endln(int a) {
    for(int i=0; i<a; i++) {
        cout << endl;
    }
}

void line() {
    cout << "-----------------------------------------\n";
}

void line1(int a) {
    for(int i=0; i<a; i++) {
        input("-");
    }
    endln(1);
}

void line2(int a) {
    for(int i=0; i<a; i++) {
        input("=");
    }
    endln(1);
}

void header(string a) {
    line1(70);
    cout <<"|               E-Tiket                 |\n";
    line1(70);
    cout << a << endl;
    line1(70);
    endln(1);
}
