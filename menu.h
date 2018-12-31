void menuHome() {
    out("\tDaftar Menu :");
    out("\t[1] Booking Tiket");
    out("\t[2] Keluar");
}

void menuDashboard() {
    endln(2);
    out("\tDaftar Menu :");
    out("\t[1] Tiket Pesawat");
    out("\t[2] Tiket Kereta");
    out("\t[3] Tiket Bioskop");
    out("\t[4] Tiket Event");
    out("\t[5] Saldo E-Pay");
    out("\t[6] Akun");
    out("\t[7] Logout");
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
