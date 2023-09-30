// Purpose: Implementation of a doubled linked list in Java.


class Node<E>{
    private Node next;
    private Node prev;
    private E data;

    public Node(E data){
        this.data = data;
        next = null;
        prev = null;
    }

    public Node getNext(){
        return next;
    }

    public Node getPrev(){
        return prev;
    }

    public E getData(){
        return data;
    }

    public void setNext(Node next){
        this.next = next;
    }

    public void setPrev(Node prev){
        this.prev = prev;
    }

    public void setData(E data){
        this.data = data;
    }

    public String toString(){
        return data.toString();
    }
}


class DoubledLinkList<E>{
    private Node head;
    private Node tail;
    private int length;
    
    public DoubledLinkList(){
        head = null;
        tail = null;
        length = 0;
    }

    public void insert(E data){
        Node node = new Node(data);
        if(head == null){
            head = node;
            tail = node;
        }else{
            tail.setNext(node);
            node.setPrev(tail);
            tail = node;
        }
        length++;
    }

    public void delete(E data){
       
    }

    public void print(){
        Node node = head;
        while(node != null){
            System.out.println(node);
            node = node.getNext();
        }
    }
}


public class LinkedListImpl {
    public static void main(String[] args) {
        DoubledLinkList<Integer> list = new DoubledLinkList<Integer>();
        list.insert(5);
        list.insert(20);
        list.insert(39);
        list.insert(47);
        list.print();
    }
}
