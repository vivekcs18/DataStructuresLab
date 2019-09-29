#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node * NODE;

NODE getnode() {
    NODE p;
    p = (NODE) malloc(sizeof(struct node));
    if (p != NULL) return p;
    else {
        printf("No Memory \n");
        return NULL;
    }
}

NODE insert_front(int item, NODE head) {
    NODE p;
    p = getnode();
    p -> data = item;
    p -> next = head;
    head = p;
    printf("Inserted \n");
    return head;
}

void insert_back(int item, NODE head) {
    NODE p, q;
    q = getnode();
    q -> data = item;
    q -> next = NULL;
    p = head;
    while (p -> next != NULL) p = p -> next;
    p -> next = q;
    printf("Inserted \n");
}

NODE insert_pos(int item, int pos, NODE head) {
    NODE curr, prev = NULL, newn;
    int count = 1;
    newn = getnode();
    newn -> data = item;
    newn -> next = NULL;
    if (head == NULL) {
        if (pos == 1) printf("Inserted \n");
        else printf("Invalid Position \n");
    }
    if (pos == 1) {
        newn -> next = head;
        head = newn;
        printf("Inserted \n");
        return head;
    } else {
        curr = head;
        while (curr != NULL && count != pos) {
            prev = curr;
            curr = curr -> next;
            count ++;
        }
        if (count == pos) {
            prev -> next = newn;
            newn -> next = curr;
            printf("Inserted \n");
	    return head;
        } else {
            printf("Invalid Position \n");
        } 
    }
}

void display (NODE head) {
    NODE p;
    if (head == NULL) {
        printf("Empty List \n");
        return;
    }
    p = head;
    while (p != NULL) {
        printf("%d \n", p -> data);
        p = p -> next;
    }
}

int main() {
    int choice, pos, ele;
    NODE head = NULL;
    
    do {
        printf("1. Enter from Front \n");
        printf("2. Enter from End \n");
        printf("3. Enter from Position \n");
        printf("4. Display \n");
	printf("5. Exit \n");
        printf("Enter Choice \n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: printf("Enter Element \n");
                    scanf("%d", &ele);
                    head = insert_front(ele, head);
                    break;
            
            case 2: printf("Enter Element \n");
                    scanf("%d", &ele);
                    insert_back(ele, head);
                    break;
                    
            case 3: printf("Enter Element and Position\n");
                    scanf("%d %d", &ele, &pos);
                    head = insert_pos(ele, pos, head);
                    break;
                    
            case 4: display(head);
                    break;

	    case 5: exit(0);
                    break;
            
            default: printf("Invalid Choice \n");
        }
        
        
    } while (choice != 5);

    return 0;
}