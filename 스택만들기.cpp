#include <stdio.h>

template <typename T>
class STACK {
public:
    STACK<T>(int theCapacity = 100) {
        stack = new T[theCapacity];
        count = 0;
    }
public:
    T Top() {
        if (count > 0) return top;
        else return -1;
    }

    void pop() {
        if (count > 0) {
            printf("%d\n", top);
            count--;
            top = stack[count - 1];
        }
        else   printf("-1\n");
    }

    void push(T e) {
        stack[count++] = e;
        top = stack[count - 1];
    }

    int size() { return this->count; }

    bool isEmpty() {
        if (count == 0)   return true;
        else if (count > 0) return false;
    }
private:
    T* stack;
    T top;
    int count;
};

int main() {
    int n, val;
    scanf("%d", &n);
    STACK<int> stack(n);
    getchar();
    char order[6];
    for (int i = 0; i < n; i++) {
        scanf("%s", order, sizeof(order));
        switch (order[0]) {
        case 'p':
            if (order[1] == 'u') {
                scanf("%d", &val);
                stack.push(val);
            }
            else if (order[1] == 'o') stack.pop();
            break;
        case 't':
            printf("%d\n", stack.Top());
            break;
        case 'e':
            if (stack.isEmpty())   printf("1\n");
            else printf("0\n");
            break;
        case 's':
            printf("%d\n", stack.size());
            break;
        }
    }
    return 0;
}