#ifndef CYCLE_LIST
#include <iostream>
#define CYCLE_LIST
class cycle {
private:
	class node {
	public:
		node * next;
		int data;
		node(int object) :data{object} {};
	};
	node * head;
	int lucky{};
	void kick_next(node * kickitr);
public:
	cycle(int number,int lucknumber);
	void eliminate(int N);
};
#endif 
cycle::cycle(int number, int lucknumber) {
	node * itr;
	int itrnumber{ 1 };
	head = new node{ itrnumber};
	itr = head;
	for (int i{1}; i < number; i++) {
		itrnumber++;
		itr->next = new node{ itrnumber };
		itr=itr->next;
	}
	itr->next = head;
	lucky = lucknumber;
};
void cycle::kick_next(node *kickitr) {
	node *tmp = kickitr->next->next;
	delete kickitr->next;
	kickitr->next = tmp;

};
void cycle::eliminate(int N) {
	node * gameitr = head;
	int count{1};
	while (gameitr->next != gameitr) {
		count++;
		if (count == N) {
			kick_next(gameitr);
			count = 1;
			lucky--;
			if (lucky==0) {
				std::cout << gameitr->next->data;
				return;
			}
		}
		gameitr = gameitr->next;
		
	}
	
};