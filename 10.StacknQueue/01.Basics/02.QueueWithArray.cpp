class ArrayQueue {
public:
    int front,rear,size,queue[10];
    ArrayQueue() {
        front=-1;
        rear=-1;
        size=0;
    }
    
    void push(int x) {

        if(size==10) return;

        if(front==-1 && rear==-1)
        {
            front=0;
        }

        rear=(rear+1)%10;
        queue[rear]=x;
        size++;
   
    }
    
    int pop() {

        if(size==0) return -1;

        int el=queue[front];

        if(front==rear)
        {
            front=rear=-1;
            
        }
        else
        {
            front=(front+1)%10;
        }
        size--;
        return el;
  
    }
    
    int peek() {

        if(size==0) return -1;

        return queue[front];
    
    }
    
    bool isEmpty() {

        return size==0;
  
    }
};