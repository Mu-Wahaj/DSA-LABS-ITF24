bool CDLL::merge(CDLL &list1, CDLL &list2)
{
    if (!isEmpty())
        return false;

    if (!list1.isSorted() || !list2.isSorted())
        return false;

    DNode *p = list1.head.next;
    DNode *q = list2.head.next;
    DNode *tail = &head;

    while (p != &list1.head && q != &list2.head)
    {
        if (p->data <= q->data)
        {
            DNode *nextP = p->next;
            tail->next = p;
            p->prev = tail;
            tail = p;
            p = nextP;
        }
        else
        {
            DNode *nextQ = q->next;
            tail->next = q;
            q->prev = tail;
            tail = q;
            q = nextQ;
        }
    }

    while (p != &list1.head)
    {
        DNode *nextP = p->next;
        tail->next = p;
        p->prev = tail;
        tail = p;
        p = nextP;
    }

    while (q != &list2.head)
    {
        DNode *nextQ = q->next;
        tail->next = q;
        q->prev = tail;
        tail = q;
        q = nextQ;
    }

    tail->next = &head;
    head.prev = tail;
    head.next->prev = &head;

    list1.head.next = &list1.head;
    list1.head.prev = &list1.head;
    list2.head.next = &list2.head;
    list2.head.prev = &list2.head;

    return true;
}