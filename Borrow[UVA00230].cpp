#include <bits/stdc++.h>

#define AVAILABLE 1
#define BORROW 2
#define RETURN 3

using namespace std;

struct Book
{
    string name;
    string author;
    int status;
    Book(string name, string author)
    {
        this->name = name;
        this->author = author;
        status = AVAILABLE;
    }
    bool operator<(const Book &book) const
    {
        if (author != book.author)
            return author < book.author;
        else
            return name < book.name;
    }
    void print()
    {
        cout << name << " by " << author << endl;
    }
};

vector<Book> books;
unordered_map<string, int> book_pos;

void read_books()
{
    string line;
    while (getline(cin, line) && line != "END")
    {
        string name, author;
        size_t pos = line.find("by");
        name = line.substr(0, pos - 1);
        author = line.substr(pos + 3, line.length() - pos - 3);
        books.push_back(Book(name, author));
    }
    sort(books.begin(), books.end());
    int size = books.size();
    for (int i = 0; i < size; i++)
    {
        book_pos[books[i].name] = i;
    }
}

int main()
{
    read_books();
    string input;
    int size = books.size();
    while (cin >> input && input != "END")
    {
        if (input == "BORROW")
        {
            cin.get();
            getline(cin, input);
            books[book_pos[input]].status = BORROW;
        }
        else if (input == "RETURN")
        {
            cin.get();
            getline(cin, input);
            books[book_pos[input]].status = RETURN;
        }
        else
        {
            int prev = -1;
            for (int i = 0; i < size; i++)
            {
                if (books[i].status == RETURN)
                {
                    if (prev == -1)
                        cout << "Put " << books[i].name << " first" << endl;
                    else
                        cout << "Put " << books[i].name << " after " << books[prev].name << endl;
                    books[i].status = AVAILABLE;
                }
                if (books[i].status == AVAILABLE)
                    prev = i;
            }
            cout << "END" << endl;
        }
    }
    return 0;
}