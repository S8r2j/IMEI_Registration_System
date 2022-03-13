#include<iostream>
#include<fstream>
#include<iomanip>
#include<limits>
#include<time.h>
#include<string>
using namespace std;
void func();
class check
{
private:
    unsigned long long int IMEI;
    unsigned long long int totdata;
    long int lower=100,upper=100000;
    long int cc;
public:
    check()
    {
    ifstream k("number.txt");
    k>>totdata;
    fclose;
    srand(time(NULL));
    cc=(rand()%(upper-lower+1))+lower;
    }
    int checkdata()
    {
        unsigned long long int data[totdata];
        cout<<"Enter the IMEI number of your mobile"<<endl;
        cin>>IMEI;
        ifstream o("input.txt");
        for(int i=0;i<totdata;i++)
        {
            o>>data[i];
        }
        fclose;
        int m=0;
        for(int i=0;i<totdata;i++)
        {
            if(IMEI==data[i])
            {
                m=m+1;
            }
        }
        if(m>0)
        {
            cout<<"Already registered"<<endl;
            return 1;
        }
        else
        {
            cout<<"Not registered";
            return 0;
        }
    }
private:
     long long int mobile;
    unsigned long long int citizenid;
    string name1,name2;
    string brand;
public:
    int regdata()
    {
        cout<<"Enter your mobile IMEI number"<<endl;
        cin>>IMEI;
        unsigned long long int data[totdata];
        ifstream o("input.txt");
        for(int i=0;i<totdata;i++)
        {
            o>>data[i];
        }
        fclose;
        for(int i=0;i<totdata;i++)
        {
            if(IMEI==data[i])
            {cout<<"This IMEI number is already registered"<<endl;
            exit(1);}
        }
        cout<<"Enter your mobile brand"<<endl;
        cin>>brand;
        cout<<"Enter your name"<<endl;
        cin>>name1>>name2;
        cout<<"Enter your mobile number"<<endl;
        cin>>mobile;
        cout<<"Enter your id number of any identity card(passport or citizenship)"<<endl;
        cin>>citizenid;
        cout<<"Type 'submit' for submission of data"<<endl;
        string s3;
        cin>>s3;
        if(s3=="submit")
        {
        ofstream o("newregister.txt", ios::app);
        o<<IMEI<<setw(20);
        o<<brand<<setw(20);
        o<<mobile<<setw(20);
        o<<citizenid<<setw(20);
        o<<name1+" "+name2<<endl;
        fclose;
        cout<<"Your request has been submitted to the respected department"<<endl;
        ofstream l("number.txt");
        totdata=totdata+1;
        l<<totdata;
        fclose;
        ofstream k("input.txt", ios::app );
        k<<IMEI<<endl;
        fclose;
        cout<<"You are successfully registered"<<endl;
        return 1;
        }
        else {cout<<"Every detail must be filled up accurately"<<endl;
        return 0;}
    }
    int retailregister()
    {
        long int pannum;
        string s;
        cout<<"Enter the name of the company in one word"<<endl;
        cin>>s;
        cout<<"Enter the registration number of the company"<<endl;
        string s1;
        cin>>s1;
        cout<<"Enter the PAN Number"<<endl;
        cin>>pannum;
        cout<<"Enter your name"<<endl;
        cin>>name1>>name2;
        cout<<"Enter your mobile number"<<endl;
        cin>>mobile;
        cout<<"Enter your id number of any identity card(passport or citizenship"<<endl;
        cin>>citizenid;
         string p,p1;
        string p2, p3;
        int code;
        long long int mob;
        unsigned long long int id;
        string regnum;
        long int num;
        ifstream i("retailregister.txt");
        getline(i,p);
        for(int j=0;j<3;j++)
        {
        i>>code;
        i>>p1;
        i>>regnum;
        i>>num;
        i>>p2;
        i>>p3;
        i>>mob;
        i>>id;
        if(s1==regnum)
        {
            cout<<"This registration number is already registered"<<endl;
            exit(1);
        }
        if(pannum==num)
        {
            cout<<"This PAN Number is already registered"<<endl;
            exit(1);
        }
        }
        fclose;
        cout<<"Type 'submit' for the further process"<<endl;
        string s6;
        cin>>s6;
        if(s6=="submit")
        {
        cout<<"Your company has been registered"<<endl;
        ofstream o("retailregister.txt", ios::app);
        o<<cc<<setw(20);
        o<<s<<setw(25);
        o<<s1<<setw(25);
        o<<pannum<<setw(25);
        o<<name1+" "+name2<<setw(25);
        o<<mobile<<setw(25);
        o<<citizenid<<endl;
        fclose;
        cout<<"Your company registered code is: "<<cc<<endl;
        return 1;
        }
        return 0;
    }
    void retaildata()
    {
        long int nummob;
        cout<<"Enter the total number of mobiles"<<endl;
        cin>>nummob;
        string k[nummob];
        string brand1[nummob];
        unsigned long long int im[nummob];
        unsigned long long int data[totdata];
        for(int i=0;i<nummob;i++)
        {
        cout<<"Enter the model number of "<<i+1<<" mobile respectively"<<endl;
            cin>>k[i];
            cout<<"Enter the IMEI number of "<<i+1<<" mobile respectively"<<endl;
            cin>>im[i];
            cout<<"Enter the brand name of "<<i+1<<" mobile respectively"<<endl;
            cin>>brand1[i];
            ifstream o("input.txt");
            for(int i=0;i<totdata;i++)
            {
                o>>data[i];
            }
            fclose;
            for(int j=0;j<totdata;j++)
            {
                if(im[i]==data[j])
                {
                    cout<<"This IMEI number is already registered. Please provide the accurate data"<<endl;
                    return retaildata();
                }
            }
            ofstream k("input.txt", ios::app);
            k<<im[i]<<endl;
            fclose;
            ofstream l("number.txt");
            totdata=totdata+1;
            l<<totdata;
            fclose;
        }
        ofstream o("retailermobile.txt", ios::app);
        o<<cc<<endl;
        for(int u=0;u<nummob;u++)
        {
            o<<k[u]<<setw(20);
            o<<im[u]<<setw(20);
            o<<brand1[u]<<endl;
        }
        fclose;
        cout<<"Your data has been recorded"<<endl;
    }
    friend void func(check c);
};
 void func(check c)
        {cout<<"Are you an individual or a retailer"<<endl;
        string s5;
        cin>>s5;
        if(s5=="individual" or s5=="Individual")
        {
            int j;
            j=c.regdata();
            if(j==1 or j==0)
                {
                    exit (1);
                }
        }
        else if(s5=="retailer" or s5=="Retailer")
        {
            int k;
            k=c.retailregister();
            if(k==1)
            {
                c.retaildata();
            }
            else if(k==0)
            {
                cout<<"Provided information are incorrect."<<endl;
                exit(1);
            }
        }
        else{
            cout<<"Input not valid. Type 'individual' or 'retailer' for further process"<<endl;
        }
        }
int main()
{
    string s;
    check c;
    cout<<"Do you want to check or register your IMEI mobile number"<<endl;
    cin>>s;
    if(s=="check" or s=="Check")
    {
    int i;
    i=c.checkdata();
    if(i==1)
    {
        exit (1);
    }
    else if(i==0)
    {
        cout<<"\nWant to register now?"<<endl;
        string s1;
        cin>>s1;
          if(s1=="yes" or s1=="Yes")
        {
          func(c);
        }
    }
    }
    else if(s=="register" or s=="Register")
    {
       func(c);
    }
    else{
        cout<<"Invalid Input"<<endl;
    }
    return 0;
}
