#include<iostream>
using namespace std;
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
		T & operator*() {
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
			
				current = current->previous;
			
			return *this;
		}
		listiterator operator--(int) {
			listiterator temp = *this;
			current = current->previous;
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
		if (head->next==NULL) {
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
		else if (head->next->next!=NULL) {
			head->next->next->previous = NULL;
			head->next = head->next->next;
			
		}
		
		
		
	}
	void deleteatindex(T val) {
		if (head->next == NULL) {
			cout << "ALREADY NULL..." << endl;
		}
		else {
			node* temp = head->next;
			while (temp != NULL && temp->data!=val) {
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
			cout << (*i) << "->";
		}
		cout << "nullptr";
		cout << endl;
	}
	void swap(T val,T val2) {

		node* temp1 = head->next;
		node* temp1previous = NULL;
		node* temp2 = head->next;
		node* temp2previous = NULL;
		node* temps = NULL;
		if (search(val )&& search(val2) == 1) {
			while (temp1 != NULL && temp1->data != val) {
				temp1previous = temp1;
				temp1=temp1->next;
			}
			while(temp2 != NULL && temp2->data != val2) {
				temp2previous = temp2;
				temp2=temp2->next;

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
			else if (temp1 != head->next && temp2->next == NULL && temp1->next!=temp2) {
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
			else if (temp1!=head->next &&temp1->next == temp2&& temp2->next!=NULL) {
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
			else if (temp1->next == temp2 && temp2->next == NULL && temp1!=head->next) {
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
		if (i.current == NULL) {
		   cout << "EMPTY..." << endl;
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
	void insert_multiple(doublylinkedlist<T>::listiterator i, T val1,T val2,T val3) {
	
		insertafter(i,val1);
		insertafter(++i,val2);
		insertafter(++i,val3);
		
	}
	void deleteone(doublylinkedlist<T>::listiterator i) {
		if (i == begin()) {
			node* temp = head->next;
			head->next = head->next->next;
			head->next->previous = NULL;
			delete[]temp;
		}
		else if (i.current == NULL) {
			cout << "EMPTY>>" << endl;
		}
		else if (i.current->next == NULL) {
			node* temp = i.current;
			i.current->previous->next = NULL;
			delete[]temp;
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
	void delete_range(doublylinkedlist<T>::listiterator i, doublylinkedlist<T>::listiterator j) {
		int counti = getcount_iterator(i);
		int countj = getcount_iterator(j);
		if (counti >= countj) {
			for (int k = 0;k < counti - countj;k++) {
				deleteone(i++);
			}
		}
		else {
			for (int k = 0;k < countj - counti;k++) {
				deleteone(j++);
			}
		}
	
	}
	listiterator search_first(T value) {
		node* temp = head->next;
		bool flag = 0;
		doublylinkedlist<T>::listiterator i;
		while (temp!=NULL && temp->data != value) {

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

private:
	node* head;

};



int main() {
	doublylinkedlist<int>l1;
	l1.insert_at_head(5);
	l1.insert_at_head(4);
	l1.insert_at_head(3);
	l1.insert_at_head(2);
	l1.insert_at_head(1);
	l1.insert_at_head(0);
	doublylinkedlist<int>::listiterator X = l1.begin();
	for (;X != l1.end();X++) {
		cout << (*X) << "->";
	}
	cout << "nullptr" << endl;
	
	cout << "at head and at not tail 0 4" << endl;
	l1.swap(0, 4);
	cout << endl;
	l1.display();
	cout << endl;
	cout << "at not head and at tail 2 5" << endl;
	l1.swap(2, 5);
	cout << endl;
	l1.display();
	cout << endl;
	cout << "at head and at tail " << endl;
	l1.swap(4, 2);
	cout << endl;
	l1.display();
	cout << endl;

	cout << endl;
	l1.display();
	cout << endl;
	cout << "DELETE FROM HEAD" << endl;
	l1.delete_from_head();
	cout << "REPLACE 3.." << endl;
	l1.replaceallexistingvalues(3);
	cout << "DELETE ALL EXISTING VALUE 7 " << endl;
	
	l1.deleteallexistingvalues(3);
	doublylinkedlist<int>::listiterator Y = l1.begin();
	bool flag = 0;
	cout << "INSERT MULTIPLE AFTER 5" << endl;
	while (flag != 1 && Y!=l1.end()) {
		if (*Y == 5) {
			flag = 1;
			Y--;
		}
		Y++;
	}
	cout << "Insert MULTIPLE: 7,7,9" << endl;
	l1.insert_multiple(Y, 7, 7, 9);
	cout << endl;
	l1.display();
	cout << endl;
	cout << "DELETE  BY ITERATOR " << endl;
	l1.deleteone(Y);
	cout << endl;
	l1.display();
	cout << endl;
	//cout << "DELETE MULTIPLE noof val 2 THROGH ITERATOR" << endl;
	//l1.delete_multiple(++Y,2);
	//cout << "After Delete Multiple.." << endl;
	//cout << endl;
	l1.display();
	cout << endl;
	doublylinkedlist<int>::listiterator Z = l1.begin();
	bool flag1 = 0;
	cout << "MOVE to previous -<0 FOR DELETE RANGE" << endl;
	while (flag1 != 1 && Z != l1.end()) {
		if (*Z == 0) {
			flag1 = 1;
			Z--;
		}
		else {
			Z++;
		}
	
	}
	if (flag == 0) {
		cout << "NOTFOUND" << endl;
	}
	else {
		cout << "successful" << endl;
	}
	l1.delete_range(Y, Z);
	cout << endl;
	l1.display();
	cout << endl; 


}