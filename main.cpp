#include <iostream>
#include <string>
using namespace std;

class Thisinh
{
private:
    string ten;
    float toan, ly, hoa, tong;

public:
    void setThiSinh()
    {
        cout << "----------\n";
        cout << "Nhap ten thi sinh:";
        cin.ignore();
        getline(cin, ten);
        cout << endl;
        cout << "Nhap lan luot diem toan, ly, hoa.\n";
        cout << "Diem toan: ";
        cin >> toan;
        cout << "Diem ly: ";
        cin >> ly;
        cout << "Diem hoa: ";
        cin >> hoa;
        cout << "---------\n";
    }
    string getTen()
    {
        return ten;
    }
    float getToan() { return toan; }
    float getLy() { return ly; }
    float getHoa() { return hoa; }
    void tongDiem() { tong = toan + ly + hoa; }
    float getTong()
    {
        tongDiem();
        return tong;
    }
    void printThiSinh()
    {
        cout << "Ten: " << ten << '\n'
             << "Co tong diem la: " << tong << '\n'
             << "Diem chi tiet: Toan: " << toan
             << ", Ly: " << ly << ", Hoa: " << hoa << '\n';
    }
    bool isKhongChe() // tong >= 15 va co 1 mon === 0
    {
        return tong >= 15 && (toan == 0 || ly == 0 || hoa == 0);
    }
};

Thisinh &findMaxTongDiem(Thisinh *listThiSinh, int numberOfThiSinh)
{
    int indexMax = 0;
    for (int i = 1; i < numberOfThiSinh; i++)
    {
        if (listThiSinh[i].getTong() > listThiSinh[indexMax].getTong())
            indexMax = i;
    }
    return listThiSinh[indexMax];
}

void swap(Thisinh &a, Thisinh &b)
{
    Thisinh temp = a;
    a = b;
    b = temp;
}

int main()
{
    cout << "Testing";
    Thisinh *listThiSinh;
    cout << "Nhap so luong thi sinh: ";
    int numberOfThiSinh;
    cin >> numberOfThiSinh;
    if (numberOfThiSinh <= 0)
    {
        throw out_of_range("");
    }

    listThiSinh = new Thisinh[numberOfThiSinh];
    cout << "Nhap lan luot tung thi sinh:\n";
    for (int i = 0; i < numberOfThiSinh; i++)
    {
        // cin.clear();
        listThiSinh[i].setThiSinh();
    }

    // Tinh tong diem
    for (int i = 0; i < numberOfThiSinh; i++)
    {
        listThiSinh[i].tongDiem();
    }

    // Get max tongdiem
    Thisinh &thiSinhMaxTongDiem = findMaxTongDiem(listThiSinh, numberOfThiSinh);
    cout << "\n\n";
    cout << "Thi sinh co tong diem cao nhat:\n";
    thiSinhMaxTongDiem.printThiSinh();
    // In ra thi sinh bi khong che
    cout << "\n\n";
    cout << "Thi sinh bi khong che la:\n";
    for (int i = 0; i < numberOfThiSinh; i++)
    {
        if (listThiSinh[i].isKhongChe())
            listThiSinh[i].printThiSinh();
    }
    for (int i = 1; i < numberOfThiSinh; i++)
        for (int j = 0; j < i; j++)
        {
            if (listThiSinh[i].getTong() > listThiSinh[j].getTong())
                swap(listThiSinh[i], listThiSinh[j]);
        }
    // in ra danh sach thi sinh co tong diem giam dan
    cout << "\n\n";
    cout << "Danh sach thi sinh theo thu tu diem tong giam dan:\n";
    for (int i = 0; i < numberOfThiSinh; i++)
    {
        cout << i + 1 << ".\n";
        listThiSinh[i].printThiSinh();
    }
    delete[] listThiSinh;
    return 0;
}