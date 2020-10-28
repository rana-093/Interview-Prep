//RANA
class LRUCache {
	class listNode{
		int key;
		int value;
		listNode next;
		listNode prev;
	}
	
	listNode head;
	listNode tail;
	int capacity;
	HashMap< Integer, listNode> mp = new HashMap< Integer, listNode>();
	
	void Add(listNode res) {
		listNode temp = head.next;
		head.next = res;
		res.prev = head;
		res.next = temp;
		temp.prev = res;
	}
	
	void Remove(listNode temp) {
		if(head.next == tail) { return ; }
		listNode p = temp.prev;
		listNode n = temp.next;
		p.next = n;
		n.prev = p;
	}
	
	void Print() {
		listNode x = head;
		x = x.next;
		while(x != tail) {
			System.out.println(x.key+" , "+ x.value);
			x = x.next;
		}
	}
	
	void moveToHead(listNode res) {
		Remove(res);
		Add(res);
	}
	
	void popBack() {
		mp.remove(tail.prev.key);
		Remove(tail.prev);
	}
	
    public LRUCache(int capacity) {
        head = new listNode();
        tail = new listNode();
        this.capacity = capacity;
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
    	if(!mp.containsKey(key)) { return -1; }
        listNode res = mp.get(key);
        this.moveToHead(res);
        return res.value;
    }
    
    public void put(int key, int value) {
    	listNode X = mp.get(key);
    	if(X == null) {
    		if(mp.size() == this.capacity) {
            	this.popBack();
            }
            listNode cur = new listNode();
            cur.key = key;
            cur.value = value;
            Add(cur);
            mp.put(key, cur);
    	}
        else {
        	X.value = value;
        	moveToHead(X);
        	mp.put(X.key, X);
        }
    }
}
