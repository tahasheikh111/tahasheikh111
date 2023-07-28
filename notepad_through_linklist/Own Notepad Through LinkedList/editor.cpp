#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "myconsole.h"
#include "editor.h"
using namespace std;
//-------------------------------Color Codes------------------------------//
// Color Codes Hexadecimal values for both Fore Ground and Back Ground //ForeGround|BackGround
int B_BLACK			= 0x00;	int B_Royal_Blue	= 0x10;	int B_Dark_Green	= 0x20;
int B_Tale_Blue		= 0x30;	int B_Dark_Red		= 0x40;	int B_Purple		= 0x50;
int B_Tale_Green	= 0x60;	int B_Light_Grey	= 0x70; int B_Dark_Gray		= 0x80;	
int B_Light_Blue	= 0x90; int B_Light_Green	= 0xA0;	int B_Sky_Blue		= 0xB0;
int B_Red			= 0xC0;	int B_Pink			= 0xD0;	int B_Yellow		= 0xE0;
int B_White			= 0xF0;

int F_BLACK			= 0x00;	int F_Royal_Blue	= 0x01; int F_Dark_Green = 0x02;
int F_Tale_Blue		= 0x03;	int F_Dark_Red		= 0x04;	int F_Purple	 = 0x05;
int F_Tale_Green	= 0x06;	int F_Light_Grey	= 0x07; int F_Dark_Gray	 = 0x08;
int F_Light_Blue	= 0x09; int F_Light_Green	= 0x0A;	int F_Sky_Blue	 = 0x0B;
int F_Red			= 0x0C;	int F_Pink			= 0x0D;	int F_Yellow	 = 0x0E;
int F_White			= 0x0F;

//-------------------------------POINT CLASS------------------------------//
//initialize MaxPoint
point point::MaxPoint(MAX_X, MAX_Y);
bool point::incrementX()
{
	bool returnValue = true;
	if (x<MaxPoint.x)
		x++;
	else if (y<MaxPoint.y)
	{
		x = 0;
		y = y + 1; // moves in nextline
	}
	else
		returnValue = false;

	return returnValue;
}

bool point::incrementY()
{
	bool returnValue = true;
	if (y<MaxPoint.y)
		y++;
	else
		returnValue = false;

	return returnValue;

}
bool point::decrementX()
{
	bool returnValue = true;
	if (x>0)
		x--;
	else if (y>0)
	{
		y--;
		x = MaxPoint.x;  // moves in last columns in upper rows
	}
	else
		returnValue = false;

	return returnValue;
}
bool point::decrementY()
{
	bool returnValue = true;
	if (y>0)
		y--;
	else
		returnValue = false;

	return returnValue;

}
// doublylinkedlist ------------------------------------
template<class T>
class doublylinkedlist {
public:
	class node {
	private:
		T data;
		node* next;
		node* previous;
		friend class doublylinkedlist<T>;
	public:
		node(T Val) {
			data = Val;
			next = NULL;
			previous = NULL;
		}
	};
	class listiterator {
	protected:
		node* current;
		friend class doublylinkedlist<T>;
	public:
		listiterator() {
			current = NULL;
		}
		listiterator(node* temp) {
			current = temp; // called in begin()
			// called in end()
		}
		T& operator*() {
			return current->data;
		}
		bool operator==(listiterator rhs) {
			return (current == rhs.current);
		}
		bool operator!=(listiterator rhs) {
			return (current != rhs.current);
		}
		listiterator& operator++() {
			if (current != NULL) {
				current = current->next;
			}

			return *this;
		}
		listiterator operator++(int) {
			listiterator temp = *this;
			if (current != NULL) {
				current = current->next;
			}

			return temp;
		}
		listiterator& operator--() {
			if (current != NULL) {
				current = current->previous;
			}
		

			return *this;
		}
		listiterator operator--(int) {
			listiterator temp = *this;
			if (current != NULL) {
				current = current->previous;
			}
			
			return temp;
		}
	};
	listiterator begin() {
		return head->next;
	}
	listiterator end() {
		return nullptr;
	}
	doublylinkedlist() {
		head = new node(0);
	}
	void insert_at_head(T val) {
		node* create = new node(val);
		if (head->next == NULL) {
			head->next = create;
			create->next = NULL;
			create->previous = NULL;
		}
		else {
			create->next = head->next;
			head->next->previous = create;
			head->next = create;
			create->previous = NULL;
		}
	}
	void delete_from_head() {
		if (head->next == NULL) {
			cout << "Already NULL...." << endl;
		}
		else if (head->next->next == NULL) {
			head->next = NULL;
			cout << "Empty..." << endl;
		}
		else if (head->next->next != NULL) {
			head->next->next->previous = NULL;
			head->next = head->next->next;

		}



	}

	void deletefromtail() {
		doublylinkedlist<T>::listiterator i = begin();
		node* temp = head->next;
		if (i.current == NULL) {
			head->next = NULL;
		}
		else {
			while (temp->next!= NULL) {
				temp = temp->next;
			}
			node* previoustemp = temp->previous;
			if (previoustemp != NULL) {
				previoustemp->next = NULL;
			}
			
		}
		


	}
	void delete_from_iterator(doublylinkedlist<T>::listiterator i) {
		if (i.current == NULL && head->next == NULL) {
			i.current = NULL;
		}
		else if (i.current == NULL && head->next->next==NULL) {
			head->next = NULL;
			//i.current->next = NULL;
		}
		else if (i.current == NULL && head->next->next != NULL) {
			head->next = head->next->next;
			head->next->previous = NULL;
			//i.current->next = NULL;
		
		}
		else if (i.current == head->next && head->next->next!=NULL) {
			i.current=i.current->next;
			head->next = head->next->next;
			head->next->previous = NULL;
		}
		else if (i.current == head->next && head->next->next == NULL) {
			i.current = NULL;
			head->next = NULL;
		}
		else if (i.current != head->next && i.current->next == NULL && i.current->previous!=NULL) {
			i.current->previous->next = NULL;
		}
		else if (i.current->next == NULL && i.current->previous == NULL) {
			head->next = NULL;
		}
		else if (i.current->next != NULL && i.current->previous == NULL) {
			i.current = i.current->next;
			i.current->previous = NULL;
		}
		
		else {
			i.current->previous->next = i.current->next;
			i.current->next->previous = i.current->previous;
		}
	}
	void deleteatindex(T val) {
		if (head->next == NULL) {
			cout << "ALREADY NULL..." << endl;
		}
		else {
			node* temp = head->next;
			while (temp != NULL && temp->data != val) {
				temp = temp->next;
			}
			if (temp == NULL) {
				cout << "NOTHING FOUND...." << endl;
			}
			else if (temp == head->next) {
				delete_from_head();
			}
			else if (temp->next == NULL) {
				temp->previous->next = NULL;
			}
			else {
				temp->next->previous = temp->previous;
				temp->previous->next = temp->next;

			}
		}
	}
	void deleteallexistingvalues(T val) {
		bool flag = 0;
		for (doublylinkedlist<T>::listiterator i = begin();i != end();i++) {
			if (*i == val) {
				flag = 1;
				deleteatindex(val);
			}

		}
		if (flag == 0) {
			cout << "Can't Find it" << endl;
		}
	}
	void replaceallexistingvalues(T val) {
		cout << "ENter Updated value: " << endl;
		T value;
		cin >> value;
		bool flag = 0;
		for (doublylinkedlist<T>::listiterator i = begin();i != end();i++) {
			if (*i == val) {
				*i = value;
				flag = 1;
			}
		}
		if (flag == 0) {
			cout << "Can'T find it..." << endl;
		}
	}
	bool search(T val) {
		bool check = 0;
		for (doublylinkedlist<T>::listiterator i = begin();i != end();i++) {
			if (*i == val) {
				check = 1;
			}
		}
		if (check == 1) { return true; }
		else { return false; }
	}
	void display() {
		for (doublylinkedlist<T>::listiterator i = begin();i != end();i++) {
			cout << (*i);
		}
		cout << endl;
	}
	void backwarddisplay() {
		node* temp = head->next;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		while (temp != NULL) {
			cout << temp->data;
			temp = temp->previous;
		}


	}
	void swap(T val, T val2) {

		node* temp1 = head->next;
		node* temp1previous = NULL;
		node* temp2 = head->next;
		node* temp2previous = NULL;
		node* temps = NULL;
		if (search(val) && search(val2) == 1) {
			while (temp1 != NULL && temp1->data != val) {
				temp1previous = temp1;
				temp1 = temp1->next;
			}
			while (temp2 != NULL && temp2->data != val2) {
				temp2previous = temp2;
				temp2 = temp2->next;

			}
			if (temp1 == head->next && temp2->next != NULL && temp1->next != temp2) {
				// means 1st is at head and other is not at tail
				temp1previous = NULL;
				temps = temp2->next;

				temp2->next = temp1->next;
				temp1->next->previous = temp2;
				temp2->previous = NULL;
				temp1->next = temps;
				temp1->previous = temp2previous;
				temp2previous->next = temp1;
				temps->previous = temp1;
				head->next = temp2;
			}
			else if (temp1 != head->next && temp2->next == NULL && temp1->next != temp2) {
				temps = temp1->next;
				temp2previous->next = temp1;
				temp1->next = NULL;
				temp1->previous = temp2previous;

				temp1previous->next = temp2;
				temp2->next = temps;
				temps->previous = temp2;
				temp2->previous = temp1previous;

			}
			else if (temp1 == head->next && temp2->next == NULL) {
				node* nexttemp1 = temp1->next;
				temp2->next = nexttemp1;
				nexttemp1->previous = temp2;


				temp2previous->next = temp1;
				temp1->previous = temp2previous;
				temp1->next = NULL;

				head->next = temp2;
			}
			else if (temp1 != head->next && temp1->next == temp2 && temp2->next != NULL) {
				temps = temp2->next;
				temp1previous->next = temp2;
				temp2->previous = temp1previous;
				temp2->next = temp1;
				temp1->previous = temp2;
				temp1->next = temps;
				temps->previous = temp1;
			}
			else if (temp1 == head->next && temp1->next == temp2 && temp2->next != NULL) {

				temps = temp2->next;
				temp1->next = temps;
				temps->previous = temp1;
				temp2->next = temp1;

				temp1->previous = temp2;
				head->next = temp2;
			}
			else if (temp1->next == temp2 && temp2->next == NULL && temp1 != head->next) {
				temp2->next = temp1;
				temp1->previous = temp2;
				temp2->previous = temp1previous;
				temp1previous->next = temp2;
				temp1->next = NULL;

			}
			else {
				temps = temp2->next;
				temp2->next = temp1->next;
				temp2->previous = temp1previous;
				temp1->next->previous = temp2;
				temp1previous->next = temp2;

				temp1->next = temps;
				temps->previous = temp1;
				temp2previous->next = temp1;
				temp1->previous = temp2previous;
			}

		}
		else {
			cout << "Element not found..." << endl;
		}
	}
	void insertafter(doublylinkedlist<T>::listiterator i, T val) {
		node* create = new node(val);
		if (getcount() == 0) {
			insert_at_head(val);
		}
		else if (i.current == NULL) {
			insert_at_head(val);
		}
		
		else if (i.current->next == NULL) {
			i.current->next = create;
			create->previous = i.current;
			create->next = NULL;
			
		}
		else {
			create->next = i.current->next;
			i.current->next->previous = create;
			i.current->next = create;
			create->previous = i.current;
			
		}

	}
	void insert_multiple(doublylinkedlist<T>::listiterator i, T val1, T val2, T val3) {

		insertafter(i, val1);
		insertafter(++i, val2);
		insertafter(++i, val3);

	}
	void deleteone(doublylinkedlist<T>::listiterator i) {
		if (i == begin()) {
			node* temp = head->next;
			head->next = head->next->next;
			head->next->previous = NULL;
			delete temp;
		}
		else if (i.current == NULL) {
			cout << "EMPTY>>" << endl;
		}
		else if (i.current->next == NULL) {
			node* temp = i.current;
			i.current->previous->next = NULL;
			delete temp;
		}
		else {
			i.current->previous->next = i.current->next;
			i.current->next->previous = i.current->previous;
		}
	}
	int getcount_iterator(doublylinkedlist<T>::listiterator i) {
		doublylinkedlist<T>::listiterator j = i;
		int count = 0;
		for (;j != end();j++) {
			count++;
		}
		return count;
	}
	void delete_multiple(doublylinkedlist<T>::listiterator i, int noofval) {
		int count = getcount_iterator(i);
		if (count >= noofval) {
			for (int k = 0;k < noofval;k++) {
				deleteone(i++);
			}
		}
		else {
			cout << "NO of delete variable is greater then size from pointing index" << endl;
		}
	}
	int delete_range(doublylinkedlist<T>::listiterator i, doublylinkedlist<T>::listiterator j) {
		int counti = getcount_iterator(i);
		int countj = getcount_iterator(j);
		if (counti >= countj) {
			for (int k = 0;k < counti - countj;k++) {
				delete_from_iterator(++i);
			}
		}
		else {
			for (int k = 0;k < countj - counti;k++) {
				delete_from_iterator(++j);
			}
		}
		if (counti >= countj) {
			return counti - countj;
		}
		else {
			return countj - counti;
		}
	}
	listiterator search(string word,int &line,int &elements,int &forcountx) {
		node* temp = head->next;
		int i = 0;
		node* temp2 = NULL;
		int count = 0;
		bool flag = 0;
		int elementno = 0;
		doublylinkedlist<T>::listiterator mover = NULL;
		int lineno = 1;
		while (temp != NULL) {
			i = 0;
			count = 0;
			temp2 = NULL;
			if (temp->data == '\n') {
				lineno++;
				elementno = 0;
				forcountx++;
			}
			if (temp->data == word[i]) {
				//elementno++;
				forcountx++;
				count++;
				mover.current = temp;
				temp2 = temp->next;
				for (int j = i+1;j < word.length();j++) {
					if (temp->next != NULL ) {
						if (temp2->next != NULL) {
							if (temp2->data == word[j]) {
								count++;
							}
							temp2 = temp2->next;
						}
						
					}
					
				}
				if (count == word.length()) {
					line = lineno;
					elements = elementno;
					flag = 1;
					return mover;
				}
			}
			forcountx++;
			elementno++;
			temp = temp->next;

			
		}
		if (flag == 0) {
			return NULL;
		}


	}
	listiterator search_first(T value) {
		node* temp = head->next;
		bool flag = 0;
		doublylinkedlist<T>::listiterator i;
		while (temp != NULL && temp->data != value) {

			temp = temp->next;
		}
		if (temp->data == value) {
			flag = 1;
		}
		if (flag == 1) {
			i.current = temp;
		}
		else {
			i.current = NULL;
		}
		return i;
	}
	listiterator** search_ALL(T value) {
		int count = 0;
		node* temp = head->next;
		doublylinkedlist<T>::listiterator** save;
		while (temp != NULL) {
			if (temp->data == value) {
				count++;
			}
			temp = temp->next;
		}
		doublylinkedlist<T>::listiterator* save = new doublylinkedlist<T>::listiterator[count];
		for (int k = 0;k < count;k++) {
			doublylinkedlist<T>::listiterator save[k] = new doublylinkedlist<T>::listiterator;
		}
		if (count > 0) {
			int k = 0;
			temp = head->next;
			while (temp != NULL) {
				if (temp->data == value) {
					save[k]->current = temp->data;
					k++;
				}
				temp = temp->next;
			}
			return save;
		}
		else {
			return NULL;
		}

	}
	int getcount() {
		int count = 0;
		node* temp = head->next;
		while (temp != NULL) {
			temp = temp->next;
			count++;
		}
		return count;
	}
	int maxline() {
		node* temp = head->next;
		int count = 0;
		int maxcount = 0;
		while (temp != NULL) {
			if (temp->data != '\n') {
				count++;
			}
			else if (temp->data == '\n') {
				count = 0;
			}
			if (count > maxcount) {
				maxcount = count;
			}
			temp = temp->next;
		}
		return maxcount;

	}
	int * getrowscount(int lines) {
		int* arr = new int[lines];
		int countx = 0;
		int i = 0;
		node* temp = head->next;
		while (temp != NULL) {
			countx++;
			if (temp->data == '\n') {
				arr[i] = countx;
				i++;
				
			}
			temp = temp->next;
		}
		arr[i] = countx;
		return arr;
	}
private:
	node* head;

};

//-------------------------------END OF POINT CLASS------------------------------------------------//


//--------------------------The function Where you will write code--------------------------------//
int mainEditor()
{

	bool checkcursor = 0;// used in search
	int nooflines = 1;
	bool checkbackspace = 0;
	doublylinkedlist<char>* obj = new doublylinkedlist<char>;
	doublylinkedlist<char>::listiterator X = obj->begin();
	int countx = 0;
	int county = 0;
	int key = 0;
	bool stop = false;
	point currentPosition(0, 0);
	currentPosition.setMaxPoint(MAX_X, MAX_Y);
	bool specialKey = false;
	int* arr = NULL;
	while (!stop)
	{
		key = CheckWhichKeyPressed(specialKey);
		//escape key
		if (key == ESCKEY)
			stop = true;
		//printable character...only adds to the end of text
		//this will not do insertions in between text
		//add code here to insert characters within text
		else if (!specialKey&&key >= 32 && key <= 126)
		{
			if (currentPosition.getX() == MAX_X) {
				obj->insertafter(X, '\n');
				
				county++;
				nooflines++;
				currentPosition.incrementX();
				currentPosition.setX(0);
				countx++;
				X++;
			}
			else if (currentPosition.getX() < MAX_X)
			{
				//cout << (char)key; 
				if (obj->getcount() == 0 ) {
					obj->insert_at_head((char)key);
					
					countx++;
					currentPosition.incrementX();
					X = obj->begin();
				}
				else {
					obj->insertafter(X, (char)key);
					countx++;
					currentPosition.incrementX();
					X++;
				}
				
				//You can change color of text by calling this function
				SetColorAtPoint(currentPosition.getX(), currentPosition.getY(), F_Light_Green|B_BLACK);   //ForeGround|BackGround
				//currentPosition.incrementX();
				system("cls");
				obj->display();
				
			}
			else if (currentPosition.getY() < MAX_Y)
			{
				currentPosition.incrementY();
				county++;
				currentPosition.setX(0);
			}
		}
		else if (specialKey && key == LEFTKEY) {
			arr = obj->getrowscount(nooflines - 1);
			
			if (countx > 0 && county==0) {
				if (countx != 1) {
					currentPosition.decrementX();
					--X;
					countx--;
				}
				
			}
			else {
				
				if (countx != arr[county - 1]) {
					currentPosition.decrementX();
					--X;
					countx--;
				}
			}
			
			
		}
		
		else if (specialKey && key == RIGHTKEY) {
			//currentPosition.incrementX();
			arr = obj->getrowscount(nooflines - 1);
			if (countx < arr[county]) {
				
					currentPosition.incrementX();
					X++;
					countx++;
				
			}
			else {
				if (county < nooflines - 1) {
					currentPosition.incrementY();
					currentPosition.incrementX();
					county++;
					currentPosition.setX(0);
				}
				
			}
			
			
		}
			
		else if (specialKey && key == UPKEY) {
			
			if (nooflines >= 1 && nooflines<50) {
				arr = obj->getrowscount(nooflines - 1);
				
				if (county > 0) {
					
					currentPosition.decrementY();
					if (county == 1) {
						for (int i = 0;i < arr[county-1];i++) {
							X--;
							countx--;
						}
						
						
					}
					else {
						if (arr[county - 1] > arr[county - 2]) {
							for (int i = 0;i < arr[county - 1] - arr[county - 2];i++) {
								X--;
								countx--;
							}
						}
						else {
							for (int i = 0;i < arr[county - 2] - arr[county - 1];i++) {
								X--;
								countx--;
							}
						}
						
					}
					county--;
					
				}
				
		
			}
			
		}
		
		else if (specialKey && key == DOWNKEY) {
			//Update it so that cursur not move downword if it is at last line of text.
			 arr = obj->getrowscount(nooflines-1);
			if (nooflines > 1 && nooflines<50 || county<nooflines) {
				if (county < nooflines-1) {
					if (county == 0 && nooflines - 1!=0) {
						for (int i = 0;i < arr[county];i++) {
							X++;
							countx++;
						}
						county++;
						currentPosition.incrementY();
					}
					else if (county == 1) {
						 for (int i = 0;i < arr[county - 1];i++) {
							X++;
							countx++;
						 }
						 county++;
						 currentPosition.incrementY();

					}
					else {
						if (arr[county - 1] > arr[county - 2]) {
							for (int i = 0;i < arr[county - 1] - arr[county - 2];i++) {
								X++;
								countx++;
							}
							county++;
							currentPosition.incrementY();
						}
						else {
							for (int i = 0;i < arr[county - 2] - arr[county - 1];i++) {
								X++;
								countx++;
							}
							county++;
							currentPosition.incrementY();
						}

					}
					
				}
				
				
			}
			
		}
		
		else if (key == ENTERKEY){
			cout << ('\n');
			obj->insertafter(X, '\n');
			county++;
			countx++;
			nooflines++;
			X++;
			currentPosition.setX(0);
			
			currentPosition.incrementY();
		}
		else if (key == DELKEY)
		{
		
		arr = obj->getrowscount(nooflines - 1);
		doublylinkedlist<char>::listiterator j = X;
	    while (*j != ' '|| *j=='\n') {
			j--;
		}
		//j--;
		int del = obj->delete_range(j, X);
		for (int i = 0;i < del;i++) {
			if (i >=1) {
				currentPosition.decrementX();
				
			}
		
		}
		countx--;
		// left key program
		if (countx > 0 && county == 0) {
			if (countx != 1) {
				currentPosition.decrementX();
				--X;
				countx--;
			}

		}
		else {

			if (countx != arr[county - 1]) {
				currentPosition.decrementX();
				--X;
				countx--;
			}
		}
		// left key program
			//call a function to handle 
		system("cls");
		obj->display();
		}
		else if (key == BACKSPACE)
		{
		arr = obj->getrowscount(nooflines - 1);
		
		if (countx > 0 && county == 0) {
			if (countx != 1) {
				currentPosition.decrementX();
				obj->delete_from_iterator(X);
				--X;
				countx--;
				system("cls");
				obj->display();
			}

		}
		else {

			if (countx != arr[county - 1]) {
				currentPosition.decrementX();
				obj->delete_from_iterator(X);
				--X;
				countx--;
				system("cls");
				obj->display();
			}
			if (countx == arr[county - 1]) {
				currentPosition.decrementX();
				obj->delete_from_iterator(X);
				--X;
				countx--;
				currentPosition.setY(county - 1);
				currentPosition.setX(arr[county - 1]);
				system("cls");
				obj->display();
			}
		}


		}
		
		else if (key == F1KEY || key == F2KEY || key == F3KEY)
		{
			//handle search here
			doublylinkedlist<char>* searchobj = new doublylinkedlist<char>;
			doublylinkedlist<char>::listiterator S;
			//you can take the cursor at the bottom of the screen and get some input
			//for searching
			PlaceCursor(0, MAX_Y);
			for (int i = 0; i < MAX_X; i++)
			{
				cout << '\0';
				currentPosition.incrementX();
			}

			PlaceCursor(0, MAX_Y);
			cout << "Enter Search Query: "<<endl;
			string word;
			cin >> word;
			cout << word;

			if (key == F1KEY) {
				
				cout << "F1 key" << endl;
				int line = 0;
				int atindex = 0;
				int forcountx = 0;
				doublylinkedlist<char>::listiterator finder = obj->search(word, line,atindex,forcountx);
				if (finder != NULL) {
					cout << "FOUND AT LINE NO : " << line << endl;
					cout << "FOUND AT ELEMENT NO : " << atindex << endl;
					//X = finder;
					cout << "ITERATOR MOVES AT : " << forcountx << endl;
					if (line > 1) {
						X = finder;
						X--;
						atindex = atindex - 1;
					}
					
					else {
						X = finder;
						atindex = atindex;
					}
				
					system("pause");
					
					currentPosition.setX(atindex);
					currentPosition.setY(line - 1);
					
				
				}
				else {
					
					cout << "NOT FOUND..." << endl;
					system("pause");
					currentPosition.setX(1);
					currentPosition.setY(0);
				}
				//Search for one instance of string and move cursor there
			}
			else if(key == F2KEY)
			{
				cout << "F2 key" << endl;
				doublylinkedlist<char>::listiterator temp = obj->begin();
				int i = 0;
				doublylinkedlist<char>::listiterator temp2 = NULL;
				int count = 0;
				bool flag = 0;
				int elementno = 0;
				int forcountx = 0;
				doublylinkedlist<char>::listiterator mover = NULL;
				int lineno = 1;
				while (temp != NULL) {
					i = 0;
					count = 0;
					temp2 = NULL;
					if (*temp == '\n') {
						lineno++;
						elementno = 0;
						forcountx++;
					}
					if (*temp == word[i]) {
						//elementno++;
						forcountx++;
						count++;
						mover = temp;
						doublylinkedlist<char>::listiterator temp3 = temp;
						temp2 = ++temp3;
						for (int j = i + 1;j < word.length();j++) {
							if (temp != NULL) {
								if (*temp2 == word[j]) {
									count++;
								}
								temp2++;
								

							}

						}
						if (count == word.length()) {
							int tempelementno = elementno;
							flag = 1;
							for (int i = 0;i < count;i++) {
								if (lineno > 1) {
									SetColorAtPoint(tempelementno-1, lineno - 1, F_Light_Blue | B_Dark_Red);
									tempelementno++;
								}
								else {
									SetColorAtPoint(tempelementno, lineno - 1, F_Light_Blue | B_Dark_Red);
									tempelementno++;
								}
								
							}
						}
					}
					forcountx++;
					elementno++;
					temp++;

					currentPosition.setX(elementno-1);
					currentPosition.setY(lineno - 1);
					countx = forcountx;
				}
				if (flag == 0) {
					cout << "NO FOUND" << endl;
				}
				//Search for all instances of string and Highlight them
			}
			else
			{
				cout << "F3 key" << endl;
				string another;
				cout << "ENTER REPLACE STRING" << endl;
				cin >> another;
				doublylinkedlist<char>::listiterator temp = obj->begin();
				int i = 0;
				doublylinkedlist<char>::listiterator temp2 = NULL;
				int count = 0;
				bool flag = 0;
				int elementno = 0;
				int forcountx = 0;
				doublylinkedlist<char>::listiterator mover = NULL;
				int lineno = 1;
				while (temp != NULL) {
					i = 0;
					count = 0;
					temp2 = NULL;
					if (*temp == '\n') {
						lineno++;
						elementno = 0;
						forcountx++;
					}
					if (*temp == word[i]) {
						///elementno++;
						forcountx++;
						count++;
						mover = temp;
						doublylinkedlist<char>::listiterator temp3 = temp;
						temp2 = ++temp3;
						for (int j = i + 1;j < word.length();j++) {
							if (temp2 != NULL) {
								if (*temp2 == word[j]) {
									count++;
								}
								temp2++;
							}

						}
						if (count == word.length()) {
							int tempelementno = elementno;// jahan sy start hota search kerna
							flag = 1;
							doublylinkedlist<char>::listiterator replace = mover;
							doublylinkedlist<char>::listiterator tempreplace = replace;
							--replace;
							
							if (replace != NULL) {
								for (int i = 0;i < another.length();i++) {
									obj->insertafter(replace, another[i]);
									++replace;
								}
								//obj->display();
								//system("pause");
								//system("cls");
								for (int i = 0;i < count;i++) {

									obj->delete_from_iterator(++replace);
									//++replace;
								}
							}
							else {
								*tempreplace == word[0];
								obj->insert_at_head(' ');
								replace = obj->begin();
								for (int i = 0;i < another.length();i++) {
									obj->insertafter(replace, another[i]);
									++replace;
								}
								//obj->display();
								//system("pause");
								//system("cls");
								for (int i = 0;i < count;i++) {

									obj->delete_from_iterator(++replace);
									
								}
							}
							
							

						}
					}
					forcountx++;
					elementno++;
					temp++;

					currentPosition.setX(elementno-1);
					currentPosition.setY(lineno - 1);
					countx = forcountx-1;
					system("cls");
					obj->display();
				}
				if (flag == 0) {
					cout << "NO FOUND" << endl;
				}
				//Search for all instances of string 
				//Take a second input string 
				//and replace all instances of first string with second string
			}

		}
		else if (key == F4KEY)
		{
		ofstream out;
		out.open("myeditor.txt");
		if (!out) {
			cout << "ERROR WHILE LOADING" << endl;
		}
		else {
			cout << "OPENS.." << endl;
		}
		doublylinkedlist<char>::listiterator temp = obj->begin();
		while (temp != NULL) {
			out << *temp;
			temp++;
		}
		out.close();
			//save to file
		}
		
		PlaceCursor(currentPosition.getX(), currentPosition.getY());
		
	}
	cout << endl;
	obj->display();
	cout << "NO OF CHARACTERS: " << obj->getcount() << endl;
	cout << "NO OF LINES: " << nooflines << endl;
	cout << "ITERATOR AT : " << countx << " ELEMENT"<<endl;
	cout << "ITERATOR AT COLUMN: " << county << endl;
	cout << "MAX LINE SIZE : " << obj->maxline() << endl;
	cout << "NO OF ELEMENST IN ROWS" << endl;
	for (int i = 0;i < nooflines;i++) {
		cout << arr[i] << endl;
	}
	cout << "----------------------" << endl;
	return 0;
}

//-------------------------------------------End Main Editor--------------------------//
void main()
{
	cout << "----------------------------------------------APNA NOTEPAD.TXT-------------------------------------------------------" << endl;
	cout << endl << endl;
	cout << "DISCLAIMER: THIS EDITOR HAS ITS OWN FUNCTIONS.." << endl;
	cout << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "Instruction : press anykey to show your creativity" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	system("pause");
	system("cls");
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "NOt So easy to show your creativity to the World" << endl;
	cout << "Again press anykey" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	system("pause");
	system("cls");
	mainEditor();
	system("pause");
}
