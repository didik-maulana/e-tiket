#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "style.h"
#include "menu.h"

using namespace std;

string username, pwd, re_pwd, msg;
int blc=0, topup;
string mn, mn_pay;

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

void clear() {
	msg="";
	system("clear");
}

void msgAlert(string txt) {
    clear();
    msg=txt;
}

void msgMenuFalse() {
    msgAlert("|X| Pilihan menu tidak tersedia");
}

void msgPayment() {
    msgAlert("|X| Saldo e-pay tidak cukup, silahkan isi dulu!");
}

void msgPwd() {
    pwd=re_pwd;
    msgAlert("|X| Password salah, coba lagi");
}

int main()
{
    // Halaman signup
    signup:
    header("Halaman Signup");
    out("Ayo daftar akun dulu . .");
    out(msg);
    input("Username : ");
    cin >> username;
    input("Password : ");
    cin >> pwd;
    input("Confirm Password : ");
    cin >> re_pwd;

    // auth and signup
    if(pwd==re_pwd) {
        clear();
        goto home;
    } else {
        msgAlert("|X| Uppss, password tidak valid!");
        goto signup;
    }

    // Halaman home
    home:
    header("Halaman Dashboard");
    cout << "Selamat Datang " << username;

    menuHome();
    out(msg);
    input("Pilih menu : ");
    cin >> mn;

    if(mn=="1") {
        clear();
        goto flight;
    } else if(mn=="5") {
        clear();
        goto epay;
    } else if(mn=="7") {
        clear();
        goto signup;
    } else {
        msgMenuFalse();
        goto home;
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
    out("Daftar Menu :");
    out("[1] Pesan tiket");
    out("[2] Kembali");
    out(msg);
    input("Pilih Menu : ");
    cin >> mn;

    if(mn=="1") {
        input("Pilih tujuan (1/2/3/4) : ");
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

        input("Pilih kelas pesawat (E/B/X) : ");
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
        input("Input jumlah penumpang : ");
        cin >> jml_pw;
        bayar_pw = jml_pw*harga_tkt;
        string nama_pw[jml_pw];
        int nm_pw_size = (sizeof(nama_pw)/sizeof(*nama_pw));

        for(int i=0; i<jml_pw; i++) {
            cout << "Nama penumpang ke-" << i+1 << " : ";
            cin >> nama_pw[i];
        }

        clear();
        goto paymentPw;

        paymentPw:
        header("Halaman Pembayaran Tiket Pesawat");
        cout << "Saldo E-Pay Anda : Rp. " << blc;
        endln(2);
        menuPayment();
        out(msg);
        input("Pilih metode pembayaran : ");
        cin >> mn_pay;

        if(mn_pay=="1") {
            if(blc>bayar_pw) {
                input("Masukan password Anda : ");
                cin >> pwd;
                if(pwd==re_pwd)
                {
                    out("Berhasil");
                    clear();
                } else
                {
                    msgPwd();
                    goto paymentPw;
                }
            } else {
                msgPayment();
                goto paymentPw;
            }
        } else if(mn_pay=="2") {

        }

    } else if(mn=="2") {
        clear();
        goto home;
    } else {
        msgMenuFalse();
        goto flight;
    }

    endln(2);
    input("Test");
    cin >> mn;

    // Halaman epay
    epay:
    header("Halaman E-Pay");
    cout << "Saldo Anda : Rp." << blc;

    menuEpay();
    out(msg);
    input("Pilih menu :");
    cin >> mn;

    if(mn == "1") {
        input("Jumlah topup saldo : Rp.");
        cin >> topup;
        input("Masukan password Anda : ");
        cin >> pwd;
        if(pwd==re_pwd) {
            blc += topup;
            msg = "Topup saldo berhasil";
            clear();
            goto epay;
        } else {
            msgPwd();
            goto epay;
        }
    } else if(mn=="2") {
        clear();
        goto home;
    } else {
        clear();
        goto epay;
    }

    return 0;
}
