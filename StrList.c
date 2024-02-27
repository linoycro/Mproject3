#include <stdio.h>
#include "StrList.h"
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    char* _data;
    struct _node* _next;
} Node;

Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }
    newNode->_data = strdup(data);
    newNode->_next = NULL;
    return newNode;
}

struct _StrList {
    Node* _head;
    size_t _size;
};

typedef struct _StrList StrList;

StrList* StrList_alloc() {
    StrList* p = (StrList*)malloc(sizeof(StrList));
	p->_head= NULL;
	p->_size= 0;
	return p;
}

void StrList_free(StrList* StrList) {
    if (StrList==NULL) return;
	Node* p1= StrList->_head;
	Node* p2;
	while(p1) {
		p2= p1;
		p1= p1->_next;
        free(p2);
        	}
	free(StrList);
}

size_t StrList_size(const StrList* StrList) {
    	return StrList->_size;
}

void StrList_insertLast(StrList* StrList,
					  const char* data) {
    Node* newNode = createNode(data);
    if (StrList->_head == NULL) {
        StrList->_head = newNode;
    } else {
        Node* current = StrList->_head;
        while (current->_next != NULL) {
            current = current->_next;
        }
        current->_next = newNode;
    }
    StrList->_size++;}

void StrList_insertAt(StrList* StrList,
	const char* data,int index) {
        Node* newNode = createNode(data);
        if (index == 0) {
        newNode->_next = StrList->_head;
        StrList->_head = newNode;
        StrList->_size++;
        return;
    }

    Node* current = StrList->_head;
    int count = 0;
    while (current != NULL && count < index - 1) {
        current = current->_next;
        count++;
    }

    if (current == NULL) {
        return;
    }

    newNode->_next = current->_next;
    current->_next = newNode;
    StrList->_size++;
}
    

char* StrList_firstData(const StrList* StrList) {
    	return StrList->_head->_data;
}

void StrList_print(const StrList* StrList) {
    const Node* p= StrList->_head;
	while(p->_next) {
		printf("%s ", p->_data);
		p= p->_next;
	}
    printf("%s\n", p->_data);
}

void StrList_printAt(const StrList* StrList, int index) {
    if (index < 0 || index >= StrList->_size) {
        return;
    }

    Node* current = StrList->_head;
    int count = 0;
    while (current != NULL && count < index) {
        current = current->_next;
        count++;
    }
    printf("%s\n", current->_data);
}


int StrList_printLen(const StrList* StrList) {
    const Node* p = StrList->_head;
    int sum = 0;
    while (p) {
        sum += strlen(p->_data);
        p = p->_next;
    }
    return sum;
}

int StrList_count(StrList* StrList, const char* data) {
    const Node* p= StrList->_head;
    int count = 0;
    while(p) {
        if(strcmp(p->_data, data) == 0) {
            count++;
        }
        p= p->_next;
    }
    return count;
}

void StrList_remove(StrList* StrList, const char* data) {
    const Node* p= StrList->_head;
    int index = 0;
    while (p != NULL) {
        Node* nextNode = p->_next; 
        if (strcmp(p->_data, data) == 0) {
            StrList_removeAt(StrList, index); 
        }
        p = nextNode; 
        index++; 
} }

void StrList_removeAt(StrList* StrList, int index) {
    if (index == 0) {
        Node* temp = StrList->_head;
        StrList->_head = StrList->_head->_next;
        free(temp);
        return;
    }
    Node* current = StrList->_head;
    int count = 0;
    while (current != NULL && count < index - 1) {
        current = current->_next;
        count++;
    }

    if (current == NULL || current->_next == NULL) {
        return;
    }
	Node* temp = current->_next;
    current->_next = temp->_next;
    free(temp); }


int StrList_isEqual(const StrList* StrList1, const StrList* StrList2) {
    const int eq= 0;
	const int neq= 1;
	
	const Node* p1= StrList1->_head;
	const Node* p2= StrList2->_head;
	while(p1) {
		if (p2==NULL||p1->_data!=p2->_data) return neq;
		p1= p1->_next;
		p2= p2->_next;
	}
	if (p2!=NULL) return neq;
	return eq;
}

StrList* StrList_clone(const StrList* lst) {
    StrList* ret;
    ret = StrList_alloc();

    if (lst->_head == NULL) {
        return ret;
    }

    const Node* old = lst->_head;
    Node** copy = &(ret->_head);
    ret->_size = lst->_size;

    while (old != NULL) {

        *copy = createNode(old->_data);
        
        old = old->_next;

        copy = &((*copy)->_next);
    }

    return ret;
}


void StrList_reverse(StrList* StrList) {
    Node *prev = NULL, *current = StrList->_head, *next = NULL;
    while(current!=NULL) {
        next = current->_next;
        current->_next = prev;
        prev = current;
        current = next;
    }
    StrList->_head= prev;
}

void StrList_sort( StrList* StrList) {
     int swapped;
    Node *p1 = NULL; 
    Node *p2 = NULL;
    Node *ptr1;

    if (StrList == NULL || StrList->_head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = StrList->_head;
        p1 = ptr1;

        while (p1->_next != p2) {
            if (strcmp(p1->_data, p1->_next->_data) > 0) {
                char *temp = p1->_data;
                p1->_data = p1->_next->_data;
                p1->_next->_data = temp;
                swapped = 1;
            }
            p1 = p1->_next;
        }
        p2 = p1;
    } while (swapped);

}

int StrList_isSorted(StrList* StrList) {
    if (StrList->_head == NULL || StrList->_head->_next == NULL) {
        return 1; 
    }

    const Node* current = StrList->_head;
    while (current->_next != NULL) {
        if (strcmp(current->_data, current->_next->_data) > 0) {
            return 0; 
        }
        current = current->_next;
    }
    return 1; 
}







