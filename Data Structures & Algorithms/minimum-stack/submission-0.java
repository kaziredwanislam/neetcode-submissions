class MinStack {
    ArrayList<Integer>stackList;
    public MinStack() {
        stackList=new ArrayList<>();
    }
    
    public void push(int val) {
        stackList.add(val);
    }
    
    public void pop() {
        stackList.remove(stackList.size()-1);
    }
    
    public int top() {
        return stackList.get(stackList.size()-1);
    }
    
    public int getMin() {
        int min=stackList.get(0);
        for(int i=1;i<stackList.size();i++)
        {
            if(stackList.get(i)<min)min=stackList.get(i);
        }
        return min;
    }
}
