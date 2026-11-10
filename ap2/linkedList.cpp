class No{
    int valor;
    No* next;

    No(int valor, No* next = nullptr){
        this->valor = valor;
        this->next = next;
    }
    
};

class linkedList {
    No* head;

    linkedinList(){
        head = new No(0);
    }

    int size(){
        No* pont = head;
        int n = 0;
        while(pont->next != nullptr){
            pont = pont->next;
            n++;
        }
        return n;
    }

    bool isThere(int n){
        No* pont = head;
        while(pont->next != nullptr){
            pont = pont->next;
            if(pont->valor == n){
                return true;
            }
        }
        return false;
    }


    bool reverse(){
        if(head->next == nullptr){
            return false;
        }
        No* curr = head->next;
        No* nextP = nullptr;
        No* prev = nullptr;

        while(curr != nullptr){
            nextP = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextP;
        }
        head->next = prev;
        return true;
    }

    void addF(int n){
        No* pont = head;
        while(pont->next != nullptr){
            pont = pont->next;
        }
        No* novo = new No(n);
        pont->next = novo;
    }

    void removeDuplicates(){
        No* pont1 = head -> next-> next;
        No* pont2 = head -> next;

        while(pont1 != nullptr){
            if(pont1 == pont2){
                pont1 = pont1->next;
                pont2 = head->next;
                continue;
            }
            if(pont1->valor == pont2->valor){
                while(pont2->next != pont1){
                    pont2 = pont2->next;
                }
                pont2->next = pont1->next;
                pont2 = head->next;
                No* exclude = pont1;
                pont1 = pont1->next;
                delete exclude;
            } else {
                pont2 = pont2->next;
            }
        }
    }

    void selectionSort(){
        if(head->next == nullptr){
            return;
        }
        No* menor = pont;
        while(pont != nullptr){
            No* menor = pont->valor;
            No* pont2 = pont->next;
            while(pont2 != nullptr){
                if(menor->valor > pont2->valor){
                    menor = pont2;
                }
                pont2 = pont2->next;
            }
            swap(menor->valor, pont->valor);
            pont = pont->next;
        }
    } 

    int findByIndexF(int n){
        if(head->next == nullptr){
            return -1;
        }
        No* pont = head ->next;
        int size = this->size();
        int i = 0;
        while(i < size - n){
            pont = pont->next;
            i++;
        }
        return pont->valor;
    }

    void removeByIndex(int n){
        if(n >= this->size()){
            return;
        }
        No* pont = head;
        int i = 0;
        while(i < n){
            if(pont->next == nullptr){
                return;
            }
            pont = pont->next;
            i++;
        }
        No* remove = pont->next;
        pont->next = pont->next->next;
        delete remove;
    }

    void duplicate(){
        No* cur = head->next;
        No* prev = nullptr;

        while(cur != nullptr){
            prev = cur;
            cur = cur->next;
            No* novo = new No(prev->valor);
            novo->next = cur;
            prev->next = novo;
        }
    }
    
    No* reverseRec(int size = this->size()){
        if(size == 0){
            return head;
        }
        if(size == 1){
            head->next->next = nullptr;
            return head->next;
        }
        No* pont =  head;
        int i = 0;
        while(i < size){
            pont = pont->next;
            i++;
        }
        size--;
        pont->next = reverseRec(size);
        head->next = pont;
        return pont;
    }

}

linkedList mesclar(linkedList arr, linkedList arr2) {
    linkedList nova;
    No* pont1 = arr->head;
    while(pont1->next != nullptr){
        pont1 = pont1->next;
        nova.addF(pont1->valor);
    }
    pont1 = arr2->head;
    while(pont1->next != nullptr){
        pont1 = pont1->next;
        nova.addF(pont1->valor);
    }
    return nova;
}
