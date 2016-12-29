#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <windows.h>// for system('cls');
#include <stdio.h>
#include <process.h>
#include <time.h>

using namespace std;

class entry {
char ans[20], user[20];
public:
char que[30];
void re(){
        cout.write(ans,20);
}
void ideal(){
        cin.getline(ans,20);
}
void getUser(char u[20]){
        strcpy(user,u);
}
} no1;

class bot {
// Using string.h header to create objects of strings.
char id[30], re[20], ideal[20], userName[10];
public:
//Constuctor to make object of bot.
bot(char n[20]){
        cout<<"\n\n\n\t\tHey there, this is Devdutt \n\n\nBefore you start to chat with my bot, can I get your name?\n" << endl;
        cin.getline(userName,20);
        strcpy(n,userName);
}
void reply(char []);
void rename(char n[]){
        strcpy(n,userName);
}
}; // End definition of class bot

// Teach AI to reply.
void bot :: reply(char input[30]){
        fstream M;
        // Open the textfile for input.
        M.open("memory.bin", ios::in | ios::binary);
        // Search through the file until end is reached.
        while( M ) {
                M.read((char*)&no1,sizeof(no1));
                strcpy(id,no1.que); // Get next input.
                // Check whether id is what we are looking for.
                if(id == input) {
                        no1.re(); // If so, get related reply.
                }
        }
        // If reply couldn't find input in textfile close it!
        M.close();
        // Open memory.dat for output, and use append at end of file.
        M.open("memory.bin", ios::out | ios::app| ios::binary);
        M.seekp(sizeof(no1),ios::end);
        strcpy(no1.que,input);   // Record initial input in memory.
        cout << "I don't know what you mean when you say \'" << input << "\', what should I say?\n\tIDEAL REPLY (PLEASE INPUT) : ";
        no1.ideal();    // Get the ideal output.
        no1.getUser(userName); // Save name of person who modified database.
        M.write((char*)&no1,sizeof(no1));    // Write the ideal output to memory.
        M.close();    // Close the file!
}

// Prototype of functions activated when the User wants.
void quiz();
void joke();
void showTime();
// Prototypes of functions used within program.
void dataRe();
int ask(char in[]);

int i,n;
char name[20];
bot AI(name);// Generate AI through bot API.

int main() {
        system("cls");
        cin.clear();
        cin.ignore();
        char input[30]; //Char variable to store answer for Exit.
        for(;; i++) { // Prompt User for input.
                cout<<name<<": ";
                cin.getline(input,30);
                cout<<"AI: ";
                n==ask(input);
                if(n==-1) return 0;
                cout<<endl;
        }
        return 0;
}

int ask(char in[30]){
        char y;
        //Give maximum number of fallbacks to greetings, to not miss.
        if(strcmp(in,"Hello")==0||strcmp(in,"hello")==0||strcmp(in,"Hi")==0||strcmp(in,"hi")==0) cout << "Hello there ";
        // Let the User decide whether to exit the program.
        else if(strcmp(in,"exit")==0||strcmp(in,"Exit")==0||strcmp(in,"X")==0) {
                cout << "\n\t\t\tAre you sure?(Y/N) \n\t\t\tYou have asked "<<i<<" questions.\n";
                if(y=='y'||y=='Y') return -1;
        }
        else if(strcmp(in,"name")==0||strcmp(in,"Name")==0) cout <<"\n\t\tMy name is V!\n\t\tcreated by Devdutt Shenoi ";
        else if(strcmp(in,"data")==0) dataRe();
        else if (strcmp(in,"ask me")==0||strcmp(in,"quiz")==0) quiz();
        else if (strcmp(in,"joke")==0||strcmp(in,"Joke")==0) joke();
        else if(strcmp(in,"What is the time?")==0||strcmp(in,"time")==0||strcmp(in,"Time")==0) showTime();
        /*Only if the User doen't want to exit should his question go to the AI.
           Pass User's input to the AI and let it respond.*/
        else AI.reply(in);
        return 0;
}

// Definitions pertaining to random functions.
void quiz() {
        int r = rand() % 4;
        char in[20];
        switch(r) {
        case 0: cout<<"\nWho is the PM of India?\n";
                cin.getline(in,20);
                if(strcmp(in,"Narendra Modi")==0||strcmp(in,"Modi")==0) {
                        cout<<"\nCorrect";
                        exit(0);
                }
        case 1: {cout<<"\nWho is the President of India?\n";
                 cin.getline(in,20);
                 if(strcmp(in,"Pranab Mukherjee")==0)
                         cout<<"\nCorrect";
                 exit(0);}
        case 2: cout<<"\nWho am I?\n";
                cin.getline(in,20);
                if(strcmp(in,"Artificial Intelligence")==0||strcmp(in,"AI")==0||strcmp(in,"V!")==0) {
                        cout<<"\nCorrect";
                        exit(0);
                }
        case 3: cout<<"\nWho is Steve Jobs?\n";
                cin.getline(in,20);
                if(strcmp(in,"Artificial Intelligence")==0||strcmp(in,"AI")==0||strcmp(in,"V!")==0) {
                        cout<<"\nCorrect";
                        exit(0);
                }
        default: exit(0);//Add more questions
        }
        cout<<"\nWrong answer";
}
void joke() {
        int r = rand() % 4;
        switch(r) {
        case 0: cout<<"\nAsk SiRi 'What is 10^200?' only if you are a musician."; break;
        case 1: cout<<"\nYou:'Who is Indian?'\nSiRi:'You must be Trump'"; break;
        case 2: cout<<"\nOnce a friend said 'I have 8GB RAM, 2TB HDD, 8core CPU, what do you have?'\nI answered I have a 'mac'"; break;
        case 3: cout<<"\nPhysics students want Newton to have been a Keralite, why?\n Becuase coconut has more 'm', giving a larger 'F'."; break;
        default: exit(0); //Add more jokes
        }
}
void showTime(){
        time_t rawtime;
        struct tm * timeinfo;

        time ( &rawtime );
        cout<<"The current date/time is: "<< ctime(&rawtime);
}
void dataRe(){
        ifstream in;
        in.open("memory.bin",ios::binary);
        cout<<endl;
        while( in ) {
                in.read((char*)&no1, sizeof(no1));
                cout<<"Q: ";
                cout.write(no1.que,30);
                cout<<"\nA: ";
                no1.re();
                cout<<endl;
        }
}
