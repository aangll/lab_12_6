#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Node {
    string data;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string data) 
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (front == nullptr) 
    {
        front = rear = newNode;
    }
    else 
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void printQueue(Node* front) 
{
    Node* temp = front;
    while (temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

string findLongest(Node* front) 
{

    int maxLen = -1;
    string value;

    Node* temp = front;
    while (temp != nullptr) 
    {
        int len = temp->data.length();
        if (len > maxLen) 
        {
            maxLen = len;
            value = temp->data;
        }
        temp = temp->next;
      
    }
    return value;
}

string findShortest(Node* front) 
{
    int minLen = INT_MAX;
    string value;
    Node* temp = front;
    while (temp != nullptr) 
    {
        int len = temp->data.length();
        if (len < minLen) 
        {
            minLen = len;
            value = temp->data;
        }
        
        temp = temp->next;
       
    }
    return value;
}

int findLongestIdx(Node* front) 
{

    int maxLen = -1;
    int maxIdx = -1;
    int i = 0;

    Node* temp = front;

    while (temp != nullptr) 
    {
        int len = temp->data.length();
        if (len > maxLen) 
        {
            maxLen = len;
            maxIdx = i;
        }
        temp = temp->next;
        i++;
    }
    return maxIdx;
}

int findShortestIdx(Node* front) 
{
    int minLen = INT_MAX;
    int minIdx = -1;
    int i = 0;
    Node* temp = front;
    while (temp != nullptr) 
    {
        int len = temp->data.length();
        if (len < minLen) 
        {
            minLen = len;
            minIdx = i;
        }
        temp = temp->next;
        i++;
    }
    return minIdx;
}


void copyBetweenIndexes(Node* front, Node*& newFront, Node*& newRear, int startIdx, int endIdx) 
{

    Node* temp = front;

    for (int i = 0; i < startIdx+1; i++) 
    {
        temp = temp->next;
    }
    for (int i = startIdx; i < endIdx-1; i++) 
    {
        enqueue(newFront, newRear, temp->data);
        temp = temp->next;
    }
}

string dequeue(Node*& first, Node*& last)
{
    Node* tmp = first->next; // 1
    string value = first->data; // 2
    delete first; // 3
    first = tmp; // 4
    if (first == NULL)
        last = NULL; // 5
    return value; // 6
}


int main() {
    ifstream infile("C:/Student/3.txt");
    Node* front = nullptr;
    Node* rear = nullptr;
    string word;
    while (infile >> word) {
        enqueue(front, rear, word);
    }
    infile.close();
    printQueue(front);

    cout << endl;

    string longestWord = findLongest(front);
    string shortestWord = findShortest(front);
    int longestIdx = findLongestIdx(front);
    int shortestIdx = findShortestIdx(front);


    cout << "Longest word: " << longestWord << ", at position: " << longestIdx+1 << endl;
    cout << "Shortest word: " << shortestWord << ", at position: " << shortestIdx+1 << endl;

    cout << endl;

    Node* newFront = nullptr;
    Node* newRear = nullptr;
    if (longestIdx < shortestIdx) {
        copyBetweenIndexes(front, newFront, newRear, longestIdx, shortestIdx);
    }
    else {
        copyBetweenIndexes(front, newFront, newRear, shortestIdx, longestIdx);
    }

    cout << endl;

    printQueue(newFront);
    return 0;
    dequeue(front, rear);
}

