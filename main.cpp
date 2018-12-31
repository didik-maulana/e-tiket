#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "style.h"
#include "menu.h"


using namespace std;

string username, new_username, pwd, re_pwd, new_pwd, msg;
int blc=0, topup;
string mn, mn_pay, ct;
string fil;
int fil_min, fil_max;
bool fil_temp;

// random
char c;
int r;

// flight
int harga_psw, tj_psw, psw, jml_psw, bayar_psw;
string psw_kls;
string psw_rute[4] =
{
    "CGK-DPS",
    "JOG-CGK",
    "JOG-SUB",
    "KNO-JOG"
};
int psw_size = (sizeof(psw_rute)/sizeof(*psw_rute));

string psw_tgl[4] =
{
    "13-12-2018",
    "12-12-2018",
    "20-12-2018",
    "30-12-2018"
};

string psw_jam[4] =
{
    "18.30",
    "15.20",
    "20.00",
    "10.35"
};

int psw_e[4] =
{
    829000,
    484000,
    737000,
    950000
};

int psw_b[4] =
{
    2048000,
    1243000,
    4020000,
    3610000
};

int psw_x[4] =
{
    10000000,
    80000000,
    95000000,
    15000000
};

// train
int krt_harga, krt_tj, krt, jml_krt, bayar_krt;
string krt_kls;
string krt_nama[4] = {
    "Argo Parahyangan",
    "Fajar Utama YK",
    "Sawunggalih 123",
    "Argo Utama 70"
};

string krt_rute[4] =
{
    "GMR-BDG",
    "YOG-PWT",
    "PWT-JAK",
    "BDG-SMG"
};
int krt_size = (sizeof(krt_rute)/sizeof(*krt_rute));

string krt_tgl[4] =
{
    "14-01-2019",
    "16-01-2019",
    "18-01-2019",
    "21-01-2019"
};

string krt_jam[4] =
{
    "20.00",
    "19.30",
    "21.08",
    "17.35"
};

string krt_durasi[4] =
{
    "3j 14m",
    "2j 30m",
    "5j 10m",
    "7j 20m"
};
int krt_e[4] =
{
    110000,
    210000,
    300000,
    360000
};

int krt_b[4] =
{
    145000,
    225000,
    290000,
    390000
};

int krt_x[4] =
{
    160000,
    415000,
    450000,
    480000
};

// event
int ev, ev_pil, ev_jml_tkt, ev_total;
// array event
string ev_name[5] =
{
    "Djakarta Warehouse Project 2018",
    "JakCloth Year End Sale 2018",
    "International Education Expo 2018",
    "Digital Startup Connect 2018",
    "Jogja Hobbies Festival 2018"
};

int ev_size = sizeof(ev_name)/sizeof(*ev_name);

string ev_date[5]
{
    "7-12-2018",
    "19-12-2018",
    "4-08-2018",
    "7-12-2018",
    "30-11-2018"
};

int ev_kuota[5] {
    300,
    250,
    500,
    100,
    150
};

string ev_place[5]
{
    "GWK Bali",
    "Parkir Timur Senayan, Jakarta",
    "Plaza Semanggi, Jakarta",
    "Balai Kartini, Jakarta",
    "Jogja Expo Center, Yogyakarta"
};

int ev_htm[5]
{
    950000,
    250000,
    350000,
    200000,
    350000
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

void menuTiket(string type) {
    line2(70);
    endln(1);
    out("\tDaftar Menu :");
    out("\t[1] Filter");
    out("\t[2] Pesan tiket");
    out("\t[3] Kembali");
    out(msg);
    input("\tPilih Menu : ");
    cin >> mn;
}

void inputPilihan(string tiket) {
    int size;
    string ket="rute";
    if(tiket=="pesawat") {
        size=psw_size;
    } else if(tiket=="kereta") {
        size=krt_size;
    } else if(tiket=="film") {
        ket="film";
    } else if(tiket=="event") {
        size=ev_size;
        ket="event";
    }
    cout << "\tPilih " << ket << " (";
    for(int i=0; i<size; i++) {
        cout << i+1 << "/";
    }
    input(") : ");
}

void pilihKelas(string kelas) {
    endln(1);
    if(kelas=="pesawat") {
        cout << "Penerbangan : " << psw_rute[psw]; endln(1);
        out("Ekonomi(E)     Bisnis(B)       Eksekutif(X)");
        line1(70);
        for(int i=0; i<1; i++) {
        cout << "Rp."
            << psw_e[psw]
            << "     Rp."
            << psw_b[psw]
            << "        Rp."
            << psw_x[psw]; endln(1);
        }
    } else if(kelas=="kereta") {
        cout << "Rute       : " << krt_rute[krt]; endln(1);
        cout << "Kereta     : " << krt_nama[krt]; endln(1);
        line2(70);
        out("Ekonomi(E)     Bisnis(B)       Eksekutif(X)");
        line1(70);
        for(int i=0; i<1; i++) {
        cout << "Rp."
            << krt_e[krt]
            << "     Rp."
            << krt_b[krt]
            << "        Rp."
            << krt_x[krt];
            endln(1);
        }
    }
    line2(70); endln(1);
    cout << "\t> Pilih kelas " << kelas << "(E/B/X) : ";
}

void isiEvent(int i) {
    cout << i+1 << ".      "
        << ev_kuota[i] << "        "
        << ev_htm[i] << "       "
        << ev_name[i];
        endln(1);
}

void resetFilter() {
    fil="";
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
        goto psw;
    } else if(mn=="2") {
        clear();
        goto krt;
    } else if(mn=="4") {
        clear();
        goto event;
    } else if(mn=="5") {
        clear();
        goto epay;
    } else if(mn=="6") {
        clear();
        goto profile;
    } else if(mn=="7") {
        clear();
        goto home;
    } else {
        msgMenuFalse();
        goto dashboard;
    }

    // Halaman flight
    psw:
    header("Halaman Tiket Pesawat");
    endln(1);
    line2(70);
    out("                       DAFTAR PENERBANGAN           ");
    line2(70);
    out("No      Rute            Tanggal         Keberangkatan");
    line1(70);
    for(int i=0; i<psw_size; i++) {
        cout << i+1
        << ".     "
        << psw_rute[i]
        << "        "
        << psw_tgl[i]
        << "            "
        << psw_jam[i];
        endln(1);
    }
    menuTiket("pesawat");
    if(mn=="1") {
        inputPilihan("pesawat");
        cin >> tj_psw;
        psw=tj_psw-1;
        if(tj_psw>psw_size||tj_psw<1) {
            msgAlert("\t|X| Pilihan penerbangan tidak ada!");
            goto psw;
        }
        pilihKelas("pesawat");
        cin >> psw_kls;
        if(psw_kls=="E" || psw_kls=="e") {
            psw_kls="Ekonomi (E)";
            harga_psw = psw_e[psw];
        } else if(psw_kls=="B" || psw_kls=="b") {
            psw_kls="Bisnis (B)";
            harga_psw = psw_b[psw];
        } else if(psw_kls=="X" || psw_kls=="x") {
            psw_kls="Eksekutif (X)";
            harga_psw = psw_x[psw];
        } else {
            msgAlert("\t|X| Kelas pesawat tidak tersedia!");
            goto psw;
        }
        input("\t> Input jumlah penumpang : ");
        cin >> jml_psw;
        if(jml_psw<1) {
            msgAlert("\t|X| Jumlah penumpang minimal 1!");
            goto psw;
        }
        bayar_psw = jml_psw*harga_psw;
        string nama_psw[jml_psw];
        int psw_nama_size = (sizeof(nama_psw)/sizeof(*nama_psw));
        for(int i=0; i<jml_psw; i++) {
            cout << "\t  " << i+1 <<". Nama penumpang : ";
            cin >> nama_psw[i];
        }
        clear();
        goto paymentPsw;

        paymentPsw:
        header("Halaman Pembayaran Tiket Pesawat");
        cout << "\tTotal pembayaran : Rp. " << bayar_psw;
        endln(1);
        cout << "\tSaldo E-Pay Anda : Rp. " << blc;
        endln(2);
        menuPayment();
        out(msg);
        input("\tPilih metode pembayaran : ");
        cin >> mn_pay;
        if(mn_pay=="1") {
            if(blc>bayar_psw) {
                blc = blc-bayar_psw;
                clear();
                goto orderPsw;
            } else {
                msgPayment();
                input("\t> Jumlah topup saldo : Rp.");
                cin >> topup;
                input("\t> Masukan password Anda : ");
                cin >> pwd;
                if(pwd==re_pwd) {
                    blc += topup;
                    msgSuccess("\t|✔| Topup saldo berhasil");
                    goto paymentPsw;
                } else {
                    msgPwd();
                    goto paymentPsw;
                }
            }
        } else if(mn_pay=="2") {
            showTransferPay();
            input("\t  Lanjutkan pembayaran ? (Y/T) : ");
            cin >> ct;
            if(ct=="Y"||ct=="y") {
                clear();
                goto orderPsw;
            } else if(ct=="T"||ct=="t") {
                clear();
                goto paymentPsw;
            } else {
                msgMenuFalse();
                goto paymentPsw;
            }
        } else {
            msgMenuFalse();
            goto paymentPsw;
        }
        // Detail pemesanan pesawat
        orderPsw:
        header("Halaman Tiket Penerbangan");
        endln(1);
        line2(70);
        tab(3);
        out("TIKET PENERBANGAN");
        line2(70);
        cout << "  No. Tiket      : "; randomTiket();
        endln(1);
        line1(70);
        cout << "  Penerbangan    : " << psw_rute[psw];
        endln(1);
        cout << "  Kelas          : " << psw_kls;
        endln(1);
        cout << "  Gerbang        : " << randomChar() << randomInt();
        endln(1);
        cout << "  Tanggal        : " << psw_tgl[psw];
        endln(1);
        cout << "  Waktu          : " << psw_jam[psw];
        endln(1);
        line1(70);
        out("  Nama penumpang :");
        for(int i=0; i<psw_nama_size; i++) {
            cout << "   " << i+1 << ". " << nama_psw[i]
            << "  (" << randomInt() << "-" << randomChar() << ")";
            endln(1);
        }
        line1(70);
        cout << "  Harga tiket    : Rp. " << harga_psw; endln(1);
        cout << "  Jumlah tiket   : " << jml_psw; endln(1);
        cout << "  Total          : Rp. " << bayar_psw; endln(1);
        line1(70);
        endln(1);
        out(msg);
        input("\t> Pesan tiket pesawat lagi ? (Y/T) : ");
        cin >> mn;
        if(mn=="Y"||mn=="y") {
            clear();
            goto psw;
        } else if(mn=="T"||mn=="t") {
            clear();
            goto dashboard;
        } else {
            msgMenuFalse();
            goto orderPsw;
        }
    } else if(mn=="2") {
        clear();
        goto dashboard;
    } else {
        msgMenuFalse();
        goto psw;
    }

    krt:
    header("Halaman Tiket Kereta");
    endln(1);
    line2(70);
    out("                           JADWAL KERETA API           ");
    line2(70);
    out("No      Rute            Tanggal         Keberangkatan      Durasi");
    line1(70);
    for(int i=0; i<krt_size; i++) {
        cout << i+1
        << ".     "
        << krt_rute[i]
        << "        "
        << krt_tgl[i]
        << "            "
        << krt_jam[i]
        << "          "
        << krt_durasi[i];
        endln(1);
    }
    menuTiket("kereta");
    if(mn=="1") {
        inputPilihan("kereta");
        cin >> krt_tj;
        krt=krt_tj-1;
        if(krt_tj>krt_size||krt_tj<1) {
            msgAlert("\t|X| Jadwal yang dipilih tidak tersedia!");
            goto krt;
        }
        pilihKelas("kereta");
        cin >> krt_kls;
        if(krt_kls=="E" || krt_kls=="e") {
            krt_kls="Ekonomi (E)";
            krt_harga = krt_e[krt];
        } else if(krt_kls=="B" || krt_kls=="b") {
            krt_kls="Bisnis (B)";
            krt_harga = krt_b[krt];
        } else if(krt_kls=="X" || krt_kls=="x") {
            krt_kls="Eksekutif (X)";
            krt_harga = krt_x[krt];
        } else {
            msgAlert("\t|X| Kelas kereta tidak tersedia!");
            goto krt;
        }
        input("\t> Input jumlah penumpang : ");
        cin >> jml_krt;
        if(jml_krt<1) {
            msgAlert("\t|X| Jumlah penumpang minimal 1!");
            goto krt;
        }
        bayar_krt = jml_krt*krt_harga;
        string nama_krt[jml_krt];
        int krt_nama_size = (sizeof(nama_krt)/sizeof(*nama_krt));
        for(int i=0; i<jml_krt; i++) {
            cout << "\t  " << i+1 <<". Nama penumpang : ";
            cin >> nama_krt[i];
        }
        clear();
        goto paymentKrt;

        paymentKrt:
        header("Halaman Pembayaran Tiket Kereta");
        cout << "\tTotal pembayaran : Rp. " << bayar_krt;
        endln(1);
        cout << "\tSaldo E-Pay Anda : Rp. " << blc;
        endln(2);
        menuPayment();
        out(msg);
        input("\tPilih metode pembayaran : ");
        cin >> mn_pay;
        if(mn_pay=="1") {
            if(blc>bayar_krt) {
                blc=blc-bayar_krt;
                clear();
                goto orderKrt;
            } else {
                msgPayment();
                input("\t> Jumlah topup saldo : Rp.");
                cin >> topup;
                input("\t> Masukan password Anda : ");
                cin >> pwd;
                if(pwd==re_pwd) {
                    blc += topup;
                    msgSuccess("\t|✔| Topup saldo berhasil");
                    goto paymentKrt;
                } else {
                    msgPwd();
                    goto paymentKrt;
                }
            }
        } else if(mn_pay=="2") {
            showTransferPay();
            input("\t  Lanjutkan pembayaran ? (Y/T) : ");
            cin >> ct;
            if(ct=="Y"||ct=="y") {
                clear();
                goto orderKrt;
            } else if(ct=="T"||ct=="t") {
                clear();
                goto paymentKrt;
            } else {
                msgMenuFalse();
                goto paymentKrt;
            }
        } else {
            msgMenuFalse();
            goto paymentKrt;
        }
        // Detail pemesanan tiket kereta
        orderKrt:
        header("Halaman Tiket Kereta");
        endln(1);
        line2(70);
        tab(3); out("TIKET KERETA API");
        line2(70);
        cout << "  No. Tiket      : "; randomTiket(); endln(1);
        line1(70);
        cout << "  Rute           : " << krt_rute[krt]; endln(1);
        cout << "  Kereta         : " << krt_nama[krt]; endln(1);
        cout << "  Kelas          : " << krt_kls; endln(1);
        cout << "  Tanggal        : " << krt_tgl[krt]; endln(1);
        cout << "  Waktu          : " << krt_jam[krt]; endln(1);
        cout << "  Durasi         : " << krt_durasi[krt]; endln(1);
        line1(70);
        out("  Nama penumpang :");
        for(int i=0; i<krt_nama_size; i++) {
            cout << "   " << i+1 << ". " << nama_krt[i]
            << "  (" << randomInt() << "-" << randomChar() << ")";
            endln(1);
        }
        line1(70);
        cout << "  Harga tiket    : Rp. " << krt_harga; endln(1);
        cout << "  Jumlah tiket   : " << jml_krt; endln(1);
        cout << "  Total          : Rp. " << bayar_krt; endln(1);
        line1(70); endln(1);
        out(msg);
        input("\t> Pesan tiket kereta lagi ? (Y/T) : "); cin >> mn;
        if(mn=="Y"||mn=="y") {
            clear();
            goto krt;
        } else if(mn=="T"||mn=="t") {
            clear();
            goto dashboard;
        } else {
            msgMenuFalse();
            goto orderKrt;
        }
    } else if(mn=="2") {
        clear();
        goto dashboard;
    } else {
        msgMenuFalse();
        goto krt;
    }

    // Halaman event
    event:
    header("Halaman Tiket Event");
    endln(1);
    line2(70);
    tab(3);
    out("   DAFTAR EVENT");
    line2(70);
    out("Kode.    Kuota        HTM          Nama Event");
    line1(70);
    for(int i=0; i<ev_size; i++) {
        if(fil=="1") {
            if(ev_htm[i]>=fil_min && ev_htm[i]<=fil_max) {
                isiEvent(i);
            } else {
                fil_temp=false;
            }
        } else {
            isiEvent(i);
        }
    }

    if(fil_temp==false) {
        tab(3); ("Event tidak tersedia");
    }
    menuTiket("event");
    if(mn=="1") {
        out("\t[1] Berdasarkan harga");
        out("\t[2] Berdasarkan tanggal");
        out("\t[3] Berdasarkan nama");
        input("\tInput pilihan filter : "); cin >> fil;
        if(fil=="1") {
            input("\t  > Input harga terendah  : "); cin>>fil_min;
            input("\t  > Input harga tertinggi : "); cin>>fil_max;
            if(fil_max<fil_min) {
                msgAlert("\t|X| Inputan harga tidak sesuai!");
                goto event;
            } else {
                clear();
                goto event;
            }
        }
    }else if(mn=="2") {
        inputPilihan("event");
        cin >> ev_pil;
        ev = ev_pil-1;
        if(ev_pil > ev_size || ev_pil < 1) {
            msgAlert("\t|X| Event yang dipilih tidak tersedia!");
            goto event;
        }
        input("\t> Input jumlah tiket : ");
        cin >> ev_jml_tkt;
        if(ev_jml_tkt > ev_kuota[ev]) {
            msgAlert("\t|X| Jumlah tiket melebihi kuota !");
            goto event;
        } else {
            ev_total=ev_jml_tkt*ev_htm[ev];
            clear();
            goto paymentEvent;
        }

        paymentEvent:
        header("Halaman Pembayaran Tiket Event");
        endln(1);
        cout << "\tTotal pembayaran : Rp. " << ev_total;
        endln(1);
        cout << "\tSaldo E-Pay Anda : Rp. " << blc;
        endln(2);
        menuPayment();
        out(msg);
        input("\tPilih metode pembayaran : ");
        cin >> mn_pay;
        if(mn_pay=="1") {
            if(blc>ev_total) {
                blc=blc-ev_total;
                clear();
                goto orderEvent;
            } else {
                msgPayment();
                input("\t> Jumlah topup saldo : Rp.");
                cin >> topup;
                input("\t> Masukan password Anda : ");
                cin >> pwd;
                if(pwd==re_pwd) {
                    blc += topup;
                    msgSuccess("\t|✔| Topup saldo berhasil");
                    goto paymentEvent;
                } else {
                    msgPwd();
                    goto paymentEvent;
                }
            }
        } else if(mn_pay=="2") {
            showTransferPay();
            input("\t  Lanjutkan pembayaran ? (Y/T) : ");
            cin >> ct;
            if(ct=="Y"||ct=="y") {
                clear();
                goto orderEvent;
            } else if(ct=="T"||ct=="t") {
                clear();
                goto paymentEvent;
            } else {
                msgMenuFalse();
                goto paymentEvent;
            }
        } else {
            msgMenuFalse();
            goto paymentEvent;
        }

        orderEvent:
        header("Halaman Tiket Event");
        endln(1);
        line2(70);
        tab(3); out("   TIKET EVENT");
        line2(70);
        cout << "  Nama Event     : " << ev_name[ev]; endln(1);
        cout << "  Tanggal        : " << ev_date[ev]; endln(1);
        cout << "  Tempat         : " << ev_place[ev]; endln(1);
        cout << "  HTM            : Rp. " << ev_htm[ev]; endln(1);
        line1(70);
        for(int i=0; i<ev_jml_tkt; i++) {
            cout << "  No. Tiket ke-" << i+1 << " : "; randomTiket();
            endln(1);
        }
        line1(70);
        cout << "  Jumlah tiket     : " << ev_jml_tkt; endln(1);
        cout << "  Total pembayaran : Rp. " << ev_total; endln(1);
        line1(70); endln(1);
        out(msg);
        input("\t> Pesan tiket event lagi ? (Y/T) : "); cin >> mn;
        if(mn=="Y"||mn=="y") {
            clear();
            goto event;
        } else if(mn=="T"||mn=="t") {
            clear();
            goto dashboard;
        } else {
            msgMenuFalse();
            goto orderEvent;
        }
        resetFilter;
    } else if(mn=="2") {
        clear();
        goto dashboard;
    } else {
        msgMenuFalse();
        goto event;
    }

    // Halaman profile
    profile:
    header("Halaman Akun Profile");
    tab(1); line1(40);
    cout << "\tUsername     : " << username; endln(1);
    cout << "\tPassword     : " << pwd; endln(1);
    tab(1); line1(40);
    menuProfile();
    out(msg);
    input("\tPilih menu : "); cin >> mn;
    if(mn=="1") {
        input("\t> Username yang baru : "); cin >> new_username;
        input("\t> Masukan password Anda : "); cin >> pwd;
        if(pwd==re_pwd) {
            username = new_username;
            msgSuccess("\t|✔| Username berhasil diupdate");
            goto profile;
        } else {
            msgPwd();
            goto profile;
        }
    } else if(mn=="2") {
        input("\t> Password yang baru : "); cin >> new_pwd;
        input("\t> Masukan password yang lama : "); cin >> pwd;
        if(pwd==re_pwd) {
            pwd = new_pwd;
            msgSuccess("\t|✔| Password berhasil diupdate");
            goto profile;
        } else {
            msgPwd();
            goto profile;
        }
    } else if(mn=="3") {
        clear();
        goto dashboard;
    } else {
        msgMenuFalse();
        goto profile;
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
            msgSuccess("\t|✔| Topup saldo berhasil");
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
