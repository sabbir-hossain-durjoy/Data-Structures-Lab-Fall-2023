//Conference Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int t_id = 100;
struct Request_queue
{
    char Student_name[50];
    int Student_age;
    char Department[50];
    int status;
    struct Request_queue *next;
} *front = NULL, *rear = NULL, *temp, *x_temp;

void request_ticket(void)
{
    printf("Welcome to the smart ticketing system!\n");
    if (rear == NULL)
    {
        rear = (struct Request_queue *)malloc(sizeof(struct Request_queue));
        printf("Enter your name: ");
        fflush(stdin);
        gets(rear->Student_name);
        printf("Enter your age: ");
        scanf("%d", &rear->Student_age);
        printf("Enter your Department: ");
        fflush(stdin);
        gets(rear->Department);
        printf("Press 1 to confirm your ticket: ");
        int x;
        scanf("%d", &x);
        rear->next = NULL;
        if (x == 1)
        {
            rear->status = 1;
            printf("\nYour ticket is confirmed!!!\n");
            front = rear;
            return;
        }
        else
        {
            free(rear);
            printf("\nYour ticket is not booked!\n");
            return;
        }
    }
    else
    {
        temp = (struct Request_queue *)malloc(sizeof(struct Request_queue));
        printf("Enter your name: ");
        fflush(stdin);
        gets(temp->Student_name);
        printf("Enter your age: ");
        scanf("%d", &temp->Student_age);
        printf("Enter your Department: ");
        fflush(stdin);
        gets(temp->Department);
        printf("Press 1 to confirm your ticket: ");
        int x;
        scanf("%d", &x);
        temp->next = NULL;
        if (x == 1)
        {
            printf("\nYour ticket is confirmed!!!\n");
            rear->next = temp;
            temp->status = 1;
            rear = temp;
            return;
        }
        else
        {
            printf("\nYour ticket is not booked!\n");
            free(temp);
            return;
        }
    }
}
void display_req(void)
{
    temp = front;
    printf("_______________________________________________________\n");
    printf("              Displaying all requests: \n");
    while (temp != NULL)
    {
        printf("_______________________________________________________\n");
        if (temp->status != -1)
        {
            printf("Student's name       : %s\n", temp->Student_name);
            printf("Student's age        : %d\n", temp->Student_age);
            printf("Student's Department : %s\n", temp->Department);
        }
        temp = temp->next;
    }
    printf("_______________________________________________________\n");
}
void update_request(void)
{
    printf("Enter the ticket holder's name: ");
    char name[50];
    fflush(stdin);
    gets(name);
    temp = front;
    while (temp != NULL)
    {
        if (strcmp(temp->Student_name, name) == 0)
        {
            printf("Ticket found!\n");
            printf("Enter the operation to perform: \n");
            printf("1. Change name \n");
            printf("2. Change age \n");
            printf("3. Change Department \n");
            printf("4. Cancel ticket! \n");
            int choice;
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter new name: ");
                fflush(stdin);
                gets(temp->Student_name);
                printf("\nName is Updated!\n");
                return;
            case 2:
                printf("Enter new age: ");
                scanf("%d", &temp->Student_age);
                printf("\nAge is Updated!\n");
                return;
            case 3:
                printf("Enter new Department: ");
                fflush(stdin);
                gets(temp->Department);
                printf("\nDepartment is Updated!\n");
                return;
            case 4:
                printf("Press 1 if you want to cancel your ticket: ");
                int t;
                scanf("%d", &t);
                if (t == 1)
                {
                    temp->status = -1;
                    printf("\nTicket is canceled!!!\n");
                }
                else
                {
                    printf("Invalid!");
                }
                return;

            default:
                printf("Invalid!");
                return;
            }
        }
        temp = temp->next;
    }
    printf("Not found!\n");
    return;
}

struct Ticket_stack
{
    int ticket_id;
    int date;
    int time;
    int seat;
    struct Ticket_stack *next;
} *top = NULL, *temp2, *newnode2, *x_temp2;

void seat_allocation()
{
    int n, column = 1, m_column, row = 1;
    printf("Enter the number of total available seat: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (top == NULL)
        {
            top = (struct Ticket_stack *)malloc(sizeof(struct Ticket_stack));
            top->ticket_id = t_id;
            t_id++;
            printf("Enter the date for all tickets in DDMMYYYY format: ");
            scanf("%d", &top->date);
            printf("Enter the time for all tickets in HHMM format: ");
            scanf("%d", &top->time);
            printf("Enter the number of column in the room: ");
            scanf("%d", &m_column);
            column++;
            top->seat = 11;
            top->next = NULL;
        }
        else
        {

            newnode2 = (struct Ticket_stack *)malloc(sizeof(struct Ticket_stack));
            newnode2->ticket_id = t_id;
            t_id++;
            newnode2->date = top->date;
            newnode2->time = top->time;
            if (column > m_column)
            {
                row++;
                column = 1;
            }
            int x;
            x = (log10(column) + 1);
            newnode2->seat = (pow(10, x) * row) + column;
            column++;
            newnode2->next = top;
            top = newnode2;
        }
    }
}
void display_seat()
{
    temp2 = top;
    printf("_______________________________________________________\n");
    printf("          Displaying available tickets\n");
    while (temp2 != NULL)
    {
        printf("_______________________________________________________\n");
        printf("Ticket id   : %d\n", temp2->ticket_id);
        printf("Ticket date : %d\n", temp2->date);
        printf("Ticket time : %d\n", temp2->time);
        printf("Seat no     : %d\n", temp2->seat);
        temp2 = temp2->next;
    }
    printf("_______________________________________________________\n");
}
struct History
{
    int date;
    int time;
    char Student_name[50];
    int Student_age;
    char Department[50];
    int ticket_id;
    int seat;
    struct History *next;
} *head = NULL, *temp3, *newnode3;

void process(void)
{
    temp = front;
    temp2 = top;
    while (1)
    {
        if (temp == NULL)
        {
            printf("All request is allocated!!!\n");
            front = temp;
            return;
        }
        else if (temp2 == NULL)
        {
            printf("All seats are booked!!!\n");
            top = temp2;
            return;
        }
        if (temp->status != 1)
        {
            x_temp = temp;
            temp = temp->next;
            free(x_temp);
            front = temp;
        }
        else
        {
            if (head == NULL)
            {
                head = (struct History *)malloc(sizeof(struct History));
                head->next = NULL;
                strcpy(head->Student_name, temp->Student_name);
                head->Student_age = temp->Student_age;
                strcpy(head->Department, temp->Department);
                head->date = temp2->date;
                head->time = temp2->time;
                head->ticket_id = temp2->ticket_id;
                head->seat = temp2->seat;
                temp3 = head;

                x_temp = temp;
                temp = temp->next;
                front = temp;
                free(x_temp);

                x_temp2 = temp2;
                temp2 = temp2->next;
                top = temp2;
                free(x_temp2);
            }
            else
            {
                newnode3 = (struct History *)malloc(sizeof(struct History));
                newnode3->next = NULL;
                strcpy(newnode3->Student_name, temp->Student_name);
                newnode3->Student_age = temp->Student_age;
                strcpy(newnode3->Department, temp->Department);
                newnode3->date = temp2->date;
                newnode3->time = temp2->time;
                newnode3->ticket_id = temp2->ticket_id;
                newnode3->seat = temp2->seat;
                newnode3->next = NULL;
                temp3->next = newnode3;
                temp3 = newnode3;

                x_temp = temp;
                temp = temp->next;
                front = temp;
                free(x_temp);

                x_temp2 = temp2;
                temp2 = temp2->next;
                top = temp2;
                free(x_temp2);
            }
        }
    }
}

void display_history()
{
    temp3 = head;
    printf("_______________________________________________________\n");
    printf("                  Displaying History\n");
    while (temp3 != NULL)
    {
        printf("_______________________________________________________\n");
        printf("Student's name       : %s\n", temp3->Student_name);
        printf("Student's age        : %d\n", temp3->Student_age);
        printf("Student's Department : %s\n", temp3->Department);
        printf("Ticket id            : %d\n", temp3->ticket_id);
        printf("Ticket date          : %d\n", temp3->date);
        printf("Ticket time          : %d\n", temp3->time);
        printf("Ticket no            : %d\n", temp3->seat);
        temp3 = temp3->next;
    }
    printf("_______________________________________________________\n");
}
int main()
{
    while (1)
    {
        printf("_______________________________________________________\n");
        printf("Choice an option: \n");
        printf("1. Request for a ticket\n");
        printf("2. Update or cancel ticket\n");
        printf("3. Display all requests\n");
        printf("4. Total Available Seats\n");
        printf("5. Display available tickets\n");
        printf("6. Process request and tickets\n");
        printf("7. Ticket history\n");
        printf("8. Exit\n");
        int choice;
        scanf("%d", &choice);
        printf("_______________________________________________________\n");
        switch (choice)
        {
        case 1:
            request_ticket();
            break;
        case 2:
            update_request();
            break;
        case 3:
            display_req();
            break;
        case 4:
            seat_allocation();
            break;
        case 5:
            display_seat();
            break;
        case 6:
            process();
            break;
        case 7:
            display_history();
            break;
        case 8:
            return 0;
        default:
            printf("Inavlid!!!\n");
            break;
        }
    }

    return 0;
}
