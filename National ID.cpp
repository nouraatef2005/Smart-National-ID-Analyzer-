#include <iostream>
#include <string>

using namespace std;

int convert(string s) {
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        num = num * 10 + (s[i] - '0');
    }
    return num;
}

bool isValidID(string id) {
    if (id.length() != 14) return false;

    for (int i = 0; i < 14; i++) {
        if (id[i] < '0' || id[i] > '9') return false; 
    }

    if (id[0] != '2' && id[0] != '3') return false;

    int month = convert(id.substr(3, 2));
    int day = convert(id.substr(5, 2));

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    return true;
}

int main() {
    string id;
    string governorates[89];

    for (int i = 0; i < 89; i++) governorates[i] = "Unknown";

    
    governorates[1] = "Cairo";
    governorates[2] = "Alexandria";
    governorates[3] = "Port Said";
    governorates[4] = "Suez";
    governorates[11] = "Damietta";
    governorates[12] = "Dakahlia";
    governorates[13] = "Sharqia";
    governorates[14] = "Qalyubia";
    governorates[15] = "Kafr El Sheikh";
    governorates[16] = "Gharbia";
    governorates[17] = "Monufia";
    governorates[18] = "Beheira";
    governorates[19] = "Ismailia";
    governorates[21] = "Giza";
    governorates[22] = "Beni Suef";
    governorates[23] = "Fayoum";
    governorates[24] = "Minya";
    governorates[25] = "Assyut";
    governorates[26] = "Sohag";
    governorates[27] = "Qena";
    governorates[28] = "Aswan";
    governorates[29] = "Luxor";
    governorates[31] = "Red Sea";
    governorates[32] = "New Valley";
    governorates[33] = "Matrouh";
    governorates[34] = "North Sinai";
    governorates[35] = "South Sinai";
    governorates[88] = "Outside Egypt";

    do {
        cout << "Enter Your National ID: ";
        cin >> id;
        if (!isValidID(id)) cout << "Invalid ID,Please try again:\n";
    } while (!isValidID(id));

    string yearPart = id.substr(1, 2);
    string monthPart = id.substr(3, 2);
    string dayPart = id.substr(5, 2);
    int govCode = convert(id.substr(7, 2));

    
    int genderDigit = id[12] - '0';

    int birthYear = (id[0] == '2' ? 1900 : 2000) + convert(yearPart);
    int age = 2026 - birthYear;

    string gender = (genderDigit % 2 != 0) ? "Male" : "Female";

    cout << "\n=============================\n";
    cout << "Birth Date  : " << dayPart << "/" << monthPart << "/" << birthYear << endl;
    cout << "Age         : " << age << " Years" << endl;
    cout << "Gender      : " << gender << endl;
    cout << "Governorate : " << governorates[govCode] << endl;
    cout << "=============================\n";

    return 0;
}