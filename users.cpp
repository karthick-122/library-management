/*#include<iostream>
using namespace std;
#include<string>
#include<vector>*/
#include"C:\Users\KARTHICK\Documents\vs code\cpp\library management\books.cpp"
#include<map>
class _users {
    
    int user_id;
    string name;
    public:
    map<string,string> mp_bk_return_date;
     int book_count ;
     
    _users(int id,string _name)
    {
        user_id = id;
        name = _name;
        book_count =0;

    }
    int give_user_id()
    {
        return user_id;
    }
    bool add_borrwed_list(string cpy_id)
    {
        if(book_count>5)
        {
            cout<<"Your barrowing limit exid"<<endl;
            return 0;
        }
        mp_bk_return_date[cpy_id] = "1/02.24";
        book_count+=1;
        return 1;
    }
    void print_all_books_barrowed()
    {
        int count =1;
        for(auto x : mp_bk_return_date)
        {
            cout<<count<<" : "<<x.first<<"  :  "<<x.second<<endl;

        }
    }
    bool remove_from_barrowed(string cp_id)
    {
       
                mp_bk_return_date.erase(mp_bk_return_date.find(cp_id));
                return 1;  
    }
    void print_user_details()
    {
        cout<<" ID :"<<user_id<<" - name : "<<name<<endl;
    }
};

