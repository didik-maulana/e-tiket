#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "style.h"
#include "menu.h"


using namespace std;

string username, pwd, re_pwd, msg;
int blc=0, topup;
string mn, mn_pay, ct;

// random
char c;
int r;

// flight
char kode, kelas;
int harga_tkt, tj_pw, pw, jml_pw, bayar_pw;
string kls_pw;
string no_tkt = "TKT-00";
string tujuan_pw[4] =
{
    "CGK-DPS",
    "JOG-CGK",
    "JOG-SUB",
    "KNO-JOG"
};
int size_flight = (sizeof(tujuan_pw)/sizeof(*tujuan_pw));

string tgl_pw[4] =
{
    "18-12-2018",
    "18-12-2018",
    "18-12-2018",
    "18-12-2018"
};

string jam_pw[4] =
{
    "18.30",
    "15.20",
    "20.00",
    "10.35"
};

int ekonomi_pw[4] =
{
    829000,
    484000,
    737000,
    950000
};

int bisnis_pw[4] =
{
    2048000,
    1243000,
    4020000,
    3610000
};

int eksekutif_pw[4] =
{
    10000000,
    80000000,
    95000000,
    15000000
};

char randomChar() {
    int num=1;
    for (int i=0; i<num; i++)
    {
        r = rand() % 26;
        c = 'A' + r;
        return c;
    }
}

int randomInt() {
    int n;
    n=1+(rand()%(400));
    return n;
}

void randomTiket() {
    cout << "TKT-" << randomChar() << "-" << randomInt();
}

void clear() {
	msg="";
	system("clear");
}

void msgAlert(string txt) {
    clear();
    string color = "\033[1;31m";
    string normal = "\033[0m";
    msg=color+txt+normal;
}

void msgSuccess(string txt) {
    clear();
    string color = "\033[1;32m";
    string normal = "\033[0m";
    msg=color+txt+normal;
}

void msgMenuFalse() {
    msgAlert("\t|X| Pilihan menu tidak tersedia");
}

void msgPayment() {
    string txt="\t|X| Saldo tidak cukup, silahkan isi ulang dulu!";
    string color = "\033[1;31m";
    string normal = "\033[0m";
    msg=color+txt+normal;
    out(msg);
}

void msgPwd() {
    pwd=re_pwd;
    msgAlert("\t|X| Password salah, coba lagi");
}

int main()
{
    srand (time(NULL));
    home:
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

    // Halaman signup
    signup:
    header("\tHalaman Signup");
    out("\tAyo daftar akun dulu . .");
    tab(1);
    line1(50);
    out(msg);
    input("\t  > Username : "); cin >> username;
    input("\t  > Password : "); cin >> pwd;
    input("\t  > Confirm Password : "); cin >> re_pwd;
    // auth and signup
    if(pwd==re_pwd) {
        clear();
        goto dashboard;
    } else {
        msgAlert("\t  |X| Uppss, password tidak valid!");
        goto signup;
    }

    // Halaman dashboard
    dashboard:
    header("Halaman Dashboard");
    cout << "\tSelamat Datang " << username;
    menuDashboard();
    out(msg);
    input("\tPilih menu : ");
    cin >> mn;
    if(mn=="1") {
        clear();
        goto flight;
    } else if(mn=="5") {
        clear();
        goto epay;
    } else if(mn=="6") {
        clear();
    } else if(mn=="7") {
        clear();
        goto home;
    } else {
        msgMenuFalse();
        goto dashboard;
    }

    // Halaman flight
    flight:
    header("Halaman Tiket Pesawat");
    endln(1);
    line2(70);
    out("                       DAFTAR PENERBANGAN           ");
    line2(70);
    out("No     Tujuan           Tanggal         Keberangkatan");
    line1(70);
    for(int i=0; i<size_flight; i++) {
        cout << i+1
        << ".     "
        << tujuan_pw[i]
        << "        "
        << tgl_pw[i]
        << "            "
        << jam_pw[i];
        endln(1);
    }
    line2(70);
    endln(1);
    out("\tDaftar Menu :");
    out("\t[1] Pesan tiket");
    out("\t[2] Kembali");
    out(msg);
    input("\tPilih Menu : ");
    cin >> mn;

    if(mn=="1") {
        input("\t> Pilih tujuan (1/2/3/4) : ");
        cin >> tj_pw;
        pw=tj_pw-1;
        endln(1);
        cout << "Penerbangan : " << tujuan_pw[pw];
        endln(1);
        line2(70);
        out("Ekonomi(E)     Bisnis(B)       Eksekutif(X)");
        line1(70);
        for(int i=0; i<1; i++) {
        cout << "Rp."
            << ekonomi_pw[pw]
            << "     Rp."
            << bisnis_pw[pw]
            << "        Rp."
            << eksekutif_pw[i];
            endln(1);
        }
        line2(70);
        endln(1);
        input("\t> Pilih kelas pesawat (E/B/X) : ");
        cin >> kls_pw;
        if(kls_pw=="E" || kls_pw=="e") {
            kls_pw="Ekonomi (E)";
            harga_tkt = ekonomi_pw[pw];
        } else if(kls_pw=="B" || kls_pw=="b") {
            kls_pw="Bisnis (B)";
            harga_tkt = bisnis_pw[pw];
        } else if(kls_pw=="X" || kls_pw=="x") {
            kls_pw="Eksekutif (X)";
            harga_tkt = eksekutif_pw[pw];
        }
        input("\t> Input jumlah penumpang : ");
        cin >> jml_pw;
        bayar_pw = jml_pw*harga_tkt;
        string nama_pw[jml_pw];
        int nm_pw_size = (sizeof(nama_pw)/sizeof(*nama_pw));
        for(int i=0; i<jml_pw; i++) {
            cout << "\t  " << i+1 <<". Nama penumpang : ";
            cin >> nama_pw[i];
        }
        clear();
        goto paymentPw;

        paymentPw:
        header("Halaman Pembayaran Tiket Pesawat");
        cout << "\tTotal pembayaran : Rp. " << bayar_pw;
        endln(1);
        cout << "\tSaldo E-Pay Anda : Rp. " << blc;
        endln(2);
        menuPayment();
        out(msg);
        input("\tPilih metode pembayaran : ");
        cin >> mn_pay;
        if(mn_pay=="1") {
            if(blc>bayar_pw) {
                clear();
                goto orderPw;
            } else {
                msgPayment();
                input("\t> Jumlah topup saldo : Rp.");
                cin >> topup;
                input("\t> Masukan password Anda : ");
                cin >> pwd;
                if(pwd==re_pwd) {
                    blc += topup;
                    msgSuccess("\t|*| Topup saldo berhasil");
                    goto paymentPw;
                } else {
                    msgPwd();
                    goto paymentPw;
                }
            }
        } else if(mn_pay=="2") {
            endln(1);
            out("\tSilahkkan transfer pada salah satu virtual account");
            out("\t*) verifikasi otomatis setelah transfer dilakukan");
            endln(1);
            input("\t  > Bank BCA     : 891083863658915"); endln(1);
            input("\t  > Bank Mandiri : 892056982116894"); endln(1);
            input("\t  > Bank BRI     : 893065854224012"); endln(1);
            input("\t  Lanjutkan pembayaran ? (Y/T) : ");
            cin >> ct;
            if(ct=="Y"||ct=="y") {
                clear();
                goto orderPw;
            } else if(ct=="T"||ct=="t") {
                clear();
                goto paymentPw;
            } else {
                msgMenuFalse();
                goto paymentPw;
            }
        } else {
            msgMenuFalse();
            goto paymentPw;
        }
        // Detail pemesanan pesawat
        orderPw:
        header("Halaman Tiket Penerbangan");
        endln(1);
        line2(70);
        tab(3);
        out("TIKET PENERBANGAN");
        line2(70);
        cout << "  No. Tiket      : "; randomTiket();
        endln(1);
        line1(70);
        cout << "  Penerbangan    : " << tujuan_pw[pw];
        endln(1);
        cout << "  Kelas          : " << kls_pw;
        endln(1);
        cout << "  Gerbang        : " << randomChar() << randomInt();
        endln(1);
        cout << "  Tanggal        : " << tgl_pw[pw];
        endln(1);
        cout << "  Waktu          : " << jam_pw[pw];
        endln(1);
        line1(70);
        out("  Nama penumpang :");
        for(int i=0; i<nm_pw_size; i++) {
            cout << "   " << i+1 << ". " << nama_pw[i]
            << "  (" << randomInt() << "-" << randomChar() << ")";
            endln(1);
        }
        line1(70);
        endln(1);
        out(msg);
        input("\t> Pesan tiket pesawat lagi ? (Y/T) : ");
        cin >> mn;
        if(mn=="Y"||mn=="y") {
            clear();
            goto flight;
        } else if(mn=="T"||mn=="t") {
            clear();
            goto dashboard;
        } else {
            msgMenuFalse();
            goto orderPw;
        }
    } else if(mn=="2") {
        clear();
        goto dashboard;
    } else {
        msgMenuFalse();
        goto flight;
    }

    // Halaman epay
    epay:
    header("Halaman E-Pay");
    cout << "\tSaldo Anda : Rp." << blc;

    menuEpay();
    out(msg);
    input("\tPilih menu : ");
    cin >> mn;

    if(mn == "1") {
        input("\tJumlah topup saldo : Rp.");
        cin >> topup;
        input("\tMasukan password Anda : ");
        cin >> pwd;
        if(pwd==re_pwd) {
            blc += topup;
            msgSuccess("\t|*| Topup saldo berhasil");
            goto epay;
        } else {
            msgPwd();
            goto epay;
        }
    } else if(mn=="2") {
        clear();
        goto dashboard;
    } else {
        msgMenuFalse();
        goto epay;
    }

    return 0;
}
