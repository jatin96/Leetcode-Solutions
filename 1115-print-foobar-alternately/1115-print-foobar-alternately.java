class FooBar {
    private int n;
    private boolean isFooPrinted;
    private boolean isBarPrinted;
    public FooBar(int n) {
        this.n = n;
        isFooPrinted = false;
        isBarPrinted = true;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            synchronized(this) {
                // printFoo.run() outputs "foo". Do not change or remove this line.
                while(!isBarPrinted) wait(); 
        	    printFoo.run();
                isFooPrinted = true;
                isBarPrinted = false;
                notifyAll();
            }

        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            
            synchronized(this) {
                while (!isFooPrinted) wait();
                // printBar.run() outputs "bar". Do not change or remove this line.
        	    printBar.run();
                isFooPrinted = false;
                isBarPrinted = true;
                notifyAll();
            }

        }
    }
}