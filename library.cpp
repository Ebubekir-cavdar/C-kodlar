#include <iostream>
#include <vector>
#include <algorithm> // For sorting

using namespace std;

vector<vector<string>> kutuphane;

void yeniOgrenci(string ogrNO, string adSoyad) {
    // Check if the student already exists
    for (const auto& ogrenci : kutuphane) {
        if (ogrenci[0] == ogrNO) {
            cout << "Bu ��renci zaten kay�tl�!" << endl;
            return;

        }
    }
    // Add the new student to the library records
    kutuphane.push_back({ogrNO, adSoyad});
    cout << "Yeni ��renci kayd� ba�ar�yla olu�turuldu." << endl;
}

void oduncKayit(string ogrenciNo, string kitapAdi) {
    // Check if the student exists
    bool studentFound = false;
    for (auto& ogrenci : kutuphane) {
        if (ogrenci[0] == ogrenciNo) {
            // Check if the book is already loaned to the student
            for (size_t i = 2; i < ogrenci.size(); ++i) {
                if (ogrenci[i] == kitapAdi) {
                    cout << "Bu kitap zaten ��rencide bulunuyor!" << endl;
                    return;
                }
            }
            // Add the book to the student's record
            ogrenci.push_back(kitapAdi);
            // Sort the books alphabetically for the student
            sort(ogrenci.begin() + 2, ogrenci.end());
            cout << "Kitap �d�n� verme i�lemi ba�ar�yla ger�ekle�tirildi." << endl;
            studentFound = true;
            break;
        }
    }
    if (!studentFound)
        cout << "��renci bulunamad�!" << endl;
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
                cout << "Kitap iade i�lemi ba�ar�yla ger�ekle�tirildi." << endl;
            } else {
                cout << "Bu ��rencide bu kitap bulunmuyor!" << endl;
            }
            studentFound = true;
            break;
        }
    }
    if (!studentFound)
        cout << "��renci bulunamad�!" << endl;
}

void rapor() {
    if (kutuphane.empty()) {
        cout << "K�t�phanede kay�tl� ��renci bulunmamaktad�r." << endl;
        return;
    }
    // Find the student who borrowed the most books
    auto mostBooksStudent = max_element(kutuphane.begin(), kutuphane.end(), [](const vector<string>& a, const vector<string>& b) {
        return a.size() < b.size();
    });
    cout << "�zerinde en �ok kitap bulunan ��renci: " << (*mostBooksStudent)[1] << " (" << (*mostBooksStudent)[0] << ")" << endl;

    // Find the student who borrowed the least books
    auto leastBooksStudent = min_element(kutuphane.begin(), kutuphane.end(), [](const vector<string>& a, const vector<string>& b) {
        return a.size() < b.size();
    });
    cout << "�zerinde en az kitap bulunan ��renci: " << (*leastBooksStudent)[1] << " (" << (*leastBooksStudent)[0] << ")" << endl;

    // Calculate the average number of books per student
    double totalBooks = 0;
    for (const auto& ogrenci : kutuphane) {
        totalBooks += ogrenci.size() - 2; // excluding student number and name
    }
    double averageBooksPerStudent = totalBooks / kutuphane.size();
    cout << "��renci ba��na al�nan ortalama kitap say�s�: " << averageBooksPerStudent << endl;
}

void tumKayitlariGoruntule() {
    if (kutuphane.empty()) {
        cout << "K�t�phanede kay�tl� ��renci bulunmamaktad�r." << endl;
        return;
    }
    cout << "T�m Kay�tlar:" << endl;
    for (const auto& ogrenci : kutuphane) {
        cout << "��renci No: " << ogrenci[0] << ", Ad Soyad: " << ogrenci[1] << ", Kitaplar:";
        for (size_t i = 2; i < ogrenci.size(); ++i) {
            cout << " " << ogrenci[i];
        }
        cout << endl;
    }
}

int main() {
    string secim, ogrNo, adSoyad, kitapAdi;
    while (true) {
        cout << "Yeni ��renci Eklemek ��in: 1\n";
        cout << "Kitap �d�n� Vermek ��in: 2\n";
        cout << "Kitap �adesi ��in: 3\n";
        cout << "Rapor Almak ��in: 4\n";
        cout << "T�m Kay�tlar� G�rmek i�in: 5\n";
        cout << "��k�� ��in: X\n";
        cout << "Yapmak istedi�iniz i�lemi se�iniz:";
        cin >> secim;

        if (secim == "1") {
            cout << "��rencinin Numaras�:";
            cin >> ogrNo;
            cout << "Ad Soyad:";
            cin.ignore();
            getline(cin, adSoyad);
            yeniOgrenci(ogrNo, adSoyad);
        } else if (secim == "2") {
            cout << "��rencinin Numaras�:";
            cin >> ogrNo;
            cout << "Kitap Ad�:";
            cin.ignore();
            getline(cin, kitapAdi);
            oduncKayit(ogrNo, kitapAdi);
        } else if (secim == "3") {
            cout << "��rencinin Numaras�:";
            cin >> ogrNo;
            cout << "Kitap Ad�:";
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
            cout << "L�tfen istenilen de�erlerden birini girin!...\n";
        }
    }
    return 0;
}

