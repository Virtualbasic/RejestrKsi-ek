#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class instancjaWyp {
public:
    int nr_wypozyczenia;
    string tytul;
    bool status;
    int ID_klienta;

    instancjaWyp(int nr_w, string t, bool stat, int id_k) : nr_wypozyczenia(nr_w), tytul(t), status(stat), ID_klienta(id_k) {}
};

instancjaWyp dodaj() {
    int nr_wypozyczenia;
    string tytul;
    bool status;
    int ID_klienta;

    cout << "nr_wypozyczenia: ";
    cin >> nr_wypozyczenia;

    cout << "tytul: ";
    cin.ignore();
    getline(cin, tytul);

    cout << "status (1 - wypożyczone, 0 - dostępne): ";
    cin >> status;

    cout << "ID_klienta: ";
    cin >> ID_klienta;

    return instancjaWyp(nr_wypozyczenia, tytul, status, ID_klienta);
}

void zapiszDoPliku(const instancjaWyp& nowaInstancja, const string& nazwaPliku) {
    ofstream plik(nazwaPliku, ios::app);

    if (plik.is_open()) {
        plik << "nr_wypozyczenia: " << nowaInstancja.nr_wypozyczenia << endl;
        plik << "tytul: " << nowaInstancja.tytul << endl;
        plik << "status: " << nowaInstancja.status << endl;
        plik << "ID_klienta: " << nowaInstancja.ID_klienta << endl;
        plik << "---------------------------" << endl; 

        cout << "Dodano nowy wpis do pliku: " << nazwaPliku << endl;
        plik.close();
    }
    else {
        cerr << "Nie można otworzyć pliku" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "");
    bool start = true;
    int temp = 0;
    ifstream plik("interface.txt");
    
    string linia;
    while (getline(plik, linia)) {
        cout << linia << endl;
    }

    plik.close();

    
    while (temp!=3) {
        cout << "wybierz tryp" << endl;
        cin >> temp;
        switch (temp) {
        case 3: {
            break;
            }
               
        case 1: {
            instancjaWyp nowaInstancja = dodaj();
            zapiszDoPliku(nowaInstancja, "Wypozyczenia.txt");
            temp = 0;
            break;
           }
               
        case 4: {
            ifstream rejestr("Wypozyczenia.txt");
            string rej;
            while (getline(rejestr, rej)) {
                cout << rej << endl;
            }
            temp = 0;
            rejestr.close();
            break;
        }
      }
                
    }
    return 0;
}