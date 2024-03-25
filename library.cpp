#include <iostream>
#include <vector>
#include <algorithm> // For sorting

using namespace std;

vector<vector<string>> kutuphane;

void yeniOgrenci(string ogrNO, string adSoyad) {
    // Check if the student already exists
    for (const auto& ogrenci : kutuphane) {
        if (ogrenci[0] == ogrNO) {
            cout << "Bu öðrenci zaten kayýtlý!" << endl;
            return;

        }
    }
    // Add the new student to the library records
    kutuphane.push_back({ogrNO, adSoyad});
    cout << "Yeni öðrenci kaydý baþarýyla oluþturuldu." << endl;
}

void oduncKayit(string ogrenciNo, string kitapAdi) {
    // Check if the student exists
    bool studentFound = false;
    for (auto& ogrenci : kutuphane) {
        if (ogrenci[0] == ogrenciNo) {
            // Check if the book is already loaned to the student
            for (size_t i = 2; i < ogrenci.size(); ++i) {
                if (ogrenci[i] == kitapAdi) {
                    cout << "Bu kitap zaten öðrencide bulunuyor!" << endl;
                    return;
                }
            }
            // Add the book to the student's record
            ogrenci.push_back(kitapAdi);
            // Sort the books alphabetically for the student
            sort(ogrenci.begin() + 2, ogrenci.end());
            cout << "Kitap ödünç verme iþlemi baþarýyla gerçekleþtirildi." << endl;
            studentFound = true;
            break;
        }
    }
    if (!studentFound)
        cout << "Öðrenci bulunamadý!" << endl;
}

void kitapIade(string ogrNo, string kitapAdi) {
    // Check if the student exists
    bool studentFound = false;
    for (auto& ogrenci : kutuphane) {
        if (ogrenci[0] == ogrNo) {
            // Check if the student has the book
            auto it = find(ogrenci.begin() + 2, ogrenci.end(), kitapAdi);
            if (it != ogrenci.end()) {
                ogrenci.erase(it);
                cout << "Kitap iade iþlemi baþarýyla gerçekleþtirildi." << endl;
            } else {
                cout << "Bu öðrencide bu kitap bulunmuyor!" << endl;
            }
            studentFound = true;
            break;
        }
    }
    if (!studentFound)
        cout << "Öðrenci bulunamadý!" << endl;
}

void rapor() {
    if (kutuphane.empty()) {
        cout << "Kütüphanede kayýtlý öðrenci bulunmamaktadýr." << endl;
        return;
    }
    // Find the student who borrowed the most books
    auto mostBooksStudent = max_element(kutuphane.begin(), kutuphane.end(), [](const vector<string>& a, const vector<string>& b) {
        return a.size() < b.size();
    });
    cout << "Üzerinde en çok kitap bulunan öðrenci: " << (*mostBooksStudent)[1] << " (" << (*mostBooksStudent)[0] << ")" << endl;

    // Find the student who borrowed the least books
    auto leastBooksStudent = min_element(kutuphane.begin(), kutuphane.end(), [](const vector<string>& a, const vector<string>& b) {
        return a.size() < b.size();
    });
    cout << "Üzerinde en az kitap bulunan öðrenci: " << (*leastBooksStudent)[1] << " (" << (*leastBooksStudent)[0] << ")" << endl;

    // Calculate the average number of books per student
    double totalBooks = 0;
    for (const auto& ogrenci : kutuphane) {
        totalBooks += ogrenci.size() - 2; // excluding student number and name
    }
    double averageBooksPerStudent = totalBooks / kutuphane.size();
    cout << "Öðrenci baþýna alýnan ortalama kitap sayýsý: " << averageBooksPerStudent << endl;
}

void tumKayitlariGoruntule() {
    if (kutuphane.empty()) {
        cout << "Kütüphanede kayýtlý öðrenci bulunmamaktadýr." << endl;
        return;
    }
    cout << "Tüm Kayýtlar:" << endl;
    for (const auto& ogrenci : kutuphane) {
        cout << "Öðrenci No: " << ogrenci[0] << ", Ad Soyad: " << ogrenci[1] << ", Kitaplar:";
        for (size_t i = 2; i < ogrenci.size(); ++i) {
            cout << " " << ogrenci[i];
        }
        cout << endl;
    }
}

int main() {
    string secim, ogrNo, adSoyad, kitapAdi;
    while (true) {
        cout << "Yeni Öðrenci Eklemek Ýçin: 1\n";
        cout << "Kitap Ödünç Vermek Ýçin: 2\n";
        cout << "Kitap Ýadesi Ýçin: 3\n";
        cout << "Rapor Almak Ýçin: 4\n";
        cout << "Tüm Kayýtlarý Görmek için: 5\n";
        cout << "Çýkýþ Ýçin: X\n";
        cout << "Yapmak istediðiniz iþlemi seçiniz:";
        cin >> secim;

        if (secim == "1") {
            cout << "Öðrencinin Numarasý:";
            cin >> ogrNo;
            cout << "Ad Soyad:";
            cin.ignore();
            getline(cin, adSoyad);
            yeniOgrenci(ogrNo, adSoyad);
        } else if (secim == "2") {
            cout << "Öðrencinin Numarasý:";
            cin >> ogrNo;
            cout << "Kitap Adý:";
            cin.ignore();
            getline(cin, kitapAdi);
            oduncKayit(ogrNo, kitapAdi);
        } else if (secim == "3") {
            cout << "Öðrencinin Numarasý:";
            cin >> ogrNo;
            cout << "Kitap Adý:";
            cin.ignore();
            getline(cin, kitapAdi);
            kitapIade(ogrNo, kitapAdi);
        } else if (secim == "4") {
            rapor();
        } else if (secim == "5") {
                        tumKayitlariGoruntule();
        } else if (secim == "X" || secim == "x") {
            break;
        } else {
            cout << "Lütfen istenilen deðerlerden birini girin!...\n";
        }
    }
    return 0;
}

