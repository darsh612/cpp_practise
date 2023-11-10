/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class ring_buffer{
    private:
        int * buffer;
        int head;
        int tail;
        bool head_phase;
        bool tail_phase;
        bool full;
        int size;
    public:
        ring_buffer(int buffersize){
            size = buffersize;
            buffer = new int[size];
            for (int i = 0; i < size; ++i) {
                buffer[i] = -1;
            }
            head = 0;
            tail = 0;
            head_phase = 0;
            tail_phase = 0;
        }
        //void enter_size(int user_size);
        void push(int data);
        void pop();
        bool isEmpty();
        bool isFull();
        int peek();    // To peek data at the head of the buffer
        void clear();  // To clear buffer entirely
        int buffer_size(); //How much part of the buffer is occupied
};

//void ring_buffer::enter_size(int user_size){
//    size = user_size;
//}

void ring_buffer:: push(int data){
    if(tail == head && head_phase != tail_phase){
        cout<<"This push of data " << data << " is not allowed !!!! Ring buffer is full.\n";
        //cout<<"Position of head is "<< head <<" and head_phase = "<< head_phase <<" and position of tail is "<<tail<<" and tail_phase = "<<tail_phase<<"\n";
    }
    else{
        buffer[tail] = data;
        tail++;
        tail = tail%size;
        if(tail == 0){
            tail_phase = !tail_phase;
        }        
    }
    cout<<"Position of head is "<< head <<" and head_phase = "<< head_phase <<" and position of tail is "<<tail<<" and tail_phase = "<<tail_phase<<"\n";
    cout<<"Contents of buffer is : ";
    for(int i =0;i<size;i++){
        cout<<buffer[i]<<" ";
    }
    cout<<"\n";
}
void ring_buffer:: pop(){
    if(tail == head && head_phase == tail_phase){
        cout<<"Buffer is empty !!! Pop of data is not allowed.\n";
        //cout<<"Position of head is "<< head <<" and head_phase = "<< head_phase <<" and position of tail is "<<tail<<" and tail_phase = "<<tail_phase<<"\n";
    }
    else{
        buffer[head] = -1; // -1 is just to show that we have removed the element from the buffer
        // In reality if we move the head pointer, we are indicating that we removed the data.
        head++;
        head = head%size;
        if(head == 0){
            head_phase = !head_phase;
        }    
    }
    cout<<"Position of head is "<< head <<" and head_phase = "<< head_phase <<" and position of tail is "<<tail<<" and tail_phase = "<<tail_phase<<"\n";
    cout<<"Contents of buffer is : ";
    for(int i =0;i<size;i++){
        cout<<buffer[i]<<" ";
    }
    cout<<"\n";
}

bool ring_buffer::isEmpty(){
    cout<<"Position of head is "<< head <<" and head_phase = "<< head_phase <<" and position of tail is "<<tail<<" and tail_phase = "<<tail_phase<<"\n";
    if(tail == head && head_phase == tail_phase){
        return true;
    }
    return false;
}

bool ring_buffer::isFull(){
    cout<<"Position of head is "<< head <<" and head_phase = "<< head_phase <<" and position of tail is "<<tail<<" and tail_phase = "<<tail_phase<<"\n";
    if(tail == head && head_phase != tail_phase){
        return true;
    }
    return false;
}

int ring_buffer:: peek(){
    return buffer[head];
}

void ring_buffer:: clear(){
    tail = head;
    tail_phase = head_phase;
    for(int i = 0; i < size;i++){
        buffer[i] = -1;
    }
}

int ring_buffer:: buffer_size(){
    if(isFull()){
        return size;
    }
    else if(isEmpty()){
        return 0;
    }
    else{
        if( (tail > head) && (tail_phase == head_phase)){
            return tail-head;
        }
        else if((tail < head) && (tail_phase != head_phase)){
            return (size - (head-tail));
        }
    }
}

int main()
{
    int user_size;
    cout<<"Enter the size of the ring buffer :- \n";
    cin >> user_size;
    //myRingBuffer.enter_size(user_size);
    ring_buffer myRingBuffer(user_size);
    
    // Push some data into the buffer
    myRingBuffer.push(10);
    myRingBuffer.push(20);
    myRingBuffer.push(30);
    myRingBuffer.push(40);
    myRingBuffer.push(50);
    myRingBuffer.push(60);
    myRingBuffer.push(70);
    myRingBuffer.pop();
    myRingBuffer.pop();
    myRingBuffer.push(60);
    myRingBuffer.push(70); 
    myRingBuffer.pop();
    myRingBuffer.pop();
    myRingBuffer.pop();
    myRingBuffer.pop();
    myRingBuffer.pop();
    myRingBuffer.pop();
    myRingBuffer.push(10);
    myRingBuffer.push(20);
    myRingBuffer.push(30);
    myRingBuffer.push(40);
    myRingBuffer.push(50);
    // Peek at the head of the buffer
    std::cout << "Peek at the head: " << myRingBuffer.peek() << std::endl;

    // Check if the buffer is empty or full
    std::cout << "Is the buffer empty? " << (myRingBuffer.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Is the buffer full? " << (myRingBuffer.isFull() ? "Yes" : "No") << std::endl;

    // Pop an element from the buffer
    myRingBuffer.pop();

    // Check buffer size
    std::cout << "Buffer size: " << myRingBuffer.buffer_size() << std::endl;

    // Clear the buffer
    myRingBuffer.clear();

    // Check if the buffer is empty after clearing
    std::cout << "Is the buffer empty after clearing? " << (myRingBuffer.isEmpty() ? "Yes" : "No") << std::endl;
    
    return 0;

}