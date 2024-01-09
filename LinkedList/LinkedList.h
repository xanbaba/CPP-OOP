#pragma once

template <typename T>
class LinkedList
{
public:
    class Node
    {
    public:
        Node(const T& AValue) :Value(AValue), Next(), Prev() {}
        T Value;
        Node* Next;
        Node* Prev;
    };

    ~LinkedList()
    {

        Clear();
    }

    LinkedList() : MHead(), MTail(), MSize()
    {
    }

    void PushBack(const T& AElement)
    {
        auto LNode = new Node{AElement};
        if (MSize == 0)
        {
            MHead = MTail = LNode;
            ++MSize;
            return;
        }

        MTail->Next = LNode;
        LNode->Prev = MTail;
        MTail = LNode;
        ++MSize;
    }

    void PopFront()
    {
        auto NextNode = MHead->Next;
        delete MHead;
        MHead = NextNode;
        MHead->Prev = nullptr;
    }

    void PopBack()
    {
        auto PrevNode = MTail->Prev;
        delete MTail;
        MTail = PrevNode;
        MTail->Next = nullptr;
    }

    void Clear()
    {
        Node* LCurrent = MHead;

        while (LCurrent != nullptr)
        {
            auto LNext = LCurrent->Next;
            delete LCurrent;
            LCurrent = LNext;
        }
        MSize = 0;
    }

    bool Empty()
    {
        return MSize == 0;
    }

    void InsertAfter(const T& AElement, const Node* APosition)
    {
        auto LNode = new Node{AElement};
        auto CurrentNext = APosition->Next;
        APosition->Next = LNode;
        CurrentNext->Prev = LNode;
        LNode->Prev = APosition;
        LNode->Next = CurrentNext;
    }

private:
    Node* MHead;
    Node* MTail;
    int MSize;
};
