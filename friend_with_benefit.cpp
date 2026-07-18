#include <cstdlib>
#include <iostream>

class A;

class B {
    public:
        void Do(A &a);
};

class A {
    friend void B::Do(A& a);
    friend class C;
    private:
        int value;
        void tellMe(void) { std::cout << "my secret is : " << value << "\n" ; }
        void Set(int x) { value = x; }
};

class C {
    friend void callMe (A& a, B& b, C& c, int x);
    private:
        void Set(A& a, B& b, int x) {
            a.Set(x);
            b.Do(a);
        }
};

void B::Do(A& a) {
    a.tellMe();
}

void callMe (A& a, B& b, C& c, int x) {
    c.Set(a, b, x);
}

int main() {
    A a; 
    B b; 
    C c;
   
    callMe(a, b, c, 99);

    return EXIT_SUCCESS;
}
