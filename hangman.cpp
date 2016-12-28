#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<ctime>
using namespace std;
const int MAX_LENGTH = 80;
int MAX_TRY =  10;
int MAX_LIST = 10;

void welcome();
void init_unknown(char [],char []);
int checking(char [],char [],char);
int main(){
   char word[MAX_LENGTH];
   char unknown[MAX_LENGTH];
   char guess_char;

    vector<string> words;
    words.push_back("dhaka");
    words.push_back("rajshahi");
    words.push_back("khulna");
    words.push_back("chittagong");
    words.push_back("sylhet");
    words.push_back("natore");
    words.push_back( "pabna");
    words.push_back("jossore");
    words.push_back("rongpur");
    words.push_back("dinajpur");
     char ch;
 while(ch!='e'){
    srand (time(NULL) );
  int n = rand() % 10;
strcpy( word, words[n].c_str());

welcome();
init_unknown(word,unknown);

cout<<"\n\n\n\tUNKNOWN WORD\n\n\t"<<unknown;
int guess_used=0;
while(guess_used<MAX_TRY){

cout<<"\n\n\n\tGuess a letter: ";
cin>>guess_char;
if(checking(word,unknown,guess_char)==0){
  cout<<"\n\n\n\tYOU ALREADY GUESSED THIS LETTER or LETTER IS NOT IN THE WORD";
}
else{
    cout<<"\n\n\tYAHOO! YOU FOUND A LETTER";
}
guess_used++;
cout<<"\n\n\n\tAFTER "<<guess_used<<" GUESS: \n\n\t";
cout<<unknown;
cout<<"\n\n\n\tYOU HAVE "<<MAX_TRY-guess_used<<" LEFT\t";
if(strcmp(word,unknown)==0){
    cout<<"\n\n\n\tCONGURATULATION!! YOU DID IT!!!!\n\t";

    cout<<"\n\n\n\tPRESS 'e' TO EXIT THE GAME or PRESS 'c' TO CONTINUE:";
    cin>>ch;
    break;
}
}
 if(MAX_TRY == guess_used){
    cout<<"\n\n\n\tSORRY YOU ARE OUT OF TRIES!!!\n\n"<<"\tTHE WORD WAS: \n\n\t"<<word;
cin.ignore();
    cout<<"\n\n\n\tPRESS 'e' TO EXIT THE GAME or PRESS 'c' TO CONTINUE: ";
    cin>>ch;
     }
 }
return 0;
}

void welcome(){
     system("cls");
cout<<"\n\n\n\tWELCOME TO HANGMAN GAME";
cout<<"\n\n\tYOU HAVE  "<<MAX_TRY <<" CHANCES TO GUESS THE WORD\n\n\t";
cin.get();
}

void init_unknown(char word[],char unknown[]){
    system("cls");
int i;
for(i=0;i<strlen(word);i++){
    unknown[i]='*';
}
unknown[i]='\0';

}
int checking(char word[],char unknown[],char guess_char){
int matches=0,i=0;
while(i < strlen(word)){

    if(guess_char == unknown[i])
    {
       break;
    }

     else if(guess_char == word[i])
     {
        unknown[i] = guess_char;
        matches++;
    }
    i++;
}

    return matches;

}
