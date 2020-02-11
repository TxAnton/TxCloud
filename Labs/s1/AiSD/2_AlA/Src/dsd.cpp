 #include <iostream>
 #include <cstdlib>

 base getAtom (const lisp s){
        if (!isAtom(s)) {
            cerr << "Error: getAtom(s) for !isAtom(s) \n";
            exit(1);
        }
        else
            return (s->node.atom);
    }

//...........................
const lisp read_arg(base* x){
    lisp arg;
    cin>>(*x);
    if((*x).compare(")")){
        cout<<"Ошибка. Неверный аргумент"<<endl;
        return 0;
    }
    if((*x).compare("(")){
        read_seq(arg);
        return arg;
    }
    if((((*x)>= "a")&&((*x) <= "z"))||((*x).compare("1")==0)||((*x).compare("0")==0)){
        arg = make_atom((*x));
        return arg;
    }
    else{
        cout<<"Ошибка."<<endl;
        return 0;
    }
}
void read_seq ( lisp& y) {
    base x;
    lisp arg1, op, tl;
    if (!(cin >> x)) {
        cerr << "Ошибка. Пустой сегмент" << endl;
        exit(1);3+
    }
    else {
        if (x.compare(")")){
            cout<< "Ошибка. Нет оператора"<<endl;
            y = NULL;
        }
        else if ((x.compare("OR") == 0)||(x.compare("AND") == 0)||(x.compare("XOR") == 0)){
            op = make_atom(x);
            arg1 = read_arg(&x);
            tl = cons(arg1, read_arg(&x));
            y = cons(op, tl);
        }
        else if ((x.compare("NOT") == 0)){
            op = make_atom(x);
            y = cons(op,read_arg(&x));
        }

    }
}