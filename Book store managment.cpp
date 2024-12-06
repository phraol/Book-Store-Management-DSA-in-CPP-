// Book store management System
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//Book managment
struct Book_record {
    string Book_name;
    int Book_id;
    string Author;
    string status;
    struct Book_record* next;
    struct Book_record* prev;
};
struct Book_record* head_book = NULL;
void Add_book(Book_record* book) {
    if (head_book == NULL) {
        head_book = book;
        book->next = NULL;
        book->prev = NULL;
    }
    else {
        Book_record* temp = head_book;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = book;
        book->prev = temp;
        book->next = NULL;
    }
}

void delete_book() {
    if (head_book == NULL)
        return;

    head_book = head_book->next;
    if (head_book != NULL)
        head_book->prev = NULL;
}
void delete_by_id(int id) {
    if (head_book == NULL) {
        cout << "Sorry there is no book in the system" << endl;
        return;
    }
    else if (head_book->Book_id== id) {
        head_book = NULL;
        cout << "You have successfully delated the book" << endl;
    }
    else {
        Book_record* temp = head_book;
        while (temp->Book_id != id) {
            temp = temp->next;
            if (temp == NULL)
                break;
        }
        if (temp == NULL)
            cout << "This book is not found in the system" << endl;
        else {
            if (temp->next == NULL)
                temp->prev->next = NULL;
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            cout << "You have successfully deleted a book" << endl;
        }
    }
}
void delete_by_name(string name) {
    if (head_book == NULL) {
        cout << "Sorry there is no book in the system" << endl;
        return;
    }
    else if (head_book->Book_name == name) {
        head_book = NULL;
        cout << "You have successfully delated the book" << endl;
    }
    else {
        Book_record* temp = head_book;
        while (temp->Book_name != name) {
            temp = temp->next;
            if (temp == NULL)
                break;
        }
        if (temp == NULL)
            cout << "This book is not found in the system" << endl;
        else {
            if (temp->next == NULL)
                temp->prev->next = NULL;
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            cout << "You have successfully deleted a book" << endl;
        }
    }
}
void Display_books() {
    Book_record* temp = head_book;
    cout << left << setw(20) << "Book Name" << setw(20) << "Book id" << setw(20) << "Book Author" << setw(20) << "Book status" << endl;
    cout << left << "-------------------------------------------------------------------------" << endl;
    while (temp != NULL) {
        cout << left << setw(20) << temp->Book_name << setw(20) << temp->Book_id << setw(20) << temp->Author << setw(20) << temp->status << endl;
        temp = temp->next;
    }
}


void delet_last() {
    if (head_book == NULL)
        return;
    else if (head_book->next == NULL) {
        head_book = NULL;
    }
    else {
        Book_record* temp = head_book;
        while (temp->next!=NULL)
            temp = temp->next;
        temp->prev->next = NULL;
    }
       
}
void delete_middle() {
    if (head_book == nullptr)
        return;
    else if (head_book->next == nullptr) {
        head_book = nullptr;
    }
    else {
        Book_record* temp = head_book;
        int n = 0;
        while (temp != nullptr) {
            temp = temp->next;
            n++;
        }

        temp = head_book;
        Book_record* prev = nullptr;
        for (int i = 0; i < n / 2; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (prev != nullptr) {
            prev->next = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = prev;
        }
        delete temp;
    }
}

void add_middle(Book_record* book) {
    if (head_book == NULL) {
        head_book = book;
        book->next = NULL;
        book->prev = NULL;
    }
    else {
        Book_record* slow_ptr = head_book;
        Book_record* fast_ptr = head_book->next;
        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        book->next = slow_ptr->next;
        if (slow_ptr->next != NULL) {
            slow_ptr->next->prev = book;
        }
        slow_ptr->next = book;
        book->prev = slow_ptr;
    }
}
//Student managment
struct student_record {
    string stud_name;
    int stud_id;
    int password;
    struct student_record* nexts;
    struct Book_record* borrowed;
};

struct student_record* head_stud = NULL;
void add_studfront(student_record* stud) {
    if (head_stud == NULL) {
        head_stud = stud;
        stud->nexts = NULL;
    }
    else {
        stud->nexts = head_stud;
        head_stud = stud;
    }
}
void add_studmid(student_record* stud){
    if (head_stud == NULL) {
        head_stud = stud;
        stud->nexts = NULL;
    }
    else if (head_stud->nexts == NULL) {
        stud->nexts = NULL;
        head_stud->nexts = stud;
    }
    else {
        student_record* temp = head_stud;
        int n = 0;
        while (temp != NULL) {
            n++;
            temp = temp->nexts;
        }
        temp = head_stud;
        for (int i = 0; i <n/2; i++) {
            temp = temp->nexts;
        }
        stud->nexts = temp->nexts;
        temp->nexts = stud;
    }
}
void add_stud(student_record* stud) {
    if (head_stud == NULL) {
        head_stud = stud;
        stud->nexts = NULL;
    }
    else if (head_stud->nexts == NULL) {
        stud->nexts = NULL;
        head_stud->nexts = stud;
    }
    else {
        student_record* temp = head_stud;
        while (temp->nexts != NULL)
            temp = temp->nexts;
        temp->nexts = stud;
        stud->nexts = NULL;
    }
}
void del_stud() {
    if (head_stud == NULL)
        return;
    else {
        head_stud= head_stud->nexts;
    }
}
void del_laststud() {
    if (head_stud == NULL)
        return;
    else if (head_stud->nexts == NULL)
        head_stud = NULL;
    else {
        student_record* temp = head_stud;
        while (temp->nexts->nexts != NULL)
            temp = temp->nexts;
        temp->nexts = NULL;
    }
}
void del_midstud() {
    if (head_stud == NULL)
        return;
    else if (head_stud->nexts == NULL)
        head_stud = NULL;
    else {
        student_record* temp = head_stud;
        int n = 0;
        while (temp != NULL) {
            n++;
            temp = temp->nexts;
        }
        temp = head_stud;
        for (int i = 1; i <n/2; i++) {
            temp = temp->nexts;
        }
        temp->nexts = temp->nexts ->nexts;
    }
}
void del_studname(string name) {
    if (head_stud == NULL) {
        cout << "There is no student in the system";
        return;
    }
    else if (head_stud->nexts == NULL && head_stud->stud_name==name) {
        head_stud = NULL;
        cout << "You have successfully deleted the student from the system" << endl;
    }
    else if (head_stud->stud_name == name) {
        head_stud = head_stud->nexts;
        cout << "You have successfully deleted the student from the system" << endl;
    }
    
    else {
        student_record* temp = head_stud;
        while (temp->nexts->stud_name!=name) {
            temp = temp->nexts;
            if (temp->nexts== NULL)
                break;
        }
        if (temp->nexts== NULL)
            cout << "The student is not found in the system" << endl;
        else {
            temp->nexts = temp->nexts->nexts;
            cout << "You have successfully deleted the student from the system";
        }
    }
}   
void del_studid(int id) {
    if (head_stud == NULL) {
        cout << "There is no student in the system";
        return;
    }
    else if (head_stud->nexts == NULL && head_stud->stud_id == id) {
        head_stud = NULL;
    }
    else if (head_stud->stud_id== id) {
        head_stud = head_stud->nexts;
    }

    else {
        student_record* temp = head_stud;
        while (temp->nexts->stud_id != id) {
            temp = temp->nexts;
            if (temp->nexts == NULL)
                break;
        }
        if (temp->nexts == NULL)
            cout << "The student is not found in the system" << endl;
        else {
            temp->nexts = temp->nexts->nexts;
        }
    }
}

void display_stud() {
    student_record* dis = head_stud;
    cout << left << setw(20) << "Student Name" << setw(20) << "Student id" << setw(20) << "Book borrowed" << endl;
    cout << left << "-------------------------------------------------------------------------" << endl;
    while (dis != NULL) {
        cout << left << setw(20) << dis->stud_name << setw(20) << dis->stud_id;
        if (dis->borrowed == NULL)
            cout << setw(20) << "None" << endl;
        else {
            cout << setw(20) << dis->borrowed->Book_name << endl;
        }
        dis = dis->nexts;
    }
}
void display_studname(string name) {
    student_record* temp = head_stud;
    while (temp->stud_name!=name) {
        temp = temp->nexts;
        if (temp == NULL)
            break;
    }
    if (temp == NULL)
        cout << "We couldn't find a student with this name" << endl;
    else {
        cout << "student name: " << temp->stud_name << endl;
        cout << "student id: " << temp->stud_id << endl;
        if (temp->borrowed == NULL)
            cout << "Book borrowed: " << "None" << endl;
        else {
            cout << "Book borrowed: " << temp->borrowed->Book_name << endl;
        }
    }
}
void display_studid(int id) {
    student_record* temp = head_stud;
    while (temp->stud_id != id) {
        temp = temp->nexts;
        if (temp == NULL)
            break;
    }
    if (temp == NULL)
        cout << "We couldn't find a student with this id" << endl;
    else {
        cout << "student name: " << temp->stud_name << endl;
        cout << "student id: " << temp->stud_id << endl;
        if (temp->borrowed == NULL)
            cout << "Book borrowed: " << "None" << endl;
        else {
            cout << "Book borrowed: " << temp->borrowed->Book_name << endl;
        }
    }
}
void display_borrowed_books() {
    Book_record* temp_book = head_book;
    cout << left << setw(20) << "Book Name" << setw(20) << "Book id" << setw(20) << "Book Author" <<endl;
    cout << left << "-------------------------------------------------------------------------" << endl;
    while (temp_book != NULL) {
        if (temp_book->status == "borrowed")
            cout << left << setw(20) << temp_book->Book_name << setw(20) << temp_book->Book_id << setw(20) << temp_book->Author << setw(20)<<endl;
        temp_book = temp_book->next;
    }
}
void display_available_books() {
    Book_record* temp_book = head_book;
    cout << left << setw(20) << "Book Name" << setw(20) << "Book id" << setw(20) << "Book Author" << endl;
    cout << left << "-------------------------------------------------------------------------" << endl;
    while (temp_book != NULL) {
        if (temp_book->status == "Available")
            cout << left << setw(20) << temp_book->Book_name << setw(20) << temp_book->Book_id << setw(20) << temp_book->Author << setw(20) << endl;
        temp_book = temp_book->next;
    }
}
void lend_book(int id ) {
    student_record* temp = head_stud;
    while (temp->stud_id != id) {
        temp = temp->nexts;
        if(temp==NULL)
            break;
    }
    if (temp == NULL)
        cout << "Your id is not found. Please make sure you have entered the write id and try again" << endl;
    else {
        cout << "This are the books in our library enter the id of the book you wanted to lend" << endl << endl;
        display_available_books();
        cout << "Eneter id of a book you want to borrow" << endl;
        int id;
        cin >> id;
        Book_record* add = head_book;
        while (add->Book_id != id) {
            add = add->next;
            if (add == NULL)
                break;
        }
        if (add == NULL)
            cout << "you have entered the wrong id, this book is not available" << endl;
        else if (add->status == "borrowed")
            cout << "this book is not available"<<endl;
        else {
            temp->borrowed = add;
            add->status = "borrowed";
            cout << "You have successfully borrowed a book titled " << add->Book_name << endl;
        }
    }
}
void return_book(int id) {
    student_record* temp = head_stud;
    while (temp->stud_id != id) {
        temp = temp->nexts;
        if (temp == NULL)
            break;
    }
    if (temp == NULL)
        cout << "Your id is not found. Please make sure you have entered the write id and try again" << endl;
    else if (temp->borrowed == NULL)
        cout << "You haven't borrowed a book" << endl;
    else {
        Book_record* add = temp->borrowed;
        add->status = "Availble";
        temp->borrowed = NULL;
        cout << "You have successfully returned the book to our system" << endl;
    }
    
}

int number_of_books();
int main() {
    Book_record* book_1 = new Book_record{ "Software Eng", 1, "Ian Sommervaille", "borrowed", nullptr, nullptr };
    Book_record* book_2 = new Book_record{ "Intro to Computing", 2, "David Evans", "Available", nullptr, nullptr };
    Book_record* book_3 = new Book_record{ "DSA using C", 3, "A.K Sharma", "borrowed", nullptr, nullptr };
    Book_record* book_4 = new Book_record{ "Open DSA", 4, "Pat Morin", "Available", nullptr, nullptr };
    Add_book(book_1);
    Add_book(book_2);
    Add_book(book_3);
    Add_book(book_4);
    student_record* stud_3 = new student_record{ "Naol Girma",31014,0000,nullptr,nullptr };
    student_record* stud_2 = new student_record{ "Idan Aseffa",30703,0000,nullptr,nullptr};
    student_record* stud_1 = new student_record{ "Baran Abdeta",30224,0000,nullptr,nullptr};
    student_record* stud_4 = new student_record{ "Yeabsira Goitom",31390,0000,nullptr,nullptr };
    student_record* stud_5 = new student_record{ "Yoseph Tafese",31461,0000,nullptr,nullptr };
    add_stud(stud_1);
    add_stud(stud_2);
    add_stud(stud_3);
    add_stud(stud_4);
    add_stud(stud_5);
        cout << "How do you want to login in to our systen, are u a student or a librarian" << endl;
        cout << "1.A student " << endl;
        cout << "2.A librarian" << endl;
        int operate;
        cin >> operate;
        switch (operate)
        {
        case 1: {
            bool logged_in = true;
            
                cout << "Enter your id and your password" << endl;
                int id, pass;
                cin >> id >> pass;
                student_record* temp = head_stud;
                while (temp->stud_id != id) {
                    temp=temp->nexts;
                    if (temp == NULL)
                        break;
                }
                if (temp == NULL) {
                    cout << "Log in failed" << endl;
                    logged_in = false;
                }
                else if (temp->password != pass) {
                    cout << "You have entered the wrong password" << endl;
                    logged_in = false;
                }
                while (logged_in) {
                cout << "Hello there! what do you want to do today" << endl;
                cout << "1. To chech on my data" << endl;
                cout << "2.to check books in library" << endl;
                cout << "3.To borrow a book" << endl;
                cout << "4.To return a book" << endl;
                cout << "5.To exit from library membership" << endl;
                cout << "6. Log out" << endl;
                int stud;
                cin >> stud;
                switch (stud)
                {
                case 1:
                    display_studid(id);
                    break;
                case 2:
                    Display_books();
                    break;
                case 3:
                    lend_book(id);
                    break;
                case 4:
                    return_book(id);
                    break;
                case 5: {
                    cout << "are you sure you want to exit from our library  membership (y/n)";
                    string choos;
                    cin >> choos;
                    if (choos == "y") {
                        del_studid(id);
                        cout << "you have sussessfully unregisterd from our system, we are sorry to tell you that youcannot use the servise of our library anymore" << endl;
                        logged_in = false;
                    }
                    else if (choos == "n")
                        cout << "We are glad you didn'y exit from our library membership" << endl;
                    break; 
                }
                default:
                    cout << "wrong login" << endl;
                    break;
                }
                if (logged_in) {
                    char continueOption;
                    cout << "Do you want to continue? (y/n): "<<endl;
                    cin >> continueOption;
                    if (continueOption != 'y' && continueOption != 'Y') {
                        logged_in = false;
                        cout << "You have chosen to exit the system. Goodbye!" << endl;
                    }
                }
               
             }
                break;
            }
        case 2: {
            bool logged_in = true;
            while (logged_in) {
                cout << "Welcome back! Choose what you wanna do with the sytem today by entering the number of your choice" << endl;
                cout << "1.To check on  the books in the library" << endl;
                cout << "2.To see students in our library system" << endl;
                cout << "3.To add a new book to the shelf" << endl;
                cout << "4.To delete a book from a system" << endl;
                cout << "5.To add a new student to the system" << endl;
                cout << "6.To delete a student from a system" << endl;
                cout << "7.To check borrowed books" << endl;
                cout << "8.log out" << endl;
                int control;
                cin >> control;
                switch (control)
                {
                case 1:
                    cout << "Here are the books availible in our library" << endl;
                    Display_books();
                    break;
                case 2:
                {
                    cout << "How do you want to display the student?" << endl;
                    cout << "1. Display all students" << endl;
                    cout << "2. Display by name" << endl;
                    cout << "3. Display by ID" << endl;

                    int displayOption;
                    cin >> displayOption;

                    switch (displayOption)
                    {
                    case 1:
                        cout << "Here are all the students:" << endl;
                        display_stud();
                        break;
                    case 2:
                    {
                        string name;
                        cout << "Enter the name of the student you want to display: ";
                        cin.ignore();
                        getline(cin, name);
                        display_studname(name);
                        break;
                    }
                    case 3:
                    {
                        int id;
                        cout << "Enter the ID of the student you want to display: ";
                        cin >> id;
                        display_studid(id);
                        break;
                    }
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                    }
                    break;
                }

                case 3:
                {
                    cout << "How do you want to add the book?" << endl;
                    cout << "1 -> Regularly at the end of the shelf" << endl;
                    cout << "2 -> At the middle of the shelf" << endl;
                    int how;
                    cin >> how;

                    int x, n = number_of_books();
                    x = n + 1;
                    string name, author;
                    cout << "Enter name of the book: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter the Author of the book: ";
                    getline(cin, author);
                    Book_record* newbook = new Book_record{ name, x, author, "Available", nullptr, nullptr };

                    switch (how)
                    {
                    case 1:
                        Add_book(newbook);
                        cout << "You have successfully added a book to the end of the shelf" << endl;
                        Display_books();
                        break;
                    case 2:
                        cout << "You have successfully added a book to the middle of the shelf" << endl;
                        add_middle(newbook);
                        Display_books();
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                    }
                }
                break;


                case 4:
                {
                    cout << "How do you want to delete the book?" << endl;
                    cout << "1. Delete by ID" << endl;
                    cout << "2. Delete by Name" << endl;
                    cout << "3. Delete from the front of the shelf" << endl;
                    cout << "4. Delete from the last of the shelf" << endl;
                    cout << "5. Delete from the middle of the shelf" << endl;

                    int deleteOption;
                    cin >> deleteOption;

                    switch (deleteOption)
                    {
                    case 1:
                    {
                        int id;
                        cout << "Enter the ID of the book you want to delete: ";
                        cin >> id;
                        delete_by_id(id);
                        Display_books();
                        break;
                    }
                    case 2:
                    {
                        string name;
                        cout << "Enter the name of the book you want to delete: ";
                        cin.ignore();
                        getline(cin, name);
                        delete_by_name(name);
                        Display_books();
                        break;
                    }
                    case 3:
                        delete_book();
                        cout << "Book from the front of the shelf deleted successfully." << endl;
                        Display_books();
                        break;
                    case 4:
                        delet_last();
                        cout << "Book from the last of the shelf deleted successfully." << endl;
                        Display_books();
                        break;
                    case 5:
                        delete_middle();
                        cout << "Book from the middle of the shelf deleted successfully." << endl;
                        Display_books();
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                    }
                    break;
                }

                case 5:
                {
                    cout << "How do you want to add the student?" << endl;
                    cout << "1. Add at the front of the student list" << endl;
                    cout << "2. Add at the middle of the student list" << endl;
                    cout << "3. Add at the last of the student list" << endl;

                    int addOption;
                    cin >> addOption;

                    string name;
                    int id;

                    cout << "Enter the name of the student: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter the ID of the student: ";
                    cin >> id;

                    student_record* newStudent = new student_record{ name, id, 0000,nullptr, nullptr };

                    switch (addOption)
                    {
                    case 1:
                        add_studfront(newStudent);
                        cout << "Student added at the front of the student list." << endl;
                        display_stud();
                        break;
                    case 2:
                        add_studmid(newStudent);
                        cout << "Student added at the middle of the student list." << endl;
                        display_stud();
                        break;
                    case 3:
                        add_stud(newStudent);
                        cout << "Student added at the last of the student list." << endl;
                        display_stud();
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                    }
                    break;
                }

                case 6:
                {
                    cout << "How do you want to delete the student?" << endl;
                    cout << "1. Delete from the front of the student list" << endl;
                    cout << "2. Delete from the middle of the student list" << endl;
                    cout << "3. Delete from the last of the student list" << endl;
                    cout << "4. Delete by name" << endl;
                    cout << "5. Delete by ID" << endl;

                    int deleteOption;
                    cin >> deleteOption;

                    switch (deleteOption)
                    {
                    case 1:
                        del_stud();
                        cout << "Student from the front of the student list deleted successfully." << endl;
                        display_stud();
                        break;
                    case 2:
                        del_midstud();
                        cout << "Student from the middle of the student list deleted successfully." << endl;
                        display_stud();
                        break;
                    case 3:
                        del_laststud();
                        cout << "Student from the last of the student list deleted successfully." << endl;
                        display_stud();
                        break;
                    case 4:
                    {
                        string name;
                        cout << "Enter the name of the student you want to delete: ";
                        cin.ignore();
                        getline(cin, name);
                        del_studname(name);
                        display_stud();
                        break;
                    }
                    case 5:
                    {
                        int id;
                        cout << "Enter the ID of the student you want to delete: ";
                        cin >> id;
                        del_studid(id);
                        cout << "You have successfully deleted a student with id " << id << "from the system" << endl;
                        display_stud();
                        break;
                    }
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                    }
                    break;
                }
                case 7:
                    cout << "These are borrowed books from library currentyl" << endl;
                    display_borrowed_books();
                    break;
                default:
                    cout << "Sorry! the only things you can perform on the library is the above things" << endl;
                    break;
                case 8:
                    logged_in = false;
                    cout << "You have successfully logged out of the system. Goodbye!" << endl;
                    break;
                }
                if (logged_in) {
                    char continueOption;
                    cout << "Do you want to continue? (y/n): ";
                    cin >> continueOption;
                    if (continueOption != 'y' && continueOption != 'Y') {
                        logged_in = false;
                        cout << "You have chosen to exit the system. Goodbye!" << endl;
                    }
                }
            }
        }
        default:
            cout << "wrong log in" << endl;
            break;
        }
    return 0;

}
    int number_of_books() {
        Book_record* temp = head_book;
        int n = 0;
        while (temp != NULL) {
            temp = temp->next;
            n++;
        }
    
    return n;
}
