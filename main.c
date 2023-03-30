#include "stive.h"
#include "cozi.h"

int main()
{
    Node *sMain = NULL;
    Queue* queue = createQueue();
    int choice;
    printf("\n\tStacks:\n\t\t1:Reverse stack\n\t\t2:Check for palindrome\n\t\t3:Check if paranthesis order is valid ");
    printf("\n\tQueues\n\t\t4:Reverse queue with stack");
    printf("\n\t5:Exit");
    while(1) {
        printf("\n\nChoice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1: {
                Data chr;
                printf("\n\nelem: ");
                scanf("%c", &chr);
                getchar();
                while (chr >= '0' && chr <= '9') {
                    push(&sMain, chr);
                    printf("\n\nelem: ");
                    scanf("%c", &chr);
                    getchar();
                }
                print(sMain);
                printf("\n");
                reverseStack(&sMain);
                print(sMain);
                break;
            }
            case 2: {
                Data chrString[] = "iobababXbababoi";
                int stop = 0, i = 1;
                while (chrString[stop] != 'X') {
                    push(&sMain, chrString[stop]);
                    stop++;
                }
                while (chrString[stop + i] != '\0' && chrString[stop + i] == pop(&sMain))
                    i++;
                if (i - 1 == stop)
                    printf("palindrom");
                break;
            }
            case 3: {
                Node *pozitii = NULL;
                Data paranteze[] = "()()()()(())(()()()";
                int countParanteze = 0, err = 0;
                while (paranteze[countParanteze]) {
                    if (paranteze[countParanteze] == '(') {
                        push(&sMain, paranteze[countParanteze]);
                        char poz = countParanteze + '1';
                        push(&pozitii, poz);
                    }
                    if (paranteze[countParanteze] == ')') {
                        pop(&pozitii);
                        if (isEmpty(sMain)) {
                            err = 1;
                            printf("\nparanteza de pe poz %d n are pereche\n", countParanteze);
                        }
                        pop(&sMain);
                    }
                    countParanteze++;
                }
                if (!isEmpty(sMain) && err == 1)
                    printf("Ordine gresita!");
                else if (err == 1)
                    printf("Prea multe inchise!");
                else if (!isEmpty(sMain)) {
                    printf("Prea multe deschise!");
                    printf("\nparanteza de pe poz %d n are pereche\n", pop(&pozitii) - 48);
                }
                break;
            }
            case 4: {
                int elem;
                printf("\nelem: ");
                scanf("%d",&elem);
                getchar();
                Queue* temp = NULL;
                temp=createQueue();
                while(elem){
                    enQueue(queue,elem);
                    enQueue(temp,elem);
                    printf("\nelem: ");
                    scanf("%d",&elem);
                }
                Node* stackForReversal=NULL;
                char aux;
                int val;
                while(!isqEmpty(temp)){
                    val = deQueue(temp);
                    if(val < 10) {
                        aux = '0' + val;
                    }
                    else {
                        aux = 'A' + val - 10;
                    }
                    push(&stackForReversal, aux);
                }
                printf("\n");
                printQueue(queue);
                printf("\n");
                deleteQueue(queue);
                queue=createQueue();
                while(!isEmpty(stackForReversal)){
                    val= pop(&stackForReversal) -'0';
                    enQueue(queue,val);
                }
                printQueue(queue);
                printf("\n");
            }
            case 5:
                exit(0);
            default:
                printf("\n\nAlegere gresita");
                break;
        }
    }
}
