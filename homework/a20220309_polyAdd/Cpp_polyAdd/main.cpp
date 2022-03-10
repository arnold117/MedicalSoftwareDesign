#include <iostream>

using namespace std;

struct Polynomial
{
    int coef{};
    int expr{};
    Polynomial* next = nullptr;
};

Polynomial* read()
{
    auto* head = new Polynomial;
    int n;
    cout << "input the number of non-zero polynomial terms";
    cin >> n;
    cout << "input the polynomial terms with the form of \"3 2\" as 3x^2, separate with space";
    Polynomial* last = head, * temp;
    for (int i = 0; i < n; i++)
    {
        temp= new Polynomial;
        cin >> temp->coef >> temp->expr;
        last->next = temp;
        last = last->next;
    }
    return head;
}

Polynomial* add(Polynomial* list1, Polynomial* list2)
{
    auto* head = new Polynomial;
    Polynomial* last = head, * temp, * p1 = list1->next, * p2 = list2->next;
    while (p1 && p2)
    {
        temp = new Polynomial;
        if (p1->expr > p2->expr)
        {
            temp->coef = p1->coef;
            temp->expr = p1->expr;
            p1 = p1->next;
        }
        else if (p1->expr < p2->expr)
        {
            temp->coef = p2->coef;
            temp->expr = p2->expr;
            p2 = p2->next;
        }
        else
        {
            if (p1->coef + p2->coef != 0)
            {
                temp->coef = p1->coef + p2->coef;
                temp->expr = p1->expr;
            }
            else
            {
                free(temp);
                temp = nullptr;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        if (temp)
        {
            last->next = temp;
            last = last->next;
        }
    }
    if (p1)  last->next = p1;
    if (p2)  last->next = p2;
    return head;
}

void showRes(Polynomial* polynomial)
{
    Polynomial* p = polynomial->next;
    if (!p)
        cout << "0 0";
    for (; p; p=p->next)
    {
        cout << "(" << p->coef << ")x^(" << p->expr << ")";
        if (p->next)
            cout << "+";
    }
    cout << endl;
}

int main()
{
    Polynomial* list1, *list2;
    cout << "enter the first list:";
    list1= read();
    cout << "enter the second list:";
    list2 = read();
    Polynomial* result;
    result = add(list1, list2);
    showRes(result);
    return 0;
}