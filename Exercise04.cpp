// Creates a Doubly Linked list, adds some elements, then prints the list from front to back and back to front.

#include <cstdio>

struct Element {
	Element* next{};
	Element* previous{};
	void insert_after(Element* new_element) {
		new_element->next = this->next;
		this->next = new_element;
		new_element->previous = this;
		if (new_element->next != NULL) {
		new_element->next->previous = new_element;
		}
	}
	void insert_before(Element* new_element) {
		new_element->previous = this->previous;
		this->previous = new_element;
		new_element->next = this;
		if (new_element->previous != NULL) {
			new_element->previous->next = new_element;
		}
	}
	char prefix[2];
	short operating_number;
};

int main() {
	Element trooper1, trooper2, trooper3, trooper4;
	trooper1.prefix[0] = 'T';
	trooper1.prefix[1] = 'K';
	trooper1.operating_number = 421;
	trooper1.insert_before(&trooper2);
	trooper2.prefix[0] = 'F';
	trooper2.prefix[1] = 'N';
	trooper2.operating_number = 2187;
	trooper2.insert_after(&trooper3);
	trooper3.prefix[0] = 'L';
	trooper3.prefix[1] = 'S';
	trooper3.operating_number = 005;
	trooper2.insert_after(&trooper4);
	trooper4.prefix[0] = 'B';
	trooper4.prefix[1] = 'Z';
	trooper4.operating_number = 007;

	printf("from the front:\n\n");
	for (Element *cursor = &trooper2; cursor; cursor = cursor->next) {
		printf("stormtrooper %c%c-%d\n",
			cursor->prefix[0],
			cursor->prefix[1],
			cursor->operating_number);
	}
	printf("\n");
	printf("from the back:\n\n");
	 for (Element *cursor = &trooper1; cursor; cursor = cursor->previous) {
		printf("stormtrooper %c%c-%d\n",
			cursor->prefix[0],
			cursor->prefix[1],
			cursor->operating_number);
	}
	
}
