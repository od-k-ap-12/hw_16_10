#include <iostream>
using namespace std;

template <typename T>
struct Elem
{
    T data; // данные
    Elem<T> *next;
    Elem<T>* prev;
};

template <typename T>
class QueueList
{
    // Голова, хвост
    Elem<T>* Head, * Tail;
    // Количество элементов
    int Count;

public:

    QueueList<T>();
    QueueList<T>(const QueueList<T>& L);
    void Add(T a);
    T Extract();
    bool IsEmpty();
    void Print();
    int GetCount();
    T GetFirst();
    ~QueueList();
    void DelAll();
    QueueList<T>& operator = (const QueueList<T>&);
};
template <typename T>
bool QueueList<T>::IsEmpty()
{
    return Count == 0;
}

template<typename T>
QueueList<T>::QueueList()
{
    Head = Tail = NULL;
    Count = 0;
}
template<typename T>
QueueList<T>::QueueList(const QueueList<T>& L)
{
    Head = Tail = NULL;
    Count = 0;

    Elem* temp = L.Head;
    while (temp != 0)
    {
        AddTail(temp->data);
        temp = temp->next;
    }
}
template <typename T>
QueueList<T>::~QueueList() 
{
    DelAll();
}

template <typename T>
void QueueList<T>::Add(T n)
{
    Elem<T>* temp = new Elem<T>; 
    temp->next = 0;
    temp->data = n;
    temp->prev = Tail;

    if (Tail != 0)
        Tail->next = temp;

    if (Count == 0)
        Head = Tail = temp;
    else
        Tail = temp;

    Count++;
}

template <typename T>
T QueueList<T>::Extract()
{

    Elem<T>* Extract = nullptr;
    int i = 1;
    Extract = Head;
    Elem<T>* AfterExtract = Extract->next;
    Head = AfterExtract;
    Count--;
    return Extract->data;
}
template<typename T>
void QueueList<T>::Print()
{
    if (Count != 0)
    {
        Elem<T>* temp = Head; 
        cout << "( ";
        while (temp->next != 0)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }

        cout << temp->data << " )\n";
    }
}
template<typename T>
void QueueList<T>::DelAll()
{
    while (Count != 0)
        Extract();
}
template <typename T>
int QueueList<T>::GetCount()
{
    return Count;
}

template<typename T>
T QueueList<T>::GetFirst()
{
    return Head->data;
}

template <class T>
QueueList<T>& QueueList<T>::operator = (const QueueList<T>& L)
{
    if (this == &L)
        return *this;

    this->~List(); 

    Elem* temp = L.Head;

    while (temp != 0)
    {
        AddTail(temp->data);
        temp = temp->next;
    }

    return *this;
}

int main()
{
    QueueList<int> L;

    const int n = 10;
    int a[n] = { 0,1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i < n; i++)
            L.Add(a[i]);

    cout << "List L:\n";
    L.Print();
    int ex1=L.Extract();
    int ex2 = L.Extract();
    cout << ex1<<ex2;
    int head = L.GetFirst();
    cout << endl << head;

}