#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<malloc.h> 
#include<cstdlib>
using namespace std;

const int max_no_length = 20;
const int max_name_length = 30;
/**************************************Book类*************************************/
class Book
{
private:
	char bookNo[max_no_length];
	char bookName[max_name_length];
	int Num;
public:
	/*Book();//构造函数*/
	void Show(char* c)//显示一本图书信息    cout<<"输入书号\n";  cin>>s; for(i=0; i<=20; i++){Book[i].Show(s);}
	{
		int q = 0, i;
		cin >> c;
		/*
		for(i=0;i<=sizeof(*this->bookNo);i++)
		{
			if(c[q]==bookNo[i]) q++;
			else break;

		}
		*/
		//if (i == sizeof(*this->bookNo))
		if (strcmp(bookName, c) == 0)
		{
			cout << "书名为" << *this->bookName << endl;
			cout << "库存量为" << this->Num << endl;
		}
	}
	void Print(ofstream& out); //将库存记录写入文件
	void setInfo(char* nop, char* nap, int n)
	{
		/*bookNo=new(char[n]);
		bookName=new(char[n]);*/ //动态内存分配（书名） 
		/*	bookNo=nop;            //将书号写进类中
			bookName=nap;          //将书名写进类中
			Num=n;    */             //将库存写进类里 
	}

	int getNum();//获取库存量
	friend class bookList;
};
int Book::getNum() {
	return this->Num;
}
/***************************BookList类******************************/
class bookList
{
private:
	int curLen;//现有图书记录数（线性表中元素个数） 
	int maxLen;//线性表最大长度 
	Book* Listptr;//线性表首指针  Book类 
public:
	bookList(int Len = 20) //1初始化图书列表，动态申请线性表  构造函数 
	{
		curLen = 0;
		maxLen = Len;
		if (Len)
		{
			Listptr = new Book[Len];
		}
		else
		{
			Listptr = NULL;
		}

	}
	~bookList() //2释放线性表空间 
	{
		delete[]Listptr;
	}
	void appendBook(Book a)//3追加到线性表尾部 
	{
		if (curLen == maxLen) {
			Book* newptr;
			newptr = new Book[maxLen + 1];
			for (int i = 0; i < curLen; i++) {
				newptr[i] = Listptr[i];
			}
			delete[] Listptr;
			Listptr = newptr;
			maxLen++;
		}
		Listptr[curLen++] = a;
		/*n=0;
		nop=new(char[sizeof(nop)]);
		cout<<"请输入追加图书的书号";
		//cin>>nop->bookNo;
		while(nop->bookNo!=NULL)
		{
			n++;
			if(n==1){
				nead=nop;
			}
			else
			{
				nap->next=nop;
				cout<<"请输入追加图书的书名";
				cin>>nop->bookName;
				cout<<"请输入追加图书的库存量" ;
				cin>>nop->Num;
				nap=nop;
				cout<<"请输入追加图书的书号";
				nop=new(Book);
				cin>>nap->bookNo;
			}
		}
		cout<<endl;
		delete nop;
		nap->next=NULL;
		return Books;	*/
	}
	int isIn(char* bkNo) //4按书号查找图书  cin>>x;(char[])   isIn(x);
	{
		for (int m = 0; m < sizeof(Listptr) / sizeof(Book); m++)
		{
			/*
				for(int i=0; i<max(sizeof(bkNo),sizeof(Listptr[m].bookNo));i++)
				{
					if(bkNo[i]!=Listptr[m].bookNo[i])
					{

						break;
					}
					else
					{
						return m;
					}
				}
			*/
			if (strcmp(Listptr[m].bookNo, bkNo) == 0)
				return m;
		}
		printf("所输入的书号不存在\n");
		return -1;
	};
	Book& getBooks(int i) //5返回下标i图书库存记录的引用  
	{
		return (Listptr[i]);
	}
	void deleteBook(char* bkNo)//6删除指定书号库存记录
	{
		cout << "输入需要删除的书号";
		cin >> bkNo;
		int pos = isIn(bkNo);
		if (pos > 0)
		{
			delete (Listptr + pos);
			for (int i = pos + 1; i < curLen; i++)
			{
				Listptr[i - 1] = Listptr[i];
			}
			curLen--;
		}
		else
		{
			cout << "书号不存在";
		}
		/*
		 for(int m=0;m<sizeof(Listptr);m++)
		{

			 for (int i = 0; i < max(sizeof(bkNo), sizeof(Listptr[i].bookNo)); i++)
			 {
				 if (bkNo[i] != Listptr[i].bookNo[i])
				 {
					 break;
					 cout << "书号不存在";
					 return ;
				 }
				 else
				 {
					 delete& getbooks;
				 }
			 }
			 break;
		}
		*/
	}
	void sortBooks() //7按书号将线性表排升序 
	{
		Book temp;
		for (int i = 0; i < sizeof(Listptr); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (Listptr[j].bookNo < Listptr[i].bookNo)
				{
					temp = Listptr[i];
					Listptr[j] = Listptr[i];
					Listptr[j] = temp;
				}
			}
		}
	}
	void showAll() //8显示全部图书库存记录 
	{
		int q = 0, i;
		for (i = 0; i < curLen; i++)
		{

			cout << "书名为" << Listptr[i].bookName << endl;
			cout << "库存量为" << Listptr[i].bookNo << endl;
		}
	}
	int curBookLen() //9返回现有图书记录数 
	{
		return (this->curLen);
	}
	void setCurBookLen(int len) //10设置现有图书记录数 
	{
		cout << "输入现有图书记录数";
		cin >> len;
		if (len <= (this->curLen))
		{
			this->curLen = len;

		}
		else
			return;
	}
	
	
		void readFromFile(char* filename)//12读入库存记录 
	{
		char line[50];
		ifstream infile;
		infile.open("bookdata.txt",ios_base::in);
		while (infile.getline(line, 50))
		{
			//此时line中是书号
			string no = line;
			infile.getline(line, 50);
			//此时line中是书名
			string name = line;
			infile.getline(line, 50);
			string num = line;
			int number = atoi(line);
			//构造Book对象，放到Booklist里
		}
	}

	
	void initBookList() //11初始化线性表，readFromFile bookdata.txt*************************************************************
	{
		this->curLen=0;
		readFromFile(Listptr);
		
		
		

	};
	

	void writeToFile(char* filename);//13*******************************************************************8
};



/**************************************菜单********************************************/

int menu_select();
int main()
{
	bookList booksObj; //针对该对象执行 
	int sel;
	booksObj.initBookList();
	for (;;)
	{
		char in_no[max_no_length];
		switch (sel = menu_select())
		{
		case 1:
			booksObj.appendBook(Book());
			//system("pause");
			break;
		case 2: booksObj.deleteBook(in_no);
			//system("pause");
			break;
		case 3: booksObj.showAll();
			//system("pause");
			break;
		case 4: booksObj.isIn(in_no);
			//system("pause");
			break;
		case 5: //addBooks(booksObj);
			booksObj.isIn(in_no);
			//system("pause");
			break;
		case 6: //sellBooks(booksObj);
			  //system("pause");
			booksObj.isIn(in_no);
			break;
		case 7: //appendFromTxtFile(booksObj);
			  //system("pause");
			booksObj.isIn(in_no);
			break;
		case 8: //writeToTxtFile(booksObj);
			  //system("pause");
			booksObj.isIn(in_no);
			break;
		case 9: //sortByNoTxtFile(booksObj);
			  //system("pause");
			booksObj.isIn(in_no);
			break;
		case 10: //delAll(booksObj);
			  //system("pause");
			booksObj.isIn(in_no);
			break;
		case 0:
			//if(Quit(booksObj)!='y')	
			booksObj.isIn(in_no);
			continue;
		}
		if (sel == 0)break;
	}
	return 0;
}
int menu_select()
{
	string m[20] = {
		"1.追加图书记录",
		"2.删除图书记录",
		"3.显示所有图书记录",
		"4.查询图书",
		"5.图书入库",
		"6.图书销售",
		"7.批量导入图书记录",
		"8.导出图书记录",
		"9.按书号排序",
		"10.删除全部图书记录",
		"0.退出" ,
	};
	int i, choice;
	do
	{
		system("cls");
		for (i = 0; i < 11; i++)
			cout << m[i] << endl;
		cout << "请输入选择";
		cin >> choice;
	} while (choice < 0 || choice>10);
	return(choice);
}
