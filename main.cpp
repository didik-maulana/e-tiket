#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>

#include "style.h"
#include "menu.h"


using namespace std;

string username, new_username, pwd, re_pwd, new_pwd, msg;
int blc=0, topup;
int id, valKuota, isKuota;
char kls;
string mn, mn_pay, ct;
string fil, fil_tgl;
int fil_harga;
string fil_asal, fil_tujuan;
bool fil_cek;

// random
char c;
int r;

// flight
int psw_harga, psw_tj, psw_jml_tkt, psw_total;
string psw_kls;
struct Pesawat {
   string maskapai;
   string asal;
   string tujuan;
   string rute;
   string tgl;
   string jam_terbang;
   string jam_tiba;
   int kls_e;
   int kls_b;
   int kls_x;
   int kuota_e;
   int kuota_b;
   int kuota_x;
};

Pesawat psw[] =
{
    { "Garuda Indonesia", "Jakarta", "Denpasar", "CGK-DPS", "12-01-2019", "18.30", "20.00",  829000, 2048000, 10000000, 350, 18, 8 },
    { "Citilink", "Yogyakarta", "Jakarta", "JOG-CGK", "16-01-2019", "15.10", "16.15", 484000, 1243000, 80000000, 350, 18, 8 },
    { "Lion Air", "Surabaya", "Yogyakarta", "SUB-JOG", "18-01-2019", "21.00", "22.45", 737000, 4020000, 95000000, 350, 18, 8 },
    { "Garuda Indonesia", "Denpasar", "Surabaya", "DPS-SUB", "21-01-2018", "10.30", "11.15", 950000, 3610000, 15000000, 350, 18, 8 },
    { "Lion Air", "Makassar", "Yogyakarta", "UPG-JOG", "20-01-2019", "20.00", "21.00", 1200000, 4100000, 20000000, 350, 18, 8 },
    { "Garuda Indonesia", "Kendari", "Makassar", "KDI-UPG", "28-01-2019", "04.00", "05.35", 750000, 1810000, 7840000, 150, 38, 8 },
    { "Citilink", "Surakarta", "Yogyakarta", "SOC-JOG", "21-02-2019", "08.00", "08.45", 650000, 1610000, 9000000, 350, 18, 8 },
    { "Lion Air", "Surakarta", "Bandung", "SOC-BDO", "15-02-2019", "13.15", "14.00", 1000000, 1510000, 8700000, 350, 18, 8 }
};
int psw_size = sizeof(psw)/sizeof(*psw);

// train
int krt_harga, krt_tj, krt_jml_tkt, krt_total;
string krt_kls;
struct Kereta {
    string krt_nama;
    string asal;
    string tujuan;
    string rute;
    string tgl;
    string jam_berangkat;
    string jam_tiba;
    int kls_e;
    int kls_b;
    int kls_x;
    int kuota_e;
    int kuota_b;
    int kuota_x;
};

Kereta krt[] =
{
    { "Argo Parahyangan", "Jakarta", "Bandung", "GMR-BDG", "20-01-2019", "15.30", "18.30", 110000, 250000, 350000, 450, 200, 150 },
    { "Fajar Utama YK", "Jakarta", "Yogyakarta", "GMR-JOG", "17-01-2019", "21.30", "05.30", 250000, 350000, 425000, 500, 150, 100 },
    { "Argo Lawu", "Jakarta", "Solo", "GMR-SLO", "22-01-2019", "06.30", "14.30", 2600000, 370000, 440000, 400, 250, 150 },
    { "Argo Wilis", "Bandung", "Surabaya", "BDG-SBY", "20-01-2019", "15.30", "22.30", 200000, 285000, 360000, 400, 250, 150 },
    { "Bima", "Jakarta", "Malang", "PSE-MLG", "05-02-2019", "14.00", "23.00", 225000, 300000, 380000, 450, 250, 100 },
    { "Purwojaya", "Jakarta", "Purwokerto", "PSE-PWT", "10-02-2019", "09.00", "13.30", 170000, 220000, 3250000, 300, 250, 250 },
    { "Taksaka", "Jakarta", "Yogyakarta", "PSE-JOG", "29-01-2019", "13.00", "20.00", 190000, 300000, 410000, 250, 300, 250 },
    { "New Argo Jati", "Jakarta", "Cirebon", "GMR-CBN", "01-03-2019", "08.30", "18.30", 200000, 325000, 420000, 400, 250, 150 }
};
int krt_size = sizeof(krt)/sizeof(*krt);

// event
int ev, ev_pil, ev_jml_tkt, ev_total;
// array event
struct Event {
    string nama;
    string tgl;
    string tempat;
    int kuota;
    int htm;
};

Event event[] =
{
    { "Djakarta Warehouse Project", "07-02-2019", "GWK Bali", 1200, 950000 },
    { "Cold Play Concert Indonesia", "13-03-2019", "Stadion GBK, Jakarta", 6000, 700000 },
    { "JakCloth Year End Sale", "19-01-2019", "Parkir Timur Senayan, Jakarta", 1100, 250000 },
    { "International Education Expo", "04-02-2019", "Plaza Semanggi, Jakarta", 2000, 350000 },
    { "Jogja Hobbies Festival", "30-01-2019", "Jogja Expo Center, Yogyakarta", 1500, 400000 },
    { "Java Jazz", "17-02-2019", "Candi Borobudur, Magelang", 1000, 990000 },
    { "Ed Sheeran Tour Indonesia", "06-03-2019", "Istora Senayan, Jakarta", 3500, 900000 },
    { "Digital Startup Connect", "07-02-2019", "Balai Kartini, Jakarta", 1300,  100000  }
};
int ev_size = sizeof(event)/sizeof(*event);

struct Riwayat {
    int kode;
    string type;
    int total;
    string pay;
};
Riwayat riw[100];
int riw_size = sizeof(riw)/sizeof(*riw);
int idRiw;
int pay;

void addRiw() {
    idRiw+=1;
}

void printTiket(int kode, string type, int total, int type_pay) {
    string ket, pay;
    int id = idRiw;
    if(type=="psw") {
        ket = "Tiket Pesawat";
    } else if(type=="krt") {
        ket = "Tiket Kereta";
    } else {
        ket = "Tiket Event";
    }

    if(type_pay==1) {
        pay = "E-Payment";
    } else {
        pay = "Transfer Bank";
    }
    riw[id].kode = kode;
    riw[id].type = ket;
    riw[id].total = total;
    riw[id].pay = pay;
}

void showRiwayat() {
    for(int i=0; i<riw_size; i++) {
        if(riw[i].kode!=0) {
            cout << "Kode Transaksi     : PAY-" << riw[i].kode; endln(1);
            cout << "Pembelian          : " << riw[i].type; endln(1);
            cout << "Total Transaksi    : Rp. " << riw[i].total; endln(1);
            cout << "Metode Pembayaran  : " << riw[i].pay; endln(1);
            line1(70);
        }
    }
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

char randChar(int MAX) {
    int num=1;
    for (int i=0; i<num; i++)
    {
        r = rand() % MAX;
        c = 'A' + r;
        return c;
    }
}

int randInt(int MAX) {
    int n;
    n=1+(rand()%(MAX));
    return n;
}

void randTransaksi() {
    cout << "PAY-" << randInt(999);
}

void randTiket() {
    cout << "TKT-" << randChar(26) << "-" << randInt(999);
}

void inputPilihan(string tiket) {
    int size;
    string ket="rute";
    if(tiket=="pesawat") {
        size=psw_size;
    } else if(tiket=="kereta") {
        size=krt_size;
    } else {
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
    line2(70);
    if(kelas=="pesawat") {
        cout << "Rute       : " << psw[id].rute; endln(1);
        cout << "Asal       : " << psw[id].asal; endln(1);
        cout << "Tujuan     : " << psw[id].tujuan; endln(1);
        cout << "Maskapai   : " << psw[id].maskapai; endln(1);
        line2(70);
        tab(3); out("Harga"); line1(70);
        out("Ekonomi(E)     Bisnis(B)       Eksekutif(X)");
        line1(70);
        for(int i=0; i<1; i++) {
        cout << "Rp."
            << psw[id].kls_e
            << "     Rp."
            << psw[id].kls_b
            << "        Rp."
            << psw[id].kls_x; endln(1);
        }
        line2(70);
        tab(3); out("Kuota"); line1(70);
        out("Ekonomi(E)     Bisnis(B)       Eksekutif(X)");
        line1(70);
        for(int i=0; i<1; i++) {
        cout << "   "
            << psw[id].kuota_e
            << "             "
            << psw[id].kuota_b
            << "                "
            << psw[id].kuota_x; endln(1);
        }
    } else if(kelas=="kereta") {
        cout << "Kereta     : " << krt[id].krt_nama; endln(1);
        cout << "Rute       : " << krt[id].rute; endln(1);
        cout << "Asal       : " << krt[id].asal; endln(1);
        cout << "Tujuan     : " << krt[id].tujuan; endln(1);
        line2(70);
        tab(3); out("Harga"); line1(70);
        out("Ekonomi(E)     Bisnis(B)       Eksekutif(X)");
        line1(70);
        for(int i=0; i<1; i++) {
        cout << "Rp."
            << krt[id].kls_e
            << "     Rp."
            << krt[id].kls_b
            << "        Rp."
            << krt[id].kls_x;
            endln(1);
        }
        line2(70);
        tab(3); out("Kuota"); line1(70);
        out("Ekonomi(E)     Bisnis(B)       Eksekutif(X)");
        line1(70);
        for(int i=0; i<1; i++) {
        cout << "   "
            << krt[id].kuota_e
            << "             "
            << krt[id].kuota_b
            << "                "
            << krt[id].kuota_x; endln(1);
        }
    }
    line2(70); endln(1);
    cout << "\t> Pilih kelas " << kelas << "(E/B/X) : ";
}

void detailEvent(int t) {
    if(t==1) {
        cout << "  No. Transaksi   : PAY-" << idRiw; endln(1);
    }
    cout << "  Nama event      : " << event[id].nama; endln(1);
    cout << "  Tanggal         : " << event[id].tgl; endln(1);
    cout << "  Tempat          : " << event[id].tempat; endln(1);
    if(t==0) {
        cout << "  Kuota           : " << event[id].kuota; endln(1);
    }
    cout << "  HTM             : Rp. " << event[id].htm; endln(1);
    line1(70);
}

// validate kuota
int validateKuota(string type, int tkt_count) {
    int kuota_e, kuota_b, kuota_x;
    if(type=="psw") {
        kuota_e=psw[id].kuota_e;
        kuota_b=psw[id].kuota_b;
        kuota_x=psw[id].kuota_x;
    } else {
        kuota_e=krt[id].kuota_e;
        kuota_b=krt[id].kuota_b;
        kuota_x=krt[id].kuota_x;
    }
    if(tkt_count<1) {
        msgAlert("\t|X| Jumlah penumpang minimal 1!");
        return 0;
    } else {
        switch(kls) {
            case 'e': valKuota = kuota_e; break;
            case 'b': valKuota = kuota_b; break;
            case 'x': valKuota = kuota_x; break;
        }
        if(tkt_count>valKuota) {
            msgAlert("\t|X| Kuota tiket tidak cukup!");
            return 1;
        } else {
            return 2;
        }
    }
}

// payment menu
void onPayment(string type) {
    string ket;
    int total;
    if(type=="psw") {
        ket="Pesawat";
        total=psw_total;
    } else if(type=="krt") {
        ket="Kereta";
        total=krt_total;
    } else {
        ket="Event";
        total=ev_total;
    }
    header("Halaman Pembayaran Tiket "+ket);
    cout << "\tTotal pembayaran : Rp. " << total;
    endln(1);
    cout << "\tSaldo E-Pay Anda : Rp. " << blc;
    endln(2);
    menuPayment();
    out(msg);
    input("\tPilih metode pembayaran : ");
    cin >> mn_pay;
    if(mn_pay=="1") {
        if(blc>total) {
            pay=1;
            blc = blc-total;
            addRiw();
            printTiket(idRiw, type, total, pay);
            clear();
        } else {
            msgPayment();
            input("\t> Jumlah topup saldo : Rp.");
            cin >> topup;
            if(topup>100000) {
                input("\t> Masukan password Anda : ");
                cin >> pwd;
                if(pwd==re_pwd) {
                    blc += topup;
                    msgSuccess("\t|✔| Topup saldo berhasil");
                    onPayment(type);
                } else {
                    msgPwd();
                    onPayment(type);
                }
            } else {
                msgAlert("\t|X| Topup saldo minimal Rp.100000 !");
                onPayment(type);
            }
        }
    } else if(mn_pay=="2") {
        showTransferPay();
        input("\t  Lanjutkan pembayaran ? (Y/T) : ");
        cin >> ct;
        if(ct=="Y"||ct=="y") {
            pay=2;
            addRiw();
            printTiket(idRiw, type, total, pay);
            clear();
        } else if(ct=="T"||ct=="t") {
            clear();
            onPayment(type);
        } else {
            msgMenuFalse();
            onPayment(type);
        }
    } else {
        msgMenuFalse();
        onPayment(type);
    }
}

void filterData(string type, int i) {
    if(type=="psw") {
        cout << i+1
        << ".     "
        << psw[i].rute
        << "        "
        << psw[i].tgl
        << "         "
        << psw[i].jam_terbang
        << "         "
        << psw[i].jam_tiba;
    } else if(type=="krt") {
        cout << i+1
        << ".     "
        << krt[i].rute
        << "        "
        << krt[i].tgl
        << "            "
        << krt[i].jam_berangkat
        << "          "
        << krt[i].jam_tiba;
    } else {
        cout << i+1 << ".      "
        << event[i].tgl << "      Rp."
        << event[i].htm << "       "
        << event[i].nama;
    }
    endln(1);
}

void resetFilter() {
    fil="";
}

void resetData() {
    blc=0;
    idRiw=0;
    resetFilter();
    // reset riwayat
    for(int i; i<riw_size; i++) {
        riw[i].kode = 0;
        riw[i].type = "";
        riw[i].total = 0;
        riw[i].pay = "";
    }
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
        goto aplikasi;
    } else if(mn=="3") {
        clear();
        exit(0);
    } else {
        msgMenuFalse();
        goto home;
    }

    aplikasi:
    header("Halaman Aplikasi");
    detailApp();
    out(msg);
    input("\tPilih menu : "); cin >> mn;
    if(mn=="1") {
        clear();
        goto home;
    } else {
        msgMenuFalse();
        goto aplikasi;
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
    input("\t  > Konfirmasi Password : "); cin >> re_pwd;
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
    fil_cek=true;
    resetFilter();
    header("Halaman Dashboard");
    cout << "\tSelamat Datang " << username;
    menuDashboard();
    out(msg);
    input("\tPilih menu : ");
    cin >> mn;
    if(mn=="1") {
        clear();
        goto pesawat;
    } else if(mn=="2") {
        clear();
        goto krt;
    } else if(mn=="3") {
        clear();
        goto event;
    } else if(mn=="4") {
        clear();
        goto epay;
    } else if(mn=="5") {
        clear();
        goto profile;
    } else if(mn=="6") {
        clear();
        goto riwayat;
    } else if(mn=="7") {
        clear();
        resetData();
        goto home;
    }else {
        msgMenuFalse();
        goto dashboard;
    }

    // Halaman flight
    pesawat:
    header("Halaman Tiket Pesawat");
    endln(1);
    line2(70);
    out("                       DAFTAR PENERBANGAN           ");
    line2(70);
    out("No      Rute            Tanggal         Terbang        Tiba");
    line1(70);
    for(int i=0; i<psw_size; i++) {
        if(fil=="1") {
            if(psw[i].asal==fil_asal&&psw[i].tujuan==fil_tujuan) {
                filterData("psw", i);
                fil_cek=true;
            }
        } else if(fil=="2") {
            if(psw[i].tgl==fil_tgl) {
                filterData("psw", i);
                fil_cek=true;
            }
        } else {
            filterData("psw", i);
        }
    }

    /*if(!fil_cek) {
        tab(3); out("Penerbangan tidak tersedia");
    }*/
    menuTiket();
    out(msg);
    input("\tPilih Menu : "); cin >> mn;
    if(mn=="1") {
        endln(1);
        out("\t[1] Berdasarkan rute");
        out("\t[2] Berdasarkan tanggal");
        input("\tInput pilihan filter : "); cin >> fil;
        if(fil=="1") {
            input("\t  > Input kota asal    : "); cin>>fil_asal;
            input("\t  > Input kota tujuan  : "); cin>>fil_tujuan;
            clear();
            goto pesawat;
        } else if(fil=="2") {
            input("\t  > Input tanggal penerbangan (dd-mm-yyyy) : "); cin >> fil_tgl;
            clear();
            goto pesawat;
        } else {
            msgMenuFalse();
            goto pesawat;
        }
    } else if(mn=="2") {
        resetFilter();
        goto pesawat;
    } else if(mn=="3") {
        inputPilihan("pesawat");
        cin >> psw_tj;
        id=psw_tj-1;
        if(psw_tj>psw_size||psw_tj<1) {
            msgAlert("\t|X| Pilihan penerbangan tidak ada!");
            goto pesawat;
        }
        pilihKelas("pesawat");
        cin >> psw_kls;
        if(psw_kls=="E" || psw_kls=="e") {
            kls='e';
            psw_kls="Ekonomi (E)";
            psw_harga = psw[id].kls_e;
        } else if(psw_kls=="B" || psw_kls=="b") {
            kls='b';
            psw_kls="Bisnis (B)";
            psw_harga = psw[id].kls_b;
        } else if(psw_kls=="X" || psw_kls=="x") {
            kls='x';
            psw_kls="Eksekutif (X)";
            psw_harga = psw[id].kls_x;
        } else {
            msgAlert("\t|X| Kelas pesawat tidak tersedia!");
            goto pesawat;
        }
        input("\t> Input jumlah penumpang : ");
        cin >> psw_jml_tkt;
        isKuota=validateKuota("psw", psw_jml_tkt);
        if(isKuota==0) {
            goto pesawat;
        } else if(isKuota==1) {
            goto pesawat;
        }
        psw_total = psw_jml_tkt*psw_harga;
        string psw_penumpang[psw_jml_tkt];
        int psw_nama_size = (sizeof(psw_penumpang)/sizeof(*psw_penumpang));
        for(int i=0; i<psw_jml_tkt; i++) {
            cout << "\t  " << i+1 <<". Nama penumpang : ";
            cin >> psw_penumpang[i];
        }
        switch(kls) {
            case 'e': psw[id].kuota_e-=psw_jml_tkt; break;
            case 'b': psw[id].kuota_b-=psw_jml_tkt; break;
            case 'x': psw[id].kuota_x-=psw_jml_tkt; break;
        }
        clear();
        onPayment("psw");

        // Detail pemesanan pesawat
        orderPsw:
        header("Halaman Tiket Penerbangan");
        endln(1);
        line2(70);
        tab(3);
        out("TIKET PENERBANGAN");
        line2(70);
        cout << "  No. Transaksi  : PAY-" << idRiw; endln(1);
        line1(70);
        cout << "  Rute           : " << psw[id].rute; endln(1);
        cout << "  Penerbangan    : " << psw[id].asal+"-"+psw[id].tujuan; endln(1);
        cout << "  Maskapai       : " << psw[id].maskapai; endln(1);
        cout << "  Kelas          : " << psw_kls; endln(1);
        cout << "  Gerbang        : " << randChar(7) << randInt(12); endln(1);
        cout << "  Tanggal        : " << psw[id].tgl; endln(1);
        cout << "  Jam Terbang    : " << psw[id].jam_terbang; endln(1);
        cout << "  Jam Tiba       : " << psw[id].jam_tiba; endln(1);
        line1(70);
        out("  Nama penumpang :");
        for(int i=0; i<psw_nama_size; i++) {
            cout << "   " << i+1 << ". " << psw_penumpang[i]
                << "  ( No. Tiket : TKT-" << randChar(26) << "-" << randInt(999)
                << ", Kursi : " << randInt(350) << randChar(12) << ")";
                endln(1);
        }
        line1(70);
        cout << "  Harga tiket    : Rp. " << psw_harga; endln(1);
        cout << "  Jumlah tiket   : " << psw_jml_tkt; endln(1);
        cout << "  Total          : Rp. " << psw_total; endln(1);
        line1(70);
        endln(1);
        out(msg);
        input("\t> Pesan tiket pesawat lagi ? (Y/T) : ");
        cin >> mn;
        if(mn=="Y"||mn=="y") {
            clear();
            goto pesawat;
        } else if(mn=="T"||mn=="t") {
            clear();
            goto dashboard;
        } else {
            msgMenuFalse();
            goto orderPsw;
        }
    }  else if(mn=="4") {
        clear();
        goto dashboard;
    } else {
        msgMenuFalse();
        goto pesawat;
    }

    krt:
    header("Halaman Tiket Kereta");
    endln(1);
    line2(70);
    out("                           JADWAL KERETA API           ");
    line2(70);
    out("No      Rute            Tanggal           Berangkat        Tiba");
    line1(70);
    for(int i=0; i<krt_size; i++) {
        if(fil=="1") {
            if(krt[i].asal==fil_asal&&krt[i].tujuan==fil_tujuan) {
                filterData("krt", i);
                fil_cek=true;
            }
        } else if(fil=="2") {
            if(krt[i].tgl==fil_tgl) {
                filterData("krt", i);
                fil_cek=true;
            }
        } else {
            filterData("krt", i);
        }
    }

    /*if(!fil_cek) {
        tab(3); out("Penerbangan tidak tersedia");
    }*/
    menuTiket();
    out(msg);
    input("\tPilih Menu : "); cin >> mn;
    if(mn=="1") {
        endln(1);
        out("\t[1] Berdasarkan rute");
        out("\t[2] Berdasarkan tanggal");
        input("\tInput pilihan filter : "); cin >> fil;
        if(fil=="1") {
            input("\t  > Input kota asal    : "); cin>>fil_asal;
            input("\t  > Input kota tujuan  : "); cin>>fil_tujuan;
            clear();
            goto krt;
        } else if(fil=="2") {
            input("\t  > Input tanggal keberangkatan (dd-mm-yyyy) : "); cin >> fil_tgl;
            clear();
            goto krt;
        } else {
            msgMenuFalse();
            goto krt;
        }
    } else if(mn=="2") {
        resetFilter();
        goto krt;
    } else if(mn=="3") {
        inputPilihan("kereta");
        cin >> krt_tj;
        id=krt_tj-1;
        if(krt_tj>krt_size||krt_tj<1) {
            msgAlert("\t|X| Jadwal yang dipilih tidak tersedia!");
            goto krt;
        }
        pilihKelas("kereta");
        cin >> krt_kls;
        if(krt_kls=="E" || krt_kls=="e") {
            kls='e';
            krt_kls="Ekonomi (E)";
            krt_harga = krt[id].kls_e;
        } else if(krt_kls=="B" || krt_kls=="b") {
            kls='b';
            krt_kls="Bisnis (B)";
            krt_harga = krt[id].kls_b;
        } else if(krt_kls=="X" || krt_kls=="x") {
            kls='x';
            krt_kls="Eksekutif (X)";
            krt_harga = krt[id].kls_x;
        } else {
            msgAlert("\t|X| Kelas kereta tidak tersedia!");
            goto krt;
        }
        input("\t> Input jumlah penumpang : ");
        cin >> krt_jml_tkt;
        isKuota=validateKuota("krt", krt_jml_tkt);
        if(isKuota==0) {
            goto krt;
        } else if(isKuota==1) {
            goto krt;
        }
        krt_total = krt_jml_tkt*krt_harga;
        string nama_krt[krt_jml_tkt];
        int krt_nama_size = (sizeof(nama_krt)/sizeof(*nama_krt));
        for(int i=0; i<krt_jml_tkt; i++) {
            cout << "\t  " << i+1 <<". Nama penumpang : ";
            cin >> nama_krt[i];
        }
        switch(kls) {
            case 'e': krt[id].kuota_e-=krt_jml_tkt; break;
            case 'b': krt[id].kuota_b-=krt_jml_tkt; break;
            case 'x': krt[id].kuota_x-=krt_jml_tkt; break;
        }
        clear();
        onPayment("krt");

        // Detail pemesanan tiket kereta
        orderKrt:
        header("Halaman Tiket Kereta");
        endln(1);
        line2(70);
        tab(3); out("TIKET KERETA API");
        line2(70);
        cout << "  No. Transaksi  : PAY-" << idRiw; endln(1);
        line1(70);
        cout << "  Rute           : " << krt[id].rute; endln(1);
        cout << "  Perjalanan     : " << krt[id].asal << "-" << krt[id].tujuan; endln(1);
        cout << "  Kereta         : " << krt[id].krt_nama; endln(1);
        cout << "  Kelas          : " << krt_kls; endln(1);
        cout << "  Tanggal        : " << krt[id].tgl; endln(1);
        cout << "  Berangkat      : " << krt[id].jam_berangkat; endln(1);
        cout << "  Tiba           : " << krt[id].jam_tiba; endln(1);
        line1(70);
        out("  Nama penumpang :");
        for(int i=0; i<krt_nama_size; i++) {
            cout << "   " << i+1 << ". " << nama_krt[i]
                << "  ( No. Tiket : TKT-" << randChar(26) << "-" << randInt(999)
                << ", Kursi : " << randInt(450) << randChar(12) << ")";
                endln(1);
        }
        line1(70);
        cout << "  Harga tiket    : Rp. " << krt_harga; endln(1);
        cout << "  Jumlah tiket   : " << krt_jml_tkt; endln(1);
        cout << "  Total          : Rp. " << krt_total; endln(1);
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
    } else if(mn=="4") {
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
    tab(3); out("   DAFTAR EVENT");
    line2(70);
    out("Kode.    Tanggal           HTM          Nama Event");
    line1(70);
    for(int i=0; i<ev_size; i++) {
        if(fil=="1") {
            if(event[i].htm<=fil_harga) {
                filterData("ev", i);
                fil_cek=true;
            } else {
                fil_cek=false;
            }
        } else if(fil=="2") {
            if(event[i].tgl==fil_tgl) {
                filterData("ev", i);
                fil_cek=true;
            }
        } else {
            filterData("ev", i);
            fil_cek=true;
        }
    }

    /*if(!fil_cek) {
        tab(3); out("Event tidak tersedia");
    }*/
    menuTiket();
    out(msg);
    input("\tPilih Menu : "); cin >> mn;
    if(mn=="1") {
        endln(1);
        out("\t[1] Berdasarkan harga");
        out("\t[2] Berdasarkan tanggal");
        input("\tInput pilihan filter : "); cin >> fil;
        if(fil=="1") {
            input("\t  > Input budget anda : Rp. "); cin>>fil_harga;
            if(fil_harga<1) {
                msgAlert("\t|X| Filter harga harus diisi!");
                goto event;
            } else {
                clear();
                goto event;
            }
        } else if(fil=="2") {
            input("\t  > Input tanggal event (dd-mm-yyyy) : "); cin >> fil_tgl;
            clear();
            goto event;
        } else {
            msgMenuFalse();
            goto event;
        }
    } else if(mn=="2") {
        resetFilter();
        goto event;
    } else if(mn=="3") {
        inputPilihan("event");
        cin >> ev_pil;
        id = ev_pil-1;
        if(ev_pil > ev_size || ev_pil < 1) {
            msgAlert("\t|X| Event yang dipilih tidak tersedia!");
            goto event;
        }
        line1(70);
        tab(3); out("DETAIL EVENT");
        line1(70);
        detailEvent(0);
        input("\t> Input jumlah tiket : ");
        cin >> ev_jml_tkt;
        if(ev_jml_tkt > event[id].kuota) {
            msgAlert("\t|X| Jumlah tiket melebihi kuota !");
            goto event;
        } else if(ev_jml_tkt < 1) {
            msgAlert("\t|X| Pembelian tiket minimal 1 !");
            goto event;
        } else {
            ev_total=ev_jml_tkt*event[id].htm;
            event[id].kuota-=ev_jml_tkt;
            clear();
            goto paymentEvent;
        }

        paymentEvent:
        resetFilter();
        onPayment("ev");

        orderEvent:
        header("Halaman Tiket Event");
        endln(1);
        line2(70);
        tab(3); out("   TIKET EVENT");
        line2(70);
        detailEvent(1);
        for(int i=0; i<ev_jml_tkt; i++) {
            cout << "  No. Tiket ke-" << i+1 << "  : "; randTiket();
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
        resetFilter();
    } else if(mn=="4") {
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
        if(topup>100000) {
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
        } else {
            msgAlert("\t|X| Topup saldo minimal Rp.100000 !");
        }
    } else if(mn=="2") {
        clear();
        goto dashboard;
    } else {
        msgMenuFalse();
        goto epay;
    }

    riwayat:
    header("Halaman Riwayat Transaksi");
    showRiwayat();
    out("\tPilihan menu : ");
    out("\t[1]. Kembali");
    out(msg);
    input("\tPilih menu : "); cin >> mn;
    if(mn=="1") {
        clear();
        goto dashboard;
    } else {
        msgMenuFalse();
        goto riwayat;
    }

    return 0;
}
