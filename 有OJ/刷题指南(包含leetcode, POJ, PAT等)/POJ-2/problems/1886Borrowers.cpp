#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;
struct Book{
    string title;
    string author;
};
bool operator<(const Book &b1,const Book &b2){
    if(b1.author==b2.author) return b1.title>b2.title;
    return b1.author>b2.author;
}

set<Book> library;
set<Book> desk;
map<string,Book> title_to_book;
int main()
{
    string line;
    //build library
    while(getline(cin,line),line!="END"){
        int p = line.find(" by ");
        Book book;
        string title = line.substr(0,p);
        string author = line.substr(p+4);
        book.title = title;
        book.author = author;
        title_to_book[title] = book;
        library.insert(book);
    }
    while(getline(cin,line),line!="END"){
        string title;
        if(line.substr(0,6)=="BORROW"){
            title = line.substr(7);
            library.erase(title_to_book[title]);
        }else if(line.substr(0,6)=="RETURN"){
            title = line.substr(7);
            desk.insert(title_to_book[title]);
        }else{
            //shelve
            for(set<Book>::reverse_iterator it=desk.rbegin();it!=desk.rend();it++){
                cout<<"Put "<<it->title;
                if(library.upper_bound(*it)==library.end()) cout<<" first"<<endl;
                else cout<<" after "<<library.upper_bound(*it)->title<<endl;
                library.insert(*it);
            }
            cout<<"END"<<endl;
            desk.clear();
        }
    }
    return 0;
}
