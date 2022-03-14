#include <iostream>

using namespace std;

struct Polynomial {
    int coef{};
    int expr{};
    Polynomial* next = nullptr;
};

Polynomial* read() {
    auto* head = new Polynomial;
    int n;

    cout << "input the number of non-zero polynomial terms" << endl;
    cin >> n;
    cout << "input the polynomial terms with the form of \"3 2\" as 3x^2, separate with space" << endl;

    Polynomial* last = head, * temp;

    for (int i = 0; i < n; i++) {
        temp= new Polynomial;
        cin >> temp->coef >> temp->expr;
        last->next = temp;
        last = last->next;
    }

    return head;
}

Polynomial* add(Polynomial* list1, Polynomial* list2) {
    auto* head = new Polynomial;
    Polynomial* last = head, * temp, * p1 = list1->next, * p2 = list2->next;

    while (p1 && p2) {
        temp = new Polynomial;

        // Aline the items to corresponded expr
        if (p1->expr > p2->expr) {
            temp->coef = p1->coef;
            temp->expr = p1->expr;
            p1 = p1->next;
        } else if (p1->expr < p2->expr) {
            temp->coef = p2->coef;
            temp->expr = p2->expr;
            p2 = p2->next;
        } else {
            // add coefficient
            if (p1->coef + p2->coef != 0) {
                temp->coef = p1->coef + p2->coef;
                temp->expr = p1->expr;
            // if added unit's result is 0, free memory to simplify formula
            } else {
                free(temp);
                temp = nullptr;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        // added unit exist, append to the end of result list
        if (temp) {
            last->next = temp;
            last = last->next;
        }
    }
    return head;
}

void showRes(Polynomial* polynomial) {
    Polynomial* p = polynomial->next;

    if (!p) {
        cout << "0 0";
    }

    while (p) {
        cout << "(" << p->coef << ")x^(" << p->expr << ")";
        if (p->next){
            cout << "+";
        }
        p = p->next;
    }
    cout << endl;
}

int main() {
    cout << "enter the first list:" << endl;
    Polynomial* list1 = read();
    cout << "enter the second list:" << endl;
    Polynomial* list2 = read();

    Polynomial* result = add(list1, list2);

    showRes(result);

    return 0;
}