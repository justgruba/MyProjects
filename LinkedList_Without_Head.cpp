//Justyna Gruba 3 Nov 2020

/* Implementatnion Linked List without head */

#include <iostream>
struct element{
    int i;
    element* next = NULL;
};

void display(element *List) {
    if(List == NULL)
        return;
    element *first = List;

    while(first !=NULL){

        std::cout << first->i << " ";
        first = first->next;
    }

}

element * create(){
    return NULL;
}
element* find(element* List, int a){
    element *tmp = List;
    while(tmp != NULL){

        if(tmp->i == a){
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}
element* add_last(element* List, int a){


    if(List == NULL){
        List->i = a;
        return List;
    }

    element *tmp = List;
    while(tmp->next != NULL){
        tmp = tmp->next;

    }
    element *newElem = new element;
    newElem->i = a;
    tmp->next = newElem;
    return List;
}
element* add_first(element* List, int a){

        element *newElement = new element;
        newElement->i = a;
        newElement->next = List;

        List = newElement;
        return List;
}
element * add_between(element* List, element *x, int a){
    element* newElement = new element;
    newElement->i = a;

    element *tmp = List;

    if(tmp == x){

        newElement->next = List;

        List = newElement;

        return List;
    }

    while(tmp->next != NULL){

        if(tmp->next->i == x->i){
            newElement->next = tmp->next;
            tmp->next = newElement;
            return List;
        }
        tmp = tmp->next;
    }
    return List;
}

element* remove_all(element *List){
    element *tmp = List;

    while(List != NULL){
        List = List-> next;
        std::cout << "usuwane elementy =" << tmp ->i << " " << std::endl;
        delete tmp;
        tmp = List;
    }
    return List;
}
element * remove_integer(element *List, int a){
    if(List == NULL)
        return NULL;

    element *tmp = List;
    if(List->i  == a){
        List= List->next;
        delete tmp;
        return List;
    }
    else{

        while(tmp->next != NULL){

            if(tmp->next->i == a){
               std:: cout << "tmp next wskazuje " << tmp->next->i << std:: endl;
               element * del = tmp->next;
               tmp->next = tmp->next->next;
               delete del;
               return List;
            }
            tmp = tmp->next;
        }
        return List;

    }
}
element* remove_element(element* List, element* elem){
    element* tmp = List;
    if(List->i == elem ->i){

        List = List->next;
        delete tmp;
        if(List == NULL){
            return NULL;
        }
        return List;
    }
    while(tmp->next != NULL){
        if(tmp->next->i == elem->i){
            tmp->next = elem->next;
            std::cout << "usuniety element to " << elem->i << std::endl;
            delete elem;
            break;
        }
        tmp = tmp->next;
    }
    if(tmp == NULL){
        return NULL;
    }
    return List;
}
element* remove_next_element( element* List, element * elem){
    element* tmp = List;

    while(tmp -> next != NULL){

            if(tmp->next->i == elem->next ->i) {

                element *del = elem->next;
                tmp->next = elem->next->next;
                delete del;
                break;
            }
            tmp = tmp->next;
    }
    return List;
}
int main() {
    element *first= create();

    first = add_first(first, 5);
    first = add_first(first, 8);
    first = add_first(first, 15);
    first = add_last(first, 14);
    first = add_last(first, 34);

   element *x = find(first, 15);
    display(first);
   std::cout << std:: endl << "znaleniono element = " << x->i << " " << std:: endl;

   first = add_between(first, x, 28);
   //  display(first);


   //  first= remove_element(first, x);
   //  first = remove_all(first);
   //  first = remove_integer(first, 15);

    first = remove_next_element(first, x);

    display(first);
}

