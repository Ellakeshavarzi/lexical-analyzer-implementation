#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;


int fail(int start)
{
    int nextstart;

    switch (start)
    {
    case 1: nextstart = 10;
        break;
    case 10: nextstart = 15;
        break;
    case 15: nextstart = 19;
        break;
    case 19: nextstart = 23;
        break;
    case 23: nextstart = 25;
        break;
    case 25: nextstart = 28;
        break;
    case 28: nextstart = 32;
        break;
    case 32: nextstart = 36;
        break;
    case 36: nextstart = 42;
        break;
    case 42: nextstart = 45;
        break;
    case 45: nextstart = 47;
        break;
    case 47: nextstart = 50;
        break;
    case 50: nextstart = 53;
        break;
    case 53: nextstart = 56;
        break;
    case 56: nextstart = 61;
    	break;
    
    }
    return nextstart;

}




bool  isKeyword(string str)				//check if the given substring is a keyword or not
{
	bool x = false ;
    string array[] = {"if","else","while","do","break",
	"continue","int","double","float","return",
	"char","case","long","short","typedef",
	"switch","unsigned","void","static","struct",
	"sizeof","asm","volatile","auto","enum",
	"const","union","extern","bool","register",
	"for","signed","default","goto","catch",
	"class","const_cast","delete","dynamic_cast","explicit",
	"export","false","friend","inline","mutable",
	"namespace","new","operator","private","protected",
	"public","reinterpret_cast","static_cast","template","this",
	"throwv","true","try","typeid","typename",
	"using","virtual","cout","cin"};
	for(int i = 0 ;i<64;i++){if(str==array[i]) x =true;}
	return x ;

}


    void LexicalAnalyzer() 
    {

        int state, start, loc = 1;
        char ch;
        FILE* fp;
        fp = fopen("source.txt", "r");
        ofstream output("output.txt");
        state = 1;
        start = 1;


        string word = "";
        string word2 = "";

        while(1)
            switch (state)
            {
                
                case 1:         //DFA 1  float

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if (ch == '+' || ch == '-')
                        state = 2 ;

                    else if (ch == '.')
                        state = 4;

                    else if (ch >= '0' && ch <= '9')
                        state = 3;
                    else if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t') 
                        state = 35;
                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 2:

                    ch = getc(fp);
                    word += ch;

                    if (ch >= '0' && ch <= '9')
                    state = 3;

                    else if (ch == '.')
                        state = 4;

                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 3:

                    ch = getc(fp);
                    word += ch;

                    if (ch == '.')
                        state = 5;

                    else if (ch >= '0' && ch <= '9')
                        state = 3;

                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 4:

                    ch = getc(fp);
                    word += ch;

                    if (ch >= '0' && ch <= '9')
                        state = 6;

                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 5:
                    word2=word;
                    ch = getc(fp);
                    word += ch;

                    if (ch == 'e' || ch == 'E')
                        state = 8;
                    else if (ch >= '0' && ch <= '9')
                        state = 7;
					else if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t') {
                        cout << word2 << " : " << "Float\n";
                        output << word2 << " : " << "Float\n";
                        state = 35;}
                    else if ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='%')||(ch=='/')||(ch=='=')||(ch=='^')||(ch=='<')||(ch=='>')||(ch=='!')||(ch=='!')||(ch==44)||(ch=='|')
					||(ch=='~')||(ch==59)||(ch=='<')||(ch=='>')||(ch=='?')||(ch=='#')||(ch=='.')||(ch=='[')||(ch==']')||(ch==40)||(ch==41)||(ch==125)||(ch==123)||(ch==':')||(ch=='&')){
                    	cout << word2 << " : " << "Float\n";
                        output << word2 << " : " << "Float\n";
                        state = 59;
					}
                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 6:
                	word2=word;
                    ch = getc(fp);
                    word += ch;

                    if (ch >= '0' && ch <= '9')
                        state = 6;

                    else if (ch == 'e' || ch == 'E')
                        state = 8;

                    else if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t') {
                        cout << word2 << " : " << "float\n";
                        output << word2 << " : " << "float\n";
                        state = 35;
                    }
					else if ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='%')||(ch=='/')||(ch=='=')||(ch=='^')||(ch=='<')||(ch=='>')||(ch=='!')||(ch==44)||(ch=='|')||(ch=='~')||(ch==59)||(ch=='<')||(ch=='>')||(ch=='?')||(ch=='#')||(ch=='.')||(ch=='[')||(ch==']')||(ch==40)||(ch==41)||(ch==125)||(ch==123)||(ch==':')||(ch=='&')){
                    	cout << word2 << " : " << "Float\n";
                        output << word2 << " : " << "Float\n";
                        state = 59;
					}
                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                    
                case 7:
                	word2=word;
                    ch = getc(fp);
                    word += ch;

                    if (ch >= '0' && ch <= '9')
                        state = 7;

                    else if (ch == 'e' || ch == 'E')
                        state = 8;

                    else if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t') {
                        cout << word2 << " : " << "float\n";
                    	output << word2 << " : " << "float\n";
                        state = 35;
                    }
					else if ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='%')||(ch=='/')||(ch=='=')||(ch=='^')||(ch=='<')||(ch=='>')||(ch=='!')||(ch=='!')||(ch==44)||(ch=='|')||(ch=='~')||(ch==59)||(ch=='<')||(ch=='>')||(ch=='?')||(ch=='#')||(ch=='.')||(ch=='[')||(ch==']')||(ch==40)||(ch==41)||(ch==125)||(ch==123)||(ch==':')||(ch=='&')){
                    	cout << word2 << " : " << "Float\n";
                        output << word2 << " : " << "Float\n";
                        state = 59;
					}
                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 8:

                    ch = getc(fp);
                    word += ch;

                    if (ch >= '0' && ch <= '9')
                        state = 9;
                	else if(ch =='+'||ch=='-')
                    	state =63;
                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 9:
                	word2=word;
                    ch = getc(fp);
                    word += ch;

                    if (ch >= '0' && ch <= '9')
                        state = 9;

                    else if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t') {
                        cout << word2 << " : " << "float\n";
                        output << word2 << " : " << "float\n";
                        state = 35;
                    }
					else if ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='%')||(ch=='/')||(ch=='=')||(ch=='^')||(ch=='<')||(ch=='>')||(ch=='!')||(ch=='!')||(ch==44)||(ch=='|')||(ch=='~')||(ch==59)||(ch=='<')||(ch=='>')||(ch=='?')||(ch=='#')||(ch=='.')||(ch=='[')||(ch==']')||(ch==40)||(ch==41)||(ch==125)||(ch==123)||(ch==':')||(ch=='&')){
                    	cout << word2 << " : " << "Float\n";
                        output << word2 << " : " << "Float\n";
                        state = 59;
					}
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 10:        //DFA 2   integer

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if (ch == '+' || ch == '-')
                        state = 11;

                    else if (ch >= '0' && ch <= '9')
                        state = 12;

                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 11:

                    ch = getc(fp);
                    word += ch;

                    if (ch >= '0' && ch <= '9')
                        state = 12;

                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 12:
                	word2=word;
                    ch = getc(fp);
                    word += ch;

                    if (ch >= '0' && ch <= '9')
                        state = 12;

                    else if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t') 
                    {
                        cout << word2 << " : " << "Integer\n";
                        output << word2 << " : " << "Integer\n";
                        state = 35;
                    }
 					else if ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='%')||(ch=='/')||(ch=='=')||(ch=='^')||(ch=='<')||(ch=='>')||(ch=='!')||(ch=='!')||(ch==44)
					 ||(ch=='|')||(ch=='~')||(ch==59)||(ch=='<')||(ch=='>')||(ch=='?')||(ch=='#')||(ch=='.')||(ch=='[')||(ch==']')||(ch==40)||(ch==41)||(ch==125)
					 ||(ch==123)||(ch==':')||(ch=='&'))
					 {
                    	cout << word2 << " : " << "Integer\n";
                        output << word2 << " : " << "Integer\n";
                        state = 59;
					}
                    else if (ch == 'e' || ch == 'E')
                        state = 13;

                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 13:

                    ch = getc(fp);
                    word += ch;

                    if (ch >= '0' && ch <= '9')
                        state = 14;
                    else if(ch =='+'||ch=='-')
                    	state =64;
                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 14: 
                	word2=word;
                    ch = getc(fp);
                    word += ch;

                    if (ch >= '0' && ch <= '9')
                        state = 14;

                      
                    else if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t') 
                    {
                        cout << word2 << " : " << "Integer\n";
                        output << word2 << " : " << "Integer\n";
                        state = 35;
                    }
					else if ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='%')||(ch=='/')||(ch=='=')||(ch=='^')||(ch=='<')||(ch=='>')||(ch=='!')||(ch=='!')||(ch==44)||(ch=='|')||(ch=='~')||(ch==59)||(ch=='<')||(ch=='>')||(ch=='?')||(ch=='#')||(ch=='[')||(ch==']')||(ch==40)||(ch==41)||(ch==125)||(ch==123)||(ch==':')||(ch=='&')){
                    	cout << word2 << " : " << "Integer\n";
                        output << word2 << " : " << "Integer\n";
                        state = 59;
                	}
                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 15:            //DFA 3    integer_hex

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if (ch == '0')
                        state = 16;

                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 16:

                    ch = getc(fp);
                    word += ch;

                    if (ch == 'x' || ch == 'X')
                        state = 17;

                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;


                case 17:

                    ch = getc(fp);
                    word += ch;

                    if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'f' || ch >= 'A' && ch <= 'F')
                        state = 18;

                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 18:
                	word2=word;
                    ch = getc(fp);
                    word += ch;

                    if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'f' || ch >= 'A' && ch <= 'F')
                        state = 18;

                    else if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t')
                    {
                        cout << word2 << " : " << "Integer_hex\n";
                        output << word2 << " : " << "Integer_hex\n";
                        state = 35;
                    }
					else if ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='%')||(ch=='/')||(ch=='=')||(ch=='^')||(ch=='<')||(ch=='>')||(ch=='!')||(ch=='!')||(ch==44)||(ch=='|')||(ch=='~')||(ch==59)||(ch=='<')||(ch=='>')||(ch=='?')||(ch=='#')||(ch=='.')||(ch=='[')||(ch==']')||(ch==40)||(ch==41)||(ch==125)||(ch==123)||(ch==':')||(ch=='&')){
                    	cout << word2 << " : " << "Integer_hex\n";
                        output << word2 << " : " << "Integer_hex\n";
                        state = 59;
                	}
                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;


                case 19:            //DFA 4  integer_binary

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if (ch == '0')
                        state = 20;

                    else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 20:

                    ch = getc(fp);
                    word += ch;

                    if (ch == 'b' || ch == 'B')
                        state = 17;

                    else 
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 21:

                    ch = getc(fp);
                    word += ch;

                    if (ch == '0' || ch == '1')
                        state = 22;

                    else 
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 22:
                	word2=word;
                    ch = getc(fp);
                    word += ch;

                    if (ch == '0' || ch == '1')
                        state = 22;

                    else if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t')
                    {
                        cout << word2 << " : " << "Integer_binary\n";
                        output << word2 << " : " << "Integer_binary\n";
                        state = 35;
                    }
					else if ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='%')||(ch=='/')||(ch=='=')||(ch=='^')||(ch=='<')||(ch=='>')||(ch=='!')||(ch=='!')||(ch==44)||(ch=='|')||(ch=='~')||(ch==59)||(ch=='<')||(ch=='>')||(ch=='?')||(ch=='#')||(ch=='.')||(ch=='[')||(ch==']')||(ch==40)||(ch==41)||(ch==125)||(ch==123)||(ch==':')||(ch=='&')){
                    	cout << word2 << " : " << "Integer_binary\n";
                        output << word2 << " : " << "Integer_binary\n";
                        state = 59;
                	}
                    else 
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 23:        //DFA 5    identifier

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_')
                        state = 24;

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 24:
                	word2=word;
                    ch = getc(fp);
                    word += ch;

                    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_')
                        state = 24;

                    else if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t') 
                    {
                        int result = isKeyword(word2);
                        if (result == true){
                            cout << word2 << ":" << "Keyword\n";
                            output << word2 << ":" << "Keyword\n";
                            state = 35;
                        }
                        else
                        {
                            cout << word2 << ":" << "Identifier\n";
                            output << word2 << ":" << "Identifier\n";
                            state = 35;
                        }
						
                    }
					else if ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='%')||(ch=='/')||(ch=='=')||(ch=='^')||(ch=='<')||(ch=='>')||(ch=='!')||(ch=='!')||(ch==44)||(ch=='|')||(ch=='~')||(ch==59)||(ch=='<')||(ch=='>')||(ch=='?')||(ch=='#')||(ch=='.')||(ch=='[')||(ch==']')||(ch==40)||(ch==41)||(ch==125)||(ch==123)||(ch==':'))
                    {
                        int result = isKeyword(word2);
                        if (result == true){
                            cout << word2 << ":" << "Keyword\n";
                            output << word2 << ":" << "Keyword\n";
                            state = 59;
                        } 
                        else
                        {
                            cout << word2 << ":" << "Identifier\n";
                            output << word2 << ":" << "Identifier\n";
                            state = 59;
                        }
                    }
                    else if ((ch=='\"')||(ch=='\'')||(ch==','))
                    {
                        int result = isKeyword(word2);
                        if (result == true){
                            cout << word2 << ":" << "Keyword\n";
                            output << word2 << ":" << "Keyword\n";
                            state = 60;
                        }
                        else
                        {
                            cout << word2 << ":" << "Identifier\n";
                            output << word2 << ":" << "Identifier\n";
                            state = 60;
                        }
						
                    }
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 25:                //DFA 6    string

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if (ch == '\"')
                        state = 26;

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 26:

                    ch = getc(fp);
                    word += ch;

                    if ((ch>=32&&ch<34)||(ch>34&&ch<=126))
                        state = 26;

                    else if (ch == '\"')
                        state = 27;
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 27:
					word2=word;
                    ch = getc(fp);
                    word += ch;

                    if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t')
                    {
                    cout << word2 << " : " << "String\n";
                    output << word2 << " : " << "String\n";
                    state = 35;
                    }
                	else if ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='%')||(ch=='/')||(ch=='=')||(ch=='^')||(ch=='<')||(ch=='>')||(ch=='!')||(ch=='!')||(ch==44)||(ch=='|')||(ch=='~')||(ch==59)||(ch=='<')||(ch=='>')||(ch=='?')||(ch=='#')||(ch=='.')||(ch=='[')||(ch==']')||(ch==40)||(ch==41)||(ch==125)||(ch==123)||(ch==':')||(ch==',')){
				        cout << word2 << " : " << "String\n";
                    	output << word2 << " : " << "String\n";
                        state = 59;	}
                     else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
					
                case 28:            //DFA 7  character

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if (ch == '\'')
                        state = 29;

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 29:

                    ch = getc(fp);
                    word += ch;
                    if (ch == 92){ch = getc(fp);
							if(ch =='n'){word+=ch;state = 30;}
							else if(ch =='\''){word+=ch;state = 30;}
							else if(ch =='\"'){word+=ch;state = 30;}
							else if(ch =='t'){word+=ch;state = 30;}
							else {
							ungetc(ch, fp);state=30;}
					}
                	else if ((ch >= 32 && ch < 39)||(ch>39&&ch<=127)){
                        state = 30;}

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                    
                case 30:
                	ch = getc(fp);
                    word += ch;
                    if (ch == '\'')
                        state = 31;

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 31:
					word2=word;
                    ch = getc(fp);
                    word += ch;
                    if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t')
                    {
                        cout << word2 << " : " << "Character\n";
                        output << word2 << " : " << "Character\n";
                        state = 35;
                    }
					else if ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='%')||(ch=='/')||(ch=='=')||(ch=='^')||(ch=='<')||(ch=='>')||(ch=='!')||(ch=='!')||(ch==44)||(ch=='|')||(ch=='~')||(ch==59)||(ch=='<')||(ch=='>')||(ch=='?')||(ch=='#')||(ch=='.')||(ch=='[')||(ch==']')||(ch==40)||(ch==41)||(ch==125)||(ch==123)||(ch==':')){
				        cout << word2 << " : " << "Character\n";
                        output << word2 << " : " << "Character\n";
                        state = 59;	}
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 32:            //DFA 8         pointer

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_')
                        state = 33;

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 33:

                    ch = getc(fp);
                    word += ch;

                    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_')
                        state = 33;

                    else if (ch == '*')
                        state = 34;

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;

                case 34:
                	word2=word;
                    ch = getc(fp);
                    word += ch;

                    if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t')
                    {
                        cout << word2 << " : " << "pointer\n";
                        output << word2 << " : " << "pointer\n";
                        state = 35;
                    }

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                    
            	case 35:
            	word="";
                ch = getc(fp);
                if (ch == ' ' || ch == '\n'||ch=='\t')
                    state = 35;
                else if (ch == EOF){
				
                    output.close();
                    exit(0);}
                else {
                    ungetc(ch, fp);
                    start = 1;
                    state = 1;
                }
                break;
                
				case 36:            //DFA 9 comment        

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if (ch=='/')
                        state = 37;

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                  case 37:
                    ch = getc(fp);
                    word += ch;

                    if (ch=='/')
                        state = 38;
                    else if(ch=='*')
                    	state = 39;
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                 case 38:
					word2=word;
                    ch = getc(fp);
                    word += ch;
					if ((ch!='\n')&&(ch>=22)&&(ch<=127))
                    state = 38;
                    else if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t')
                    {
                        cout << word2 << " : " << "comment\n";
                        output << word2 << " : " << "comment\n";
                        state = 35;
                    }
                   
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                 case 39:
                    ch = getc(fp);
                    word += ch;
                    if(ch=='*')
                    state = 40 ;
                    else if ((ch=='\n')||(ch>=22)&&(ch<=127))
                    state = 39;
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                 case 40:
                    ch = getc(fp);
                    word += ch;
                    if(ch=='/')
                    state = 41 ;
                    else if ((ch=='\n')||((ch>=22)&&(ch<=127)))
                    state = 39;
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break; 
                case 41:
					word2=word;
                    ch = getc(fp);
                    word += ch;
                    if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t')
                    {
                        cout << word2 << " : " << "Comment\n";
                        output << word2 << " : " << "Comment\n";
                        state = 35;
                    }
                    else if ((ch>=22)&&(ch<=127)){
				        cout << word2 << " : " << "Comment\n";
                        output << word2 << " : " << "Comment\n";
                        state = 60;	}
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                	}
                    break;
                case 42:            //DFA 10 operator       

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='%')||(ch=='/')||(ch=='=')||(ch=='^')||(ch=='<')||(ch=='>')||(ch=='!'))
                        state = 43;
					else if (ch == '|'){ch = getc(fp);
							if(ch =='|'){word+=ch;state = 43;}
							else {
							ungetc(ch, fp);state=43;}
					}
					else if (ch == '&'){ch = getc(fp);
							if(ch =='&'){word+=ch;state = 43;}
							else {
							ungetc(ch, fp);state=43;}
					}
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                 case 43:
					word2=word;
                    ch = getc(fp);
                    word += ch;
                    if(ch=='=')
					    state=44;
                    else if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t')
                    {
                        cout << word2 << " : " << "Operator\n";
                        output << word2 << " : " << "Operator\n";
                        state = 35;
                    }
                    else if ((ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '_')||(ch == 40)||(ch == 41)||(ch == 39)||(ch == 34)){
                    	cout << word2 << " : " << "Operator\n";
                        output << word2 << " : " << "Operator\n";
						state = 60;
					}
                   
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                	}
                    break;
                 case 44:
					word2=word;
                    ch = getc(fp);
                    word += ch;
                    if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t')
                    {
                        cout << word2 << " : " << "Operator\n";
                        output << word2 << " : " << "Operator\n";
                        state = 35;
                    }
                    else if ((ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '_')||(ch == 40)||(ch == 41)||(ch == 39)||(ch == 34)){
                    	cout << word2 << " : " << "Operator\n";
                        output << word2 << " : " << "Operator\n";
						state = 60;
					}
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                	}
                    break;
                case 45:            //DFA 11 punctuators       

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;
                    if ((ch=='!')||(ch==44)||(ch=='|')||(ch=='~')||(ch==59)||(ch=='<')||(ch=='>')||(ch=='?')||(ch=='#')||(ch=='.')||(ch=='[')||(ch==']')||(ch==40)||(ch==41)||(ch==125)||(ch==123)||(ch==':')||(ch==','))
                        state = 46;

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                case 46:
					word2=word;
                    ch = getc(fp);
                    word += ch;
                    if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t')
                    {
                        cout << word2 << " : " << "Punctuators\n";
                        output << word2 << " : " << "Punctuators\n";
                        state = 35;
                    }
                    else if ((ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||(ch=='\"')|| (ch == '_')||(ch=='+')||(ch=='-')||(ch=='*')||(ch=='%')||(ch=='/')||(ch=='=')||(ch=='^')||(ch=='!')||(ch=='|')||(ch=='&')||(ch==40)||(ch==41)||(ch==123)||(ch==125)||(ch==59)||(ch==58)||(ch=='[')||(ch==']'))
                    {cout << word2 << " : " << "Punctuators\n";
                        output << word2 << " : " << "Punctuators\n";
						state = 60;}
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                	}
                    break;
                case 47:            //DFA 12 operator ++       

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if (ch=='+')
                        state = 48;

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                    case 48:                  

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if (ch=='+')
                        state = 49;

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                case 49:
					word2=word;
                    ch = getc(fp);
                    word += ch;
                    if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t')
                    {
                        cout << word2 << " : " << "operator\n";
                        output << word2 << " : " << "operator\n";
                        state = 35;
                    }
                    else if ((ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '_')||(ch == 40)||(ch == 41)||(ch == 39)||(ch == 34)){
                    	cout << word2 << " : " << "Operator\n";
                        output << word2 << " : " << "Operator\n";
						state = 60;}
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                	}
                    break;
                case 50:            //DFA 13 operator --       

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if (ch=='-')
                        state = 51;

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                case 51:                  

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if (ch=='-')
                        state = 52;

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                case 52:
					word2=word;
                    ch = getc(fp);
                    word += ch;
                    if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t')
                    {
                        cout << word2 << " : " << "Operator\n";
                        output << word2 << " : " << "Operator\n";
                        state = 35;
                    }
                    else if ((ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '_')||(ch == 40)||(ch == 41)||(ch == 39)||(ch == 34)){
                    	cout << word2 << " : " << "Operator\n";
                        output << word2 << " : " << "Operator\n";
						state = 60;}
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                	}
                    break;
                    case 53:            //DFA 14 operator >>      

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if (ch=='>')
                        state = 54;

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                case 54:                  

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if (ch=='>')
                        state = 55;

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                case 55:
					word2=word;
                    ch = getc(fp);
                    word += ch;
                    if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t')
                    {
                        cout << word2 << " : " << "Operator\n";
                        output << word2 << " : " << "Operator\n";
                        state = 35;
                    }
                    else if ((ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '_')||(ch == 40)||(ch == 41)||(ch == 39)||(ch == 34)){
                    	cout << word2 << " : " << "Operator\n";
                        output << word2 << " : " << "Operator\n";
						state = 60;}
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                	}
                    break;
                      case 56:            //DFA 15 operator <<      

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if (ch=='<')
                        state = 57;

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                case 57:                  

                    loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;

                    if (ch=='<')
                        state = 58;

                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                case 58:
					word2=word;
                    ch = getc(fp);
                    word += ch;
                    if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t')
                    {
                        cout << word2 << " : " << "Operator\n";
                        output << word2 << " : " << "Operator\n";
                        state = 35;
                    }
                    else if ((ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '_')||(ch == 40)||(ch == 41)||(ch == 39)||(ch == 34)){
                    	cout << word2 << " : " << "Operator\n";
                        output << word2 << " : " << "Operator\n";
						state = 60;}
                    else
                    {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                	}
                    break;
                case 59:
                	word="";
                	ungetc(ch, fp);
                    start = 42;
                    state = 42;
                    break;
                case 60:
                	word="";
                	ungetc(ch, fp);
                    start = 1;
                    state = 1;
                    break;
                case 61:                    // DFA Not Accepted
                	loc = ftell(fp);
                    ch = getc(fp);
                    word += ch;
                     if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t')
                    {
                        state = 35;
                    }
                    else state = 62;
                    break;
                case 62:
                	word2=word;
                    ch = getc(fp);
                    word += ch;
                    if (ch == ' ' || ch == '\n' || ch == EOF||ch=='\t')
                    {
                    	cout << word2 << " : " << "Not Accepted\n";
                        output << word2 << " : " << "Not Accepted\n";
                        state = 35;
                    }
                    else if ((ch=='+')||(ch=='-')||(ch=='*')||(ch=='%')||(ch=='/')||(ch=='=')||(ch=='^')||(ch=='<')||(ch=='>')||(ch=='!')||(ch==44)||(ch=='|')
					||(ch=='~')||(ch==59)||(ch=='<')||(ch=='>')||(ch=='?')||(ch=='#')||(ch=='[')||(ch==']')||(ch==40)||(ch==41)||(ch==125)||(ch==123)||(ch==':'))
					{
				        cout << word2 << " : " << "Not Accepted\n";
                        output << word2 << " : " << "Not Accepted\n";
                        state = 59;	}
                	else if (ch != ' ' || ch != '\n' || ch != EOF){state =62;
					}
					else {
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                	}
                	break;
                	
                case 63:               // sign for float exp
                    ch = getc(fp);
                    word += ch;
                    if (ch >= '0' && ch <= '9')
                        state = 9;
                    else{
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
                    
                case 64:               // sign for integer exp
                    ch = getc(fp);
                    word += ch;

                    if (ch >= '0' && ch <= '9')
					state = 14;
					else{
                        start = fail(start);
                        word = "";
                        state = start;
                        fseek(fp, loc, SEEK_SET);
                    }
                    break;
            }
    
            
        
    
    }


    int main()
    { 
        LexicalAnalyzer();
        return 0;
    }
