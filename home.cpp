#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "style.h"
#include "menu.h"

using namespace std;

int main() {
    header("Halaman Home");
    out("\tPesan tiket semudah klik, kapanpun dan dimanapun!");
    out("\t-------------------------------------------------");
    endln(1);
    menuHome();
    out(msg);
    input("\tPilih menu : ");
    cin >> mn;
    if(mn=="1") {
        clear();
        goto signup;
    } else if(mn=="2") {
        clear();
        exit(0);
    } else {
        msgMenuFalse();
        goto home;
    }
}
