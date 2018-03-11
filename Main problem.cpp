//Shereen Hassan Mohamed
//ID:20170130
//Assignment two: The affine cipher

#include <iostream>
#include <string>
#include <string.h>
#include <cctype>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    string arr, msg, out;
    char z;
    bool flag = false ;
    int a, b, c, i=0, j=0, eq=0,x=0, y=0;
    string choice;
    arr="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; //Array of all letters


    cout<<"Ahlan ya user ya habeby"<<endl;
    while(true){
            cout<<"Please enter 1 to cipher , 2 to decipher the message and 3 to end: "<<endl;
            cin>>choice;

     while(choice !="1" && choice !="2" && choice!="3")
    {
        cout<<"Please enter 1 to cipher , 2 to decipher the message and 3 to end: "<<endl;
        cin>>choice;
    }
    if(choice=="3"){
        cout<<"Thank you for using Affine cipher."<<endl;
        break;
    }

    cout<<"Please enter the message: "<<endl;
    msg="anything";
    cin.ignore();
    getline(cin,msg); //to get the full message


    cout<<"Please enter a: "<<endl;
    cin>>a; // used in calculating equations

    while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"Please enter another a: "<<endl; //if user entered invalid a and c
        cin>>a;
    }
    cout<<"Please enter b: "<<endl;
    cin>>b; // used in calculating equations
    while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"Please enter another b: "<<endl; //if user entered invalid a and c
        cin>>b;
    }
    cout<<"Please enter c: "<<endl;
    cin>>c; // used in calculating equations
    while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"Please enter another c: "<<endl; //if user entered invalid a and c
        cin>>c;
    }
    if(cin.fail()){
        cout<<"Please enter another a: "; //if user entered invalid a and c
        cin>>a;
    }



    while((a*c)%26 !=1)
    {
        cout<<"Please enter another a : "; //if user entered invalid a and c
        cin>>a;
        while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"Please enter another a: "<<endl; //if user entered invalid a and c
        cin>>a;}
        cout<<"Please enter another c: "<<endl;
        cin>>c; // used in calculating equations
        while(cin.fail()){
        cin.clear();
        cin.ignore();
        cout<<"Please enter another c: "<<endl; //if user entered invalid a and c
        cin>>c;}

    }




    if((a*c)%26==1)
    {
        if(choice=="1")  //user chose to cipher the message
        {

            for(i=0; i<strlen(msg.c_str()); i++)
            {

                for(j=0; j<strlen(arr.c_str()); j++)
                {

                    flag = false ;
                    if(msg[i] == ' ')
                    {
                        out += ' ' ;
                        flag = true ;
                        break;
                    } //3alashan law space tb2a zy mahya


                    if(msg[i]==arr[j])
                    {
                        x=j;
                        eq=((a*x)+b)%26; //cipher equation
                        out += arr[eq];
                        flag = true ;
                        break;

                    }



                }
                if(flag == false) // the flag is for checking whether msg[i]  matched any of the alphabets or not if matched it will be set to true else it will be false
                {
                    out += msg[i] ;
                }

            }
            cout<<"The ciphered message is: "<<out<<endl; //out is the full output message
            out.erase(); //3alashan lma yedkhol fe loop tanya tb2a


        }
        if(choice=="2")
        {
            for(i=0; i<strlen(msg.c_str()); i++)
            {

                for(j=0; j<strlen(arr.c_str()); j++)
                {
                    flag = false ;
                    if(msg[i] == ' ')
                    {
                        out += ' ' ;
                        flag = true ;
                        break;
                    } //3alashan law space tb2a zy mahya


                    if(msg[i]==arr[j])
                    {
                        y=j;

                        eq=(c*(y-b))%26; //decipher equation
                        if(eq<0)
                        {
                            eq+=26;

                        }

                        out += arr[eq];
                        flag=true;

                        break;

                    }


                }
                if(flag == false) // the flag is for checking whether msg[i]  matched any of the alphabets or not if matched it will be set to true else it will be false
                {
                        out += msg[i] ;

                }
            }
            cout<<"The deciphered message is: "<<out<<endl;
            out.erase();

        }

    }
    }

    return 0;
}
