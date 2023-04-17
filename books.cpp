#include<iostream>
using namespace std;
#include<string>
#include<vector>
class book
{
    
     public:
     bool is_book_there;
    int  book_id;
    string title;
    string copy_id;
    vector<string> authers;
    vector<string> publishers;


    book()
    {
        book_id = -1;
        title = "kkk";
        is_book_there =0;
    }
    book(int id,string _title)
    {
        book_id = id;
        title =_title;
        is_book_there =1;
    }
    bool remove_book()
    {
        is_book_there =0;
        title = "";
        copy_id = "";
        book_id = -1;
        authers.clear();
        publishers.clear();
    }
    bool add_auther(string name)
    {
        authers.push_back(name);
        return 1;
    }
    bool add_publisers(string publiser)
    {
        publishers.push_back(publiser);
        return 1;
    }
    void set_copy_id(string id)
    {
        copy_id = id;
    }
    void print_authers_and_pub()
    {
        for(int i=0;i<authers.size();i++)
        {
            cout<<authers[i]<<" , ";
        }
        cout<<" - ";
        for(int i=0;i<publishers.size();i++)
        {
            cout<<publishers[i]<<" , ";
        }
    }

    void print_the_book()
    {
        cout<<endl<<endl;
        cout<<copy_id<<" - "<<book_id <<" - "<<title<<" - ";
        print_authers_and_pub();
    }
    bool is_auther_there(string auth)
    {
         for(int i=0;i<authers.size();i++)
        {
           if(authers[i]==auth)
            return 1;
        }
        return 0;
    }
    bool is_publisr_there(string pub)
    {
        for(int i=0;i<publishers.size();i++)
        {
           if(publishers[i]==pub)
           return 1;
        }
        return 0;

    }
};