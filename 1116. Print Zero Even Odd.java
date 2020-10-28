//RANA
class ZeroEvenOdd {
    private int n;
    boolean flag = true;
    AtomicInteger res = new AtomicInteger(1);
    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public  void zero(IntConsumer printNumber) throws InterruptedException {
        synchronized(this){
            for(int i = 1; i <= n; i++){
                while(!flag){ wait(); } // Only TRUE hoile dhukbe eikhane
                printNumber.accept(0);
                flag = false;
                notifyAll();
            }    
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        synchronized(this){
            for(int i = 2; i <= n; i+=2){
                while( (flag==true) || (res.get() % 2 == 1) ){ wait(); }
                res.set(i);
                printNumber.accept(res.get());
                res.incrementAndGet();
                flag = true;
                notifyAll();
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        synchronized(this){
            for(int i = 1; i <= n; i+=2){
                while( (flag == true) || (res.get() % 2 == 0) ){ wait(); }
                res.set(i);
                printNumber.accept(res.get());
                res.incrementAndGet();
                flag = true;
                notifyAll();
            }
        }
    }
}
