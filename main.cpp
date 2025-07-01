// //Project Name: Movie Ticket Booking System
// Language: C++
// Concepts: OOP (Class, Inheritance), Arrays, Functions, Menu UI
// Main Features:
// - Movie list
// - Show timings
// - DTCard discount
// - Card payment simulation
// - Ticket printing

#include <iostream>
#include <string>
#include <limits>
#include <ctime>
#include <cstdlib>
using namespace std;

// 🎟 Ticket class
class Ticket {
public:
    string name;
    string contact;
};

// 💳 DTCard ke liye Card class (Ticket class se inherit hoti hai)
class Card : public Ticket {
public:
    string email;
    int cardID;
};

Card registeredCard;

// 👉 Har baar user input ke baad buffer clear karne ke liye
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// 💡 Fancy UI header function
void displayHeader(const string& title) {
    cout << "\n==================================================\n";
    cout << "\t\t" << title << "\n";
    cout << "==================================================\n";
}

// 📜 Main menu
void displayMenu() {
    displayHeader("🎬 WELCOME TO BOX OFFICE 🎬");
    cout << "1️⃣  Book Movie Ticket\n";
    cout << "2️⃣  Contact Us\n";
    cout << "3️⃣  Register for DTCard\n";
    cout << "4️⃣  Exit\n";
    cout << "--------------------------------------------------\n";
    cout << "Enter your choice: ";
}

// 🔢 Random Card ID Generator
int generateCardID() {
    srand(time(0));
    return rand() % 400000 + 4000000;
}

// 💰 Payment function
void pay(int count) {
    int choice;
    double total = 0.0;
    const double normalPrice = 200.0;
    const double goldPrice = 700.0;

    cout << "\n💺 Select Seat Type:\n1. Normal (Rs.200)\n2. Gold (Rs.700)\nChoice: ";
    cin >> choice;

    if (choice == 1) total = count * normalPrice;
    else if (choice == 2) total = count * goldPrice;
    else {
        cout << "\n❌ Invalid seat type selected.\n";
        return;
    }

    char hasCard;
    cout << "\n💳 Do you have a DTCard? (y/n): ";
    cin >> hasCard;
    if (hasCard == 'y' || hasCard == 'Y') {
        total *= 0.9; // 10% discount
        cout << "✅ 10% discount applied!\n";
    }

    cout << "\n💰 Total Amount to Pay: Rs. " << total << endl;
    char payByCard;
    cout << "Would you like to pay by Card? (y/n): ";
    cin >> payByCard;

    if (payByCard == 'y' || payByCard == 'Y') {
        string cardName, cardNumber;
        int mm, yyyy;
        cout << "\nCard Holder Name: ";
        cin >> cardName;
        cout << "Card Number (16 digits): ";
        cin >> cardNumber;
        cout << "Expiry Date (MM YYYY): ";
        cin >> mm >> yyyy;
        cout << "✅ Payment Successful via Card!\n";
    } else {
        cout << "✅ Payment Successful (Cash)!\n";
    }
}

// 🆕 Card Registration
void registerCard() {
    clearInput();
    displayHeader("🆕 Register for DTCard");
    cout << "Full Name: ";
    getline(cin, registeredCard.name);
    cout << "Contact Number: ";
    getline(cin, registeredCard.contact);
    cout << "Email ID: ";
    getline(cin, registeredCard.email);
    registeredCard.cardID = generateCardID();

    cout << "\n🎉 Card Registered Successfully!\n";
    cout << "Card ID: " << registeredCard.cardID << endl;
    cout << "\n✨ DTCard Benefits:\n";
    cout << "- Earn 25 points per ticket (1 point = Rs.1)\n";
    cout << "- Get 1 free ticket after 16 movies\n";
    cout << "- Exclusive early access and preferred seats\n";
}

// 🎫 Booking Ticket
void bookTicket() {
    Ticket t;
    int movieChoice, timeChoice, ticketCount;
    string movies[] = {
        "1. Ae Dil Hai Mushkil (Romance/Drama - U/A)",
        "2. Yeh Jawaani Hai Deewani (Romance/Comedy - A)",
        "3. Avatar: The Way of Water (Sci-fi/Action - U/A)",
        "4. Avatar: Fire and Ash (Sci-fi/Action - U/A)",
        "5. Brahmāstra: Part One – Shiva (Action/Fantasy - U/A)"
    };
    
    displayHeader("🎟 Available Movies");
    for (const auto& m : movies) cout << m << endl;
    cout << "\nSelect a movie (1-5): ";
    cin >> movieChoice;

    string showTimings[] = {"08:00", "13:00", "15:00", "18:00", "21:00"};
    cout << "\n⏰ Show Timings:\n";
    for (int i = 0; i < 5; ++i) cout << i + 1 << ". " << showTimings[i] << endl;
    cout << "\nChoose a timing slot (1-5): ";
    cin >> timeChoice;

    clearInput();
    cout << "\nEnter Your Name: ";
    getline(cin, t.name);
    cout << "Enter Your Contact Number: ";
    getline(cin, t.contact);
    cout << "How many tickets? ";
    cin >> ticketCount;

    pay(ticketCount);

    // 🎫 Print Ticket
    displayHeader("🎫 Your Movie Ticket 🎟");
    cout << "Name        : " << t.name << endl;
    cout << "Contact No. : " << t.contact << endl;
    cout << "Movie       : " << movies[movieChoice - 1] << endl;
    cout << "Show Time   : " << showTimings[timeChoice - 1] << endl;
    cout << "Enjoy your movie! 🍿" << endl;
}

// 🚀 Main Function
int main() {
    int choice;
    char again;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: bookTicket(); break;
            case 2:
                displayHeader("📞 Contact Us");
                cout << "For more info, call 0123-4567890 or visit our app.\n";
                break;
            case 3: registerCard(); break;
            case 4:
                displayHeader("🙏 Thank You!");
                cout << "Visit Again Soon!\n";
                return 0;
            default:
                cout << "❌ Invalid choice. Try again.\n";
        }
        cout << "\nWould you like to do another operation? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    return 0;
}