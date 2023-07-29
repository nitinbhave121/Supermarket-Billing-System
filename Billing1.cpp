
#include<iostream>
#include<fstream>
#include<windows.h>

using namespace std;

class shopping
{
    private :
    int pcode;
    float price;
    float dis;
    string pname;

    public :
            void menu();
            void admin();
            void buyer();
            void add();
            void edit();
            void rem();
            void list();
            void receipt();

};

void shopping :: menu()
{
    system("color 0A");
    int choice ;
    string email;
    string password;

    cout<<"\t\t\t\t___________*******************_______________\n";
    cout<<"\t\t\t\t                                             \n";
    cout<<"\t\t\t\t          Supermarket Main Menu              \n";
    cout<<"\t\t\t\t                                             \n";
    cout<<"\t\t\t\t___________*******************_______________\n";
    
    cout<<"\t\t\t\t                                             \n";
    cout<<"\t\t\t\t||   1).Admin      ||\n";
    cout<<"\t\t\t\t                    \n";
    cout<<"\t\t\t\t||   2).Buyer      ||\n";
    cout<<"\t\t\t\t                    \n";
    cout<<"\t\t\t\t||   3).Exit       ||\n";
    cout<<"\t\t\t\t                    \n";
    cout<<"\t\t\t\t|| Please Select  ||\n";
    cin>>choice;

    switch(choice)
    {
        m:
        case 1:
        cout<<"\t\t\t Please Login\n";
        cout<<"\t\t\t Enter Email \n";
        cin>>email;
        cout<<"\t\t\t password    \n";
        cin>>password;

        if(email == "nitinbhave2002@gmail.com" &&password =="Nitin123")

        admin();

        else
        cout<<"Invalid email / Passsword";
        break;

        case 2:
       {
        buyer();

       }
    case 3:
    {
        exit(0);
    }

    default :
        cout<<"please Select valid choice\n";

    }
    goto m;

}

void shopping ::admin()
{
    m:
    int choice ;
    cout<<"\n\n\n\t\t\t ######## Admin Menu #######";
    cout<<"\n\n\n\t\t\t || 1).Add the Product    ||";
    cout<<"\n\t\t\t                            ";
    cout<<"\n\n\n\t\t\t || 2).Modify the Product || ";
    cout<<"\n\t\t\t                            ";
    cout<<"\n\n\n\t\t\t || 3).Delete the Product || ";
    cout<<"\n\t\t\t                            ";
    cout<<"\n\n\n\t\t\t || 4).Back to Menu       || ";

    cout<<"\n\n\t Please Enter your Choice ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default :
            cout<<"Invalid Choice\n";
    }

    goto m;


}

void shopping ::buyer()
{
    m:
    int choice;
    cout<<"\t\t\t********** Buyer ********** \n";
    cout<<"                \n";
    cout<<"\t\t\t ||  1.Buy Product       ||\n";
    cout<<"                             \n";
    cout<<"\t\t\t ||  2.Go Back           ||\n";
    cout<<"                             \n";
    cout<<"\t\t\t ||  Enter Your Choice : || \n";

    cin>>choice;

    switch(choice)
    {
        case 1:
            receipt();
            break;
        case 2:
            menu();
        
        default:
            cout<<"Invalid Choice\n";
    }
    goto m;
}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t ********** Add New Product ***********";
    cout<<"\n\n\t\t 1)Product Code of Product  ";
    cin>>pcode;
    cout<<"\n\n\t\t 2)Name of the Product   ";
    cin>>pname;
    cout<<"\n\n\t\t 3)Price of the Product  ";
    cin>>price;
    cout<<"\n\n\t\t 4)Discount on the Product  ";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" \n";

        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c == pcode)
            token++;
            data>>c>>n>>p>>d;
        }
        data.close();
    }
    if(token ==1)
    goto m;
    else
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" \n";
        data.close();
    }

    cout<<"\n\n\t\t Record Inserted";

}

void shopping :: edit()
{
    fstream data , data1;
    int pkey;
    int token =0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\\t\t********** Modify the Record **********";
    cout<<"\n\t\t\t 1) Product Code :";
    cin>>pkey;
     data.open("database.txt",ios::in);
     if(!data)
     {
        cout<<"\n\n File Doest not exist";

     }
     else
     {
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\n\t Product New code ==>";
                cin>>c;
                cout<<"\n\n\t Name of the Product ==>";
                cin>>n;
                cout<<"\n\n\t Price ==>";
                cout<<"\n\n\t Discount ==>";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<" \n";
                cout<<"\n\n\t\t Record Edited";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n Record Not Found";
        }
     }
}

void shopping :: rem()
{
    fstream data ,data1;
    int pkey,token=0;
    cout<<"\n\n\t*********** Delete Product ************";
    cout<<"\n\n\t 1) Product Code ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File Not Exist";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product Deleted Successfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;

        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token ==0)
        {
            cout<<"\n\n\t Record Not Found";
        }
    }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n*************************************************************\n";
    cout<<"ProNo  \t\t  Name  \t\t  Price \n";
    cout<<"\n\n*************************************************************\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<" \t\t "<<pname<<" \t\t "<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();

}

void shopping ::receipt()
{
    
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount =0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t************************* Product List***************************************";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
    }
    else
    {
        data.close();
        list ();
        cout<<"\n***********************************************\n";
        cout<<"\n                                               \n";
        cout<<"\n          Please place the order               \n";
        cout<<"\n                                               \n";
        cout<<"\n***********************************************\n";
       
       do
       {
            m:
            cout<<"\n\n Enter Product Code ==>";
            cin>>arrc[c];
            cout<<"\n\n Enter the Quantity ==>";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code.Please try again";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another Product ? if yes then press y else n ===> ";
            cin>>choice;
       }
       while(choice == 'y');

       cout<<"\n\n\t\t***************************************RECEIPT****************************************************\n";
       cout<<"\n Product No   \t  Product Name \t  Product Quantity  \t    Price  \t  Amount with discount \n";

       for(int i=0;i<c;i++)
       {
        data.open("database.txt",ios::in);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode == arrc[i])
            {
                amount =price * arrq[i];
                dis=amount -(amount*dis/100);
                total=total+dis;
                cout<<"\n"<<pcode<<" \t\t "<<pname<<"\t\t "<<arrq[i]<<" \t\t "<<price<<" \t\t "<<amount<<" \t\t "<<dis;
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();

       }
       


    }
    cout<<"\n\n*********************************************************************************************************";
    cout<<"\nTOtal Amount :"<<total;
    cout<<"\n Total Amount :"<<total;

}

int main()
{
    shopping s;
    s.menu();
}