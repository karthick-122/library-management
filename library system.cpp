#include"C:\Users\KARTHICK\Documents\vs code\cpp\library management\users.cpp"

class library{
    vector<_users> users;
    vector<book> books;
    vector<book> racks;
    int num_of_racks;
    public:
    library(int num)
    {

        num_of_racks = num;
        for(int i=0;i<num;i++)
        {
            book bk;
            racks.push_back(bk);
        }
        cout<<"Library created with "<<num<<" Racks"<<endl;

    }
    void add_users()
    {
             int id;
            string name;
            cout<<"Enter user id and name ";
            cin>>id>>name;
            
            _users usr(id,name);
            users.push_back(usr);
        
    }
    bool add_book_to_rack(book bbk)
    {
        for(int i=0;i<num_of_racks;i++)
        {
            if(racks[i].is_book_there==0)
            {
                racks[i] = bbk;
                cout<<" ------ book added_sucessfully -----"<<endl;
                return 1;
            }
        }
       
       
            cout<<"Rack not available"<<endl;
            return 0;
        
    }
    void create_book_and_add()
    {
        string title;
        int book_id;
        int num_copy;
        int num_authers;
        int num_publishers;
       
        cout<<"Enter title of the book : ";
        cin>>title;
        cout<<"Enter book id , num.of.cpy , num.of.authers , num.of.publishers : ";
        cin>>book_id>>num_copy>>num_authers>>num_publishers;

        

          book bk(book_id,title);
        for(int i=0;i<num_authers;i++)
        {
            string str;
            cout<<"Enter auther : "<<i<<" details : ";
            cin>>str;
            bk.add_auther(str);
        }
        for(int i=0;i<num_publishers;i++)
        {
            string str;
            cout<<"Enter publishers : "<<i<<" details : ";
            cin>>str;
            bk.add_publisers(str);
        }
        for(int i=0;i<num_copy;i++)
        {
            string str;
            cout<<"Enter copy_id : "<< i <<" details : ";
            cin>>str;

            bk.set_copy_id(str);
            if(add_book_to_rack(bk))
              books.push_back(bk);
            
            
        }

    }

    void search_book_using_id(int num)
    {
        for(int i=0;i<racks.size();i++)
        {
               if(racks[i].book_id == num)
               racks[i].print_the_book();
              //  racks[i].print_authers_and_pub();
        }
    }
    void search_book_using_auther_in_rack(string auth)
    {
        for(int i=0;i<racks.size();i++)
        {
               if(racks[i].is_auther_there(auth))
               racks[i].print_the_book();
                // racks[i].print_authers_and_pub();
        }

    }
    void search_book_uaing_publiser_in_rack(string pub)
    {
         for(int i=0;i<racks.size();i++)
        {
               if(racks[i].is_publisr_there(pub))
               racks[i].print_the_book();
                // racks[i].print_authers_and_pub();
        }

    }

    void search_book()
    {
        int value = 0;
        string ss;
        cout<<"For search using id        : 1"<<endl;
        cout<<"for search using auther    : 2"<<endl;
        cout<<"For search using publisher : 3  ";
        cin>>value;

        switch (value)
        {
        case 1:
            int nn;
            cout<<" ener book id :  ";
            cin>>nn;
            search_book_using_id(nn);
            break;
        case 2:
            
            cout<<"Enter auther name : ";
            cin>>ss;
            search_book_using_auther_in_rack(ss);
            break;
        case 3:
            
             cout<<"Enter publiser name : ";
             cin>>ss;
             search_book_uaing_publiser_in_rack(ss);
        break;
        
        default:
            break;
        }
    }
    void remove_book_on_rack_using_cpy(string cpy_id)
    {

         for(int i=0;i<racks.size();i++)
        {
               if(racks[i].copy_id== cpy_id)
                 racks[i].remove_book();
        }
    }
    bool barrow_book_copy()
    {
        int userid;string copy_id;
        cout<<"Enter user id and copy_name : ";
        cin>>userid>>copy_id;
        for(int i=0;i<users.size();i++)
        {
            if(users[i].give_user_id()==userid)
            {
                if(users[i].add_borrwed_list(copy_id))
                {
                    remove_book_on_rack_using_cpy( copy_id);
                    return 1;
                }
            }
        }
        
        return 0;
    }

    bool find_the_book(string coy_id)
    {
        for(int i=0;i<books.size();i++)
        {
            if(books[i].copy_id == coy_id)
            return 1;
        }
        return 0;
    }

    void return_the_book()
    {
        int userid;string copy_id;
        cout<<"Enter user id and copy_name : ";
        cin>>userid>>copy_id;

        if(!find_the_book(copy_id))
        {
            cout<<"invalid copy ID"<<endl;
        }

        for(int i=0;i<racks.size();i++)// book in serted in the rack
        {
            if(racks[i].is_book_there ==0)
            {
                for(int j=0;j<books.size();j++)
                {
                 
                  if(books[j].copy_id == copy_id)
                       {
                        racks[i] = books[j];
                        cout<<"book returned sucessfull"<<endl;;
                        return;
                       }
                  }
                 
            }
        }

        for(int i=0;i<users.size();i++)
        {
            if(users[i].give_user_id()==userid)
            {
                users[i].remove_from_barrowed(copy_id);
                return;
            }
        }

    }


    void print_the_users()
    {
        for(int i=0;i<users.size();i++)
        {
            users[i].print_user_details();
            users[i].print_all_books_barrowed();
        }
    }

    void print_the_rack()
    {
        for(int i=0;i<racks.size();i++)
        {
            if(racks[i].is_book_there==1)
                racks[i].print_the_book();
            else
             cout<<"in rack "<<i<<" no book available"<<endl;
        }
    }
   


};



int main()
{
    library lib(10);
    int i=1;
    int expression = 0;
    string ss;
    while(i)
    {
        cout<<" 1 : add user "<<endl;
        cout<<" 2 : create_book_and_add"<<endl;
        cout<<" 3 : search book "<<endl;
        cout<<" 4 : barrow_book"<<endl;
        cout<<" 5 : return the book"<<endl;
        cout<<" 6 : print the rack"<<endl;
        cout<<" 7 : pritn the users"<<endl;

        cout<<" 9 : remove the book"<<endl;
        cin>>expression;
        switch (expression)
        {
        case 1:
            lib.add_users();
            break;
        case 2:
            lib.create_book_and_add();
            break;
        case 3:
            lib.search_book();
            break;
        case 4:
            lib.barrow_book_copy();
            break;
        case 5:
            lib.return_the_book();
            break;
        case 6:
            lib.print_the_rack();
            break;
        case 7:
            lib.print_the_users();
            break;
        case 9: 
            
            cout<<"enter book_copy_id ";
            cin>>ss;
            lib.remove_book_on_rack_using_cpy(ss);
            break;
        
        default:
            break;
        }
    }



    cout<<"you can do it"<<endl;
}




/*
  frist add the use
  add the books
  search the books
  barrow the books 
  return the books
*/



/*
add_users()
 library(int num)
 bool add_book_to_rack(book bbk)
  void create_book_and_add()
  void search_book_using_id(int num)
   void search_book_using_auther_in_rack(string auth)
    void search_book_uaing_publiser_in_rack(string pub)
    void remove_book_on_rack_using_cpy(string cpy_id)
     bool barrow_book_copy(int userid,string copy_id)
   


*/