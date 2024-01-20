#pragma once
#include <iostream>

template <typename T>
class LinkedList
{
public:
    class Node
    {
    public:
        Node(const T& AValue) : Value(AValue), Next(), Prev()
        {
        }

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
    
    LinkedList(const LinkedList& AOriginal)
    {
        auto CurrentNode = AOriginal.GetHeadNode();
        MSize = AOriginal.MSize;
        if (CurrentNode == nullptr)
        {
            MHead = MTail = nullptr;
            return;
        }
        MHead = new Node{CurrentNode->Value};
        auto PrevNode = MHead;
        CurrentNode = CurrentNode->Next;
        Node* LNode = MHead;
        while (CurrentNode != nullptr)
        {
            LNode = new Node{CurrentNode->Value};
            LNode->Prev = PrevNode;
            PrevNode->Next = LNode;
            PrevNode = LNode;
            CurrentNode = CurrentNode->Next;
        }
        MTail = LNode;
    }
    
    LinkedList(LinkedList&& AOriginal) noexcept
    {
        MHead = AOriginal.MHead;
        AOriginal.MHead = nullptr;
        
        MTail = AOriginal.MTail;
        AOriginal.MTail = nullptr;
        
        MSize = AOriginal.MSize;
        AOriginal.MSize = 0;
        
    }
    LinkedList& operator=(const LinkedList& AOriginal)
    {
        if (this != &AOriginal)
        {
            this->~LinkedList();
            auto CurrentNode = AOriginal.GetHeadNode();
            MSize = AOriginal.MSize;
            if (CurrentNode == nullptr)
            {
                MHead = MTail = nullptr;
                return *this;
            }
            MHead = new Node{CurrentNode->Value};
            auto PrevNode = MHead;
            CurrentNode = CurrentNode->Next;
            Node* LNode = MHead;
            while (CurrentNode != nullptr)
            {
                LNode = new Node{CurrentNode->Value};
                LNode->Prev = PrevNode;
                PrevNode->Next = LNode;
                PrevNode = LNode;
                CurrentNode = CurrentNode->Next;
            }
            MTail = LNode;
        }

        return *this;
    }
    
    LinkedList& operator=(LinkedList&& AOriginal) noexcept
    {
        if (this != &AOriginal)
        {
            this->~LinkedList();
            
            MHead = AOriginal.MHead;
            AOriginal.MHead = nullptr;
        
            MTail = AOriginal.MTail;
            AOriginal.MTail = nullptr;
        
            MSize = AOriginal.MSize;
            AOriginal.MSize = 0;
        }
        return *this;
    }

    Node* PushBack(const T& AElement)
    {
        auto LNode = new Node{AElement};
        if (MSize == 0)
        {
            MHead = MTail = LNode;
            ++MSize;
            return LNode;
        }

        MTail->Next = LNode;
        LNode->Prev = MTail;
        MTail = LNode;
        ++MSize;
        return LNode;
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

    bool IsEmpty() const
    {
        return MSize == 0;
    }

    Node* InsertAfter(const T& AElement, Node* APosition)
    {
        auto LNode = new Node{AElement};
        auto CurrentNext = APosition->Next;
        APosition->Next = LNode;
        CurrentNext->Prev = LNode;
        LNode->Prev = APosition;
        LNode->Next = CurrentNext;
        if (APosition == MTail)
        {
            MTail = LNode;
        }

        return LNode;
    }

    void Remove(const Node* APosition)
    {
        auto PrevNode = APosition->Prev;
        auto NextNode = APosition->Next;
        if (MHead == MTail)
        {
        }
        else if (APosition == MHead)
        {
            MHead = NextNode;
            NextNode->Prev = nullptr;
        }
        else if (APosition == MTail)
        {
            MTail = PrevNode;
            PrevNode->Next = nullptr;
        }
        else
        {
            PrevNode->Next = NextNode;
            NextNode->Prev = PrevNode;
        }
        --MSize;
        delete APosition;
    }

    void Reverse()
    {
        Node* current_node = MTail = MHead;
        while (current_node->Next != nullptr)
        {
            std::swap(current_node->Next, current_node->Prev);
            current_node = current_node->Prev;
        }
        std::swap(current_node->Next, current_node->Prev);
        MHead = current_node;
    }

    int Count() const
    {
        return MSize;
    }

    Node* GetHeadNode() const
    {
        return MHead;
    }

private:
    Node* MHead;
    Node* MTail;
    int MSize;
};


template <typename T>
std::ostream& operator<<(std::ostream& out, LinkedList<T>& linked_list)
{
    auto current_node = linked_list.GetHeadNode();
    while (current_node != nullptr)
    {
        out << current_node->Value << '\n';
        current_node = current_node->Next;
    }
    return out;
}
