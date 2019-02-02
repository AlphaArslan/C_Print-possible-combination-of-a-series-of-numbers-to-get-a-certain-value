//In this version of the program, you can find all possible paths
//you can also choose start and end and the sum you want
//Concatenation is finally available yaaaaaaaaaaaaaaaaaay
//you are welcome ^_^

#include <stdio.h>

/*********** Control Panel ***********/
#define         m_START       1
#define         m_END           9
#define         m_Sum           100
#define         m_ResultBuf   20
/**********************************/

enum flags {PLUS , MINUS};

typedef struct {
    int     value;
    void   *next;
    void   *prev;
}Tree;

Tree one ;
char result[m_ResultBuf];


void  init_tree(Tree* ,int ,int );
int    Engine(Tree*, char*, char, char, int, char);
int    getCncCarry(char, char, int, Tree*);




int main()
{
    init_tree(&one ,m_START ,m_END );
    printf("Initialized\n");
    Engine(&one, result, 0, 0, m_START, PLUS);
    return 0;
}




void init_tree(Tree *node ,int start ,int end){
    if(start == end) {
        node->value = end;
        node ->next = NULL;
        return;
    }

    node ->value = start;

    node ->next = malloc(sizeof(Tree));
    ((Tree*)(node->next))->prev = node;
    init_tree(node ->next ,start+1 ,end);

}





int Engine(Tree *node, char *result, char counter, char cnc_counter, int carry, char op_flag){

    result[counter++] = (char)((node ->value) + '0');

    if(node->value == m_END){
        result[counter] = '\0';
        if(carry == m_Sum)printf("%s\n", result);
        return 0;
    }


    result[counter] = '+';
    Engine(node->next , result, counter+1 , 0, carry + ((Tree*)(node->next))->value ,PLUS);

    result[counter] = '-';
    Engine(node->next , result, counter+1 , 0, carry - ((Tree*)(node->next))->value ,MINUS);

    Engine(node->next , result, counter, cnc_counter+1, getCncCarry(cnc_counter, op_flag, carry, node), op_flag);
}





int getCncCarry(char cnc_counter ,char op_flag, int carry ,Tree *node){
    if(cnc_counter == 0){
        if(op_flag == PLUS)     carry = carry + 9 * node->value + ((Tree*)(node->next))->value;
        if(op_flag == MINUS)   carry = carry - 9 * node->value - ((Tree*)(node->next))->value;
        return carry ;
    }
    if(cnc_counter == 1){
        if(op_flag == PLUS)     carry = carry + 9  * node->value + 90 * ((Tree*)(node->prev))->value + ((Tree*)(node->next))->value;
        if(op_flag == MINUS)     carry = carry - 9  * node->value - 90 * ((Tree*)(node->prev))->value - ((Tree*)(node->next))->value;
        return carry ;
    }
}



