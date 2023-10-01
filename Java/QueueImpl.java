//implment Queue ADT using array
class QueueImpl<E>{
    private E buff[];
    private int length;
    private int qp;

    public QueueImpl(int length){
        this.length = length;
        buff = (E[]) new Object[length];
        qp = 0;
    }
    
    public void enqueue(E e){
        if(qp < length){
            buff[qp] = e;
            qp++;
        }
    }

    public E dequeue(){
        if(qp > 0){
            E e = buff[0];
            for(int i = 0; i < qp-1; i++){
                buff[i] = buff[i+1];
            }
            qp--;
            return e;
        }
        return null;
    }

    public boolean isEmpty(){
        return qp == 0;
    }

    public boolean isFull(){
        return qp == length;
    }

    public int size(){
        return qp;
    }

    public int top(){
        return (int) buff[qp-1];
    }
}

class QueueImplTest{
    public static void main(String args[]){
        QueueImpl<Integer> queue = new QueueImpl<Integer>(10);
        queue.enqueue(11);
        queue.enqueue(12);
        queue.enqueue(13);
        queue.enqueue(14);
        System.out.println(queue.dequeue());
        System.out.println(queue.dequeue());
        System.out.println(queue.dequeue());
        System.out.println(queue.dequeue());
    }
}