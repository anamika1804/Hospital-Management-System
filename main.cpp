#include <iostream>
#include <iomanip>
#include <conio.h>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <cstdlib>
#include <string.h>
#include <limits>
#ifdef _WIN32
#define CLEAR "cls"
#else 
#define CLEAR "clear"
#endif

using namespace std;
struct doctor1
{   int id,age,exp;
    string fname,lname,Q,city,special;
};
struct patient1
{   int id1,age,charg,room;
    string fname,lname,city,dis,sym,con,date;
};
struct pharmacy1
{   string med; int tablets; double cost;
};
class doctor;
class patient;
class pharmacy;
class hospital
{   private:
    string password;
    public:
    int counter;
    hospital()
    {   counter=0;
        password="BCS2020";
    }
    void tot_no();
    bool checkpassword(string x);
    bool changepassword(string x);
    doctor select1(doctor d);
    patient select2(patient p);
    pharmacy select3(pharmacy P);
    pharmacy select4(pharmacy P);
};
bool hospital :: checkpassword(string x)
{   if (x==password)
    {   return true;
    }
    else
    {   return false;
    }
}
bool hospital :: changepassword(string x)
{   if (x==password)
    {   cout<<"Enter new password: ";
        cin>>password; 
        return true;
    }
    else
    {   return false;
    }
}
class doctor:public hospital
{   public:
    int docid;
    struct doctor1 arr[100];
    doctor()
    {   docid=0;
        counter=0;
        for(int i=0;i<100;i++)
        {   arr[i].id=0;
            arr[i].fname="";
            arr[i].lname="";
            arr[i].age=0;
            arr[i].Q="";
            arr[i].special="";
            arr[i].exp=0;
            arr[i].city="";
        }
    }  
    void add_doc_info();
    void Display();
    void doctor_detail();
    void tot_no();
};
void doctor :: tot_no()
{   system(CLEAR);
    cout<<"Total Number: "<<counter<<endl;
    cout<<endl;
    cout<<"Press Any Key to Exit.";   
    cin.get();
    getch();
}
void doctor :: add_doc_info()
{   int i,en;
    system(CLEAR);
    cout<<"Enter Number of Entries: "<<flush;
    cin>>en;
    cout<<endl;
    for(i=1;i<=en;i++)
    {   cout<<"Enter Doctor's ID                :";
        cin>>arr[docid].id;         cin.clear();
        cout<<"Enter Doctor's First Name        :";
        cin>>arr[docid].fname;      cin.clear();
        cout<<"Enter Doctor's Last Name         :";
        cin>>arr[docid].lname;      cin.clear();
        cout<<"Enter Doctor's Age               :";
        cin>>arr[docid].age;        cin.clear();
        cout<<"Enter Doctor's Qualification     :";
        cin>>arr[docid].Q;          cin.clear();
        cout<<"Enter Doctor's Specialization    :";
        cin>>arr[docid].special;    cin.clear();
        cout<<"Enter Doctor's Experience        :";
        cin>>arr[docid].exp;        cin.clear();
        cout<<"Enter Doctor's City              :";
        cin>>arr[docid].city;       cin.clear();
        docid++;
        counter++;
        cout<<"Added Successfully."<<endl;
    }
}
void doctor :: Display()
{   system(CLEAR);
    int n,i;
    if(docid==0)
    {   cout<<"No Doctor Entries Found."<<endl;
    }
    else
    {   cout<<"Enter Doctor's ID: "<<flush;
        cin>>n;
        int status=0;
        for(i=0;i<docid;i++)
        {   if(arr[i].id==n)
            {   status=1;
                break;
            }
        }
        if(status)
        {   cout<<"1.Doctor's ID                :"<<arr[i].id<<endl;
            cout<<"2.Doctor's First Name        :"<<arr[i].fname<<endl;
            cout<<"3.Doctor's First Name        :"<<arr[i].lname<<endl;
            cout<<"4.Doctor's Age               :"<<arr[i].age<<endl;
            cout<<"5.Doctor's Qualification     :"<<arr[i].Q<<endl;
            cout<<"6.Doctor's Specialization    :"<<arr[i].special<<endl;
            cout<<"7.Doctor's Experience        :"<<arr[i].exp<<endl;
            cout<<"8.Doctor's City              :"<<arr[i].city<<endl;
            cout<<endl;
            cout<<"Press Any Key to Exit.";   
            cin.get();
            getch();
        }
        else
        {   cout<<"Invalid Doctor ID."<<endl;
        }
        
    }
}
void doctor :: doctor_detail()
{   int i;
    system(CLEAR);
    if(docid==0)
    {   cout<<"No Doctor Entries Found."<<endl;
    }
    else
    {   cout<<"\t \t                    Details of All Doctors \n"<<endl;
        cout<<setw(7)<<"ID"<<setw(18)<<"First Name"<<setw(18)<<"Last Name"<<setw(14)<<"Age"<<setw(25)<<"Qualification"<<setw(25)<<"Specialization"<<endl;
        for(i=0;i<docid;i++)
        {    cout<<setw(7)<<arr[i].id<<setw(18)<<arr[i].fname<<setw(18)<<arr[i].lname<<setw(14)<<arr[i].age<<setw(25)<<arr[i].Q<<setw(25)<<arr[i].special<<endl;
        }
        cout<<endl;
        cout<<"Press Any Key to Exit.";   
        cin.get();
        getch();
    }
}
class patient:public hospital
{   public:
    int docid1;
    struct patient1 arr[100];
    patient()
    {   docid1=0;
        counter=0;
        for(int i=0;i<100;i++)
        {   arr[i].id1=0;
            arr[i].age=0;
            arr[i].fname="";
            arr[i].lname="";
            arr[i].dis="";
            arr[i].sym="";
            arr[i].room=0;
            arr[i].con="";
            arr[i].date="";
            arr[i].charg=0;
        }
    }
    void add_pat_info();
    void Display();
    void patient_detail();
    void tot_no();
};
void patient :: tot_no()
{   system(CLEAR);
    cout<<"Total Number: "<<counter<<endl;
    cout<<endl;
    cout<<"Press Any Key to Exit.";   
    cin.get();
    getch();
}
void patient :: add_pat_info()
{   int i,en;
    system(CLEAR);
    string x;
    cout<<"Enter Admin Password: "<<flush;
    cin>>x;
    if(checkpassword(x))
    {   cout<<"Enter Number of Entries: "<<flush;
        cin>>en;
        cout<<endl;
        for(i=1;i<=en;i++)
        {   cout<<"1. Enter Patient's ID             :";
            cin>>arr[docid1].id1;           cin.clear();
            cout<<"2. Enter Patient's Age            :";
            cin>>arr[docid1].age;           cin.clear();
            cout<<"3. Enter Patient's First Name     :";
            cin>>arr[docid1].fname;         cin.clear();
            cout<<"4. Enter Patient's Last Name      :";
            cin>>arr[docid1].lname;         cin.clear();
            cout<<"5. Enter Patient's Disease        :";
            cin>>arr[docid1].dis;           cin.clear();
            cout<<"6. Enter Patient's Symptoms       :";
            cin>>arr[docid1].sym;           cin.clear();
            cout<<"7. Enter Patient's Room No.       :";
            cin>>arr[docid1].room;          cin.clear();
            cout<<"8. Enter Patient's Condition      :";
            cin>>arr[docid1].con;           cin.clear();
            cout<<"9. Enter Patient's Admit Date     :";
            cin>>arr[docid1].date;          cin.clear();
            cout<<"10.Enter Patient's Room Charge    :";
            cin>>arr[docid1].charg;
            docid1++;
            counter++;
            cout<<"Added Successfully."<<endl;
            sleep(1);
        }
    }
    else
    {   cout<<"Incorrect Password."<<endl;
        sleep(1);
    }
}
void patient :: Display()
{   system(CLEAR);
    int n,i;
    if(docid1==0)
    {   cout<<"No Patient Entries Found."<<endl;
    }
    else
    {   cout<<"Enter Patients's ID: "<<flush;
        cin>>n;
        int status=0;
        for(i=0;i<docid1;i++)
        {   if(arr[i].id1==n)
            {   status=1;
                break;
            }
        }
        if(status==1)
        {   cout<<"1. Patient's ID               :"<<arr[i].id1<<endl;
            cout<<"2. Patient's First Name       :"<<arr[i].fname<<endl;
            cout<<"3. Patient's Last Name        :"<<arr[i].lname<<endl;
            cout<<"4. Patient's Age              :"<<arr[i].age<<endl;
            cout<<"5. Patient's Disease          :"<<arr[i].dis<<endl;
            cout<<"6. Patient's Symptoms         :"<<arr[i].sym<<endl;
            cout<<"7. Patient's Room No.         :"<<arr[i].room<<endl;
            cout<<"8. Patient's Condition        :"<<arr[i].con<<endl;
            cout<<"9. Patient's Admit Date       :"<<arr[i].date<<endl;
            cout<<"10.Patient's Room Charge      :"<<arr[i].charg<<endl;
            cout<<endl;
            cout<<"Press Any Key to Exit.";   
            cin.get();
            getch();
        }
        else
        {   cout<<"Invalid Patient ID."<<endl;
        }
    }
}
void patient :: patient_detail()
{   int i;
    system(CLEAR);
    string x;
    cout<<"Enter Admin Password: "<<flush;
    cin>>x;
    if(checkpassword(x))
    {   if(docid1==0)
        {   cout<<"No Patient Entries Found."<<endl;
        }
        else
        {   cout<<"\t \t                    Details of All Patients \n"<<endl;
            cout<<setw(7)<<"ID"<<setw(18)<<"First Name"<<setw(18)<<"Last Name"<<setw(14)<<"Age"<<setw(25)<<"Illness"<<setw(25)<<"Admission Date"<<endl;
            for(int i=0;i<docid1;i++)
            {    cout<<setw(7)<<arr[i].id1<<setw(18)<<arr[i].fname<<setw(18)<<arr[i].lname<<setw(14)<<arr[i].age<<setw(25)<<arr[i].dis<<setw(25)<<arr[i].date<<endl;
            }
            cout<<endl;
            cout<<"Press Any Key to Exit.";   
            cin.get();
            getch();
        }
    }
    else
    {   cout<<"Incorrect Password."<<endl;
        sleep(1);
    }
}

class pharmacy: public hospital
{   public:
    struct pharmacy1 arr[100];
    pharmacy()
    {   counter=0;
        for(int i=0;i<100;i++)
        {   arr[i].med="";
            arr[i].tablets=0;
            arr[i].cost=0;
        }
        arr[0].med="Disprin";
    arr[0].tablets=12;
    arr[0].cost=14;
    counter++;
    
    arr[1].med="Neurokind Plus";
    arr[1].tablets=10;
    arr[1].cost=99;
    counter++;
    
    arr[2].med="Febutaz";
    arr[2].tablets=15;
    arr[2].cost=178;
    counter++;
    
    arr[3].med="Nortryptomer";
    arr[3].tablets=10;
    arr[3].cost=217;
    counter++;
    
    arr[4].med="Naprosyn";
    arr[4].tablets=10;
    arr[4].cost=58;
    counter++;
    
    arr[5].med="Etrobax";
    arr[5].tablets=10;
    arr[5].cost=140;
    counter++;
    
    arr[6].med="Esclo Plus";
    arr[6].tablets=10;
    arr[6].cost=79;
    counter++;
    
    arr[7].med="Dolo";
    arr[7].tablets=15;
    arr[7].cost=30;
    counter++;
    
    arr[8].med="Sinarest";
    arr[8].tablets=10;
    arr[8].cost=48;
    counter++;
    
    arr[9].med="Addaprin";
    arr[9].tablets=10;
    arr[9].cost=10;
    counter++;

    }
    void manage();
    void buying();
    void billing(int billid[20]);
    void tot_no();
};
void pharmacy :: tot_no()
{   system(CLEAR);
    cout<<"Total Number: "<<counter<<endl;
    cout<<endl;
    cout<<"Press Any Key to Exit.";   
    cin.get();
    getch();
}
void pharmacy :: buying()
{   system(CLEAR);
    int billid[20];
    for(int i=0;i<20;i++)
    {   billid[i]=0;
    }
    cout<<"\t   Details of All Medicines \n"<<endl;
    cout<<setw(7)<<"ID"<<setw(20)<<"Name"<<setw(8)<<"Tablets"<<setw(8)<<"Cost"<<endl;
    for(int i=0;i<counter;i++)
    {    cout<<setw(7)<<i<<setw(20)<<arr[i].med<<setw(8)<<arr[i].tablets<<setw(8)<<arr[i].cost<<endl;
    }
    cout<<endl<<"Enter Number of Entries: "<<flush;
    int en;
    cin>>en;
    cout<<endl;
    int n,quantity;
    for(int i=1;i<=en;i++)
    {   cout<<"Enter ID         :";
        cin>>n;
        if(n>=0 && n<counter)
        {   cout<<"Enter Quantity   :";
            cin>>billid[n];
            cout<<"Added Successfully."<<endl<<endl;
        }
        else
        {   cout<<"Invalid Medicine ID."<<endl<<endl;
        }
    }
    if(en>0)
    {   cout<<"Press Any Key to Print Bill.";   
        cin.get();
        getch();
        billing(billid);
    }
}
void pharmacy :: billing(int billid[20])
{   system(CLEAR);
    cout<<"\t\t\t      *** BILL *** \n"<<endl;
    cout<<setw(7)<<"ID"<<setw(20)<<"Name"<<setw(15)<<"Quantity"<<setw(8)<<"Cost"<<setw(15)<<"Total Cost"<<endl;
    double cost=0;
    for(int i=0; i<20; i++)
    {   if(billid[i]!=0)
        {   cout<<setw(7)<<i<<setw(20)<<arr[i].med<<setw(15)<<billid[i]<<setw(8)<<arr[i].cost<<setw(15)<<billid[i]*arr[i].cost<<endl;
            cost=cost+billid[i]*arr[i].cost;
        }
        else
        {   continue;
        }
    }
    cout<<endl<<"\t \t \t   Total Cost: "<<cost<<endl;
    cout<<"          Please Pay and Collect Your Medicines at the Counter"<<endl<<endl;
    cout<<"Press Any Key to Exit.";   
    cin.get();
    getch();
}
void pharmacy :: manage()
{   system(CLEAR);
    string x;
    cout<<"Enter Admin Password: "<<flush;
    cin>>x;
    if(checkpassword(x))
    {   int en;
        cout<<"Enter Number of Entries: "<<flush;
        cin>>en;
        cout<<endl;
        for(int i=1;i<=en;i++)
        {   cout<<"Enter Medicine Name      :";
            cin>>arr[counter].med;      cin.clear();
            cout<<"Enter Number of Tablets  :";
            cin>>arr[counter].tablets;  cin.clear();
            cout<<"Enter Medicine Cost      :";
            cin>>arr[counter].cost;     cin.clear();
            cout<<"Added Successfully."<<endl;
            counter++;
        }
    }
    else
    {   cout<<"Incorrect Password."<<endl;
        sleep(1);
    }
}
doctor hospital :: select1(doctor d)
{   char ch;
    string x;
    cout<<"Enter Admin Password: "<<flush;
    cin>>x;
    if(d.checkpassword(x))
    {   cout<<"*** Welcome To Doctor's Database ***"<<endl;
        cout<<"1. Add New Doctor's Information"<<endl;   
        cout<<"2. Display Doctor's Information"<<endl;
        cout<<"3. Details of All The Doctors in Hospital"<<endl;
        cout<<"4. Total Number of Doctor's in Hospital"<<endl;
        cout<<"X. Exit"<<endl;
        cout<<"Enter your choice: "<<flush;
        cin>>ch;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(ch=='1')
        {   sleep(1);
            d.add_doc_info();
            sleep(1);
        }    
        else if(ch=='2')
        {   sleep(1);
            d.Display();
            sleep(1);
        }
        else if(ch=='3')
        {   sleep(1);
            d.doctor_detail();
            sleep(1);
        }
        else if(ch=='4')
        {   sleep(1);
            d.tot_no();
            sleep(1);
        }
        else
        {   sleep(1);
        }
    }
    else
    {   cout<<"Incorrect Password."<<endl;
        sleep(1);
    }
    return d;
}
patient hospital :: select2(patient p)
{   char ch;
    cout<<"*** Welcome To Patient's Database ***"<<endl;
    cout<<"1. Add New Patient's Information"<<endl;
    cout<<"2. Display Patient's Information"<<endl;
    cout<<"3. Detail OF All The Patient's In The Hospital"<<endl;
    cout<<"4. Total Number of Patient's in Hospital"<<endl;
    cout<<"X. Exit"<<endl;
    cout<<"Enter your choice: "<<flush;
    cin>>ch;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(ch=='1')
    {   sleep(1);
        p.add_pat_info();
        sleep(1);
    }    
    else if(ch=='2')
    {   sleep(1);
        p.Display();
        sleep(1);
    }
    else if(ch=='3')
    {   sleep(1);
        p.patient_detail();
        sleep(1);
    }
    else if(ch=='4')
    {   sleep(1);
        p.tot_no();
        sleep(1);
    }    
    else
    {   sleep(1);
    }
    return p;
}
pharmacy hospital :: select3(pharmacy P)
{   char ch;
    cout<<"*** Welcome To Pharmacy ***"<<endl;
    cout<<"1. Buy Medicines"<<endl;
    cout<<"2. Add Medicines To Database"<<endl;
    cout<<"3. Check Total Number of Medicines in Inventory"<<endl;
    cout<<"X. Exit"<<endl;
    cout<<"Enter your choice: "<<flush;
    cin>>ch;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(ch=='1')
    {   sleep(1);
        P.buying();
        sleep(1);
    }    
    else if(ch=='2')
    {   sleep(1);
        P.manage();
        sleep(1);
    }
    else if(ch=='3')
    {   sleep(1);
        P.tot_no();
        sleep(1);
    }
    else
    {   sleep(1);
    }
    return P;
}
pharmacy hospital :: select4(pharmacy P)
{   string x;
    cout<<"Enter Admin Password: "<<flush;
    cin>>x;
    if(P.changepassword(x))
    {   cout<<"Password Changed Successfully."<<endl;
        sleep(1);
    }
    else
    {   cout<<"Incorrect Password."<<endl;
        sleep(1);
    }
    return P;
}
int main()
{   bool repeat= true;
    char ch;
    doctor d;
    patient p;
    pharmacy P;
    while(repeat)
    {   system(CLEAR);
        cout<<"*** Welcome to the Hospital Management System ***"<<endl;
        cout<<"1. Enter into Doctor's Database"<<endl;
        cout<<"2. Enter into Patient's Database"<<endl;
        cout<<"3. Enter into Pharmacy"<<endl;
        cout<<"4. Change Admin Password"<<endl;
        cout<<"X. Exit"<<endl;
        cout<<"Enter your choice: "<<flush;
        sleep(1);
        cin>>ch;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        system(CLEAR);
        if(ch=='1')
        {   d=d.select1(d);
        }
        else if(ch=='2')
        {   p=p.select2(p);
        }
        else if(ch=='3')
        {   P=P.select3(P);
        }
        else if(ch=='4')
        {   P=P.select4(P);
        }
        else
        {    return 0;
        }
    }
    return 0;

}
