#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	string wordlist[12948];
	int count=0;
	ifstream fin;
	fin.open("wordle_word_list.txt");
	string str="";
	char ch;
	fin.get(ch);
	while(!fin.eof())
	{
		fin.get(ch);
		if(ch=='"')
		{
			fin.get(ch);
			while(ch!='"')
			{
				str+=ch;
				fin.get(ch);
			}
		}
		wordlist[count++]=str;
		str="";
		fin.get();
	}
	fin.close();
	string a,b="NNNNN";
	string guess="crage";	//first guess is "salet"
	cout<<guess<<endl;
	while(1)
	{
		cin>>a;						//A for correct, B for present, N for absent
		for(int i=0;i<12948;i++)
		{
			if(wordlist[i]=="\0")
				continue;
			b="NNNNN";
			for(int j=0;j<5;j++)
			{
				if(wordlist[i][j]==guess[j])
					b[j]='A';
				else
				{
					for(int k=0;k<5;k++)
						if(wordlist[i][k]==guess[j])
							b[j]='B';
				}	
			}
			
			if(a==b)
			{
				guess=wordlist[i];
				cout<<guess<<endl;
				break;
			}
			wordlist[i]="\0";
		}
	}
	return 0;
		
	
 } 
