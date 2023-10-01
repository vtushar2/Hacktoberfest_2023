// Purpose: Implementation of Stack ADT using Array
class StackImpl<E>{
    private E buff[];
    private int length;
    private int sp;

    public StackImpl(int length){
        this.length = length;
        buff = (E[]) new Object[length];
        sp = 0;
    }

    public void push(E e){
        if(sp < length){
            buff[sp] = e;
            sp++;
        }
    }

    public E pop(){
        if(sp > 0){
            sp--;
            return buff[sp];
        }
        return null;
    }

    public boolean isEmpty(){
        return sp == 0;
   }

   public boolean isFull(){
       return sp == length;
   }

   public int size(){
       return sp;
   }

   public void clear(){
       sp = 0;
   }

   //implement peek
    public E peek(){
         if(sp > 0){
              return buff[sp-1];
         }
         return null;
    }
}


class StackImplTest{
    public static void main(String args[]){
        StackImpl<Integer> stack = new StackImpl<Integer>(10);
        stack.push(11);
        stack.push(12);
        stack.push(13);
        stack.push(14);
        System.out.println(stack.peek());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
    }
}