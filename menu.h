void detailApp() {
    out("\tE-Tiket merupakan aplikasi penyedia layanan pemesanan tiket");
    out("\tpesawat, kereta, dan event secara daring yang berfokus pada");
    out("\tlayanan lokal.");
    endln(1);
    out("\tTeam Pengembang : ");
    out("\t1. Adhit     : Project Documentation");
    out("\t2. Didik     : Programmer");
    out("\t3. Fauzan    : Data Engineer");
    out("\t4. Randa     : Software QA");
    endln(1);
    out("\tPilihan menu : ");
    out("\t[1]. Kembali");
}

void menuHome() {
    out("\tDaftar Menu :");
    out("\t[1] Booking Tiket");
    out("\t[2] Tentang Kami");
    out("\t[3] Keluar");
}

void menuDashboard() {
    endln(2);
    out("\tDaftar Menu :");
    out("\t[1] Tiket Pesawat");
    out("\t[2] Tiket Kereta");
    out("\t[3] Tiket Event");
    out("\t[4] Saldo E-Pay");
    out("\t[5] Akun");
    out("\t[6] Riwayat Transaksi");
    out("\t[7] Logout");
}

void menuTiket() {
    line2(70);
    endln(1);
    out("\tDaftar Menu :");
    out("\t[1] Filter");
    out("\t[2] Refresh");
    out("\t[3] Pesan tiket");
    out("\t[4] Kembali");
}

void menuPayment() {
    out("\tMenu pembayaran :");
    out("\t[1] E-Pay");
    out("\t[2] Transfer");
}

void menuProfile() {
    endln(1);
    out("\tDaftar Menu :");
    out("\t[1] Ganti username");
    out("\t[2] Ganti password");
    out("\t[3] Kembali");
}

void menuEpay() {
    endln(2);
    out("\tDaftar Menu :");
    out("\t[1] Topup saldo");
    out("\t[2] Kembali");
}

void showTransferPay() {
    endln(1);
    out("\tSilahkkan transfer pada salah satu virtual account");
    out("\t*) verifikasi otomatis setelah transfer dilakukan");
    endln(1);
    input("\t  > Bank BCA     : 891083863658915"); endln(1);
    input("\t  > Bank Mandiri : 892056982116894"); endln(1);
    input("\t  > Bank BRI     : 893065854224012"); endln(1);
}
