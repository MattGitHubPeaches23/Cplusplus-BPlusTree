// Copyright (c) 2019, Matthew Chalifoux.

#include "bplustree.h"
template<typename T>
void random(BPlusTree<T>& test);
template<typename T>
void interactive(BPlusTree<T>& test, int cat[], int num);
template<typename T>
void randomBig(BPlusTree<T> &open,int num, int& got);
int main(int argc, char *argv[])
{
    BPlusTree<int> test;

    srand(time(0));
    int got;
    randomBig(test,200, got);
    cout << "************ TEST *********************" << endl;
    cout << test << endl;

    BPlusTree<int>::Iterator bb;
    bb = test.begin();
    do{
        bb.print_Iterator();
        ++bb;

    }while(bb != test.end());
    cout << endl;

//    BPlusTree<int> test2(test);
//    //test2 = test;
//    //test.insert(85);
//    cout << "Test after insert" << endl;
//    cout << "************ TEST *********************" << endl;
//    cout << test << endl;

//    bb = test.begin();
//    do{
//        bb.print_Iterator();
//        ++bb;

//    }while(bb != test.end());


//    cout << "************ TEST 2*********************" << endl
//         << "            BPlusTree<int> test2(test);      " << endl;
//    cout << test2 << endl;

//    BPlusTree<int>::Iterator bb2;
//    bb2 = test2.begin();
//    do{
//        bb2.print_Iterator();
//        ++bb2;

//    }while(bb2 != test2.end());
//    cout << endl;

//    cout << "SIZE of test2 = " << test2.size() << endl;
    //test2.insert(999);




//    BPlusTree<int> test3;
//    test3 = test2;

//    cout << "************ TEST 3*********************" << endl;
//    cout << "             test3 = test2;   " << endl;
//    cout << test3 << endl;


//    BPlusTree<int>::Iterator bb3;
//    bb3 = test3.begin();
//    do{
//        bb3.print_Iterator();
//        ++bb3;

//    }while(bb3 != test3.end());
//    cout << endl;
   //cout << "SIZE of test3 = " << test3.size() << endl;






    return 0;
}

template<typename T>
void randomBig(BPlusTree<T> &open,int num, int& got){
    //record here[num];
    int cat[num];
    for(int i = 0; i < num; ++i){
        int num0;
        num0 = rand()%1000;

        open.insert(num0);
        cat[i] = num0;
    }
    //cout << open;


    //interactive(open, cat,num);
//    cout << "****************************************" << endl;
//    cout << open;

//    for(int i = 0; i < num; ++i){
//        int num0;
//        num0 = rand()%num;
//        int yup = cat[num0];


//        open.erase(yup);
//    }
//    cout << "***********************************" << endl;
//    cout << open;

}



template<typename T>
void interactive(BPlusTree<T>& test, int cat[], int tell){
    BPlusTree<T> test2;
    BPlusTree<T> test3;
    char ans = '\0';
    do{
        cout << "[R]andom  [I]nsert  [E]rase  [G]oBack  [S]ave  [P]lugSave  e[X]it: " << endl;
        cin >> ans;
        if(ans == 'R' || ans == 'r'){
            int num = 0;
            num = rand()%100;
            cout << "Entering number " << num << endl;
            test2.clear_tree();
            test2 = test;
            test.insert(num);
            cout << test;
        }
        else if(ans == 'I' || ans == 'i'){
            int num;
            cout << "Enter number to insert : ";
            cin >> num;
            cout << "Entering number " << num << endl;
            test2.clear_tree();
            test2 = test;
            test.insert(num);
            cout << test;
        }
        else if(ans == 'E' || ans == 'e'){

            cout << "Enter number to erase : ";


//                int num0;
//                num0 = rand()%tell;
//                int yup = cat[num0];

//                test2.clear_tree();
//                test2 = test;
//                test.erase(yup);

            int num0;
            cin >> num0;
            test2.clear_tree();
            test2 = test;
            test.erase(num0);






            cout << "Erasing number " << num0 << endl;

            //test.erase(num);
            cout << test;
        }
        else if(ans == 'G' || ans == 'g'){
            test.clear_tree();
            test = test2;
            cout << test;
        }
        else if(ans == 's' || ans == 'S'){
            test3.clear_tree();
            test3 = test;
            cout << "SAVED" << endl;
            cout << test;
        }
        else if(ans == 'p' || ans == 'P'){
            test.clear_tree();
            test = test3;
            cout << test;
        }
        else if(ans == 'X' || ans == 'x'){
            BPlusTree<int>::Iterator bb;
            bb = test.begin();
            do{
                bb.print_Iterator();
                ++bb;

            }while(bb != test.end());
            cout << endl;
            //exit(1);
        }

    }while(ans != 'X' || ans != 'x');
}

template<typename T>
void random(BPlusTree<T>& test){
    for(int i = 0; i < 500; ++i){
        int num = 0;
        num = rand()%1000;
        test.insert(num);
    }

    cout << test;
}
