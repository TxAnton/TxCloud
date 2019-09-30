#include<iostream>

//Memory is allocated for BLOCK elements at once
#define BLOCK 16



namespace st_modul2 {

//-------------------------------------
    template <class Elem>
    class Stack {
    private:

        //std::vector<Elem>* vec;


            //size_t alloc_mem;
            //node *topOfStack;

    public:
        Elem* vec;
        int topOfStack;
        Stack() {
            vec=0;

            topOfStack=-1;
        }//;
// -------------------------------------
            bool isEmpty(void)//
        {
            return (topOfStack<0);
        }
//-------------------------------------
        Elem top(void) //Returns top element
        {// PreCondition: not null
            if (this->isEmpty()) {
                std::cerr << "Error: top(Empty) \n";
                exit(1);
            }
            else return vec[topOfStack];
        }

        Elem ttop(void) //TERMINAL TOP. Reterns top element destroying stack right after(for usage like: return stack.ttop();)
        {// PreCondition: not null
            if (this->isEmpty()) {
                std::cerr << "Error: ttop(Empty) \n";
                exit(1);
            }
            else {recClear(); auto ret = vec[topOfStack]; destroy(); return ret;}
        }

//-------------------------------------
        void pop(void)//Removes top element
        {// PreCondition: not null
            if (this->isEmpty()) {
                std::cerr << "Error: pop(Empty) \n";
                exit(1);
            }
            else {
                if(topOfStack%BLOCK==0)vec=(Elem*)realloc(vec,sizeof(Elem)*topOfStack);
                topOfStack--;
            }
        }

//-------------------------------------
        Elem pop2(void)//Removes top element and returns it.
        {// PreCondition: not null
            if (this->isEmpty()) {
                std::cerr << "Error: pop2(Empty) \n";
                exit(1);
            }
            else {
                Elem r = this->top();
                this->pop();
                return r;
            }
        }

//-------------------------------------
        void push(const Elem &x)//Push element on top
        {
            topOfStack++;
            if(topOfStack%BLOCK==0)
                vec=(Elem*) realloc(vec,sizeof(Elem)*(topOfStack+BLOCK));
            if(!vec){
                std::cerr << "Can not allocate more memory!\n";
                exit(1);
            } else{
                vec[topOfStack]=x;
            }
        }

        void recClear()//recusrive clear
        {

            if (!vec) {
                std::cerr << "Error: recClear(None) \n";
                exit(1);
            }
            if(!this->isEmpty()){
                pop();
                recClear();
            }


        }



//-------------------------------------
        void destroy(void)//Suicide
        {
            recClear();
            topOfStack=0;
            if(vec)
            {
                delete vec;
                vec=0;
            }
            //delete this;
        }
    };
} 